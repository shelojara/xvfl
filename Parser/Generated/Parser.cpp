/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VAR = 258,
     ASSIGN = 259,
     END = 260,
     RETURN = 261,
     IF = 262,
     ELSE = 263,
     PRINT = 264,
     VOID = 265,
     FOR = 266,
     TRUE = 267,
     FALSE = 268,
     PLUS = 269,
     MINUS = 270,
     MULT = 271,
     DIV = 272,
     EQ = 273,
     NEQ = 274,
     LESS = 275,
     GREATER = 276,
     LEQ = 277,
     GEQ = 278,
     MOD = 279,
     INTEGER = 280,
     FLOAT = 281,
     FUNCTION_NAME = 282,
     STRUCT_NAME = 283,
     IDENTIFIER = 284,
     STRING = 285
   };
#endif
/* Tokens.  */
#define VAR 258
#define ASSIGN 259
#define END 260
#define RETURN 261
#define IF 262
#define ELSE 263
#define PRINT 264
#define VOID 265
#define FOR 266
#define TRUE 267
#define FALSE 268
#define PLUS 269
#define MINUS 270
#define MULT 271
#define DIV 272
#define EQ 273
#define NEQ 274
#define LESS 275
#define GREATER 276
#define LEQ 277
#define GEQ 278
#define MOD 279
#define INTEGER 280
#define FLOAT 281
#define FUNCTION_NAME 282
#define STRUCT_NAME 283
#define IDENTIFIER 284
#define STRING 285




/* Copy the first part of user declarations.  */
#line 1 "Parser.y"

	#include <string>
	#include <vector>
	#include <memory>

    #include "../../AST/Program.hpp"
    #include "../../AST/StructAST.hpp"
    #include "../../TypeSystem/Types.hpp"

	size_t yyline = 1;

	extern int yylex();

	extern Program program;

	void yyerror(const char *str)
	{
        throw std::runtime_error(std::string(str) + " at line " + std::to_string(yyline));
	}


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 23 "Parser.y"
{
	ParameterList * parameterList;
	ExpressionList * expressionList;

	BlockAST * block;
	FunctionAST * function;
	StructAST * structDef;
	StatementAST * statement;
	ExpressionAST * expression;
	Type * type;

	std::string * string;
	int integer;
	int token;
	float floatNumber;
}
/* Line 193 of yacc.c.  */
#line 194 "Generated/Parser.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 207 "Generated/Parser.cpp"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   643

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNRULES -- Number of states.  */
#define YYNSTATES  150

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      33,    34,     2,     2,    37,     2,    31,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    36,
       2,     2,     2,     2,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    32,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    17,    26,    35,    46,
      47,    52,    55,    59,    60,    64,    68,    75,    80,    85,
      87,    92,    94,    98,    99,   102,   104,   106,   108,   110,
     112,   114,   116,   120,   122,   124,   126,   130,   132,   134,
     136,   138,   142,   146,   150,   154,   158,   162,   166,   170,
     174,   178,   182,   186,   190,   192,   194,   199,   206,   211,
     218,   223,   224,   228,   230,   233,   236,   242,   252,   255,
     265
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    -1,    43,    44,    -1,    43,    46,    -1,
      27,    33,    45,    34,    50,     5,    -1,    27,    33,    45,
      34,    35,    49,    50,     5,    -1,    27,    33,    29,    36,
      45,    34,    50,     5,    -1,    27,    33,    29,    36,    45,
      34,    35,    49,    50,     5,    -1,    -1,    45,    37,    49,
      29,    -1,    49,    29,    -1,    28,    47,     5,    -1,    -1,
      47,    29,    29,    -1,    47,    28,    29,    -1,     3,    29,
      35,    49,     4,    53,    -1,     3,    29,     4,    53,    -1,
       3,    29,    35,    49,    -1,    29,    -1,    29,    32,    53,
      38,    -1,    28,    -1,    29,    32,    38,    -1,    -1,    50,
      51,    -1,    52,    -1,    53,    -1,    58,    -1,    48,    -1,
      59,    -1,    60,    -1,    61,    -1,    53,     4,    53,    -1,
      54,    -1,    55,    -1,    56,    -1,    53,    31,    29,    -1,
      30,    -1,    29,    -1,    25,    -1,    26,    -1,    53,    14,
      53,    -1,    53,    16,    53,    -1,    53,    17,    53,    -1,
      53,    15,    53,    -1,    53,    18,    53,    -1,    53,    19,
      53,    -1,    53,    20,    53,    -1,    53,    21,    53,    -1,
      53,    22,    53,    -1,    53,    23,    53,    -1,    53,    24,
      53,    -1,    33,    53,    34,    -1,    32,    57,    38,    -1,
      12,    -1,    13,    -1,    27,    33,    57,    34,    -1,    27,
      33,    29,    36,    57,    34,    -1,    39,    33,    57,    34,
      -1,    39,    33,    29,    36,    57,    34,    -1,    53,    32,
      53,    38,    -1,    -1,    57,    37,    53,    -1,    53,    -1,
       6,    10,    -1,     6,    53,    -1,     7,    53,    40,    50,
      41,    -1,     7,    53,    40,    50,    41,     8,    40,    50,
      41,    -1,     9,    53,    -1,    11,    29,     4,    53,    37,
      53,    40,    50,    41,    -1,    11,    29,     4,    53,    37,
      53,    37,    53,    40,    50,    41,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    73,    77,    84,    88,    92,    96,   104,
     107,   111,   119,   127,   130,   134,   141,   145,   149,   156,
     160,   164,   168,   176,   179,   186,   187,   191,   192,   193,
     194,   195,   199,   206,   207,   208,   209,   213,   217,   221,
     225,   229,   233,   237,   241,   245,   249,   253,   257,   261,
     265,   269,   273,   277,   281,   285,   292,   296,   302,   306,
     313,   318,   321,   325,   333,   337,   344,   349,   357,   364,
     369
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "ASSIGN", "END", "RETURN", "IF",
  "ELSE", "PRINT", "VOID", "FOR", "TRUE", "FALSE", "PLUS", "MINUS", "MULT",
  "DIV", "EQ", "NEQ", "LESS", "GREATER", "LEQ", "GEQ", "MOD", "INTEGER",
  "FLOAT", "FUNCTION_NAME", "STRUCT_NAME", "IDENTIFIER", "STRING", "'.'",
  "'['", "'('", "')'", "':'", "';'", "','", "']'", "'@'", "'{'", "'}'",
  "$accept", "program", "function", "parameterList", "struct",
  "structMembers", "variableDeclaration", "typeName", "block", "statement",
  "assignment", "expression", "functionCall", "versionInv",
  "arraySelector", "expressionList", "return", "if", "print", "for", 0
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
     285,    46,    91,    40,    41,    58,    59,    44,    93,    64,
     123,   125
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    43,    44,    44,    44,    44,    45,
      45,    45,    46,    47,    47,    47,    48,    48,    48,    49,
      49,    49,    49,    50,    50,    51,    51,    51,    51,    51,
      51,    51,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    54,    54,    55,    55,
      56,    57,    57,    57,    58,    58,    59,    59,    60,    61,
      61
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     6,     8,     8,    10,     0,
       4,     2,     3,     0,     3,     3,     6,     4,     4,     1,
       4,     1,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     4,     6,     4,     6,
       4,     0,     3,     1,     2,     2,     5,     9,     2,     9,
      11
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    13,     3,     4,     9,     0,    21,
      19,     0,     0,    12,     0,     0,     0,     9,    23,     0,
      11,    15,    14,    54,    55,    39,    40,     0,    38,    37,
      61,     0,    22,     0,     0,    33,    34,    35,    19,     0,
       0,     0,     0,    61,    63,     0,     0,    61,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    23,    23,     0,     5,     0,     0,     0,     0,
      28,    24,    25,    26,    27,    29,    30,    31,    10,    38,
       0,     0,    53,    52,    38,     0,    41,    44,    42,    43,
      45,    46,    47,    48,    49,    50,    51,    36,     0,     0,
       0,     0,     0,    64,    65,     0,    68,     0,     0,    61,
      56,    62,    61,    58,    60,    23,     7,     6,     0,     0,
      23,     0,    32,     0,     0,     0,    17,    18,     0,     0,
      57,    59,     8,     0,    66,     0,    16,     0,     0,    23,
       0,    23,     0,     0,     0,    67,    23,    69,     0,    70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     5,    11,     6,     8,    70,    12,    41,    71,
      72,    73,    35,    36,    37,    45,    74,    75,    76,    77
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -60
static const yytype_int16 yypact[] =
{
     -60,    18,   -60,   -22,   -60,   -60,   -60,    -8,     0,   -60,
     -13,   -21,    -3,   -60,     1,    24,   341,    48,    14,    48,
     -60,   -60,   -60,   -60,   -60,   -60,   -60,    27,   -60,   -60,
     363,   363,   -60,    41,   492,   -60,   -60,   -60,    51,    20,
      48,   224,    55,   374,   587,    21,   566,   385,   363,   363,
     363,   363,   363,   363,   363,   363,   363,   363,   363,    56,
     363,   -60,    53,   -60,    57,   -60,   301,   363,   363,    60,
     -60,   -60,   -60,   328,   -60,   -60,   -60,   -60,   -60,    54,
      30,   363,   -60,   -60,    58,    32,    31,    31,    47,    47,
     600,   600,   611,   611,    -7,    -7,    47,   -60,   517,    48,
     235,   266,     8,   -60,   587,   438,   587,    87,   363,   363,
     -60,   587,   363,   -60,   -60,   -60,   -60,   -60,   363,    48,
     -60,   363,   587,    36,    38,   277,   587,    91,   100,   542,
     -60,   -60,   -60,   363,    89,   363,   587,    59,   411,   -60,
     363,   -60,   131,   465,   162,   -60,   -60,   -60,   193,   -60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -60,   -60,   -60,    81,   -60,   -60,   -60,   -18,   -59,   -60,
     -60,   -16,   -60,   -60,   -60,   -41,   -60,   -60,   -60,   -60
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      34,    42,    80,   100,   101,    13,    85,    48,    49,    50,
      51,     7,   118,    18,    44,    46,    19,    58,     2,    16,
       9,    10,    63,    17,    59,    60,    20,    44,    14,    15,
      21,    44,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,   119,    98,     3,     4,    50,    51,    40,
     104,   105,   106,    22,    62,    58,   125,    19,    81,    82,
      43,   128,    59,    60,   110,   111,   113,    81,   123,    81,
     130,   124,   131,    81,    47,    81,     9,    38,    59,    60,
     142,   115,   144,    16,    78,    97,   102,   148,    99,   107,
     109,   121,   122,    44,   112,   133,    44,   137,    39,   139,
       0,   127,   126,    64,     0,   129,    66,    67,     0,    68,
       0,    69,    23,    24,     0,     0,     0,   136,     0,   138,
       0,     0,     0,     0,   143,    25,    26,    27,     0,    28,
      29,     0,    30,    31,    64,     0,     0,    66,    67,    33,
      68,   134,    69,    23,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,    27,     0,
      28,    29,     0,    30,    31,    64,     0,     0,    66,    67,
      33,    68,   145,    69,    23,    24,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,    27,
       0,    28,    29,     0,    30,    31,    64,     0,     0,    66,
      67,    33,    68,   147,    69,    23,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    25,    26,
      27,     0,    28,    29,     0,    30,    31,    64,     0,    65,
      66,    67,    33,    68,   149,    69,    23,    24,    64,     0,
     116,    66,    67,     0,    68,     0,    69,    23,    24,    25,
      26,    27,     0,    28,    29,     0,    30,    31,     0,     0,
      25,    26,    27,    33,    28,    29,     0,    30,    31,    64,
       0,   117,    66,    67,    33,    68,     0,    69,    23,    24,
      64,     0,   132,    66,    67,     0,    68,     0,    69,    23,
      24,    25,    26,    27,     0,    28,    29,     0,    30,    31,
       0,     0,    25,    26,    27,    33,    28,    29,     0,    30,
      31,   103,     0,    23,    24,     0,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,    27,     0,
      28,    29,   108,    30,    31,     0,     0,     0,     0,     0,
      33,     0,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    23,    24,     0,     0,     0,     0,    59,
      60,     0,     0,     0,     0,     0,    25,    26,    27,     0,
      28,    29,     0,    30,    31,    23,    24,     0,     0,    32,
      33,     0,     0,     0,     0,     0,    23,    24,    25,    26,
      27,     0,    28,    29,     0,    30,    31,    23,    24,    25,
      26,    27,    33,    79,    29,     0,    30,    31,     0,     0,
      25,    26,    27,    33,    84,    29,     0,    30,    31,     0,
       0,     0,     0,     0,    33,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,     0,     0,     0,     0,
       0,     0,    59,    60,     0,     0,     0,     0,   140,     0,
       0,   141,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,     0,     0,     0,     0,     0,     0,    59,
      60,     0,     0,     0,     0,     0,     0,     0,   120,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
       0,     0,     0,     0,     0,     0,    59,    60,     0,     0,
       0,     0,     0,     0,     0,   146,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     0,     0,     0,
       0,     0,     0,    59,    60,     0,     0,     0,     0,     0,
      61,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,     0,     0,     0,     0,     0,     0,    59,    60,
       0,     0,     0,     0,     0,   114,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,     0,     0,     0,
       0,     0,     0,    59,    60,     0,     0,     0,     0,   135,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,     0,     0,     0,     0,     0,     0,    59,    60,     0,
      83,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,     0,     0,    48,    49,    50,    51,    59,    60,
      54,    55,    56,    57,    58,    48,    49,    50,    51,     0,
       0,    59,    60,    56,    57,    58,     0,     0,     0,     0,
       0,     0,    59,    60
};

static const yytype_int16 yycheck[] =
{
      16,    19,    43,    62,    63,     5,    47,    14,    15,    16,
      17,    33,     4,    34,    30,    31,    37,    24,     0,    32,
      28,    29,    40,    36,    31,    32,    29,    43,    28,    29,
      29,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    35,    60,    27,    28,    16,    17,    35,
      66,    67,    68,    29,    34,    24,   115,    37,    37,    38,
      33,   120,    31,    32,    34,    81,    34,    37,   109,    37,
      34,   112,    34,    37,    33,    37,    28,    29,    31,    32,
     139,    99,   141,    32,    29,    29,    29,   146,    35,    29,
      36,     4,   108,   109,    36,     4,   112,     8,    17,    40,
      -1,   119,   118,     3,    -1,   121,     6,     7,    -1,     9,
      -1,    11,    12,    13,    -1,    -1,    -1,   133,    -1,   135,
      -1,    -1,    -1,    -1,   140,    25,    26,    27,    -1,    29,
      30,    -1,    32,    33,     3,    -1,    -1,     6,     7,    39,
       9,    41,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,    -1,
      29,    30,    -1,    32,    33,     3,    -1,    -1,     6,     7,
      39,     9,    41,    11,    12,    13,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,
      -1,    29,    30,    -1,    32,    33,     3,    -1,    -1,     6,
       7,    39,     9,    41,    11,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    25,    26,
      27,    -1,    29,    30,    -1,    32,    33,     3,    -1,     5,
       6,     7,    39,     9,    41,    11,    12,    13,     3,    -1,
       5,     6,     7,    -1,     9,    -1,    11,    12,    13,    25,
      26,    27,    -1,    29,    30,    -1,    32,    33,    -1,    -1,
      25,    26,    27,    39,    29,    30,    -1,    32,    33,     3,
      -1,     5,     6,     7,    39,     9,    -1,    11,    12,    13,
       3,    -1,     5,     6,     7,    -1,     9,    -1,    11,    12,
      13,    25,    26,    27,    -1,    29,    30,    -1,    32,    33,
      -1,    -1,    25,    26,    27,    39,    29,    30,    -1,    32,
      33,    10,    -1,    12,    13,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,    -1,
      29,    30,     4,    32,    33,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    12,    13,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,    -1,
      29,    30,    -1,    32,    33,    12,    13,    -1,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    12,    13,    25,    26,
      27,    -1,    29,    30,    -1,    32,    33,    12,    13,    25,
      26,    27,    39,    29,    30,    -1,    32,    33,    -1,    -1,
      25,    26,    27,    39,    29,    30,    -1,    32,    33,    -1,
      -1,    -1,    -1,    -1,    39,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    37,    -1,
      -1,    40,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,
      38,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    38,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    -1,    -1,    -1,    -1,    37,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    -1,
      34,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    14,    15,    16,    17,    31,    32,
      20,    21,    22,    23,    24,    14,    15,    16,    17,    -1,
      -1,    31,    32,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    43,     0,    27,    28,    44,    46,    33,    47,    28,
      29,    45,    49,     5,    28,    29,    32,    36,    34,    37,
      29,    29,    29,    12,    13,    25,    26,    27,    29,    30,
      32,    33,    38,    39,    53,    54,    55,    56,    29,    45,
      35,    50,    49,    33,    53,    57,    53,    33,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    31,
      32,    38,    34,    49,     3,     5,     6,     7,     9,    11,
      48,    51,    52,    53,    58,    59,    60,    61,    29,    29,
      57,    37,    38,    34,    29,    57,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    29,    53,    35,
      50,    50,    29,    10,    53,    53,    53,    29,     4,    36,
      34,    53,    36,    34,    38,    49,     5,     5,     4,    35,
      40,     4,    53,    57,    57,    50,    53,    49,    50,    53,
      34,    34,     5,     4,    41,    37,    53,     8,    53,    40,
      37,    40,    50,    53,    50,    41,    40,    41,    50,    41
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 74 "Parser.y"
    {
		program.addFunction((yyvsp[(2) - (2)].function));
	;}
    break;

  case 4:
#line 78 "Parser.y"
    {
        program.addStruct((yyvsp[(2) - (2)].structDef));
    ;}
    break;

  case 5:
#line 85 "Parser.y"
    {
		(yyval.function) = new FunctionAST(*(yyvsp[(1) - (6)].string), *(yyvsp[(3) - (6)].parameterList), std::shared_ptr<BlockAST>((yyvsp[(5) - (6)].block)));
	;}
    break;

  case 6:
#line 89 "Parser.y"
    {
		(yyval.function) = new FunctionAST(*(yyvsp[(1) - (8)].string), *(yyvsp[(3) - (8)].parameterList), std::shared_ptr<BlockAST>((yyvsp[(7) - (8)].block)), "", std::shared_ptr<Type>((yyvsp[(6) - (8)].type)));
	;}
    break;

  case 7:
#line 93 "Parser.y"
    {
		(yyval.function) = new FunctionAST(*(yyvsp[(1) - (8)].string), *(yyvsp[(5) - (8)].parameterList), std::shared_ptr<BlockAST>((yyvsp[(7) - (8)].block)), *(yyvsp[(3) - (8)].string));
	;}
    break;

  case 8:
#line 97 "Parser.y"
    {
		(yyval.function) = new FunctionAST(*(yyvsp[(1) - (10)].string), *(yyvsp[(5) - (10)].parameterList), std::shared_ptr<BlockAST>((yyvsp[(9) - (10)].block)), *(yyvsp[(3) - (10)].string), std::shared_ptr<Type>((yyvsp[(8) - (10)].type)));
	;}
    break;

  case 9:
#line 104 "Parser.y"
    {
		(yyval.parameterList) = new ParameterList();
	;}
    break;

  case 10:
#line 108 "Parser.y"
    {
		(yyvsp[(1) - (4)].parameterList)->push_back(std::make_shared<ParameterAST>(*(yyvsp[(4) - (4)].string), std::shared_ptr<Type>((yyvsp[(3) - (4)].type))));
	;}
    break;

  case 11:
#line 112 "Parser.y"
    {
		(yyval.parameterList) = new ParameterList();
		(yyval.parameterList)->push_back(std::make_shared<ParameterAST>(*(yyvsp[(2) - (2)].string), std::shared_ptr<Type>((yyvsp[(1) - (2)].type))));
	;}
    break;

  case 12:
#line 120 "Parser.y"
    {
        (yyval.structDef) = new StructAST(*(yyvsp[(1) - (3)].string), *(yyvsp[(2) - (3)].parameterList));
    ;}
    break;

  case 13:
#line 127 "Parser.y"
    {
        (yyval.parameterList) = new std::vector<std::shared_ptr<ParameterAST>>();
    ;}
    break;

  case 14:
#line 131 "Parser.y"
    {
        (yyvsp[(1) - (3)].parameterList)->push_back(std::make_shared<ParameterAST>(*(yyvsp[(3) - (3)].string), std::make_shared<Type>(*(yyvsp[(2) - (3)].string))));
    ;}
    break;

  case 15:
#line 135 "Parser.y"
    {
        (yyvsp[(1) - (3)].parameterList)->push_back(std::make_shared<ParameterAST>(*(yyvsp[(3) - (3)].string), std::make_shared<StructType>(*(yyvsp[(2) - (3)].string))));
    ;}
    break;

  case 16:
#line 142 "Parser.y"
    {
		(yyval.statement) = new VarDeclAST(*(yyvsp[(2) - (6)].string), std::shared_ptr<Type>((yyvsp[(4) - (6)].type)), std::shared_ptr<ExpressionAST>((yyvsp[(6) - (6)].expression)));
	;}
    break;

  case 17:
#line 146 "Parser.y"
    {
		(yyval.statement) = new VarDeclAST(*(yyvsp[(2) - (4)].string), std::shared_ptr<Type>(nullptr), std::shared_ptr<ExpressionAST>((yyvsp[(4) - (4)].expression)));
	;}
    break;

  case 18:
#line 150 "Parser.y"
    {
		(yyval.statement) = new VarDeclAST(*(yyvsp[(2) - (4)].string), std::shared_ptr<Type>((yyvsp[(4) - (4)].type)));
	;}
    break;

  case 19:
#line 157 "Parser.y"
    {
		(yyval.type) = new Type(*(yyvsp[(1) - (1)].string));
	;}
    break;

  case 20:
#line 161 "Parser.y"
    {
		(yyval.type) = new ArrayType(*(yyvsp[(1) - (4)].string), std::shared_ptr<ExpressionAST>((yyvsp[(3) - (4)].expression)));
	;}
    break;

  case 21:
#line 165 "Parser.y"
    {
	    (yyval.type) = new StructType(*(yyvsp[(1) - (1)].string));
	;}
    break;

  case 22:
#line 169 "Parser.y"
    {
		(yyval.type) = new ArrayType(*(yyvsp[(1) - (3)].string));
	;}
    break;

  case 23:
#line 176 "Parser.y"
    {
		(yyval.block) = new BlockAST();
	;}
    break;

  case 24:
#line 180 "Parser.y"
    {
		(yyvsp[(1) - (2)].block)->addStatement(std::shared_ptr<StatementAST>((yyvsp[(2) - (2)].statement)));
	;}
    break;

  case 26:
#line 188 "Parser.y"
    {
		(yyval.statement) = new ExpressionStatementAST(std::shared_ptr<ExpressionAST>((yyvsp[(1) - (1)].expression)));
	;}
    break;

  case 32:
#line 200 "Parser.y"
    {
		(yyval.statement) = new AssignmentAST(std::shared_ptr<ExpressionAST>((yyvsp[(1) - (3)].expression)), std::shared_ptr<ExpressionAST>((yyvsp[(3) - (3)].expression)));
	;}
    break;

  case 36:
#line 210 "Parser.y"
    {
	    (yyval.expression) = new StructMemberAST(std::shared_ptr<ExpressionAST>((yyvsp[(1) - (3)].expression)), *(yyvsp[(3) - (3)].string));
	;}
    break;

  case 37:
#line 214 "Parser.y"
    {
		(yyval.expression) = new StringAST(*(yyvsp[(1) - (1)].string));
	;}
    break;

  case 38:
#line 218 "Parser.y"
    {
		(yyval.expression) = new IdentifierAST(*(yyvsp[(1) - (1)].string));
	;}
    break;

  case 39:
#line 222 "Parser.y"
    {
		(yyval.expression) = new IntegerAST((yyvsp[(1) - (1)].integer));
	;}
    break;

  case 40:
#line 226 "Parser.y"
    {
		(yyval.expression) = new FloatAST((yyvsp[(1) - (1)].floatNumber));
	;}
    break;

  case 41:
#line 230 "Parser.y"
    {
		(yyval.expression) = new BinaryOpAST(std::shared_ptr<ExpressionAST>((yyvsp[(1) - (3)].expression)), "+", std::shared_ptr<ExpressionAST>((yyvsp[(3) - (3)].expression)));
	;}
    break;

  case 42:
#line 234 "Parser.y"
    {
		(yyval.expression) = new BinaryOpAST(std::shared_ptr<ExpressionAST>((yyvsp[(1) - (3)].expression)), "*", std::shared_ptr<ExpressionAST>((yyvsp[(3) - (3)].expression)));
	;}
    break;

  case 43:
#line 238 "Parser.y"
    {
		(yyval.expression) = new BinaryOpAST(std::shared_ptr<ExpressionAST>((yyvsp[(1) - (3)].expression)), "/", std::shared_ptr<ExpressionAST>((yyvsp[(3) - (3)].expression)));
	;}
    break;

  case 44:
#line 242 "Parser.y"
    {
		(yyval.expression) = new BinaryOpAST(std::shared_ptr<ExpressionAST>((yyvsp[(1) - (3)].expression)), "-", std::shared_ptr<ExpressionAST>((yyvsp[(3) - (3)].expression)));
	;}
    break;

  case 45:
#line 246 "Parser.y"
    {
		(yyval.expression) = new BinaryOpAST(std::shared_ptr<ExpressionAST>((yyvsp[(1) - (3)].expression)), "==", std::shared_ptr<ExpressionAST>((yyvsp[(3) - (3)].expression)));
	;}
    break;

  case 46:
#line 250 "Parser.y"
    {
		(yyval.expression) = new BinaryOpAST(std::shared_ptr<ExpressionAST>((yyvsp[(1) - (3)].expression)), "!=", std::shared_ptr<ExpressionAST>((yyvsp[(3) - (3)].expression)));
	;}
    break;

  case 47:
#line 254 "Parser.y"
    {
		(yyval.expression) = new BinaryOpAST(std::shared_ptr<ExpressionAST>((yyvsp[(1) - (3)].expression)), "<", std::shared_ptr<ExpressionAST>((yyvsp[(3) - (3)].expression)));
	;}
    break;

  case 48:
#line 258 "Parser.y"
    {
		(yyval.expression) = new BinaryOpAST(std::shared_ptr<ExpressionAST>((yyvsp[(1) - (3)].expression)), ">", std::shared_ptr<ExpressionAST>((yyvsp[(3) - (3)].expression)));
	;}
    break;

  case 49:
#line 262 "Parser.y"
    {
		(yyval.expression) = new BinaryOpAST(std::shared_ptr<ExpressionAST>((yyvsp[(1) - (3)].expression)), "<=", std::shared_ptr<ExpressionAST>((yyvsp[(3) - (3)].expression)));
	;}
    break;

  case 50:
#line 266 "Parser.y"
    {
		(yyval.expression) = new BinaryOpAST(std::shared_ptr<ExpressionAST>((yyvsp[(1) - (3)].expression)), ">=", std::shared_ptr<ExpressionAST>((yyvsp[(3) - (3)].expression)));
	;}
    break;

  case 51:
#line 270 "Parser.y"
    {
		(yyval.expression) = new BinaryOpAST(std::shared_ptr<ExpressionAST>((yyvsp[(1) - (3)].expression)), "%", std::shared_ptr<ExpressionAST>((yyvsp[(3) - (3)].expression)));
	;}
    break;

  case 52:
#line 274 "Parser.y"
    {
		(yyval.expression) = (yyvsp[(2) - (3)].expression);
	;}
    break;

  case 53:
#line 278 "Parser.y"
    {
		(yyval.expression) = new ArrayAST(*(yyvsp[(2) - (3)].expressionList));
	;}
    break;

  case 54:
#line 282 "Parser.y"
    {
	    (yyval.expression) = new BoolAST(true);
	;}
    break;

  case 55:
#line 286 "Parser.y"
    {
	    (yyval.expression) = new BoolAST(false);
	;}
    break;

  case 56:
#line 293 "Parser.y"
    {
		(yyval.expression) = new FunctionCallAST(*(yyvsp[(1) - (4)].string), "", *(yyvsp[(3) - (4)].expressionList));
	;}
    break;

  case 57:
#line 297 "Parser.y"
    {
		(yyval.expression) = new FunctionCallAST(*(yyvsp[(1) - (6)].string), *(yyvsp[(3) - (6)].string), *(yyvsp[(5) - (6)].expressionList));
	;}
    break;

  case 58:
#line 303 "Parser.y"
    {
		(yyval.expression) = new VersionInvAST("", *(yyvsp[(3) - (4)].expressionList));
	;}
    break;

  case 59:
#line 307 "Parser.y"
    {
		(yyval.expression) = new VersionInvAST(*(yyvsp[(3) - (6)].string), *(yyvsp[(5) - (6)].expressionList));
	;}
    break;

  case 61:
#line 318 "Parser.y"
    {
		(yyval.expressionList) = new ExpressionList();
	;}
    break;

  case 62:
#line 322 "Parser.y"
    {
		(yyvsp[(1) - (3)].expressionList)->push_back(std::shared_ptr<ExpressionAST>((yyvsp[(3) - (3)].expression)));
	;}
    break;

  case 63:
#line 326 "Parser.y"
    {
		(yyval.expressionList) = new ExpressionList();
		(yyval.expressionList)->push_back(std::shared_ptr<ExpressionAST>((yyvsp[(1) - (1)].expression)));
	;}
    break;

  case 64:
#line 334 "Parser.y"
    {
		(yyval.statement) = new ReturnAST();
	;}
    break;

  case 65:
#line 338 "Parser.y"
    {
		(yyval.statement) = new ReturnAST(std::shared_ptr<ExpressionAST>((yyvsp[(2) - (2)].expression)));
	;}
    break;

  case 66:
#line 345 "Parser.y"
    {
		(yyval.statement) = new IfAST(std::shared_ptr<ExpressionAST>((yyvsp[(2) - (5)].expression)),
		        std::shared_ptr<BlockAST>((yyvsp[(4) - (5)].block)), std::shared_ptr<BlockAST>(nullptr));
	;}
    break;

  case 67:
#line 350 "Parser.y"
    {
		(yyval.statement) = new IfAST(std::shared_ptr<ExpressionAST>((yyvsp[(2) - (9)].expression)),
		        std::shared_ptr<BlockAST>((yyvsp[(4) - (9)].block)), std::shared_ptr<BlockAST>((yyvsp[(8) - (9)].block)));
	;}
    break;

  case 68:
#line 358 "Parser.y"
    {
		(yyval.statement) = new PrintAST(std::shared_ptr<ExpressionAST>((yyvsp[(2) - (2)].expression)));
	;}
    break;

  case 69:
#line 365 "Parser.y"
    {
		(yyval.statement) = new ForAST(*(yyvsp[(2) - (9)].string), std::shared_ptr<ExpressionAST>((yyvsp[(4) - (9)].expression)), std::shared_ptr<ExpressionAST>((yyvsp[(6) - (9)].expression)),
				std::make_shared<IntegerAST>(1), std::shared_ptr<BlockAST>((yyvsp[(8) - (9)].block)));
	;}
    break;

  case 70:
#line 370 "Parser.y"
    {
		(yyval.statement) = new ForAST(*(yyvsp[(2) - (11)].string), std::shared_ptr<ExpressionAST>((yyvsp[(4) - (11)].expression)), std::shared_ptr<ExpressionAST>((yyvsp[(6) - (11)].expression)),
				std::shared_ptr<ExpressionAST>((yyvsp[(8) - (11)].expression)), std::shared_ptr<BlockAST>((yyvsp[(10) - (11)].block)));
	;}
    break;


/* Line 1267 of yacc.c.  */
#line 2039 "Generated/Parser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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



