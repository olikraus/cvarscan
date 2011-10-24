/*

  variable access path 
  
  
  ERSETZT DURCH c_fi_va.c
  
*/

#include <assert.h>
#include <stdlib.h>
#include "c_fi.h"
#include "c_const.h"
#include "c_util.h"

/*------------------------------------------------------------*/

c_vap_type c_fi_vap_cast_expression(c_fi_type fi, c_ast_type n);

/*------------------------------------------------------------*/

c_vap_type c_vap_Open(void)
{
  c_vap_type vap;
  vap = (c_vap_type)malloc(sizeof(c_vap_struct));
  if ( vap != NULL )
  {
    vap->el_idx_list = b_il_Open();
    if ( vap->el_idx_list != NULL )
    {
      vap->is_read = 0;
      vap->is_write = 0;
      return vap;
    }
    free(vap);
  }
  return c_mem_err(), NULL;
}

void c_vap_Close(c_vap_type vap)
{
  if ( vap == NULL )
    return;
  b_il_Close(vap->el_idx_list);
  vap->el_idx_list = NULL;
  free(vap);
}

int c_vap_Add(c_vap_type vap, int el_idx)
{
  if ( vap == NULL || el_idx < 0 )
    return 1;
  if ( b_il_Add(vap->el_idx_list, el_idx) < 0 )
    return c_mem_err(), 0;
  return 1;
}

c_vap_type c_vap_OpenAdd(int el_idx)
{
  if ( el_idx >= 0 )
  {
    c_vap_type vap = c_vap_Open();
    if ( vap != NULL )
    {
      if ( c_vap_Add(vap, el_idx) != 0 )
      {
        return vap;
      }
      c_vap_Close(vap);
    }
  }
  return NULL;
}

int c_vap_GetLastElementIdx(c_vap_type vap)
{
  if ( vap == NULL )
    return -1;
  if ( b_il_Cnt(vap->el_idx_list) == 0 )
    return -1;
  return b_il_GetLast(vap->el_idx_list);
}

int c_vap_Copy(c_vap_type dest, c_vap_type src)
{
  if ( b_il_Copy(dest->el_idx_list, src->el_idx_list) == 0 )
    return 0;
  dest->is_read = src->is_read;
  dest->is_write = src->is_write;
  return 1;
}

c_vap_type c_vap_OpenCopy(c_vap_type src)
{
  c_vap_type vap = c_vap_Open();
  if ( vap != NULL )
  {
    if ( c_vap_Copy(vap, src) != 0 )
    {
      return vap;
    }
    c_vap_Close(vap);
  }
  return NULL;
}

/*------------------------------------------------------------*/

#ifdef _OLD_OLD_OLD_
int c_fi_vap_postfix_expression(c_fi_type fi, c_ast_type n)
{
  if ( c_ast_Is(n, c_str_postfix_expression) == 0 )
    return c_ast_err(), 0;

  if ( c_ast_Is(n->d, c_str_unnamed_object) != 0 )
    return 1; /* nothing to do */
  
  if ( c_ast_Is(n->d, c_str_primary_expression) == 0 )
    return c_ast_err(), 0;
  
  /* todo */
  return 0;
}
#endif

/*
  for 'n' return its function_definition if available
  returns NULL of node 'n' is not a part of a function_definition
*/
c_ast_type c_fi_vap_get_function_definition(c_fi_type fi, c_ast_type n)
{
  return c_ast_FindByStrIfContains(fi->ast, c_str_function_definition, n);
}

/*
  below 'n' search for a init_declarator with 's' as identifier of the init_declarator_list
*/
c_ast_type c_ast_get_init_declarator(c_ast_type n, const char *s)
{
  c_ast_type result;
  if ( n == NULL )
    return NULL;
  if ( c_ast_Is(n, c_str_declaration) != 0 )
  {
    c_ast_type declaration_specifiers;
    c_ast_type init_declarator_list;
    declaration_specifiers = n->d;
    if ( declaration_specifiers != NULL )
    {
      init_declarator_list = declaration_specifiers->n;
      if ( init_declarator_list != NULL )
      {
        c_ast_type init_declarator = c_ast_chk_init_declarator_list(init_declarator_list, s);
        if ( init_declarator != NULL )
          return init_declarator;
      }
    }
  }
  result = c_ast_get_init_declarator(n->d, s);
  if ( result != NULL )
    return result;
  return c_ast_get_init_declarator(n->n, s);
}

/* expects function definition */
const char *c_ast_get_function_name(c_ast_type function_definition)
{
  c_ast_type declarator;
  c_ast_type direct_declarator;
  c_ast_type identifier;
  
  if ( c_ast_Is(function_definition, c_str_function_definition) == 0 )
    return c_ast_err(), NULL;
  if ( c_ast_Is(function_definition->d, c_str_declaration_specifiers) == 0 )
    return c_ast_err(), NULL;
  if ( c_ast_Is(function_definition->d->n, c_str_declarator) == 0 )
    return c_ast_err(), NULL;
  declarator = function_definition->d->n;
  if ( c_ast_Is(declarator->d->n, c_str_direct_declarator) == 0 )
    return c_ast_err(), NULL;
  direct_declarator = declarator->d->n;

  /* search for function name */
  identifier = c_ast_FindChildByStr(direct_declarator, c_str_identifier);
  if ( identifier != NULL )
  {
    return identifier->d->s;
  }
  return NULL;
}

int c_fi_vap_fn_arg(c_fi_type fi, c_ast_type function_definition, c_ast_type n)
{
  const char *fn_name;
  const char *arg_name;
  int el_idx; 
  if ( c_ast_Is(n, c_str_identifier) == 0 )
    return c_ast_err(), -1;
  if ( c_ast_Is(function_definition, c_str_function_definition) == 0 )
    return c_ast_err(), -1;
  fn_name = c_ast_get_function_name(function_definition);
  arg_name = n->d->s;
  
  el_idx = c_ell_FindByFnAndArg(fi->ell, fn_name, arg_name);
  if ( el_idx >= 0 )
    return el_idx;
  
  return -1;
}
  
int c_fi_vap_local_identifier(c_fi_type fi, c_ast_type function_definition, c_ast_type n)
{
  int i;
  c_ast_type compound_statement;
  c_ast_type init_declarator;
  int el_idx;
  
  if ( c_ast_Is(n, c_str_identifier) == 0 )
    return c_ast_err(), -1;

  /* calculate the ast_path for n */
  if ( c_ast_GetCompoundStatementPath(fi->ast, n, fi->vap_ast_path) == 0 )
    return -1;
  i = b_pl_Cnt(fi->vap_ast_path);
  while( i > 0 )
  {
    i--;
    compound_statement = b_pl_Get(fi->vap_ast_path, i);
    init_declarator = c_ast_get_init_declarator(compound_statement, n->d->s);
    if ( init_declarator != NULL )
    {
      el_idx = c_ell_FindByASTInitDeclarator(fi->ell, init_declarator);
      if ( el_idx >= 0 )
        return el_idx;
    }
  }
  return -1;
}

/* find var which matches identifier  'n' */
/* returns an index to the definition/declaration of the variable or -1 */
int c_fi_vap_identifier(c_fi_type fi, c_ast_type n)
{
  c_ast_type function_definition; 
  int el_idx;
  
  if ( c_ast_Is(n, c_str_identifier) == 0 )
    return c_ast_err(), -1;
  
  c_log(4, "lookup identifier '%s'\n", n->d->s);
  
  function_definition = c_fi_vap_get_function_definition(fi, n);
  
  if ( function_definition != NULL )
  {
    
    /* is the identifier a local variable? */
    el_idx = c_fi_vap_local_identifier(fi, function_definition, n);
    if ( el_idx >= 0 )
    {
      c_ell_log(fi->ell, el_idx, 4, "found local identifier");
      return el_idx;
    }
    
    /* is the identifier a function argument? */    
    el_idx = c_fi_vap_fn_arg(fi, function_definition, n);
    if ( el_idx >= 0 )
    {
      c_ell_log(fi->ell, el_idx, 4, "found function argument");
      return el_idx;
    }    
  }

  /* global variables */
  el_idx = c_ell_FindGlobalVar(fi->ell, n->d->s);
  if ( el_idx >= 0 )
  {
    c_ell_log(fi->ell, el_idx, 4, "found global var");
    return el_idx;
  }
  
  c_log(3, "unresolved identifier '%s'.\n", n->d->s);
  return -1;
}

/*
  Description:
    return the type or variable of the expression if suitable
    else: return NULL
*/
c_vap_type c_fi_vap_expression(c_fi_type fi, c_ast_type n)
{
  if ( c_ast_Is(n, c_str_expression) == 0 )
    return c_ast_err(), NULL;
  /* todo */
  return NULL;
}

/*
primary_expression:
  identifier                                            { $$ = T1(@$,$1,@1); }
  | constant                                            { $$ = T1(@$,$1,@1); }
  | string                                              { $$ = T1(@$,$1,@1); }
  | '(' expression ')'                                  { $$ = T1(@$,$2,@2); }
  ;
  
  Description:
    Expects a primary expression and tries to match a variable if possible.
  Returns:
    Index to an element (el_type within fi->ell)
    -1 if there is no suitable index
  Bugs: no error value possible... perhaps -2?
  
*/
c_vap_type c_fi_vap_primary_expression(c_fi_type fi, c_ast_type n)
{
  assert( c_ast_Is(n, c_str_primary_expression) != 0 );
  
  /* examine possible childs */
  
  if ( c_ast_Is(n->d, c_str_constant) != 0 )
    return NULL;  /* valid, but not a variable, return -1 */

  if ( c_ast_Is(n->d, c_str_string) != 0 )
    return NULL;  /* valid, but not a variable, return -1 */

  if ( c_ast_Is(n->d, c_str_expression) != 0 )
    return c_fi_vap_expression(fi, n->d); 

  if ( c_ast_Is(n->d, c_str_identifier) != 0 )
    return c_vap_OpenAdd(c_fi_vap_identifier(fi, n->d));  /* find var which matches identifier  */

  return c_ast_err(), NULL; /* internal error, still return -1 */
}

/*
dot:
  '.' identifier_usertype                               { $$ = T1(@$,$2,@2); }
  ;

arrow:
  ARROW identifier_usertype                             { $$ = T1(@$,$2,@2); }
  ;

  returns the argument vap if successful, else arg vap is closed and 
      NULL returned
*/
c_vap_type c_fi_vap_dot_arrow(c_fi_type fi, c_vap_type vap, c_ast_type n)
{
  int su_el_idx;
  int member_el_idx;
  
  if ( c_ast_Is(n, c_str_dot) == 0 && c_ast_Is(n, c_str_arrow) == 0 )
    return c_vap_Close(vap), NULL;
  
  if ( c_ast_Is(n->d, c_str_identifier_usertype) == 0 )
    return c_vap_Close(vap), NULL;
  
  if ( n->d->s == NULL )
    return c_vap_Close(vap), NULL;
  
  su_el_idx = c_vap_GetLastElementIdx(vap);
  if ( su_el_idx < 0 )
    return c_vap_Close(vap), NULL;

  member_el_idx = c_ell_FindStructUnionMember(
          fi->ell, su_el_idx, n->d->s);
  if ( member_el_idx < 0 )
  {
    c_log(1, "member '%s' not found\n", n->d->s);
    return c_vap_Close(vap), NULL;
  }
  
  if ( c_vap_Add(vap, member_el_idx) == 0 )
    return c_vap_Close(vap), NULL;

  return vap;
}

/*
postfix_expression:
  primary_expression                                    { $$ = T1(@$,$1,@1); }
  | postfix_expression array                            { $$ = LIST($1, $2); }
  | postfix_expression fnargs                           { $$ = LIST($1, $2); }
  | postfix_expression dot                              { $$ = LIST($1, $2); }
  | postfix_expression arrow                            { $$ = LIST($1, $2); }
  | postfix_expression inc                              { $$ = LIST($1, $2); }
  | postfix_expression dec                              { $$ = LIST($1, $2); }
  | unnamed_object                                      { $$ = T1(@$,$1,@1); }
  ;
*/
c_vap_type c_fi_vap_postfix_expression(c_fi_type fi, c_ast_type n)
{
  c_ast_type l;
  c_vap_type vap;
  if ( c_ast_Is(n, c_str_postfix_expression) == 0 )
    return NULL;
  l = n->d;
  if ( c_ast_Is(l, c_str_primary_expression) == 0 )
    return NULL;
  vap = c_fi_vap_primary_expression(fi, l);
  l = l->n;
  while( l != NULL )
  {
    if ( c_ast_Is(l, c_str_array) != 0 )
      /* todo */;
    if ( c_ast_Is(l, c_str_fnargs) != 0 )
      /* todo */;
    if ( c_ast_Is(l, c_str_dot) != 0 )
      vap =  c_fi_vap_dot_arrow(fi, vap, l);
    if ( c_ast_Is(l, c_str_arrow) != 0 )
      vap =  c_fi_vap_dot_arrow(fi, vap, l);
    if ( c_ast_Is(l, c_str_inc) != 0 )
      c_vapl_AddUniqueCopyWithRW(fi->vapl, vap, 1, 1);
    if ( c_ast_Is(l, c_str_dec) != 0 )
      c_vapl_AddUniqueCopyWithRW(fi->vapl, vap, 1, 1);
    l = l->n;
  }
  return vap;
}

/*
unary_expression:
  postfix_expression                                    { $$ = T1(@$,$1,@1); }
  | inc unary_expression                                { $$ = T2(@$,$1,@1,$2,@2); }
  | dec unary_expression                                { $$ = T2(@$,$1,@1,$2,@2); }
  | unary_operator cast_expression                      { $$ = T2(@$,$1,@1,$2,@2); }
  | sizeof unary_expression                             { $$ = T2(@$,$1,@1,$2,@2); }
  | sizeof '(' type_name ')'                            { $$ = T2(@$,$1,@1,$3,@3); }
  ;
*/
c_vap_type c_fi_vap_unary_expression(c_fi_type fi, c_ast_type n)
{
  if ( c_ast_Is(n, c_str_unary_expression) == 0 )
    return c_ast_err(), NULL;
  if ( n->d == NULL )
    return c_ast_err(), NULL;
  if ( c_ast_Is(n->d, c_str_postfix_expression) != 0 )
    return c_fi_vap_postfix_expression(fi, n->d);
  if ( c_ast_Is(n->d, c_str_inc) != 0 || c_ast_Is(n->d, c_str_dec) )
  {
    c_vap_type vap = c_fi_vap_unary_expression(fi, n->d->n);
    c_vapl_AddUniqueCopyWithRW(fi->vapl, vap, 1, 1);
    return vap;
  }
  if ( c_ast_Is(n->d, c_str_unary_operator) != 0 )
  {
    c_vap_type vap = c_fi_vap_cast_expression(fi, n->d->n);
    c_vapl_AddUniqueCopyWithRW(fi->vapl, vap, 1, 0);
    return vap;
  }
  return c_ast_err(), NULL;
}

/*
cast_expression:
  unary_expression                                      { $$ = T1(@$,$1,@1); }
  | '(' type_name ')' cast_expression                   { $$ = T2(@$,$2,@2,$4,@4); }
  ;
*/
c_vap_type c_fi_vap_cast_expression(c_fi_type fi, c_ast_type n)
{
  if ( c_ast_Is(n, c_str_cast_expression) == 0 )
    return c_ast_err(), NULL;
  if ( n->d == NULL )
    return c_ast_err(), NULL;
  if ( c_ast_Is(n->d, c_str_unary_expression) != 0 )
    return c_fi_vap_unary_expression(fi, n->d);
  /* todo type_name */
  return c_ast_err(), NULL;
}

void c_fi_vap_test_recur(c_fi_type fi, c_ast_type n)
{
  if ( n == NULL )
    return;
  if ( c_ast_Is(n, c_str_primary_expression) != 0 )
  {
    c_fi_vap_primary_expression(fi, n);
    return;
  }
  c_fi_vap_test_recur(fi, n->d);
  c_fi_vap_test_recur(fi, n->n);
}


