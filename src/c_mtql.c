/* 
  
  c_mtql.c

  merged type qualifier's and 
  merged type qualifier list
  --> unified type description
  
  Die funktionen hier sind bestandteil der el und ell strukturen.
  Die prototypen verteilen sich entsprechend auf c_el.h und c_ell.h

  Letztlich geht es um die funktion
    c_ell_ConvertMTQLToC()
  die ein gegebenes object wieder in C syntax zurückrechnet.
  
  Die mtql structur ist auch der ort, wo typedefs aufgelöst werden
  und die type qualifier verODERed werden (c_mtq_OrTQ).

    typedef int t;
    typedef volatile t tt;
    typedef const tt ttt;
    ttt a;

  a ist also vom typ 'const volatile int'. Das kann letztlich nur über
  die mtql ermittelt werden. Die mtql ist sozusagen dafür zuständig
  den eigentlichen resultierenden typ aufzulösen und zu ermitteln.
  
  Umgang mit namenlosen objecten:
    - wenn es einen unmittelbaren typedef (also ohne pointer) dafür gibt, wird der genommen
    - namenlose objekte ohne typedef können nicht rekonstruiert werden.

  Die zweite hälfte der Funktionalität dieses Modul beschäftigt sich mit der Initalisierung
  eines gegebenen Objects. c_ell_ConvertMTQLToC() liefert sozusagen die linke Seite.
  Berechnet wird hier die zugehörige rechte Seite. Beides zusammen wird in der ILS abgespeichert.
  
  Die funktion
    int c_ell_BuildAllILS(c_ell_type ell)
  berechnet all ILS für alle objekte

*/
#include "c_el.h"
#include "c_ell.h"
#include "c_util.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

c_mtq_type c_mtq_Open(void)
{
  c_mtq_type mtq = (c_mtq_type)malloc(sizeof(struct _c_mtq_struct));
  if ( mtq != NULL )
  {
    c_tq_Clear(&(mtq->tq));
    mtq->ad_list = NULL;
    return mtq;
  }
  return NULL;
}

/* returns index to the ad or -1 */
int c_mtq_AddAD(c_mtq_type mtq)
{
  int ret = -1;
  c_ad_type ad;
  
  if ( mtq->ad_list == NULL )
  {
    mtq->ad_list = b_pl_Open();
    if ( mtq->ad_list == NULL )
      return c_mem_err(), -1;
  }
  
  ad = c_ad_Open();
  if ( ad != NULL )
  {
    ret = b_pl_Add(mtq->ad_list, ad);
    if ( ret < 0 )
    {
      c_ad_Close(ad);
      c_mem_err();
    }
  }
  return ret;
}

c_ad_type c_mtq_NewAD(c_mtq_type mtq)
{
  int pos = c_mtq_AddAD(mtq);
  if ( pos < 0 )
    return NULL;
  return c_mtq_GetAD(mtq, pos);
}

void c_mtq_ClearADList(c_mtq_type mtq)
{
  int i = -1;
  if ( mtq->ad_list == NULL )
    return;
  while( c_mtq_WhileAD(mtq, &i) != 0 )
  {
    c_ad_Close(c_mtq_GetAD(mtq, i));
  }
  b_pl_Clear(mtq->ad_list);
}

void c_mtq_Close(c_mtq_type mtq)
{
  if ( mtq->ad_list != NULL )
  {
    c_mtq_ClearADList(mtq);
    b_pl_Close(mtq->ad_list);
  }
  free(mtq);
}

void c_mtq_OrTQ(c_mtq_type mtq, c_tq_type tq)
{
  mtq->tq.is_const |= tq->is_const;
  mtq->tq.is_volatile |= tq->is_volatile;
  mtq->tq.is_restrict |= tq->is_restrict;
}

/* returns 0 or 1 */
int c_mtq_AppendAD(c_mtq_type mtq, c_ad_type ad)
{
  c_ad_type dest = c_mtq_NewAD(mtq);
  if ( dest == NULL )
    return 0;
  *dest = *ad;
  return 1;
}

/*
ausgabe(i)
  ausgabe_tq()
  

??? erstmal lineare ausgabe --> test_decl_10.c


*/

void c_mtq_Show(c_mtq_type mtq)
{
  int i = -1;
  c_ad_type ad;
  printf("%s", c_tq_GetStr(&(mtq->tq)));
  if ( mtq->ad_list != NULL )
  {
    while( c_mtq_WhileAD(mtq, &i) != 0 )
    {
      ad = c_mtq_GetAD(mtq, i);
      printf("[%d]", ad->dimension);
    }
  }
}

size_t c_mtq_PrintStr(c_mtq_type mtq, char *buf)
{
  /* const char *c_tq_GetStr(mtq->tq); */
  return 0;
}

/*------------------------------------------------------------*/

c_mtql_type c_mtql_Open(void)
{
  c_mtql_type mtql = (c_mtql_type)malloc(sizeof(struct _c_mtql_struct));
  if ( mtql != NULL )
  {
    mtql->mtq_list = b_pl_Open();
    if ( mtql->mtq_list != NULL )
    {
      mtql->el_idx = -1;
      return mtql;
    }
    free(mtql);
  }
  return NULL;
}

void c_mtql_ClearMTQList(c_mtql_type mtql)
{
  int i = -1;
  if ( mtql->mtq_list == NULL )
    return;
  while( c_mtql_WhileMTQ(mtql, &i) != 0 )
  {
    c_mtq_Close(c_mtql_GetMTQ(mtql, i));
  }
  b_pl_Clear(mtql->mtq_list);
}

void c_mtql_Close(c_mtql_type mtql)
{  
  if ( mtql->mtq_list != NULL )
  {
    c_mtql_ClearMTQList(mtql);
    b_pl_Close(mtql->mtq_list);
  }
  free(mtql);
}

/* returns index to the tq or -1 */
int c_mtql_AddMTQ(c_mtql_type mtql)
{
  int ret = -1;
  c_mtq_type mtq = c_mtq_Open();
  if ( mtq != NULL )
  {
    ret = b_pl_Add(mtql->mtq_list, mtq);
    if ( ret < 0 )
    {
      c_mtq_Close(mtq);
      c_mem_err();
    }
  }
  return ret;
}

c_mtq_type c_mtql_NewMTQ(c_mtql_type mtql)
{
  int pos = c_mtql_AddMTQ(mtql);
  if ( pos < 0 )
    return NULL;
  return c_mtql_GetMTQ(mtql, pos);
}

c_mtq_type c_mtql_GetLastMTQ(c_mtql_type mtql)
{
  if ( c_mtql_CntMTQ(mtql) == 0 )
    return NULL;
  return c_mtql_GetMTQ(mtql, c_mtql_CntMTQ(mtql)-1);
}

int c_mtql_OrLastTQ(c_mtql_type mtql, c_tq_type tq)
{
  c_mtq_type mtq = c_mtql_GetLastMTQ(mtql);
  if ( mtq == NULL )
    return 0;
  c_mtq_OrTQ(mtq, tq);
  return 1;
}

int c_mtql_AppendLastAD(c_mtql_type mtql, c_ad_type ad)
{
  c_mtq_type mtq = c_mtql_GetLastMTQ(mtql);
  if ( mtq == NULL )
    return 0;
  return c_mtq_AppendAD(mtq, ad);
}

int c_mtql_AppendLastADElement(c_mtql_type mtql, c_el_type el)
{
  int i = -1;
  while( c_el_WhileAD(el, &i) != 0 )
  {
    if ( c_mtql_AppendLastAD(mtql, c_el_GetAD(el, i)) == 0 )
      return 0;
  }
  return 1;
}

void c_mtql_Show(c_mtql_type mtql)
{
  int i = -1;
  int is_first = 1;
  c_mtq_type mtq;
  if ( mtql != NULL )
  {
    if ( mtql->mtq_list != NULL )
    {
      while( c_mtql_WhileMTQ(mtql, &i) != 0 )
      {
        if ( is_first == 0 )
          printf(" ");
        printf("%d:", i);
        mtq = c_mtql_GetMTQ(mtql, i);
        c_mtq_Show(mtq);
        is_first = 0;
      }
    }
    printf(" el_idx=%d ", mtql->el_idx);
  }
}

static size_t c_mtql_build_C_out(char *dest, const char *s)
{
  if ( dest != NULL )
    strcat( dest, s );
  return strlen(s);
}

/*
  for a nameless struct or union, check, if a typedef exists for that struct or union
  if yes, return the typedef name
  if no, return NULL
*/
static char *c_ell_mtql_find_type(c_ell_type ell, int su_el_idx)
{
  int el_idx = c_ell_FindSUTypedef(ell, su_el_idx, 0);
  if ( el_idx >= 0 )
    return c_ell_GetEL(ell, el_idx)->name;
  return NULL;
}

/*
  top_el_idx		the index of the element for with this initalization is created
  el_idx			the element which provides the mtql
  mtql_idx			the index within the mtql

  these three numbers together are unique within the current file.
  The question is, can we the element name instead of the element idx?
  Also note, that for simple elements, top_el_idx is identical to el_idx.

  we could do the following
    if ( top_el_idx == el_idx )
    {
      name = ...
      return %s[name]_%d[mtql_idx]
    }
   else
     return %s[top_el_idx]_%s[el_idx]_%d[mtql_idx]

*/

/* obsolete... alte routine */
const char *__c_ell_get_intermediate_name(c_ell_type ell, int top_el_idx, int el_idx, int mtql_idx)
{
  /* TODO: remove static buffer, use dynamic memory in ell */
  static char buf[1024];
  
  /* note mtql_idx can be -1 */
  if ( c_ell_GetEL(ell, el_idx)->name != NULL )
  {
    sprintf(buf, "_%s_%d_%d", c_ell_GetEL(ell, el_idx)->name, el_idx, mtql_idx+1);
  }
  else
  {
    sprintf(buf, "_arg_%d_%d", el_idx, mtql_idx+1);
  }
  return buf;
}

const char *c_ell_get_intermediate_name(c_ell_type ell, int top_el_idx, int el_idx, int mtql_idx)
{
  /* TODO: remove static buffer, use dynamic memory in ell */
  static char buf[1024];
  char topnameval[16];
  char nameval[16];
  if ( top_el_idx == el_idx )
  {
    char *name = c_ell_GetEL(ell, el_idx)->name;
    if ( name == NULL )
    {
      sprintf(nameval, "%d", el_idx);
      name = nameval;
    }
    sprintf(buf, "_%s_%d", name, mtql_idx+1);
  }
  else
  {
    char *topname = c_ell_GetEL(ell, top_el_idx)->name;
    char *name = c_ell_GetEL(ell, el_idx)->name;
    if ( topname == NULL )
    {
      sprintf(topnameval, "%d", top_el_idx);
      topname = topnameval;
    }
    if ( name == NULL )
      name ="";
    sprintf(buf, "_%s_%d%s_%d", topname, el_idx, name, mtql_idx+1);
  }
  
  return buf;
}

/*
  Parameter:
    ell                 List of all elements
    el_idx           The element, which contains the name of the object. 
                        Usually this is the element which contains also the mtql
    mtql             merged tq list
    start		start index for the mtql
    idx                current index into the mtql
    is_output_type      output '*' or the the target type
    top_el_idx	topmost parent idx, only used for the creation if temporary names
    dest                destination pointer for the string (usually ell->c_mtql_str)
  returns:
    number of char's appended to dest
*/

static size_t c_ell_mtql_build_C_ptr(c_ell_type ell, int el_idx, c_mtql_type mtql, int start, int idx, int is_output_type, int top_el_idx, char *dest)
{
  c_mtq_type mtq;
  const char *s;
  size_t len = 0;
  
  if ( idx < 0 )
  {
    c_el_type el;
    /* reached the end of the mtql, output name */
    
    el = c_ell_GetEL(ell, el_idx);
    
    if ( el->element == C_EL_ARGUMENT )
    {
      /* use automatic name if this is a function argument */
      len += c_mtql_build_C_out(dest, c_ell_get_intermediate_name(ell, top_el_idx, el_idx, idx));
    }
    else if ( el->name != NULL )
    {
      len += c_mtql_build_C_out(dest, el->name);
    }
    return len;
  }

  /* else idx < 0 */
  
  if ( idx < start )
  {
    c_el_type el;
    /* output intermediate name */
    
    el = c_ell_GetEL(ell, el_idx);
    /* no problem if el->name is NULL (well, it will be empty for fn args */
    len += c_mtql_build_C_out(dest, c_ell_get_intermediate_name(ell, top_el_idx, el_idx, idx));
    return len;
  }
  
  /* else idx < start */
  
  mtq = c_mtql_GetMTQ(mtql, idx);
  
  /* output '*' */
  
  if ( is_output_type == 0 )
  {
    len += c_mtql_build_C_out(dest, "*");
  }

  /* output tq (const, volatile and/or restrict) */

  s = c_tq_GetStr(&(mtq->tq));
  if ( *s != '\0' )
  {
    len += c_mtql_build_C_out(dest, " ");
    len += c_mtql_build_C_out(dest, s);
    len += c_mtql_build_C_out(dest, " ");
  }
  
  /* output type? */
  
  if ( is_output_type != 0 )
  {
    const char *s;
    c_el_type el = c_ell_GetEL(ell, mtql->el_idx);
    if ( el->is_struct )		/* test_init_09.c, 1.3.2010 geändert auf is_struct*/
    {
      if ( el->su_name != NULL )
      {
	len += c_mtql_build_C_out(dest, "struct ");
	len += c_mtql_build_C_out(dest, el->su_name);
      }
      else
      {
	s = c_ell_mtql_find_type(ell, mtql->el_idx);
	if ( s != NULL )
	{
	  len += c_mtql_build_C_out(dest, s);
	}
	else
	{
	  /* give up: mtql can not be simply converted to a string */
	  if ( dest != NULL )
	    c_log(1, "error: nameless struct (idx=%d) without typedef\n", mtql->el_idx);
	  len += c_mtql_build_C_out(dest, "<unknown struct>");
	}
      }
    }
    else if ( el->is_union )  	/* 1.3.2010 geändert auf is_union*/
    {
      if ( el->su_name != NULL )
      {
	len += c_mtql_build_C_out(dest, "union ");
	len += c_mtql_build_C_out(dest, el->su_name);
      }
      else
      {
	s = c_ell_mtql_find_type(ell, mtql->el_idx);
	if ( s != NULL )
	{
	  len += c_mtql_build_C_out(dest, s);
	}
	else
	{
	  /* give up: mtql can not be simply converted to a string */
	  if ( dest != NULL )
	    c_log(1, "error: nameless union (idx=%d) without typedef\n", mtql->el_idx);
	  len += c_mtql_build_C_out(dest, "<unknown union>");
	}
      }
    }
    else if ( el->dt != NULL )
    {
      len += c_mtql_build_C_out(dest, c_dt_GetStrType(el->dt));
    }
    else
    {
      len += c_mtql_build_C_out(dest, "<unsupported> ");
    }
    len += c_mtql_build_C_out(dest, " ");
  }

  /* output '(' if required */
  
  if ( c_mtq_CntAD(mtq) > 0 && idx > 0 ) 
  {
    len += c_mtql_build_C_out(dest, "(");
  }
  
  /* recur: next ptr */

  len += c_ell_mtql_build_C_ptr(ell, el_idx, mtql, start, idx-1, 0, top_el_idx, dest);

  /* output ')' if required */
  
  if ( c_mtq_CntAD(mtq) > 0 && idx > 0  ) 
  {
    len += c_mtql_build_C_out(dest, ")");
  }

  /* output dimensions */
  
  if ( mtq->ad_list != NULL )
  {
    c_ad_type ad;
    char buf[32];
    int i = -1;
    while( c_mtq_WhileAD(mtq, &i) != 0 )
    {
      ad = c_mtq_GetAD(mtq, i);
      sprintf(buf, "[%d]", ad->dimension);
      len += c_mtql_build_C_out(dest, buf);
    }
  }
  
  return len;
}

/*
  start_idx		mtql start index, usually 0. used during object definition to create intermediate objects
*/
const char *c_ell_ConvertMTQLToC(c_ell_type ell, int el_idx, int start_idx, int top_el_idx)
{
  int mtq_idx;
  c_mtql_type mtql;
  c_el_type el;
  size_t len;
  void *ptr;
  
  el = c_ell_GetEL(ell, el_idx);
  mtql = el->mtql;
  if ( mtql == NULL )
    return NULL;  
  mtq_idx =  c_mtql_CntMTQ(mtql);
  if ( mtq_idx == 0 )
    return NULL;
  mtq_idx--;

  /* do a test construction of the string, to calculate the number or chars */
  
  len = c_ell_mtql_build_C_ptr(ell, el_idx, mtql, start_idx, mtq_idx, 1, top_el_idx, NULL );
  if ( ell->c_mtql_len < len || ell->c_mtql_str == NULL )
  {
    if ( ell->c_mtql_str == NULL )
      ptr = malloc(len+1);
    else
      ptr = realloc(ell->c_mtql_str, len+1);
    if ( ptr == NULL )
      return NULL;
    ell->c_mtql_str = (char *)ptr;
    ell->c_mtql_len = len;
  }
  
  /* create the string itself */
  
  ell->c_mtql_str[0] = '\0';
  c_ell_mtql_build_C_ptr(ell, el_idx, mtql, start_idx, mtq_idx, 1, top_el_idx, ell->c_mtql_str);
  
  assert( strlen(ell->c_mtql_str) == len );
  
  return ell->c_mtql_str;
}


/*----------------------------------*/
/*
  mtql_init_single()



  mtql_init_array(depth)
    "{"
    for i = 0; i < dimension; i++ 
      
      if ( c_mtq_CntAD(el) == depth )      
	output type of dest element or output adress of previous object 
      else
	mtql_init_array( depth+1)
      if ( i+1 < dimension )
	","
    "}"

  init_el(this)
    if c_mtql_CntMTQ() > 0
      init_mtql
    else if mtql->el_idx != this
      init_el(mtql->el_idx)
    else if struct
      init_el_struct
    else if union
      init_el_union
    else if el->dt != NULL
     init_el_dt

  die initalisierung ist mehrstufig
  
  int a; 		--> einstufig int a = 0;
  int *a;		--> mehrstufig 
				    int x_a = 0; 
				    int *a = &x_a;
  int **a;		--> dreistufig 
				    int x1_a = 0; 
				    int *x2_a = &x1_a; 
				    int *a = &x2_a;
  die initalisierung wird nun aufgeteilt in die eigentliche initalisierung des objects und
  die vorinitalisierung:

  int a; 		--> einstufig int a = 0;		--> keine vorinitalisierung
  int *a;		--> mehrstufig 
			      vorinitalisierung:
				    int x_a = 0; 
			      hauptinitalisierung:
				    int *a = &x_a;
  int **a;		--> dreistufig 
			      vorinitalisierung:
				    int x1_a = 0; 
				    int *x2_a = &x1_a; 
			      hauptinitalisierung:
				    int *a = &x2_a;
				    
  pre-init: 
    1) die haupt-initalisierung wird nicht durchgeführt
    2) für member-verariablen irgendwelcher strukts oder unions wird die haupt initalisierung durchgeführt.

  vor initalisierung:
    mtql: initalisierung vom index 1 bis cnt-1, beginnend mit dem letzten
  haupt initalisierung
    mtql: initalisierung des index 0
    

*/

/* forward declaration */
int c_ell_init_main(c_ell_type ell, int el_idx, int top_el_idx);
int c_ell_build_init_str(c_ell_type ell, int el_idx, int top_el_idx);

int c_ell_init_el_dt(c_ell_type ell, int el_idx, int top_el_idx)
{
  c_ils_type ils = c_ell_GetIls(ell, top_el_idx);
  c_el_type el;
  
  el = c_ell_GetEL(ell, el_idx);
  if ( el->dt == NULL )
    return 0;
  
  /* min max handling??? */
  
  /*
  if ( b_ds_Add(ds, "0") == 0 )
    return c_mem_err(), 0;
  */
  if ( c_ils_AddRight(ils, "0") == 0 )
    return 0;
  
  return 1;
}

int c_ell_init_el_struct(c_ell_type ell, int el_idx, int top_el_idx)
{
  c_ils_type ils = c_ell_GetIls(ell, top_el_idx);
  c_el_type el;
  
  int i, cnt;
  int member_idx;
  
  el = c_ell_GetEL(ell, el_idx);
  if ( el->is_struct == 0 )
    return c_int_err(), 0;
  
  /* loop through the member */
  
  cnt = c_el_CntRef(el);
  /*
  if ( b_ds_Add(ds, "{") == 0 )
    return c_mem_err(), 0;
  */
  if ( c_ils_AddRight(ils, "{") == 0 )
    return 0;
  for( i = 0; i < cnt; i++ )
  {
    member_idx = c_el_GetRef(el, i);
    if ( c_ell_init_main(ell, member_idx, top_el_idx) == 0 )
      return 0;
    if ( i + 1 != cnt )
    {
      /*
      if ( b_ds_Add(ds, ",") == 0 )
	return c_mem_err(), 0;
      */
      if ( c_ils_AddRight(ils, ",") == 0 )
	return 0;
    }
  }
  /*
  if ( b_ds_Add(ds, "}") == 0 )
    return c_mem_err(), 0;
  */
  if ( c_ils_AddRight(ils, "}") == 0 )
    return 0;
  
  return 1;
}

int c_ell_init_el_union(c_ell_type ell, int el_idx, int top_el_idx)
{
  c_ils_type ils = c_ell_GetIls(ell, top_el_idx);
  c_el_type el;
  int cnt;
  int member_idx;
  
  el = c_ell_GetEL(ell, el_idx);
  if ( el->is_union == 0 )
    return c_int_err(), 0;
  
  /* output first member */
  
  cnt = c_el_CntRef(el);
  if ( cnt == 0 )
    return c_int_err(), 0;
  /*
  if ( b_ds_Add(ds, "{") == 0 )
    return c_mem_err(), 0;
  */
  if ( c_ils_AddRight(ils, "{") == 0 )
    return 0;
  member_idx = c_el_GetRef(el, 0);
  if ( c_ell_init_main(ell, member_idx, top_el_idx) == 0 )
    return 0;
  /*
  if ( b_ds_Add(ds, "}") == 0 )
    return c_mem_err(), 0;
  */
  if ( c_ils_AddRight(ils, "}") == 0 )
    return 0;  
  return 1;
}

int c_ell_init_pure(c_ell_type ell, int el_idx, int top_el_idx)
{
  c_el_type el;  
  el = c_ell_GetEL(ell, el_idx);
  if ( el->is_struct )
    return c_ell_init_el_struct(ell, el_idx, top_el_idx);
  else if ( el->is_union )
    return c_ell_init_el_union(ell, el_idx, top_el_idx);
  else if ( el->dt != NULL )
    return c_ell_init_el_dt(ell, el_idx, top_el_idx);
  return 0;
}

/* common entry point for pre and main/top init */
int c_ell_init_array(c_ell_type ell, int el_idx, int mtq_idx, int dimension_cnt, int top_el_idx)
{
  c_ils_type ils = c_ell_GetIls(ell, top_el_idx);
  c_el_type el;  
  c_mtql_type mtql;
  c_mtq_type mtq;
  
  el = c_ell_GetEL(ell, el_idx);
  mtql = el->mtql;  
  mtq = c_mtql_GetMTQ(mtql, mtq_idx);
  if ( dimension_cnt >= c_mtq_CntAD(mtq) )
  {
    if ( mtq_idx+1 == c_mtql_CntMTQ(mtql) )
    {
      return c_ell_init_pure(ell, mtql->el_idx, top_el_idx);
    }
    else
    {      
      /*
      if ( b_ds_Add(ds, "&") == 0 )
	return c_mem_err(), 0;
      */
      if ( c_ils_AddRight(ils, "&") == 0 )
	return 0;
      /*
      if ( b_ds_Add(ds, c_ell_get_intermediate_name(ell, top_el_idx, el_idx, mtq_idx)) == 0 )
	return c_mem_err(), 0;
      */
      if ( c_ils_AddRight(ils, c_ell_get_intermediate_name(ell, top_el_idx, el_idx, mtq_idx)) == 0 )
	return 0;
    }
  }
  else
  {
    unsigned int i, max;
    max = c_mtq_GetAD(mtq, dimension_cnt)->dimension;
    /*
    if ( b_ds_Add(ds, "{") == 0 )
      return c_mem_err(), 0;
    */
    if ( c_ils_AddRight(ils, "{") == 0 )
      return 0;
    for( i = 0; i < max; i++ )
    {
      if ( c_ell_init_array(ell, el_idx, mtq_idx, dimension_cnt+1, top_el_idx) == 0 )
	return 0;
      if ( i+1 < max )
      {
	/*
	if ( b_ds_Add(ds, ",") == 0 )
	  return c_mem_err(), 0;
	*/
	if ( c_ils_AddRight(ils, ",") == 0 )
	  return 0;
      }
    }
    /*
    if ( b_ds_Add(ds, "}") == 0 )
      return c_mem_err(), 0;
    */
    if ( c_ils_AddRight(ils, "}") == 0 )
      return 0;
  }
  return 1;
}

/* recursive part of pre init */
int c_ell_init_pre_sub(c_ell_type ell, int el_idx, int mtq_idx, int top_el_idx)
{
  c_ils_type ils = c_ell_GetIls(ell, top_el_idx);
  c_el_type el;  
  c_mtql_type mtql;
  const char *s;
  
  el = c_ell_GetEL(ell, el_idx);
  mtql = el->mtql;
  
  if ( mtq_idx+1 < c_mtql_CntMTQ(mtql) )
  {
    if ( c_ell_init_pre_sub(ell, el_idx, mtq_idx+1, top_el_idx ) == 0 )
      return 0;
  }
  s = c_ell_ConvertMTQLToC(ell, el_idx, mtq_idx, top_el_idx);
  /*
  if ( b_ds_Add(ds, s) == 0 )
    return c_mem_err(), 0;    
  if ( b_ds_Add(ds, "=") == 0 )
    return c_mem_err(), 0;    
  */
  if ( c_ils_AddLeft(ils, s) == 0 )
    return 0;
  if ( c_ell_init_array(ell, el_idx, mtq_idx, 0, top_el_idx) == 0 )
    return 0;
  /*
  if ( b_ds_Add(ds, ";\n") == 0 )
    return c_mem_err(), 0;  
  */
  if ( c_ils_NL(ils) == 0 )
    return 0;
  return 1;
}

/* pre init */
int c_ell_init_pre(c_ell_type ell, int el_idx, int top_el_idx)
{
  c_el_type el;  
  c_mtql_type mtql;
  
  el = c_ell_GetEL(ell, el_idx);
  if ( el->is_typedef != 0 )		/* skip typedefs, bugfix for test_init_21.c and test_init_23.c where unneeded ILS are generated */
    return 1;
  
  mtql = el->mtql;
  
  if ( c_mtql_CntMTQ(mtql) <= 1 )
    return 1;				/* nothing todo, pre init is empty */
  return c_ell_init_pre_sub(ell, el_idx, 1, top_el_idx);  
}

/* pre init, main entry point to build up the ell elements */
int c_ell_BuildPreInitStr(c_ell_type ell, int el_idx, int top_el_idx)
{
  c_el_type el;  
  el = c_ell_GetEL(ell, el_idx);
  if ( el->mtql == NULL )	/* not all element have an mtql e.g. struct */
    return 1;		/* all ok */
  /* b_ds_Clear(el->init_ds); */
  return c_ell_init_pre(ell, el_idx, top_el_idx);
}

/* main init, used by top init and for all member elements */
int c_ell_init_main(c_ell_type ell, int el_idx, int top_el_idx)
{
  c_el_type el;  
  el = c_ell_GetEL(ell, el_idx);
  return c_ell_init_array(ell, el_idx, 0, 0, top_el_idx);
  /* return c_ell_init_mtql(ell, el->mtql, 0, ds);*/
}

/* toplevel entry point for the object creation */
int c_ell_init_el_top(c_ell_type ell, int el_idx, int top_el_idx)
{
  c_ils_type ils = c_ell_GetIls(ell, top_el_idx);
  const char *left = c_ell_ConvertMTQLToC(ell, el_idx, 0, top_el_idx);
  /*
  if ( b_ds_Add(ds, left) == 0 )
    return c_mem_err(), 0;
  */
  if ( c_ils_AddLeft(ils, left) == 0 )
    return 0;
  /*
  if ( b_ds_Add(ds, "=") == 0 )
    return c_mem_err(), 0;    
  */
  if ( c_ell_init_main(ell, el_idx, top_el_idx) == 0 )
    return 0;
  /*
  if ( b_ds_Add(ds, ";") == 0 )
    return 0;
  */
  if ( c_ils_NL(ils) == 0 )
    return 0;
  return 1;
}


int c_ell_visitfn_build_pre_init_str(int msg, c_ell_type ell, int el_idx, int top_el_idx)
{
  c_el_type el; 
  if ( msg == C_ELL_VISIT_POST )
  {
    el = c_ell_GetEL(ell, top_el_idx);
    if ( c_ell_BuildPreInitStr(ell, el_idx, top_el_idx) == 0 )
      return 0;
    el = c_ell_GetEL(ell, el_idx);
    /*
    if ( b_ds_Add(ell->init_ds, el->init_ds->str) == 0 )
      return 0;
    */
  }
  return 1;
}


/*
  handle functions, called by c_ell_GetInitStr()
*/
int c_ell_build_fn_init(c_ell_type ell, int el_idx)
{
  c_ils_type ils = c_ell_GetIls(ell, el_idx);
  int i, idx;
  c_el_type el;  
  el = c_ell_GetEL(ell, el_idx);
  if ( el->is_function == 0 )
    return 0;
  
  /* build inits */
  i = -1;
  while( b_il_Loop(el->ref_list,&i, &idx) != 0 )
  {
    if ( i != 0 )
    {
      if ( c_ell_build_init_str(ell, idx, el_idx) == 0 )
	return 0;
    }
  }
  
  /* generate function call */
  /*
  if ( b_ds_Add(ell->fn_ds, el->name) == 0 )
    return NULL;
  */
  if ( c_ils_AddLeft(ils, el->name) == 0 )
    return 0;
  /*
  if ( b_ds_Add(ell->fn_ds, "(") == 0 )
    return NULL;
  */
  if ( c_ils_AddLeft(ils, "(") == 0 )
    return 0;
  i = -1;
  while( b_il_Loop(el->ref_list,&i, &idx) != 0 )
  {
    if ( i != 0 )
    {
      /*
      if ( b_ds_Add(ell->fn_ds, c_ell_get_intermediate_name(ell, el_idx, idx, -1)) == 0 )
	return NULL;
      */
      if ( c_ils_AddLeft(ils, c_ell_get_intermediate_name(ell, el_idx, idx, -1)) == 0 )
	return 0;
      if ( i+1 < b_il_Cnt(el->ref_list) )
      {
	/*
	if ( b_ds_Add(ell->fn_ds, ",") == 0 )
	  return NULL;
	*/
	if ( c_ils_AddLeft(ils, ",") == 0 )
	  return 0;
      }
    }    
  }
  /*
  if ( b_ds_Add(ell->fn_ds, ");") == 0 )
    return NULL;
  */
  if ( c_ils_AddLeft(ils, ")") == 0 )
    return 0;
  
  return 1;
}

/*
  this is the toplevel object creation function
  it works in two steps
  1) build up all pre-init assignments
  2) build up the toplevel assignment
  result is stored in a b_ds of the ell structure.
  the result must not be freed and is valid until the next call.
*/
/*const char *c_ell_get_init_str(c_ell_type ell, int el_idx, int top_el_idx)*/
int c_ell_build_init_str(c_ell_type ell, int el_idx, int top_el_idx)
{
  c_el_type el;  
  el = c_ell_GetEL(ell, el_idx);
  if ( el->is_function != 0 )
    return c_ell_build_fn_init(ell, el_idx);
  if ( el->mtql == NULL )	/* not all element have an mtql e.g. struct */
    return 1;
  if ( el->element == C_EL_RETURN_VALUE )
    return 1;
  
  
  if ( c_ell_Visit(ell, el_idx, top_el_idx, c_ell_visitfn_build_pre_init_str) == 0 )
    return 0;
  if ( c_ell_init_el_top(ell, el_idx, top_el_idx ) == 0 )
    return 0;
  
  return 1;
}

/* obsolete, will be replaced by c_ell_BuildILS() */
/*
const char *c_ell_GetInitStr(c_ell_type ell, int el_idx)
{
  c_el_type el;  
  el = c_ell_GetEL(ell, el_idx);
  b_ds_Clear(ell->init_ds); 
  c_ils_Clear(el->ils); 
  return c_ell_build_init_str(ell, el_idx, el_idx);
}
*/

/* (re)build the ILS structure of the element with index 'el_idx' */
int c_ell_BuildElementILS(c_ell_type ell, int el_idx)
{
  c_el_type el;  
  el = c_ell_GetEL(ell, el_idx);
  c_ils_Clear(el->ils); 
  return c_ell_build_init_str(ell, el_idx, el_idx);
}

int c_ell_BuildAllILS(c_ell_type ell)
{
  int i = -1;
  while( c_ell_WhileEL(ell,&i) != 0 )
  {
    if ( c_ell_BuildElementILS(ell, i) == 0 )
      return 0;
  }
  return 1;
}
