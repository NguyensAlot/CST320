/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 3 "lang.y" /* yacc.c:339  */

#include <iostream>
#include <string>
#include "lex.h"

#line 72 "langparse.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "langparse.h".  */
#ifndef YY_YY_LANGPARSE_H_INCLUDED
# define YY_YY_LANGPARSE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    TYPE_ID = 259,
    INT_VAL = 260,
    FLOAT_VAL = 261,
    ARRAY = 262,
    SCAN = 263,
    PRINT = 264,
    WHILE = 265,
    IF = 266,
    ELSE = 267,
    STRUCT = 268,
    RETURN = 269,
    JUNK_TOKEN = 270
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 11 "lang.y" /* yacc.c:355  */

    int                 int_val;
    double              float_val;
    cSymbol*            symbol;
    cScope*             sym_table;
    cAstNode*           ast_node;
    cBlockNode*         block;
    cDeclsNode*         decls;
    cDeclNode*          decl;
    cVarDeclNode*       varDecl;
    cStructDeclNode*    structDecl;
    cArrayDeclNode*     arrayDecl;
    cFuncDeclNode*      funcDecl;
    cParamsSpecNode*    paramsSpec;
    cArraySpecNode*     arraySpec;
    cFuncCallNode*      funcCall;
    cStmtsNode*         stmts;
    cStmtNode*          stmt;
    cVarRefNode*        varRef;
    cVarPartNode*       varPart;
    cArrayValNode*      arrayVal;
    cParamNode*         param;
    cExprNode*          expr;
    

#line 154 "langparse.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_LANGPARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 36 "lang.y" /* yacc.c:358  */

    int yyerror(const char *msg);
    int semantic_error(std::string msg);

    cBlockNode *yyast_root;

#line 189 "langparse.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   188

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    30,     2,     2,
      20,    19,    28,    26,    21,    27,    25,    29,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    18,
       2,    24,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    22,     2,    23,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    16,     2,    17,     2,     2,     2,     2,
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
      15
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    87,    87,    94,    95,    96,    98,   100,   103,   105,
     106,   107,   108,   109,   111,   113,   115,   117,   122,   128,
     135,   140,   144,   149,   153,   155,   157,   162,   164,   167,
     169,   171,   173,   175,   177,   179,   180,   181,   182,   183,
     184,   194,   196,   198,   202,   206,   208,   209,   218,   220,
     224,   226,   228,   229,   230,   232,   233,   234,   235,   237,
     238,   239,   240
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "TYPE_ID", "INT_VAL",
  "FLOAT_VAL", "ARRAY", "SCAN", "PRINT", "WHILE", "IF", "ELSE", "STRUCT",
  "RETURN", "JUNK_TOKEN", "'{'", "'}'", "';'", "')'", "'('", "','", "'['",
  "']'", "'='", "'.'", "'+'", "'-'", "'*'", "'/'", "'%'", "$accept",
  "program", "block", "open", "close", "decls", "decl", "var_decl",
  "struct_decl", "array_decl", "func_decl", "func_header", "func_prefix",
  "paramsspec", "paramspec", "arrayspec", "stmts", "stmt", "func_call",
  "varref", "varpart", "lval", "arrayval", "params", "param", "expr",
  "term", "fact", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   123,   125,    59,    41,
      40,    44,    91,    93,    61,    46,    43,    45,    42,    47,
      37
};
# endif

#define YYPACT_NINF -45

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-45)))

#define YYTABLE_NINF -40

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -1,   -45,    12,   -45,   140,   -45,     7,    10,    58,    39,
      34,    69,    76,    84,    -1,    11,   -45,   140,   -45,    95,
     100,   101,   -45,    42,    14,    89,   -45,   103,   102,   -45,
     105,   108,     4,   113,   110,   133,   135,    11,    11,    11,
      40,   -45,   -45,   -45,    11,   102,    -7,    65,   -45,   -45,
      89,   -45,   -45,   -45,   140,   -45,   149,   -45,   -45,    51,
     -45,   143,   -45,   -45,   -45,   -45,   135,    32,   -45,    91,
     -45,    22,    11,   -45,   144,   148,    37,    50,    52,   151,
      38,    61,   -45,    11,    11,    11,    11,    11,   -45,   140,
     106,   -45,   -45,   167,   -45,   -45,   155,    41,   -45,    11,
     119,   169,   150,   157,   158,   154,   154,   -45,   174,   -45,
      65,    65,   -45,   -45,   -45,   123,   -45,   -45,   -45,   -45,
     -45,   -45,   156,   173,   -45,   -45,   -45,   168,   -45,   -45,
     -45,   159,   154,   -45,   -45
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     2,     0,     1,     0,    48,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,     8,     0,
       0,     0,    11,     0,     0,     0,    29,     0,    46,    44,
       0,    13,     0,    45,    14,     0,     0,     0,     0,     0,
       0,    48,    60,    61,     0,    62,     0,    54,    58,     7,
       0,     9,    10,    12,     0,    17,     0,    21,    25,     0,
      24,     0,     6,     4,    28,    36,     0,     0,    42,     0,
      50,    51,     0,    22,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     3,     0,
       0,    14,    20,     0,    39,    43,     0,     0,    41,     0,
       0,     0,    16,     0,     0,     0,     0,    13,     0,    59,
      52,    53,    55,    56,    57,     0,    19,    23,    40,    35,
      49,    47,     0,     0,    34,    33,    32,    31,    15,    18,
      27,     0,     0,    26,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -45,   -45,   181,   170,   -44,   -32,   -15,   -20,   -45,   -45,
     -45,   -45,   -45,   -45,    90,   -45,   -14,   -24,   118,    -4,
     120,   152,   -45,   -45,    88,   -10,     0,    73
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    16,     4,    63,    17,    18,    19,    20,    21,
      22,    23,    24,    59,    60,   102,    25,    26,    27,    45,
      29,    30,    33,    69,    70,    71,    47,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      28,    64,    49,    50,    58,    46,    88,    41,    80,    42,
      43,    82,     5,    28,    41,     1,    42,    43,    56,    83,
      84,    28,    89,    68,    44,    31,    64,    76,    77,    78,
      32,    44,    28,    57,    81,     7,   108,    42,    43,    79,
      90,    79,     8,    35,     8,     9,    28,     9,    83,    84,
      28,    14,    44,    14,    36,    62,   104,    97,    54,   119,
      55,    34,   100,    83,    84,    49,    64,    83,    84,   105,
      92,   106,    93,    58,    49,   115,    83,    84,    83,    84,
     109,   126,   127,   110,   111,    28,    28,    83,    84,    37,
      61,    64,     7,    85,    86,    87,    38,    10,    11,    12,
      13,    28,    28,    15,    39,     1,    62,    61,   134,     7,
      98,    28,    99,    51,    10,    11,    12,    13,    52,    53,
      15,    65,     1,   116,    61,   -39,     7,    66,    28,    67,
      73,    10,    11,    12,    13,    72,    74,    15,    41,     1,
     129,     6,   121,     7,     8,    83,    84,     9,    10,    11,
      12,    13,    91,    14,    15,    61,     1,     7,   112,   113,
     114,    94,    10,    11,    12,    13,   101,   103,    15,   107,
       1,    56,   123,   118,   122,   124,   125,   128,   131,   130,
     132,     3,   133,   117,    40,    96,    95,   120,    75
};

static const yytype_uint8 yycheck[] =
{
       4,    25,    17,    17,    24,    15,    50,     3,    40,     5,
       6,    18,     0,    17,     3,    16,     5,     6,     4,    26,
      27,    25,    54,    19,    20,    18,    50,    37,    38,    39,
      20,    20,    36,    19,    44,     3,    80,     5,     6,     1,
      54,     1,     4,     4,     4,     7,    50,     7,    26,    27,
      54,    13,    20,    13,    20,    17,    19,    67,    16,    18,
      18,     3,    72,    26,    27,    80,    90,    26,    27,    19,
      19,    19,    21,    93,    89,    89,    26,    27,    26,    27,
      19,   105,   106,    83,    84,    89,    90,    26,    27,    20,
       1,   115,     3,    28,    29,    30,    20,     8,     9,    10,
      11,   105,   106,    14,    20,    16,    17,     1,   132,     3,
      19,   115,    21,    18,     8,     9,    10,    11,    18,    18,
      14,    18,    16,    17,     1,    17,     3,    25,   132,    24,
      20,     8,     9,    10,    11,    22,     3,    14,     3,    16,
      17,     1,    23,     3,     4,    26,    27,     7,     8,     9,
      10,    11,     3,    13,    14,     1,    16,     3,    85,    86,
      87,    18,     8,     9,    10,    11,    22,    19,    14,    18,
      16,     4,    22,    18,     5,    18,    18,     3,     5,    23,
      12,     0,    23,    93,    14,    67,    66,    99,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    16,    32,    33,    34,     0,     1,     3,     4,     7,
       8,     9,    10,    11,    13,    14,    33,    36,    37,    38,
      39,    40,    41,    42,    43,    47,    48,    49,    50,    51,
      52,    18,    20,    53,     3,     4,    20,    20,    20,    20,
      34,     3,     5,     6,    20,    50,    56,    57,    58,    37,
      47,    18,    18,    18,    16,    18,     4,    19,    38,    44,
      45,     1,    17,    35,    48,    18,    25,    24,    19,    54,
      55,    56,    22,    20,     3,    52,    56,    56,    56,     1,
      36,    56,    18,    26,    27,    28,    29,    30,    35,    36,
      47,     3,    19,    21,    18,    51,    49,    56,    19,    21,
      56,    22,    46,    19,    19,    19,    19,    18,    35,    19,
      57,    57,    58,    58,    58,    47,    17,    45,    18,    18,
      55,    23,     5,    22,    18,    18,    48,    48,     3,    17,
      23,     5,    12,    23,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    31,    32,    33,    33,    34,    35,    36,    36,    37,
      37,    37,    37,    37,    38,    39,    40,    41,    41,    41,
      42,    42,    43,    44,    44,    45,    46,    46,    47,    47,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    49,    49,    50,    50,    51,    52,    53,    53,    54,
      54,    55,    56,    56,    56,    57,    57,    57,    57,    58,
      58,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     4,     3,     1,     1,     2,     1,     2,
       2,     1,     2,     2,     2,     5,     4,     2,     5,     4,
       3,     2,     3,     3,     1,     1,     4,     3,     2,     1,
       7,     5,     5,     5,     5,     4,     2,     1,     3,     2,
       4,     4,     3,     3,     1,     2,     1,     4,     0,     3,
       1,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
     '$$ = $1'.

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
#line 87 "lang.y" /* yacc.c:1646  */
    { (yyval.block) = (yyvsp[0].block);
                                  yyast_root = (yyval.block);
                                  if (yynerrs == 0) 
                                      YYACCEPT;
                                  else
                                      YYABORT;
                                }
#line 1464 "langparse.c" /* yacc.c:1646  */
    break;

  case 3:
#line 94 "lang.y" /* yacc.c:1646  */
    { (yyval.block) = new cBlockNode((yyvsp[-2].decls), (yyvsp[-1].stmts)); }
#line 1470 "langparse.c" /* yacc.c:1646  */
    break;

  case 4:
#line 95 "lang.y" /* yacc.c:1646  */
    { (yyval.block) = new cBlockNode(NULL, (yyvsp[-1].stmts)); }
#line 1476 "langparse.c" /* yacc.c:1646  */
    break;

  case 5:
#line 96 "lang.y" /* yacc.c:1646  */
    { (yyval.sym_table) = symbolTableRoot->IncreaseScope(); }
#line 1482 "langparse.c" /* yacc.c:1646  */
    break;

  case 6:
#line 98 "lang.y" /* yacc.c:1646  */
    { (yyval.sym_table) = symbolTableRoot->DecreaseScope(); }
#line 1488 "langparse.c" /* yacc.c:1646  */
    break;

  case 7:
#line 100 "lang.y" /* yacc.c:1646  */
    { (yyval.decls) = (yyvsp[-1].decls); 
                                  (yyvsp[-1].decls)->AddNode((yyvsp[0].decl)); 
                                }
#line 1496 "langparse.c" /* yacc.c:1646  */
    break;

  case 8:
#line 103 "lang.y" /* yacc.c:1646  */
    { (yyval.decls) = new cDeclsNode((yyvsp[0].decl)); }
#line 1502 "langparse.c" /* yacc.c:1646  */
    break;

  case 9:
#line 105 "lang.y" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[-1].varDecl); }
#line 1508 "langparse.c" /* yacc.c:1646  */
    break;

  case 10:
#line 106 "lang.y" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[-1].structDecl); }
#line 1514 "langparse.c" /* yacc.c:1646  */
    break;

  case 11:
#line 107 "lang.y" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[0].funcDecl); }
#line 1520 "langparse.c" /* yacc.c:1646  */
    break;

  case 12:
#line 108 "lang.y" /* yacc.c:1646  */
    { (yyval.decl) = (yyvsp[-1].arrayDecl); }
#line 1526 "langparse.c" /* yacc.c:1646  */
    break;

  case 13:
#line 109 "lang.y" /* yacc.c:1646  */
    { (yyval.decl) = NULL; }
#line 1532 "langparse.c" /* yacc.c:1646  */
    break;

  case 14:
#line 112 "lang.y" /* yacc.c:1646  */
    { (yyval.varDecl) = new cVarDeclNode((yyvsp[-1].symbol), (yyvsp[0].symbol)); }
#line 1538 "langparse.c" /* yacc.c:1646  */
    break;

  case 15:
#line 114 "lang.y" /* yacc.c:1646  */
    { (yyval.structDecl) = new cStructDeclNode((yyvsp[-3].sym_table), (yyvsp[-2].decls), (yyvsp[0].symbol)); }
#line 1544 "langparse.c" /* yacc.c:1646  */
    break;

  case 16:
#line 116 "lang.y" /* yacc.c:1646  */
    { (yyval.arrayDecl) = new cArrayDeclNode((yyvsp[-2].symbol), (yyvsp[-1].symbol), (yyvsp[0].arraySpec)); }
#line 1550 "langparse.c" /* yacc.c:1646  */
    break;

  case 17:
#line 118 "lang.y" /* yacc.c:1646  */
    {
                            symbolTableRoot->DecreaseScope();
                            (yyval.funcDecl) = (yyvsp[-1].funcDecl);
                          }
#line 1559 "langparse.c" /* yacc.c:1646  */
    break;

  case 18:
#line 123 "lang.y" /* yacc.c:1646  */
    {
                            symbolTableRoot->DecreaseScope();
                            (yyval.funcDecl) = (yyvsp[-4].funcDecl);
                            (yyvsp[-4].funcDecl)->SetBody((yyvsp[-2].decls),(yyvsp[-1].stmts));
                          }
#line 1569 "langparse.c" /* yacc.c:1646  */
    break;

  case 19:
#line 129 "lang.y" /* yacc.c:1646  */
    {
                            symbolTableRoot->DecreaseScope();
                            (yyval.funcDecl) = (yyvsp[-3].funcDecl);
                            (yyvsp[-3].funcDecl)->SetBody(NULL,(yyvsp[-1].stmts));
                          }
#line 1579 "langparse.c" /* yacc.c:1646  */
    break;

  case 20:
#line 136 "lang.y" /* yacc.c:1646  */
    {
                            (yyval.funcDecl) = (yyvsp[-2].funcDecl);
                            (yyvsp[-2].funcDecl)->SetParams((yyvsp[-1].paramsSpec));
                          }
#line 1588 "langparse.c" /* yacc.c:1646  */
    break;

  case 21:
#line 141 "lang.y" /* yacc.c:1646  */
    { (yyval.funcDecl) = (yyvsp[-1].funcDecl);
                            (yyvsp[-1].funcDecl)->SetParams(NULL);
                          }
#line 1596 "langparse.c" /* yacc.c:1646  */
    break;

  case 22:
#line 145 "lang.y" /* yacc.c:1646  */
    { (yyval.funcDecl) = new cFuncDeclNode((yyvsp[-2].symbol), (yyvsp[-1].symbol));
                            symbolTableRoot->IncreaseScope(); 
                          }
#line 1604 "langparse.c" /* yacc.c:1646  */
    break;

  case 23:
#line 150 "lang.y" /* yacc.c:1646  */
    { (yyval.paramsSpec) = (yyvsp[-2].paramsSpec);
                                  (yyvsp[-2].paramsSpec)->AddNode((yyvsp[0].varDecl)); 
                                }
#line 1612 "langparse.c" /* yacc.c:1646  */
    break;

  case 24:
#line 153 "lang.y" /* yacc.c:1646  */
    { (yyval.paramsSpec) = new cParamsSpecNode((yyvsp[0].varDecl)); }
#line 1618 "langparse.c" /* yacc.c:1646  */
    break;

  case 25:
#line 155 "lang.y" /* yacc.c:1646  */
    { (yyval.varDecl) = (yyvsp[0].varDecl);}
#line 1624 "langparse.c" /* yacc.c:1646  */
    break;

  case 26:
#line 158 "lang.y" /* yacc.c:1646  */
    {
                                (yyval.arraySpec) = (yyvsp[-3].arraySpec);
                                (yyvsp[-3].arraySpec)->AddNode((yyvsp[-1].int_val));
                            }
#line 1633 "langparse.c" /* yacc.c:1646  */
    break;

  case 27:
#line 162 "lang.y" /* yacc.c:1646  */
    { (yyval.arraySpec) = new cArraySpecNode((yyvsp[-1].int_val)); }
#line 1639 "langparse.c" /* yacc.c:1646  */
    break;

  case 28:
#line 164 "lang.y" /* yacc.c:1646  */
    { (yyval.stmts) = (yyvsp[-1].stmts); 
                                  (yyvsp[-1].stmts)->AddNode((yyvsp[0].stmt)); 
                                }
#line 1647 "langparse.c" /* yacc.c:1646  */
    break;

  case 29:
#line 167 "lang.y" /* yacc.c:1646  */
    { (yyval.stmts) = new cStmtsNode((yyvsp[0].stmt)); }
#line 1653 "langparse.c" /* yacc.c:1646  */
    break;

  case 30:
#line 170 "lang.y" /* yacc.c:1646  */
    { (yyval.stmt) = new cIfNode((yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 1659 "langparse.c" /* yacc.c:1646  */
    break;

  case 31:
#line 172 "lang.y" /* yacc.c:1646  */
    { (yyval.stmt) = new cIfNode((yyvsp[-2].expr), (yyvsp[0].stmt), NULL); }
#line 1665 "langparse.c" /* yacc.c:1646  */
    break;

  case 32:
#line 174 "lang.y" /* yacc.c:1646  */
    { (yyval.stmt) = new cWhileNode((yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 1671 "langparse.c" /* yacc.c:1646  */
    break;

  case 33:
#line 176 "lang.y" /* yacc.c:1646  */
    { (yyval.stmt) = new cPrintNode((yyvsp[-2].expr)); }
#line 1677 "langparse.c" /* yacc.c:1646  */
    break;

  case 34:
#line 178 "lang.y" /* yacc.c:1646  */
    { (yyval.stmt) = new cScanNode((yyvsp[-2].varRef)); }
#line 1683 "langparse.c" /* yacc.c:1646  */
    break;

  case 35:
#line 179 "lang.y" /* yacc.c:1646  */
    { (yyval.stmt) = new cAssignNode((yyvsp[-3].varRef), (yyvsp[-1].expr)); }
#line 1689 "langparse.c" /* yacc.c:1646  */
    break;

  case 36:
#line 180 "lang.y" /* yacc.c:1646  */
    { (yyval.stmt) = new cFuncStmtNode((yyvsp[-1].funcCall)); }
#line 1695 "langparse.c" /* yacc.c:1646  */
    break;

  case 37:
#line 181 "lang.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].block); }
#line 1701 "langparse.c" /* yacc.c:1646  */
    break;

  case 38:
#line 182 "lang.y" /* yacc.c:1646  */
    { (yyval.stmt) = new cReturnNode((yyvsp[-1].expr)); }
#line 1707 "langparse.c" /* yacc.c:1646  */
    break;

  case 39:
#line 183 "lang.y" /* yacc.c:1646  */
    { (yyval.stmt) = NULL; }
#line 1713 "langparse.c" /* yacc.c:1646  */
    break;

  case 40:
#line 185 "lang.y" /* yacc.c:1646  */
    { 
                                    (yyval.stmt) = new cAssignNode((cVarRefNode*)(yyvsp[-3].varRef), (yyvsp[-1].funcCall));
                                    if ((yyval.stmt)->SemanticError())
                                    {
                                        semantic_error("function");
                                        (yyval.stmt) = nullptr;
                                    }
                                }
#line 1726 "langparse.c" /* yacc.c:1646  */
    break;

  case 41:
#line 195 "lang.y" /* yacc.c:1646  */
    { (yyval.funcCall) = new cFuncCallNode((yyvsp[-3].symbol), (yyvsp[-1].param)); }
#line 1732 "langparse.c" /* yacc.c:1646  */
    break;

  case 42:
#line 197 "lang.y" /* yacc.c:1646  */
    { (yyval.funcCall) = new cFuncCallNode((yyvsp[-2].symbol), NULL); }
#line 1738 "langparse.c" /* yacc.c:1646  */
    break;

  case 43:
#line 198 "lang.y" /* yacc.c:1646  */
    { (yyval.varRef) = (yyvsp[-2].varRef);
                                  (yyval.varRef)->AddNode((yyvsp[0].varPart));
                                  if ((yyval.varRef)->SemanticError()) YYERROR;
                                }
#line 1747 "langparse.c" /* yacc.c:1646  */
    break;

  case 44:
#line 202 "lang.y" /* yacc.c:1646  */
    { (yyval.varRef) = new cVarRefNode((yyvsp[0].varPart)); 
                                  if ((yyval.varRef)->SemanticError()) YYERROR;
                                }
#line 1755 "langparse.c" /* yacc.c:1646  */
    break;

  case 45:
#line 206 "lang.y" /* yacc.c:1646  */
    { (yyval.varPart) = new cVarPartNode((yyvsp[-1].symbol), (yyvsp[0].arrayVal)); }
#line 1761 "langparse.c" /* yacc.c:1646  */
    break;

  case 46:
#line 208 "lang.y" /* yacc.c:1646  */
    { (yyval.varRef) = (yyvsp[0].varRef); }
#line 1767 "langparse.c" /* yacc.c:1646  */
    break;

  case 47:
#line 210 "lang.y" /* yacc.c:1646  */
    { if ((yyvsp[-3].arrayVal) == NULL)
                                  (yyval.arrayVal) = new cArrayValNode((yyvsp[-1].expr));
                                else 
                                {
                                  (yyval.arrayVal) = (yyvsp[-3].arrayVal);
                                  (yyvsp[-3].arrayVal)->AddNode((yyvsp[-1].expr));
                                }
                              }
#line 1780 "langparse.c" /* yacc.c:1646  */
    break;

  case 48:
#line 218 "lang.y" /* yacc.c:1646  */
    { (yyval.arrayVal) = NULL; }
#line 1786 "langparse.c" /* yacc.c:1646  */
    break;

  case 49:
#line 221 "lang.y" /* yacc.c:1646  */
    { (yyval.param) = (yyvsp[-2].param);
                                  (yyvsp[-2].param)->AddNode((yyvsp[0].expr));
                                }
#line 1794 "langparse.c" /* yacc.c:1646  */
    break;

  case 50:
#line 224 "lang.y" /* yacc.c:1646  */
    { (yyval.param) = new cParamNode((yyvsp[0].expr)); }
#line 1800 "langparse.c" /* yacc.c:1646  */
    break;

  case 51:
#line 226 "lang.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1806 "langparse.c" /* yacc.c:1646  */
    break;

  case 52:
#line 228 "lang.y" /* yacc.c:1646  */
    { (yyval.expr) = new cBinaryExprNode((yyvsp[-2].expr), '+', (yyvsp[0].expr)); }
#line 1812 "langparse.c" /* yacc.c:1646  */
    break;

  case 53:
#line 229 "lang.y" /* yacc.c:1646  */
    { (yyval.expr) = new cBinaryExprNode((yyvsp[-2].expr), '-', (yyvsp[0].expr)); }
#line 1818 "langparse.c" /* yacc.c:1646  */
    break;

  case 54:
#line 230 "lang.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1824 "langparse.c" /* yacc.c:1646  */
    break;

  case 55:
#line 232 "lang.y" /* yacc.c:1646  */
    { (yyval.expr) = new cBinaryExprNode((yyvsp[-2].expr), '*', (yyvsp[0].expr)); }
#line 1830 "langparse.c" /* yacc.c:1646  */
    break;

  case 56:
#line 233 "lang.y" /* yacc.c:1646  */
    { (yyval.expr) = new cBinaryExprNode((yyvsp[-2].expr), '/', (yyvsp[0].expr)); }
#line 1836 "langparse.c" /* yacc.c:1646  */
    break;

  case 57:
#line 234 "lang.y" /* yacc.c:1646  */
    { (yyval.expr) = new cBinaryExprNode((yyvsp[-2].expr), '%', (yyvsp[0].expr)); }
#line 1842 "langparse.c" /* yacc.c:1646  */
    break;

  case 58:
#line 235 "lang.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1848 "langparse.c" /* yacc.c:1646  */
    break;

  case 59:
#line 237 "lang.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 1854 "langparse.c" /* yacc.c:1646  */
    break;

  case 60:
#line 238 "lang.y" /* yacc.c:1646  */
    { (yyval.expr) = new cIntExprNode((yyvsp[0].int_val)); }
#line 1860 "langparse.c" /* yacc.c:1646  */
    break;

  case 61:
#line 239 "lang.y" /* yacc.c:1646  */
    { (yyval.expr) = new cFloatExprNode((yyvsp[0].float_val)); }
#line 1866 "langparse.c" /* yacc.c:1646  */
    break;

  case 62:
#line 240 "lang.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].varRef); }
#line 1872 "langparse.c" /* yacc.c:1646  */
    break;


#line 1876 "langparse.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 242 "lang.y" /* yacc.c:1906  */


int yyerror(const char *msg)
{
    std::cout << "ERROR: " << msg << " at symbol "
        << yytext << " on line " << yylineno << "\n";

    return 0;
}
int semantic_error(std::string msg)
{
    std::cout << "ERROR: " << msg << " on line " << yylineno << "\n";
    
    yynerrs++;

    return 0;
}
