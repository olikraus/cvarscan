
#include <stdlib.h>
#include <string.h>
#include "c_ell.h"
#include "c_util.h"

c_ell_type c_ell_Open()
{
  c_ell_type c;
  c = (c_ell_type)malloc(sizeof(struct _c_ell_struct));
  if ( c != NULL )
  {
    c->el_list = b_pl_Open();
    if ( c->el_list != NULL )
    {
      c->c_mtql_str = NULL;
      c->c_mtql_len = 0;
/*      
      c->init_ds = b_ds_Open();
      if ( c->init_ds != NULL )
      {
	c->fn_ds = b_ds_Open();
	if ( c->fn_ds != NULL )
	{
      */
	  return c;
      /*
	}
	b_ds_Close(c->init_ds);
      }
      b_pl_Close(c->el_list);
      */
    }
    free(c);
  }
  return c_mem_err(), NULL;
}

void c_ell_ClearEL(c_ell_type ell)
{
  int i = -1;
  c_el_type el;
  while( c_ell_WhileEL(ell,&i) != 0 )
  {
    el = c_ell_GetEL(ell, i);
    c_el_Close(el);
  }
  b_pl_Clear(ell->el_list);
}

void c_ell_Close(c_ell_type ell)
{
  c_ell_ClearEL(ell);
  b_pl_Close(ell->el_list);
  if ( ell->c_mtql_str != NULL )
    free(ell->c_mtql_str);
  /*
  b_ds_Close(ell->init_ds);
  b_ds_Close(ell->fn_ds);
  */
  free(ell);
}

/* returns index to the tq or -1 */
int c_ell_AddEL(c_ell_type ell)
{
  int ret = -1;
  c_el_type el = c_el_Open();
  if ( el != NULL )
  {
    ret = b_pl_Add(ell->el_list, el);
    if ( ret < 0 )
    {
      c_el_Close(el);
      c_mem_err();
    }
  }
  return ret;
}

c_el_type c_ell_NewEL(c_ell_type ell)
{
  int pos = c_ell_AddEL(ell);
  if ( pos < 0 )
    return NULL;
  return c_ell_GetEL(ell, pos);
}

void c_ell_log(c_ell_type ell, int el_pos, int level, const char *pre)
{
  c_el_type el;
  if ( el_pos < 0 )
  {
    c_log(level, "%s EL index illegal (%d)\n", pre, el_pos);
  }
  else
  {
    el = c_ell_GetEL(ell, el_pos);
    c_log(level, "%s EL <%s> idx %d name %s refcnt %d 1st ref %d\n", 
	pre,
	c_el2str(el->element), 
	el_pos,
	el->name==NULL?"NULL":el->name,
	el->ref_list==NULL?-1:b_il_Cnt(el->ref_list),
	el->ref_list==NULL?-1:(b_il_Cnt(el->ref_list)==0?-1:b_il_Get(el->ref_list,0))
	);
  }
}

/*--------------------------------------------------------------*/

/*
  search for the member of a struct or union
*/
int c_ell_FindStructUnionMember(c_ell_type ell, int el_idx, const char *s)
{
  int i = -1;
  int idx;
  c_el_type el;
  b_il_type il;
  
  /* is the arg ok? */  
  if ( el_idx < 0 )
    return -1;  
  
  /* resolve typedef's */
  for(;;)
  {
    el = c_ell_GetEL(ell, el_idx);
    if ( c_el_IsSU(el) != 0 )
      break;
    el_idx = el->td_idx;
    if ( el_idx < 0 )
    {
      el_idx = el->complex_type_ref;
      if ( el_idx < 0 )
        return -1;
    }
  }
  
  /* lookup member variable */
  il = el->ref_list;
  if ( il == NULL )
    return -1;
  
  i = -1;
  while( b_il_Loop(il,&i, &idx) != 0 )
  {
    el = c_ell_GetEL(ell, idx);
    if ( el->name != NULL )
      if ( strcmp(el->name, s) == 0 )
        return idx;
    }
    
    /* member not found */
    return -1;
}



int c_ell_FindFnDef(c_ell_type ell, const char *s)
{
  int i = -1;
  c_el_type el;
  while( c_ell_WhileEL(ell,&i) != 0 )
  {
    el = c_ell_GetEL(ell, i);
    if ( c_el_IsFnDef(el) != 0 )
      if ( el->name != NULL )
        if ( strcmp(el->name, s) == 0 )
          return i;
    }
    return -1;
}


int c_ell_FindFnDecl(c_ell_type ell, const char *s)
{
  int i = -1;
  c_el_type el;
  while( c_ell_WhileEL(ell,&i) != 0 )
  {
    el = c_ell_GetEL(ell, i);
    if ( c_el_IsFnDecl(el) != 0 )
      if ( el->name != NULL )
        if ( strcmp(el->name, s) == 0 )
          return i;
    }
    return -1;
}

int c_ell_FindTypedef(c_ell_type ell, const char *s)
{
  int i = -1;
  c_el_type el;
  while( c_ell_WhileEL(ell,&i) != 0 )
  {
    el = c_ell_GetEL(ell, i);
    if ( c_el_IsTypedef(el) != 0 )
      if ( el->name != NULL )
        if ( strcmp(el->name, s) == 0 )
          return i;
    }
    return -1;
}

/*
  find a typedef for another object with the provided number of ptr_refs
  the other object must be refered by el->complex_type_ref
*/
int c_ell_FindSUTypedef(c_ell_type ell, int su_el_idx, int ptr_refs)
{
  int i = -1;
  c_el_type el;
  while( c_ell_WhileEL(ell,&i) != 0 )
  {
    el = c_ell_GetEL(ell, i);
    if ( c_el_IsTypedef(el) != 0 )
      if ( el->name != NULL )
	if ( el->complex_type_ref == su_el_idx )
	  if ( ptr_refs+1 == c_el_CntTQ(el) )
	    return i;
    }
    return -1;
}

int c_ell_FindGlobalVar(c_ell_type ell, const char *s)
{
  int i = -1;
  c_el_type el;
  while( c_ell_WhileEL(ell,&i) != 0 )
  {
    el = c_ell_GetEL(ell, i);
    if ( c_el_IsGlobalVar(el) != 0 )
      if ( el->name != NULL )
        if ( strcmp(el->name, s) == 0 )
          return i;
    }
    return -1;
}

/* find none-empty struct or union */
int c_ell_FindDeclaredSU(c_ell_type ell, const char *s)
{
  int i = -1;
  c_el_type el;
  while( c_ell_WhileEL(ell,&i) != 0 )
  {
    el = c_ell_GetEL(ell, i);
    if ( c_el_IsSU(el) != 0 )
      if ( c_el_IsUndeclaredSU(el) == 0 )
	if ( strcmp(el->su_name, s) == 0 )
	  return i;
   }
    return -1;
}

int c_ell_FindSU(c_ell_type ell, const char *s)
{
  int i = -1;
  c_el_type el;
  while( c_ell_WhileEL(ell,&i) != 0 )
  {
    el = c_ell_GetEL(ell, i);
    if ( c_el_IsSU(el) != 0 )
      if ( strcmp(el->su_name, s) == 0 )
	return i;
   }
    return -1;
}

/* find none-empty struct or union */
int c_ell_FindByElementAndName(c_ell_type ell, int element, const char *s)
{
  int i = -1;
  c_el_type el;
  while( c_ell_WhileEL(ell,&i) != 0 )
  {
    el = c_ell_GetEL(ell, i);
    if ( el->element == element )
      if ( strcmp(el->su_name, s) == 0 )
	return i;
   }
   return -1;
}


int c_ell_FindByASTInitDeclarator(c_ell_type ell, c_ast_type init_declarator)
{
  int i = -1;
  c_el_type el;
  while( c_ell_WhileEL(ell,&i) != 0 )
  {
    el = c_ell_GetEL(ell, i);
    if ( el->ast_init_declarator == init_declarator )
      return i;
    }
    return -1;
}

int c_ell_FindByFnAndArg(c_ell_type ell, const char *fn, const char *arg)
{
  int i = -1;
  int j;
  c_el_type el;
  c_el_type el_arg;
  while( c_ell_WhileEL(ell,&i) != 0 )
  {
    el = c_ell_GetEL(ell, i);
    if ( el->is_function != 0 )
    {
      if ( strcmp(el->name, fn) == 0 )
      {
        for( j = 1; j < c_el_CntRef(el); j++)
        {
          el_arg = c_ell_GetEL(ell, c_el_GetRef(el,j));
          if ( strcmp(el_arg->name, arg) == 0 )
          {
            return c_el_GetRef(el,j);
          }
        }
      }
    }
  }
  return -1;
}

void c_ell_ClearVisited(c_ell_type ell)
{
  int j = -1;
  while( c_ell_WhileEL(ell,&j) != 0 )
    c_ell_GetEL(ell, j)->is_visited = 0;
}

int c_ell__visit(c_ell_type ell, int el_idx, int top_el_idx, int (*fn)(int msg, c_ell_type ell, int el_idx, int top_el_idx))
{
  int i, v;
  c_el_type el;
  if ( el_idx < 0 )
    return 1;
  el = c_ell_GetEL(ell, el_idx);
  
  /* avoid recursive calls */
  
  if ( el->is_visited != 0 )
    return 1;
  el->is_visited = 1;

  /* call aux function */
  
  if ( fn(C_ELL_VISIT_PRE, ell, el_idx, top_el_idx) == 0 )
    return 0;
  
  /* recursive calls */
  
  if ( c_ell__visit(ell, el->td_idx, top_el_idx, fn) == 0 ) return 0;
  
  if ( c_ell__visit(ell, el->complex_type_ref, top_el_idx, fn) == 0 ) return 0;

  if ( el->ref_list != NULL )
  {
    i = -1;
    while( b_il_Loop( el->ref_list, &i, &v)  )
      if ( c_ell__visit(ell, v, top_el_idx, fn) == 0 ) return 0;
  }
  
  /* call aux function */
  
  if ( fn(C_ELL_VISIT_POST, ell, el_idx, top_el_idx) == 0 )
    return 0;
  
  return 1;
}

int c_ell_Visit(c_ell_type ell, int el_idx, int top_el_idx, int (*fn)(int msg, c_ell_type ell, int el_idx, int top_el_idx))
{
  c_ell_ClearVisited(ell);
  return c_ell__visit(ell, el_idx, top_el_idx, fn);
}

c_ils_type c_ell_GetIls(c_ell_type ell, int el_idx)
{
  c_el_type el;
  if ( el_idx < 0 )
    return NULL;
  el = c_ell_GetEL(ell, el_idx);
  return el->ils;
}


/*--------------------------------------------------------------*/

int c_ell_put_complete_data_type_element(c_ell_type ell, c_mtql_type mtql, int el_idx, int tq_idx, int el_array_idx)
{
  c_el_type el;
  el = c_ell_GetEL(ell, el_idx);
  if ( tq_idx >= 0 )
  {
    if ( c_mtql_CntMTQ(mtql) == 0 )
    {
      if ( c_mtql_NewMTQ(mtql) == NULL )
        return 0;
    }
    else if ( tq_idx > 0 )
    {
      if ( c_mtql_NewMTQ(mtql) == NULL )
        return 0;
    }
    
    if ( c_mtql_OrLastTQ(mtql, c_el_GetTQ(el, tq_idx)) == 0 )
      return 0;
    
    if ( el_array_idx >= 0 )
    {
      if ( c_mtql_AppendLastADElement(mtql, c_ell_GetEL(ell, el_array_idx)) == 0 )
        return 0;
    }
  }
  else
  {
    mtql->el_idx = el_idx;
  }
  return 1;
}

#ifdef OBSOLETE
int _c_ell_BuildMTQL(c_ell_type ell, int el_idx, c_mtql_type mtql)
{
  int el_next_idx;
  int el_ad_idx;
  c_el_type el;
  int i, tq_cnt;
  
  if ( el_idx < 0 )
    return 0;
  el = c_ell_GetEL(ell, el_idx);
  /*if ( c_el_IsComplexType(el) != 0 )
    return 0; *//* pure struct provided */
  
  /* loop over all elements */
  for(;;)
  {
    el = c_ell_GetEL(ell, el_idx);
    el_next_idx = el->td_idx;
        /*
    if ( el_next_idx < 0 )
            el_next_idx = el->complex_type_ref;
        */
    
    tq_cnt = c_el_CntTQ(el);
    if ( tq_cnt == 0 )
    {
      c_log(0, "error: empty tq list for declaration\n");
      return 0;
    }
    else
    {
      for( i = 0; i < tq_cnt;i++ )
      {
        el_ad_idx = -1;
        if ( i == tq_cnt-1 && c_el_CntAD(el) > 0 )
          el_ad_idx = el_idx;
        c_ell_put_complete_data_type_element(ell, mtql, el_idx, i, el_ad_idx);
      }
    }
  
    if ( el_next_idx < 0 )
      break;
    el_idx = el_next_idx;
  }
  
  /* the last entry is ... */
  if ( el->complex_type_ref >=  0 )
  {
      /* ... a complex type (e.g. struct) */
      c_ell_put_complete_data_type_element(ell, mtql, el->complex_type_ref, -1, -1);
  }
  else
  {
      /* ... directly stored in the element (e.g. dt or function) */
      c_ell_put_complete_data_type_element(ell, mtql, el_idx, -1, -1);
  }
  return 1;
}
#endif

int c_build_MTQL_put_tq(c_el_type el, int tq_idx, c_mtql_type mtql)
{
  if ( c_mtql_OrLastTQ(mtql, c_el_GetTQ(el, tq_idx)) == 0 )
    return 0;
  if ( c_el_CntAD(el) > 0 )
    if ( c_mtql_AppendLastADElement(mtql, el) == 0 )
      return 0;
  return 1;
}

int c_ell_BuildMTQL(c_ell_type ell, int el_idx, c_mtql_type mtql)
{
  c_el_type el;
  int tq_cnt;           /* no of pointer + 1 */
  int tq_idx;
  int loop_cnt = 0;
  
  /* with all elements in the chain */
  while( loop_cnt++ < 1000 )
  {
    el = c_ell_GetEL(ell, el_idx);
    /* 
      2.3.2010: the complex type check is wrong. the question is not if it is a struct or not 
      the question is, if it is e.g. a pure struct declaration
      pure struct declaration:
	- is_struct == 1
	- tq_cnt == 0
	- is_su_decl_lest == 1 [optional]
    */
    /*
    if ( c_el_IsComplexType(el) != 0 )  	
      break;
    */
    tq_cnt = c_el_CntTQ(el);
    
    /* 2.3.2010: removed, instead, simply break if tq_cnt == 0 */
    /*
    if ( tq_cnt == 0 )
      return c_log(0, "error: empty tq list for declaration\n"), 0;
    */
    if ( tq_cnt == 0 )
      break;
    
    if ( c_mtql_CntMTQ(mtql) == 0 )
    {
      /* mtql is empty: create mtq and ... */ 
      if ( c_mtql_NewMTQ(mtql) == NULL )
        return 0;
    }

    /* ... copy last tq and array to it */
    if ( c_mtql_OrLastTQ(mtql, c_el_GetTQ(el, tq_cnt-1)) == 0 )
      return 0;
    if ( c_el_CntAD(el) > 0 )
      if ( c_mtql_AppendLastADElement(mtql, el) == 0 )
        return 0;
    
    /* now copy all remaining tq */
    for( tq_idx = tq_cnt-2; tq_idx >= 0; tq_idx-- )
    {
      if ( c_mtql_NewMTQ(mtql) == NULL )
        return 0;
      if ( c_mtql_OrLastTQ(mtql, c_el_GetTQ(el, tq_idx)) == 0 )
        return 0;
    }
    
    /* find next element to process */
    
    if ( el->td_idx >= 0 && el->complex_type_ref >= 0 )
       return c_log(0, "internal error: td_idx and complex_type_ref set.\n"), 0;
    
    if ( el->td_idx >= 0 )
      el_idx = el->td_idx;
    else if ( el->complex_type_ref >= 0 )
      el_idx = el->complex_type_ref ;
    else
      break;            /* no more elements */
  }
  
  mtql->el_idx = el_idx;                /* store the element, that holdes the data type */
  return 1;
}



int c_ell_AssignMTQL(c_ell_type ell, int el_idx)
{
  c_el_type el;
  c_mtql_type mtql = c_mtql_Open();
  if ( mtql == NULL )
    return 0;
  if ( c_ell_BuildMTQL(ell, el_idx, mtql) == 0 )
    return c_mtql_Close(mtql), 0;
  el = c_ell_GetEL(ell, el_idx);
  c_el_SetMTQL(el, mtql);
  return 1;
  
}

void c_ell_ShowMTQL(c_ell_type ell, int el_idx)
{
  c_mtql_type mtql = c_ell_GetEL(ell, el_idx)->mtql;
  if ( mtql == NULL )
    return;
  return;
}

/*--------------------------------------------------------------*/

/*
  search for a member idx;
  el_idx is either avariable with su type or the su itself
*/
int c_ell_GetMember(c_ell_type ell, int el_idx, const char *member)
{
  c_el_type el;
  c_el_type el2;
  int i, cnt;
  int el2_idx;
  el = c_ell_GetEL(ell, el_idx);
  if ( el->mtql != NULL )
  {
    if ( el->mtql->el_idx < 0 )
      return c_int_err(), -1;
    el = c_ell_GetEL(ell, el->mtql->el_idx);
  }
  if ( c_el_IsSU(el) == 0 )		/* 1.3.2010: die ursprüngliche abfrage der elemente ersetzt */
    return -1;
  if ( el->ref_list == NULL )
    return -1;
  
  cnt = b_il_Cnt(el->ref_list);  
  for(i = 0; i < cnt; i++)
  {
    el2_idx = b_il_Get(el->ref_list, i);
    if ( el2_idx < 0 )
      return c_int_err(), -1;
    el2 = c_ell_GetEL(ell, el2_idx);
    if ( strcmp( el2->name, member) == 0 )
      return el2_idx;
  }
  return -1;
}

/*--------------------------------------------------------------*/

void c_ell_Show(c_ell_type ell)
{
  int i = -1;
  c_el_type el;
  while( c_ell_WhileEL(ell,&i) != 0 )
  {
    el = c_ell_GetEL(ell, i);
    printf("--- element %d ---\n", i);
    c_el_Show(el);
    printf("\n");
    printf("  C Conversion: %s", c_ell_ConvertMTQLToC(ell, i, 0, i));
    printf("\n");
    /*
    printf("C Init Str:\n%s\n", c_ell_GetInitStr(ell, i));
    printf("\n");
    */
    c_ils_Show(el->ils);
  }
}

int c_ell_Check(c_ell_type ell)
{
  int i = -1;
  int j;
  c_el_type el;
  c_log(5, "check element list start (%d elements)\n", c_ell_Cnt(ell));
  while( c_ell_WhileEL(ell,&i) != 0 )
  {
    el = c_ell_GetEL(ell, i);
    if ( c_el_Check(el) == 0 )
      return c_el_Show(el), 0;
    /* todo: check recursive typedef's (can this ever happen?) */
    
    if ( el->td_idx >= 0 )
    {
      c_ell_ClearVisited(ell);
      /*
      j = -1;
      while( c_ell_WhileEL(ell,&j) != 0 )
        c_ell_GetEL(ell, j)->is_visited = 0;
      */
      
      j = i;
      while( j >= 0 )
      {
        if ( c_ell_GetEL(ell, j)->is_visited != 0 )
        {
          c_log(0, "internal error: recursive typedef\n");
          return 0;
        }
        c_ell_GetEL(ell, j)->is_visited = 1;
        j = c_ell_GetEL(ell, j)->td_idx;
      }
    }
  }
  
  /* check for unresolved struct/unions */
  if ( el->complex_type_ref >= 0 )
  {
    if ( c_el_IsUndeclaredSU(c_ell_GetEL(ell, el->complex_type_ref)) != 0 )
      return c_log(0, "chk el err: complex type ref to unresolved struct\n"), 0; /* wrong, must not be empty */
  }
  
  c_log(5, "check element list successful\n");
  return 1;
}

size_t c_ell_GetMemUsage(c_ell_type ell)
{
  int i = -1;
  c_el_type el;
  size_t m = sizeof(struct _c_ell_struct);
  m += b_pl_GetMemUsage(ell->el_list);
  m += ell->c_mtql_len+1;
  /*
  m += b_ds_GetMemUsage(ell->init_ds);
  */
  
  while( c_ell_WhileEL(ell,&i) != 0 )
  {
    el = c_ell_GetEL(ell, i);
    m += c_el_GetMemUsage(el);
  }

  return m;
}




