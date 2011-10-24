/*
  va variable access
  
  hauptaufgabe ist das erkennen von lese- und/oder schreibzugriffen
  auf die variablen aus fi->ell. in fi->ell werden die Zugriffe dann auch
  vermerkt.
  
  
*/

#include <assert.h>
#include <stdlib.h>
#include "c_util.h"
#include "c_fi.h"

/*======================================================================*/
/* Part 1: Analyse cast expression. Purpose is to find out if this is a cast to a struct/union.  */

/*
struct_or_union_specifier:
  struct_or_union identifier_usertype '{' struct_declaration_list '}'    { $$ = T3(@$,$1,@1,$2,@2,$4,@4); }
  | struct_or_union '{' struct_declaration_list '}'             { $$ = T3(@$,$1,@1,NIL(@$),@$,$3,@3); }
  | struct_or_union identifier_usertype                         { $$ = T3(@$,$1,@1,$2,@2,NIL(@$),@$); }
  ;
*/

int c_fi_va_struct_or_union_specifier(c_fi_type fi, c_ast_type n)
{
  const char *name;

  if ( c_ast_Is(n, c_str_struct_or_union_specifier) == 0 )
    return c_ast_err(), -2;
  
  /*
    n->d                c_str_struct | c_str_union
    n->d->n             c_identifier | NIL
    n->d->n->d          the structure or union name
    n->d->n->n          struct_declaration_list
  */

  /* 1. Part: Identify struct or union */
  
  if ( n->d == NULL )
    return c_ast_err(), -2;
  
  
  if ( c_ast_Is(n->d, c_str_struct) != 0 )
  {
  }
  else if ( c_ast_Is(n->d, c_str_union) != 0 )
  {
  }
  else
  {
    return c_ast_err(), -2;
  }

  /* 2. Part: Read identifier (if any) */
  
  if ( n->d->n == NULL )
    return c_ast_err(), -2;

  /* example: test_va_14.c */
  if ( c_ast_Is(n->d->n, c_str_identifier) != 0 || c_ast_Is(n->d->n, c_str_identifier_usertype) != 0  )
  {
    int idx = -1;
    name = n->d->n->d->s;
    idx = c_ell_FindSU(fi->ell, name);
    c_log(4, "struct/union lookup for '%s' with result %d\n", name, idx);
    return idx;
  }
  return -1;
}

/*
type_specifier:
  void                                                  { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | char                                                { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | short                                               { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | int                                                 { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | long                                                { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | float                                               { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | double                                              { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | signed                                              { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | unsigned                                            { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | _bool                                               { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | _complex                                            { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | _imaginary                                          { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | struct_or_union_specifier                           { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | enum_specifier                                      { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | typedef_name                                        { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  ;

  results: -1:  not found, -2:internal error, >=0: index into fi->ell

*/

int c_fi_va_type_specifier(c_fi_type fi, c_ast_type n)
{
  int result_idx = -1;
  
  if ( c_ast_Is(n, c_str_type_specifier) == 0 )
    return c_ast_err(), -2;
  
  n = n->d;
  
  if ( n->n != NULL ) return c_ast_err(), 0;
  
  if ( c_ast_Is(n, c_str_void) != 0 )
  {
    return -1;
  }
  else if ( c_ast_Is(n, c_str_char) != 0 )
  {
    return -1;
  }
  else if ( c_ast_Is(n, c_str_short) != 0 )
  {
    return -1;
  }
  else if ( c_ast_Is(n, c_str_int) != 0 )
  {
    return -1;
  }
  else if ( c_ast_Is(n, c_str_long) != 0 )
  {
    return -1;
  }
  else if ( c_ast_Is(n, c_str_float) != 0 )
  {
    return -1;
  }
  else if ( c_ast_Is(n, c_str_double) != 0 )
  {
    return -1;
  }
  else if ( c_ast_Is(n, c_str_signed) != 0 )
  {
    return -1;
  }
  else if ( c_ast_Is(n, c_str_unsigned) != 0 )
  {
    return -1;
  }
  else if ( c_ast_Is(n, c_str__bool) != 0 )
  {
    return -1;
  }
  else if ( c_ast_Is(n, c_str__complex) != 0 )
  {
    return -1;
  }
  else if ( c_ast_Is(n, c_str__imaginary) != 0 )
  {
    return -1;
  }
  else if ( c_ast_Is(n, c_str_struct_or_union_specifier) != 0 )
  {
    result_idx = c_fi_va_struct_or_union_specifier(fi, n) ;
  }
  else if ( c_ast_Is(n, c_str_enum_specifier) != 0 )
  {
    /* todo: write enum handling */
    return -1;
  }
  else if ( c_ast_Is(n, c_str_typedef_name) != 0 )
  {
    result_idx = c_ell_FindTypedef(fi->ell, n->d->s);
    c_log(4, "typedef lookup for '%s' with result %d\n", n->d->s, result_idx);
    /*
      An dieser Stelle wird tatsächlich der Typedef zurückgegeben.
      Die später verwendete Funktion c_ell_GetMember() lößt dann über
      das mtql den typedef auf und sucht sich ggf die correcte struct.
    */
  }
  else c_ast_err(), -2;
    
  return result_idx;
}


/*
specifier_qualifier_list:
  type_specifier specifier_qualifier_list               { $$ = RLIST($2, $1); }
  | type_specifier                                      { $$ = T1(@$,$1,@1); }
  | type_qualifier specifier_qualifier_list             { $$ = RLIST($2, $1); }
  | type_qualifier                                      { $$ = T1(@$,$1,@1); }
  ;
type_qualifier:
	const                                           { $$ = T1(@$,$1,@1); }
        | restrict                                      { $$ = T1(@$,$1,@1); }
	| volatile                                      { $$ = T1(@$,$1,@1); }
	;
  
  results: -1:  not found, -2:internal error, >=0: index into fi->ell
  
*/
int c_fi_va_specifier_qualifier_list(c_fi_type fi, c_ast_type n)
{
  int idx;
  int result_idx = -1;
  if ( c_ast_Is(n, c_str_specifier_qualifier_list) == 0 )
    return c_ast_err(), -2;

  n = n->d;
  while( n != NULL )
  {
    if ( c_ast_Is(n, c_str_type_specifier) != 0 )
    {
      idx = c_fi_va_type_specifier(fi, n);
    }
    else if ( c_ast_Is(n, c_str_type_qualifier) != 0 )
    {
      /* no further investigtion */
      idx = -1;
    }
    else
    {
      return c_ast_err(), -2;
    }
    if (  idx >= 0 )
      result_idx = idx;			/* can this assignment happen more than once??? is "(struct a struct b)" possible?*/
    n = n->n;
  }
  
  return result_idx;
}

/*
type_name:
  specifier_qualifier_list                              { $$ = T1(@$,$1,@1); }
  | specifier_qualifier_list abstract_declarator        { $$ = T2(@$,$1,@1,$2,@2); }
  ;

  results: -1:  not found, -2:internal error, >=0: index into fi->ell

*/
int c_fi_va_type_name(c_fi_type fi, c_ast_type n)
{
  if ( c_ast_Is(n, c_str_type_name) == 0 )
    return c_ast_err(), -2;
  /* currently only the specifier_qualifier_list is examined, this means that only 
  the return value of a function cast is considered */
  return c_fi_va_specifier_qualifier_list(fi,n->d);
}



/*======================================================================*/
/* Part 2: Traverse C file, handle all of the rw accessed */

typedef struct _dfs_state
{
  int idx;
  unsigned int r:1;
  unsigned int w:1;
  unsigned int exit:1;
} dfs_state;

#define CHILD_CMD_ALL 0
#define CHILD_CMD_FIRST 1

dfs_state c_fi_va_dfs(c_fi_type fi, c_ast_type n);


void dfs_state_clear(dfs_state *s)
{
  s->idx = -1;
  s->r = 0;
  s->w = 0;
  s->exit = 0;
}

void c_fi_va_mark_read(c_fi_type fi, int el_idx, const char *comment)
{
  c_el_type el;
  if ( el_idx < 0 )
    return;
  el = c_ell_GetEL(fi->ell, el_idx);
  c_log(3, "read from variable '%s' (idx %d, %s)\n", el->name, el_idx, comment);
  el->is_read = 1;
}

void c_fi_va_mark_write(c_fi_type fi, int el_idx, const char *comment)
{
  c_el_type el;
  if ( el_idx < 0 )
    return;
  el = c_ell_GetEL(fi->ell, el_idx);
  c_log(3, "write to variable '%s' (idx, %d, %s)\n", el->name, el_idx, comment);
  el->is_write = 1;
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
does not handle the first element
*/
int c_fi_va_postfix_expression(c_fi_type fi, c_ast_type n, int idx)
{
  int new_idx = idx;
  assert( c_ast_Is(n, c_str_postfix_expression) != 0 );
  n = n->d;
  if ( n == NULL )
    return new_idx; /* should never occur */
  n = n->n;
  while( n != NULL )
  {
    if ( c_ast_Is(n, c_str_dot) != 0 || c_ast_Is(n, c_str_arrow) != 0  )
    {
      if ( n->d == NULL )
	return c_ast_err(), -2;
      if ( n->d->d == NULL )
	return c_ast_err(), -2;
      if ( idx >= 0 )
      {
	new_idx = c_ell_GetMember(fi->ell, idx, n->d->d->s);
	if ( new_idx >= 0 )
	{
	  c_fi_va_mark_read(fi, idx, "struct/union/pointer");
	  c_log(5, "struct/union %d with member '%s' (%d)\n", idx, n->d->d->s, new_idx);
	  c_ell_log(fi->ell, idx, 5, "Member: ");
	}
      }
      else
      {
	c_log(4, "struct/union not found for member '%s'\n", n->d->d->s);
      }
    }
    else if ( c_ast_Is(n, c_str_inc) != 0 || c_ast_Is(n, c_str_dec) != 0 )
    {
      /* postfix in/decrement */
      c_fi_va_mark_read(fi, idx, "++/--");
      c_fi_va_mark_write(fi, idx, "++/--");
    }
    else if ( c_ast_Is(n, c_str_array) != 0 )
    {
      dfs_state result = c_fi_va_dfs(fi, n);
      c_fi_va_mark_read(fi, result.idx, c_str_array);
    }
    else if ( c_ast_Is(n, c_str_fnargs) != 0 )
    {
      /* call dfs, fnargs are handled there (c_def_argument_expression_list), so discard the result */
      c_fi_va_dfs(fi, n);
    }
    n = n->n;
  }
  return new_idx;
}

/*
  child_cmd: zeigt an, gibt an, welche pfade nach unten durchlaufen werden sollen.
    default sind alle.
  konkret wird hier verhindert, dass die member-variable auch als normaler identifier
  gematched wird. das wäre zwar egal, ist aber zeitverschwendung.
  tatsächlich gibt es aber noch einen zweiten grund, warum die member sowieso
  nicht gefunden werden: Die sind nämlich vom type "identifier_usertype"
*/
void c_fi_va_dfs_down(c_fi_type fi, c_ast_type n, int *child_cmd)
{
  *child_cmd = CHILD_CMD_ALL;
  if ( c_ast_Is(n, c_str_postfix_expression) != 0 )
    *child_cmd = CHILD_CMD_FIRST;
}


static const char *nodes_with_read_only_args[] = 
{
  c_def_mul_expression,
  c_def_div_expression,
  c_def_mod_expression,
  c_def_add_expression,
  c_def_sub_expression,
  c_def_shift_left_expression,
  c_def_shift_right_expression,
  c_def_lt_expression,
  c_def_gt_expression,
  c_def_lteq_expression,
  c_def_gteq_expression,
  c_def_eq_expression,
  c_def_neq_expression,
  c_def_and_expression,
  c_def_exclusive_or_expression,
  c_def_inclusive_or_expression,
  c_def_logical_and_expression,
  c_def_logical_or_expression,
  c_def_conditional_expression,
  c_def_for,
  c_def_while,
  c_def_do,
  c_def_switch,
  c_def_if,
  c_def_array,
  c_def_argument_expression_list
};

static const char *nodes_with_rw_assignment[] = 
{
  c_def_mul_assignment,
  c_def_div_assignment,
  c_def_mod_assignment,
  c_def_add_assignment,
  c_def_sub_assignment,
  c_def_left_shift_assignment,
  c_def_right_shift_assignment,
  c_def_and_assignment,
  c_def_xor_assignment,
  c_def_or_assignment
};


dfs_state c_fi_va_dfs_up(c_fi_type fi, c_ast_type n, dfs_state *array, size_t cnt)
{
  dfs_state result;
  int i, j;
  
  if ( cnt == 0 )
    dfs_state_clear(&result);
  else
    result = array[0];
  
  if ( c_ast_Is(n, c_str_identifier) != 0 )
  {
    result.idx = c_fi_ResolveIdentifier(fi, n);
  }
  else if ( c_ast_Is(n, c_str_cast_expression) != 0 )
  {
    if ( c_ast_Is(n->d, c_str_type_name) != 0 )
    {
      result.idx = c_fi_va_type_name(fi, n->d);
      if ( result.idx < 0 )
      {
	result = array[cnt-1];
      }
      else
      {
	/* do a read to the element which is now casted to something else */
	/* perhaps for the future: could store the cast target (result) in the original element, */
	/* so that we know all the casts... */
	c_fi_va_mark_read(fi, array[cnt-1].idx, "cast");
      }
    }
  }
  else if ( c_ast_Is(n, c_str_declarator) != 0 )
  {
    if ( cnt == 0 )
      dfs_state_clear(&result);
    else
      result = array[cnt-1];
  }
  else if ( c_ast_Is(n, c_str_postfix_expression) != 0 )
  {
    result = array[0];
    result.idx = c_fi_va_postfix_expression(fi, n, result.idx);
  }
  else if ( c_ast_Is(n, c_str_unary_expression) != 0 )
  {
    if ( cnt == 1 )
    {
      result = array[0];
    }
    if ( cnt == 2 )
    {
      /* prefix in/decrement */
      if ( c_ast_Is( n->d, c_str_inc) != 0 || c_ast_Is( n->d, c_str_dec) != 0 )
      {
	c_fi_va_mark_read(fi, array[1].idx, "++/--");
	c_fi_va_mark_write(fi, array[1].idx, "++/--");
	dfs_state_clear(&result);
      }
    }
  }
  else if ( c_ast_Is(n, c_str_direct_assignment) != 0 )
  {
    if ( cnt == 2 )
    {
	c_fi_va_mark_write(fi, array[0].idx, c_str_direct_assignment);
	c_fi_va_mark_read(fi, array[1].idx, c_str_direct_assignment);
	dfs_state_clear(&result);
    }
  }
  else if ( c_ast_Is(n, c_str_init_declarator) != 0 )
  {
    if ( cnt == 2 )
    {
	c_fi_va_mark_write(fi, array[0].idx, c_str_init_declarator);
	c_fi_va_mark_read(fi, array[1].idx, c_str_init_declarator);
	dfs_state_clear(&result);
    }
  }
  else if ( c_ast_Is(n, c_str_statement) != 0 )
  {
    c_fi_va_mark_read(fi, array[0].idx, c_str_statement);
    dfs_state_clear(&result);
  }
  else
  {
    for( i = 0; i < sizeof(nodes_with_read_only_args)/sizeof(*nodes_with_read_only_args); i++ )
    {
      if ( c_ast_Is(n, nodes_with_read_only_args[i]) != 0 )
      {
	for( j = 0; j < cnt; j++ )
	  c_fi_va_mark_read(fi, array[j].idx, nodes_with_read_only_args[i]);
	dfs_state_clear(&result);
	break;
      }
    }
    
    for( i = 0; i < sizeof(nodes_with_rw_assignment)/sizeof(*nodes_with_rw_assignment); i++ )
    {
      if ( c_ast_Is(n, nodes_with_rw_assignment[i]) != 0 )
      {
	c_fi_va_mark_read(fi, array[0].idx, nodes_with_rw_assignment[i]);
	c_fi_va_mark_write(fi, array[0].idx, nodes_with_rw_assignment[i]);
	for( j = 1; j < cnt; j++ )
	  c_fi_va_mark_read(fi, array[j].idx, nodes_with_rw_assignment[i]);
	dfs_state_clear(&result);
	break;
      }
    }
    
    
  }
  return result;
}

/* depth first search */
dfs_state c_fi_va_dfs(c_fi_type fi, c_ast_type n)
{
  c_ast_type loop;
  dfs_state *dfs_array;
  dfs_state result;
  size_t idx;
  int child_cmd = CHILD_CMD_ALL;
  
  /* count all childs, result is in "idx" */
  
  idx = 0;
  loop = n->d;
  while( loop != NULL )
  {
    idx++;
    loop = loop->n;
  }
  
  dfs_array = (dfs_state *)malloc(idx*sizeof(dfs_state));
  
  /* loop through the childs, fill the array */
  
  c_fi_va_dfs_down(fi, n, &child_cmd);
  
  if ( child_cmd ==  CHILD_CMD_ALL )
  {
    idx = 0;
    loop = n->d;
    while( loop != NULL )
    {
      dfs_array[idx] = c_fi_va_dfs(fi, loop);
      idx++;
      loop = loop->n;
    }
  }
  else if ( child_cmd == CHILD_CMD_FIRST )
  {
      dfs_array[0] = c_fi_va_dfs(fi, n->d);
      idx = 1;
  }
  else
  {
    idx = 0;
  }
  
  /* process the array, calculate the result */

  result = c_fi_va_dfs_up(fi, n, dfs_array, idx);
  
  /* free the array and return result */
  
  free(dfs_array);
  
  return result;
}

int c_fi_BuildVariableAccess(c_fi_type fi)
{
  c_fi_va_dfs(fi, fi->ast);
  return 1;
}

