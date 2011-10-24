/*

  c file interface

*/
#include <stdlib.h>
#include "c_fi.h"
#include "c_const.h"

c_fi_type c_fi_Open(void)
{
  c_fi_type fi;
  fi = (c_fi_type)malloc(sizeof(struct _c_fi_struct));
  if ( fi != NULL )
  {
    fi->ell = c_ell_Open();
    if ( fi->ell != NULL )
    {
      /*
      fi->vapl = c_vapl_Open();
      if ( fi->vapl != NULL )
      {
      */
        fi->ast_path = b_pl_Open();
        if ( fi->ast_path != NULL )
        {
          fi->ast = NULL;
          return fi;
    
        }
	  /*
        c_vapl_Close(fi->vapl);
      }
	  */
      c_ell_Close(fi->ell);
    }
    free(fi);
  }
  return NULL;
}

void c_fi_Clear(c_fi_type fi)
{
  /* c_vapl_ClearVAP(fi->vapl); */
  c_ell_ClearEL(fi->ell);
  c_ast_Close(fi->ast);
  fi->ast = NULL;
}

void c_fi_Close(c_fi_type fi)
{
  c_fi_Clear(fi);
  /*c_vapl_Close(fi->vapl);*/
  c_ell_Close(fi->ell);
  b_pl_Close(fi->ast_path);
  free(fi);
}

int c_fi_ReadFile(c_fi_type fi, const char *filename)
{
  c_fi_Clear(fi);
  fi->ast = c_ast_OpenFile(filename);
  if ( fi->ast ==  NULL )
    return 0;
  return 1;
}

c_fi_type c_fi_OpenFile(const char *filename)
{
  c_fi_type fi = c_fi_Open();
  if ( fi != NULL )
  {
    if ( c_fi_ReadFile(fi, filename) != 0 )
    {
      return fi;
    }
    c_fi_Close(fi);
  }
  return NULL;
}

void c_fi_ShowAST(c_fi_type fi)
{
  c_ast_Show(fi->ast);
}

size_t c_fi_GetMemUsage(c_fi_type fi)
{
  size_t m = sizeof(struct _c_fi_struct);
  m += c_ast_GetMemUsage(fi->ast);
  m += c_ell_GetMemUsage(fi->ell);
  return m;
}



