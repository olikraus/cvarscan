
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse         c_yyparse
#define yylex           c_yylex
#define yyerror         c_yyerror
#define yylval          c_yylval
#define yychar          c_yychar
#define yydebug         c_yydebug
#define yynerrs         c_yynerrs
#define yylloc          c_yylloc

/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 23 "c_gram.y"


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



/* Line 189 of yacc.c  */
#line 115 "c_gram.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 1
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AUTO = 258,
     BREAK = 259,
     CASE = 260,
     CHAR = 261,
     CONST = 262,
     CONTINUE = 263,
     DEFAULT = 264,
     DO = 265,
     DOUBLE = 266,
     ELSE = 267,
     ENUM = 268,
     EXTERN = 269,
     FLOAT = 270,
     FOR = 271,
     GOTO = 272,
     IF = 273,
     INLINE = 274,
     INT = 275,
     LONG = 276,
     REGISTER = 277,
     RESTRICT = 278,
     RETURN = 279,
     SHORT = 280,
     SIGNED = 281,
     SIZEOF = 282,
     STATIC = 283,
     STRUCT = 284,
     SWITCH = 285,
     TYPEDEF = 286,
     UNION = 287,
     UNSIGNED = 288,
     VOID = 289,
     VOLATILE = 290,
     WHILE = 291,
     _BOOL = 292,
     _COMPLEX = 293,
     _IMAGINARY = 294,
     LEFT = 295,
     RIGHT = 296,
     ADDASS = 297,
     SUBASS = 298,
     MULASS = 299,
     DIVASS = 300,
     MODASS = 301,
     XORASS = 302,
     ANDASS = 303,
     ORASS = 304,
     LEFTASS = 305,
     RIGHTASS = 306,
     LTEQ = 307,
     GTEQ = 308,
     EQ = 309,
     NEQ = 310,
     AND = 311,
     OR = 312,
     INC = 313,
     DEC = 314,
     ARROW = 315,
     ELLIPSIS = 316,
     STRING = 317,
     CONSTANT = 318,
     USERTYPE = 319,
     IDENTIFIER = 320
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 235 "c_gram.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  74
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1897

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  161
/* YYNRULES -- Number of rules.  */
#define YYNRULES  336
/* YYNRULES -- Number of states.  */
#define YYNSTATES  527

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   320

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    79,     2,     2,     2,    81,    74,     2,
      66,    67,    75,    76,    73,    77,    70,    80,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    87,    89,
      82,    88,    83,    86,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,    84,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    71,    85,    72,    78,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    18,    21,
      24,    27,    30,    33,    35,    39,    43,    46,    49,    52,
      54,    56,    63,    71,    73,    77,    79,    82,    85,    88,
      91,    96,    98,   100,   102,   104,   106,   108,   110,   112,
     114,   116,   118,   120,   122,   124,   129,   131,   133,   135,
     137,   141,   145,   149,   151,   153,   155,   159,   163,   165,
     167,   169,   173,   177,   179,   181,   183,   185,   187,   191,
     195,   199,   203,   205,   207,   209,   213,   217,   219,   223,
     225,   229,   231,   235,   237,   241,   243,   247,   249,   255,
     257,   259,   261,   263,   265,   267,   269,   271,   273,   275,
     277,   279,   283,   287,   291,   295,   299,   303,   307,   311,
     315,   319,   323,   325,   327,   331,   333,   335,   337,   339,
     341,   343,   345,   349,   352,   355,   357,   360,   362,   365,
     367,   370,   372,   374,   378,   380,   384,   386,   388,   390,
     392,   394,   396,   398,   400,   402,   404,   406,   408,   410,
     412,   414,   416,   418,   420,   422,   424,   426,   428,   430,
     432,   434,   436,   438,   440,   442,   444,   446,   448,   450,
     452,   454,   456,   458,   464,   469,   472,   474,   476,   478,
     480,   482,   485,   489,   492,   494,   497,   499,   501,   505,
     507,   510,   514,   520,   525,   528,   530,   534,   536,   540,
     542,   544,   546,   548,   550,   552,   554,   556,   559,   561,
     563,   565,   568,   571,   575,   580,   586,   591,   597,   602,
     606,   610,   614,   617,   619,   623,   627,   630,   633,   635,
     639,   642,   644,   647,   649,   653,   655,   657,   661,   664,
     667,   669,   671,   675,   677,   680,   682,   685,   687,   689,
     692,   694,   697,   699,   703,   707,   711,   714,   718,   721,
     723,   725,   729,   734,   737,   739,   744,   748,   751,   753,
     756,   760,   763,   765,   767,   769,   771,   773,   775,   779,
     783,   787,   789,   792,   794,   798,   801,   802,   805,   807,
     810,   812,   814,   817,   819,   821,   823,   829,   837,   843,
     845,   847,   849,   855,   863,   870,   878,   886,   895,   903,
     912,   921,   931,   938,   946,   954,   963,   965,   967,   969,
     971,   975,   978,   981,   985,   988,   989,   992,   994,   997,
     999,  1001,  1006,  1010,  1013,  1015,  1018
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     250,     0,    -1,   151,    -1,   153,    -1,   154,    -1,    66,
     147,    67,    -1,    91,    -1,    92,    93,    -1,    92,    94,
      -1,    92,    95,    -1,    92,    96,    -1,    92,    97,    -1,
      92,    98,    -1,    99,    -1,    68,   147,    69,    -1,    66,
     100,    67,    -1,    66,    67,    -1,    70,   152,    -1,    60,
     152,    -1,    58,    -1,    59,    -1,    66,   209,    67,    71,
     217,    72,    -1,    66,   209,    67,    71,   217,    73,    72,
      -1,   135,    -1,   100,    73,   135,    -1,    92,    -1,    97,
     101,    -1,    98,   101,    -1,   103,   110,    -1,   102,   101,
      -1,   102,    66,   209,    67,    -1,    27,    -1,   104,    -1,
     105,    -1,   106,    -1,   107,    -1,   108,    -1,   109,    -1,
      74,    -1,    75,    -1,    76,    -1,    77,    -1,    78,    -1,
      79,    -1,   101,    -1,    66,   209,    67,   110,    -1,   110,
      -1,   112,    -1,   113,    -1,   114,    -1,   111,    75,   110,
      -1,   111,    80,   110,    -1,   111,    81,   110,    -1,   111,
      -1,   116,    -1,   117,    -1,   115,    76,   111,    -1,   115,
      77,   111,    -1,   115,    -1,   119,    -1,   120,    -1,   118,
      40,   115,    -1,   118,    41,   115,    -1,   118,    -1,   122,
      -1,   123,    -1,   124,    -1,   125,    -1,   121,    82,   118,
      -1,   121,    83,   118,    -1,   121,    52,   118,    -1,   121,
      53,   118,    -1,   121,    -1,   127,    -1,   128,    -1,   126,
      54,   121,    -1,   126,    55,   121,    -1,   126,    -1,   129,
      74,   126,    -1,   129,    -1,   130,    84,   129,    -1,   130,
      -1,   131,    85,   130,    -1,   131,    -1,   132,    56,   131,
      -1,   132,    -1,   133,    57,   132,    -1,   133,    -1,   133,
      86,   147,    87,   134,    -1,   134,    -1,   136,    -1,   137,
      -1,   138,    -1,   139,    -1,   140,    -1,   141,    -1,   142,
      -1,   143,    -1,   144,    -1,   145,    -1,   146,    -1,   101,
      88,   135,    -1,   101,    44,   135,    -1,   101,    45,   135,
      -1,   101,    46,   135,    -1,   101,    42,   135,    -1,   101,
      43,   135,    -1,   101,    50,   135,    -1,   101,    51,   135,
      -1,   101,    48,   135,    -1,   101,    47,   135,    -1,   101,
      49,   135,    -1,   135,    -1,   148,    -1,   147,    73,   135,
      -1,   134,    -1,   151,    -1,    65,    -1,    65,    -1,    64,
      -1,    63,    -1,    62,    -1,   156,   157,    89,    -1,   156,
      89,    -1,   159,   156,    -1,   159,    -1,   165,   156,    -1,
     165,    -1,   190,   156,    -1,   190,    -1,   194,   156,    -1,
     194,    -1,   158,    -1,   157,    73,   158,    -1,   196,    -1,
     196,    88,   216,    -1,   160,    -1,   161,    -1,   162,    -1,
     163,    -1,   164,    -1,    31,    -1,    14,    -1,    28,    -1,
       3,    -1,    22,    -1,   166,    -1,   167,    -1,   168,    -1,
     169,    -1,   170,    -1,   171,    -1,   172,    -1,   173,    -1,
     174,    -1,   175,    -1,   176,    -1,   177,    -1,   178,    -1,
     187,    -1,   215,    -1,    34,    -1,     6,    -1,    25,    -1,
      20,    -1,    21,    -1,    15,    -1,    11,    -1,    26,    -1,
      33,    -1,    37,    -1,    38,    -1,    39,    -1,   179,   152,
      71,   182,    72,    -1,   179,    71,   182,    72,    -1,   179,
     152,    -1,   180,    -1,   181,    -1,    29,    -1,    32,    -1,
     183,    -1,   182,   183,    -1,   184,   185,    89,    -1,   165,
     184,    -1,   165,    -1,   190,   184,    -1,   190,    -1,   186,
      -1,   185,    73,   186,    -1,   196,    -1,    87,   149,    -1,
     196,    87,   149,    -1,    13,   151,    71,   188,    72,    -1,
      13,    71,   188,    72,    -1,    13,   151,    -1,   189,    -1,
     188,    73,   189,    -1,   150,    -1,   150,    88,   149,    -1,
     191,    -1,   192,    -1,   193,    -1,     7,    -1,    23,    -1,
      35,    -1,   195,    -1,    19,    -1,   202,   197,    -1,   197,
      -1,   151,    -1,   198,    -1,   197,   199,    -1,   197,   201,
      -1,    66,   196,    67,    -1,    68,   203,   135,    69,    -1,
      68,   162,   203,   135,    69,    -1,    68,   162,   135,    69,
      -1,    68,   203,   162,   135,    69,    -1,    68,   203,   200,
      69,    -1,    68,   203,    69,    -1,    68,   135,    69,    -1,
      68,   200,    69,    -1,    68,    69,    -1,    75,    -1,    66,
     204,    67,    -1,    66,   208,    67,    -1,    66,    67,    -1,
     200,   203,    -1,   200,    -1,   200,   203,   202,    -1,   200,
     202,    -1,   190,    -1,   203,   190,    -1,   206,    -1,   206,
      73,   205,    -1,    61,    -1,   207,    -1,   206,    73,   207,
      -1,   156,   196,    -1,   156,   210,    -1,   156,    -1,   151,
      -1,   208,    73,   151,    -1,   184,    -1,   184,   210,    -1,
     202,    -1,   202,   211,    -1,   211,    -1,   212,    -1,   211,
     213,    -1,   213,    -1,   211,   214,    -1,   214,    -1,    66,
     210,    67,    -1,    68,   135,    69,    -1,    68,   200,    69,
      -1,    68,    69,    -1,    66,   204,    67,    -1,    66,    67,
      -1,    64,    -1,   135,    -1,    71,   217,    72,    -1,    71,
     217,    73,    72,    -1,   218,   216,    -1,   216,    -1,   217,
      73,   218,   216,    -1,   217,    73,   216,    -1,   219,    88,
      -1,   220,    -1,   219,   220,    -1,    68,   149,    69,    -1,
      70,   151,    -1,   222,    -1,   226,    -1,   231,    -1,   232,
      -1,   235,    -1,   239,    -1,   223,    87,   221,    -1,   224,
      87,   221,    -1,   225,    87,   221,    -1,   151,    -1,     5,
     149,    -1,     9,    -1,    71,   227,    72,    -1,    71,    72,
      -1,    -1,   228,   229,    -1,   230,    -1,   229,   230,    -1,
     155,    -1,   221,    -1,   147,    89,    -1,    89,    -1,   233,
      -1,   234,    -1,    18,    66,   147,    67,   221,    -1,    18,
      66,   147,    67,   221,    12,   221,    -1,    30,    66,   147,
      67,   221,    -1,   236,    -1,   237,    -1,   238,    -1,    36,
      66,   147,    67,   221,    -1,    10,   221,    36,    66,   147,
      67,    89,    -1,    16,    66,    89,    89,    67,   221,    -1,
      16,    66,   147,    89,    89,    67,   221,    -1,    16,    66,
      89,   147,    89,    67,   221,    -1,    16,    66,   147,    89,
     147,    89,    67,   221,    -1,    16,    66,    89,    89,   147,
      67,   221,    -1,    16,    66,   147,    89,    89,   147,    67,
     221,    -1,    16,    66,    89,   147,    89,   147,    67,   221,
      -1,    16,    66,   147,    89,   147,    89,   147,    67,   221,
      -1,    16,    66,   155,    89,    67,   221,    -1,    16,    66,
     155,   147,    89,    67,   221,    -1,    16,    66,   155,    89,
     147,    67,   221,    -1,    16,    66,   155,   147,    89,   147,
      67,   221,    -1,   240,    -1,   241,    -1,   242,    -1,   243,
      -1,    17,   151,    89,    -1,     8,    89,    -1,     4,    89,
      -1,    24,   147,    89,    -1,    24,    89,    -1,    -1,   245,
     246,    -1,   247,    -1,   246,   247,    -1,   248,    -1,   155,
      -1,   156,   196,   249,   226,    -1,   156,   196,   226,    -1,
     196,   226,    -1,   155,    -1,   249,   155,    -1,   244,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   145,   145,   146,   147,   148,   154,   155,   156,   157,
     158,   159,   160,   161,   165,   169,   170,   174,   178,   182,
     186,   190,   191,   196,   197,   202,   203,   204,   205,   206,
     207,   211,   227,   228,   229,   230,   231,   232,   235,   239,
     243,   247,   251,   255,   260,   261,   276,   277,   278,   279,
     283,   287,   291,   296,   297,   298,   302,   306,   312,   313,
     314,   318,   322,   327,   328,   329,   330,   331,   336,   340,
     344,   348,   354,   355,   356,   360,   364,   370,   371,   376,
     377,   382,   383,   388,   389,   394,   395,   400,   401,   406,
     407,   408,   409,   410,   411,   412,   413,   414,   415,   416,
     417,   421,   424,   428,   432,   436,   440,   444,   448,   452,
     456,   460,   465,   466,   470,   476,   480,   484,   488,   489,
     493,   497,   507,   508,   515,   516,   517,   518,   519,   520,
     521,   522,   527,   528,   533,   534,   539,   540,   541,   542,
     543,   547,   551,   555,   559,   563,   569,   570,   571,   572,
     573,   574,   575,   576,   577,   578,   579,   580,   581,   582,
     583,   587,   591,   595,   599,   603,   607,   611,   615,   619,
     623,   627,   631,   637,   638,   639,   644,   645,   649,   653,
     659,   660,   665,   671,   672,   673,   674,   687,   688,   693,
     694,   695,   700,   701,   702,   707,   708,   713,   714,   719,
     720,   721,   725,   729,   733,   738,   742,   747,   748,   753,
     754,   755,   756,   766,   776,   777,   778,   779,   780,   781,
     782,   783,   784,   788,   792,   793,   794,   801,   802,   803,
     804,   810,   811,   816,   817,   821,   826,   827,   832,   833,
     834,   839,   840,   845,   846,   851,   852,   853,   859,   860,
     861,   862,   863,   868,   877,   878,   879,   883,   884,   889,
     893,   894,   895,   900,   901,   902,   903,   908,   913,   914,
     918,   919,   928,   929,   930,   931,   932,   933,   938,   939,
     940,   944,   948,   952,   957,   958,   962,   962,   965,   966,
     971,   972,   977,   978,   987,   988,   992,   993,   997,  1002,
    1003,  1004,  1008,  1012,  1016,  1017,  1018,  1019,  1020,  1021,
    1022,  1023,  1024,  1025,  1026,  1027,  1032,  1033,  1034,  1035,
    1039,  1043,  1047,  1051,  1052,  1062,  1062,  1065,  1066,  1071,
    1072,  1077,  1078,  1084,  1093,  1094,  1104
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO", "BREAK", "CASE", "CHAR", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM", "EXTERN", "FLOAT",
  "FOR", "GOTO", "IF", "INLINE", "INT", "LONG", "REGISTER", "RESTRICT",
  "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH",
  "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE", "WHILE", "_BOOL",
  "_COMPLEX", "_IMAGINARY", "LEFT", "RIGHT", "ADDASS", "SUBASS", "MULASS",
  "DIVASS", "MODASS", "XORASS", "ANDASS", "ORASS", "LEFTASS", "RIGHTASS",
  "LTEQ", "GTEQ", "EQ", "NEQ", "AND", "OR", "INC", "DEC", "ARROW",
  "ELLIPSIS", "STRING", "CONSTANT", "USERTYPE", "IDENTIFIER", "'('", "')'",
  "'['", "']'", "'.'", "'{'", "'}'", "','", "'&'", "'*'", "'+'", "'-'",
  "'~'", "'!'", "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'",
  "'='", "';'", "$accept", "primary_expression", "postfix_expression",
  "array", "fnargs", "dot", "arrow", "inc", "dec", "unnamed_object",
  "argument_expression_list", "unary_expression", "sizeof",
  "unary_operator", "unary_and", "unary_mul", "unary_plus", "unary_minus",
  "unary_binary_not", "unary_logical_not", "cast_expression",
  "multiplicative_expression", "mul_expression", "div_expression",
  "mod_expression", "additive_expression", "add_expression",
  "sub_expression", "shift_expression", "shift_left_expression",
  "shift_right_expression", "relational_expression", "lt_expression",
  "gt_expression", "lteq_expression", "gteq_expression",
  "equality_expression", "eq_expression", "neq_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "direct_assignment",
  "mul_assignment", "div_assignment", "mod_assignment", "add_assignment",
  "sub_assignment", "left_shift_assignment", "right_shift_assignment",
  "and_assignment", "xor_assignment", "or_assignment", "expression",
  "comma_expression", "constant_expression", "enumeration_constant",
  "identifier", "identifier_usertype", "constant", "string", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "typedef", "extern", "static", "auto",
  "register", "type_specifier", "void", "char", "short", "int", "long",
  "float", "double", "signed", "unsigned", "_bool", "_complex",
  "_imaginary", "struct_or_union_specifier", "struct_or_union", "struct",
  "union", "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "enum_specifier", "enumerator_list", "enumerator",
  "type_qualifier", "const", "restrict", "volatile", "function_specifier",
  "inline", "declarator", "direct_declarator", "function_parenthesis",
  "declarator_square_bracket", "star", "declarator_parenthesis", "pointer",
  "type_qualifier_list", "parameter_type_list", "ellipsis",
  "parameter_list", "parameter_declaration", "identifier_list",
  "type_name", "abstract_declarator", "direct_abstract_declarator",
  "abstract_function_parenthesis", "abstract_declarator_square_bracket",
  "abstract_declarator_parenthesis", "typedef_name", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "statement", "labeled_statement", "label", "case", "default",
  "compound_statement", "block_item_list", "$@1", "in_block_item_list",
  "block_item", "expression_statement", "selection_statement", "if",
  "switch", "iteration_statement", "while", "do", "for", "jump_statement",
  "goto", "continue", "break", "return", "translation_unit", "$@2",
  "in_translation_unit", "external_declaration", "function_definition",
  "declaration_list", "file", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,    40,    41,    91,    93,
      46,   123,   125,    44,    38,    42,    43,    45,   126,    33,
      47,    37,    60,    62,    94,   124,    63,    58,    61,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    91,    91,    91,    92,    92,    92,    92,
      92,    92,    92,    92,    93,    94,    94,    95,    96,    97,
      98,    99,    99,   100,   100,   101,   101,   101,   101,   101,
     101,   102,   103,   103,   103,   103,   103,   103,   104,   105,
     106,   107,   108,   109,   110,   110,   111,   111,   111,   111,
     112,   113,   114,   115,   115,   115,   116,   117,   118,   118,
     118,   119,   120,   121,   121,   121,   121,   121,   122,   123,
     124,   125,   126,   126,   126,   127,   128,   129,   129,   130,
     130,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   147,   148,   149,   150,   151,   152,   152,
     153,   154,   155,   155,   156,   156,   156,   156,   156,   156,
     156,   156,   157,   157,   158,   158,   159,   159,   159,   159,
     159,   160,   161,   162,   163,   164,   165,   165,   165,   165,
     165,   165,   165,   165,   165,   165,   165,   165,   165,   165,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   178,   178,   179,   179,   180,   181,
     182,   182,   183,   184,   184,   184,   184,   185,   185,   186,
     186,   186,   187,   187,   187,   188,   188,   189,   189,   190,
     190,   190,   191,   192,   193,   194,   195,   196,   196,   197,
     197,   197,   197,   198,   199,   199,   199,   199,   199,   199,
     199,   199,   199,   200,   201,   201,   201,   202,   202,   202,
     202,   203,   203,   204,   204,   205,   206,   206,   207,   207,
     207,   208,   208,   209,   209,   210,   210,   210,   211,   211,
     211,   211,   211,   212,   213,   213,   213,   214,   214,   215,
     216,   216,   216,   217,   217,   217,   217,   218,   219,   219,
     220,   220,   221,   221,   221,   221,   221,   221,   222,   222,
     222,   223,   224,   225,   226,   226,   228,   227,   229,   229,
     230,   230,   231,   231,   232,   232,   233,   233,   234,   235,
     235,   235,   236,   237,   238,   238,   238,   238,   238,   238,
     238,   238,   238,   238,   238,   238,   239,   239,   239,   239,
     240,   241,   242,   243,   243,   245,   244,   246,   246,   247,
     247,   248,   248,   248,   249,   249,   250
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     2,     2,     2,
       2,     2,     2,     1,     3,     3,     2,     2,     2,     1,
       1,     6,     7,     1,     3,     1,     2,     2,     2,     2,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       3,     3,     3,     1,     1,     1,     3,     3,     1,     1,
       1,     3,     3,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     1,     1,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     2,     1,     2,     1,     2,     1,
       2,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     4,     2,     1,     1,     1,     1,
       1,     2,     3,     2,     1,     2,     1,     1,     3,     1,
       2,     3,     5,     4,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     2,     2,     3,     4,     5,     4,     5,     4,     3,
       3,     3,     2,     1,     3,     3,     2,     2,     1,     3,
       2,     1,     2,     1,     3,     1,     1,     3,     2,     2,
       1,     1,     3,     1,     2,     1,     2,     1,     1,     2,
       1,     2,     1,     3,     3,     3,     2,     3,     2,     1,
       1,     3,     4,     2,     1,     4,     3,     2,     1,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     1,     2,     1,     3,     2,     0,     2,     1,     2,
       1,     1,     2,     1,     1,     1,     5,     7,     5,     1,
       1,     1,     5,     7,     6,     7,     7,     8,     7,     8,
       8,     9,     6,     7,     7,     8,     1,     1,     1,     1,
       3,     2,     2,     3,     2,     0,     2,     1,     2,     1,
       1,     4,     3,     2,     1,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
     325,   336,     0,     0,   144,   162,   202,   167,     0,   142,
     166,   206,   164,   165,   145,   203,   163,   168,   143,   178,
     141,   179,   169,   161,   204,   170,   171,   172,   259,   117,
       0,   223,   209,   330,     0,   125,   136,   137,   138,   139,
     140,   127,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     0,   176,   177,   159,   129,
     199,   200,   201,   131,   205,     0,   208,   210,   228,     0,
     160,   326,   327,   329,     1,     0,   194,     0,   123,     0,
     132,   134,   124,   126,   119,   118,     0,   175,   128,   130,
     286,   333,     0,     0,   211,   212,   231,   230,   227,   207,
     328,   197,   116,     0,   195,     0,   213,     0,   122,     0,
     334,     0,   332,     0,   184,     0,   180,     0,   186,     0,
     285,     0,     0,   226,   241,   240,     0,   233,   236,     0,
      31,    19,    20,   121,   120,     0,   222,    38,    39,    40,
      41,    42,    43,     6,    25,     0,     0,    13,    44,     0,
       0,    32,    33,    34,    35,    36,    37,    46,    53,    47,
      48,    49,    58,    54,    55,    63,    59,    60,    72,    64,
      65,    66,    67,    77,    73,    74,    79,    81,    83,    85,
      87,    89,     0,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,     2,     3,     4,     0,     0,     0,
     232,   229,     0,   193,     0,     0,   133,   134,     0,    39,
     260,   135,   335,   331,   183,   174,   181,     0,     0,   187,
     189,   185,     0,   284,     0,     0,     0,   283,     0,     0,
       0,     0,     0,     0,     0,   293,   112,     0,   113,     2,
     290,   291,   272,     0,     0,     0,   273,   287,   288,   274,
     275,   294,   295,   276,   299,   300,   301,   277,   316,   317,
     318,   319,     0,     0,   238,   245,   239,   247,   248,   250,
     252,   224,     0,   225,     0,     0,   243,     0,     0,     0,
       0,     0,     7,     8,     9,    10,    11,    12,     0,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    29,    44,    28,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,     0,     0,   221,   219,
       0,     0,     0,   115,   198,   196,   192,     0,     0,   264,
       0,     0,     0,   268,   190,     0,   182,     0,   173,   322,
     282,   321,     0,     0,     0,     0,   324,     0,     0,     0,
       0,   292,     0,     0,     0,   289,   258,     0,     0,   256,
       0,     0,   246,     0,   249,   251,   235,   234,   237,   242,
       5,     0,   245,   244,     0,    18,    16,     0,    23,     0,
      17,     0,   105,   106,   102,   103,   104,   110,   109,   111,
     107,   108,   101,     0,    50,    51,    52,    56,    57,    61,
      62,    70,    71,    68,    69,    75,    76,    78,    80,    82,
      84,    86,     0,   216,     0,   214,     0,   218,     0,   271,
     261,     0,   263,   267,   269,   188,   191,     0,     0,     0,
       0,   320,     0,   323,     0,     0,   114,   278,   279,   280,
     257,   253,   254,   255,     0,    45,    15,     0,    14,     0,
      30,     0,   215,   217,   270,   262,   266,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    88,
     265,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     296,   298,   302,    21,     0,     0,   304,     0,     0,     0,
       0,     0,     0,   312,     0,     0,     0,     0,    22,   303,
     308,   306,     0,   305,     0,     0,     0,   314,   313,     0,
     297,   310,   309,   307,     0,   315,   311
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   143,   144,   282,   283,   284,   285,   145,   146,   147,
     387,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   236,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   237,   238,   334,
     101,   194,    87,   195,   196,    33,   111,    79,    80,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,   115,   116,   117,   218,   219,    58,   103,   104,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    94,
      68,    95,    69,    98,   367,   377,   127,   128,   129,   277,
     368,   267,   268,   269,   270,    70,   339,   340,   341,   342,
     343,   241,   242,   243,   244,   245,   246,   121,   122,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,     1,     2,    71,    72,    73,   113,
       3
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -414
static const yytype_int16 yypact[] =
{
    -414,  -414,  1058,    39,  -414,  -414,  -414,  -414,    -6,  -414,
    -414,  -414,  -414,  -414,  -414,  -414,  -414,  -414,  -414,  -414,
    -414,  -414,  -414,  -414,  -414,  -414,  -414,  -414,  -414,  -414,
      82,  -414,  -414,  -414,    -3,  1514,  -414,  -414,  -414,  -414,
    -414,  1514,  -414,  -414,  -414,  -414,  -414,  -414,  -414,  -414,
    -414,  -414,  -414,  -414,  -414,    62,  -414,  -414,  -414,  1514,
    -414,  -414,  -414,  1514,  -414,   -15,    64,  -414,    26,   138,
    -414,  1058,  -414,  -414,  -414,    52,    60,    78,  -414,   -21,
    -414,   738,  -414,  -414,  -414,  -414,  1548,    91,  -414,  -414,
      15,  -414,  1304,   481,  -414,  -414,  -414,  -414,    26,    64,
    -414,    86,  -414,   174,  -414,    52,  -414,    82,  -414,  1552,
    -414,    -3,  -414,  1180,  1548,  1220,  -414,    85,  1548,  1548,
    -414,   110,   584,  -414,  -414,   123,   133,   121,  -414,   -32,
    -414,  -414,  -414,  -414,  -414,   849,  -414,  -414,   158,  -414,
    -414,  -414,  -414,  -414,   127,  1774,  1774,  -414,    93,  1796,
    1818,  -414,  -414,  -414,  -414,  -414,  -414,  -414,   126,  -414,
    -414,  -414,   216,  -414,  -414,   210,  -414,  -414,    -7,  -414,
    -414,  -414,  -414,   253,  -414,  -414,   149,   146,   147,   186,
     -33,  -414,   185,  -414,  -414,  -414,  -414,  -414,  -414,  -414,
    -414,  -414,  -414,  -414,  -414,  -414,  -414,  1103,   202,  1078,
    -414,  -414,  1818,  -414,    52,   239,  -414,   206,  1530,  -414,
    -414,  -414,  -414,  -414,  -414,  -414,  -414,  1818,    -9,  -414,
     196,  -414,  1256,  -414,   201,  1818,   212,  -414,   774,   231,
      52,   238,   908,   252,   254,  -414,  -414,     4,  -414,   235,
    -414,  -414,  -414,   248,   250,   257,  -414,   584,  -414,  -414,
    -414,  -414,  -414,  -414,  -414,  -414,  -414,  -414,  -414,  -414,
    -414,  -414,   926,  1575,  -414,   234,  -414,   111,  -414,  -414,
    -414,  -414,  1477,  -414,    52,    22,   154,   258,   249,  1597,
    1818,   249,  -414,  -414,  -414,  -414,  -414,  -414,   849,  -414,
    -414,  1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,
    1818,  1818,   849,  -414,  -414,  -414,  1818,  1818,  1818,  1818,
    1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,  1818,
    1818,  1818,  1818,  1818,  1818,  -414,   262,  1103,  -414,  -414,
     272,  1818,   273,  -414,  -414,  -414,  -414,  1818,    52,  -414,
     244,  1552,   -30,  -414,  -414,    85,  -414,  1818,  -414,  -414,
    -414,  -414,   309,   661,   265,  1818,  -414,    18,  1818,  1818,
    1818,  -414,   774,   774,   774,  -414,  -414,   279,   280,  -414,
     282,   286,   111,  1359,  -414,  -414,  -414,  -414,  -414,  -414,
    -414,   992,   193,  -414,  1619,  -414,  -414,    79,  -414,    31,
    -414,   289,  -414,  -414,  -414,  -414,  -414,  -414,  -414,  -414,
    -414,  -414,  -414,   290,  -414,  -414,  -414,   126,   126,   216,
     216,   210,   210,   210,   210,    -7,    -7,   253,   149,   146,
     147,   186,   -13,  -414,   294,  -414,   295,  -414,   298,  -414,
    -414,   331,  -414,  -414,  -414,  -414,  -414,   302,  1356,    21,
    1378,  -414,   100,  -414,   103,   117,  -414,  -414,  -414,  -414,
    -414,  -414,  -414,  -414,  1530,  -414,  -414,  1818,  -414,   301,
     301,  1818,  -414,  -414,  -414,  -414,  -414,  1552,  1818,  1641,
      23,  1400,  1664,    29,   774,   774,   774,   255,  -414,  -414,
    -414,   152,   774,   164,  1686,  1708,    35,   774,   182,  1730,
     357,  -414,  -414,  -414,   975,   284,  -414,   774,   774,   195,
     774,   197,  1752,  -414,   774,   774,   208,   774,  -414,  -414,
    -414,  -414,   774,  -414,   774,   774,   209,  -414,  -414,   774,
    -414,  -414,  -414,  -414,   774,  -414,  -414
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -414,  -414,  -414,  -414,  -414,  -414,  -414,   232,   233,  -414,
    -414,   107,  -414,  -414,  -414,  -414,  -414,  -414,  -414,  -414,
    -143,    20,  -414,  -414,  -414,    27,  -414,  -414,   -29,  -414,
    -414,    16,  -414,  -414,  -414,  -414,    56,  -414,  -414,    58,
      61,    57,    68,  -414,  -181,   -83,  -414,  -414,  -414,  -414,
    -414,  -414,  -414,  -414,  -414,  -414,  -414,  -119,  -414,  -188,
    -414,    -2,  -196,  -414,  -414,   -79,     7,  -414,   274,  -414,
    -414,  -414,   -80,  -414,  -414,   -64,  -414,  -414,  -414,  -414,
    -414,  -414,  -414,  -414,  -414,  -414,  -414,  -414,  -414,  -414,
    -414,  -414,   266,  -101,  -110,  -414,    42,  -414,   287,   191,
     364,  -414,  -414,  -414,  -414,  -414,   -19,   -66,  -414,  -414,
     -88,  -414,   -41,   -63,   306,  -414,  -414,   128,  -414,  -205,
    -105,  -253,  -414,  -250,  -244,  -414,  -108,   -50,  -413,  -414,
      70,  -209,  -414,  -414,  -414,  -414,   -34,  -414,  -414,  -414,
     184,  -414,  -414,  -414,  -414,  -414,  -414,  -414,  -414,  -414,
    -414,  -414,  -414,  -414,  -414,  -414,  -414,   362,  -414,  -414,
    -414
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -282
static const yytype_int16 yytable[] =
{
      32,   211,   110,    99,   214,   198,    76,   305,   221,    34,
     182,    77,   372,   197,   216,    81,   275,   374,   467,   352,
     266,   333,   114,   375,   323,   276,   210,    97,    32,   344,
     199,    91,    32,     6,   212,   273,   333,   350,   337,    74,
     338,   274,    82,   240,   333,   313,   314,   112,    83,    15,
     114,   114,   107,   324,   114,   114,    90,   201,   433,    29,
     360,    24,    29,    30,   345,    75,    88,    32,   108,    32,
      89,   114,    31,   102,   461,   315,   316,   360,    34,   213,
     346,   467,   385,   391,   265,   390,    78,   120,   207,   380,
     124,   360,   207,   361,   360,   360,   360,   403,   220,   125,
     458,    31,   360,   102,   360,    32,   264,   443,   360,    32,
     471,   332,   484,   357,   326,    32,   330,    29,   489,   331,
     239,   216,   374,    32,   502,   210,    84,    85,   375,   372,
      92,   105,    93,    86,   327,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   106,   456,    29,    30,   428,
      29,    30,   457,   447,   448,   449,   333,    31,   114,   436,
      31,   389,   119,   404,   405,   406,   333,   474,   240,   275,
     475,   383,   217,   360,   202,   371,   360,   373,   276,   263,
     370,   301,   223,   275,   476,   131,   132,   278,    29,   262,
     360,   263,   276,   279,   272,   280,   388,   281,    31,    99,
     271,   306,   102,    29,    30,   422,   307,   308,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   495,
     381,   265,   263,   319,   114,   360,   239,  -223,   354,    31,
     320,   497,   321,   432,   439,   382,   442,   360,   114,   444,
     445,   455,   322,    77,   424,   239,   203,   204,   426,   504,
     311,   312,   289,   290,   325,   360,   303,   304,   210,   381,
      32,   263,   512,    32,   514,   490,   491,   492,   360,   125,
     360,   328,   379,   496,   440,   519,   524,   446,   503,   125,
     479,   360,   360,   347,   411,   412,   413,   414,   510,   511,
     349,   513,   309,   310,   109,   517,   518,   353,   520,    29,
     262,   351,   263,   521,   355,   522,   523,   317,   318,   304,
     525,   336,   204,    84,    85,   526,   430,   431,   358,   470,
     359,   473,  -281,   466,   304,   384,   220,   493,   494,   407,
     408,   423,   304,   415,   416,   362,   429,   363,   409,   410,
     382,   425,   427,    32,   364,   437,   450,   451,   210,   481,
     483,   452,   486,   488,   441,   453,   459,   460,   130,   480,
     239,   239,   239,   462,   463,   499,   501,   464,   468,   507,
     506,   210,   454,   509,   478,   417,   286,   287,   418,   420,
     125,   206,   419,   516,   210,   222,   466,   435,   125,   131,
     132,   421,   205,   133,   134,   335,    29,   135,   126,   337,
     378,   338,   208,   465,   477,   137,   209,   139,   140,   141,
     142,   210,   434,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     304,   365,    96,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   304,     0,     0,     0,     0,     0,
     118,     0,     0,     0,   304,     0,     0,    96,     0,     0,
       0,     0,   200,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   239,   239,   239,     0,     0,     0,   118,   118,
     239,     0,   118,   118,     0,   239,     0,     0,     6,     0,
       0,   304,     0,     0,     0,   239,   239,     0,   239,   118,
       0,     0,   239,   239,    15,   239,     0,     0,   130,    18,
     239,     0,   239,   239,     0,     0,    24,   239,     0,     0,
       0,     0,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
     132,     0,     0,   133,   134,     0,    29,   135,     0,     0,
     136,     0,     0,     0,     0,   137,   138,   139,   140,   141,
     142,    96,     0,   200,     0,     0,     0,     0,   304,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   118,     4,   224,   225,
       5,     6,   226,   227,   228,     7,     0,     8,     9,    10,
     229,   230,   231,    11,    12,    13,    14,    15,   232,    16,
      17,   130,    18,    19,   233,    20,    21,    22,    23,    24,
     234,    25,    26,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,   132,     0,     0,   133,   134,    28,    29,
     135,     0,   118,     0,     0,    90,     0,     0,   137,   209,
     139,   140,   141,   142,     4,     0,   118,     5,     6,     0,
       0,     0,     7,   235,     8,     9,    10,     0,     0,     0,
      11,    12,    13,    14,    15,     0,    16,    17,   130,    18,
      19,   200,    20,    21,    22,    23,    24,     0,    25,    26,
      27,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   131,
     132,     0,     0,   133,   134,    28,    29,   135,     0,     0,
       0,     0,     0,     0,     0,   137,   209,   139,   140,   141,
     142,     4,     0,     0,     5,     6,     0,     0,     0,     7,
     438,     8,     9,    10,     0,     0,     0,    11,    12,    13,
      14,    15,     0,    16,    17,     0,    18,    19,     0,    20,
      21,    22,    23,    24,     0,    25,    26,    27,   224,   225,
       0,     0,   226,   227,   228,     0,     0,     0,     0,     0,
     229,   230,   231,     0,     0,     0,     0,     0,   232,     0,
       0,   130,    28,     0,   233,     0,     0,     0,     0,    90,
     234,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,     0,     0,     0,
       0,     0,   131,   132,     0,     0,   133,   134,     0,    29,
     135,     0,     0,     0,     0,    90,     0,     0,   137,   209,
     139,   140,   141,   142,     0,     5,     6,     0,     0,     0,
       7,     0,     8,   235,    10,     0,     0,     0,     0,    12,
      13,     0,    15,     0,    16,    17,   130,     0,    19,     0,
       0,    21,    22,    23,    24,     0,    25,    26,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   131,   132,     0,
       0,   133,   134,    28,    29,   135,     0,     0,     0,     0,
       0,     0,     0,   137,   209,   139,   140,   141,   142,     4,
       0,     0,     5,     6,     0,   130,     0,     7,     0,     8,
       9,    10,     0,     0,     0,    11,    12,    13,    14,    15,
       0,    16,    17,     0,    18,    19,     0,    20,    21,    22,
      23,    24,     0,    25,    26,    27,   131,   132,     0,     0,
     133,   134,     0,    29,   135,     0,     0,     0,     0,     0,
       0,     0,   137,   209,   139,   140,   141,   142,     0,     0,
      28,    29,   262,   366,   263,     4,     0,   356,     5,     6,
       0,    31,   130,     7,     0,     8,     9,    10,     0,     0,
       0,    11,    12,    13,    14,    15,     0,    16,    17,     0,
      18,    19,     0,    20,    21,    22,    23,    24,     0,    25,
      26,    27,     0,   131,   132,     0,     0,   133,   134,     0,
      29,   135,     0,   337,     0,   338,   208,   508,     0,   137,
     209,   139,   140,   141,   142,     0,    28,     0,   381,   366,
     263,     4,     0,     0,     5,     6,     0,    31,     0,     7,
       0,     8,     9,    10,     0,     0,     0,    11,    12,    13,
      14,    15,     0,    16,    17,     6,    18,    19,     0,    20,
      21,    22,    23,    24,     0,    25,    26,    27,     0,     0,
       0,    15,     0,     0,     0,   130,    18,     0,     0,     0,
       6,     0,     0,    24,     0,     0,     0,     0,     0,     0,
       0,     0,    28,    29,    30,     0,    15,     0,     0,     0,
     130,     0,     0,    31,     0,     0,   131,   132,    24,     0,
     133,   134,     0,    29,   135,     0,     0,   329,     0,     0,
       0,     0,   137,   138,   139,   140,   141,   142,     0,     0,
       0,   131,   132,     0,     0,   133,   134,     0,    29,   135,
       0,     0,     0,     0,     0,     0,     0,   137,   209,   139,
     140,   141,   142,     4,     0,     0,     5,     6,     0,     0,
       0,     7,     0,     8,     9,    10,     0,     0,     0,    11,
      12,    13,    14,    15,     0,    16,    17,     0,    18,    19,
       0,    20,    21,    22,    23,    24,     0,    25,    26,    27,
       0,     0,     0,     0,     0,     0,     5,     6,     0,     0,
       0,     7,     0,     8,     0,    10,     0,     0,     0,     0,
      12,    13,     0,    15,    28,    16,    17,     0,     0,    19,
       0,    90,    21,    22,    23,    24,     0,    25,    26,    27,
       0,     0,     5,     6,     0,     0,     0,     7,     0,     8,
       0,    10,     0,     0,     0,     0,    12,    13,     0,    15,
       0,    16,    17,     0,    28,    19,     0,     0,    21,    22,
      23,    24,   215,    25,    26,    27,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     0,     0,
       5,     6,     0,     0,     0,     7,     0,     8,     9,    10,
      28,     0,     0,    11,    12,    13,    14,    15,   348,    16,
      17,     0,    18,    19,     0,    20,    21,    22,    23,    24,
       0,    25,    26,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     0,     0,     5,     6,     0,    28,    29,
       7,   123,     8,     9,    10,     0,     0,     0,    11,    12,
      13,    14,    15,   130,    16,    17,     0,    18,    19,     0,
      20,    21,    22,    23,    24,     0,    25,    26,    27,     0,
       0,     0,     0,     0,     0,   130,     0,     0,     0,     0,
       0,     0,     0,     0,   131,   132,     0,     0,   133,   134,
       0,    29,   135,    28,     0,     0,   366,   130,     0,     0,
     137,   209,   139,   140,   141,   142,   131,   132,     0,     0,
     133,   134,     0,    29,   135,   469,     0,     0,     0,     0,
       0,     0,   137,   209,   139,   140,   141,   142,   131,   132,
       0,     0,   133,   134,     0,    29,   135,   472,     0,     0,
       0,     0,     0,     0,   137,   209,   139,   140,   141,   142,
       4,     0,     0,     5,     6,     0,     0,     0,     7,   485,
       8,     9,    10,     0,     0,     0,    11,    12,    13,    14,
      15,     0,    16,    17,     0,    18,    19,     0,    20,    21,
      22,    23,    24,     0,    25,    26,    27,     4,     0,     0,
       5,     6,     0,     0,     0,     7,     0,     8,     9,    10,
       0,     0,     0,    11,    12,    13,    14,    15,   376,    16,
      17,    28,    18,    19,     0,    20,    21,    22,    23,    24,
       0,    25,    26,    27,     5,     6,     0,   130,     0,     7,
       0,     8,     0,    10,     0,     0,     0,     0,    12,    13,
       0,    15,     0,    16,    17,     0,     0,    19,    28,   130,
      21,    22,    23,    24,     0,    25,    26,    27,   131,   132,
       0,     0,   133,   134,     0,    29,   135,     0,   337,     0,
     338,   208,   130,     0,   137,   209,   139,   140,   141,   142,
     131,   132,    28,     0,   133,   134,     0,    29,   135,     0,
       0,     0,     0,   208,   130,     0,   137,   209,   139,   140,
     141,   142,     0,   131,   132,     0,     0,   133,   134,     0,
      29,   135,     0,     0,   369,     0,   130,     0,     0,   137,
     138,   139,   140,   141,   142,   131,   132,     0,     0,   133,
     134,     0,    29,   135,   386,     0,     0,     0,   130,     0,
       0,   137,   209,   139,   140,   141,   142,   131,   132,     0,
       0,   133,   134,     0,    29,   135,     0,     0,     0,     0,
     454,   130,     0,   137,   209,   139,   140,   141,   142,   131,
     132,     0,     0,   133,   134,     0,    29,   135,   482,     0,
       0,     0,     0,   130,     0,   137,   209,   139,   140,   141,
     142,     0,   131,   132,     0,     0,   133,   134,     0,    29,
     135,   487,     0,     0,     0,   130,     0,     0,   137,   209,
     139,   140,   141,   142,   131,   132,     0,     0,   133,   134,
       0,    29,   135,   498,     0,     0,     0,   130,     0,     0,
     137,   209,   139,   140,   141,   142,   131,   132,     0,     0,
     133,   134,     0,    29,   135,   500,     0,     0,     0,   130,
       0,     0,   137,   209,   139,   140,   141,   142,   131,   132,
       0,     0,   133,   134,     0,    29,   135,   505,     0,     0,
       0,   130,     0,     0,   137,   209,   139,   140,   141,   142,
     131,   132,     0,     0,   133,   134,     0,    29,   135,   515,
       0,     0,     0,   130,     0,     0,   137,   209,   139,   140,
     141,   142,   131,   132,     0,     0,   133,   134,     0,    29,
     288,     0,     0,     0,     0,   130,     0,     0,   137,   209,
     139,   140,   141,   142,   131,   132,     0,     0,   133,   134,
       0,    29,   302,     0,     0,     0,     0,     0,     0,     0,
     137,   209,   139,   140,   141,   142,   131,   132,     0,     0,
     133,   134,     0,    29,   135,     0,     0,     0,     0,     0,
       0,     0,   137,   209,   139,   140,   141,   142
};

static const yytype_int16 yycheck[] =
{
       2,   109,    81,    69,   114,    93,     8,   150,   118,     2,
      93,    30,   265,    93,   115,    34,   135,   267,   431,   228,
     125,   202,    86,   267,    57,   135,   109,    68,    30,   217,
      93,    65,    34,     7,   113,    67,   217,   225,    68,     0,
      70,    73,    35,   122,   225,    52,    53,    81,    41,    23,
     114,   115,    73,    86,   118,   119,    71,    98,    88,    65,
      73,    35,    65,    66,    73,    71,    59,    69,    89,    71,
      63,   135,    75,    75,    87,    82,    83,    73,    71,   113,
      89,   494,   278,   288,   125,   281,    89,    72,   107,    67,
      92,    73,   111,    89,    73,    73,    73,   302,   117,    92,
      69,    75,    73,   105,    73,   107,   125,    89,    73,   111,
      89,   199,    89,   232,   197,   117,   199,    65,    89,   199,
     122,   222,   372,   125,    89,   208,    64,    65,   372,   382,
      66,    71,    68,    71,   197,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    67,    67,    65,    66,   337,
      65,    66,    73,   362,   363,   364,   337,    75,   222,   347,
      75,   280,    71,   306,   307,   308,   347,    67,   247,   288,
      67,   276,    87,    73,    88,   263,    73,    66,   288,    68,
     263,    88,    72,   302,    67,    58,    59,    60,    65,    66,
      73,    68,   302,    66,    73,    68,   279,    70,    75,   265,
      67,    75,   204,    65,    66,   324,    80,    81,   291,   292,
     293,   294,   295,   296,   297,   298,   299,   300,   301,    67,
      66,   262,    68,    74,   288,    73,   228,    69,   230,    75,
      84,    67,    85,   341,   353,   276,   355,    73,   302,   358,
     359,   384,    56,   262,   327,   247,    72,    73,   331,    67,
      40,    41,   145,   146,    69,    73,   149,   150,   341,    66,
     262,    68,    67,   265,    67,   474,   475,   476,    73,   262,
      73,    69,   274,   482,   353,    67,    67,   360,   487,   272,
     461,    73,    73,    87,   313,   314,   315,   316,   497,   498,
      89,   500,    76,    77,    88,   504,   505,    66,   507,    65,
      66,    89,    68,   512,    66,   514,   515,    54,    55,   202,
     519,    72,    73,    64,    65,   524,    72,    73,    66,   438,
      66,   440,    87,   431,   217,    67,   345,    72,    73,   309,
     310,    69,   225,   317,   318,    87,   338,    87,   311,   312,
     381,    69,    69,   345,    87,    36,    67,    67,   431,   468,
     469,    69,   471,   472,    89,    69,    67,    67,    27,   467,
     362,   363,   364,    69,    69,   484,   485,    69,    66,    12,
     489,   454,    71,    89,   457,   319,   144,   144,   320,   322,
     373,   107,   321,   502,   467,   119,   494,   345,   381,    58,
      59,   323,   105,    62,    63,   204,    65,    66,    92,    68,
     272,    70,    71,    72,   454,    74,    75,    76,    77,    78,
      79,   494,   342,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   247,    68,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   337,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    -1,   347,    -1,    -1,    93,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   474,   475,   476,    -1,    -1,    -1,   114,   115,
     482,    -1,   118,   119,    -1,   487,    -1,    -1,     7,    -1,
      -1,   384,    -1,    -1,    -1,   497,   498,    -1,   500,   135,
      -1,    -1,   504,   505,    23,   507,    -1,    -1,    27,    28,
     512,    -1,   514,   515,    -1,    -1,    35,   519,    -1,    -1,
      -1,    -1,   524,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    -1,    -1,    62,    63,    -1,    65,    66,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,   197,    -1,   199,    -1,    -1,    -1,    -1,   461,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   222,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    -1,    -1,    62,    63,    64,    65,
      66,    -1,   288,    -1,    -1,    71,    -1,    -1,    74,    75,
      76,    77,    78,    79,     3,    -1,   302,     6,     7,    -1,
      -1,    -1,    11,    89,    13,    14,    15,    -1,    -1,    -1,
      19,    20,    21,    22,    23,    -1,    25,    26,    27,    28,
      29,   327,    31,    32,    33,    34,    35,    -1,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    -1,    -1,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,
      79,     3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,
      89,    13,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    -1,    25,    26,    -1,    28,    29,    -1,    31,
      32,    33,    34,    35,    -1,    37,    38,    39,     4,     5,
      -1,    -1,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      16,    17,    18,    -1,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    27,    64,    -1,    30,    -1,    -1,    -1,    -1,    71,
      36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,
      -1,    -1,    58,    59,    -1,    -1,    62,    63,    -1,    65,
      66,    -1,    -1,    -1,    -1,    71,    -1,    -1,    74,    75,
      76,    77,    78,    79,    -1,     6,     7,    -1,    -1,    -1,
      11,    -1,    13,    89,    15,    -1,    -1,    -1,    -1,    20,
      21,    -1,    23,    -1,    25,    26,    27,    -1,    29,    -1,
      -1,    32,    33,    34,    35,    -1,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,    59,    -1,
      -1,    62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    75,    76,    77,    78,    79,     3,
      -1,    -1,     6,     7,    -1,    27,    -1,    11,    -1,    13,
      14,    15,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      -1,    25,    26,    -1,    28,    29,    -1,    31,    32,    33,
      34,    35,    -1,    37,    38,    39,    58,    59,    -1,    -1,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,    -1,    -1,
      64,    65,    66,    67,    68,     3,    -1,    89,     6,     7,
      -1,    75,    27,    11,    -1,    13,    14,    15,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    -1,    25,    26,    -1,
      28,    29,    -1,    31,    32,    33,    34,    35,    -1,    37,
      38,    39,    -1,    58,    59,    -1,    -1,    62,    63,    -1,
      65,    66,    -1,    68,    -1,    70,    71,    72,    -1,    74,
      75,    76,    77,    78,    79,    -1,    64,    -1,    66,    67,
      68,     3,    -1,    -1,     6,     7,    -1,    75,    -1,    11,
      -1,    13,    14,    15,    -1,    -1,    -1,    19,    20,    21,
      22,    23,    -1,    25,    26,     7,    28,    29,    -1,    31,
      32,    33,    34,    35,    -1,    37,    38,    39,    -1,    -1,
      -1,    23,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,
       7,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    -1,    23,    -1,    -1,    -1,
      27,    -1,    -1,    75,    -1,    -1,    58,    59,    35,    -1,
      62,    63,    -1,    65,    66,    -1,    -1,    69,    -1,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,    -1,    -1,
      -1,    58,    59,    -1,    -1,    62,    63,    -1,    65,    66,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    74,    75,    76,
      77,    78,    79,     3,    -1,    -1,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    14,    15,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    -1,    25,    26,    -1,    28,    29,
      -1,    31,    32,    33,    34,    35,    -1,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,     6,     7,    -1,    -1,
      -1,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,    -1,
      20,    21,    -1,    23,    64,    25,    26,    -1,    -1,    29,
      -1,    71,    32,    33,    34,    35,    -1,    37,    38,    39,
      -1,    -1,     6,     7,    -1,    -1,    -1,    11,    -1,    13,
      -1,    15,    -1,    -1,    -1,    -1,    20,    21,    -1,    23,
      -1,    25,    26,    -1,    64,    29,    -1,    -1,    32,    33,
      34,    35,    72,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,
       6,     7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,
      64,    -1,    -1,    19,    20,    21,    22,    23,    72,    25,
      26,    -1,    28,    29,    -1,    31,    32,    33,    34,    35,
      -1,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,     6,     7,    -1,    64,    65,
      11,    67,    13,    14,    15,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    27,    25,    26,    -1,    28,    29,    -1,
      31,    32,    33,    34,    35,    -1,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    59,    -1,    -1,    62,    63,
      -1,    65,    66,    64,    -1,    -1,    67,    27,    -1,    -1,
      74,    75,    76,    77,    78,    79,    58,    59,    -1,    -1,
      62,    63,    -1,    65,    66,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79,    58,    59,
      -1,    -1,    62,    63,    -1,    65,    66,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    74,    75,    76,    77,    78,    79,
       3,    -1,    -1,     6,     7,    -1,    -1,    -1,    11,    89,
      13,    14,    15,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    -1,    25,    26,    -1,    28,    29,    -1,    31,    32,
      33,    34,    35,    -1,    37,    38,    39,     3,    -1,    -1,
       6,     7,    -1,    -1,    -1,    11,    -1,    13,    14,    15,
      -1,    -1,    -1,    19,    20,    21,    22,    23,    61,    25,
      26,    64,    28,    29,    -1,    31,    32,    33,    34,    35,
      -1,    37,    38,    39,     6,     7,    -1,    27,    -1,    11,
      -1,    13,    -1,    15,    -1,    -1,    -1,    -1,    20,    21,
      -1,    23,    -1,    25,    26,    -1,    -1,    29,    64,    27,
      32,    33,    34,    35,    -1,    37,    38,    39,    58,    59,
      -1,    -1,    62,    63,    -1,    65,    66,    -1,    68,    -1,
      70,    71,    27,    -1,    74,    75,    76,    77,    78,    79,
      58,    59,    64,    -1,    62,    63,    -1,    65,    66,    -1,
      -1,    -1,    -1,    71,    27,    -1,    74,    75,    76,    77,
      78,    79,    -1,    58,    59,    -1,    -1,    62,    63,    -1,
      65,    66,    -1,    -1,    69,    -1,    27,    -1,    -1,    74,
      75,    76,    77,    78,    79,    58,    59,    -1,    -1,    62,
      63,    -1,    65,    66,    67,    -1,    -1,    -1,    27,    -1,
      -1,    74,    75,    76,    77,    78,    79,    58,    59,    -1,
      -1,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    -1,
      71,    27,    -1,    74,    75,    76,    77,    78,    79,    58,
      59,    -1,    -1,    62,    63,    -1,    65,    66,    67,    -1,
      -1,    -1,    -1,    27,    -1,    74,    75,    76,    77,    78,
      79,    -1,    58,    59,    -1,    -1,    62,    63,    -1,    65,
      66,    67,    -1,    -1,    -1,    27,    -1,    -1,    74,    75,
      76,    77,    78,    79,    58,    59,    -1,    -1,    62,    63,
      -1,    65,    66,    67,    -1,    -1,    -1,    27,    -1,    -1,
      74,    75,    76,    77,    78,    79,    58,    59,    -1,    -1,
      62,    63,    -1,    65,    66,    67,    -1,    -1,    -1,    27,
      -1,    -1,    74,    75,    76,    77,    78,    79,    58,    59,
      -1,    -1,    62,    63,    -1,    65,    66,    67,    -1,    -1,
      -1,    27,    -1,    -1,    74,    75,    76,    77,    78,    79,
      58,    59,    -1,    -1,    62,    63,    -1,    65,    66,    67,
      -1,    -1,    -1,    27,    -1,    -1,    74,    75,    76,    77,
      78,    79,    58,    59,    -1,    -1,    62,    63,    -1,    65,
      66,    -1,    -1,    -1,    -1,    27,    -1,    -1,    74,    75,
      76,    77,    78,    79,    58,    59,    -1,    -1,    62,    63,
      -1,    65,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      74,    75,    76,    77,    78,    79,    58,    59,    -1,    -1,
      62,    63,    -1,    65,    66,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    75,    76,    77,    78,    79
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   244,   245,   250,     3,     6,     7,    11,    13,    14,
      15,    19,    20,    21,    22,    23,    25,    26,    28,    29,
      31,    32,    33,    34,    35,    37,    38,    39,    64,    65,
      66,    75,   151,   155,   156,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   187,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   200,   202,
     215,   246,   247,   248,     0,    71,   151,   196,    89,   157,
     158,   196,   156,   156,    64,    65,    71,   152,   156,   156,
      71,   226,    66,    68,   199,   201,   190,   202,   203,   197,
     247,   150,   151,   188,   189,    71,    67,    73,    89,    88,
     155,   156,   226,   249,   165,   182,   183,   184,   190,    71,
      72,   227,   228,    67,   151,   156,   204,   206,   207,   208,
      27,    58,    59,    62,    63,    66,    69,    74,    75,    76,
      77,    78,    79,    91,    92,    97,    98,    99,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   151,   153,   154,   162,   200,   203,
     190,   202,    88,    72,    73,   188,   158,   196,    71,    75,
     135,   216,   155,   226,   184,    72,   183,    87,   185,   186,
     196,   184,   182,    72,     4,     5,     8,     9,    10,    16,
      17,    18,    24,    30,    36,    89,   135,   147,   148,   151,
     155,   221,   222,   223,   224,   225,   226,   229,   230,   231,
     232,   233,   234,   235,   236,   237,   238,   239,   240,   241,
     242,   243,    66,    68,   196,   202,   210,   211,   212,   213,
     214,    67,    73,    67,    73,   147,   184,   209,    60,    66,
      68,    70,    93,    94,    95,    96,    97,    98,    66,   101,
     101,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    88,    66,   101,   101,   110,    75,    80,    81,    76,
      77,    40,    41,    52,    53,    82,    83,    54,    55,    74,
      84,    85,    56,    57,    86,    69,   135,   203,    69,    69,
     135,   162,   200,   134,   149,   189,    72,    68,    70,   216,
     217,   218,   219,   220,   149,    73,    89,    87,    72,    89,
     149,    89,   221,    66,   151,    66,    89,   147,    66,    66,
      73,    89,    87,    87,    87,   230,    67,   204,   210,    69,
     135,   200,   211,    66,   213,   214,    61,   205,   207,   151,
      67,    66,   202,   210,    67,   152,    67,   100,   135,   147,
     152,   209,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   135,   135,   209,   110,   110,   110,   111,   111,   115,
     115,   118,   118,   118,   118,   121,   121,   126,   129,   130,
     131,   132,   147,    69,   135,    69,   135,    69,   149,   151,
      72,    73,   216,    88,   220,   186,   149,    36,    89,   147,
     155,    89,   147,    89,   147,   147,   135,   221,   221,   221,
      67,    67,    69,    69,    71,   110,    67,    73,    69,    67,
      67,    87,    69,    69,    69,    72,   216,   218,    66,    89,
     147,    89,    89,   147,    67,    67,    67,   217,   135,   134,
     216,   147,    67,   147,    89,    89,   147,    67,   147,    89,
     221,   221,   221,    72,    73,    67,   221,    67,    67,   147,
      67,   147,    89,   221,    67,    67,   147,    12,    72,    89,
     221,   221,    67,   221,    67,    67,   147,   221,   221,    67,
     221,   221,   221,   221,    67,   221,   221
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

/* User initialization code.  */

/* Line 1242 of yacc.c  */
#line 119 "c_gram.y"
{
  c_yylloc.first_line = 0;
  c_yylloc.first_column = 0;
  c_yylloc.last_line = 0;
  c_yylloc.last_column = 0;
  enable_c_notd = 1;
  c_scan_init();
}

/* Line 1242 of yacc.c  */
#line 2144 "c_gram.tab.c"

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 145 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 146 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 147 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 148 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (3)]),(yylsp[(2) - (3)])); ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 154 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 155 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 156 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 157 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 158 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 159 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 160 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 161 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 165 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (3)]),(yylsp[(2) - (3)])); ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 169 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (3)]),(yylsp[(2) - (3)])); ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 170 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 174 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (2)]),(yylsp[(2) - (2)])); ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 178 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (2)]),(yylsp[(2) - (2)])); ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 182 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 186 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 190 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (6)]),(yylsp[(1) - (6)]),(yyvsp[(2) - (6)]),(yylsp[(2) - (6)])); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 191 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (7)]),(yylsp[(1) - (7)]),(yyvsp[(2) - (7)]),(yylsp[(2) - (7)])); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 196 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 197 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 202 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 203 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (2)]),(yylsp[(1) - (2)]),(yyvsp[(2) - (2)]),(yylsp[(2) - (2)])); ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 204 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (2)]),(yylsp[(1) - (2)]),(yyvsp[(2) - (2)]),(yylsp[(2) - (2)])); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 205 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (2)]),(yylsp[(1) - (2)]),(yyvsp[(2) - (2)]),(yylsp[(2) - (2)])); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 206 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (2)]),(yylsp[(1) - (2)]),(yyvsp[(2) - (2)]),(yylsp[(2) - (2)])); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 207 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (4)]),(yylsp[(1) - (4)]),(yyvsp[(3) - (4)]),(yylsp[(3) - (4)])); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 211 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 227 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 228 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 229 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 230 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 231 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 232 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 235 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 239 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 243 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 247 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 251 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 255 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 260 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 261 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(2) - (4)]),(yylsp[(2) - (4)]),(yyvsp[(4) - (4)]),(yylsp[(4) - (4)])); ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 276 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 277 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 278 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 279 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 283 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 287 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 291 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 296 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 297 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 298 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 302 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 306 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 312 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 313 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 314 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 318 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 322 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 327 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 328 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 329 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 330 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 331 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 336 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 340 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 344 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 348 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 354 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 355 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 356 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 360 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 364 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 370 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 371 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 376 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 377 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 382 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 383 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 388 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 389 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 394 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 395 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 400 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 401 "c_gram.y"
    { (yyval) = T3((yyloc),(yyvsp[(1) - (5)]),(yylsp[(1) - (5)]),(yyvsp[(3) - (5)]),(yylsp[(3) - (5)]),(yyvsp[(5) - (5)]),(yylsp[(5) - (5)])); ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 406 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 407 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 408 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 409 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 410 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 411 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 412 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 413 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 414 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 415 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 416 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 417 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 421 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 424 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 428 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 432 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 436 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 440 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 444 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 448 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 452 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 456 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 460 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 465 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 466 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 470 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 476 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 480 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 484 "c_gram.y"
    { (yyval) = T1((yyloc),LEAF((yyloc)),(yyloc)); ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 488 "c_gram.y"
    { (yyval) = T1((yyloc),LEAF((yyloc)),(yyloc)); ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 489 "c_gram.y"
    { (yyval) = T1((yyloc),LEAF((yyloc)),(yyloc)); ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 493 "c_gram.y"
    { (yyval) = T1((yyloc),LEAF((yyloc)),(yyloc)); ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 497 "c_gram.y"
    { (yyval) = T1((yyloc),LEAF((yyloc)),(yyloc)); ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 507 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yylsp[(2) - (3)])); enable_c_notd = 0; ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 508 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (2)]),(yylsp[(1) - (2)])); enable_c_notd = 0; ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 515 "c_gram.y"
    { (yyval) = RLIST((yyvsp[(2) - (2)]),(yyvsp[(1) - (2)])); ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 516 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 517 "c_gram.y"
    { (yyval) = RLIST((yyvsp[(2) - (2)]),(yyvsp[(1) - (2)])); ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 518 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 519 "c_gram.y"
    { (yyval) = RLIST((yyvsp[(2) - (2)]),(yyvsp[(1) - (2)])); ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 520 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 521 "c_gram.y"
    { (yyval) = RLIST((yyvsp[(2) - (2)]),(yyvsp[(1) - (2)])); ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 522 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 527 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 528 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 533 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 534 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 539 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); enable_c_notd = 1; ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 540 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 541 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 542 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 543 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 547 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 551 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 555 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 559 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 563 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 569 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); if ( enable_c_notd ) c_tn_disable(); ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 570 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); if ( enable_c_notd ) c_tn_disable(); ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 571 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); if ( enable_c_notd ) c_tn_disable(); ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 572 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); if ( enable_c_notd ) c_tn_disable(); ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 573 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); if ( enable_c_notd ) c_tn_disable(); ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 574 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); if ( enable_c_notd ) c_tn_disable(); ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 575 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); if ( enable_c_notd ) c_tn_disable(); ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 576 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); if ( enable_c_notd ) c_tn_disable(); ;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 577 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); if ( enable_c_notd ) c_tn_disable(); ;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 578 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); if ( enable_c_notd ) c_tn_disable(); ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 579 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); if ( enable_c_notd ) c_tn_disable(); ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 580 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); if ( enable_c_notd ) c_tn_disable(); ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 581 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); if ( enable_c_notd ) c_tn_disable(); ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 582 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); if ( enable_c_notd ) c_tn_disable(); ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 583 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); if ( enable_c_notd ) c_tn_disable(); ;}
    break;

  case 161:

/* Line 1455 of yacc.c  */
#line 587 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 162:

/* Line 1455 of yacc.c  */
#line 591 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 595 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 599 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 603 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 607 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 611 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 615 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 619 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 623 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 627 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 631 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 637 "c_gram.y"
    { (yyval) = T3((yyloc),(yyvsp[(1) - (5)]),(yylsp[(1) - (5)]),(yyvsp[(2) - (5)]),(yylsp[(2) - (5)]),(yyvsp[(4) - (5)]),(yylsp[(4) - (5)])); ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 638 "c_gram.y"
    { (yyval) = T3((yyloc),(yyvsp[(1) - (4)]),(yylsp[(1) - (4)]),NIL((yyloc)),(yyloc),(yyvsp[(3) - (4)]),(yylsp[(3) - (4)])); ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 639 "c_gram.y"
    { (yyval) = T3((yyloc),(yyvsp[(1) - (2)]),(yylsp[(1) - (2)]),(yyvsp[(2) - (2)]),(yylsp[(2) - (2)]),NIL((yyloc)),(yyloc)); ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 644 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 645 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 649 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 653 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 659 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 660 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 665 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yylsp[(2) - (3)])); ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 671 "c_gram.y"
    { (yyval) = RLIST((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)])); ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 672 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 673 "c_gram.y"
    { (yyval) = RLIST((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)])); ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 674 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 687 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 688 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 693 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 694 "c_gram.y"
    { (yyval) = T2((yyloc),NIL((yyloc)),(yyloc), (yyvsp[(2) - (2)]),(yylsp[(2) - (2)])); ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 695 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 700 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(2) - (5)]),(yylsp[(2) - (5)]),(yyvsp[(4) - (5)]),(yylsp[(4) - (5)])); ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 701 "c_gram.y"
    { (yyval) = T2((yyloc),NIL((yyloc)),(yyloc), (yyvsp[(3) - (4)]),(yylsp[(3) - (4)])); ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 702 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(2) - (2)]),(yylsp[(2) - (2)]), NIL((yyloc)),(yyloc)); ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 707 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 708 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 713 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 714 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 199:

/* Line 1455 of yacc.c  */
#line 719 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 200:

/* Line 1455 of yacc.c  */
#line 720 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 201:

/* Line 1455 of yacc.c  */
#line 721 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 202:

/* Line 1455 of yacc.c  */
#line 725 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 729 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 733 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 205:

/* Line 1455 of yacc.c  */
#line 738 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 206:

/* Line 1455 of yacc.c  */
#line 742 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 747 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (2)]),(yylsp[(1) - (2)]),(yyvsp[(2) - (2)]),(yylsp[(2) - (2)])); ;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 748 "c_gram.y"
    { (yyval) = T2((yyloc),NIL((yyloc)),(yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 753 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 754 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 755 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 756 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 766 "c_gram.y"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 776 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(2) - (4)]),(yylsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yylsp[(3) - (4)])); ;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 777 "c_gram.y"
    { (yyval) = T3((yyloc),(yyvsp[(3) - (5)]),(yylsp[(3) - (5)]),(yyvsp[(4) - (5)]),(yylsp[(4) - (5)]),(yyvsp[(2) - (5)]),(yylsp[(2) - (5)])); ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 778 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(3) - (4)]),(yylsp[(3) - (4)]),(yyvsp[(2) - (4)]),(yylsp[(2) - (4)])); ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 779 "c_gram.y"
    { (yyval) = T3((yyloc),(yyvsp[(2) - (5)]),(yylsp[(2) - (5)]),(yyvsp[(4) - (5)]),(yylsp[(4) - (5)]),(yyvsp[(3) - (5)]),(yylsp[(3) - (5)])); ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 780 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (4)]),(yylsp[(2) - (4)])); ;}
    break;

  case 219:

/* Line 1455 of yacc.c  */
#line 781 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (3)]),(yylsp[(2) - (3)])); ;}
    break;

  case 220:

/* Line 1455 of yacc.c  */
#line 782 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (3)]),(yylsp[(2) - (3)])); ;}
    break;

  case 221:

/* Line 1455 of yacc.c  */
#line 783 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 222:

/* Line 1455 of yacc.c  */
#line 784 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 788 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 792 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (3)]),(yylsp[(2) - (3)])); ;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 793 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (3)]),(yylsp[(2) - (3)])); ;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 794 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 801 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (2)]),(yylsp[(1) - (2)]),(yyvsp[(2) - (2)]),(yylsp[(2) - (2)])); ;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 802 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 803 "c_gram.y"
    { (yyval) = RLIST(RLIST((yyvsp[(3) - (3)]), (yyvsp[(2) - (3)])), (yyvsp[(1) - (3)])); ;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 804 "c_gram.y"
    { (yyval) = RLIST((yyvsp[(2) - (2)]), (yyvsp[(1) - (2)])); ;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 810 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 811 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 816 "c_gram.y"
    { (yyval) = (yyvsp[(1) - (1)]); ;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 817 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 821 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 826 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 827 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 832 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (2)]),(yylsp[(1) - (2)]),(yyvsp[(2) - (2)]),(yylsp[(2) - (2)])); ;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 833 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (2)]),(yylsp[(1) - (2)]),(yyvsp[(2) - (2)]),(yylsp[(2) - (2)])); ;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 834 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 839 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 840 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (3)]), (yyvsp[(2) - (3)])); ;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 845 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 846 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (2)]),(yylsp[(1) - (2)]),(yyvsp[(2) - (2)]),(yylsp[(2) - (2)])); ;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 851 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)]), NIL((yyloc)),(yyloc)); ;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 852 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (2)]),(yylsp[(1) - (2)]),(yyvsp[(2) - (2)]),(yylsp[(2) - (2)])); ;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 853 "c_gram.y"
    { (yyval) = T2((yyloc),NIL((yyloc)),(yyloc), (yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 859 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 860 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 861 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 862 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 863 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 868 "c_gram.y"
    { (yyval) = (yyvsp[(2) - (3)]); ;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 877 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (3)]),(yylsp[(2) - (3)])); ;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 878 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 879 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 883 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (3)]),(yylsp[(2) - (3)])); ;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 884 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 889 "c_gram.y"
    { (yyval) = T1((yyloc),LEAF((yyloc)),(yyloc)); ;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 893 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 894 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (3)]),(yylsp[(2) - (3)])); ;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 895 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (4)]),(yylsp[(2) - (4)])); ;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 900 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (2)]),(yylsp[(1) - (2)]),(yyvsp[(2) - (2)]),(yylsp[(2) - (2)])); ;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 901 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 902 "c_gram.y"
    { (yyval) = LIST(LIST((yyvsp[(1) - (4)]),(yyvsp[(3) - (4)])), (yyvsp[(4) - (4)])); ;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 903 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (3)]), (yyvsp[(3) - (3)])); ;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 908 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (2)]),(yylsp[(1) - (2)])); ;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 913 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 914 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)])); ;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 918 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (3)]),(yylsp[(2) - (3)])); ;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 919 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (2)]),(yylsp[(2) - (2)])); ;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 928 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 929 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 930 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 931 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 932 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 933 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 938 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 939 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 940 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 944 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 948 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (2)]),(yylsp[(1) - (2)])); ;}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 952 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 957 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (3)]),(yylsp[(2) - (3)])); ;}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 958 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 962 "c_gram.y"
    { PUSH("block_item_list"); ;}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 962 "c_gram.y"
    { (yyval) = POP((yyloc)); ;}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 965 "c_gram.y"
    { (yyval) = LIST(LAST(), (yyvsp[(1) - (1)])); ;}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 966 "c_gram.y"
    { (yyval) = LIST(LAST(), (yyvsp[(2) - (2)])); ;}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 971 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 972 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 977 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (2)]),(yylsp[(1) - (2)])); ;}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 978 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 987 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 988 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 992 "c_gram.y"
    { (yyval) = T3((yyloc),(yyvsp[(3) - (5)]),(yylsp[(3) - (5)]),(yyvsp[(5) - (5)]),(yylsp[(5) - (5)]),NIL((yyloc)),(yyloc)); ;}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 993 "c_gram.y"
    { (yyval) = T3((yyloc),(yyvsp[(3) - (7)]),(yylsp[(3) - (7)]),(yyvsp[(5) - (7)]),(yylsp[(5) - (7)]),(yyvsp[(7) - (7)]),(yylsp[(7) - (7)])); ;}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 997 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(3) - (5)]),(yylsp[(3) - (5)]),(yyvsp[(5) - (5)]),(yylsp[(5) - (5)])); ;}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 1002 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 1003 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 1004 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 1008 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(3) - (5)]),(yylsp[(3) - (5)]),(yyvsp[(5) - (5)]),(yylsp[(5) - (5)])); ;}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 1012 "c_gram.y"
    { (yyval) = T2((yyloc),(yyvsp[(5) - (7)]),(yylsp[(5) - (7)]),(yyvsp[(2) - (7)]),(yylsp[(2) - (7)])); ;}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 1016 "c_gram.y"
    { (yyval) = T4((yyloc),NIL((yyloc)),(yyloc), NIL((yyloc)),(yyloc), NIL((yyloc)),(yyloc), (yyvsp[(6) - (6)]),(yylsp[(6) - (6)])); ;}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 1017 "c_gram.y"
    { (yyval) = T4((yyloc),(yyvsp[(3) - (7)]),(yylsp[(3) - (7)]), NIL((yyloc)),(yyloc), NIL((yyloc)),(yyloc), (yyvsp[(7) - (7)]), (yylsp[(7) - (7)])); ;}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 1018 "c_gram.y"
    { (yyval) = T4((yyloc),NIL((yyloc)),(yyloc), (yyvsp[(4) - (7)]),(yylsp[(4) - (7)]), NIL((yyloc)),(yyloc), (yyvsp[(7) - (7)]),(yylsp[(7) - (7)])); ;}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 1019 "c_gram.y"
    { (yyval) = T4((yyloc),(yyvsp[(3) - (8)]),(yylsp[(3) - (8)]), (yyvsp[(5) - (8)]),(yylsp[(5) - (8)]), NIL((yyloc)),(yyloc), (yyvsp[(8) - (8)]),(yylsp[(8) - (8)])); ;}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 1020 "c_gram.y"
    { (yyval) = T4((yyloc),NIL((yyloc)),(yyloc), NIL((yyloc)),(yyloc), (yyvsp[(5) - (7)]),(yylsp[(5) - (7)]), (yyvsp[(7) - (7)]),(yylsp[(7) - (7)])); ;}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 1021 "c_gram.y"
    { (yyval) = T4((yyloc),(yyvsp[(3) - (8)]),(yylsp[(3) - (8)]), NIL((yyloc)),(yyloc), (yyvsp[(6) - (8)]),(yylsp[(6) - (8)]), (yyvsp[(8) - (8)]),(yylsp[(8) - (8)])); ;}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 1022 "c_gram.y"
    { (yyval) = T4((yyloc),NIL((yyloc)),(yyloc), (yyvsp[(4) - (8)]),(yylsp[(4) - (8)]), (yyvsp[(6) - (8)]),(yylsp[(6) - (8)]), (yyvsp[(8) - (8)]),(yylsp[(8) - (8)])); ;}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 1023 "c_gram.y"
    { (yyval) = T4((yyloc),(yyvsp[(3) - (9)]),(yylsp[(3) - (9)]),(yyvsp[(5) - (9)]),(yylsp[(5) - (9)]),(yyvsp[(7) - (9)]),(yylsp[(7) - (9)]),(yyvsp[(9) - (9)]),(yylsp[(9) - (9)])); ;}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 1024 "c_gram.y"
    { (yyval) = T4((yyloc),(yyvsp[(3) - (6)]),(yylsp[(3) - (6)]), NIL((yyloc)),(yyloc), NIL((yyloc)),(yyloc), (yyvsp[(6) - (6)]),(yylsp[(6) - (6)])); ;}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 1025 "c_gram.y"
    { (yyval) = T4((yyloc),(yyvsp[(3) - (7)]),(yylsp[(3) - (7)]), (yyvsp[(4) - (7)]),(yylsp[(4) - (7)]), NIL((yyloc)),(yyloc), (yyvsp[(7) - (7)]),(yylsp[(7) - (7)])); ;}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 1026 "c_gram.y"
    { (yyval) = T4((yyloc),(yyvsp[(3) - (7)]),(yylsp[(3) - (7)]), NIL((yyloc)),(yyloc), (yyvsp[(5) - (7)]),(yylsp[(5) - (7)]), (yyvsp[(7) - (7)]),(yylsp[(7) - (7)])); ;}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 1027 "c_gram.y"
    { (yyval) = T4((yyloc),(yyvsp[(3) - (8)]),(yylsp[(3) - (8)]),(yyvsp[(4) - (8)]),(yylsp[(4) - (8)]),(yyvsp[(6) - (8)]),(yylsp[(6) - (8)]),(yyvsp[(8) - (8)]),(yylsp[(8) - (8)])); ;}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 1032 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 317:

/* Line 1455 of yacc.c  */
#line 1033 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 318:

/* Line 1455 of yacc.c  */
#line 1034 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 319:

/* Line 1455 of yacc.c  */
#line 1035 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 320:

/* Line 1455 of yacc.c  */
#line 1039 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (3)]),(yylsp[(2) - (3)])); ;}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 1043 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 1047 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 1051 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(2) - (3)]),(yylsp[(2) - (3)])); ;}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 1052 "c_gram.y"
    { (yyval) = T0((yyloc)); ;}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 1062 "c_gram.y"
    { PUSH("translation_unit"); ;}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 1062 "c_gram.y"
    { (yyval) = POP((yyloc)); ;}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 1065 "c_gram.y"
    { (yyval) = LIST(LAST(), (yyvsp[(1) - (1)])); ;}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 1066 "c_gram.y"
    { (yyval) = LIST(LAST(), (yyvsp[(2) - (2)])); ;}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 1071 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 1072 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 1077 "c_gram.y"
    { (yyval) = T4((yyloc),(yyvsp[(1) - (4)]),(yylsp[(1) - (4)]),(yyvsp[(2) - (4)]),(yylsp[(2) - (4)]),(yyvsp[(3) - (4)]),(yylsp[(3) - (4)]),(yyvsp[(4) - (4)]),(yylsp[(4) - (4)])); ;}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 1078 "c_gram.y"
    { (yyval) = T4((yyloc),(yyvsp[(1) - (3)]),(yylsp[(1) - (3)]),(yyvsp[(2) - (3)]),(yylsp[(2) - (3)]),NIL((yyloc)),(yyloc),(yyvsp[(3) - (3)]),(yylsp[(3) - (3)])); ;}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 1084 "c_gram.y"
    { (yyval) = T4((yyloc),  NIL((yyloc)),(yyloc),   (yyvsp[(1) - (2)]),(yylsp[(1) - (2)]),  NIL((yyloc)),(yyloc),  (yyvsp[(2) - (2)]),(yylsp[(2) - (2)])); ;}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 1093 "c_gram.y"
    { (yyval) = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 1094 "c_gram.y"
    { (yyval) = LIST((yyvsp[(1) - (2)]),(yyvsp[(2) - (2)])); ;}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 1104 "c_gram.y"
    { c_result = T1((yyloc),(yyvsp[(1) - (1)]),(yylsp[(1) - (1)])); ;}
    break;



/* Line 1455 of yacc.c  */
#line 4676 "c_gram.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 1107 "c_gram.y"


void c_yyerror(const char *msg)
{
/*
  printf("%d.%d: %s\n", c_line, c_col, msg);
  */
}



