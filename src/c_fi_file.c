/*

  c file interface
  

  Zentraler einsprungpunkt ist
    int c_fi_apply_file(c_fi_type fi)
  Das ist der erste schrit nach dem erstellen des AST. 
  Hier werden alle relevanten objecte extrahiert und in 
  der fi->ell liste gespeichert.
  

*/

#include <assert.h>
#include "c_fi.h"
#include "c_const.h"
#include "c_util.h"

int c_fi_apply_external_declaration(c_fi_type fi, c_ast_type n)
{
  if ( c_ast_Is(n, c_str_external_declaration) == 0 )
    return c_ast_err(), 0;
  
  if ( c_ast_Is(n->d, c_str_declaration) != 0 )
  {
    if ( c_fi_apply_declaration(fi, n->d) == 0 )
      return 0;
  }
  else if (c_ast_Is(n->d, c_str_function_definition) != 0 )
  {
    if ( c_fi_apply_function_definition(fi, n->d) == 0 )
      return 0;
  }
  else
    return c_ast_err(), 0;
    
  return 1;
}

int c_fi_apply_translation_unit(c_fi_type fi, c_ast_type n)
{
  c_ast_type external_declaration;
  if ( c_ast_Is(n, c_str_translation_unit) == 0 )
    return c_ast_err(), 0;
  external_declaration = n->d;
  while( external_declaration != NULL )
  {
    if ( c_fi_apply_external_declaration(fi, external_declaration) == 0 )
      return 0;
    external_declaration = external_declaration->n;
  }
  return 1;
}

int c_fi_apply_file(c_fi_type fi)
{
  c_ast_type n = fi->ast;
  if ( c_ast_Is(n, c_str_file) == 0 )
    return c_ast_err(), 0;
  return c_fi_apply_translation_unit(fi, n->d);
}

