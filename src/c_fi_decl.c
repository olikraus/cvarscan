/*

  c file interface

*/

#include <assert.h>
#include "c_fi.h"
#include "c_const.h"
#include "c_util.h"
#include "c_eval.h"


/*
  called by c_fi_apply_declaration_specifiers

declaration_specifiers:
  storage_class_specifier declaration_specifiers  
  | storage_class_specifier                             
  | type_specifier declaration_specifiers        
  | type_specifier                                     
  | type_qualifier declaration_specifiers  
  | type_qualifier                                     
  | function_specifier declaration_specifiers      
  | function_specifier                         

storage_class_specifier:
  typedef                              
  | extern                              
  | static                                
  | auto                                  
  | register                             
  ;

*/
int c_fi_apply_storage_class_specifier(c_fi_type fi, c_el_type el, c_ast_type n)
{
  if ( el == NULL )
    return 0;
  if ( c_ast_Is(n, c_str_storage_class_specifier) == 0 )
    return c_ast_err(), 0;
  
  n = n->d;
  
  if ( n->n != NULL ) return c_ast_err(), 0;
  
  if ( c_ast_Is(n, c_str_typedef) != 0 )
    el->is_typedef = 1;
  else if ( c_ast_Is(n, c_str_extern) != 0 )
    el->is_extern = 1;
  else if ( c_ast_Is(n, c_str_static) != 0 )
    el->is_static = 1;
  else if ( c_ast_Is(n, c_str_auto) != 0 )
    el->is_auto = 1;
  else if ( c_ast_Is(n, c_str_register) != 0 )
    el->is_register = 1;
  else c_ast_err(), 0;

  return 1;
}

int c_fi_apply_type_qualifier_list(c_fi_type fi, c_tq_type tq, c_ast_type n)
{
  if ( c_ast_Is(n, c_str_type_qualifier_list) == 0 )
    return c_ast_err(), 0;
  n = n->d;
  while( n != NULL )
  {
    if ( c_ast_Is(n, c_str_type_qualifier) != 0 )
    {
      if ( c_fi_apply_type_qualifier(fi, tq, n) == 0 )
        return 0;
    }
    else
    {
      return c_ast_err(), 0;
    }
    n = n->n;
  }
  
  return 1;
}

/*
specifier_qualifier_list:
  type_specifier specifier_qualifier_list               { $$ = RLIST($2, $1); }
  | type_specifier                                      { $$ = T1(@$,$1,@1); }
  | type_qualifier specifier_qualifier_list             { $$ = RLIST($2, $1); }
  | type_qualifier                                      { $$ = T1(@$,$1,@1); }
  ;
*/
int c_fi_apply_specifier_qualifier_list(c_fi_type fi, c_el_type el, c_ast_type n)
{
  c_tq_type tq;
  
  if ( c_ast_Is(n, c_str_specifier_qualifier_list) == 0 )
    return c_ast_err(), 0;

  c_el_Clear(el);
  
  tq = c_el_NewTQ(el);          /* create the first type qualifier entry */
  if ( tq == NULL )
    return 0;
  
  n = n->d;
  while( n != NULL )
  {
    if ( c_ast_Is(n, c_str_type_specifier) != 0 )
    {
      if ( c_fi_apply_type_specifier(fi, el, n) == 0 )
        return 0;
    }
    else if ( c_ast_Is(n, c_str_type_qualifier) != 0 )
    {
      if ( c_fi_apply_type_qualifier(fi, tq, n) == 0 )
        return 0;
    }
    else
    {
      return c_ast_err(), 0;
    }
    n = n->n;
  }
  
  return 1;
}

/*
struct_declarator:
  declarator                                            { $$ = T1(@$,$1,@1); }
  | ':' constant_expression                             { $$ = T2(@$,NIL(@$),@$, $2,@2); }
  | declarator ':' constant_expression                  { $$ = T2(@$,$1,@1,$3,@3); }
  ;

*/
int c_fi_apply_struct_declarator(c_fi_type fi, c_el_type el, c_ast_type n)
{
  if ( n == NULL )
    return c_ast_err(), 0;
  if ( n->d == NULL )
    return c_ast_err(), 0;
  if ( c_ast_Is(n->d, c_str_declarator) != 0 )
  {
    if ( c_fi_apply_declarator(fi, el, n->d) == 0 )
      return 0;    
  }
  if ( n->d->n != NULL )
  {
    if ( c_ast_Is(n->d->n, c_str_constant_expression) == 0 )
      return c_ast_err(), 0;
    el->is_bitfield = 1;
    el->bitfield_size = c_Eval(n->d->n);
  }
  return 1;
}

/*
struct_declarator_list:
  struct_declarator                                     { $$ = T1(@$,$1,@1); }
  | struct_declarator_list ',' struct_declarator        { $$ = LIST($1, $3); }
  ;
*/

int c_fi_apply_struct_declarator_list(c_fi_type fi, c_el_type parent, c_el_type el, c_ast_type n)
{
  int el_pos;
  c_el_type additional_el;
  if ( parent == NULL )
    return 0;
  if ( el == NULL )
    return 0;
  if ( c_ast_Is(n, c_str_struct_declarator_list) == 0 )
    return c_ast_err(), 0;
  n = n->d;
  
  while( n != NULL )
  {
    if ( c_ast_Is(n, c_str_struct_declarator) == 0 )
      return c_ast_err(), 0;
    if ( c_fi_apply_struct_declarator(fi, el, n) == 0 )
      return 0;
    
    n = n->n;
    
    if ( n == NULL )
      break;

    el_pos = c_fi_AddEL(fi);
    if ( el_pos < 0 )
      return 0;
    additional_el =c_fi_GetEL(fi, el_pos);
    if ( c_el_CopyDeclaration(additional_el, el) == 0 )
      return 0;
    if ( c_el_AddRef(parent, el_pos) < 0 )
      return 0;
    c_ell_log(fi->ell, el_pos, 5, "member copied");
    el = additional_el;
  }
  return 1;
}
  
  
/*
struct_declaration:
  specifier_qualifier_list struct_declarator_list ';'   { $$ = T2(@$,$1,@1,$2,@2); }
  ;
*/
int c_fi_apply_struct_declaration(c_fi_type fi, c_el_type parent, c_ast_type n)
{
  c_ast_type specifier_qualifier_list;
  c_ast_type struct_declarator_list;
  int el_pos;
  c_el_type el;

  if ( parent == NULL )
    return 0;
  if ( c_ast_Is(n, c_str_struct_declaration) == 0 )
    return c_ast_err(), 0;
  if ( n->d == NULL )
    return c_ast_err(), 0;
  specifier_qualifier_list = n->d;
  if ( n->d->n == NULL )
    return c_ast_err(), 0;
  struct_declarator_list = n->d->n;

  el_pos = c_fi_AddEL(fi);
  if ( el_pos < 0 )
    return 0;
  el = c_fi_GetEL(fi, el_pos);
  if ( c_el_AddRef(parent, el_pos) < 0 )
    return 0;
  
  c_ell_log(fi->ell, el_pos, 5, "member created");

  if ( c_fi_apply_specifier_qualifier_list(fi, el, specifier_qualifier_list) == 0 )
    return 0;
  
  /* c_fi_apply_specifier_qualifier_list clears everything, so do */
  /* setup of el here */
  
  el->is_su_member = 1;
  el->element = C_EL_MEMBER;
  el->ast_declaration = n;
  
  c_ell_log(fi->ell, el_pos, 5, "member specifier_qualifier_list applied");

  if ( c_fi_apply_struct_declarator_list(fi, parent, el, struct_declarator_list) == 0 )
    return 0;
  
  return 1;
}

/*
  called by c_fi_apply_type_specifier

struct_or_union_specifier:
  struct_or_union identifier_usertype '{' struct_declaration_list '}'    { $$ = T3(@$,$1,@1,$2,@2,$4,@4); }
  | struct_or_union '{' struct_declaration_list '}'             { $$ = T3(@$,$1,@1,NIL(@$),@$,$3,@3); }
  | struct_or_union identifier_usertype                         { $$ = T3(@$,$1,@1,$2,@2,NIL(@$),@$); }
  ;
*/

int c_fi_apply_struct_or_union_specifier(c_fi_type fi, c_el_type el, c_ast_type n)
{
  c_ast_type sdl, struct_declaration;
  
  if ( el == NULL )
    return 0;
  if ( c_ast_Is(n, c_str_struct_or_union_specifier) == 0 )
    return c_ast_err(), 0;
  
  /*
    n->d                c_str_struct | c_str_union
    n->d->n             c_identifier | NIL
    n->d->n->d          the structure or union name
    n->d->n->n          struct_declaration_list
  */

  /* 1. Part: Identify struct or union */
  
  if ( n->d == NULL )
    return c_ast_err(), 0;
  
  if ( c_ast_Is(n->d, c_str_struct) != 0 )
  {
    /* el->element = C_EL_STRUCT; */ /* 1.3.2010  removed to keep the original element type (DECL or ARG...) */
    el->is_struct = 1;
  }
  else if ( c_ast_Is(n->d, c_str_union) != 0 )
  {
    /* el->element = C_EL_UNION; */ /* 1.3.2010  removed to keep the original element type (DECL or ARG...) */
    el->is_union = 1;
  }
  else
  {
    return c_ast_err(), 0;
  }

  /* 2. Part: Read identifier (if any) */
  
  if ( n->d->n == NULL )
    return c_ast_err(), 0;

  if ( c_ast_Is(n->d->n, c_str_identifier) != 0 || c_ast_Is(n->d->n, c_str_identifier_usertype) != 0  )
  {
    if ( c_set_name(&(el->su_name), n->d->n->d->s) == 0 )
      return c_mem_err(), 0;
  }

  /* 3. Part: Read members  (if any) */
  
  if ( n->d->n->n == NULL )
    return c_ast_err(), 0;
  
  sdl = n->d->n->n;
  if ( c_ast_Is(sdl, c_str_struct_declaration_list) != 0 )
  {
    el->is_su_decl_list = 1;
    /*
      struct_declaration_list:
        struct_declaration                                  
        | struct_declaration_list struct_declaration         
        ;
    */
    
    struct_declaration = sdl->d;
    while( struct_declaration != NULL )
    {

      /*
  struct_or_union_specifier:
    struct_or_union identifier '{' struct_declaration_list '}'    { $$ = T3(@$,$1,@1,$2,@2,$4,@4); }
    | struct_or_union '{' struct_declaration_list '}'             { $$ = T3(@$,$1,@1,NIL(@$),@$,$3,@3); }
    | struct_or_union identifier                                  { $$ = T3(@$,$1,@1,$2,@2,NIL(@$),@$); }


  struct_declarator_list:
    struct_declarator                                     { $$ = T1(@$,$1,@1); }
    | struct_declarator_list ',' struct_declarator        { $$ = LIST($1, $3); }
    ;
      */
      

      if ( c_ast_Is(struct_declaration, c_str_struct_declaration) == 0 )
        return c_ast_err(), 0;
      
      if ( c_fi_apply_struct_declaration(fi, el, struct_declaration) == 0 )
        return 0;
        

      struct_declaration = struct_declaration->n;
    } /* while */
  } /* if */
  return 1;
}

/*
declaration_specifiers:
  storage_class_specifier declaration_specifiers  
  | storage_class_specifier                             
  | type_specifier declaration_specifiers        
  | type_specifier                                     
  | type_qualifier declaration_specifiers  
  | type_qualifier                                     
  | function_specifier declaration_specifiers      
  | function_specifier                         

type_specifier:
  void                       
  | char                    
  | short                   
  | int                       
  | long                     
  | float                     
  | double                  
  | signed                  
  | unsigned              
  | _bool                    
  | _complex              
  | _imaginary                       
  | struct_or_union_specifier 
  | enum_specifier                 
  | typedef_name                   
  ;
*/
int c_fi_apply_type_specifier(c_fi_type fi, c_el_type el, c_ast_type n)
{
  if ( el == NULL )
    return 0;
  
  /* treat special case of a function which has no return type specified. used by c_fi_apply_declaration_specifiers() */
  if ( n == NULL )
  {
    if ( c_el_OpenDT(el) == 0 )
      return 0;
    el->dt->is_int = 1;
    return 1;
  }
  
  if ( c_ast_Is(n, c_str_type_specifier) == 0 )
    return c_ast_err(), 0;
  
  n = n->d;
  
  if ( n->n != NULL ) return c_ast_err(), 0;
  
  if ( c_ast_Is(n, c_str_void) != 0 )
  {
    if ( c_el_OpenDT(el) == 0 )
      return 0;
    el->dt->is_void = 1;
  }
  else if ( c_ast_Is(n, c_str_char) != 0 )
  {
    if ( c_el_OpenDT(el) == 0 )
      return 0;
    el->dt->is_char = 1;
  }
  else if ( c_ast_Is(n, c_str_short) != 0 )
  {
    if ( c_el_OpenDT(el) == 0 )
      return 0;
    el->dt->is_short = 1;
  }
  else if ( c_ast_Is(n, c_str_int) != 0 )
  {
    if ( c_el_OpenDT(el) == 0 )
      return 0;
    el->dt->is_int = 1;
  }
  else if ( c_ast_Is(n, c_str_long) != 0 )
  {
    if ( c_el_OpenDT(el) == 0 )
      return 0;
    if ( el->dt->is_long == 0 )
      el->dt->is_long = 1;
    else
      el->dt->is_long_long = 1;
  }
  else if ( c_ast_Is(n, c_str_float) != 0 )
  {
    if ( c_el_OpenDT(el) == 0 )
      return 0;
    el->dt->is_float = 1;
  }
  else if ( c_ast_Is(n, c_str_double) != 0 )
  {
    if ( c_el_OpenDT(el) == 0 )
      return 0;
    el->dt->is_double = 1;
  }
  else if ( c_ast_Is(n, c_str_signed) != 0 )
  {
    if ( c_el_OpenDT(el) == 0 )
      return 0;
    el->dt->is_signed = 1;
  }
  else if ( c_ast_Is(n, c_str_unsigned) != 0 )
  {
    if ( c_el_OpenDT(el) == 0 )
      return 0;
    el->dt->is_unsigned = 1;
  }
  else if ( c_ast_Is(n, c_str__bool) != 0 )
  {
    if ( c_el_OpenDT(el) == 0 )
      return 0;
    el->dt->is_bool = 1;
  }
  else if ( c_ast_Is(n, c_str__complex) != 0 )
  {
    if ( c_el_OpenDT(el) == 0 )
      return 0;
    el->dt->is_complex = 1;
  }
  else if ( c_ast_Is(n, c_str__imaginary) != 0 )
  {
    if ( c_el_OpenDT(el) == 0 )
      return 0;
    el->dt->is_imaginary = 1;
  }
  else if ( c_ast_Is(n, c_str_struct_or_union_specifier) != 0 )
  {
    el->is_struct_or_union_specifier = 1;
    if ( c_fi_apply_struct_or_union_specifier(fi, el, n) == 0 )
      return 0;
  }
  else if ( c_ast_Is(n, c_str_enum_specifier) != 0 )
  {
    el->is_enum_specifier = 1;
    /* todo: write enum handling */
  }
  else if ( c_ast_Is(n, c_str_typedef_name) != 0 )
  {
    el->is_typedef_name = 1;
    if ( c_set_name(&(el->td_name), n->d->s) == 0 ) return c_mem_err(), 0;
    /* resolve type reference --> c_fi_ResolveAllTypenames() */
  }
  else c_ast_err(), 0;
    
  return 1;
}


int c_fi_apply_type_qualifier(c_fi_type fi, c_tq_type tq, c_ast_type n)
{
  if ( tq == NULL )
    return 0;
  if ( c_ast_Is(n, c_str_type_qualifier) == 0 )
    return c_ast_err(), 0;
  
  n = n->d;
  
  if ( n->n != NULL ) return c_ast_err(), 0;
  
  if ( c_ast_Is(n, c_str_const) != 0 )
    tq->is_const = 1;
  else if ( c_ast_Is(n, c_str_restrict) != 0 )
    tq->is_restrict = 1;
  else if ( c_ast_Is(n, c_str_volatile) != 0 )
    tq->is_volatile = 1;
  else c_ast_err(), 0;
    
  return 1;
}

int c_fi_apply_function_specifier(c_fi_type fi, c_el_type el, c_ast_type n)
{
  if ( el == NULL )
    return 0;
  if ( c_ast_Is(n, c_str_function_specifier) == 0 )
    return c_ast_err(), 0;
  
  n = n->d;
  
  if ( n->n != NULL ) return c_ast_err(), 0;
  
  if ( c_ast_Is(n, c_str_inline) != 0 )
    el->is_inline = 1;
  else c_ast_err(), 0;
    
  return 1;
}

/*
  called by c_fi_apply_declaration

declaration_specifiers:
  storage_class_specifier declaration_specifiers  
  | storage_class_specifier                             
  | type_specifier declaration_specifiers        
  | type_specifier                                     
  | type_qualifier declaration_specifiers  
  | type_qualifier                                     
  | function_specifier declaration_specifiers      
  | function_specifier                         

*/
int c_fi_apply_declaration_specifiers(c_fi_type fi, c_el_type el, c_ast_type n)
{
  c_tq_type tq;
  
  /* if the return argument of a function is ommited, then we must insert  'int' */
  /* treat this special case here: call c_fi_apply_type_specifier with third argument NULL */
  if ( n->s == NULL )
  {
    /* create the first type qualifier entry */
    
    tq = c_el_GetLastTQ(el, 1);
    if ( tq == NULL )
      return 0;
    if ( c_fi_apply_type_specifier(fi, el, NULL) == 0 )
      return 0;
  }
  else /* this is the usual case */
  {
    if ( c_ast_Is(n, c_str_declaration_specifiers) == 0 )
      return c_ast_err(), 0;

    /* removed 7.4.2009 */ 
    /* c_el_Clear(el); */
    /* create the first type qualifier entry */
    
    tq = c_el_GetLastTQ(el, 1);
    if ( tq == NULL )
      return 0;

    n = n->d;
    while( n != NULL )
    {
      if ( c_ast_Is(n, c_str_storage_class_specifier) != 0 )
      {
	if ( c_fi_apply_storage_class_specifier(fi, el, n) == 0 )
	  return 0;
      }
      else if ( c_ast_Is(n, c_str_type_specifier) != 0 )
      {
	if ( c_fi_apply_type_specifier(fi, el, n) == 0 )
	  return 0;
      }
      else if ( c_ast_Is(n, c_str_type_qualifier) != 0 )
      {
	if ( c_fi_apply_type_qualifier(fi, tq, n) == 0 )
	  return 0;
      }
      else if ( c_ast_Is(n, c_str_function_specifier) != 0 )
      {
	if ( c_fi_apply_function_specifier(fi, el, n) == 0 )
	  return 0;
      }
      else
      {
	return c_ast_err(), 0;
      }
      n = n->n;
    }
  }
  return 1;
}

/*

declarator_square_bracket:
  '[' type_qualifier_list assignment_expression ']'             { $$ = T2(@$,$2,@2,$3,@3); }
  | '[' static type_qualifier_list assignment_expression ']'    { $$ = T3(@$,$3,@3,$4,@4,$2,@2); }
  | '[' static assignment_expression ']'                        { $$ = T2(@$,$3,@3,$2,@2); }
  | '[' type_qualifier_list static  assignment_expression ']'   { $$ = T3(@$,$2,@2,$4,@4,$3,@3); }
  | '[' type_qualifier_list star ']'                            { $$ = T1(@$,$2,@2); }
  | '[' type_qualifier_list ']'                                 { $$ = T1(@$,$2,@2); }
  | '[' assignment_expression ']'                               { $$ = T1(@$,$2,@2); }
  | '[' star ']'                                                { $$ = T0(@$); }
  | '[' ']'                                                     { $$ = T0(@$); }
  ;

abstract_declarator_square_bracket:
  '[' assignment_expression ']'                         { $$ = T1(@$,$2,@2); }
  | '[' star ']'                                        { $$ = T0(@$); }
  | '[' ']'                                             { $$ = T0(@$); }
  ;

*/
int c_fi_apply_declarator_square_bracket(c_fi_type fi, c_el_type el, c_ast_type n)
{
  c_ad_type ad;
  
  if ( c_ast_Is(n, c_str_declarator_square_bracket) == 0 &&
       c_ast_Is(n, c_str_abstract_declarator_square_bracket) == 0  )
    return c_ast_err(), 0;

  ad = c_el_NewAD(el);
  if ( ad == NULL )
    return 0;
  
  ad->dimension = -1; /* variable length array */

  n = n->d;
  
  if ( c_ast_Is(n, c_str_type_qualifier_list) != 0 )
  {
    if ( c_fi_apply_type_qualifier_list(fi, &(ad->tq), n) == 0 )
      return 0;
    n = n->n;
  }
  
  if ( c_ast_Is(n, c_str_assignment_expression) != 0 )
  {
    ad->dimension = c_Eval(n);
    n = n->n;
  }
  
  if ( c_ast_Is(n, c_str_static) != 0 )
  {
    ad->is_static = 1;
    n = n->n;
  }
  
  return 1;
}

/*
pointer:
  star type_qualifier_list                              { $$ = T2(@$,$1,@1,$2,@2); }
  | star                                                { $$ = T1(@$,$1,@1); }
  | star type_qualifier_list pointer                    { $$ = RLIST(RLIST($3, $2), $1); }
  | star pointer                                        { $$ = RLIST($2, $1); }
  ;
*/
int c_fi_apply_pointer(c_fi_type fi, c_el_type el, c_ast_type n)
{
  c_tq_type tq = NULL;
  if ( c_ast_Is(n, c_str_pointer) == 0 )
    return c_ast_err(), 0;
  n = n->d;
  while( n != NULL )
  {
    if ( c_ast_Is(n, c_str_star) != 0 )
    {
      assert( b_pl_Cnt(el->tq_list) > 0 );
      tq = c_el_NewTQ(el);
      if ( tq == NULL )
        return 0;
    }
    else if ( c_ast_Is(n, c_str_type_qualifier_list) != 0 )
    {
      if ( tq == NULL )
        return c_ast_err(), 0;
      if ( c_fi_apply_type_qualifier_list(fi, tq, n) == 0 )
        return 0;
    }
    else
      return c_ast_err(), 0;
    n = n->n;
  }
  return 1;
}

/*
6.7.6
abstract_declarator:
  pointer                                               { $$ = T2(@$,$1,@1, NIL(@$),@$); }
  | pointer direct_abstract_declarator                  { $$ = T2(@$,$1,@1,$2,@2); }
  | direct_abstract_declarator                          { $$ = T2(@$,NIL(@$),@$, $1,@1); }
  ;


6.7.6
direct_abstract_declarator:
  abstract_function_parenthesis                                         { $$ = T1(@$,$1,@1); }
  | direct_abstract_declarator abstract_declarator_square_bracket       { $$ = LIST($1, $2); }
  | abstract_declarator_square_bracket                                  { $$ = T1(@$,$1,@1); }
  | direct_abstract_declarator abstract_declarator_parenthesis          { $$ = LIST($1, $2); }
  | abstract_declarator_parenthesis                                     { $$ = T1(@$,$1,@1); }
  ;

*/
/*
int c_fi_apply_abstract_declarator(c_fi_type fi, c_el_type el, c_ast_type n)
{
  
}
*/

/*
parameter_declaration:
  declaration_specifiers declarator                     { $$ = T2(@$,$1,@1,$2,@2); }
  | declaration_specifiers abstract_declarator          { $$ = T2(@$,$1,@1,$2,@2); }
  | declaration_specifiers                              { $$ = T1(@$,$1,@1); }
*/

int c_fi_apply_parameter_declaration(c_fi_type fi, c_el_type el, c_ast_type n)
{
  int arg_idx;
  c_el_type arg_el;

  if ( c_ast_Is(n, c_str_parameter_declaration) == 0 )
    return c_ast_err(), 0;

  arg_idx = c_ell_AddEL(fi->ell);
  if ( arg_idx < 0 )
    return c_mem_err(), 0;
  c_ell_log(fi->ell, arg_idx, 4, "created (argument)");
  arg_el = c_ell_GetEL(fi->ell, arg_idx);
  arg_el->element = C_EL_ARGUMENT;
  if ( c_ast_GetCompoundStatementPath(fi->ast, n, el->ast_path) < 0 )
    return c_mem_err(), 0;
  
  if ( c_ast_Is(n->d, c_str_declaration_specifiers) == 0 )
    return c_ast_err(), 0;
  
  if ( c_fi_apply_declaration_specifiers(fi, arg_el, n->d) == 0 )
    return 0;
  
  if ( c_el_AddRef(el, arg_idx) < 0 )
    return c_mem_err(), 0;
  
  n = n->d->n;
  
  if ( n != NULL )
  {
    if ( c_ast_Is(n, c_str_declarator) != 0 )
    {
      if ( c_fi_apply_declarator(fi, arg_el, n) == 0 )
        return 0;
    }
    else if ( c_ast_Is(n, c_str_abstract_declarator) != 0 )
    {
      /* also handled by apply_declarator */
      if ( c_fi_apply_declarator(fi, arg_el, n) == 0 )
        return 0;
    }
    else 
      return c_ast_err(), 0;
  }
  return 1;
}

int c_fi_apply_parameter_list(c_fi_type fi, c_el_type el, c_ast_type n)
{
  if ( c_ast_Is(n, c_str_parameter_list) == 0 )
    return c_ast_err(), 0;
  n = n->d;
  while( n != NULL )
  {
    if ( c_ast_Is(n, c_str_parameter_declaration) != 0 )
    {
      if ( c_fi_apply_parameter_declaration(fi, el, n) == 0 )
        return 0;
    }
    else if ( c_ast_Is(n, c_str_ellipsis) != 0 )
    {
      el->is_ellipsis = 1;
    }
    else
      return c_ast_err(), 0;
    n = n->n;
  }
  return 1;
}

/*
  declarator_parenthesis:
    '(' parameter_type_list ')'                           { $$ = T1(@$,$2,@2); }
    | '(' identifier_list ')'                             { $$ = T1(@$,$2,@2); }
    | '(' ')'                                             { $$ = T0(@$); }
    ;

  abstract_declarator_parenthesis:
    '(' parameter_type_list ')'                           { $$ = T1(@$,$2,@2); }
    | '(' ')'                                             { $$ = T0(@$); }
*/

int c_fi_apply_declarator_parenthesis(c_fi_type fi, c_el_type el, c_ast_type n)
{
  if ( c_ast_Is(n, c_str_declarator_parenthesis) == 0 &&
       c_ast_Is(n, c_str_abstract_declarator_parenthesis) == 0 )
    return c_ast_err(), 0;
  if ( n->d == NULL )
  {
    /* empty list */
    return 1;
  }
  else if ( c_ast_Is(n->d, c_str_identifier_list) != 0 )
  {
    /* todo: identifier list (K&R fn?) */
    /* todo: create empty elements with the name of the identifier */
    return 1;
  }
  else if ( c_ast_Is(n->d, c_str_parameter_list) != 0 )
  {
    return c_fi_apply_parameter_list(fi, el, n->d);    
  }
  return c_ast_err(), 0;
}

/*
  declarator:
    pointer direct_declarator                             { $$ = T2(@$,$1,@1,$2,@2); }
    | direct_declarator                                   { $$ = T2(@$,NIL(@$),@$,$1,@1); }
    ;

  direct_declarator:
    identifier                                            { $$ = T1(@$,$1,@1); }
    | '(' declarator ')'                                  { $$ = T1(@$,$2,@2); }
    | direct_declarator declarator_square_bracket         { $$ = LIST($1, $2); }
    | direct_declarator declarator_parenthesis            { $$ = LIST($1, $2); }
    ;

  abstract_declarator:
    pointer                                               { $$ = T2(@$,$1,@1, NIL(@$),@$); }
    | pointer direct_abstract_declarator                  { $$ = T2(@$,$1,@1,$2,@2); }
    | direct_abstract_declarator                          { $$ = T2(@$,NIL(@$),@$, $1,@1); }
    ;

  direct_abstract_declarator:
    abstract_function_parenthesis                                         { $$ = T1(@$,$1,@1); }
    | direct_abstract_declarator abstract_declarator_square_bracket       { $$ = LIST($1, $2); }
    | abstract_declarator_square_bracket                                  { $$ = T1(@$,$1,@1); }
    | direct_abstract_declarator abstract_declarator_parenthesis          { $$ = LIST($1, $2); }
    | abstract_declarator_parenthesis                                     { $$ = T1(@$,$1,@1); }
    ;

  called by c_fi_apply_init_declarator AND c_fi_apply_struct_declarator

  examples
  int x;                variable x
                        el:int
  int (x);              variable x
                        el:int
  int *x;               pointer x auf int?
                        el:*int
  int (*x);             pointer x auf int?
                        el:*int
  int x();              prototype for function x which returns an int
                        el:fn -> { el:int }
  int (x)();            prototype for function x which returns an int
                        el:fn -> { el:int }
  int (*x)();           pointer x to a function, returning int
                        el:*fn -> { el:int }
  int (*x())();         prototype for function x which returns a pointer to a function 
                        el:fn -> { el:*fn -> { el:int } }
                        
  1) pointer auswerten (gehört noch zum element)
  2) wenn () nicht vorhanden, 
            dann 
                  - alle [] auswerten
                  - wenn identifier, dann ok
                  - wenn declarator, dann abtauchen mit gleichem element
  3) wenn () vorhanden
            dann
                  - neues element anlegen (function)
                  - aktuelles element wird rückgabewert der funktion
                  - aus technischen gründen den inhalt des neuen mit dem aktuellen element vertauschen
                  - () auswerten --> argumente
                  - wenn identifier, dann fertig (funktionsprototyp)
                  - wenn declarator, dann abtauchen mit neuem element (weiter bei 1)

  int (*a)();
  int (*b())()
  {
    return  a;
  }
  int (*(*c)())();
  int (*(*d())())()
  {
    return c;
  }
  
  Wenn der direct_declarator declarator_parenthesis enthält,
  dann ist es eine function oder ein pointer auf eine function,
  ansonsten ist es eine variable oder ein pointer auf eine variable
  
  direct_declarator kann grundsätzlich verschachtelt sein, wie in
  int (((a)));
  aber von bedeutung ist das nur dann, wenn irgendwo 
  declarator_parenthesis dabei sind.
  --> das stimmt so nocht (3.5.2009). Über die schachtelung wird
  die pointer und array zugehörigkeit geregelt.
    pointer auf array mit int
      int (*a)[3] = &aa;
    array mit pointer auf int
      int *b[3] = { &bb, &bb, &bb };

  Es kann höchstens eine declarator_parenthesis in einem 
  direct_declarator geben.
  
*/
int c_fi_apply_declarator(c_fi_type fi, c_el_type el, c_ast_type n)
{
  c_ast_type pointer;
  c_ast_type direct_declarator;
  c_ast_type declarator = NULL;
  c_ast_type identifier = NULL;
  c_ast_type nn;
  c_ast_type loop = NULL;

  if ( c_ast_Is(n, c_str_declarator) == 0 &&    
       c_ast_Is(n, c_str_abstract_declarator) == 0 )
    return c_ast_err(), 0;

  /* it is a declarator, store it in the element structure */
  el->ast_declarator = n;
  
  pointer = n->d;
  if ( pointer == NULL ) 
    return c_ast_err(), 0;
  
  if ( pointer->s != NULL )
    if ( c_fi_apply_pointer(fi, el, pointer) == 0 )
      return 0;

  direct_declarator = pointer->n;
  if ( direct_declarator == NULL ) 
    return 1;   /* probably an error */
  if ( direct_declarator->s == NULL ) 
    return 1;   /* ok, for abstract_declarator only */
    
  nn = direct_declarator->d;
  
  if ( c_ast_Is(nn, c_str_identifier) != 0 )
  {
    identifier = nn;
    declarator = NULL;
  }
  else if ( c_ast_Is(nn, c_str_declarator) != 0 || 
            c_ast_Is(nn, c_str_abstract_declarator) != 0 )
  {
    identifier = NULL;
    declarator = nn;
  }
  else
    return c_ast_err(), 0;
    
  nn = nn->n;
  if ( c_ast_Is(nn, c_str_declarator_square_bracket) != 0 || 
       c_ast_Is(nn, c_str_abstract_declarator_square_bracket) != 0 )
  {
    loop = nn;
    while( loop != NULL )
    {
      if ( c_ast_Is(loop, c_str_declarator_square_bracket) != 0 ||
           c_ast_Is(loop, c_str_abstract_declarator_square_bracket) != 0 )
      {
        if ( c_fi_apply_declarator_square_bracket(fi, el, loop) == 0 )
          return 0;
      }
      else if ( c_ast_Is(loop->n, c_str_declarator_parenthesis) == 0 )
      {
        /* todo: is this ok??? no mix of [] and ()*/
        return c_ast_err(), 0;        
      }
      else
        return c_ast_err(), 0;
      loop = loop->n;
    }
  }
  else if ( c_ast_Is(nn, c_str_declarator_parenthesis) != 0 ||  
            c_ast_Is(nn, c_str_abstract_declarator_parenthesis) != 0 )
  {
    c_el_type new_el;
    int idx = c_ell_AddEL(fi->ell);
    struct _c_el_struct tmp_el;
    
    if ( idx < 0 )
      return c_mem_err(), 0;
    new_el = c_ell_GetEL(fi->ell, idx);
    if ( c_ast_GetCompoundStatementPath(fi->ast, nn, el->ast_path) < 0 )
      return c_mem_err(), 0;

    c_ell_log(fi->ell, idx, 4, "created (return value)");
    
    /*
      the data type so far belongs to the return value.
      so, the data type should be copied to "new_el".
      this is done by swapping the two elements
      and moving back some other information
    */
    
    tmp_el = *new_el; *new_el = *el; *el = tmp_el;
    
    el->element = new_el->element;
    new_el->element = C_EL_RETURN_VALUE;

    /* copy the storage type to the function */
    el->is_typedef = new_el->is_typedef;
    el->is_extern = new_el->is_extern;
    el->is_static = new_el->is_static;
    el->is_auto = new_el->is_auto;
    el->is_register = new_el->is_register;
    
    /* function specifier */
    el->is_inline = new_el->is_inline;
    el->is_function = new_el->is_function;

    new_el->is_typedef = 0;
    new_el->is_extern = 0;
    new_el->is_static = 0;
    new_el->is_auto = 0;
    new_el->is_register = 0;
    
    new_el->is_inline = 0;
    new_el->is_function = 0;
    
    if ( c_el_AddRef(el, idx) < 0 )
      return c_mem_err(), 0;
    
    el->is_function = 1;
    if ( c_fi_apply_declarator_parenthesis(fi, el, nn) == 0 )
      return 0;                 
  }
  
  /* delayed assignment of the identifier, because, el might have been changed */
  if ( identifier != NULL )
  {
    if ( identifier->d == NULL ) return c_ast_err(), 0;
    if ( c_set_name(&(el->name), identifier->d->s) == 0 ) return c_mem_err(), 0;
  }
  
  if ( declarator != NULL )
  {
    c_el_type new_el;
    int idx = c_ell_AddEL(fi->ell);
    struct _c_el_struct tmp_el;
    /*
      Das ist der fall, den ich noch nie in freier wildbahn gesehen habe:
        int (*a)[3] --> ein pointer auf ein array mit int oder sowas ähnliches
      bisher geparsed wurde "int (" sowie ")[3]". benötigt wird also noch der
      klammerinhalt, der auch zurückgegeben werden muss. 
      In el steht allerdings wieder der falsche inhalt, so dass hier wieder
      geswapped werden muss.
    
      27.2.2010: der simple fall eines function pointers gehört auch
      dazu: 
	int (*a)(int);  --> test_init_15.c
      der andere fall sind komplexere array declarationen:
	extern volatile int (* const a)[3];	--> test_decl_12.c
    */
    
    if ( idx < 0 )
      return c_mem_err(), 0;
    new_el = c_ell_GetEL(fi->ell, idx);
    if ( c_ast_GetCompoundStatementPath(fi->ast, nn, el->ast_path) < 0 )
      return c_mem_err(), 0;

    tmp_el = *new_el; *new_el = *el; *el = tmp_el;
    c_ell_log(fi->ell, idx, 4, "created (nested declarator target)");
    
    el->element = new_el->element;
    new_el->element = C_EL_DECLARATOR_CHAIN;
    
    /* copy the storage type to the function */
    el->is_typedef = new_el->is_typedef;
    el->is_extern = new_el->is_extern;
    el->is_static = new_el->is_static;
    el->is_auto = new_el->is_auto;
    el->is_register = new_el->is_register;
    
    /* clear copied values */
    new_el->is_typedef = 0;
    new_el->is_extern = 0;
    new_el->is_static = 0;
    new_el->is_auto = 0;
    new_el->is_register = 0;
    
    /* function specifier: not copied */
    /*
    el->is_inline = new_el->is_inline;
    el->is_function = new_el->is_function;
    
    new_el->is_inline = 0;
    new_el->is_function = 0;
    */
    
    el->complex_type_ref = idx;

    return c_fi_apply_declarator(fi, el, declarator);
  }
  return 1;
}

int c_fi_apply_initializer(c_fi_type fi, c_el_type el, c_ast_type n)
{
  if ( c_ast_Is(n, c_str_initializer) == 0 )
    return c_ast_err(), 0;
  
  /* todo: write initializer */
  
  return 1;
}

/*
  init_declarator = declarator ['=' initializer]

  called by c_fi_apply_declaration
  calls
    - c_fi_apply_declarator
    - c_fi_apply_initializer
*/
int c_fi_apply_init_declarator(c_fi_type fi, c_el_type el, c_ast_type n)
{
  if ( c_ast_Is(n, c_str_init_declarator) == 0 )
    return c_ast_err(), 0;

  el->ast_init_declarator = n;
  
  n = n->d;
  if ( n == NULL ) return c_ast_err(), 0;

  if ( c_fi_apply_declarator(fi, el, n) == 0 )
    return 0;

  n = n->n;
  if ( n == NULL ) return 1;
  
  return c_fi_apply_initializer(fi, el, n);
}

/*
  convert decleration from AST into elements

  calls
    - c_fi_apply_declaration_specifiers
    - c_fi_apply_init_declarator
    - c_el_CopyDeclaration

  basic structure:
  1) create new element
  2) fill element with declaration_specifiers
  3) fill element with init_declarator
  4) if there are no more init_declarator, finish
  5) create another element, copy declaration_specifiers from prev. element
  6) goto 3)

declaration:
  declaration_specifiers init_declarator_list ';'  
  | declaration_specifiers ';'                       

declaration_specifiers:
  storage_class_specifier declaration_specifiers  
  | storage_class_specifier                             
  | type_specifier declaration_specifiers        
  | type_specifier                                     
  | type_qualifier declaration_specifiers  
  | type_qualifier                                     
  | function_specifier declaration_specifiers      
  | function_specifier                         

*/

int c_fi_apply_declaration(c_fi_type fi, c_ast_type n)
{
  int el_pos;
  c_el_type el;
  c_el_type additional_el;
  
  if ( c_ast_Is(n, c_str_declaration) == 0 )
    return c_ast_err(), 0;
  
  el_pos = c_fi_AddEL(fi);
  if ( el_pos < 0 )
    return 0;
  el = c_fi_GetEL(fi, el_pos);
  c_ell_log(fi->ell, el_pos, 4, "created");

  el->element = C_EL_DECLARATION;
  el->ast_declaration = n;
  
  if ( c_ast_GetCompoundStatementPath(fi->ast, n, el->ast_path) < 0 )
    return c_mem_err(), 0;
  
  /* declaration_specifiers */
  n = n->d;
  
  if ( n == NULL ) 
    return c_ast_err(), 0;
    
  if ( c_fi_apply_declaration_specifiers(fi, el, n) == 0 )
    return 0;

  c_ell_log(fi->ell, el_pos, 4, "applied declaration specifiers");

  if ( n->n == NULL  )
  {
    /* clean tq list: It might be a structure 'struct a { ... };' */
    c_el_ClearTQList(el);
    return 1;           /* init_declarator_list is optional */
  }
  
  /* create single element for the struct/union or enum */
  /* all init_declarator elements will refer to this element */
  /* through el->complex_type_ref */

  if ( el->is_struct_or_union_specifier != 0 ||
        el->is_enum_specifier != 0 )
  {
    int additional_el_pos = c_fi_AddEL(fi);
    c_tq_type additional_tq, tq;
    if ( additional_el_pos < 0 )
      return 0;
    additional_el =c_fi_GetEL(fi, additional_el_pos);
    additional_tq = c_el_GetLastTQ(additional_el, 1);
    tq = c_el_GetLastTQ(el, 1);
    
    if ( tq == NULL || additional_tq == NULL )
      return 0;
    
    
    assert( c_el_CntTQ(el) == 1 );
    assert( c_el_CntTQ(additional_el) == 1 );
    
    additional_el->complex_type_ref = el_pos;
    
    /* copy storage types and inline */
    additional_el->is_typedef = el->is_typedef ;
    additional_el->is_extern  = el->is_extern  ;
    additional_el->is_static  = el->is_static  ;
    additional_el->is_auto    = el->is_auto    ;
    additional_el->is_register= el->is_register;
    additional_el->is_inline  = el->is_inline  ;

    /* copy the one and only tq */
    *additional_tq = *tq;
    
    /* the orginal struct or enum def does not have storage types */
    el->is_typedef = 0; 
    el->is_extern  = 0; 
    el->is_static  = 0;
    el->is_auto    = 0; 
    el->is_register= 0; 
    el->is_inline  = 0; 
    
    /* remove the original tq */
    c_tq_Clear(tq);
    c_el_ClearTQList(el);
    
    
    /* for the remaining part of the function, let el be the variable */
    el = additional_el;

    /* for the variable, set the element type */
    el->element = C_EL_DECLARATION;
  }
  
  /* init_declarator_list */
  n = n->n;

  /* init_declarator_list is optional */
  /* this has been checked before */
  /*
  if ( n == NULL )
    return 1;           
  */

  if ( c_ast_Is(n, c_str_init_declarator_list) == 0 )
    return c_ast_err(), 0;

  c_ell_log(fi->ell, el_pos, 4, "applied declaration specifiers");
  
  /* go down to first init_declarator */
  n = n->d;

  if ( n == NULL ) 
    return c_ast_err(), 0;  /* init_declarator_list must not be empty */
  
  for(;;)
  {
    if ( c_ast_Is(n, c_str_init_declarator) == 0 )
      return c_ast_err(), 0;
    
    if ( c_fi_apply_init_declarator(fi, el, n) == 0 )
      return 0;
    
    c_ell_log(fi->ell, el_pos, 4, "applied init_declarator");
    
  /* go to next init_declarator */
    n = n->n;
    
    if ( n == NULL )
      break;            /* init_declarator_list finished */

    el_pos = c_fi_AddEL(fi);
    if ( el_pos < 0 )
      return 0;
    additional_el =c_fi_GetEL(fi, el_pos);
    if ( c_el_CopyDeclaration(additional_el, el) == 0 )
      return 0;
    el = additional_el;
  }

  return 1;
}

