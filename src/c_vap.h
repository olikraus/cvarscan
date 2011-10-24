/*

  variable access path 

  ERSETZT 


*/

#ifndef _C_VAP_H
#define _C_VAP_H


#include "b_il.h"

struct _c_vap_struct
{
  b_il_type el_idx_list;
  unsigned int is_read;
  unsigned int is_write;
};

typedef struct _c_vap_struct c_vap_struct;
typedef struct _c_vap_struct *c_vap_type;

c_vap_type c_vap_Open(void);
void c_vap_Close(c_vap_type vap);
int c_vap_Add(c_vap_type vap, int el_idx);
c_vap_type c_vap_OpenAdd(int el_idx);
int c_vap_GetLastElementIdx(c_vap_type vap);
int c_vap_Copy(c_vap_type dest, c_vap_type src);
c_vap_type c_vap_OpenCopy(c_vap_type src);


#endif


