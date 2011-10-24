
#include "c_fi.h"
#include "c_util.h"
#include <stdio.h>

int main(int argc, char **argv)
{
  if ( argc >= 2 )
  {
    c_fi_type fi = c_fi_OpenFile(argv[1]);
    if ( fi == NULL )
    {
      puts("file syntax error");
      return 1;         
    }
    c_fi_ShowAST(fi);
    printf("mem: %lu bytes\n", (unsigned long)c_fi_GetMemUsage(fi));
    c_fi_apply_file(fi);
    c_fi_Resolve(fi);
    c_ell_Show(fi->ell);
    if ( c_ell_Check(fi->ell) == 0 )
      c_log(0, "Check failed\n");
    /* c_fi_vap_test_recur(fi, fi->ast);*/
    c_fi_BuildVariableAccess(fi);

    c_fi_Close(fi);
  }
  return 1;
}

