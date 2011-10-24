/*

  c_init.c
  
  list of init assignments
  
  iline = init line
  ils = init line's
  
  
  
*/


#include <stdlib.h>
#include "c_util.h"
#include "c_init.h"


c_iline_type c_iline_Open(void)
{
  c_iline_type iline = (c_iline_type)malloc(sizeof(struct _c_iline_struct));
  if ( iline != NULL )
  {
    iline->left = b_ds_Open();
    if ( iline->left != NULL ) 
    {
      iline->right = b_ds_Open();
      if ( iline->right != NULL )
      {
	return iline;
      }
      else
      {
	c_mem_err();
      }
      b_ds_Close(iline->left);
    }
    else
    {
      c_mem_err();
    }
    free(iline);
  }
  else
  {
    c_mem_err();
  }
  return NULL;
}

void c_iline_Close(c_iline_type iline)
{
  b_ds_Close(iline->left);
  b_ds_Close(iline->right);
  free(iline);
}

int c_iline_AddLeft(c_iline_type iline, const char *s)
{
  if ( b_ds_Add(iline->left, s) == 0 )
    return c_mem_err(), 0;
  return 1;
}

int c_iline_AddRight(c_iline_type iline, const char *s)
{
  if ( b_ds_Add(iline->right, s) == 0 )
    return c_mem_err(), 0;
  return 1;
}

void c_iline_Show(c_iline_type iline)
{
  if ( *iline->right->str  == '\0' )
    printf("%s;\n", iline->left->str);
  else
    printf("%s=%s;\n", iline->left->str, iline->right->str);
}

c_ils_type c_ils_Open()
{
  c_ils_type ils;
  ils = (c_ils_type)malloc(sizeof(struct _c_ils_struct));
  if ( ils != NULL )
  {
    ils->list = b_pl_Open();
    if ( ils->list != NULL )
    {
      ils->is_nl = 0;
      return ils;
    }
    else
    {
      c_mem_err();
    }
  }
  else
  {
    c_mem_err();
  }
  return NULL;
}

void c_ils_Clear(c_ils_type ils)
{
  int i = -1;
  c_iline_type iline;
  ils->is_nl = 0;
  while( c_ils_WhileEL(ils,&i) )
  {
    iline = c_ils_GetIline(ils, i);
    c_iline_Close(iline);
  }
  b_pl_Clear(ils->list);
}

void c_ils_Close(c_ils_type ils)
{
  c_ils_Clear(ils);
  b_pl_Close(ils->list);
  free(ils);
}

int c_ils_AddIline(c_ils_type ils)
{
  c_iline_type iline;
  int idx;
  iline = c_iline_Open();
  if ( iline == NULL )
    return -1;
  idx = b_pl_Add(ils->list, iline);
  if ( idx < 0 )
  {
    c_iline_Close(iline);
    c_mem_err();
  }
  return idx;  
}

c_iline_type c_ils_NewIline(c_ils_type ils)
{
  int idx = c_ils_AddIline(ils);
  if ( idx < 0 )
    return NULL;
  return c_ils_GetIline(ils, idx);
}

c_iline_type c_ils_GetLastIline(c_ils_type ils)
{
  if ( ils == NULL )
    return NULL;
  if ( c_ils_Cnt(ils) == 0 )
    return c_ils_NewIline(ils);
  return c_ils_GetIline(ils, c_ils_Cnt(ils)-1);  
}

int c_ils_AddLeft(c_ils_type ils, const char *s)
{
  c_iline_type iline;
  if ( ils == NULL )
    return 1;
  iline = c_ils_GetLastIline(ils);
  if ( iline == NULL )
    return 0;
  if ( ils->is_nl != 0 )
  {
    iline = c_ils_NewIline(ils);
    ils->is_nl = 0;
    if ( iline == NULL )
      return 0;
  }
  return c_iline_AddLeft(iline, s);
}

int c_ils_AddRight(c_ils_type ils, const char *s)
{
  c_iline_type iline;
  if ( ils == NULL )
    return 1;
  iline = c_ils_GetLastIline(ils);
  if ( iline == NULL )
    return 0;
  if ( ils->is_nl != 0 )
  {
    iline = c_ils_NewIline(ils);
    ils->is_nl = 0;
    if ( iline == NULL )
      return 0;
  }
  return c_iline_AddRight(iline, s);
}

int c_ils_NL(c_ils_type ils)
{
  if ( ils == NULL )
    return 1;
  ils->is_nl = 1;
  return 1;
}

void c_ils_Show(c_ils_type ils)
{
  int i = -1;
  c_iline_type iline;
  ils->is_nl = 0;
  while( c_ils_WhileEL(ils,&i) )
  {
    iline = c_ils_GetIline(ils, i);
    printf("ILS %03d: ", i);
    c_iline_Show(iline);
  }
}
