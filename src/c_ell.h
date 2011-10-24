
#ifndef _C_CLL_H
#define _C_CLL_H

#include "b_pl.h"
#include "b_ds.h"
#include "c_el.h"

typedef struct _c_ell_struct *c_ell_type;

struct _c_ell_struct
{
  b_pl_type el_list;
  
  /* converted MTQL string */
  size_t c_mtql_len;
  char *c_mtql_str;

  /* converted init string */
  /* b_ds_type init_ds; */
  
  /* converted init string for function calls */
  /* b_ds_type fn_ds; */
  
};

#define c_ell_Cnt(c) b_pl_Cnt((c)->el_list)
#define c_ell_GetEL(c,pos) ((c_el_type)b_pl_Get((c)->el_list,(pos)))
#define c_ell_WhileEL(c,ptr_pos) b_pl_While((c)->el_list,(ptr_pos))

c_ell_type c_ell_Open();
void c_ell_ClearEL(c_ell_type c);
void c_ell_Close(c_ell_type ell);
int c_ell_AddEL(c_ell_type ell);
c_el_type c_ell_NewEL(c_ell_type ell);
void c_ell_log(c_ell_type ell, int el_pos, int level, const char *pre);

int c_ell_FindStructUnionMember(c_ell_type ell, int el_idx, const char *s);
int c_ell_FindFnDef(c_ell_type ell, const char *s);
int c_ell_FindFnDecl(c_ell_type ell, const char *s);
int c_ell_FindTypedef(c_ell_type ell, const char *s);
int c_ell_FindSUTypedef(c_ell_type ell, int su_el_idx, int ptr_refs);
int c_ell_FindGlobalVar(c_ell_type ell, const char *s);
int c_ell_FindDeclaredSU(c_ell_type ell, const char *s);
int c_ell_FindSU(c_ell_type ell, const char *s);
int c_ell_FindByElementAndName(c_ell_type ell, int element, const char *s);
int c_ell_FindByASTInitDeclarator(c_ell_type ell, c_ast_type init_declarator);
int c_ell_FindByFnAndArg(c_ell_type ell, const char *fn, const char *arg);

void c_ell_ClearVisited(c_ell_type ell);
#define C_ELL_VISIT_PRE 0
#define C_ELL_VISIT_POST 1
int c_ell_Visit(c_ell_type ell, int el_idx, int top_el_idx, int (*fn)(int msg, c_ell_type ell, int el_idx, int top_el_idx));

c_ils_type c_ell_GetIls(c_ell_type ell, int el_idx);


int c_ell_AssignMTQL(c_ell_type ell, int el_idx);


int c_ell_GetMember(c_ell_type ell, int el_idx, const char *member);


void c_ell_Show(c_ell_type ell);
int c_ell_Check(c_ell_type ell);

size_t c_ell_GetMemUsage(c_ell_type ell);

/* c_mtql.c */
const char *c_ell_ConvertMTQLToC(c_ell_type ell, int el_idx, int start_idx, int top_el_idx);

const char *c_ell_GetInitStr(c_ell_type ell, int el_idx);
const char *c_ell_GetFnInitStr(c_ell_type ell, int el_idx);		/* called by c_ell_GetInitStr() */
int c_ell_BuildAllILS(c_ell_type ell);


#endif /* _C_CLL_H */
