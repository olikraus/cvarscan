/*
  c_fi_id.c
  
  for an identifier in the ast find the entriy in fi->ell and return the index.
  
  16.2.2010: renamed c_fi_resolve.c to c_fi_id.c to avoid conflict with c_fi_Resolve() which was placed in c_fi_type.c
  
  
*/

#include "c_ast.h"
#include "c_util.h"
#include "c_fi.h"

/*
  for 'n' return its function_definition if available
  returns NULL of node 'n' is not a part of a function_definition
*/
static c_ast_type c_fi_get_function_definition(c_fi_type fi, c_ast_type n)
{
  return c_ast_FindByStrIfContains(fi->ast, c_str_function_definition, n);
}

/*
  below 'n' search for a init_declarator with 's' as identifier of the init_declarator_list
*/
static c_ast_type c_ast_get_init_declarator(c_ast_type n, const char *s)
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
static const char *c_ast_get_function_name(c_ast_type function_definition)
{
  c_ast_type declarator;
  c_ast_type direct_declarator;
  c_ast_type identifier;
  
  if ( c_ast_Is(function_definition, c_str_function_definition) == 0 )
    return c_ast_err(), NULL;
  if ( function_definition->d == NULL )
    return c_ast_err(), NULL;
  /* changed, function_definition->d can be empty if the function does not specify any return arg... 21.2.2010 */
  if ( function_definition->d->s != NULL )
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

int c_fi_fn_arg(c_fi_type fi, c_ast_type function_definition, c_ast_type n)
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

int c_fi_local_identifier(c_fi_type fi, c_ast_type function_definition, c_ast_type n)
{
  int i;
  c_ast_type compound_statement;
  c_ast_type init_declarator;
  int el_idx;
  
  if ( c_ast_Is(n, c_str_identifier) == 0 )
    return c_ast_err(), -1;

  /* calculate the ast_path for n */
  if ( c_ast_GetCompoundStatementPath(fi->ast, n, fi->ast_path) == 0 )
    return -1;
  i = b_pl_Cnt(fi->ast_path);
  while( i > 0 )
  {
    i--;
    compound_statement = b_pl_Get(fi->ast_path, i);
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
/* expects an identifier, returns index within ell */
int c_fi_ResolveIdentifier(c_fi_type fi, c_ast_type n)
{
  c_ast_type function_definition; 
  int el_idx;
  
  if ( c_ast_Is(n, c_str_identifier) == 0 )
    return c_ast_err(), -1;
  
  c_log(4, "lookup identifier '%s'\n", n->d->s);
  
  function_definition = c_fi_get_function_definition(fi, n);
  
  if ( function_definition != NULL )
  {
    
    /* is the identifier a local variable? */
    el_idx = c_fi_local_identifier(fi, function_definition, n);
    if ( el_idx >= 0 )
    {
      c_ell_log(fi->ell, el_idx, 4, "found local identifier");
      return el_idx;
    }
    
    /* is the identifier a function argument? */    
    el_idx = c_fi_fn_arg(fi, function_definition, n);
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

  