
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include "c_ast.h"
#include "c_const.h"

int c_ast_is_constant_string(const char *str)
{
  if ( str == NULL )
    return 1;
  if ( str >= &(c_constant_str_table[0][0]) && 
       str < &(c_constant_str_table[0][0])  + sizeof(c_constant_str_table) )
  {
    return 1;
  }
  return 0;
}

const char *c_ast_replace_with_constant(const char *str)
{
  int i = 0;
  const char *s;
  for(;;)
  {
    s = c_constant_str_table[i];
    if ( s >= &(c_constant_str_table[0][0])  + sizeof(c_constant_str_table) )
      break;
    if ( strcmp(s, str) == 0 )
      return s;
    i++;
  }
  return str;
}

c_ast_type c_ast_Open(const char *s, c_loc_struct *l)
{
  c_ast_type ast;
  ast = (c_ast_type)malloc(sizeof(struct _c_ast_struct));
  if ( ast != NULL )
  {
    if ( l != NULL )
    {
      ast->l = *l;
    }
    else
    {
      ast->l.first_line = 0;
      ast->l.first_column = 0;
      ast->l.last_line = 0;
      ast->l.last_column = 0;
    }
    ast->d = NULL;
    ast->n = NULL;
    if ( s == NULL )
    {
      ast->s = NULL;
      return ast;
    }
    
    s = c_ast_replace_with_constant(s);
    
    if ( c_ast_is_constant_string(s) != 0 )
    {
      ast->s = s;
      return ast;
    }
    else 
    {
      ast->s = strdup(s);
      if ( ast->s !=  NULL )
      {
        return ast;
      }
    }
    free(ast);
  }
  return NULL;
}

c_ast_type c_ast_OpenNIL(void)
{
  return c_ast_Open(NULL, NULL);
}


void c_ast_Close(c_ast_type ast)
{
  if ( ast == NULL )
    return;
  c_ast_Close(ast->d);
  c_ast_Close(ast->n);
  if ( ast->s != NULL )
  {
    if ( c_ast_is_constant_string(ast->s) == 0 )
      free((char *)ast->s);
  }
  free(ast);
}

size_t c_ast_GetMemUsage(c_ast_type ast)
{
  if ( ast == NULL )
    return (size_t)0;
  return c_ast_GetMemUsage(ast->d)+
         c_ast_GetMemUsage(ast->n)+
         sizeof(struct _c_ast_struct)+
         (c_ast_is_constant_string(ast->s) != 0?0:strlen(ast->s)+1) ;
}

/* returns parent */
c_ast_type c_ast_AddChild(c_ast_type parent, c_ast_type child)
{
  if ( parent == NULL )
    return NULL;
  if ( parent->d == NULL )
  {
    parent->d = child;
  }
  else
  {
    c_ast_type tmp = parent->d;
    while( tmp->n != NULL )
      tmp = tmp->n;
    tmp->n = child;
  }
  return parent;
}

/* returns parent */
c_ast_type c_ast_AddChildFirst(c_ast_type parent, c_ast_type child)
{
  if ( parent == NULL )
    return NULL;
  if ( child == NULL )
    return parent;
  assert( child->n == NULL );
  if ( parent->d == NULL )
  {
    parent->d = child;
  }
  else
  {
    c_ast_type tmp = parent->d;
    parent->d = child;
    child->n = tmp;
  }
  return parent;
}

/* returns parent */
c_ast_type c_ast_AddVAChildren(c_ast_type parent, int n, va_list va)
{
  c_ast_type child;
  int i;
  
  for( i = 0; i < n; i++ )
  {
    child = va_arg(va, c_ast_type);
    c_ast_AddChild(parent, child);
  }
  return parent;
}

/* returns parent */
c_ast_type c_ast_AddChildren(c_ast_type parent, int n, ...)
{
  va_list va;
  va_start(va, n);
  parent = c_ast_AddVAChildren( parent, n, va );
  va_end(va);
  return parent;
}

/* returns parent or NULL */
c_ast_type c_ast_OpenChildren(const char *s, c_loc_struct *l, int n, ...)
{
  va_list va;
  c_ast_type parent = c_ast_Open(s, l);
  if ( parent == NULL )
    return NULL;
  va_start(va, n);
  parent = c_ast_AddVAChildren( parent, n, va );
  va_end(va);
  return parent;
  
}

/*----------------------------------------------------------------------*/

#define C_AST_STACK_SIZE 1024
static c_ast_type c_ast_stack_array[C_AST_STACK_SIZE];
static int c_ast_stack_pos = 0;

/* block_item_list or translation_unit */
void c_ast_Push(c_ast_type n)
{
  assert( c_ast_stack_pos < C_AST_STACK_SIZE);
  c_ast_stack_array[c_ast_stack_pos] = n;
  c_ast_stack_pos++;
}

c_ast_type c_ast_Pop(c_loc_struct *l)
{
  c_ast_type n;
  assert( c_ast_stack_pos > 0);
  n = c_ast_stack_array[c_ast_stack_pos-1];
  n->l = *l;
  c_ast_stack_pos--;
  return n;
}

c_ast_type c_ast_Last(void)
{
  assert( c_ast_stack_pos > 0);
  return c_ast_stack_array[c_ast_stack_pos-1];
}

/*----------------------------------------------------------------------*/

int c_ast_Is(c_ast_type n, const char *s)
{
  if ( n == NULL || s == NULL )
    return 0;
  if ( c_ast_is_constant_string(s) == 0 )
  {
    if ( strcmp(n->s, s) == 0 )
      return 1;
  }
  else if ( n->s == s )
    return 1;
  return 0;
}

int c_ast_IsN(c_ast_type n, int cnt, ...)
{
  const char *s;
  va_list va;
  va_start(va, cnt);
  while( cnt > 0 )
  {
    s = va_arg(va, const char *);
    if ( c_ast_Is(n, s) != 0 )
    {
      va_end(va);
      return 1;
    }
    cnt--;
  }
  va_end(va);
  return 0;
}

c_ast_type c_ast_FindChildByStr(c_ast_type n, const char *s)
{
  if ( n == NULL )
    return NULL;
  n = n->d;
  while( n != NULL )
  {
    if ( c_ast_Is(n, s) != 0 )
      return n;
    n = n->n;
  }
  return NULL;
}

/*----------------------------------------------------------------------*/

/*
  returns parent node for 'n'. Search starts at 'start'
  parent node is p->d or p->d->n or p->d->n->n ..
*/
c_ast_type c_ast_GetParent(c_ast_type start, c_ast_type n)
{
  c_ast_type nn;
  c_ast_type parent;
  
  if ( start == NULL )
    return NULL;
  
  nn = start->d;
  while( nn != NULL )
  {
    if ( nn == n )
      return start;
    parent = c_ast_GetParent(nn, n);
    if ( parent != NULL )
      return parent;
    nn = nn->n;
  }
  return NULL;
}

/*
  search for a node of type s which also contains node 'inside'
  search starts at 'start'
  'inside' must be really inside and can not be the same as the return value
*/
c_ast_type c_ast_FindByStrIfContains(c_ast_type start, const char *s, c_ast_type inside)
{
  c_ast_type loop, result;
  if ( start == NULL )
    return NULL;
  loop = start->d;
  while( loop != NULL )
  {
    if ( c_ast_Is(loop, s) != 0 )
    {
      if ( c_ast_GetParent(loop, inside) != NULL )
      {
        return loop;
      }
    }
    else
    {
      result = c_ast_FindByStrIfContains(loop, s, inside);
      if ( result != NULL )
        return result;
    }
    loop = loop->n;
  }
  return NULL;
  
}


/*----------------------------------------------------------------------*/

/*
  expect: declaration_specifiers
  returns 1 if storage_class_specifier is 'typedef'
*/
static int c_ast_chk_declaration_specifiers_for_typedef(c_ast_type n)
{
  c_ast_type l, ll;
  assert( c_ast_Is(n, c_str_declaration_specifiers) != 0 );
  
  l = n->d;
  while( l != NULL )
  {
    assert( c_ast_IsN(l, 4, c_str_storage_class_specifier, 
      c_str_type_specifier, 
      c_str_type_qualifier, 
      c_str_function_specifier) != 0 );
    if ( c_ast_Is(l, c_str_storage_class_specifier ) != 0 )
    {
      ll = l->d;
      while( ll != NULL )
      {
        if ( c_ast_Is(ll, c_str_typedef) != 0 )
          return 1;
        ll = ll->n;
      }
    }
    l = l->n;
  }
  return 0;
}

/* expect declarator */
const char *c_ast_get_declarator_identifier(c_ast_type n)
{
  assert( c_ast_Is(n, c_str_declarator) != 0 );
  n = n->d;
  assert( n != NULL );
  n = n->n;
  assert( c_ast_Is(n, c_str_direct_declarator) != 0 );
  n = n->d;
  if ( c_ast_Is(n, c_str_identifier) != 0 );
  {
    n = n->d;
    assert( n != NULL );
    return n->s;
  }
  if ( c_ast_Is(n, c_str_declarator) != 0 );
  {
    return c_ast_get_declarator_identifier(n);
  }
  return NULL;
}

static const char *c_ast_get_init_declarator_identifier(c_ast_type n)
{
  assert( c_ast_Is(n, c_str_init_declarator) != 0 );
  n = n->d;
  assert( c_ast_Is(n, c_str_declarator) != 0 );
  return c_ast_get_declarator_identifier(n);
}

/* 
  check if one of the init_declarator elments of the init_declarator_list 
  matches the string s

  expects: init_declarator_list

  returns init_declarator if the string s matches
  returns NULL if there is no match

  4.4.09: made this function public (used by c_vap.c)

*/
c_ast_type c_ast_chk_init_declarator_list(c_ast_type n, const char *s)
{
  c_ast_type l;
  const char *identifier;
  assert( c_ast_Is(n, c_str_init_declarator_list) != 0 );
  l = n->d;
  while( l != NULL )
  {
    assert( c_ast_Is(l, c_str_init_declarator) != 0 );
    identifier = c_ast_get_init_declarator_identifier(l);
    if ( identifier != NULL )
    {
      if ( strcmp( identifier, s ) == 0 )
        return l;
    }
    l = l->n;
  }
  return NULL;
}

/*
  check if the declaration is a typedef and string s is 
  typedef'ed inside

  expects: declaration

  returns 1 of the string s matches

*/
static int c_ast_chk_declaration(c_ast_type n, const char *s)
{
  c_ast_type c1, c2;
  assert( c_ast_Is(n, c_str_declaration) != 0 );
  c1 = n->d;
  assert( c_ast_Is(c1, c_str_declaration_specifiers) != 0 );
  c2 = c1->n;
  if ( c2 == NULL )
    return 0;
  assert( c_ast_Is(c2, c_str_init_declarator_list) != 0 );
  
  if ( c_ast_chk_declaration_specifiers_for_typedef(c1) == 0 )
    return 0;
  
  return c_ast_chk_init_declarator_list(c2, s)==NULL?0:1;
}

static int c_ast_chk_ex_dec_or_blk_itm(c_ast_type n, const char *s)
{
  c_ast_type l;
  assert( c_ast_IsN(n, 2, c_str_external_declaration, c_str_block_item) != 0 );
  l = n->d;
  
  while( l != NULL )
  {
    assert( c_ast_IsN(l, 3, c_str_declaration, 
                            c_str_function_definition, 
                            c_str_statement) != 0 );
    if ( c_ast_Is(l, c_str_declaration) != 0 )
    {
      if ( c_ast_chk_declaration(l, s) != 0 )
        return 1; /* "s" is typedef */
    }
    l = l->n;
  }
  return 0;
}

static int c_ast_chk_tu_or_bil(c_ast_type n, const char *s)
{
  c_ast_type l;
  assert( c_ast_IsN(n, 2, c_str_translation_unit, c_str_block_item_list) != 0 );
  l = n->d;
  
  while( l != NULL )
  {
    assert( c_ast_IsN(l, 2, c_str_external_declaration, c_str_block_item) != 0 );
    if ( c_ast_chk_ex_dec_or_blk_itm(l, s) != 0 )
      return 1; /* "s" is typedef */
    l = l->n;
  }
  return 0;
}

/* check if 's' has been typedef'd */
int c_is_typedef(const char *s)
{
  int i;
  for( i = 0; i < c_ast_stack_pos; i++ )
  {
    if ( c_ast_chk_tu_or_bil(c_ast_stack_array[i], s) != 0 )
      return 1;
  }
  return 0;
}


/*----------------------------------------------------------------------*/

static void c_ast_indent(int depth, FILE *fp)
{
  int i;
  for( i = 0; i < depth; i++ )
    fprintf(fp, " ");
}

static void c_ast_show_string(c_ast_type n, FILE *fp)
{
  if ( n == NULL )
    return;
  if ( n->s == NULL )
    fprintf(fp, "<null>");
  else
    fprintf(fp, "%s", n->s);
}

void c_ast_show_location(c_ast_type n, FILE *fp)
{
  fprintf(fp, "%02d.%02d-%02d.%02d ", 
    n->l.first_line,
    n->l.first_column,
    n->l.last_line,
    n->l.last_column
  );
}

static void c_ast_show_plain(c_ast_type n, int depth, FILE *fp)
{
  while( n != NULL )
  {
    c_ast_show_location(n, fp);
    c_ast_indent(depth, fp);
    c_ast_show_string(n, fp);
    fprintf(fp, "\n");
    c_ast_show_plain(n->d, depth+1, fp);
    n = n->n;
  }
}

void c_ast_Show(c_ast_type n)
{
  c_ast_show_plain(n, 0, stdout);
}

/*----------------------------------------------------------------------*/



