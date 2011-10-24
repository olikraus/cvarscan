/*

  variable access path list
  
*/

#include <stdlib.h>
#include "c_vapl.h"

static int b_il_ordered_compare(b_il_type il1, b_il_type il2)
{
  int i, cnt;
  if ( b_il_Cnt(il1) != b_il_Cnt(il2) )
    return 0;
  cnt = b_il_Cnt(il1);
  for(i = 0; i < cnt; i++ )
    if ( b_il_Get(il1, i) != b_il_Get(il2, i) )
      return 0;
  return 1;
}

c_vapl_type c_vapl_Open(void)
{
  c_vapl_type vapl;
  vapl = (c_vapl_type)malloc(sizeof(c_vapl_struct));
  if ( vapl != NULL )
  {
    vapl->vap_list = b_pl_Open();
    if ( vapl->vap_list != NULL )
    {
      return vapl;
    }
    free(vapl);
  }
  return NULL;
}

void c_vapl_ClearVAP(c_vapl_type vapl)
{
  int i = -1;
  c_vap_type vap;
  while( c_vapl_WhileVAP(vapl,&i) != 0 )
  {
    vap = c_vapl_GetVAP(vapl, i);
    c_vap_Close(vap);
  }
  b_pl_Clear(vapl->vap_list);
}

void c_vapl_Close(c_vapl_type vapl)
{
  c_vapl_ClearVAP(vapl);
  b_pl_Close(vapl->vap_list);
  free(vapl);
}

int c_vapl_Add(c_vapl_type vapl, c_vap_type vap)
{
  if ( vap == NULL )
    return -1;
  return b_pl_Add(vapl->vap_list, vap);
}

int c_vapl_Find(c_vapl_type vapl, b_il_type il)
{
  int i = -1;
  c_vap_type vap;
  while( c_vapl_WhileVAP(vapl,&i) != 0 )
  {
    vap = c_vapl_GetVAP(vapl, i);
    if ( b_il_ordered_compare(vap->el_idx_list, il) != 0 )
      return i;
  }
  return -1;
}

/*
  add arg vap to vapl. if vap->el_idx_list already exists,
  arg vap is closed

  rw status is ORed with an existing vap

  returns the added vap
*/
int c_vapl_AddUnique(c_vapl_type vapl, c_vap_type vap)
{
  c_vap_type v;
  int pos = c_vapl_Find(vapl, vap->el_idx_list);
  if ( pos < 0 )
    return c_vapl_Add(vapl, vap);
  v = c_vapl_GetVAP(vapl, pos);
  v->is_read |= vap->is_read;
  v->is_write |= vap->is_write;
  c_vap_Close(vap);
  return pos;
}


int c_vapl_AddCopy(c_vapl_type vapl, c_vap_type vap)
{
  return c_vapl_Add(vapl, c_vap_OpenCopy(vap));
}

int c_vapl_AddUniqueCopy(c_vapl_type vapl, c_vap_type vap)
{
  c_vap_type v;
  int pos = c_vapl_Find(vapl, vap->el_idx_list);
  if ( pos < 0 )
    return c_vapl_AddCopy(vapl, vap);
  v = c_vapl_GetVAP(vapl, pos);
  v->is_read |= vap->is_read;
  v->is_write |= vap->is_write;
  return pos;
}

/*
int c_vapl_AddCopyWithRW(c_vapl_type vapl, c_vap_type src, int is_r, int is_w)
{
  c_vap_type vap;
  vap = c_vap_OpenCopy(src);
  if ( vap == NULL )
    return -1;
  vap->is_read |= is_r;
  vap->is_write |= is_w;
  src->is_read = 0;
  src->is_write = 0;
  return c_vapl_Add(vapl, vap);
}
*/

/*
  add a unique copy of 'src' to 'vapl'
  clear's rw status in 'src'
  OR's is_r and is_w into the unique element in vapl

  returns the position of the added (or existing) element or -1
*/
int c_vapl_AddUniqueCopyWithRW(c_vapl_type vapl, c_vap_type src, int is_r, int is_w)
{
  int pos;
  if ( src == NULL )
    return -1;
  pos = c_vapl_AddUniqueCopy(vapl, src);
  if ( pos >= 0 )
  {
    c_vap_type vap = c_vapl_GetVAP(vapl, pos);
    vap->is_read |= is_r;
    vap->is_write |= is_w;
    src->is_read = 0;
    src->is_write = 0;
    
  }
  return pos;
}


