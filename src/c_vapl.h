/*

  variable access path list
  
*/

#ifndef _C_VAPL_H
#define _C_VAPL_H


#include "c_vap.h"
#include "b_pl.h"

struct _c_vapl_struct
{
  b_pl_type vap_list;
  /* tmp storage... r/w status will be copied to the vap object */
  int is_read;
  int is_write;
};
typedef struct _c_vapl_struct c_vapl_struct;
typedef struct _c_vapl_struct *c_vapl_type;

#define c_vapl_Cnt(c) b_pl_Cnt((c)->vap_list)
#define c_vapl_GetVAP(c,pos) ((c_vap_type)b_pl_Get((c)->vap_list,(pos)))
#define c_vapl_WhileVAP(c,ptr_pos) b_pl_While((c)->vap_list,(ptr_pos))

c_vapl_type c_vapl_Open(void);
void c_vapl_ClearVAP(c_vapl_type vapl);
void c_vapl_Close(c_vapl_type vapl);

int c_vapl_AddUniqueCopyWithRW(c_vapl_type vapl, c_vap_type src, int is_r, int is_w);


#endif
