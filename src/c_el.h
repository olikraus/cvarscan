/*

  c_el.h
  
  c element (e.g. declaration or definition, but also members)
  
*/

#ifndef _C_EL_H
#define _C_EL_H

#include "b_il.h"
#include "b_pl.h"
#include "b_ds.h"

#include "c_ast.h"
#include "c_init.h"


typedef struct _c_tq_struct *c_tq_type;
typedef struct _c_ad_struct *c_ad_type;
typedef struct _c_dt_struct *c_dt_type;
typedef struct _c_el_struct *c_el_type;
typedef struct _c_mtq_struct *c_mtq_type;
typedef struct _c_mtql_struct *c_mtql_type;


/* type qualifier */
struct _c_tq_struct
{
  unsigned int is_const:1;
  unsigned int is_volatile:1;
  unsigned int is_restrict:1;
};

/* array dimension */
struct _c_ad_struct
{
  /* c_ast_type expression; */          /* != NULL --> variable length array */
  struct _c_tq_struct tq;
  unsigned int dimension;               /* the integer type depends on the target processor */
  /* dimensions < 0 --> VL array */
  unsigned int is_static;
};

/* dt direct type, types which are directly available such like unsigned short */

#define C_DT_VOID 0
#define C_DT_CHAR 1
#define C_DT_SIGNED_CHAR 2
#define C_DT_UNSIGNED_CHAR 3
#define C_DT_SIGNED_SHORT 4
#define C_DT_UNSIGNED_SHORT 5
#define C_DT_SIGNED_INT 6
#define C_DT_UNSIGNED_INT 7
#define C_DT_SIGNED_LONG 8
#define C_DT_UNSIGNED_LONG 9
#define C_DT_SIGNED_LONG_LONG 10
#define C_DT_UNSIGNED_LONG_LONG 11
#define C_DT_FLOAT 12
#define C_DT_DOUBLE 13
#define C_DT_LONG_DOUBLE 14

struct _c_dt_struct
{
  
  /* direct type */

  unsigned int is_unsigned:1; 
  unsigned int is_signed:1; 

  unsigned int is_char:1; 
  unsigned int is_short:1; 
  unsigned int is_int:1; 
  unsigned int is_long:1; 
  unsigned int is_long_long:1; 
  unsigned int is_float:1; 
  unsigned int is_double:1; 

  unsigned int is_void:1;
  
  unsigned int is_bool:1;
  unsigned int is_imaginary:1;
  unsigned int is_complex:1;
  
  /* result */

  int derived_type; /* one of C_DT_xxxx */

};


/* c_el_Open() */
#define C_EL_NONE           0

/* int c_fi_apply_declaration(c_fi_type fi, c_ast_type n) */
#define C_EL_DECLARATION 1

/* int c_fi_apply_struct_or_union_specifier(c_fi_type fi, c_el_type el, c_ast_type n) */
/* die drei folgenden defines gibt es nicht mehr. sie sollten NICHT mehr verwendet werden */
#define C_EL_STRUCT         3
#define C_EL_UNION          4
#define C_EL_ENUM           5

/* int c_fi_apply_function_definition(c_fi_type fi, c_ast_type n) */
#define C_EL_FN_DEF 6

#define C_EL_MEMBER    9
#define C_EL_ARGUMENT      10
#define C_EL_RETURN_VALUE 11

#define C_EL_DECLARATOR_CHAIN 12


/*
#define C_EL_VARIABLE       1
#define C_EL_TYPEDEF        2
#define C_EL_ENUM           5
#define C_EL_FUNCTION       6
#define C_EL_MEMBER_STRUCT  7
#define C_EL_MEMBER_UNION   8
#define C_EL_MEMBER_ENUM    9
#define C_EL_ARGUMENT      10
*/

struct _c_el_struct
{
  /*
    Element is one of
    C_EL_NONE         
    if "is_typedef" is set, the whole element is a typedef. "name" is the new type
    A typedef either referes to an object (complex_type_ref) or does a typedef of atomic elements  
    C_EL_STRUCT        struct        -multi-ref-> <empty>, struct member		--> OBSOLETE (1.3.2010) --> is_struct
    C_EL_UNION         union         -multi-ref-> <empty>, union member		--> OBSOLETE (1.3.2010) --> is_union
    C_EL_ENUM          enum          -multi-ref-> <empty>, enum member		--> OBSOLETE (1.3.2010) --> is_enum
    
   (C_EL_FN_DEF , C_EL_DECLARATION, C_EL_DECLARATOR_CHAIN) and is_function != 0   
          function      -multi-ref-> <empty>, arg member
    Note: C_EL_DECLARATOR_CHAIN is a function e.g. for function pointer.
  
    C_EL_MEMBER   -single-ref-> <empty>
    C_EL_ARGUMENT      arg member    -single-ref-> <empty>, struct, union, enum, typedef
  
    single_ref : b_il_Cnt(ref_list) == 1 || == 0 
    multi-ref : b_il_Cnt(ref_list) >= 0 
       
  */
    
  
  int element;

  /* the name of the element */ 
  char *name;
  /*c_ast_type ast_name;*/	/* str_identifier */  
  b_pl_type ast_path;           /* the path to the current element (compound_statement list) */
  /* c_ast_type ast_scope; */
  c_ast_type ast_declaration;   /* can be declaration, parameter declaration or struct declaration */
  c_ast_type ast_declarator; 	/* declarator or abstract declarator */
  c_ast_type ast_init_declarator;       /* AST node of the c_init_declarator */
  c_ast_type ast_compound_statement;

  /* braucht man das? --> befüllt in c_fi_apply_type_specifier */
  char *su_name;        /* name of the struct or union */
  
  char *td_name;        /* typedef name (only if is_typedef_name is set), used by decls where the type  is  a usedde'd type */
  int td_idx;               /* idx of the typedef element; todo: merge with complex_type_ref */

  /* graph search */
  unsigned int is_visited:1;	/* c_ell_Check() */

  /* identify stuct/union member */
  unsigned int is_su_member:1;
  

  unsigned int is_struct_or_union_specifier:1;
  unsigned int is_su_decl_list:1;		/* if a structure or union declaration (=member) list exists... anhand der ref list läßt sich nicht entscheiden, ob es eine decl_list gibt */
  unsigned int is_enum_specifier:1;
  unsigned int is_typedef_name:1;       /* if the type of this element was given by a typedef name */
  
  unsigned int is_struct:1;			/* ref_list might contain the member list if is_su_decl_list == 1*/
  unsigned int is_union:1; 			/* ref_list might contain the member list if is_su_decl_list == 1 */
  unsigned int is_enum:1;			/* 1.3.2010: introduced in order to remove C_EL_ENUM, but currently still not used */
  
  
  /* storage type: valid for all elements */
  
  unsigned int is_typedef:1;	/* the keyword "typedef" was used */
  unsigned int is_extern:1;
  unsigned int is_static:1;
  unsigned int is_auto:1;
  unsigned int is_register:1;
  
  /* function specifier: only for functions */
  unsigned int is_function:1;           /* set to 1 for fn decl AND fn def */
  unsigned int is_inline:1;
  unsigned int is_ellipsis:1;
  
  /* access to the variable */
  unsigned int is_read:1;
  unsigned int is_write:1;

  /* bitfield, only for su_member */  
  unsigned int is_bitfield:1;
  unsigned int bitfield_size;

  /* compex types: struct, union or enum's, e.g. if the type is a struct */
  int complex_type_ref; /* referes to an other element */

  /* direct type: only for atomic elements */
  c_dt_type dt;

  /* references to other c_el's, only for aggregates */  
  /* function: [0]: Return value, [>=1] args */
  /* struct/union: members */
  b_il_type ref_list;
  

  /* type qualifier and pointer: valid for all elements */
  /* this list has at least one entry for the object itself */
  /* if it is a pointer reference if it has more than one entries (see p413 6.7.5) */
  b_pl_type tq_list;  /* x_tq_type */

  /* arrays: valid for all elements */

  /* b_il_Cnt(array_sizes) --> dimension */
  /* b_il_Get(array_sizes, 0) --> size of dimension 0 */
  /* b_il_type array_sizes;  */ /* should be replaced by a list of x_ad_type */
  
  /* c_el_CntAD(el)--> dimension */
  /* c_el_GetAD(el, 0) --> size of dimension 0 */
  b_pl_type ad_list;

  /* fn-calls */
  /*
    referes to the fn definition,if the definition exists. else point 
    to the declaration
  */
  b_il_type calls_to;
  
  /* resolved typedefs */
  c_mtql_type mtql;

  /* pre-init code: dynamic string, empty if mtql has only size 1 */
  /* b_ds_type init_ds; */
  c_ils_type ils;
  
};

/* merged type qualifier */
struct _c_mtq_struct
{
  struct _c_tq_struct tq;
  b_pl_type ad_list;
};

/* merged type qualifier list */
struct _c_mtql_struct
{
  b_pl_type mtq_list;
  int el_idx;                           /* final data type */
};


const char *c_el2str(int element);

c_ad_type c_ad_Open();
void c_ad_Close(c_ad_type ad);
size_t c_ad_GetMemUsage(c_ad_type ad);


c_tq_type c_tq_Open();
void c_tq_Close(c_tq_type tq);
void c_tq_Clear(c_tq_type tq);
size_t c_tq_GetMemUsage(c_tq_type tq);

const char *c_dt_GetStrType(c_dt_type dt);


c_el_type c_el_Open();
int c_el_CopyDeclaration(c_el_type dest, c_el_type src);
void c_el_Clear(c_el_type el);
void c_el_Close(c_el_type el);
int c_el_AddTQ(c_el_type el);

int c_el_OpenDT(c_el_type el);

int c_el_OpenRefList(c_el_type el);
int c_el_AddRef(c_el_type el, int ref);

int c_el_OpenCallsTo(c_el_type el);
int c_el_AddCallsTo(c_el_type el, int ref);

c_tq_type c_el_NewTQ(c_el_type el);
c_tq_type c_el_GetLastTQ(c_el_type el, int do_create_if_empty_list);
void c_el_ClearTQList(c_el_type el);
const char *c_tq_GetStr(c_tq_type tq);

c_ad_type c_el_NewAD(c_el_type el);
void c_el_ClearADList(c_el_type el);

void c_el_SetMTQL(c_el_type el, c_mtql_type mtql);

int c_el_IsSU(c_el_type el);
int c_el_IsUndeclaredSU(c_el_type el);
int c_el_IsComplexType(c_el_type el);
int c_el_IsFnDef(c_el_type el);
int c_el_IsFnDecl(c_el_type el);
int c_el_IsVar(c_el_type el);
int c_el_IsTypedef(c_el_type el);
int c_el_IsGlobalVar(c_el_type el);
int c_el_IsLocalVar(c_el_type el);

void c_el_Show(c_el_type el);
int c_el_Check(c_el_type el);
size_t c_el_GetMemUsage(c_el_type el);


/* get type qualifier */
#define c_el_GetTQ(el, pos) ((c_tq_type)b_pl_Get((el)->tq_list,(pos)))
/* get number of type qualifiers */
/* there is one type qualifier for the data type itself and n-1 for the pointer */
#define c_el_CntTQ(el) b_pl_Cnt((el)->tq_list)
#define c_el_WhileTQ(el,ptr_pos) b_pl_While((el)->tq_list,(ptr_pos))

#define c_el_GetAD(el, pos) ((c_ad_type)b_pl_Get((el)->ad_list,(pos)))
#define c_el_CntAD(el) b_pl_Cnt((el)->ad_list)
#define c_el_WhileAD(el,ptr_pos) b_pl_While((el)->ad_list,(ptr_pos))

#define c_mtq_GetAD(el, pos) ((c_ad_type)b_pl_Get((el)->ad_list,(pos)))
#define c_mtq_CntAD(el) ((el)->ad_list==NULL?0:b_pl_Cnt((el)->ad_list))
#define c_mtq_WhileAD(el,ptr_pos) b_pl_While((el)->ad_list,(ptr_pos))

#define c_el_ClearArraySizes(el) c_el_ClearADList(el)
/* #define c_el_ClearArraySizes(el) b_il_Clear((el)->array_sizes) */

#define c_el_CntRef(el) ((el)->ref_list==NULL?0:b_il_Cnt((el)->ref_list))
#define c_el_GetRef(el,pos) b_il_Get((el)->ref_list,(pos))
#define c_el_IsRef(el, ref) (b_il_Find((el)->ref_list, (ref))<0?0:1)

#define c_mtql_GetMTQ(l, pos) ((c_mtq_type)b_pl_Get((l)->mtq_list,(pos)))
#define c_mtql_CntMTQ(l) b_pl_Cnt((l)->mtq_list)
#define c_mtql_WhileMTQ(l,ptr_pos) b_pl_While((l)->mtq_list,(ptr_pos))

c_mtql_type c_mtql_Open(void);
void c_mtql_Close(c_mtql_type mtql);
c_mtq_type c_mtql_NewMTQ(c_mtql_type mtql);
int c_mtql_OrLastTQ(c_mtql_type mtql, c_tq_type tq);
int c_mtql_AppendLastADElement(c_mtql_type mtql, c_el_type el);
void c_mtql_Show(c_mtql_type mtql);




#endif /* _C_EL_H */

