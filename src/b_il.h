/*

  b_il.h

  basic integer list 

  Copyright (C) 2001 Oliver Kraus (olikraus@yahoo.com)

  
*/

#ifndef _B_IL_H
#define _B_IL_H

#include <stddef.h>
#include <stdio.h>

struct _b_il_struct
{
  int cnt;
  int max;
  int *list;
};
typedef struct _b_il_struct b_il_struct;
typedef struct _b_il_struct *b_il_type;

#define b_il_Cnt(il)     ((il)->cnt)
#define b_il_Get(il,pos) ((il)->list[pos])
#define b_il_GetLast(il) ((il)->list[b_il_Cnt(il)-1])
#define b_il_Clear(il)      ((il)->cnt = 0)

int b_il_init(b_il_type b_il);
int b_il_expand(b_il_type b_il);
int b_il_set_max(b_il_type b_il, int max);
void b_il_destroy(b_il_type b_il);


b_il_type b_il_Open();
b_il_type b_il_OpenVA(int cnt, ...);
int b_il_OpenMultiple(int cnt, ...);
void b_il_Close(b_il_type il);
void b_il_CloseMultiple(int cnt, ...);
int b_il_Find(b_il_type il, int val);
int b_il_Add(b_il_type il, int val);  /* returns position or -1 */
int b_il_AddUnique(b_il_type il, int val); /* returns position or -1 */
int b_il_AddVA(b_il_type il, int cnt, ...);
int b_il_SetVal(b_il_type il, int pos, int val);  /* returns 0 or 1 */
void b_il_Swap(b_il_type il, int p1, int p2);
void b_il_DelRange(b_il_type il, int pos, int cnt);
void b_il_DelByPos(b_il_type il, int pos);
void b_il_DelByVal(b_il_type il, int val);
int b_il_InsByPos(b_il_type il, int pos, int val);

int b_il_Copy(b_il_type dest, b_il_type src);
int b_il_CopyRange(b_il_type dest, b_il_type src, int start, int cnt);
int b_il_Cmp(b_il_type dest, b_il_type src);

int b_il_CmpValues(b_il_type il, int *values, int cnt);
int b_il_SetValues(b_il_type il, int *values, int cnt);
int *b_il_GetValues(b_il_type il, int *cnt);

void b_il_Sort(b_il_type il);
int b_il_IsElEq(b_il_type a, b_il_type b);
int b_il_CmpEl(b_il_type a, b_il_type b);
int b_il_IsSubSetEl(b_il_type a, b_il_type b);

int b_il_Write(b_il_type il, FILE *fp);
int b_il_Read(b_il_type il, FILE *fp);

int b_il_While(b_il_type il, int *pos);
int b_il_Loop(b_il_type il, int *pos, int *val);
int b_il_IsInvLoop(b_il_type il, int *pos, int *val, int is_inv);

size_t b_il_GetMemUsage(b_il_type il);

#endif
