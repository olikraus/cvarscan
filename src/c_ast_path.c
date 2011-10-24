

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "c_ast.h"
#include "c_const.h"
#include "b_pl.h"

/*
  return value:
    -1: error
    0: not found
    1: found
*/
static int c_ast_get_path(c_ast_type curr, c_ast_type dest, b_pl_type pl)
{
  if ( curr == dest )
  {
    return 1;
  }
  else 
  {
    if ( curr->d != NULL )
    {
      int r;
      if ( c_ast_Is(curr, c_str_compound_statement) != 0 )
      {
        if ( b_pl_Add(pl, curr) < 0 )
          return -1;
        r = c_ast_get_path(curr->d, dest, pl);
        if ( r != 0 )
          return r; /* error or found */
        if (b_pl_Cnt(pl) == 0 )
          return -1;
        b_pl_DelByPos(pl, b_pl_Cnt(pl)-1);
      }
      else
      {
        r = c_ast_get_path(curr->d, dest, pl);
        if ( r != 0 )
          return r; /* error or found */        
      }
    }
    if ( curr->n != NULL )
      return c_ast_get_path(curr->n, dest, pl);
  }
  return 0;
}

int c_ast_GetCompoundStatementPath(c_ast_type root, c_ast_type dest, b_pl_type pl)
{
  b_pl_Clear(pl);
  return c_ast_get_path(root, dest, pl);
}
