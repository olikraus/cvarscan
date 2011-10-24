
#include "c_eval.h"
#include "c_const.h"
#include "c_util.h"
#include <stdlib.h>


#define EVAL_ERR_VAL 0


#define B(n,r,op) \
  if ( c_ast_Is((n), c_str_##r##_expression) != 0 )\
    return c__eval((n)->d) op c__eval((n)->d->n)

#define NOP(n,r) \
  if ( c_ast_Is((n), c_str_##r##_expression) != 0 )\
    return c__eval((n)->d)
    
#define ASS(node,r)\
  if ( c_ast_Is((node), c_str_##r##_assignment) != 0 )\
    return c__eval((node)->d->n)


void c_eval_err(void)
{
}

c_eval_type c_eval_constant(c_ast_type n)
{
  if ( c_ast_Is(n, c_str_constant) == 0 )
    return 0;
  /* todo: check for the different constants */
  return atol(n->d->s);
}

c_eval_type c__eval(c_ast_type n)
{
  B(n,mul,*);
  B(n,div,/);
  B(n,mod,%);

  B(n,add,+);
  B(n,sub,-);

  B(n,shift_left,<<);
  B(n,shift_right,>>);
  
  B(n,lt,<);
  B(n,gt,>);
  B(n,lteq,<=);
  B(n,gteq,>=);


  B(n,eq,==);
  B(n,and,&);
  B(n,exclusive_or,^);
  B(n,inclusive_or,|);
  B(n,logical_and,&&);
  B(n,logical_or,||);
  NOP(n,constant);
  NOP(n,assignment);
  NOP(n,primary);
  ASS(n, mul);
  ASS(n, div);
  ASS(n, mod);
  ASS(n, add);
  ASS(n, sub);
  ASS(n, left_shift);
  ASS(n, right_shift);
  ASS(n, and);
  ASS(n, xor);
  ASS(n, or);
  if ( c_ast_Is(n, c_str_expression) != 0 )
    return c__eval(n->d);
  if ( c_ast_Is(n, c_str_conditional_expression) != 0 )
    return c__eval(n->d) ? c__eval(n->d->n) : c__eval(n->d->n->n);
  if ( c_ast_Is(n, c_str_cast_expression) != 0 )
  {
    if ( n->d->n == NULL )
      return c__eval(n->d);
    else
      return c__eval(n->d->n);
  }
  if ( c_ast_Is(n, c_str_unary_expression) != 0 )
  {
    if ( n->d->n == NULL )
      return c__eval(n->d);
    if ( c_ast_Is(n->d, c_str_inc) != 0 ) return c__eval(n->d->n)+1;
    if ( c_ast_Is(n->d, c_str_dec) != 0 ) return c__eval(n->d->n)-1;
    if ( c_ast_Is(n->d, c_str_unary_mul) != 0 ) return c_eval_err(), c__eval(n->d->n);
    if ( c_ast_Is(n->d, c_str_unary_and) != 0 ) return c_eval_err(), c__eval(n->d->n);
    if ( c_ast_Is(n->d, c_str_unary_plus) != 0 ) return +c__eval(n->d->n);
    if ( c_ast_Is(n->d, c_str_unary_minus) != 0 ) return -c__eval(n->d->n);
    if ( c_ast_Is(n->d, c_str_unary_binary_not) != 0 ) return ~c__eval(n->d->n);
    if ( c_ast_Is(n->d, c_str_unary_logical_not) != 0 ) return !c__eval(n->d->n);
    if ( c_ast_Is(n->d, c_str_sizeof) != 0 ) return c_eval_err(), sizeof(c_eval_type);
    c_eval_err();
    return EVAL_ERR_VAL;    
  }
  if ( c_ast_Is(n, c_str_postfix_expression) != 0 )
  {
      c_eval_type x = 0;
      n = n->d;
      while( n != NULL )
      {
        if ( c_ast_Is(n, c_str_unnamed_object) != 0 ) return c_eval_err(), EVAL_ERR_VAL;
        else if ( c_ast_Is(n, c_str_primary_expression) != 0 ) x = c__eval(n->d);
        else if ( c_ast_Is(n, c_str_inc) != 0 ) x++;
        else if ( c_ast_Is(n, c_str_dec) != 0 ) x--;
        else if ( c_ast_Is(n, c_str_unnamed_object) != 0 ) return c_eval_err(), EVAL_ERR_VAL;
        else return c_eval_err(), EVAL_ERR_VAL;
        n = n->n;
      }
      return x;
  }
  if ( c_ast_Is(n, c_str_identifier) != 0 ) return c_eval_err(), EVAL_ERR_VAL;
  if ( c_ast_Is(n, c_str_string) != 0 ) return c_eval_err(), EVAL_ERR_VAL;
  if ( c_ast_Is(n, c_str_constant) != 0 ) return c_eval_constant(n);
  return c_eval_err(), EVAL_ERR_VAL;
}

c_eval_type c_Eval(c_ast_type n)
{
  return c__eval(n);
}
