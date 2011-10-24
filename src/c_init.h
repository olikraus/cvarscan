/*

  c_init.h
  
  list of init lines (=assignments)
  
  inner object: iline (init line)
  list of iline: ils (init lines)
  
*/

#ifndef _C_INIT_H
#define _C_INIT_H


#include "b_pl.h"
#include "b_ds.h"

struct _c_iline_struct
{
  b_ds_type left;
  b_ds_type right;
};
typedef struct _c_iline_struct *c_iline_type;

struct _c_ils_struct
{
  int is_nl;
  b_pl_type list;
};
typedef struct _c_ils_struct *c_ils_type;

#define c_ils_Cnt(c) b_pl_Cnt((c)->list)
#define c_ils_GetIline(c,pos) ((c_iline_type)b_pl_Get((c)->list,(pos)))
#define c_ils_WhileEL(c,ptr_pos) b_pl_While((c)->list,(ptr_pos))

c_ils_type c_ils_Open();
void c_ils_Clear(c_ils_type ils);
void c_ils_Close(c_ils_type ils);

int c_ils_AddIline(c_ils_type ils);
c_iline_type c_ils_NewIline(c_ils_type ils);
int c_ils_AddLeft(c_ils_type ils, const char *s);
int c_ils_AddRight(c_ils_type ils, const char *s);
int c_ils_NL(c_ils_type ils);
void c_ils_Show(c_ils_type ils);

#endif

