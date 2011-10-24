
#include "b_ds.h"
#include <string.h>
#include <assert.h>

b_ds_type b_ds_Open(void)
{
  b_ds_type ds;
  ds = (b_ds_type)malloc(sizeof(struct _b_ds_struct));
  if ( ds != NULL )
  {
    ds->str = (char *)malloc(1);
    if ( ds->str != NULL )
    {
      ds->len = 1;
      ds->str[0] = '\0';
      return ds;
    }
    free(ds);
  }
  return NULL;
}

void b_ds_Close(b_ds_type ds)
{
  free(ds->str);
  ds->str = NULL;
  ds->len = 0;
  free(ds);
}

int b_ds_set_len(b_ds_type ds, size_t len)
{
  char *ptr;
  if ( len == ds->len )
    return 1;
  ptr = (char *)realloc(ds->str, len);
  if ( ptr == NULL )
    return 0;
  ds->str = ptr;
  ds->len = len;
  return 1;
}

int b_ds_Clear(b_ds_type ds)
{
  if ( b_ds_set_len(ds, 1) == 0 )
    return 0;
  ds->str[0] = '\0';
  return 1;
}

int b_ds_Add(b_ds_type ds, const char *s)
{
  size_t nlen; /* chars in s without '\0' */
  size_t olen;
  
  if ( s == NULL )
    return 0;
  
  assert( ds != NULL );
  assert( ds->str != NULL );
  assert( strlen(ds->str)+1 == ds->len );
  nlen = strlen(s);
  
  olen = ds->len;
  
  /*
    ds->len	--> including '\0'
    nlen		--> not including '\0'
    ds->len + nlen --> space for all chars plus one '\0'
  */
  if ( b_ds_set_len(ds, ds->len + nlen) == 0 )
    return 0;
  
  strcpy(ds->str + olen-1, s);
  return 1;
}

size_t b_ds_GetMemUsage(b_ds_type ds)
{
  return sizeof(struct _b_ds_struct)+ds->len;
}