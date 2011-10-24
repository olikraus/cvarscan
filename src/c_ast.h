

#ifndef _C_AST_H
#define _C_AST_H

#include <stddef.h>
#include <stdarg.h>

#include "c_const.h" 
#include "b_pl.h" 

struct _c_loc_struct
{
  /* use same names as bison, so that YYLLOC_DEFAULT */
  /* must not be redefined */
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};

typedef struct _c_loc_struct c_loc_struct;

typedef struct _c_ast_struct *c_ast_type;

struct _c_ast_struct
{
  const char *s;        /* string */
  c_loc_struct l;       /* location */
  c_ast_type d;         /* down */
  c_ast_type n;         /* next */
};




c_ast_type c_ast_Open(const char *s, c_loc_struct *l);
c_ast_type c_ast_OpenNIL(void);
c_ast_type c_ast_OpenChildren(const char *s, c_loc_struct *l, int n, ...);
void c_ast_Close(c_ast_type ast);
size_t c_ast_GetMemUsage(c_ast_type ast);
c_ast_type c_ast_AddChild(c_ast_type parent, c_ast_type child);
c_ast_type c_ast_AddChildFirst(c_ast_type parent, c_ast_type child);
c_ast_type c_ast_AddVAChildren(c_ast_type parent, int n, va_list va);
c_ast_type c_ast_AddChildren(c_ast_type parent, int n, ...);
void c_ast_Push(c_ast_type n);
c_ast_type c_ast_Pop(c_loc_struct *l);
c_ast_type c_ast_Last(void);

int c_ast_Is(c_ast_type n, const char *s);
int c_ast_IsN(c_ast_type n, int cnt, ...);
c_ast_type c_ast_FindChildByStr(c_ast_type n, const char *s);
c_ast_type c_ast_GetParent(c_ast_type start, c_ast_type n);
c_ast_type c_ast_FindByStrIfContains(c_ast_type start, const char *s, c_ast_type inside);

c_ast_type c_ast_chk_init_declarator_list(c_ast_type n, const char *s);


/* expect declarator */
const char *c_ast_get_declarator_identifier(c_ast_type n);

int c_is_typedef(const char *s);

void c_ast_show_location(c_ast_type n, FILE *fp);
void c_ast_Show(c_ast_type n);

c_ast_type c_ast_OpenFile(const char *filename);

/* c_ast_path.c */

int c_ast_GetCompoundStatementPath(c_ast_type root, c_ast_type dest, b_pl_type pl);

#endif /* _C_AST_H */

