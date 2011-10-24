
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include "c_ast.h"
#include "c_const.h"

/*----------------------------------------------------------------------*/

extern FILE *c_yyin;
extern int c_yydebug;
extern c_ast_type c_result;
int c_yyparse(void);


c_ast_type c_ast_OpenFile(const char *filename)
{
  /* assign parser input file */
  if ( filename == NULL )
    c_yyin = stdin;
  else
    c_yyin = fopen(filename, "r");
  if ( c_yyin == NULL )
    return NULL;
  
  
  /* call parser */
  c_result = NULL;
  c_yydebug = 1;
  if ( c_yyparse() != 0 )
  {
    if ( filename != NULL )
      fclose(c_yyin);
    return NULL;
  }
  if ( filename != NULL )
    fclose(c_yyin);
  
  /* get result */
  return c_result;
}

