/*

  c file interface

*/

#ifndef _C_FI_H
#define _C_FI_H

#include "c_ast.h"
#include "c_ell.h"
#include "c_vapl.h"
#include "b_pl.h"


typedef struct _c_fi_struct *c_fi_type;

struct _c_fi_struct
{
  c_ast_type ast;
  c_ell_type ell;
  /* c_vapl_type vapl; */
  
  /* a local variable of c_vap_identifier() */
  b_pl_type ast_path;
};

/* c_fi.c */

c_fi_type c_fi_Open();
void c_fi_Clear(c_fi_type fi);
void c_fi_Close(c_fi_type fi);
c_fi_type c_fi_OpenFile(const char *filename);
int c_fi_ReadFile(c_fi_type fi, const char *filename);
void c_fi_ShowAST(c_fi_type fi);
size_t c_fi_GetMemUsage(c_fi_type fi);

#define c_fi_CntEL(fi) c_ell_Cnt((fi)->ell)
#define c_fi_AddEL(fi) c_ell_AddEL((fi)->ell)
#define c_fi_GetEL(fi,pos) c_ell_GetEL((fi)->ell,(pos))
#define c_fi_NewEL(fi) c_ell_NewEL((fi)->ell)


/* c_fi_file.c */

/* extract information from fi->ast and store the information in fi->ell */
int c_fi_apply_file(c_fi_type fi);

/* c_fi_decl.c */

/* functions called by c_fi_apply_file() */ 
int c_fi_apply_storage_class_specifier(c_fi_type fi, c_el_type el, c_ast_type n);
int c_fi_apply_type_qualifier_list(c_fi_type fi, c_tq_type tq, c_ast_type n);
int c_fi_apply_specifier_qualifier_list(c_fi_type fi, c_el_type el, c_ast_type n);
int c_fi_apply_struct_declarator(c_fi_type fi, c_el_type el, c_ast_type n);
int c_fi_apply_struct_declarator_list(c_fi_type fi, c_el_type parent, c_el_type el, c_ast_type n);
int c_fi_apply_struct_declaration(c_fi_type fi, c_el_type parent, c_ast_type n);
int c_fi_apply_struct_or_union_specifier(c_fi_type fi, c_el_type el, c_ast_type n);
int c_fi_apply_type_specifier(c_fi_type fi, c_el_type el, c_ast_type n);
int c_fi_apply_type_qualifier(c_fi_type fi, c_tq_type tq, c_ast_type n);
int c_fi_apply_function_specifier(c_fi_type fi, c_el_type el, c_ast_type n);
int c_fi_apply_declaration_specifiers(c_fi_type fi, c_el_type el, c_ast_type n);
int c_fi_apply_declarator_square_bracket(c_fi_type fi, c_el_type el, c_ast_type n);
int c_fi_apply_pointer(c_fi_type fi, c_el_type el, c_ast_type n);
int c_fi_apply_parameter_declaration(c_fi_type fi, c_el_type el, c_ast_type n);
int c_fi_apply_parameter_list(c_fi_type fi, c_el_type el, c_ast_type n);
int c_fi_apply_declarator_parenthesis(c_fi_type fi, c_el_type el, c_ast_type n);
int c_fi_apply_declarator(c_fi_type fi, c_el_type el, c_ast_type n);
int c_fi_apply_init_declarator(c_fi_type fi, c_el_type el, c_ast_type n);
int c_fi_apply_declaration(c_fi_type fi, c_ast_type n);

/* c_fi_type.c */

int c_fi_ResolveAllTypenames(c_fi_type fi);	/* called c_fi_Resolve() */ 
int c_fi_ResolveAllSU(c_fi_type fi);			/* called c_fi_Resolve() */ 
int c_fi_Resolve(c_fi_type fi);


/* c_fi_fn.c */
/* function called by c_fi_apply_file() */ 
int c_fi_apply_function_definition(c_fi_type fi, c_ast_type n);

/* c_vap.c */
void c_fi_vap_test_recur(c_fi_type fi, c_ast_type n);

/* c_fi_va.c */
int c_fi_BuildVariableAccess(c_fi_type fi);

/* c_fi_id.c */
int c_fi_ResolveIdentifier(c_fi_type fi, c_ast_type n);


#endif /* _C_FI_H */

