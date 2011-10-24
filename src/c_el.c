
#include <stdlib.h>
#include <string.h>
#include "c_el.h"
#include "c_util.h"


/*-----------------------------------------------------*/

const char *c_el2str(int element)
{
  if ( element == C_EL_NONE )
    return "none";
  else if ( element == C_EL_DECLARATION)
    return "declaration";
  else if ( element == C_EL_STRUCT ) return "struct (replaced)";
  else if ( element == C_EL_UNION ) return "union (replaced)";
  else if ( element == C_EL_ENUM ) return "enum (replaced)";
  else if ( element == C_EL_FN_DEF )
    return "fn def";
  else if ( element == C_EL_MEMBER )
    return "member";
  else if ( element == C_EL_ARGUMENT )
    return "argument";
  else if ( element == C_EL_RETURN_VALUE )
    return "return value";
  return "unknown";
}


/*-----------------------------------------------------*/
/* type qualifier */
c_tq_type c_tq_Open()
{
  c_tq_type tq;
  tq = (c_tq_type)malloc(sizeof(struct _c_tq_struct));
  if ( tq != NULL )
  {
    memset(tq, 0, sizeof(struct _c_tq_struct));
    return tq;
  }
  return c_mem_err(), NULL;
}

void c_tq_Close(c_tq_type tq)
{
  free(tq);
}

void c_tq_Clear(c_tq_type tq)
{
  memset(tq, 0, sizeof(struct _c_tq_struct));
}

size_t c_tq_GetMemUsage(c_tq_type tq)
{
  return sizeof(struct _c_tq_struct);
}

const char *c_tq_GetStr(c_tq_type tq)
{
  static char s[128];
  strcpy(s, "");
  if ( tq->is_const ) strcat(s, c_str_const),strcat(s," ");
  if ( tq->is_volatile ) strcat(s, c_str_volatile),strcat(s," ");
  if ( tq->is_restrict ) strcat(s, c_str_restrict),strcat(s," ");
  if ( s[0] == '\0' )
    return "";
  s[strlen(s)-1] = '\0';
  return s;
}


/*-----------------------------------------------------*/
/* array dimension */
c_ad_type c_ad_Open()
{
  c_ad_type ad;
  ad = (c_ad_type)malloc(sizeof(struct _c_ad_struct));
  if ( ad != NULL )
  {
    memset(ad, 0, sizeof(struct _c_ad_struct));
    return ad;
  }
  return c_mem_err(), NULL;
}

void c_ad_Close(c_ad_type ad)
{
  free(ad);
}

void c_ad_Clear(c_ad_type ad)
{
  memset(ad, 0, sizeof(struct _c_ad_struct));
}

size_t c_ad_GetMemUsage(c_ad_type ad)
{
  return sizeof(struct _c_ad_struct);
}

/*-----------------------------------------------------*/

c_dt_type c_dt_Open()
{
  c_dt_type dt;
  dt = (c_dt_type)malloc(sizeof(struct _c_dt_struct));
  if ( dt != NULL )
  {
    memset(dt, 0, sizeof(struct _c_dt_struct));
    return dt;
  }
  return c_mem_err(), NULL;
}

void c_dt_Copy(c_dt_type dest, c_dt_type src)
{
  memcpy(dest, src, sizeof(struct _c_dt_struct));
}

void c_dt_Close(c_dt_type dt)
{
  free(dt);
}

void c_dt_Clear(c_dt_type dt)
{
  memset(dt, 0, sizeof(struct _c_dt_struct));
}

size_t c_dt_GetMemUsage(c_dt_type dt)
{
  return sizeof(struct _c_dt_struct);
}

const char *c_dt_GetStrType(c_dt_type dt)
{
  static char s[128];
  strcpy(s, "");
  if ( dt->is_unsigned ) strcat(s, c_str_unsigned),strcat(s," ");
  if ( dt->is_signed ) strcat(s, c_str_signed),strcat(s," ");
  if ( dt->is_char ) strcat(s, c_str_char),strcat(s," ");
  if ( dt->is_short ) strcat(s, c_str_short),strcat(s," ");
  if ( dt->is_long ) strcat(s, c_str_long),strcat(s," ");
  if ( dt->is_long_long ) strcat(s, c_str_long),strcat(s," ");
  if ( dt->is_int ) strcat(s, c_str_int),strcat(s," ");
  if ( dt->is_float ) strcat(s, c_str_float),strcat(s," ");
  if ( dt->is_double ) strcat(s, c_str_double),strcat(s," ");
  if ( dt->is_void ) strcat(s, c_str_void),strcat(s," ");
  if ( dt->is_bool ) strcat(s, c_str__bool),strcat(s," ");
  if ( dt->is_imaginary ) strcat(s, c_str__imaginary),strcat(s," ");
  if ( dt->is_complex ) strcat(s, c_str__complex),strcat(s," ");
  if ( s[0] == '\0' )
    return "";
  s[strlen(s)-1] = '\0';
  return s;
}

/*-----------------------------------------------------*/

c_el_type c_el_Open()
{
  c_el_type el;
  el = (c_el_type)malloc(sizeof(struct _c_el_struct));
  if ( el != NULL )
  {
    memset(el, 0, sizeof(struct _c_el_struct));
    el->name = NULL;
    el->ast_declaration = NULL;
    el->ast_declarator = NULL;

    el->ast_init_declarator = NULL;
    el->ast_compound_statement = NULL;
    el->dt = NULL;
    el->element = C_EL_NONE;
    el->ref_list = NULL;
    el->calls_to = NULL;
    el->td_idx = -1;
    el->complex_type_ref = -1;
    el->mtql = NULL;
    /* el->el->init_ds  = NULL; */
    el->ast_path = b_pl_Open();
    if ( el->ast_path != NULL )
    {
      el->ad_list = b_pl_Open();
      if ( el->ad_list != NULL )
      {
        el->tq_list = b_pl_Open();
        if ( el->tq_list != NULL )
        {
          if ( c_el_AddTQ(el) >= 0 )     /* required... or not? */
          {
	    /*
	    el->init_ds = b_ds_Open();
	    if ( el->init_ds != NULL )
	    {
	    */
	      el->ils = c_ils_Open();
	      if ( el->ils != NULL )
	      {
		return el;
	      }
	      /*
	    }
	    b_ds_Close(el->init_ds);
	      */
          }
          b_pl_Close(el->tq_list);
        }
        b_pl_Close(el->ad_list);
      }
      b_pl_Close(el->ast_path);
    }
    free(el);
  }
  return c_mem_err(), NULL;
  
}

/*
  todo: was ist eigentlich mit dem typedef namen?
*/
int c_el_CopyDeclaration(c_el_type dest, c_el_type src)
{
  c_tq_type tq;
  
  dest->element                 = src->element        ;
  dest->ast_declaration         = src->ast_declaration;
  dest->ast_declarator         = src->ast_declarator;
  dest->is_su_member            = src->is_su_member   ;

  dest->is_typedef              = src->is_typedef     ;
  dest->is_extern               = src->is_extern      ;
  dest->is_static               = src->is_static      ;
  dest->is_auto                 = src->is_auto        ;
  dest->is_register             = src->is_register    ;
  
  dest->is_struct_or_union_specifier = src->is_struct_or_union_specifier;
  dest->is_enum_specifier       = src->is_enum_specifier;
  dest->is_typedef_name         = src->is_typedef_name;
  
  dest->is_inline               = src->is_inline;
  
  dest->complex_type_ref        = src->complex_type_ref;
  if ( src->dt != NULL )
  {
    if ( c_el_OpenDT(dest) == 0 )
      return 0;
    c_dt_Copy(dest->dt, src->dt);
  }

  if ( src->ref_list != NULL )
  {
    if ( c_el_OpenRefList(dest) == 0 )
      return 0;
    if ( b_il_Copy(dest->ref_list, src->ref_list) == 0 )
      return c_mem_err(), 0;
  }

  if ( src->calls_to != NULL )
  {
    if ( c_el_OpenCallsTo(dest) == 0 )
      return 0;
    if ( b_il_Copy(dest->calls_to, src->calls_to) == 0 )
      return c_mem_err(), 0;
  }

  c_el_ClearTQList(dest);
  if ( c_el_CntTQ(src) >= 1 )
  {
    /* copy only first element, others belong to the init_declarator */
    tq = c_el_NewTQ(dest);
    if ( tq == NULL )
      return 0;
    *tq = *c_el_GetTQ(src, 0);
  }
  return 1;
}

/*
  allocated dt structure.
  do not touch any existing dt structure
*/
int c_el_OpenDT(c_el_type el)
{
  if ( el->dt == NULL )
  {
    el->dt = c_dt_Open();
    if ( el->dt == NULL )
    {
      return 0;
    }
  }
  return 1;
}

void c_el_ClearRefList(c_el_type el) 
{
  if ( (el)->ref_list != NULL )
    b_il_Clear((el)->ref_list);
}

int c_el_OpenRefList(c_el_type el)
{
  if ( el->ref_list == NULL )
  {
    el->ref_list = b_il_Open();
    if ( el->ref_list == NULL )
    {
      return c_mem_err(), 0;
    }
  }
  else
  {
    c_el_ClearRefList(el);
  }
  return 1;
}

/* returns -1 on error or position */
int c_el_AddRef(c_el_type el, int ref) 
{
  if ( el->ref_list == NULL )
    if ( c_el_OpenRefList(el) == 0 )
      return -1;
  return b_il_Add(el->ref_list, ref);
}

void c_el_ClearCallsTo(c_el_type el) 
{
  if ( (el)->calls_to != NULL )
    b_il_Clear((el)->calls_to);
}

int c_el_OpenCallsTo(c_el_type el)
{
  if ( el->calls_to == NULL )
  {
    el->calls_to = b_il_Open();
    if ( el->calls_to == NULL )
    {
      return c_mem_err(), 0;
    }
  }
  else
  {
    c_el_ClearCallsTo(el);
  }
  return 1;
}

/* returns -1 on error or position */
int c_el_AddCallsTo(c_el_type el, int ref) 
{
  if ( el->calls_to == NULL )
    if ( c_el_OpenCallsTo(el) == 0 )
      return -1;
  return b_il_Add(el->calls_to, ref);
}

void c_el_Clear(c_el_type el)
{
  c_set_name(&(el->name), NULL);

  el->element = C_EL_NONE;
  el->ast_declaration = NULL;
  el->ast_init_declarator = NULL;

  if ( el->dt != NULL )
    c_dt_Clear(el->dt);
  
  el->is_struct_or_union_specifier = 0;
  el->is_enum_specifier = 0;
  el->is_typedef_name = 0;
  
  el->is_inline = 0;
  
  c_el_ClearTQList(el);
  c_el_ClearRefList(el);
  c_el_ClearCallsTo(el); 
  c_el_ClearArraySizes(el);
  c_el_SetMTQL(el, NULL);
  c_ils_Clear(el->ils);
}

void c_el_Close(c_el_type el)
{
  c_el_Clear(el);
  if ( el->dt != NULL )
    c_dt_Close(el->dt);
  if ( (el)->ref_list != NULL )
    b_il_Close(el->ref_list);
  if ( (el)->calls_to != NULL )
    b_il_Close(el->calls_to);
  
  if ( el->ad_list != NULL )
    b_pl_Close(el->ad_list);
  if ( el->tq_list != NULL )
    b_pl_Close(el->tq_list);
  if ( el->ast_path != NULL )
    b_pl_Close(el->ast_path);
  

  el->dt = NULL;
  el->ref_list = NULL;
  el->ad_list = NULL;
  el->tq_list = NULL;
  el->ast_path = NULL;

  c_el_SetMTQL(el, NULL); /* sicher ist sicher  */
  
  /* b_ds_Close( el->init_ds ); */
  c_ils_Close(el->ils);
  
  free(el);
}


/* returns index to the tq or -1 */
int c_el_AddTQ(c_el_type el)
{
  int ret = -1;
  c_tq_type tq = c_tq_Open();
  if ( tq != NULL )
  {
    ret = b_pl_Add(el->tq_list, tq);
    if ( ret < 0 )
    {
      c_tq_Close(tq);
      c_mem_err();
    }
  }
  return ret;
}

c_tq_type c_el_NewTQ(c_el_type el)
{
  int pos = c_el_AddTQ(el);
  if ( pos < 0 )
    return NULL;
  return c_el_GetTQ(el, pos);
}

c_tq_type c_el_GetLastTQ(c_el_type el, int do_create_if_empty_list)
{
  int cnt = b_pl_Cnt(el->tq_list);
  if ( cnt == 0 )
  {
    if ( do_create_if_empty_list == 0 )
      return NULL;
    return c_el_NewTQ(el);
  }
  return c_el_GetTQ(el, cnt-1);
}

void c_el_ClearTQList(c_el_type el)
{
  int i = -1;
  while( c_el_WhileTQ(el, &i) != 0 )
  {
    c_tq_Close(c_el_GetTQ(el, i));
  }
  b_pl_Clear(el->tq_list);
}

/* returns index to the tq or -1 */
int c_el_AddAD(c_el_type el)
{
  int ret = -1;
  c_ad_type ad = c_ad_Open();
  if ( ad != NULL )
  {
    ret = b_pl_Add(el->ad_list, ad);
    if ( ret < 0 )
    {
      c_ad_Close(ad);
      c_mem_err();
    }
  }
  return ret;
}

c_ad_type c_el_NewAD(c_el_type el)
{
  int pos = c_el_AddAD(el);
  if ( pos < 0 )
    return NULL;
  return c_el_GetAD(el, pos);
}

void c_el_ClearADList(c_el_type el)
{
  int i = -1;
  while( c_el_WhileAD(el, &i) != 0 )
  {
    c_ad_Close(c_el_GetAD(el, i));
  }
  b_pl_Clear(el->ad_list);
}

void c_el_SetMTQL(c_el_type el, c_mtql_type mtql)
{
  if ( el->mtql != NULL )
    c_mtql_Close(el->mtql);
  el->mtql = mtql;
}


/*--------------------------------------------------------------*/

int c_el_IsSU(c_el_type el)
{
  if ( el->is_struct != 0 || el->is_union != 0 )
    return 1;
  return 0;
}

/* checks if the struct or union has not been declared, this means it does not have a member list */
int c_el_IsUndeclaredSU(c_el_type el)
{
  if ( c_el_IsSU(el) == 0 )
    return 0;
  if ( el->is_su_decl_list == 1 )
    return 0;
  
  return 1;
}

int c_el_IsComplexType(c_el_type el)
{
  if ( el->is_struct != 0 || el->is_union != 0 || el->is_enum != 0 )
    return 1;
  return 0;
}

int c_el_IsFnDef(c_el_type el)
{
  if ( el->element == C_EL_FN_DEF )
    return 1;
  return 0;
}

int c_el_IsFnDecl(c_el_type el)
{
  if ( el->element == C_EL_DECLARATION )
    if ( el->is_function != 0 )
      if ( el->is_typedef == 0 )
        return 1;
  return 0;
}

int c_el_IsVar(c_el_type el)
{
  if ( el->element == C_EL_DECLARATION )
    if ( el->is_function == 0 )
      if ( el->is_typedef == 0 )
	if ( el->is_struct == 0 )		/* 1.3.2010 */
	  if ( el->is_union == 0 )		/* 1.3.2010 */
	    if ( el->is_enum == 0 )	/* 1.3.2010 */
	      return 1;
  return 0;
}

int c_el_IsTypedef(c_el_type el)
{
  if ( el->element == C_EL_DECLARATION )
    if ( el->is_typedef != 0 )
      return 1;
  return 0;
}

int c_el_IsGlobalVar(c_el_type el)
{
  if ( c_el_IsVar(el) != 0 )
  {
    if ( el->ast_path == NULL )
      return 0;
    if ( b_pl_Cnt(el->ast_path) == 0 )
      return 1;
    return 0;
  }
  return 0;
}

int c_el_IsLocalVar(c_el_type el)
{
  if ( c_el_IsVar(el) != 0 )
    if ( el->ast_path != NULL )
      if ( b_pl_Cnt(el->ast_path) > 0 )
        return 1;
  return 0;
}


/*--------------------------------------------------------------*/

static void c_el_show_ast_l(c_ast_type ast)
{
  if ( ast != NULL )
    c_ast_show_location(ast, stdout);
  else
    printf("        ");
}

void c_el_Show(c_el_type el)
{
  printf("  name:         %s [%d:%s]\n", el->name, el->element, c_el2str(el->element));
  
  printf("  ast_declaration: "); c_el_show_ast_l(el->ast_declaration);
  printf("  ast_declarator: ");c_el_show_ast_l(el->ast_declarator);
  printf("  ast_init_declarator: "); c_el_show_ast_l(el->ast_init_declarator);
  printf("\n");
  printf("  su_name:      %s\n", el->su_name);
  printf("  td_name:      %s  td_idx %d\n", el->td_name, el->td_idx);
  printf("  is_struct_or_union_specifier:    %d\n", el->is_struct_or_union_specifier);
  printf("  is_su_decl_list:                 %d\n", el->is_su_decl_list);
  printf("  is_su_member: %d\n", el->is_su_member);
  printf("  is_function:  %d  ", el->is_function);
  printf("  is_inline:    %d\n", el->is_inline);
  printf("  is_typedef:   %d  ", el->is_typedef);
  printf("  is_extern:    %d\n", el->is_extern);
  printf("  is_static:    %d  ", el->is_static);
  printf("  is_auto:      %d\n", el->is_auto);
  printf("  is_register:  %d  ", el->is_register);
  printf("  is_bitfield:  %d  size %d\n", el->is_bitfield, el->bitfield_size);
  printf("  ast_path:     size %d\n", b_pl_Cnt(el->ast_path));
  printf("  ad_list:      size %d\n", c_el_CntAD(el));
  {
    int i = -1;
    printf("    dimensions: ");
    while( c_el_WhileAD(el, &i) != 0 )
    {
      printf("%s %d ", c_tq_GetStr(&(c_el_GetAD(el, i)->tq)), c_el_GetAD(el, i)->dimension);
    }
    printf("\n");
  }
  printf("  tq_list:      size %d    ", c_el_CntTQ(el));
  {
    int i = -1;
    c_tq_type tq;
    while( c_el_WhileTQ(el,&i) ) 
    {
      tq = c_el_GetTQ(el, i);
      printf(" %d:", i);
      if ( tq->is_const != 0 )
        printf("%s", "c");
      if ( tq->is_volatile != 0 )
        printf("%s", "v");
      if ( tq->is_restrict != 0 )
        printf("%s", "r");
    }
    printf("\n");
  }

  printf("  ref_list:     size %d   ", c_el_CntRef(el));
  {
    int i;
    for( i = 0; i < c_el_CntRef(el); i++ )
    {
      printf(" %d", c_el_GetRef(el, i));
    }
    printf("\n");
  }
  
  if ( el->dt == NULL )
  printf("  direct type:      NULL\n");
  else
  printf("  direct type:      %s\n", c_dt_GetStrType(el->dt));
  printf("  complex_type_ref: %d\n", el->complex_type_ref);
  printf("  mtql:             ");
  c_mtql_Show(el->mtql);
  /* wird erst später berechnet
  printf("\n");
  c_ils_Show(el->ils);
  */
  
}

/*--------------------------------------------------------------*/


/* 0: not ok, 1; ok */
int c_el_Check(c_el_type el)
{
  int type_cnt, cnt;
  if ( el->element == C_EL_NONE )
    return c_log(0, "chk el err: NONE element\n"), 0;
  
  if ( c_el_IsSU(el) )
  {
    if ( el->td_idx != -1 )           return c_log(0, "chk el err: struct references typedef\n"), 0;
    if ( el->is_typedef != 0 )        return c_log(0, "chk el err: is_typedef set for struct\n"), 0;
    if ( el->is_extern != 0 )         return c_log(0, "chk el err: is_extern set for struct\n"), 0;
    if ( el->is_static != 0 )         return c_log(0, "chk el err: is_static set for struct\n"), 0;
    if ( el->is_auto != 0 )           return c_log(0, "chk el err: is_auto set for struct\n"), 0;
    if ( el->is_register != 0 )       return c_log(0, "chk el err: is_register set for struct\n"), 0;
    if ( el->is_function != 0 )       return c_log(0, "chk el err: is_function set for struct\n"), 0;
    if ( el->is_inline != 0 )         return c_log(0, "chk el err: is_inline set for struct\n"), 0;
    if ( el->is_ellipsis != 0 )       return c_log(0, "chk el err: is_ellipsis set for struct\n"), 0;
    if ( el->is_bitfield != 0 )       return c_log(0, "chk el err: is_bitfield set for struct\n"), 0;
    if ( el->bitfield_size != 0 )     return c_log(0, "chk el err: bitfield_size != 0 for struct\n"), 0;
    if ( el->dt != NULL )             return c_log(0, "chk el err: direct type != NULL for struct\n"), 0;
    /* removed, because there might be a tq_list --> test_init_19.c */
    /*
    if ( el->tq_list != NULL )      
      if ( c_el_CntTQ(el) > 0 )       return c_log(0, "chk el err: non-empty tq-list\n"), 0;
    */
    if ( el->is_su_decl_list == 0 )
    {
      if ( el->ref_list != NULL )
	if ( b_il_Cnt(el->ref_list) > 0 ) return c_log(0, "chk el err: non-empty ref-list for struct without declaration\n"), 0;
    }
    else
    {
      if ( el->complex_type_ref != -1 ) return c_log(0, "chk el err: complex_type_ref != -1 for struct\n"), 0;
    }
  }
  else
  {
    if ( el->is_su_decl_list != 0 )   return c_log(0, "chk el err: decl list only for struct or union allowed\n"), 0;
  }
  /*
    only one of
      is_struct
      is_union
      is_enum
      is_function
    must be set.
  */
  cnt = 0;
  if ( el->is_struct ) cnt++;
  if ( el->is_union  ) cnt++;
  if ( el->is_enum  ) cnt++;
  if ( el->is_function  ) cnt++;
  if ( cnt > 1 )   return c_log(0, "chk el err: too ma\n"), 0;
  
  /*
    only one of
      complex_type_ref,
      dt
      td_idx
    must be valid
  */
  type_cnt = 0;
  if ( el->complex_type_ref != -1 )
    type_cnt++;
  if ( el->dt != NULL)
    type_cnt++;
  if ( el->td_idx != -1)
    type_cnt++;
  if ( type_cnt > 1)                  return c_log(0, "chk el err: complex element ambiguous\n"), 0;

  if ( el->is_typedef_name != 0 )
  {
    if ( el->td_name == NULL )        return c_log(0, "chk el err: type name of typedef not known\n"), 0;
    if ( el->td_idx < 0 )             return c_log(0, "chk el err: no reference to typedef\n"), 0;
  }
  if ( el->td_idx >= 0 )
  {
    if ( el->td_name == NULL )        return c_log(0, "chk el err: type name of typedef not known\n"), 0;
    if ( el->is_typedef_name == 0 )   return c_log(0, "chk el err: type flag not set\n"), 0;
  }
  /* todo: more checks */

  return 1;
}

/*--------------------------------------------------------------*/

size_t c_el_GetMemUsage(c_el_type el)
{
  int i;
  size_t m = sizeof(struct _c_el_struct);
  
  m += strlen(el->name)+1;

  if ( el->ast_path != NULL )
    m += b_pl_GetMemUsage(el->ast_path);
  
  if ( el	->ref_list != NULL )
    m += b_il_GetMemUsage(el->ref_list);
  
  if ( el->calls_to != NULL )
    m += b_il_GetMemUsage(el->calls_to);
 
  if ( el->dt != NULL )
    m += c_dt_GetMemUsage(el->dt);
  
  m += b_pl_GetMemUsage(el->tq_list);

  i = -1;
  while( c_el_WhileTQ(el, &i) != 0 )
  {
    m += c_tq_GetMemUsage(c_el_GetTQ(el, i));
  }

  m += b_pl_GetMemUsage(el->ad_list);
  
  i = -1;
  while( c_el_WhileAD(el, &i) != 0 )
  {
    m += c_ad_GetMemUsage(c_el_GetAD(el, i));
  }

  /* m += b_ds_GetMemUsage(el->init_ds); */

  
  return m;
}

