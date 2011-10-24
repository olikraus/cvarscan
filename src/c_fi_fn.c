/*

  c file interface funktion
  
*/

#include <assert.h>
#include "c_fi.h"
#include "c_const.h"
#include "c_util.h"

int c_fi_apply_fn_decl(c_fi_type fi, c_ast_type n)
{
  if ( n == NULL )
    return 1;
  if ( c_ast_Is(n, c_str_declaration) != 0 )
    return c_fi_apply_declaration(fi, n);
  if ( c_fi_apply_fn_decl(fi, n->d) == 0 )
    return 0;
  return c_fi_apply_fn_decl(fi, n->n);
}

int c_fi_apply_function_definition(c_fi_type fi, c_ast_type n)
{
  c_ast_type declaration_specifiers; 
  c_ast_type declarator;
  c_ast_type declaration_list; 
  c_ast_type compound_statement;
  c_el_type el;
  int el_pos;
  
  
  if ( c_ast_Is(n, c_str_function_definition) == 0 )
    return c_ast_err(), 0;
  
  declaration_specifiers = n->d;
  /* declaration_specifiers must not be NULL, but it can be empty e.g. for "main(int a)" where the return defaults to int" */
  if ( declaration_specifiers == NULL )  /* must not be the NULL pointer */
    return c_ast_err(), 0;
  /* the name is declaration_specifiers, but it might be empty, check changed 21.2.2010 */
  if ( declaration_specifiers->s != NULL )
    if ( c_ast_Is(declaration_specifiers, c_str_declaration_specifiers) == 0 )
      return c_ast_err(), 0;
  declarator = n->d->n;
  if ( c_ast_Is(declarator, c_str_declarator) == 0 )
    return c_ast_err(), 0;
  declaration_list = n->d->n->n;
  if ( declaration_list == NULL )
    return c_ast_err(), 0;
  compound_statement = n->d->n->n->n;
  if ( c_ast_Is(compound_statement, c_str_compound_statement) == 0 )
    return c_ast_err(), 0;
  
  el_pos = c_fi_AddEL(fi);
  if ( el_pos < 0 )
    return 0;
  el = c_fi_GetEL(fi, el_pos);
  c_ell_log(fi->ell, el_pos, 4, "function created");
  el->element = C_EL_FN_DEF;
  el->is_function = 1;	
  
  if ( c_fi_apply_declaration_specifiers(fi, el, declaration_specifiers) == 0 )
    return 0;
  
  if ( c_fi_apply_declarator(fi, el, declarator) == 0 )
    return 0;
  
  /* todo: declaration_list (K&R) */
  
  /* put local def's to the element array */
  el->ast_compound_statement = compound_statement;
  if ( c_fi_apply_fn_decl(fi, compound_statement) == 0 )
    return 0;
  
  return 1;
}


int c_fi_add_fn_call(c_fi_type fi, c_el_type el, c_ast_type n)
{
  int fn_pos;
  
  if ( c_ast_Is(n, c_str_postfix_expression) == 0 )
    return 0;
  if ( c_ast_FindChildByStr(n, c_str_fnargs) == NULL )
    return 0;
  if ( c_ast_FindChildByStr(n->d, c_str_identifier) == NULL )
  {
    c_log(1, "function pointer are not supported\n");
    /* todo: some more output */
    return 1;
  }
    
  fn_pos = c_ell_FindFnDef(fi->ell, n->d->s);
  if ( fn_pos < 0 )
    fn_pos = c_ell_FindFnDecl(fi->ell, n->d->s);
  if ( fn_pos < 0 )
  {
    /*  todo: create dummy function */
    return 1;
  }
  if ( c_el_AddCallsTo(el, fn_pos) == 0 )
    return 0;
  return 1;
}

/*
  find function calls
  a function call is a postfix_expression with a fnargs member
*/
int c_fi_recur_find_calls(c_fi_type fi, c_el_type el, c_ast_type n)
{
    if ( c_ast_Is(n, c_str_postfix_expression) != 0 )
    {
      if ( c_ast_FindChildByStr(n, c_str_fnargs) != NULL )
      {
        c_fi_add_fn_call(fi, el, n);
        /* todo: add fn call */
        return 1;
      }
    }
    if ( c_fi_recur_find_calls(fi, el, n->d) == 0 )
      return 0;
    if ( c_fi_recur_find_calls(fi, el, n->n) == 0 )
      return 0;
    return 1;
}

