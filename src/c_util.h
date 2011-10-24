
#ifndef _C_UTIL_H
#define _C_UTIL_H

int c_set_name(char **s, const char *name);
void c_log(int level, const char *fmt, ...);	/* level 0: critical error, 1: error, >= 2 warnings */
void c_int_err_fn(const char *file, int line);
void c_ast_err_fn(const char *file, int line);
void c_mem_err_fn(const char *file, int line);

#define c_int_err() c_int_err_fn(__FILE__, __LINE__)
#define c_ast_err() c_ast_err_fn(__FILE__, __LINE__)
#define c_mem_err() c_mem_err_fn(__FILE__, __LINE__)

#endif

