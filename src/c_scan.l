/*

  ISO 9899:1999 scanner 
  
  (c) 2008 Oliver Kraus
  
*/

%option prefix = "c_yy"
/* no call to  yywrap */
%option noyywrap
/* this is a none-interactive scanner */
%option never-interactive
/* yytest is 'char *' */
%pointer

%{
/* includes */
#include <stdlib.h>     /* atoi */
#include <string.h>     /* strncmp */
#include <unistd.h>     /* read */

#include "c_ast.h"      /* definition of c_loc_struct and c_is_typedef */
#define YYLTYPE c_loc_struct
#include "c_tok.h"      /* token def's from c_gram.y */    

/* prototypes */
static void c_comment(void);
static void c_user_action(void);
static void c_tab(void);
static void c_newline(void);
static void c_skip_line(void);
static void c_lineno(void);
static void c_tn_init(void);
static void c_tn_push(void);
static void c_tn_pop(void);
static void c_tn_enable(void);
void c_tn_disable(void);
static int c_tn_is_enable(void);
static int c_type(void);
void c_yyerror(const char *msg);

/* macros */
#define YY_USER_ACTION c_user_action();
#define C_FILENAME_LEN (1024*8)
#define C_TYPENAME_STACK_LEN (1024*2)

long c_last_fpos = 0;
long c_fpos = 0;
static unsigned char c_typename_stack[C_TYPENAME_STACK_LEN];
static int c_typename_pos = 0;




#define C_FIRST_LINE c_yylloc.first_line
#define C_FIRST_COLUMN c_yylloc.first_column
#define C_LAST_LINE c_yylloc.last_line
#define C_LAST_COLUMN c_yylloc.last_column

/*
int C_FIRST_LINE = 1;
int C_LAST_LINE = 1;                 
int C_FIRST_COLUMN = 0;
int C_LAST_COLUMN = 0;                 
*/

char c_filename[C_FILENAME_LEN];



%}

digit                   [0-9]
nonzero_digit           [1-9]
hex_digit               [0-9a-fA-F]
hex_quad                {hex_digit}{4}
oct_digit               [0-7]
nondigit                [a-zA-Z_]
univ_char_name          (\\u{hex_quad}|\\U{hex_quad}{hex_quad})
id_nondigit             ({nondigit}|{univ_char_name})

integer_suf             (u|U|l|L)+
dec_constant            {nonzero_digit}{digit}*{integer_suf}?
hex_constant            0[xX]{hex_digit}+{integer_suf}?
oct_constant            0{oct_digit}*{integer_suf}?
integer_constant        ({hex_constant}|{oct_constant}|{dec_constant})

floating_suf            (f|F|l|L)
dec_exp_part            [eE][+-]?{digit}+
hex_exp_part            [pP][+-]?{digit}+
dec_fl_constant         {digit}*[.]{digit}+{dec_exp_part}?{floating_suf}?
hex_fl_constant         0[xX]{hex_digit}*[.]{hex_digit}+{hex_exp_part}?{floating_suf}?

fl_constant             ({hex_fl_constant}|{dec_fl_constant})

char_constant           L?'(\\.|[^\\'])+'
str_constant            L?["](\\.|[^\\"])*["]

%%

"/*"			{ c_comment(); }
"//"			{ c_skip_line(); }

"\n"			{ c_newline(); }
[ \t\v\f\r]+            { /* whitespace */ }
[#]line[ ][^\n]*[\n]    { c_lineno(); }
[#][ ][^\n]*[\n]        { c_lineno(); }


"auto"          { return AUTO; }
"break"         { return BREAK; }
"case"          { return CASE; }
"char"          { return CHAR; }
"const"         { return CONST; }
"continue"      { return CONTINUE; }
"default"       { return DEFAULT; }
"do"            { return DO; }
"double"        { return DOUBLE; }
"else"          { return ELSE; }
"enum"          { return ENUM; }
"extern"        { return EXTERN; }
"float"         { return FLOAT; }
"for"           { return FOR; }
"goto"          { return GOTO; }
"if"            { return IF; }
"inline"        { return INLINE; }
"int"           { return INT; }
"long"          { return LONG; }
"register"      { return REGISTER; }
"restrict"      { return RESTRICT; }
"return"        { return RETURN; }
"short"         { return SHORT; }
"signed"        { return SIGNED; }
"sizeof"        { return SIZEOF; }
"static"        { return STATIC; }
"struct"        { return STRUCT; }
"switch"        { return SWITCH; }
"typedef"       { return TYPEDEF; }
"union"         { return UNION; }
"unsigned"      { return UNSIGNED; }
"void"          { return VOID; }
"volatile"      { return VOLATILE; }
"while"         { return WHILE; }
"_Bool"         { return _BOOL; }
"_Complex"      { return _COMPLEX; }
"_Imaginary"    { return _IMAGINARY; }

"{"             { c_tn_push(); return '{'; }
"<%"            { c_tn_push(); return '{'; }
"}"             { c_tn_pop(); return '}'; }
"%>"            { c_tn_pop(); return '}'; }
"["             { return '['; }
"<:"            { return '['; }
"]"             { return ']'; }
":>"            { return ']'; }
"("             { c_tn_push(); return '('; }
")"             { c_tn_pop(); return ')'; }
","             { return ','; }
";"             { c_tn_enable(); return ';'; }
":"             { return ':'; }
"?"             { return '?'; }
"."             { return '.'; }
"+"             { return '+'; }
"-"             { return '-'; }
"*"             { return '*'; }
"/"             { return '/'; }
"%"             { return '%'; }
"^"             { return '^'; }
"&"             { return '&'; }
"|"             { return '|'; }
"<<"		{ return LEFT; }
">>"		{ return RIGHT; }

"~"             { return '~'; }
"!"             { return '!'; }

"="             { return '='; }
"<"             { return '<'; }
">"             { return '>'; }
"+="            { return ADDASS; }
"-="            { return SUBASS; }
"*="            { return MULASS; }
"/="            { return DIVASS; }
"%="            { return MODASS; }
"^="            { return XORASS; }
"&="		{ return ANDASS; }
"|="		{ return ORASS; }
"<<="           { return LEFTASS; }
">>="           { return RIGHTASS; }

"=="            { return EQ; }
"!="            { return NEQ; }
"<="            { return LTEQ; }
">="            { return GTEQ; }

"&&"            { return AND; }
"||"            { return OR; }
"++"            { return INC; }
"--"            { return DEC; }
"->"            { return ARROW; }
"..."           { return ELLIPSIS; }


{id_nondigit}({id_nondigit}|{digit})*   { return c_type(); }
{str_constant}          { return STRING; }
{integer_constant}      { return CONSTANT; }
{char_constant}         { return CONSTANT; }
{fl_constant}           { return CONSTANT; }

.			{ /* ignore bad characters */ }

<<EOF>>         { return 0; }
%%

static void c_comment(void)
{
  register int c;

  for ( ; ; )
  {
    for(;;)
    {
      c = input();
      C_LAST_COLUMN++; 
      c_fpos++;
      if ( c == '*' || c == EOF )
        break;
      if ( c == '\n' )
        c_newline();
    }

    if ( c == '*' )
    {
      while ( (c = input()) == '*' )
      {
        C_LAST_COLUMN++;
        c_fpos++;
      }
      C_LAST_COLUMN++;
      c_fpos++;
      if ( c == '\n' )
        c_newline();
      if ( c == '/' )
        break;    /* found the end */
    }

    if ( c == EOF )
    {
        c_yyerror( "EOF in comment" );
        break;
    }
  }
  C_FIRST_COLUMN = C_LAST_COLUMN;
  c_last_fpos = c_fpos;
}

/* called by YY_USER_ACTION */
static void c_user_action(void)
{
  C_FIRST_LINE = C_LAST_LINE;
  C_FIRST_COLUMN = C_LAST_COLUMN;
  c_last_fpos = c_fpos;  
  C_LAST_COLUMN += c_yyleng;
  c_fpos += c_yyleng;
}

static void c_newline(void)
{
  C_LAST_LINE++;
  C_LAST_COLUMN = 0;
}

static void c_skip_line(void)
{
  int c;
  for(;;)
  {
    c = input();
    C_LAST_COLUMN++;
    c_fpos++;
    if ( c == EOF )
      break;
    if ( c == '\n' )
    {
      c_newline();
      break;
    }
  }
}

/*

from gnu cpp:

#line linenum
    linenum is a non-negative decimal integer constant. 
It specifies the line number which should be reported 
for the following line of input. Subsequent lines are 
counted from linenum.

#line linenum filename
    linenum is the same as for the first form, and has 
the same effect. In addition, filename is a string 
constant. The following line and all subsequent lines 
are reported to come from the file it specifies, until 
something else happens to change that. filename is 
interpreted according to the normal rules for a string 
constant: backslash escapes are interpreted. This is 
different from `#include'.

[filename is s-char-sequence from iso9899]


# linenum filename flags

These are called linemarkers. They are inserted as 
needed into the output (but never within a string or 
character constant). They mean that the following line 
originated in file filename at line linenum. filename 
will never contain any non-printing characters; they 
are replaced with octal escape sequences.

After the file name comes zero or more flags, which are 
`1', `2', `3', or `4'. If there are multiple flags, 
spaces separate them. Here is what the flags mean:

`1'
    This indicates the start of a new file.
`2'
    This indicates returning to a file (after having 
    included another file).
`3'
    This indicates that the following text comes from 
    a system header file, so certain warnings should 
    be suppressed.
`4'
    This indicates that the following text should be 
    treated as being wrapped in an implicit extern "C" 
    block.
*/

/*
  store the filename of "# "  or "#line" in c_filename
  
  supports escaped chars with '\'
  
  TODO: Support esc seq from ISO9899
  
*/
static void c_lineno_parse_filename(char **s)
{
  int i=0;
  if ( **s == '\"' )
  {
    (*s)++;
    for(;;)
    {
      if ( **s == '\\' )
      {
        (*s)++;
        if ( **s == '\0' )
          break;    /* string terminated in esc seq */
        if ( i+1 < C_FILENAME_LEN )
          c_filename[i] = **s;
        (*s)++;
      }
      else if ( **s == '\0' )
      {
        break; /* string terminated without " */
      }
      else if ( **s == '\"' )
      {
        (*s)++;
        break;
      }
      else
      {
        if ( i+1 < C_FILENAME_LEN )
          c_filename[i] = **s;
        (*s)++;
      }
    }
    c_filename[i] = '\0';
  }
}


static int c_lineno_get_val(char **s)
{
  int val = 0;
  for(;;)
  {
    if ( **s >= '0' && **s <= '9' )
    {
      val = val*10 + ( **s - '0' );
      (*s)++;
    }
    else
    {
      break;
    }
  }
  return val;
}

static void c_lineno_skip_space(char **s)
{
  while ( **s == ' ' || **s == '\t' )
    (*s)++;
}

static void c_lineno_parse(char **s)
{
  int lineno;
  if ( **s == '#' )
    (*s)++;
  if ( strncmp( *s, "line", 4 ) == 0 )
    (*s) += 4;
  c_lineno_skip_space(s);
  lineno = c_lineno_get_val(s);
  c_lineno_skip_space(s);
  c_lineno_parse_filename(s);

  C_LAST_COLUMN = 0;
  C_LAST_LINE = lineno;
}

static void c_lineno(void)
{
  char *s = yytext;
  c_lineno_parse(&s);
}

static void c_tn_init(void)
{
  c_typename_pos = 0;
  c_typename_stack[c_typename_pos] = 1;
}

static void c_tn_push(void)
{
  c_typename_pos++;
  if ( c_typename_pos >= C_TYPENAME_STACK_LEN )
  {
    fprintf(stderr, "c-lexer typename stack overflow\n");
    exit(1);
  }
  c_typename_stack[c_typename_pos] = 1;
}

static void c_tn_pop(void)
{
  if ( c_typename_pos > 0 )
    c_typename_pos--;
}

static void c_tn_enable(void)
{
  c_typename_stack[c_typename_pos] = 1;
}

void c_tn_disable(void)
{
  c_typename_stack[c_typename_pos] = 0;
}

static int c_tn_is_enable(void)
{
  return (int)c_typename_stack[c_typename_pos];
}


static int c_type(void)
{
  if ( c_tn_is_enable() != 0 )
    if ( c_is_typedef(yytext) != 0 )
      return USERTYPE;
  return IDENTIFIER;
}

/* create and switch to a pure string buffer */
/* remember to add one additional CR and */
/* two additional YY_END_OF_BUFFER_CHAR */

YY_BUFFER_STATE c_yy_string_buffer = NULL;
int c_init_string_buffer(char *str, size_t len)
{
  c_yy_string_buffer = c_yy_scan_buffer( str, len );
  if ( c_yy_string_buffer == NULL )
    return 0;
  return 1;
}

void c_destroy_string_buffer(void)
{
  if ( c_yy_string_buffer != NULL )
    c_yy_delete_buffer( c_yy_string_buffer );
}

void c_scan_init(void)
{
  c_last_fpos = 0;
  c_fpos = 0;
  c_tn_init();
}