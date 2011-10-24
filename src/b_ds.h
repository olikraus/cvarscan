
/* dynamic string */

#ifndef _B_DS_H
#define _B_DS_H
#include <stdlib.h>

struct _b_ds_struct
{
  size_t len;	/* the number of allocated bytes (including '\0') */
  char *str;
};
typedef struct _b_ds_struct *b_ds_type;

b_ds_type b_ds_Open(void);
void b_ds_Close(b_ds_type ds);
int b_ds_Clear(b_ds_type ds);
int b_ds_Add(b_ds_type ds, const char *s);
size_t b_ds_GetMemUsage(b_ds_type ds);


#endif 

