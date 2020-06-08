/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "alfa.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "alfa.tab.h"
#include "generacion.h"
#include "tablaSimbolos.h"

extern int yylex();
extern char* yytext;
extern int row;
extern int column;
extern void yyerror();
extern int aux;
extern FILE * file;
FILE * pfasm;
FILE * yyin;
/*int vector_actual_tamano;
int pos_variable_local_actual;
int num_parametros_actual;
int num_variables_actual;
int num_variables_locales_actual;
int pos_parametro_actual;
int tipo_funcion;
*/
static int clase_actual, ambito_actual, tipo_actual;
static int num_variables_locales_actual = 0;
static int pos_variable_local_actual = 1;
static int tamanio_vector_actual = 0;
static int pos_parametro_actual = -1;
static int num_parametros_actual = 0;
static int fn_return = 0;

void ASSERT_SEMANTICO(int cond, char* err_msg, char* extra_info) {
    if (!(cond)) {
        yyerror(err_msg);
        printf("__________ERROR:%s '%s'\n",err_msg, extra_info);
        exit(0);
    }
}
/*

static int en_explist = 0;
static int etiqueta = 1;
*/

#line 114 "alfa.tab.c" /* yacc.c:339  */

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
   by #include "alfa.tab.h".  */
#ifndef YY_YY_ALFA_TAB_H_INCLUDED
# define YY_YY_ALFA_TAB_H_INCLUDED
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
    TOK_MAIN = 258,
    TOK_INT = 259,
    TOK_BOOLEAN = 260,
    TOK_ARRAY = 261,
    TOK_FUNCTION = 262,
    TOK_IF = 263,
    TOK_ELSE = 264,
    TOK_WHILE = 265,
    TOK_SCANF = 266,
    TOK_PRINTF = 267,
    TOK_RETURN = 268,
    TOK_PUNTOYCOMA = 269,
    TOK_COMA = 270,
    TOK_PARENTESISIZQUIERDO = 271,
    TOK_PARENTESISDERECHO = 272,
    TOK_CORCHETEIZQUIERDO = 273,
    TOK_CORCHETEDERECHO = 274,
    TOK_LLAVEIZQUIERDA = 275,
    TOK_LLAVEDERECHA = 276,
    TOK_ASIGNACION = 277,
    TOK_MAS = 278,
    TOK_MENOS = 279,
    TOK_DIVISION = 280,
    TOK_ASTERISCO = 281,
    TOK_AND = 282,
    TOK_OR = 283,
    TOK_NOT = 284,
    TOK_IGUAL = 285,
    TOK_DISTINTO = 286,
    TOK_MASIGUAL = 287,
    TOK_MENORIGUAL = 288,
    TOK_MAYORIGUAL = 289,
    TOK_MENOR = 290,
    TOK_MAYOR = 291,
    TOK_IDENTIFICADOR = 292,
    TOK_CONSTANTE_ENTERA = 293,
    TOK_TRUE = 294,
    TOK_FALSE = 295,
    TOK_ERROR = 296
  };
#endif
/* Tokens.  */
#define TOK_MAIN 258
#define TOK_INT 259
#define TOK_BOOLEAN 260
#define TOK_ARRAY 261
#define TOK_FUNCTION 262
#define TOK_IF 263
#define TOK_ELSE 264
#define TOK_WHILE 265
#define TOK_SCANF 266
#define TOK_PRINTF 267
#define TOK_RETURN 268
#define TOK_PUNTOYCOMA 269
#define TOK_COMA 270
#define TOK_PARENTESISIZQUIERDO 271
#define TOK_PARENTESISDERECHO 272
#define TOK_CORCHETEIZQUIERDO 273
#define TOK_CORCHETEDERECHO 274
#define TOK_LLAVEIZQUIERDA 275
#define TOK_LLAVEDERECHA 276
#define TOK_ASIGNACION 277
#define TOK_MAS 278
#define TOK_MENOS 279
#define TOK_DIVISION 280
#define TOK_ASTERISCO 281
#define TOK_AND 282
#define TOK_OR 283
#define TOK_NOT 284
#define TOK_IGUAL 285
#define TOK_DISTINTO 286
#define TOK_MASIGUAL 287
#define TOK_MENORIGUAL 288
#define TOK_MAYORIGUAL 289
#define TOK_MENOR 290
#define TOK_MAYOR 291
#define TOK_IDENTIFICADOR 292
#define TOK_CONSTANTE_ENTERA 293
#define TOK_TRUE 294
#define TOK_FALSE 295
#define TOK_ERROR 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 48 "alfa.y" /* yacc.c:355  */

    tipo_atributos atributos;

#line 240 "alfa.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ALFA_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 257 "alfa.tab.c" /* yacc.c:358  */

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  149

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   119,   119,   122,   129,   137,   139,   141,   142,   145,
     147,   148,   150,   152,   153,   155,   161,   162,   164,   165,
     167,   172,   182,   200,   201,   203,   204,   206,   211,   221,
     222,   223,   224,   225,   226,   227,   228,   229,   230,   233,
     234,   237,   254,   257,   261,   264,   267,   270,   290,   293,
     298,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     321,   322,   323,   324,   326,   329,   332,   333,   335,   336,
     337,   338,   339,   340,   341,   346,   351,   356,   362,   368,
     372
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_MAIN", "TOK_INT", "TOK_BOOLEAN",
  "TOK_ARRAY", "TOK_FUNCTION", "TOK_IF", "TOK_ELSE", "TOK_WHILE",
  "TOK_SCANF", "TOK_PRINTF", "TOK_RETURN", "TOK_PUNTOYCOMA", "TOK_COMA",
  "TOK_PARENTESISIZQUIERDO", "TOK_PARENTESISDERECHO",
  "TOK_CORCHETEIZQUIERDO", "TOK_CORCHETEDERECHO", "TOK_LLAVEIZQUIERDA",
  "TOK_LLAVEDERECHA", "TOK_ASIGNACION", "TOK_MAS", "TOK_MENOS",
  "TOK_DIVISION", "TOK_ASTERISCO", "TOK_AND", "TOK_OR", "TOK_NOT",
  "TOK_IGUAL", "TOK_DISTINTO", "TOK_MASIGUAL", "TOK_MENORIGUAL",
  "TOK_MAYORIGUAL", "TOK_MENOR", "TOK_MAYOR", "TOK_IDENTIFICADOR",
  "TOK_CONSTANTE_ENTERA", "TOK_TRUE", "TOK_FALSE", "TOK_ERROR", "$accept",
  "programa", "_inicio", "_escritura1", "_escritura2", "_final",
  "declaraciones", "declaracion", "clase", "clase_escalar", "tipo",
  "clase_vector", "identificadores", "funciones", "funcion",
  "fn_declaration", "fn_name", "parametros_funcion",
  "resto_parametros_funcion", "idpf", "parametro_funcion",
  "declaraciones_funcion", "sentencias", "sentencia", "sentencia_simple",
  "bloque", "asignacion", "elemento_vector", "condicional", "bucle",
  "lectura", "escritura", "retorno_funcion", "exp", "lista_expresiones",
  "resto_lista_expresiones", "comparacion", "constante",
  "constante_logica", "constante_entera", "identificador",
  "identificador_nuevo", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

#define YYPACT_NINF -35

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-35)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,     1,    31,   -35,   -35,     9,   -35,   -35,    25,   -35,
       9,   -12,   -35,   -35,   -35,    15,    33,   -35,   -35,    34,
      35,    13,    25,   -35,    33,    24,    36,   -35,   -12,   -35,
      44,    27,    24,   -35,    49,    56,    27,    67,    67,   -35,
      59,    24,    68,   -35,   -35,    70,   -35,   -35,   -35,   -35,
     -35,   -10,    25,   -35,   -35,   -35,   -35,    67,    67,   -35,
      67,    67,    67,   -35,   -35,   -35,    85,   -35,   -35,   -35,
       4,    85,   -35,   -35,   -35,    67,    67,    67,    27,    64,
      79,    63,    62,   127,   101,    80,    19,   -35,    67,    67,
      67,    67,    67,    67,    67,    85,    43,    85,   -35,   -35,
      94,    25,   -35,   -35,    97,    99,   -35,    67,    67,    67,
      67,    67,    67,   -35,    19,    19,    11,    11,   -35,   -35,
     115,   103,   -35,     9,    79,    24,    24,    85,    85,    85,
      85,    85,    85,    67,   -35,   -35,   -35,   -35,   -35,   112,
     124,   115,   113,   -35,   -35,   126,    24,   128,   -35
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     1,     0,    13,    14,     0,     4,
       7,     0,    10,    12,    11,     0,    19,     8,    80,     0,
      16,     0,     0,     5,    19,     0,     0,     9,     0,    78,
       0,     0,     0,    18,     0,     0,     0,     0,     0,    79,
       0,    31,     0,    34,    35,     0,    39,    40,    36,    37,
      38,     0,    24,    17,    15,    22,     6,     0,     0,    47,
       0,     0,     0,    76,    77,    62,    48,    59,    74,    75,
      58,    49,    20,    32,    33,     0,     0,     0,     0,     0,
      26,     0,     0,     0,     0,     0,    54,    57,     0,     0,
       0,     0,     0,     0,    65,    42,     0,    41,    28,    27,
       0,     0,    23,     2,     0,     0,    60,     0,     0,     0,
       0,     0,     0,    61,    50,    51,    52,    53,    55,    56,
      67,     0,    43,    30,    26,     0,     0,    68,    69,    70,
      71,    72,    73,     0,    64,    63,    29,    21,    25,     0,
       0,    67,    44,    46,    66,     0,     0,     0,    45
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -35,   -35,   -35,   -35,   -35,   -35,    -7,   -35,   -35,   -35,
      -3,   -35,   119,   132,   -35,   -35,   -35,   -35,    37,   -35,
      47,   -35,   -31,   -35,   -35,   -35,   -35,   -23,   -35,   -35,
     -35,   -35,   -35,   -34,   -35,    16,   -35,   -35,   -35,   137,
     -25,   -35
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    16,    32,    81,     9,    10,    11,    12,
      13,    14,    19,    23,    24,    25,    26,    79,   102,    98,
      80,   137,    40,    41,    42,    43,    44,    65,    46,    47,
      48,    49,    50,    66,   121,   134,    85,    67,    68,    69,
      70,    20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      51,    56,    45,    17,    71,    15,    55,    51,    76,    45,
      73,    59,    77,     6,     7,     8,    51,     1,    45,    31,
      94,     3,    76,    82,    83,    18,    84,    86,    87,     6,
       7,     4,    34,    21,    35,    36,    37,    38,    92,    93,
      22,    95,    96,    97,    90,    91,    92,    93,    27,    78,
      28,    29,    52,    99,   114,   115,   116,   117,   118,   119,
     120,    39,   122,    54,    39,    57,    88,    89,    90,    91,
      92,    93,    58,   127,   128,   129,   130,   131,   132,   104,
      72,   100,    74,    60,   103,    88,    89,    90,    91,    92,
      93,    61,    75,   101,   139,   140,    62,   113,    78,   141,
      51,    51,    45,    45,    39,    29,    63,    64,    88,    89,
      90,    91,    92,    93,   123,   147,   136,   125,   106,   126,
     135,    51,   145,    45,    88,    89,    90,    91,    92,    93,
     133,   107,   108,   142,   109,   110,   111,   112,    88,    89,
      90,    91,    92,    93,   105,   143,   146,    53,   124,   148,
      88,    89,    90,    91,    92,    93,    33,   144,    30,     0,
       0,   138
};

static const yytype_int16 yycheck[] =
{
      25,    32,    25,    10,    38,     8,    31,    32,    18,    32,
      41,    36,    22,     4,     5,     6,    41,     3,    41,    22,
      16,    20,    18,    57,    58,    37,    60,    61,    62,     4,
       5,     0,     8,    18,    10,    11,    12,    13,    27,    28,
       7,    75,    76,    77,    25,    26,    27,    28,    14,    52,
      15,    38,    16,    78,    88,    89,    90,    91,    92,    93,
      94,    37,    19,    19,    37,    16,    23,    24,    25,    26,
      27,    28,    16,   107,   108,   109,   110,   111,   112,    17,
      21,    17,    14,    16,    21,    23,    24,    25,    26,    27,
      28,    24,    22,    14,   125,   126,    29,    17,   101,   133,
     125,   126,   125,   126,    37,    38,    39,    40,    23,    24,
      25,    26,    27,    28,    20,   146,   123,    20,    17,    20,
      17,   146,     9,   146,    23,    24,    25,    26,    27,    28,
      15,    30,    31,    21,    33,    34,    35,    36,    23,    24,
      25,    26,    27,    28,    17,    21,    20,    28,   101,    21,
      23,    24,    25,    26,    27,    28,    24,   141,    21,    -1,
      -1,   124
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    43,    20,     0,    44,     4,     5,     6,    48,
      49,    50,    51,    52,    53,    52,    45,    48,    37,    54,
      83,    18,     7,    55,    56,    57,    58,    14,    15,    38,
      81,    52,    46,    55,     8,    10,    11,    12,    13,    37,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    82,    16,    54,    19,    82,    64,    16,    16,    82,
      16,    24,    29,    39,    40,    69,    75,    79,    80,    81,
      82,    75,    21,    64,    14,    22,    18,    22,    52,    59,
      62,    47,    75,    75,    75,    78,    75,    75,    23,    24,
      25,    26,    27,    28,    16,    75,    75,    75,    61,    82,
      17,    14,    60,    21,    17,    17,    17,    30,    31,    33,
      34,    35,    36,    17,    75,    75,    75,    75,    75,    75,
      75,    76,    19,    20,    62,    20,    20,    75,    75,    75,
      75,    75,    75,    15,    77,    17,    48,    63,    60,    64,
      64,    75,    21,    21,    77,     9,    20,    64,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    45,    46,    47,    48,    48,    49,
      50,    50,    51,    52,    52,    53,    54,    54,    55,    55,
      56,    57,    58,    59,    59,    60,    60,    61,    62,    63,
      63,    64,    64,    65,    65,    66,    66,    66,    66,    67,
      67,    68,    68,    69,    70,    70,    71,    72,    73,    74,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    76,    76,    77,    77,    78,    78,
      78,    78,    78,    78,    79,    79,    80,    80,    81,    82,
      83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,    10,     0,     0,     0,     0,     1,     2,     3,
       1,     1,     1,     1,     1,     5,     1,     3,     2,     0,
       3,     6,     3,     2,     0,     3,     0,     1,     2,     1,
       0,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     4,     7,    11,     7,     2,     2,     2,
       3,     3,     3,     3,     2,     3,     3,     2,     1,     1,
       3,     3,     1,     4,     2,     0,     3,     0,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1
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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 120 "alfa.y" /* yacc.c:1646  */
    { fprintf (file,";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n"); }
#line 1455 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 122 "alfa.y" /* yacc.c:1646  */
    { // Inicializacion inicial
                  iniciar_scope();
                  escribir_subseccion_data(pfasm);
                  escribir_cabecera_bss(pfasm);
                  }
#line 1465 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 129 "alfa.y" /* yacc.c:1646  */
    { // Declaramos en el segmento bss todas las variables globales declaradas
                  INFO_SIMBOLO* simbolos = simbolos_globales();
                  for (; NULL != simbolos; simbolos = simbolos->next) {
                    if (VARIABLE == simbolos->categoria)
                      declarar_variable(pfasm, simbolos->lexema, simbolos->tipo, (VECTOR == simbolos->clase) ? simbolos->adicional1 : 1);
                    }
                  escribir_segmento_codigo(pfasm);}
#line 1477 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 137 "alfa.y" /* yacc.c:1646  */
    { escribir_inicio_main(pfasm);}
#line 1483 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 139 "alfa.y" /* yacc.c:1646  */
    { escribir_fin(pfasm); liberar_scope(); }
#line 1489 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 141 "alfa.y" /* yacc.c:1646  */
    { fprintf (file,";R2:\t<declaraciones> ::= <declaracion>\n"); }
#line 1495 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 142 "alfa.y" /* yacc.c:1646  */
    { fprintf (file,";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n"); }
#line 1501 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 145 "alfa.y" /* yacc.c:1646  */
    {fprintf(file,";R4:\t<declaracion> ::= <clase> <identificadores> ;\n"); }
#line 1507 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 147 "alfa.y" /* yacc.c:1646  */
    { fprintf (file,";R5:\t<clase> ::= <clase_escalar>\n"); clase_actual = ESCALAR;		        }
#line 1513 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 148 "alfa.y" /* yacc.c:1646  */
    {fprintf (file,";R7:\t<clase> ::= <clase_vector>\n"); clase_actual = VECTOR;  }
#line 1519 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 150 "alfa.y" /* yacc.c:1646  */
    { fprintf (file,";R9:\t<clase_escalar> ::= <tipo>\n");		}
#line 1525 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 152 "alfa.y" /* yacc.c:1646  */
    {		fprintf(file,";R10:\t<tipo> ::= int\n"); tipo_actual = ENTERO;}
#line 1531 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 153 "alfa.y" /* yacc.c:1646  */
    {fprintf(file,";R11:\t<tipo> ::= boolean\n"); tipo_actual = BOOLEANO;   }
#line 1537 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 155 "alfa.y" /* yacc.c:1646  */
    {
		              fprintf(file,";R15:\t<clase_vector> ::= array <tipo> [ <constante_entera> ]\n");
                  tamanio_vector_actual = (yyvsp[-1].atributos).valor_entero;
                  ASSERT_SEMANTICO(tamanio_vector_actual >= 1, "El tamanyo del vector excede los limites permitidos ", NULL);
                  ASSERT_SEMANTICO(tamanio_vector_actual <= MAX_TAMANIO_VECTOR, "El tamanyo del vector excede los limites permitidos", NULL);}
#line 1547 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 161 "alfa.y" /* yacc.c:1646  */
    { fprintf(file,";R18:\t<identificadores> ::= <identificador>\n"); }
#line 1553 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 162 "alfa.y" /* yacc.c:1646  */
    { fprintf(file,";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");}
#line 1559 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 164 "alfa.y" /* yacc.c:1646  */
    {fprintf(file,";R20:\t<funciones> ::= <funcion> <funciones>\n");}
#line 1565 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 165 "alfa.y" /* yacc.c:1646  */
    {fprintf(file,";R21:\t<funciones> ::=\n");}
#line 1571 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 167 "alfa.y" /* yacc.c:1646  */
    {			fprintf(file,";R22:\t<funcion> ::= function <tipo> <identificador> ( <parametros_funcion> ) { <declaraciones_funcion> <sentencias> }\n");
    	ambito_actual = 0;
    	cerrar_scope_local();
    	ASSERT_SEMANTICO(fn_return != 0, "Funcion sin sentencia de retorno", (yyvsp[-2].atributos).lexema);
			}
#line 1581 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 172 "alfa.y" /* yacc.c:1646  */
    {
	    INFO_SIMBOLO* info = get_SimbolByID_SoloGlobal((yyvsp[-5].atributos).lexema);
	    info->adicional1 = num_parametros_actual;
	    info->adicional2 = num_variables_locales_actual;
	    info = get_SimbolByID((yyvsp[-5].atributos).lexema);
	    info->adicional1 = num_parametros_actual;
	    info->adicional2 = num_variables_locales_actual;
	    (yyval.atributos) = (yyvsp[-5].atributos);
	    declararFuncion(pfasm, (yyval.atributos).lexema, num_variables_locales_actual);
      }
#line 1596 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 182 "alfa.y" /* yacc.c:1646  */
    {
      INFO_SIMBOLO* info = get_SimbolByID_SoloGlobal((yyvsp[0].atributos).lexema);
      ASSERT_SEMANTICO(NULL == info, "Declaracion duplicada", NULL);
      /* Abrimos un nuevo ambito */
      /* Esta funcion declarara el nuevo ambito y realizara las inserciones correspondientes */
      /* Aun no sabemos numero de variable y parametros se modificara a posteriori */
      declarar_funcion((yyvsp[0].atributos).lexema, tipo_actual, -1, -1);
      /* Inicializamos variables de la funcion */
      num_variables_locales_actual = 0;
  		pos_variable_local_actual = 1;
  		num_parametros_actual = 0;
  		pos_parametro_actual = 0;
  		fn_return = 0;
      tamanio_vector_actual = 0;
	    /* Propagamos el nombre de la funcion */
  		(yyval.atributos) = (yyvsp[0].atributos);
  		ambito_actual = 1;
      }
#line 1619 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 200 "alfa.y" /* yacc.c:1646  */
    {fprintf(file,";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n"); }
#line 1625 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 201 "alfa.y" /* yacc.c:1646  */
    { fprintf(file,";R24:\t<parametros_funcion> ::=\n");}
#line 1631 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 203 "alfa.y" /* yacc.c:1646  */
    {fprintf(file,";R25:\t<resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");}
#line 1637 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 204 "alfa.y" /* yacc.c:1646  */
    {fprintf(file,";R26:\t<resto_parametros_funcion> ::=\n"); }
#line 1643 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 206 "alfa.y" /* yacc.c:1646  */
    {
                (yyval.atributos) = (yyvsp[0].atributos);
                clase_actual = ESCALAR;
                }
#line 1652 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 211 "alfa.y" /* yacc.c:1646  */
    {	fprintf (file,";R27:\t<parametro_funcion> ::= <tipo> <identificador>\n");
          			INFO_SIMBOLO* info = uso_solo_local((yyvsp[0].atributos).lexema);
                ASSERT_SEMANTICO(NULL == info, "Declaracion duplicada", NULL);
                /* Declaramos el parametro en la tabla local */
                /* Adicional 2 indica la posicion del parametro en llamada a funcion */
                declarar_local((yyvsp[0].atributos).lexema, PARAMETRO, tipo_actual, clase_actual, 0, pos_parametro_actual);
                /* Se debe incrementar tras insertar en la tabla para que el primer parametro comience en 0 */
                pos_parametro_actual++;
                num_parametros_actual++;
          			}
#line 1667 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 221 "alfa.y" /* yacc.c:1646  */
    { fprintf (file,";R28:\t<declaraciones_funcion> ::= <declaraciones>\n"); }
#line 1673 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 222 "alfa.y" /* yacc.c:1646  */
    { fprintf (file,";R29:\t<declaraciones_funcion> ::=\n");}
#line 1679 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 223 "alfa.y" /* yacc.c:1646  */
    { 	fprintf (file,";R30:\t<sentencias> ::= <sentencia>\n"); }
#line 1685 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 224 "alfa.y" /* yacc.c:1646  */
    { fprintf (file,";R31:\t<sentencias> ::= <sentencia> <sentencias>\n"); }
#line 1691 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 225 "alfa.y" /* yacc.c:1646  */
    { fprintf (file,";R32:\t<sentencia> ::= <sentencia_simple> ;\n"); }
#line 1697 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 226 "alfa.y" /* yacc.c:1646  */
    { fprintf (file,";R33:\t<sentencia> ::= <bloque>\n"); }
#line 1703 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 227 "alfa.y" /* yacc.c:1646  */
    { fprintf(file,";R34:\t<sentencia_simple> ::= <asignacion>\n"); }
#line 1709 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 228 "alfa.y" /* yacc.c:1646  */
    { fprintf(file,";R35:\t<sentencia_simple> ::= <lectura>\n"); }
#line 1715 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 229 "alfa.y" /* yacc.c:1646  */
    { fprintf(file,";R36:\t<sentencia_simple> ::= <escritura>\n"); }
#line 1721 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 230 "alfa.y" /* yacc.c:1646  */
    { fprintf(file,";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");
                }
#line 1728 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 233 "alfa.y" /* yacc.c:1646  */
    {fprintf(file,";R40:\t<bloque> ::= <condicional>\n");}
#line 1734 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 234 "alfa.y" /* yacc.c:1646  */
    {fprintf(file,";R41:\t<bloque> ::= <bucle>\n");}
#line 1740 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 237 "alfa.y" /* yacc.c:1646  */
    { fprintf(file,";R43:\t<asignacion> ::= <identificador> = <exp>\n");
        INFO_SIMBOLO* info = get_SimbolByID((yyvsp[-2].atributos).lexema);
        ASSERT_SEMANTICO(NULL != info, "Asignacion incompatible", NULL);
        ASSERT_SEMANTICO(FUNCION != info->categoria, "Asignacion incompatible", NULL);
        ASSERT_SEMANTICO(VECTOR != info->clase, "Asignacion incompatible", NULL);
        ASSERT_SEMANTICO((yyvsp[0].atributos).tipo == info->tipo, "Asignacion incompatible", NULL);
        /* Caso variables globales */
        if(NULL == uso_solo_local((yyvsp[-2].atributos).lexema)) {
          asignar(pfasm, (yyvsp[-2].atributos).lexema, (yyvsp[0].atributos).es_direccion);
        /* Caso parametros en funciones en funciones */
        } else if (PARAMETRO == info->categoria){
          escribirParametro(pfasm, info->adicional2, num_parametros_actual);
                            /* El ultimo caso son variables locales */
        } else {
          escribirVariableLocal(pfasm, (yyvsp[0].atributos).es_direccion, info->adicional2);
        }
      }
#line 1762 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 254 "alfa.y" /* yacc.c:1646  */
    {fprintf(file,";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
        asignar_vector(pfasm, (yyvsp[0].atributos).es_direccion);}
#line 1769 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 257 "alfa.y" /* yacc.c:1646  */
    {
			fprintf(file,";R48:\t<elemento_vector> ::= <identificador> [ <exp> ]\n");

			}
#line 1778 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 261 "alfa.y" /* yacc.c:1646  */
    {
			fprintf(file,";R50:\t<condicional> ::= if ( <exp> ) { <sentencias> }\n");
			}
#line 1786 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 264 "alfa.y" /* yacc.c:1646  */
    {
			fprintf(file,";R51:\t<condicional> ::= if ( <exp> ) { <sentencias> } else { <sentencias> }\n");
			    }
#line 1794 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 267 "alfa.y" /* yacc.c:1646  */
    {
			fprintf(file,";R52:\t<bucle> ::= while ( <exp> ) { <sentencias> }\n");
			    }
#line 1802 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 270 "alfa.y" /* yacc.c:1646  */
    {
                fprintf(file,";R54:\t<lectura> ::= scanf <identificador>\n");
              /*  INFO_SIMBOLO* info = get_SimbolByID($2.lexema);

                ASSERT_SEMANTICO(NULL != info, "Acceso a variable no declarada", $2.lexema);
                ASSERT_SEMANTICO(FUNCION != info->categoria, "Solo podemos leer enteros o booleanos", NULL);
                ASSERT_SEMANTICO(ESCALAR == info->clase, "Solo podemos leer escalares", NULL);
*/
                /* Llamamos a scanf, restauramos la pila en funcion del tipo
                if(NULL == uso_solo_local($2.lexema)){
                leer(pfasm, info->lexema, info->tipo);
                } else if(PARAMETRO == info->categoria) {
                escribirParametro(pfasm, 1, info->adicional2, num_parametros_actual);
                leer_ya_apilado(pfasm, info->tipo);
                } else {
                escribirVariableLocal(pfasm, 1, info->adicional2);
                leer_ya_apilado(pfasm, info->tipo);
                }
*/
                }
#line 1827 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 290 "alfa.y" /* yacc.c:1646  */
    {fprintf(file,";R56:\t<escritura> ::= printf <exp>\n");
                escribir(pfasm, (yyvsp[0].atributos).es_direccion, (yyvsp[0].atributos).tipo);}
#line 1834 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 293 "alfa.y" /* yacc.c:1646  */
    {fprintf(file,";R61:\t<retorno_funcion> ::= return <exp>\n");
                ASSERT_SEMANTICO(ambito_actual, "Sentencia de retorno fuera del cuerpo de una funcion", NULL);
                retornarFuncion(pfasm, (yyvsp[0].atributos).es_direccion);
                fn_return++;}
#line 1843 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 298 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(file,";R72:\t<exp> ::= <exp> + <exp>\n");
        sumar(pfasm, (yyvsp[-2].atributos).es_direccion, (yyvsp[0].atributos).es_direccion);
        /* Propaga correctamente los atributos */
        (yyval.atributos).tipo = ENTERO;
        (yyval.atributos).es_direccion = 0;}
#line 1854 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 304 "alfa.y" /* yacc.c:1646  */
    {fprintf(file,";R73:\t<exp> ::= <exp> - <exp>\n");			}
#line 1860 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 305 "alfa.y" /* yacc.c:1646  */
    {fprintf(file,";R74:\t<exp> ::= <exp> / <exp>\n");			}
#line 1866 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 306 "alfa.y" /* yacc.c:1646  */
    {fprintf(file,";R75:\t<exp> ::= <exp> * <exp>\n");			}
#line 1872 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 307 "alfa.y" /* yacc.c:1646  */
    {fprintf(file,";R76:\t<exp> ::= - <exp>\n");			}
#line 1878 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 308 "alfa.y" /* yacc.c:1646  */
    { fprintf(file,";R77:\t<exp> ::= <exp> && <exp>\n");			}
#line 1884 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 309 "alfa.y" /* yacc.c:1646  */
    {			fprintf(file,";R78:\t<exp> ::= <exp> || <exp>\n");			}
#line 1890 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 310 "alfa.y" /* yacc.c:1646  */
    {			fprintf(file,";R79:\t<exp> ::= ! <exp>\n");			}
#line 1896 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 311 "alfa.y" /* yacc.c:1646  */
    {			fprintf(file,";R80:\t<exp> ::= <identificador>\n");			}
#line 1902 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 312 "alfa.y" /* yacc.c:1646  */
    {			fprintf(file,";R81:\t<exp> ::= <constante>\n");
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
        apilar_constante(pfasm, (yyvsp[0].atributos).valor_entero);

        printf("%d-%d-%d\n",
        (yyval.atributos).tipo,
        (yyval.atributos).es_direccion,
        (yyvsp[0].atributos).valor_entero);}
#line 1916 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 321 "alfa.y" /* yacc.c:1646  */
    {			fprintf(file,";R82:\t<exp> ::= ( <exp> )\n");}
#line 1922 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 322 "alfa.y" /* yacc.c:1646  */
    {fprintf(file,";R83:\t<exp> ::= ( <comparacion> )\n");}
#line 1928 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 323 "alfa.y" /* yacc.c:1646  */
    {fprintf(file,";R85:\t<exp> ::= <elemento_vector>\n");}
#line 1934 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 324 "alfa.y" /* yacc.c:1646  */
    { fprintf(file,";R88:\t<exp> ::= <identificador> ( <lista_expresiones> )\n");}
#line 1940 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 326 "alfa.y" /* yacc.c:1646  */
    {
			fprintf(file,";R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
			}
#line 1948 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 329 "alfa.y" /* yacc.c:1646  */
    {
			fprintf(file,";R90:\t<lista_expresiones> ::=\n");
			}
#line 1956 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 332 "alfa.y" /* yacc.c:1646  */
    {			fprintf(file,";R91:\t<resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>\n");			}
#line 1962 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 333 "alfa.y" /* yacc.c:1646  */
    {			fprintf(file,";R92:\t<resto_lista_expresiones> ::=\n");}
#line 1968 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 335 "alfa.y" /* yacc.c:1646  */
    {			fprintf(file,";R93:\t<comparacion> ::= <exp> == <exp>\n");			}
#line 1974 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 336 "alfa.y" /* yacc.c:1646  */
    {			fprintf(file,";R94:\t<comparacion> ::= <exp> != <exp>\n");			}
#line 1980 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 337 "alfa.y" /* yacc.c:1646  */
    {			fprintf(file,";R95:\t<comparacion> ::= <exp> <= <exp>\n");			}
#line 1986 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 338 "alfa.y" /* yacc.c:1646  */
    {			fprintf(file,";R96:\t<comparacion> ::= <exp> >= <exp>\n");			}
#line 1992 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 339 "alfa.y" /* yacc.c:1646  */
    {			fprintf(file,";R97:\t<comparacion> ::= <exp> < <exp>\n");			}
#line 1998 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 340 "alfa.y" /* yacc.c:1646  */
    {			fprintf(file,";R98:\t<comparacion> ::= <exp> > <exp>\n");			}
#line 2004 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 341 "alfa.y" /* yacc.c:1646  */
    {    			fprintf(file,";R99:\t<constante> ::= <constante_logica>\n");
          (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
          (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
          (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
      }
#line 2014 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 346 "alfa.y" /* yacc.c:1646  */
    {
  			fprintf(file,";R100:\t<constante> ::= <constante_entera>\n");
        (yyval.atributos).tipo = (yyvsp[0].atributos).tipo;
        (yyval.atributos).es_direccion = (yyvsp[0].atributos).es_direccion;
      }
#line 2024 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 351 "alfa.y" /* yacc.c:1646  */
    {
  			fprintf(file,"R102:\t<constante_logica> ::= true\n");
        (yyval.atributos).tipo = BOOLEANO;
        (yyval.atributos).es_direccion = 0;
        (yyval.atributos).valor_entero = 1;}
#line 2034 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 356 "alfa.y" /* yacc.c:1646  */
    {
        fprintf(file,"R103:\t<constante_logica> ::= false\n");
        (yyval.atributos).tipo = BOOLEANO;
        (yyval.atributos).es_direccion = 0;
        (yyval.atributos).valor_entero = 0;
      }
#line 2045 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 362 "alfa.y" /* yacc.c:1646  */
    {
                    fprintf(file,";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");
                    (yyval.atributos).tipo = ENTERO;
                    (yyval.atributos).es_direccion = 0;
                    (yyval.atributos).valor_entero = (yyvsp[0].atributos).valor_entero;
                  }
#line 2056 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 368 "alfa.y" /* yacc.c:1646  */
    {
                    fprintf(file,";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
                    (yyval.atributos) = (yyvsp[0].atributos);
                  }
#line 2065 "alfa.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 373 "alfa.y" /* yacc.c:1646  */
    {
                    fprintf(file,";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");
                            /* Añadimos al ambito actual */

                            if (0 == ambito_actual) {
                              INFO_SIMBOLO* info = get_SimbolByID_SoloGlobal((yyvsp[0].atributos).lexema);
                             ASSERT_SEMANTICO(NULL == info, "Declaracion duplicada", NULL);

                              ASSERT_SEMANTICO(info == NULL, "Declaracion duplicada", NULL);
                              declarar_global((yyvsp[0].atributos).lexema, tipo_actual, clase_actual, tamanio_vector_actual);
                              tamanio_vector_actual = 0;
                            } else {
                                INFO_SIMBOLO* info = uso_solo_local((yyvsp[0].atributos).lexema);

                              ASSERT_SEMANTICO(info == NULL, "Declaracion duplicada", NULL);
                                  ASSERT_SEMANTICO(clase_actual != VECTOR, "Variable local de tipo no escalar", NULL);
                              declarar_local((yyvsp[0].atributos).lexema, 0, tipo_actual, clase_actual, 0, pos_variable_local_actual);
                              num_variables_locales_actual++;
                             pos_variable_local_actual++;
                            }
                          }
#line 2091 "alfa.tab.c" /* yacc.c:1646  */
    break;


#line 2095 "alfa.tab.c" /* yacc.c:1646  */
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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 396 "alfa.y" /* yacc.c:1906  */

void yyerror(char const *s){
	if(aux==0){
		fprintf (stderr,"****Error sintactico en [lin %d, col %d, '%s']\n",row,column, s);
	}else{
		aux=0;
	}
}
