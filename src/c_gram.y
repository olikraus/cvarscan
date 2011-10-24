/*

  ISO 9899:1999 parser 
  
  (c) 2008 Oliver Kraus
  
  
  generate: bison --locations
  
  
  ast:
    s   token/value
    n   next
    d   down
    l   location
  
  if s == NULL than l has the values of parent(ast)->l
  
  
  
*/

%{

#include <stdio.h>
#include "c_ast.h"

#define YYSTYPE c_ast_type
#define YYLTYPE c_loc_struct

int c_yylex(void);
void c_yyerror(char const *); 
YYSTYPE c_result = NULL;

extern char *c_yytext;
static int enable_c_notd = 0;
void c_scan_init(void);
void c_tn_disable(void);

#define NIL(l0) c_ast_Open(NULL, &(l0))
#define POP(l0) c_ast_Pop(&(l0))
#define PUSH(s) c_ast_Push(c_ast_Open((s), NULL))
#define LAST() c_ast_Last()
#define T0(l0) c_ast_Open(yytname[yyr1[yyn]], &(l0))
/* #define T0(l0) pT0(&(l0)) */
#define T1(l0,c1,l1) c_ast_OpenChildren((yytname[yyr1[yyn]]),&(l0),1,(c1))
#define T2(l0,c1,l1,c2,l2) c_ast_OpenChildren((yytname[yyr1[yyn]]),&(l0),2,(c1),(c2))
#define T3(l0,c1,l1,c2,l2,c3,l3) c_ast_OpenChildren((yytname[yyr1[yyn]]),&(l0),3,(c1),(c2),(c3))
#define T4(l0,c1,l1,c2,l2,c3,l3,c4,l4) c_ast_OpenChildren((yytname[yyr1[yyn]]),&(l0),4,(c1),(c2),(c3),(c4))
#define LIST(p,c) c_ast_AddChild((p),(c))
#define RLIST(p,c) c_ast_AddChildFirst((p),(c))
#define LEAF(l0) c_ast_Open(c_yytext, &(l0))

%}

%token AUTO
%token BREAK
%token CASE
%token CHAR
%token CONST
%token CONTINUE
%token DEFAULT
%token DO
%token DOUBLE
%token ELSE
%token ENUM
%token EXTERN
%token FLOAT
%token FOR
%token GOTO
%token IF
%token INLINE
%token INT
%token LONG
%token REGISTER
%token RESTRICT
%token RETURN
%token SHORT
%token SIGNED
%token SIZEOF
%token STATIC
%token STRUCT
%token SWITCH
%token TYPEDEF
%token UNION
%token UNSIGNED
%token VOID
%token VOLATILE
%token WHILE
%token _BOOL
%token _COMPLEX
%token _IMAGINARY
%token LEFT
%token RIGHT
%token ADDASS
%token SUBASS
%token MULASS
%token DIVASS
%token MODASS
%token XORASS
%token ANDASS
%token ORASS
%token LEFTASS
%token RIGHTASS
%token LTEQ GTEQ
%token EQ NEQ
%token AND
%token OR
%token INC
%token DEC
%token ARROW
%token ELLIPSIS
%token STRING CONSTANT USERTYPE IDENTIFIER

%name-prefix="c_yy"
%token-table
%error-verbose
%initial-action
{
  c_yylloc.first_line = 0;
  c_yylloc.first_column = 0;
  c_yylloc.last_line = 0;
  c_yylloc.last_column = 0;
  enable_c_notd = 1;
  c_scan_init();
}
/* %pure-parser */


%start file

%expect 1


%%

/* 
  A.2.1 Expressions 
  -----------------
*/


/* 6.5.1 */
primary_expression:
  identifier                                            { $$ = T1(@$,$1,@1); }
  | constant                                            { $$ = T1(@$,$1,@1); }
  | string                                              { $$ = T1(@$,$1,@1); }
  | '(' expression ')'                                  { $$ = T1(@$,$2,@2); }
  ;


/* 6.5.2 */
postfix_expression:
  primary_expression                                    { $$ = T1(@$,$1,@1); }
  | postfix_expression array                            { $$ = LIST($1, $2); }
  | postfix_expression fnargs                           { $$ = LIST($1, $2); }
  | postfix_expression dot                              { $$ = LIST($1, $2); }
  | postfix_expression arrow                            { $$ = LIST($1, $2); }
  | postfix_expression inc                              { $$ = LIST($1, $2); }
  | postfix_expression dec                              { $$ = LIST($1, $2); }
  | unnamed_object                                      { $$ = T1(@$,$1,@1); }
  ;

array:
  '[' expression ']'                                    { $$ = T1(@$,$2,@2); }
  ;

fnargs:
  '(' argument_expression_list ')'                      { $$ = T1(@$,$2,@2); }
  | '(' ')'                                             { $$ = T0(@$); }
  ;

dot:
  '.' identifier_usertype                               { $$ = T1(@$,$2,@2); }
  ;

arrow:
  ARROW identifier_usertype                             { $$ = T1(@$,$2,@2); }
  ;   
  
inc:
  INC                                                   { $$ = T0(@$); }
  ;   

dec:
  DEC                                                   { $$ = T0(@$); }
  ;   

unnamed_object:
  '(' type_name ')' '{' initializer_list '}'            { $$ = T2(@$,$1,@1,$2,@2); }
  | '(' type_name ')' '{' initializer_list ',' '}'      { $$ = T2(@$,$1,@1,$2,@2); }
  ;

/* 6.5.2 */
argument_expression_list:       
  assignment_expression                                 { $$ = T1(@$,$1,@1); }
  | argument_expression_list ',' assignment_expression  { $$ = LIST($1, $3); }
  ;

/* 6.5.3 */
unary_expression:
  postfix_expression                                    { $$ = T1(@$,$1,@1); }
  | inc unary_expression                                { $$ = T2(@$,$1,@1,$2,@2); }
  | dec unary_expression                                { $$ = T2(@$,$1,@1,$2,@2); }
  | unary_operator cast_expression                      { $$ = T2(@$,$1,@1,$2,@2); }
  | sizeof unary_expression                             { $$ = T2(@$,$1,@1,$2,@2); }
  | sizeof '(' type_name ')'                            { $$ = T2(@$,$1,@1,$3,@3); }
  ;

sizeof:
  SIZEOF                                                { $$ = T0(@$); }
  ;


/* 6.5.3 */
/*
unary_operator:
  unary_and                                             { $$ = T1(@$,$1,@1); }
  | unary_mul                                           { $$ = T1(@$,$1,@1); }
  | unary_plus                                          { $$ = T1(@$,$1,@1); }
  | unary_minus                                         { $$ = T1(@$,$1,@1); }
  | unary_binary_not                                    { $$ = T1(@$,$1,@1); }
  | unary_logical_not                                   { $$ = T1(@$,$1,@1); }
*/

unary_operator:                                        
  unary_and                                             { $$ = $1; }
  | unary_mul                                           { $$ = $1; }
  | unary_plus                                          { $$ = $1; }
  | unary_minus                                         { $$ = $1; }
  | unary_binary_not                                    { $$ = $1; }
  | unary_logical_not                                   { $$ = $1; }

unary_and:
  '&'                                                   { $$ = T0(@$); }
  ;

unary_mul:
  '*'                                                   { $$ = T0(@$); }
  ;

unary_plus:
  '+'                                                   { $$ = T0(@$); }
  ;

unary_minus:
  '-'                                                   { $$ = T0(@$); }
  ;

unary_binary_not:
  '~'                                                   { $$ = T0(@$); }
  ;

unary_logical_not:
  '!'                                                   { $$ = T0(@$); }
  ;

/* 6.5.4 */
cast_expression:
  unary_expression                                      { $$ = T1(@$,$1,@1); }
  | '(' type_name ')' cast_expression                   { $$ = T2(@$,$2,@2,$4,@4); }
  ;

/*
cast_expression:
  unary_expression                                      { $$ = $1; }
  | cast                                                { $$ = T1(@$,$1,@1); }
  ;

cast:
  '(' type_name ')' cast_expression                     { $$ = T2(@$,$2,@2,$4,@4); }
*/

/* 6.5.5 */
multiplicative_expression:
  cast_expression                                       { $$ = $1; }
  | mul_expression                                      { $$ = $1; }
  | div_expression                                      { $$ = $1; }
  | mod_expression                                      { $$ = $1; }
  ;

mul_expression:
  multiplicative_expression '*' cast_expression         { $$ = T2(@$,$1,@1,$3,@3); }
  ;

div_expression:
  multiplicative_expression '/' cast_expression         { $$ = T2(@$,$1,@1,$3,@3); }
  ;

mod_expression:
  multiplicative_expression '%' cast_expression         { $$ = T2(@$,$1,@1,$3,@3); }
  ;

/* 6.5.6 */
additive_expression:
  multiplicative_expression                             { $$ = $1; }
  | add_expression                                      { $$ = $1; }    
  | sub_expression                                      { $$ = $1; }
  ;

add_expression:
  additive_expression '+' multiplicative_expression     { $$ = T2(@$,$1,@1,$3,@3); }
  ;

sub_expression:
  additive_expression '-' multiplicative_expression     { $$ = T2(@$,$1,@1,$3,@3); }
  ;


/* 6.5.7 */
shift_expression:
  additive_expression                                   { $$ = $1; }
  | shift_left_expression                               { $$ = $1; }
  | shift_right_expression                              { $$ = $1; }
  ;

shift_left_expression:
  shift_expression LEFT additive_expression             { $$ = T2(@$,$1,@1,$3,@3); }
  ;

shift_right_expression:
  shift_expression RIGHT additive_expression            { $$ = T2(@$,$1,@1,$3,@3); }
  ;

/* 6.5.8 */
relational_expression:                                  
	shift_expression                                { $$ = $1; }
	| lt_expression                                 { $$ = $1; }
	| gt_expression                                 { $$ = $1; }
	| lteq_expression                               { $$ = $1; }
	| gteq_expression                               { $$ = $1; }
	;


lt_expression:
  relational_expression '<' shift_expression            { $$ = T2(@$,$1,@1,$3,@3); }
  ;

gt_expression:
  relational_expression '>' shift_expression            { $$ = T2(@$,$1,@1,$3,@3); }
  ;

lteq_expression:
  relational_expression LTEQ shift_expression           { $$ = T2(@$,$1,@1,$3,@3); }
  ;

gteq_expression:
  relational_expression GTEQ shift_expression           { $$ = T2(@$,$1,@1,$3,@3); }
  ;


/* 6.5.9 */
equality_expression:
	relational_expression                           { $$ = $1; }
	| eq_expression                                 { $$ = $1; }
	| neq_expression                                { $$ = $1; }
	;

eq_expression:
  equality_expression EQ relational_expression          { $$ = T2(@$,$1,@1,$3,@3); }
  ;

neq_expression:
  equality_expression NEQ relational_expression         { $$ = T2(@$,$1,@1,$3,@3); }
  ;


/* 6.5.10 */
and_expression:
	equality_expression                             { $$ = $1; }
	| and_expression '&' equality_expression        { $$ = T2(@$,$1,@1,$3,@3); }
	;

/* 6.5.11 */
exclusive_or_expression:
  and_expression                                        { $$ = $1; }
  | exclusive_or_expression '^' and_expression          { $$ = T2(@$,$1,@1,$3,@3); }
  ;

/* 6.5.12 */
inclusive_or_expression:
  exclusive_or_expression                               { $$ = $1; }
  | inclusive_or_expression '|' exclusive_or_expression { $$ = T2(@$,$1,@1,$3,@3); }
  ;

/* 6.5.13 */
logical_and_expression:
  inclusive_or_expression                               { $$ = $1; }
  | logical_and_expression AND inclusive_or_expression  { $$ = T2(@$,$1,@1,$3,@3); }
  ;

/* 6.5.14 */
logical_or_expression:
  logical_and_expression                                { $$ = $1; };
  | logical_or_expression OR logical_and_expression     { $$ = T2(@$,$1,@1,$3,@3); }
  ;

/* 6.5.15 */
conditional_expression:
  logical_or_expression                                              { $$ = $1; }
  | logical_or_expression '?' expression ':' conditional_expression  { $$ = T3(@$,$1,@1,$3,@3,$5,@5); }
  ;

/* 6.5.16 */
assignment_expression:
  conditional_expression                                { $$ = T1(@$,$1,@1); }
  | direct_assignment                                      { $$ = T1(@$,$1,@1); }
  | mul_assignment                                      { $$ = T1(@$,$1,@1); }
  | div_assignment                                      { $$ = T1(@$,$1,@1); }
  | mod_assignment                                      { $$ = T1(@$,$1,@1); }
  | add_assignment                                      { $$ = T1(@$,$1,@1); }
  | sub_assignment                                      { $$ = T1(@$,$1,@1); }
  | left_shift_assignment                               { $$ = T1(@$,$1,@1); }
  | right_shift_assignment                              { $$ = T1(@$,$1,@1); }
  | and_assignment                                      { $$ = T1(@$,$1,@1); }
  | xor_assignment                                      { $$ = T1(@$,$1,@1); }
  | or_assignment                                       { $$ = T1(@$,$1,@1); }
  ;

direct_assignment:
  unary_expression '=' assignment_expression         { $$ = T2(@$,$1,@1,$3,@3); }
  ;
mul_assignment:
  unary_expression MULASS assignment_expression         { $$ = T2(@$,$1,@1,$3,@3); }
  ;

div_assignment:
  unary_expression DIVASS assignment_expression         { $$ = T2(@$,$1,@1,$3,@3); }
  ;

mod_assignment:
  unary_expression MODASS assignment_expression         { $$ = T2(@$,$1,@1,$3,@3); }
  ;

add_assignment:
  unary_expression ADDASS assignment_expression         { $$ = T2(@$,$1,@1,$3,@3); }
  ;

sub_assignment:
  unary_expression SUBASS assignment_expression         { $$ = T2(@$,$1,@1,$3,@3); }
  ;

left_shift_assignment:
  unary_expression LEFTASS assignment_expression        { $$ = T2(@$,$1,@1,$3,@3); }
  ;

right_shift_assignment:
  unary_expression RIGHTASS assignment_expression       { $$ = T2(@$,$1,@1,$3,@3); }
  ;

and_assignment:
  unary_expression ANDASS assignment_expression         { $$ = T2(@$,$1,@1,$3,@3); }
  ;

xor_assignment:
  unary_expression XORASS assignment_expression         { $$ = T2(@$,$1,@1,$3,@3); }
  ;

or_assignment:
  unary_expression ORASS assignment_expression          { $$ = T2(@$,$1,@1,$3,@3); }


/* 6.5.17 */
expression:
  assignment_expression                                 { $$ = T1(@$,$1,@1); }
  | comma_expression                                    { $$ = T1(@$,$1,@1); }
  ;

comma_expression:
  expression ',' assignment_expression                  { $$ = T2(@$,$1,@1,$3,@3); }
  ;


/* 6.6 */
constant_expression:
  conditional_expression                                { $$ = T1(@$,$1,@1); }
  ;

enumeration_constant:
  identifier                                            { $$ = $1; }
  ;

identifier:
  IDENTIFIER                                            { $$ = T1(@$,LEAF(@$),@$); }
  ;

identifier_usertype:
  IDENTIFIER                                            { $$ = T1(@$,LEAF(@$),@$); }
  | USERTYPE                                            { $$ = T1(@$,LEAF(@$),@$); }
  ;

constant:
  CONSTANT                                              { $$ = T1(@$,LEAF(@$),@$); }
  ;

string:
  STRING                                                { $$ = T1(@$,LEAF(@$),@$); }
  ;

/* 
  A.2.2 Declarations
  ------------------
*/

/* 6.7 */
declaration:
  declaration_specifiers init_declarator_list ';'       { $$ = T2(@$,$1,@1,$2,@2); enable_c_notd = 0; }
  | declaration_specifiers ';'                          { $$ = T1(@$,$1,@1); enable_c_notd = 0; }
/*  | error ';' { yyerrok; }                              { $$ = T0(@$); } */
  ;

/* 6.7 */

declaration_specifiers:
  storage_class_specifier declaration_specifiers        { $$ = RLIST($2,$1); }
  | storage_class_specifier                             { $$ = T1(@$,$1,@1); }
  | type_specifier declaration_specifiers               { $$ = RLIST($2,$1); }
  | type_specifier                                      { $$ = T1(@$,$1,@1); }
  | type_qualifier declaration_specifiers               { $$ = RLIST($2,$1); }
  | type_qualifier                                      { $$ = T1(@$,$1,@1); }
  | function_specifier declaration_specifiers           { $$ = RLIST($2,$1); }
  | function_specifier                                  { $$ = T1(@$,$1,@1); }
  ;

/* 6.7 */
init_declarator_list:
  init_declarator                                       { $$ = T1(@$,$1,@1); }
  | init_declarator_list ',' init_declarator            { $$ = LIST($1, $3); }
  ;

/* 6.7 */
init_declarator:
  declarator                         /* 6.7.5 */        { $$ = T1(@$,$1,@1); }
  | declarator '=' initializer                          { $$ = T2(@$,$1,@1,$3,@3); }
  ;

/* 6.7.1 */
storage_class_specifier:
  typedef                                         { $$ = T1(@$,$1,@1); enable_c_notd = 1; }
  | extern                                        { $$ = T1(@$,$1,@1); }
  | static                                        { $$ = T1(@$,$1,@1); }
  | auto                                          { $$ = T1(@$,$1,@1); }
  | register                                      { $$ = T1(@$,$1,@1); }
  ;

typedef:
  TYPEDEF                                               { $$ = T0(@$); }
  ;
  
extern:
  EXTERN                                                { $$ = T0(@$); }
  ;
  
static:
  STATIC                                                { $$ = T0(@$); }
  ;
  
auto:
  AUTO                                                  { $$ = T0(@$); }
  ;
  
register:
  REGISTER                                              { $$ = T0(@$); }
  ;

/* 6.7.2 */

type_specifier:
  void                                                  { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | char                                                { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | short                                               { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | int                                                 { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | long                                                { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | float                                               { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | double                                              { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | signed                                              { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | unsigned                                            { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | _bool                                               { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | _complex                                            { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | _imaginary                                          { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | struct_or_union_specifier                           { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | enum_specifier                                      { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  | typedef_name                                        { $$ = T1(@$,$1,@1); if ( enable_c_notd ) c_tn_disable(); }
  ;

void:
  VOID                                                  { $$ = T0(@$); }
  ;
  
char:
  CHAR                                                  { $$ = T0(@$); }
  ;
  
short:
  SHORT                                                 { $$ = T0(@$); }
  ;
  
int:
  INT                                                   { $$ = T0(@$); }
  ;
  
long:
  LONG                                                  { $$ = T0(@$); }
  ;
  
float:
  FLOAT                                                 { $$ = T0(@$); }
  ;
  
double:
  DOUBLE                                                { $$ = T0(@$); }
  ;
  
signed:
  SIGNED                                                { $$ = T0(@$); }
  ;
  
unsigned:
  UNSIGNED                                              { $$ = T0(@$); }
  ;
  
_bool:
  _BOOL                                                 { $$ = T0(@$); }
  ;
  
_complex:
  _COMPLEX                                              { $$ = T0(@$); }
  ;
  
_imaginary:
  _IMAGINARY                                            { $$ = T0(@$); }
  ;
  

/* 6.7.2.1 */
struct_or_union_specifier:
  struct_or_union identifier_usertype '{' struct_declaration_list '}'    { $$ = T3(@$,$1,@1,$2,@2,$4,@4); }
  | struct_or_union '{' struct_declaration_list '}'             { $$ = T3(@$,$1,@1,NIL(@$),@$,$3,@3); }
  | struct_or_union identifier_usertype                         { $$ = T3(@$,$1,@1,$2,@2,NIL(@$),@$); }
  ;

/* 6.7.2.1 */
struct_or_union:
  struct                                                { $$ = $1; }
  | union                                               { $$ = $1; }
  ;

struct:
  STRUCT                                                { $$ = T0(@$); }
  ;

union:
  UNION                                                 { $$ = T0(@$); }
  ;


/* 6.7.2.1 */
struct_declaration_list:
  struct_declaration                                    { $$ = T1(@$,$1,@1); }
  | struct_declaration_list struct_declaration          { $$ = LIST($1, $2); }
  ;

/* 6.7.2.1 */
struct_declaration:
  specifier_qualifier_list struct_declarator_list ';'   { $$ = T2(@$,$1,@1,$2,@2); }
  ;

/* 6.7.2.1 */

specifier_qualifier_list:
  type_specifier specifier_qualifier_list               { $$ = RLIST($2, $1); }
  | type_specifier                                      { $$ = T1(@$,$1,@1); }
  | type_qualifier specifier_qualifier_list             { $$ = RLIST($2, $1); }
  | type_qualifier                                      { $$ = T1(@$,$1,@1); }
  ;
/*
specifier_qualifier_list:
  specifier_qualifier_list type_specifier               { $$ = LIST($1, $2); }
  | type_specifier                                      { $$ = T1(@$,$1,@1); }
  | specifier_qualifier_list type_qualifier             { $$ = LIST($1, $2); }
  | type_qualifier                                      { $$ = T1(@$,$1,@1); }
  ;
*/

/* 6.7.2.1 */
struct_declarator_list:
  struct_declarator                                     { $$ = T1(@$,$1,@1); }
  | struct_declarator_list ',' struct_declarator        { $$ = LIST($1, $3); }
  ;

/* 6.7.2.1 */
struct_declarator:
  declarator                                            { $$ = T1(@$,$1,@1); }
  | ':' constant_expression                             { $$ = T2(@$,NIL(@$),@$, $2,@2); }
  | declarator ':' constant_expression                  { $$ = T2(@$,$1,@1,$3,@3); }
  ;

/* 6.7.2.2 */
enum_specifier:
  ENUM identifier '{' enumerator_list '}'               { $$ = T2(@$,$2,@2,$4,@4); }
  | ENUM '{' enumerator_list '}'                        { $$ = T2(@$,NIL(@$),@$, $3,@3); }
  | ENUM identifier                                     { $$ = T2(@$,$2,@2, NIL(@$),@$); }
  ;

/* 6.7.2.2 */
enumerator_list:
  enumerator                                            { $$ = T1(@$,$1,@1); }
  | enumerator_list ',' enumerator                      { $$ = LIST($1, $3); }
  ;

/* 6.7.2.2 */
enumerator:
	enumeration_constant                            { $$ = T1(@$,$1,@1); }
	| enumeration_constant '=' constant_expression  { $$ = T2(@$,$1,@1,$3,@3); }
	;

/* 6.7.3 */
type_qualifier:
	const                                           { $$ = T1(@$,$1,@1); }
        | restrict                                      { $$ = T1(@$,$1,@1); }
	| volatile                                      { $$ = T1(@$,$1,@1); }
	;

const:
  CONST                                                 { $$ = T0(@$); }
  ;
  
restrict:
  RESTRICT                                              { $$ = T0(@$); }
  ;

volatile:
  VOLATILE                                              { $$ = T0(@$); }
  ;

/* 6.7.4 */
function_specifier:
  inline                                                { $$ = T1(@$,$1,@1); }
  ;

inline:
  INLINE                                                { $$ = T0(@$); }
  ;

/* 6.7.5 */
declarator:
  pointer direct_declarator                             { $$ = T2(@$,$1,@1,$2,@2); }
  | direct_declarator                                   { $$ = T2(@$,NIL(@$),@$,$1,@1); }
  ;

/* 6.7.5 */
direct_declarator:
  identifier                                            { $$ = T1(@$,$1,@1); }
  | function_parenthesis                                { $$ = T1(@$,$1,@1); }
  | direct_declarator declarator_square_bracket         { $$ = LIST($1, $2); }
  | direct_declarator declarator_parenthesis            { $$ = LIST($1, $2); }
  ;

/* 
  03.03.2009 added for a more clearly ast 
  actually, it is only a function of function_parenthesis is followed
  by declarator_parenthesis!
  the action could be $$ = T1(@$,$2,@2);
*/
function_parenthesis:
  '(' declarator ')'                                    { $$ = $2; }
  ;

/*
  simplifications
  - star is discarded 
  - 'static', if present, is the last child
  - type_qualifier_list, if present, is the first child
*/
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
  
star:
  '*'                                                   { $$ = T0(@$); }
  ;
  
declarator_parenthesis:
  '(' parameter_type_list ')'                           { $$ = T1(@$,$2,@2); }
  | '(' identifier_list ')'                             { $$ = T1(@$,$2,@2); }
  | '(' ')'                                             { $$ = T0(@$); }
  ;
  


/* 6.7.5 */
pointer:
  star type_qualifier_list                              { $$ = T2(@$,$1,@1,$2,@2); }
  | star                                                { $$ = T1(@$,$1,@1); }
  | star type_qualifier_list pointer                    { $$ = RLIST(RLIST($3, $2), $1); }
  | star pointer                                        { $$ = RLIST($2, $1); }
  ;


/* 6.7.5 */
type_qualifier_list:
  type_qualifier                                        { $$ = T1(@$,$1,@1); }
  | type_qualifier_list type_qualifier                  { $$ = LIST($1, $2); }
  ;

/* 6.7.5 */
parameter_type_list:
  parameter_list                                        { $$ = $1; }
  | parameter_list ',' ellipsis                         { $$ = LIST($1, $3); }
  ;

ellipsis:
  ELLIPSIS                                              { $$ = T0(@$); }
  ;

/* 6.7.5 */
parameter_list:
  parameter_declaration                                 { $$ = T1(@$,$1,@1); }
  | parameter_list ',' parameter_declaration            { $$ = LIST($1, $3); }
  ;

/* 6.7.5 */
parameter_declaration:
  declaration_specifiers declarator                     { $$ = T2(@$,$1,@1,$2,@2); }
  | declaration_specifiers abstract_declarator          { $$ = T2(@$,$1,@1,$2,@2); }
  | declaration_specifiers                              { $$ = T1(@$,$1,@1); }
  ;

/* 6.7.5 */
identifier_list:
  identifier                                            { $$ = T1(@$,$1,@1); }
  | identifier_list ',' identifier                      { $$ = LIST($1, $2); }
  ;

/* 6.7.6 */
type_name:
  specifier_qualifier_list                              { $$ = T1(@$,$1,@1); }
  | specifier_qualifier_list abstract_declarator        { $$ = T2(@$,$1,@1,$2,@2); }
  ;

/* 6.7.6 */
abstract_declarator:
  pointer                                               { $$ = T2(@$,$1,@1, NIL(@$),@$); }
  | pointer direct_abstract_declarator                  { $$ = T2(@$,$1,@1,$2,@2); }
  | direct_abstract_declarator                          { $$ = T2(@$,NIL(@$),@$, $1,@1); }
  ;


/* 6.7.6 */
direct_abstract_declarator:
  abstract_function_parenthesis                                         { $$ = T1(@$,$1,@1); }
  | direct_abstract_declarator abstract_declarator_square_bracket       { $$ = LIST($1, $2); }
  | abstract_declarator_square_bracket                                  { $$ = T1(@$,$1,@1); }
  | direct_abstract_declarator abstract_declarator_parenthesis          { $$ = LIST($1, $2); }
  | abstract_declarator_parenthesis                                     { $$ = T1(@$,$1,@1); }
  ;

/* 03.03.2009 added for a more clearly ast */
abstract_function_parenthesis:
  '(' abstract_declarator ')'                                    { $$ = $2; }
  ;

/*
  simplifications (as for declarator_square_bracket)
  - star is discarded 
*/

abstract_declarator_square_bracket:
  '[' assignment_expression ']'                         { $$ = T1(@$,$2,@2); }
  | '[' star ']'                                        { $$ = T0(@$); }
  | '[' ']'                                             { $$ = T0(@$); }
  ;
  
abstract_declarator_parenthesis:
  '(' parameter_type_list ')'                           { $$ = T1(@$,$2,@2); }
  | '(' ')'                                             { $$ = T0(@$); }


/* 6.7.7 */
typedef_name:
  USERTYPE                                              { $$ = T1(@$,LEAF(@$),@$); }

/* 6.7.8 */
initializer:
  assignment_expression                                 { $$ = T1(@$,$1,@1); }
  | '{' initializer_list '}'                            { $$ = T1(@$,$2,@2); }
  | '{' initializer_list ',' '}'                        { $$ = T1(@$,$2,@2); }
  ;

/* 6.7.8 */
initializer_list:
  designation initializer                               { $$ = T2(@$,$1,@1,$2,@2); }
  | initializer                                         { $$ = T1(@$,$1,@1); }
  | initializer_list ',' designation initializer        { $$ = LIST(LIST($1,$3), $4); }
  | initializer_list ',' initializer                    { $$ = LIST($1, $3); }
  ;

/* 6.7.8 */
designation:
  designator_list '='                                   { $$ = T1(@$,$1,@1); }
  

/* 6.7.8 */
designator_list:
  designator                                            { $$ = T1(@$,$1,@1); }
  | designator_list designator                          { $$ = LIST($1, $2); }

/* 6.7.8 */
designator:
  '[' constant_expression ']'                           { $$ = T1(@$,$2,@2); }
  | '.' identifier                                      { $$ = T1(@$,$2,@2); }

/* 
  A.2.3 Statements
  ----------------
*/

/* 6.8 */
statement:
  labeled_statement                                     { $$ = T1(@$,$1,@1); }
  | compound_statement                                  { $$ = T1(@$,$1,@1); }
  | expression_statement                                { $$ = T1(@$,$1,@1); }
  | selection_statement                                 { $$ = T1(@$,$1,@1); }
  | iteration_statement                                 { $$ = T1(@$,$1,@1); }
  | jump_statement                                      { $$ = T1(@$,$1,@1); }
  ;

/* 6.8.1 */
labeled_statement:
  label ':' statement                                   { $$ = T2(@$,$1,@1,$3,@3); }
  | case ':' statement                                  { $$ = T2(@$,$1,@1,$3,@3); }
  | default ':' statement                               { $$ = T2(@$,$1,@1,$3,@3); }
  ;

label:
  identifier                                            { $$ = T1(@$,$1,@1); }
  ;

case:
  CASE constant_expression                              { $$ = T1(@$,$1,@1); }
  ;
  
default:
  DEFAULT                                               { $$ = T0(@$); }
  ;

/* 6.8.2 */
compound_statement:
  '{' block_item_list '}'                               { $$ = T1(@$,$2,@2); }
  | '{' '}'                                             { $$ = T0(@$); }
  
/* 6.8.2 */
block_item_list:
  { PUSH("block_item_list"); } in_block_item_list { $$ = POP(@$); }

in_block_item_list:
  block_item                                            { $$ = LIST(LAST(), $1); }
  | in_block_item_list block_item                       { $$ = LIST(LAST(), $2); }
  ;

/* 6.8.2 */
block_item:
  declaration                                           { $$ = T1(@$,$1,@1); }
  | statement                                           { $$ = T1(@$,$1,@1); }
  ;

/* 6.8.3 */
expression_statement:
  expression ';'                                        { $$ = T1(@$,$1,@1); }
  | ';'                                                 { $$ = T0(@$); }
  ;

/* 6.8.4 */
/* see also */
/* http://marvin.cs.uidaho.edu/~heckendo/Handouts/danglingElse.html */
/* http://en.wikipedia.org/wiki/Dangling_else */
/* produces the known shift/reduce conflict */
selection_statement:
  if                                                    { $$ = T1(@$,$1,@1); }
  | switch                                              { $$ = T1(@$,$1,@1); }
  ;
  
if:
  IF '(' expression ')' statement                       { $$ = T3(@$,$3,@3,$5,@5,NIL(@$),@$); }
  | IF '(' expression ')' statement ELSE statement      { $$ = T3(@$,$3,@3,$5,@5,$7,@7); }
  ;
  
switch:
  SWITCH '(' expression ')' statement                   { $$ = T2(@$,$3,@3,$5,@5); }
  ;

/* 6.8.5 */
iteration_statement:
  while                                                 { $$ = T1(@$,$1,@1); }
  | do                                                  { $$ = T1(@$,$1,@1); }
  | for                                                 { $$ = T1(@$,$1,@1); }
  ;
  
while:
  WHILE '(' expression ')' statement                    { $$ = T2(@$,$3,@3,$5,@5); }
  ;
  
do:
  DO statement WHILE '(' expression ')' ';'             { $$ = T2(@$,$5,@5,$2,@2); }
  ;
  
for:
  FOR '(' ';' ';' ')' statement                         { $$ = T4(@$,NIL(@$),@$, NIL(@$),@$, NIL(@$),@$, $6,@6); }
  | FOR '(' expression ';' ';' ')' statement            { $$ = T4(@$,$3,@3, NIL(@$),@$, NIL(@$),@$, $7, @7); }
  | FOR '(' ';' expression ';' ')' statement            { $$ = T4(@$,NIL(@$),@$, $4,@4, NIL(@$),@$, $7,@7); }
  | FOR '(' expression ';' expression ';' ')' statement { $$ = T4(@$,$3,@3, $5,@5, NIL(@$),@$, $8,@8); }
  | FOR '(' ';' ';' expression ')' statement            { $$ = T4(@$,NIL(@$),@$, NIL(@$),@$, $5,@5, $7,@7); }
  | FOR '(' expression ';' ';' expression ')' statement { $$ = T4(@$,$3,@3, NIL(@$),@$, $6,@6, $8,@8); }
  | FOR '(' ';' expression ';' expression ')' statement { $$ = T4(@$,NIL(@$),@$, $4,@4, $6,@6, $8,@8); }
  | FOR '(' expression ';' expression ';' expression ')' statement { $$ = T4(@$,$3,@3,$5,@5,$7,@7,$9,@9); }
  | FOR '(' declaration ';' ')' statement               { $$ = T4(@$,$3,@3, NIL(@$),@$, NIL(@$),@$, $6,@6); }
  | FOR '(' declaration expression ';' ')' statement    { $$ = T4(@$,$3,@3, $4,@4, NIL(@$),@$, $7,@7); }
  | FOR '(' declaration ';' expression ')' statement    { $$ = T4(@$,$3,@3, NIL(@$),@$, $5,@5, $7,@7); }
  | FOR '(' declaration expression ';' expression ')' statement    { $$ = T4(@$,$3,@3,$4,@4,$6,@6,$8,@8); }
;

/* 6.8.6 */
jump_statement:
  goto                                                  { $$ = T1(@$,$1,@1); }
  | continue                                            { $$ = T1(@$,$1,@1); }
  | break                                               { $$ = T1(@$,$1,@1); }
  | return                                              { $$ = T1(@$,$1,@1); }
  ;
  
goto:
  GOTO identifier ';'                                   { $$ = T1(@$,$2,@2); }
  ;

continue:
  CONTINUE ';'                                          { $$ = T0(@$); }
  ;

break:
  BREAK ';'                                             { $$ = T0(@$); }
  ;
  
return:
  RETURN expression ';'                                 { $$ = T1(@$,$2,@2); }
  | RETURN ';'                                          { $$ = T0(@$); }


/* 
  A.2.4 External definitions
  --------------------------
*/

/* 6.9 */
translation_unit:
  { PUSH("translation_unit"); } in_translation_unit { $$ = POP(@$); }

in_translation_unit:
  external_declaration                                  { $$ = LIST(LAST(), $1); }
  | in_translation_unit external_declaration            { $$ = LIST(LAST(), $2); }
  ;

/* 6.9 */
external_declaration:
  function_definition                                   { $$ = T1(@$,$1,@1); }
  | declaration                                         { $$ = T1(@$,$1,@1); }
  ;

/* 6.9.1 */
function_definition:
  declaration_specifiers declarator declaration_list compound_statement { $$ = T4(@$,$1,@1,$2,@2,$3,@3,$4,@4); }
  | declaration_specifiers declarator compound_statement                { $$ = T4(@$,$1,@1,$2,@2,NIL(@$),@$,$3,@3); }
  
/* 
  sollte den fall einer funktion ohne rückgabewert ermöglichen, aber das scheint etwas mehr arbeit zu sein 
  die rule selber scheint zu funktionieren --> test_fn_10.c
*/
  | declarator compound_statement                                                 { $$ = T4(@$,  NIL(@$),@$,   $1,@1,  NIL(@$),@$,  $2,@2); }
/*
  was ist eigentlich mit 
  | declarator declaration_list  compound_statement                                                 { $$ = T4(@$,  NIL(@$),@$,   $1,@1,  $2,@2,  $3,@3); }
 ??? das müsste dann der fall sein K&R definition ohne rückgabewert (also mit int)
*/

/* 6.9.1 */
declaration_list:
  declaration  /* 6.7 */                                { $$ = T1(@$,$1,@1); }
  | declaration_list declaration                        { $$ = LIST($1,$2); }
  ;


/* 
  entry point
  -----------
*/

file:
  translation_unit                                      { c_result = T1(@$,$1,@1); }


%%

void c_yyerror(const char *msg)
{
/*
  printf("%d.%d: %s\n", c_line, c_col, msg);
  */
}


