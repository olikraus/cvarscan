/*

  resolve and build up additional information
  
  there is only one function to call:
    int c_fi_Resolve(c_fi_type fi)

  

*/


#include <assert.h>
#include <string.h>
#include "c_fi.h"
#include "c_util.h"


int c_el_is_typedef(c_el_type el)
{
  if ( el->is_typedef != 0 )
    return 1;
  return 0;
}

int c_el_is_typename(c_el_type el)
{
  if ( el->is_typedef_name != 0 )
    return 1;
  return 0;
}

int c_fi_is_el_typedef(c_fi_type fi, int el_idx)
{
  return c_el_is_typedef(c_fi_GetEL(fi,el_idx) );
}

int c_fi_is_el_typename(c_fi_type fi, int el_idx)
{
  return c_el_is_typename(c_fi_GetEL(fi,el_idx) );
}

int c_fi_is_typename_match(c_fi_type fi, int el_typename_idx, int el_typedef_idx)
{
  const char *typename_str;
  const char *typedef_str; 
  
  b_pl_type typename_path;
  b_pl_type typedef_path;
  int i;
  
  /* check strings */
  
  typename_str = c_fi_GetEL(fi,el_typename_idx)->td_name;
  typedef_str = c_fi_GetEL(fi,el_typedef_idx)->name;
  
  if ( strcmp(typename_str, typedef_str) != 0 )
    return 0;
  
  /* check valid nesting level */
  
  typename_path = c_fi_GetEL(fi,el_typename_idx)->ast_path;
  typedef_path = c_fi_GetEL(fi,el_typedef_idx)->ast_path;
  assert( typename_path != NULL );
  assert( typedef_path != NULL );
  for( i = 0; i < b_pl_Cnt(typedef_path); i++ )
  {
    if ( b_pl_Get(typedef_path, i) != b_pl_Get(typename_path, i) )
      return 0;
  }
  
  
  /* avoid: typedef struct { a x; } a, where member x would be bound to the typedef of the parent struct */
  if ( c_fi_GetEL(fi,el_typename_idx)->is_su_member != 0 )
    if ( c_fi_GetEL(fi,el_typedef_idx)->is_struct_or_union_specifier != 0 )
      if ( c_el_IsRef(c_fi_GetEL(fi,el_typedef_idx), el_typename_idx) != 0 )
        return 0; /* do not typedef myself */
  
  return 1;
}

int c_fi_resolve_typename(c_fi_type fi, int el_typename_idx)
{
  int i = el_typename_idx;

  /* nothing to do if there is no typename to resolve */
  if ( c_fi_is_el_typename(fi, el_typename_idx) == 0 )
    return 1;

  /* ok, resolve the typename: look for the corresponding typedef */
  while( i > 0 )
  {
    i--;
    if ( c_fi_is_el_typedef(fi, i) != 0 )
    {
      if ( c_fi_is_typename_match(fi, el_typename_idx, i) != 0 )
      {
        c_fi_GetEL(fi,el_typename_idx)->td_idx = i;
        return 1;
      }      
    }
  }
  
  /* no typedef found */
  return 0;
}

int c_fi_ResolveAllTypenames(c_fi_type fi)
{
  int i;
  int cnt = c_fi_CntEL(fi);
  for( i = 0; i < cnt; i++ )
  {
    if ( c_fi_resolve_typename(fi, i) == 0 )
      return 0;
  }
  return 1;
}



int c_fi_ResolveAllSU(c_fi_type fi)
{
  int i, j;
  int replacements;
  c_el_type el;
  int su_idx;
  int cnt = c_fi_CntEL(fi);
  for( i = 0; i < cnt; i++ )
  {
    el = c_fi_GetEL(fi,i);
    if ( c_el_IsUndeclaredSU( el )  != 0 )
    {
      su_idx = c_ell_FindDeclaredSU( fi->ell, el->su_name );
      if ( su_idx < 0 )
      {
	c_log(0, "Unresolved struct or union '%s'\n", el->su_name);
	return 0;
      }
      
      /* let this object point to the structure declaraton */
      el->complex_type_ref = su_idx;
      
      /* redirect all other references to "me" to the structure declaration */
      replacements = 0;
      for( j = 0; j < cnt; j++ )
      {
	el = c_fi_GetEL(fi,j);
	if ( el->complex_type_ref == i )
	{
	  el->complex_type_ref = su_idx;
	  replacements++;
	}
      }
      c_log(4, "resolved SU: %d (%s) idx %d (%d replacements)\n", i, el->su_name, su_idx, replacements);
    }
  }
  return 1;
}


/* requires a call to c_fi_ResolveAllTypenames */
int c_fi_BuildMTQLs(c_fi_type fi)
{
  c_el_type el;
  int i;
  int cnt = c_fi_CntEL(fi);
  for( i = 0; i < cnt; i++ )		/* TODO: should be replaced by while loop */
  {
    el = c_fi_GetEL(fi,i);
    if ( el->element == C_EL_MEMBER ||
          el->element == C_EL_ARGUMENT ||
          el->element == C_EL_RETURN_VALUE ||
          c_el_IsVar(el) != 0 ||
	  c_el_IsTypedef(el)  != 0 )
      if ( c_ell_AssignMTQL(fi->ell, i) == 0 )
        return 0;
  }
  return 1;
}

int c_fi_BuildAllILS(c_fi_type fi)
{
  return c_ell_BuildAllILS(fi->ell);
}


int c_fi_Resolve(c_fi_type fi)
{
  if ( c_fi_ResolveAllTypenames(fi) == 0 )
    c_log(1, "error typename resolve\n");
  if ( c_fi_ResolveAllSU(fi) == 0 )
    c_log(1, "error struct/union resolve\n");    
  if ( c_fi_BuildMTQLs(fi) == 0 )
    return 0;
  if ( c_fi_BuildAllILS(fi) == 0 )
    return 0;
  return 1;
}


