
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include "c_util.h"

int c_set_name(char **s, const char *name)
{
  if ( *s != NULL )
    free(*s);
  *s = NULL;
  if ( name != NULL )
  {
    *s = strdup(name);
    if ( *s == NULL )
      return 0;
  }
  return 1;
}

void c_log(int level, const char *fmt, ...)
{
  va_list va;
  va_start(va, fmt);
  vprintf(fmt, va);
  va_end(va);
}

void c_int_err_fn(const char *file, int line)
{
  fprintf(stderr, "Internal error: %s:%d\n", file, line);
}


void c_ast_err_fn(const char *file, int line)
{
  fprintf(stderr, "Internal error (AST): %s:%d\n", file, line);
}

void c_mem_err_fn(const char *file, int line)
{
  fprintf(stderr, "Internal error (out of memory): %s:%d\n", file, line);
}

