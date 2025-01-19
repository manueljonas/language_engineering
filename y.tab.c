/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/record.h"

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;
extern FILE * yyin, * yyout;

char * cat(char *, char *, char *, char *, char *, char *);
int labelCounterIf = 1; // Contador global para os rótulos goto if
int labelCounterIfElse = 1; // Contador global para os rótulos goto if-else
int labelCounterWhile = 1; // Contador global para os rótulos goto while
int labelCounterFor = 1; // Contador global para os rótulos goto for


#line 91 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    FUNCTION = 258,                /* FUNCTION  */
    END_FUNCTION = 259,            /* END_FUNCTION  */
    IF = 260,                      /* IF  */
    THEN = 261,                    /* THEN  */
    ELSE = 262,                    /* ELSE  */
    END_IF = 263,                  /* END_IF  */
    WHILE = 264,                   /* WHILE  */
    END_WHILE = 265,               /* END_WHILE  */
    FOR = 266,                     /* FOR  */
    END_FOR = 267,                 /* END_FOR  */
    ASSIGN = 268,                  /* ASSIGN  */
    MAIN = 269,                    /* MAIN  */
    END_MAIN = 270,                /* END_MAIN  */
    PRINT = 271,                   /* PRINT  */
    RETURN = 272,                  /* RETURN  */
    EQUALS = 273,                  /* EQUALS  */
    DIFF = 274,                    /* DIFF  */
    LESS = 275,                    /* LESS  */
    GREATER = 276,                 /* GREATER  */
    LESSEQUALS = 277,              /* LESSEQUALS  */
    GREATEREQUALS = 278,           /* GREATEREQUALS  */
    AND = 279,                     /* AND  */
    OR = 280,                      /* OR  */
    XOR = 281,                     /* XOR  */
    NOT = 282,                     /* NOT  */
    TYPE = 283,                    /* TYPE  */
    STRING_LIT = 284,              /* STRING_LIT  */
    BOOL_LIT = 285,                /* BOOL_LIT  */
    ID = 286,                      /* ID  */
    INT = 287,                     /* INT  */
    FLOAT = 288,                   /* FLOAT  */
    DOUBLE = 289,                  /* DOUBLE  */
    INCREMENT = 290,               /* INCREMENT  */
    DECREMENT = 291,               /* DECREMENT  */
    INCREMENT_ASSIGN = 292,        /* INCREMENT_ASSIGN  */
    DECREMENT_ASSIGN = 293,        /* DECREMENT_ASSIGN  */
    PLUS = 294,                    /* PLUS  */
    MINUS = 295,                   /* MINUS  */
    MULT = 296,                    /* MULT  */
    DIVISION = 297,                /* DIVISION  */
    EXPOENT = 298                  /* EXPOENT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 21 "parser.y"

	char * sValue;         // string value
	struct record * rec;
 

#line 190 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FUNCTION = 3,                   /* FUNCTION  */
  YYSYMBOL_END_FUNCTION = 4,               /* END_FUNCTION  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_THEN = 6,                       /* THEN  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_END_IF = 8,                     /* END_IF  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_END_WHILE = 10,                 /* END_WHILE  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_END_FOR = 12,                   /* END_FOR  */
  YYSYMBOL_ASSIGN = 13,                    /* ASSIGN  */
  YYSYMBOL_MAIN = 14,                      /* MAIN  */
  YYSYMBOL_END_MAIN = 15,                  /* END_MAIN  */
  YYSYMBOL_PRINT = 16,                     /* PRINT  */
  YYSYMBOL_RETURN = 17,                    /* RETURN  */
  YYSYMBOL_EQUALS = 18,                    /* EQUALS  */
  YYSYMBOL_DIFF = 19,                      /* DIFF  */
  YYSYMBOL_LESS = 20,                      /* LESS  */
  YYSYMBOL_GREATER = 21,                   /* GREATER  */
  YYSYMBOL_LESSEQUALS = 22,                /* LESSEQUALS  */
  YYSYMBOL_GREATEREQUALS = 23,             /* GREATEREQUALS  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_XOR = 26,                       /* XOR  */
  YYSYMBOL_NOT = 27,                       /* NOT  */
  YYSYMBOL_TYPE = 28,                      /* TYPE  */
  YYSYMBOL_STRING_LIT = 29,                /* STRING_LIT  */
  YYSYMBOL_BOOL_LIT = 30,                  /* BOOL_LIT  */
  YYSYMBOL_ID = 31,                        /* ID  */
  YYSYMBOL_INT = 32,                       /* INT  */
  YYSYMBOL_FLOAT = 33,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 34,                    /* DOUBLE  */
  YYSYMBOL_INCREMENT = 35,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 36,                 /* DECREMENT  */
  YYSYMBOL_INCREMENT_ASSIGN = 37,          /* INCREMENT_ASSIGN  */
  YYSYMBOL_DECREMENT_ASSIGN = 38,          /* DECREMENT_ASSIGN  */
  YYSYMBOL_PLUS = 39,                      /* PLUS  */
  YYSYMBOL_MINUS = 40,                     /* MINUS  */
  YYSYMBOL_MULT = 41,                      /* MULT  */
  YYSYMBOL_DIVISION = 42,                  /* DIVISION  */
  YYSYMBOL_EXPOENT = 43,                   /* EXPOENT  */
  YYSYMBOL_44_ = 44,                       /* '('  */
  YYSYMBOL_45_ = 45,                       /* ')'  */
  YYSYMBOL_46_ = 46,                       /* ';'  */
  YYSYMBOL_47_ = 47,                       /* ','  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_prog = 49,                      /* prog  */
  YYSYMBOL_subprogs = 50,                  /* subprogs  */
  YYSYMBOL_subprog = 51,                   /* subprog  */
  YYSYMBOL_args_op = 52,                   /* args_op  */
  YYSYMBOL_args = 53,                      /* args  */
  YYSYMBOL_arg = 54,                       /* arg  */
  YYSYMBOL_ids = 55,                       /* ids  */
  YYSYMBOL_main = 56,                      /* main  */
  YYSYMBOL_cmds = 57,                      /* cmds  */
  YYSYMBOL_cmd = 58,                       /* cmd  */
  YYSYMBOL_cond = 59,                      /* cond  */
  YYSYMBOL_return = 60,                    /* return  */
  YYSYMBOL_write = 61,                     /* write  */
  YYSYMBOL_iteration = 62,                 /* iteration  */
  YYSYMBOL_for_init = 63,                  /* for_init  */
  YYSYMBOL_for_init_declaration = 64,      /* for_init_declaration  */
  YYSYMBOL_for_cond = 65,                  /* for_cond  */
  YYSYMBOL_for_incr = 66,                  /* for_incr  */
  YYSYMBOL_exp = 67,                       /* exp  */
  YYSYMBOL_term = 68,                      /* term  */
  YYSYMBOL_factor = 69,                    /* factor  */
  YYSYMBOL_call = 70,                      /* call  */
  YYSYMBOL_exps_op = 71,                   /* exps_op  */
  YYSYMBOL_exps = 72                       /* exps  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   386

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  172

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      44,    45,     2,     2,    47,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    46,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    51,    51,    61,    62,    70,    83,    84,    87,    88,
      96,   102,   111,   116,   123,   124,   132,   133,   134,   135,
     136,   143,   149,   156,   162,   167,   174,   180,   186,   192,
     198,   205,   214,   240,   277,   284,   291,   317,   356,   398,
     406,   415,   432,   438,   445,   452,   459,   466,   472,   473,
     474,   478,   483,   488,   493,   498,   503,   508,   513,   518,
     523,   527,   532,   537,   542,   547,   554,   557,   559,   561,
     563,   565,   567,   571,   579,   580,   583,   584
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "FUNCTION",
  "END_FUNCTION", "IF", "THEN", "ELSE", "END_IF", "WHILE", "END_WHILE",
  "FOR", "END_FOR", "ASSIGN", "MAIN", "END_MAIN", "PRINT", "RETURN",
  "EQUALS", "DIFF", "LESS", "GREATER", "LESSEQUALS", "GREATEREQUALS",
  "AND", "OR", "XOR", "NOT", "TYPE", "STRING_LIT", "BOOL_LIT", "ID", "INT",
  "FLOAT", "DOUBLE", "INCREMENT", "DECREMENT", "INCREMENT_ASSIGN",
  "DECREMENT_ASSIGN", "PLUS", "MINUS", "MULT", "DIVISION", "EXPOENT",
  "'('", "')'", "';'", "','", "$accept", "prog", "subprogs", "subprog",
  "args_op", "args", "arg", "ids", "main", "cmds", "cmd", "cond", "return",
  "write", "iteration", "for_init", "for_init_declaration", "for_cond",
  "for_incr", "exp", "term", "factor", "call", "exps_op", "exps", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-72)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -14,    13,    28,    21,   -14,     6,   -72,    37,   -72,   -72,
       1,   320,     3,     5,    11,   320,   320,   328,   -72,   -72,
      49,   -72,   -72,   -72,    19,    26,   320,    41,    37,   -72,
     -72,   -72,   -72,   112,   -72,   -72,   -72,    30,    15,    77,
     320,    -1,   320,   181,   -72,    -6,   142,   320,    14,    17,
     320,   320,   320,    29,    32,   266,   -72,   -72,   -21,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -72,    37,    43,    16,   -72,    33,    37,   294,
      51,    67,    42,    44,   151,    47,   -72,   320,   -72,    37,
     190,   -72,   -72,   219,   228,    59,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,    58,    37,    30,
      25,    37,    76,   320,   320,   320,   320,    60,   257,   -72,
     -72,   -72,   -72,   -72,    30,   103,   -72,    37,   -72,    98,
     320,   303,    63,   303,    65,   -72,   -72,   -72,   -72,   -72,
     113,   -72,   303,   -10,   -10,   -72,     8,    91,    92,    79,
     303,    80,   -72,   -72,   -72,   -72,    37,    37,   114,   115,
     -72,   -72
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     0,     3,     0,     1,    14,     2,     4,
       0,     0,     0,     0,     0,     0,     0,     0,    72,    71,
      67,    68,    69,    70,     0,     0,     0,     0,    14,    16,
      17,    18,    19,     0,    48,    66,    49,     6,    67,     0,
       0,     0,     0,     0,    60,    67,     0,     0,     0,     0,
       0,     0,    74,     0,     0,     0,    13,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,     0,     0,     0,     7,     8,    14,     0,
       0,    40,     0,     0,    76,     0,    34,     0,    21,     0,
       0,    26,    27,     0,     0,     0,    75,    28,    29,    50,
      67,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      61,    62,    63,    64,    65,    23,    12,    10,    14,     0,
       0,    14,     0,     0,     0,     0,     0,     0,     0,    22,
      25,    30,    31,    73,     0,     0,     9,    14,    32,     0,
       0,    39,     0,    42,     0,    77,    35,    20,    11,     5,
       0,    36,    41,     0,     0,    33,    67,     0,     0,     0,
      47,     0,    43,    44,    45,    46,    14,    14,     0,     0,
      37,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -72,   -72,   124,   -72,   -72,    22,    10,   -72,   -72,   -27,
     -71,   -72,   -72,   -72,   -72,   -72,   -72,    20,    -8,   -11,
     315,   -72,   -72,   -72,   -49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    75,    76,    77,   117,     8,    27,
      28,    29,    30,    31,    32,    82,    83,   142,   159,    33,
      34,    35,    36,    95,    85
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      39,    57,   115,    96,    43,    44,    46,    87,    18,    19,
     100,    21,    22,    23,     1,    55,     5,    16,   129,    18,
      19,   156,    21,    22,    23,   157,   158,    80,     6,    79,
      81,    84,   137,   138,    26,     7,    90,    10,    52,    93,
      94,    84,    11,   162,   163,    37,    12,    40,    13,    41,
      53,   120,    52,    14,    15,    42,    56,    54,    74,    52,
      91,   118,    47,    92,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,   116,    97,   128,   145,    98,   119,
     123,    26,   122,    78,    48,    49,    50,    51,   124,   140,
     125,   135,   127,    52,   139,    58,    59,    60,    61,    62,
      63,    64,    65,    66,   133,   134,   146,   149,   151,   153,
     150,   154,   141,   143,   143,    84,    67,    68,    69,    70,
      71,   155,   164,   165,   166,   167,   170,   171,     9,   152,
      58,    59,    60,    61,    62,    63,    64,    65,    66,   168,
     169,   136,   160,   160,   148,   144,   161,     0,     0,     0,
       0,    67,    68,    69,    70,    71,     0,     0,    72,    73,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,     0,
       0,    67,    68,    69,    70,    71,     0,     0,    88,    89,
      67,    68,    69,    70,    71,     0,     0,     0,   126,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,     0,
      67,    68,    69,    70,    71,     0,     0,    86,     0,    67,
      68,    69,    70,    71,     0,     0,   130,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     0,     0,    67,    68,
      69,    70,    71,     0,     0,   131,     0,    67,    68,    69,
      70,    71,     0,     0,   132,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,     0,     0,    67,    68,    69,    70,
      71,     0,     0,   147,     0,    67,    68,    69,    70,    71,
       0,    99,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,     0,     0,    67,    68,    69,    70,    71,     0,   121,
       0,     0,    67,    68,    69,    70,    71,    16,     0,    18,
      19,    38,    21,    22,    23,    16,     0,    18,    19,    45,
      21,    22,    23,     0,    26,     0,     0,     0,     0,     0,
       0,     0,    26,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114
};

static const yytype_int16 yycheck[] =
{
      11,    28,    73,    52,    15,    16,    17,    13,    29,    30,
      31,    32,    33,    34,    28,    26,     3,    27,    89,    29,
      30,    31,    32,    33,    34,    35,    36,    28,     0,    40,
      31,    42,     7,     8,    44,    14,    47,    31,    44,    50,
      51,    52,     5,    35,    36,    44,     9,    44,    11,    44,
      31,    78,    44,    16,    17,    44,    15,    31,    28,    44,
      46,    45,    13,    46,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    31,    46,    87,   126,    46,    46,
      13,    44,    31,     6,    35,    36,    37,    38,    46,    13,
      46,   118,    45,    44,   121,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    45,    47,    46,     4,    10,    46,
     137,    46,   123,   124,   125,   126,    39,    40,    41,    42,
      43,     8,    31,    31,    45,    45,    12,    12,     4,   140,
      18,    19,    20,    21,    22,    23,    24,    25,    26,   166,
     167,   119,   153,   154,   134,   125,   154,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    -1,    -1,    46,    47,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    -1,    -1,    46,    47,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    47,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    -1,    -1,    46,    -1,    39,
      40,    41,    42,    43,    -1,    -1,    46,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    39,    40,    41,
      42,    43,    -1,    -1,    46,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    39,    40,    41,    42,    43,
      -1,    45,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    39,    40,    41,    42,    43,    -1,    45,
      -1,    -1,    39,    40,    41,    42,    43,    27,    -1,    29,
      30,    31,    32,    33,    34,    27,    -1,    29,    30,    31,
      32,    33,    34,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    44,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    28,    49,    50,    51,     3,     0,    14,    56,    50,
      31,     5,     9,    11,    16,    17,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    44,    57,    58,    59,
      60,    61,    62,    67,    68,    69,    70,    44,    31,    67,
      44,    44,    44,    67,    67,    31,    67,    13,    35,    36,
      37,    38,    44,    31,    31,    67,    15,    57,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    39,    40,    41,
      42,    43,    46,    47,    28,    52,    53,    54,     6,    67,
      28,    31,    63,    64,    67,    72,    46,    13,    46,    47,
      67,    46,    46,    67,    67,    71,    72,    46,    46,    45,
      31,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    58,    31,    55,    45,    46,
      57,    45,    31,    13,    46,    46,    47,    45,    67,    58,
      46,    46,    46,    45,    47,    57,    53,     7,     8,    57,
      13,    67,    65,    67,    65,    72,    46,    46,    54,     4,
      57,    10,    67,    46,    46,     8,    31,    35,    36,    66,
      67,    66,    35,    36,    31,    31,    45,    45,    57,    57,
      12,    12
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    52,    52,    53,    53,
      54,    54,    55,    56,    57,    57,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    59,    59,    60,    61,    62,    62,    62,    63,
      63,    64,    65,    66,    66,    66,    66,    66,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    68,    69,    69,    69,
      69,    69,    69,    70,    71,    71,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     8,     0,     1,     1,     3,
       2,     4,     1,     3,     0,     2,     1,     1,     1,     1,
       5,     3,     4,     3,     2,     4,     3,     3,     3,     3,
       4,     4,     5,     7,     3,     5,     6,    10,    10,     3,
       1,     4,     1,     2,     2,     2,     2,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     4,     0,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* prog: subprogs main  */
#line 51 "parser.y"
                     {
                      char *headers = "#include<stdio.h>\n#include<stdlib.h>\n#include<stdbool.h>\n#include<math.h>\n\n";
                      char *s = cat(headers, (yyvsp[-1].rec)->code, "\n", (yyvsp[0].rec)->code, "", "");
                      fprintf(yyout, "%s", s);
                      freeRecord((yyvsp[-1].rec));
                      freeRecord((yyvsp[0].rec));
                      free(s);                          
                     }
#line 1399 "y.tab.c"
    break;

  case 3: /* subprogs: %empty  */
#line 61 "parser.y"
                            {(yyval.rec) = createRecord("","");}
#line 1405 "y.tab.c"
    break;

  case 4: /* subprogs: subprog subprogs  */
#line 62 "parser.y"
                            {char * s = cat((yyvsp[-1].rec)->code, "\n", (yyvsp[0].rec)->code, "", "", "");
                             freeRecord((yyvsp[-1].rec));
                             freeRecord((yyvsp[0].rec));
                             (yyval.rec) = createRecord(s, "");
                             free(s);
                            }
#line 1416 "y.tab.c"
    break;

  case 5: /* subprog: TYPE FUNCTION ID '(' args_op ')' cmds END_FUNCTION  */
#line 71 "parser.y"
           {char * s1 = cat((yyvsp[-7].sValue), " ", (yyvsp[-5].sValue), "(", (yyvsp[-3].rec)->code, "");
            char * s2 = cat(s1, ")\n", "{\n", (yyvsp[-1].rec)->code, "}", "");
            free(s1);
            free((yyvsp[-7].sValue));
            free((yyvsp[-5].sValue));
            freeRecord((yyvsp[-3].rec));
            freeRecord((yyvsp[-1].rec));
            (yyval.rec) = createRecord(s2, "");
            free(s2);
           }
#line 1431 "y.tab.c"
    break;

  case 6: /* args_op: %empty  */
#line 83 "parser.y"
                {(yyval.rec) = createRecord("","");}
#line 1437 "y.tab.c"
    break;

  case 7: /* args_op: args  */
#line 84 "parser.y"
                {(yyval.rec) = (yyvsp[0].rec);}
#line 1443 "y.tab.c"
    break;

  case 8: /* args: arg  */
#line 87 "parser.y"
                    {(yyval.rec) = (yyvsp[0].rec);}
#line 1449 "y.tab.c"
    break;

  case 9: /* args: arg ';' args  */
#line 88 "parser.y"
                    {char * s = cat((yyvsp[-2].rec)->code, "; ", (yyvsp[0].rec)->code, "", "", "");
                     freeRecord((yyvsp[-2].rec));
                     freeRecord((yyvsp[0].rec));
                     (yyval.rec) = createRecord(s, "");
                     free(s);
                    }
#line 1460 "y.tab.c"
    break;

  case 10: /* arg: TYPE ids  */
#line 96 "parser.y"
               {char * s = cat((yyvsp[-1].sValue), " ", (yyvsp[0].rec)->code, "", "", "");
                free((yyvsp[-1].sValue));
                freeRecord((yyvsp[0].rec));
                (yyval.rec) = createRecord(s, "");
                free(s);
               }
#line 1471 "y.tab.c"
    break;

  case 11: /* arg: TYPE ids ',' arg  */
#line 102 "parser.y"
                         {char * s = cat((yyvsp[-3].sValue), " ", (yyvsp[-2].rec)->code, ", ", (yyvsp[0].rec)->code, "");
                free((yyvsp[-3].sValue));
                freeRecord((yyvsp[-2].rec));
                freeRecord((yyvsp[0].rec));
                (yyval.rec) = createRecord(s, "");
                free(s);
               }
#line 1483 "y.tab.c"
    break;

  case 12: /* ids: ID  */
#line 111 "parser.y"
                 {(yyval.rec) = createRecord((yyvsp[0].sValue), "");
                  free((yyvsp[0].sValue));
                 }
#line 1491 "y.tab.c"
    break;

  case 13: /* main: MAIN cmds END_MAIN  */
#line 116 "parser.y"
                          {char * s = cat("int main(){\n", (yyvsp[-1].rec)->code, "}", "", "", "");
                                  freeRecord((yyvsp[-1].rec));
                                  (yyval.rec) = createRecord(s, "");
                                  free(s);
                                 }
#line 1501 "y.tab.c"
    break;

  case 14: /* cmds: %empty  */
#line 123 "parser.y"
                 {(yyval.rec) = createRecord("","");}
#line 1507 "y.tab.c"
    break;

  case 15: /* cmds: cmd cmds  */
#line 124 "parser.y"
                 {char * s = cat((yyvsp[-1].rec)->code, "\n", (yyvsp[0].rec)->code, "", "", "");
                  freeRecord((yyvsp[-1].rec));
                  freeRecord((yyvsp[0].rec));
                  (yyval.rec) = createRecord(s, "");
                  free(s);
                 }
#line 1518 "y.tab.c"
    break;

  case 16: /* cmd: cond  */
#line 132 "parser.y"
                                {(yyval.rec) = (yyvsp[0].rec);}
#line 1524 "y.tab.c"
    break;

  case 17: /* cmd: return  */
#line 133 "parser.y"
                                {(yyval.rec) = (yyvsp[0].rec);}
#line 1530 "y.tab.c"
    break;

  case 18: /* cmd: write  */
#line 134 "parser.y"
                                {(yyval.rec) = (yyvsp[0].rec);}
#line 1536 "y.tab.c"
    break;

  case 19: /* cmd: iteration  */
#line 135 "parser.y"
                                {(yyval.rec) = (yyvsp[0].rec);}
#line 1542 "y.tab.c"
    break;

  case 20: /* cmd: TYPE ID ASSIGN exp ';'  */
#line 136 "parser.y"
                             {char * s = cat((yyvsp[-4].sValue), " ", (yyvsp[-3].sValue), " = ", (yyvsp[-1].rec)->code, ";");
                              free((yyvsp[-4].sValue));
                              free((yyvsp[-3].sValue));
                              freeRecord((yyvsp[-1].rec));
                              (yyval.rec) = createRecord(s, "");
                              free(s);
      }
#line 1554 "y.tab.c"
    break;

  case 21: /* cmd: TYPE exp ';'  */
#line 143 "parser.y"
                   {char * s = cat((yyvsp[-2].sValue), " ", (yyvsp[-1].rec)->code, ";", "", "");
                     free((yyvsp[-2].sValue));
                     freeRecord((yyvsp[-1].rec));
                     (yyval.rec) = createRecord(s, "");
                     free(s);
                    }
#line 1565 "y.tab.c"
    break;

  case 22: /* cmd: TYPE exp ',' cmd  */
#line 149 "parser.y"
                       {char * s = cat((yyvsp[-3].sValue), " ", (yyvsp[-2].rec)->code, ", ", (yyvsp[0].rec)->code, "");
                        free((yyvsp[-3].sValue));
                        freeRecord((yyvsp[-2].rec));
                        freeRecord((yyvsp[0].rec));
                        (yyval.rec) = createRecord(s, "");
                        free(s);
                       }
#line 1577 "y.tab.c"
    break;

  case 23: /* cmd: exp ',' cmd  */
#line 156 "parser.y"
                  {char * s = cat((yyvsp[-2].rec)->code, ", ", (yyvsp[0].rec)->code, "", "", "");
                        freeRecord((yyvsp[-2].rec));
                        freeRecord((yyvsp[0].rec));
                        (yyval.rec) = createRecord(s, "");
                        free(s);
                       }
#line 1588 "y.tab.c"
    break;

  case 24: /* cmd: exp ';'  */
#line 162 "parser.y"
              {char * s = cat((yyvsp[-1].rec)->code, ";", "", "", "", "");
                freeRecord((yyvsp[-1].rec));
                (yyval.rec) = createRecord(s, "");
                free(s);
               }
#line 1598 "y.tab.c"
    break;

  case 25: /* cmd: ID ASSIGN exp ';'  */
#line 167 "parser.y"
                        { 
         char *s = cat((yyvsp[-3].sValue), " = ", (yyvsp[-1].rec)->code, ";", "", "");
         free((yyvsp[-3].sValue));
         freeRecord((yyvsp[-1].rec));
         (yyval.rec) = createRecord(s, "");
         free(s);
      }
#line 1610 "y.tab.c"
    break;

  case 26: /* cmd: ID INCREMENT ';'  */
#line 174 "parser.y"
                       { 
         char *s = cat((yyvsp[-2].sValue), "++", ";", "", "", "");
         free((yyvsp[-2].sValue));
         (yyval.rec) = createRecord(s, "");
         free(s);
      }
#line 1621 "y.tab.c"
    break;

  case 27: /* cmd: ID DECREMENT ';'  */
#line 180 "parser.y"
                       { 
         char *s = cat((yyvsp[-2].sValue), "--", ";", "", "", "");
         free((yyvsp[-2].sValue));
         (yyval.rec) = createRecord(s, "");
         free(s);
      }
#line 1632 "y.tab.c"
    break;

  case 28: /* cmd: INCREMENT ID ';'  */
#line 186 "parser.y"
                       { 
         char *s = cat("++", (yyvsp[-1].sValue), ";", "", "", "");
         free((yyvsp[-1].sValue));
         (yyval.rec) = createRecord(s, "");
         free(s);
      }
#line 1643 "y.tab.c"
    break;

  case 29: /* cmd: DECREMENT ID ';'  */
#line 192 "parser.y"
                       { 
         char *s = cat("--", (yyvsp[-1].sValue), ";", "", "", "");
         free((yyvsp[-1].sValue));
         (yyval.rec) = createRecord(s, "");
         free(s);
      }
#line 1654 "y.tab.c"
    break;

  case 30: /* cmd: ID INCREMENT_ASSIGN exp ';'  */
#line 198 "parser.y"
                                  { 
         char *s = cat((yyvsp[-3].sValue), " += ", (yyvsp[-1].rec)->code, ";", "", "");
         free((yyvsp[-3].sValue));
         freeRecord((yyvsp[-1].rec));
         (yyval.rec) = createRecord(s, "");
         free(s);
      }
#line 1666 "y.tab.c"
    break;

  case 31: /* cmd: ID DECREMENT_ASSIGN exp ';'  */
#line 205 "parser.y"
                                  { 
         char *s = cat((yyvsp[-3].sValue), " -= ", (yyvsp[-1].rec)->code, ";", "", "");
         free((yyvsp[-3].sValue));
         freeRecord((yyvsp[-1].rec));
         (yyval.rec) = createRecord(s, "");
         free(s);
      }
#line 1678 "y.tab.c"
    break;

  case 32: /* cond: IF exp THEN cmds END_IF  */
#line 215 "parser.y"
      {
        // Incrementa o contador global
        int currentLabelIf = labelCounterIf++;
        
        // Gera rótulos únicos com base no contador
        char labelIf[30];
        char labelEndIf[30];
        snprintf(labelIf, sizeof(labelIf), "goto_if_%d", currentLabelIf);
        snprintf(labelEndIf, sizeof(labelEndIf), "goto_end_if_%d", currentLabelIf);

        // Etapa 1: Concatena até o "goto labelIf"
        char *part1 = cat("if ", (yyvsp[-3].rec)->code, " {\n goto ", labelIf, "; \n", "");

        // Etapa 2: Concatena o "goto labelEndIf" e abre o bloco de código
        char *part2 = cat("} \n goto ", labelEndIf, "; \n", labelIf, ": \n", (yyvsp[-1].rec)->code);

        // Etapa 3: Concatena o final com o "goto_end_if"
        char *s = cat(part1, part2, labelEndIf, ": \n", "", "");
        free(part1);
        free(part2);
        freeRecord((yyvsp[-3].rec));
        freeRecord((yyvsp[-1].rec));
        (yyval.rec) = createRecord(s, "");
        free(s);
      }
#line 1708 "y.tab.c"
    break;

  case 33: /* cond: IF exp THEN cmds ELSE cmds END_IF  */
#line 241 "parser.y"
      {
        // Incrementa o contador global
        int currentLabelIfElse = labelCounterIfElse++;
        
        // Gera rótulos únicos com base no contador
        char labelIf[30];
        char labelElse[30];
        char labelEndIfElse[30];
        snprintf(labelIf, sizeof(labelIf), "goto_if_c_%d", currentLabelIfElse);
        snprintf(labelElse, sizeof(labelElse), "goto_else_c_%d", currentLabelIfElse);
        snprintf(labelEndIfElse, sizeof(labelEndIfElse), "goto_end_if_else_%d", currentLabelIfElse);

        // Etapa 1: Concatena a condição e os rótulos de "then" e "else"
        char *part1 = cat("if ", (yyvsp[-5].rec)->code, " {\n goto ", labelIf, "; \n", "");
        char *part2 = cat("} \n goto ", labelElse, "; \n", "", "", "");

        // Etapa 2: Concatena o bloco "then" com o rótulo de fim
        char *part3 = cat(labelIf, ": \n", (yyvsp[-3].rec)->code, "goto ", labelEndIfElse, "; \n");

        // Etapa 3: Concatena o bloco "else" e o rótulo de fim
        char *part4 = cat(labelElse, ": \n", (yyvsp[-1].rec)->code, labelEndIfElse, ": \n", "");

        // Concatenar as partes do código gerado
        char *s = cat(part1, part2, part3, part4, "", "");
        free(part1);
        free(part2);
        free(part3);
        free(part4);
        freeRecord((yyvsp[-5].rec));
        freeRecord((yyvsp[-3].rec));
        freeRecord((yyvsp[-1].rec));
        (yyval.rec) = createRecord(s, "");
        free(s);
      }
#line 1747 "y.tab.c"
    break;

  case 34: /* return: RETURN exp ';'  */
#line 277 "parser.y"
                        {char * s = cat("return ", (yyvsp[-1].rec)->code, ";", "", "", "");
                         freeRecord((yyvsp[-1].rec));
                         (yyval.rec) = createRecord(s, "");
                         free(s);
                        }
#line 1757 "y.tab.c"
    break;

  case 35: /* write: PRINT '(' exps ')' ';'  */
#line 284 "parser.y"
                               {char * s = cat("printf", "(", (yyvsp[-2].rec)->code, ")", ";", "");
                                  freeRecord((yyvsp[-2].rec));
                                  (yyval.rec) = createRecord(s, "");
                                  free(s);
                                 }
#line 1767 "y.tab.c"
    break;

  case 36: /* iteration: WHILE '(' exp ')' cmds END_WHILE  */
#line 292 "parser.y"
    {
        // Incrementar o contador de rótulos para gerar identificadores únicos
        int currentLabelWhile = labelCounterWhile++;
        char labelStart[30], labelEnd[30], labelBody[30];

        // Criar rótulos únicos com base no contador
        snprintf(labelStart, sizeof(labelStart), "label_while_start_%d", currentLabelWhile);
        snprintf(labelEnd, sizeof(labelEnd), "label_while_end_%d", currentLabelWhile);
        snprintf(labelBody, sizeof(labelBody), "label_while_body_%d", currentLabelWhile);

        // Gerar as partes do código do bloco WHILE
        char *part1 = cat(labelStart, ": if ((", (yyvsp[-3].rec)->code, ")) goto ", labelBody, ";\n");
        char *part2 = cat("goto ", labelEnd, ";\n", labelBody, ":\n", (yyvsp[-1].rec)->code);
        char *part3 = cat("goto ", labelStart, ";\n", labelEnd, ": \n", "");

        // Concatenar todas as partes do código gerado
        char *s = cat(part1, part2, part3, "", "", "");
        free(part1);
        free(part2);
        free(part3);
        freeRecord((yyvsp[-3].rec));
        freeRecord((yyvsp[-1].rec));
        (yyval.rec) = createRecord(s, "");
        free(s);
    }
#line 1797 "y.tab.c"
    break;

  case 37: /* iteration: FOR '(' for_init ';' for_cond ';' for_incr ')' cmds END_FOR  */
#line 318 "parser.y"
    {
        // Gerar rótulos únicos para o laço
        int currentLabelFor = labelCounterFor++;
        char labelStart[30], labelEnd[30], labelBody[30];

        snprintf(labelStart, sizeof(labelStart), "label_for_start_%d", currentLabelFor);
        snprintf(labelEnd, sizeof(labelEnd), "label_for_end_%d", currentLabelFor);
        snprintf(labelBody, sizeof(labelBody), "label_for_body_%d", currentLabelFor);

        // Inicialização
        char *init = cat((yyvsp[-7].rec)->code, ";\n", "", "", "", "");

        // Condição (ajustada para if ((...) em vez de if (!(...))
        char *cond = cat("if ((", (yyvsp[-5].rec)->code, ")) goto ", labelBody, ";\n", "");
        char *skipToEnd = cat("goto ", labelEnd, ";\n", "", "", "");

        // Incremento
        char *increment = cat((yyvsp[-3].rec)->code, ";\n", "", "", "", "");

        // Combinar as partes do laço
        char *part1 = cat(init, labelStart, ": ", cond, skipToEnd, "");
        char *part2 = cat(labelBody, ":\n", (yyvsp[-1].rec)->code, "\n", increment, ";\n");
        char *part3 = cat("goto ", labelStart, ";\n", labelEnd, ": \n", "");

        char *s = cat(part1, part2, part3, "", "", "");
        free(init);
        free(cond);
        free(skipToEnd);
        free(part1);
        free(part2);
        free(part3);
        freeRecord((yyvsp[-7].rec));
        freeRecord((yyvsp[-5].rec));
        freeRecord((yyvsp[-3].rec));
        freeRecord((yyvsp[-1].rec));
        (yyval.rec) = createRecord(s, "");
        free(s);
    }
#line 1840 "y.tab.c"
    break;

  case 38: /* iteration: FOR '(' for_init_declaration ';' for_cond ';' for_incr ')' cmds END_FOR  */
#line 357 "parser.y"
    {
        // Gerar rótulos únicos para o laço
        int currentLabelFor = labelCounterFor++;
        char labelInit[30], labelStart[30], labelEnd[30], labelBody[30];

        snprintf(labelInit, sizeof(labelInit), "label_for_init_%d_", currentLabelFor);
        snprintf(labelStart, sizeof(labelStart), "label_for_start_%d", currentLabelFor);
        snprintf(labelEnd, sizeof(labelEnd), "label_for_end_%d", currentLabelFor);
        snprintf(labelBody, sizeof(labelBody), "label_for_body_%d", currentLabelFor);

        // Inicialização
        char *init = cat((yyvsp[-7].rec)->code, ";\n", "", "", "", "");

        // Condição (ajustada para if ((...) em vez de if (!(...))
        char *cond = cat("if ((", labelInit, (yyvsp[-5].rec)->code, ")) goto ", labelBody, ";\n");
        char *skipToEnd = cat("goto ", labelEnd, ";\n", "", "", "");

        // Incremento
        char *increment = cat(labelInit, (yyvsp[-3].rec)->code, ";\n", "", "", "");

        // Combinar as partes do laço
        char *part1 = cat(init, labelStart, ": ", cond, skipToEnd, "");
        char *part2 = cat(labelBody, ":\n", (yyvsp[-1].rec)->code, "\n", increment, ";\n");
        char *part3 = cat("goto ", labelStart, ";\n", labelEnd, ": \n", "");

        char *s = cat(part1, part2, part3, "", "", "");
        free(init);
        free(cond);
        free(skipToEnd);
        free(part1);
        free(part2);
        free(part3);
        freeRecord((yyvsp[-7].rec));
        freeRecord((yyvsp[-5].rec));
        freeRecord((yyvsp[-3].rec));
        freeRecord((yyvsp[-1].rec));
        (yyval.rec) = createRecord(s, "");
        free(s);
    }
#line 1884 "y.tab.c"
    break;

  case 39: /* for_init: ID ASSIGN exp  */
#line 399 "parser.y"
         {
            char *s = cat((yyvsp[-2].sValue), " = ", (yyvsp[0].rec)->code, "", "", "");
            free((yyvsp[-2].sValue));
            freeRecord((yyvsp[0].rec));
            (yyval.rec) = createRecord(s, "");
            free(s);
         }
#line 1896 "y.tab.c"
    break;

  case 40: /* for_init: ID  */
#line 407 "parser.y"
         {
            char *s = cat((yyvsp[0].sValue), "", "", "", "", "");
            free((yyvsp[0].sValue));
            (yyval.rec) = createRecord(s, "");
            free(s);
         }
#line 1907 "y.tab.c"
    break;

  case 41: /* for_init_declaration: TYPE ID ASSIGN exp  */
#line 416 "parser.y"
         {
            // Gerar rótulos únicos para o laço
            int currentLabelFor = labelCounterFor;
            char labelInit[30];

            snprintf(labelInit, sizeof(labelInit), "label_for_init_%d_", currentLabelFor);

            char *s = cat((yyvsp[-3].sValue), " ", labelInit, (yyvsp[-2].sValue), " = ", (yyvsp[0].rec)->code);
            free((yyvsp[-3].sValue));
            free((yyvsp[-2].sValue));
            freeRecord((yyvsp[0].rec));
            (yyval.rec) = createRecord(s, "");
            free(s);
         }
#line 1926 "y.tab.c"
    break;

  case 42: /* for_cond: exp  */
#line 433 "parser.y"
    {
        (yyval.rec) = (yyvsp[0].rec);
    }
#line 1934 "y.tab.c"
    break;

  case 43: /* for_incr: ID INCREMENT  */
#line 439 "parser.y"
    {
        char *s = cat((yyvsp[-1].sValue), "++", "", "", "", "");
        free((yyvsp[-1].sValue));
        (yyval.rec) = createRecord(s, "");
        free(s);
    }
#line 1945 "y.tab.c"
    break;

  case 44: /* for_incr: ID DECREMENT  */
#line 446 "parser.y"
    {
        char *s = cat((yyvsp[-1].sValue), "--", "", "", "", "");
        free((yyvsp[-1].sValue));
        (yyval.rec) = createRecord(s, "");
        free(s);
    }
#line 1956 "y.tab.c"
    break;

  case 45: /* for_incr: INCREMENT ID  */
#line 453 "parser.y"
    {
        char *s = cat("++", (yyvsp[0].sValue), "", "", "", "");
        free((yyvsp[0].sValue));
        (yyval.rec) = createRecord(s, "");
        free(s);
    }
#line 1967 "y.tab.c"
    break;

  case 46: /* for_incr: DECREMENT ID  */
#line 460 "parser.y"
    {
        char *s = cat("--", (yyvsp[0].sValue), "", "", "", "");
        free((yyvsp[0].sValue));
        (yyval.rec) = createRecord(s, "");
        free(s);
    }
#line 1978 "y.tab.c"
    break;

  case 47: /* for_incr: exp  */
#line 467 "parser.y"
    {
        (yyval.rec) = (yyvsp[0].rec);
    }
#line 1986 "y.tab.c"
    break;

  case 48: /* exp: term  */
#line 472 "parser.y"
                  {(yyval.rec) = (yyvsp[0].rec);}
#line 1992 "y.tab.c"
    break;

  case 49: /* exp: call  */
#line 473 "parser.y"
                  {(yyval.rec) = (yyvsp[0].rec);}
#line 1998 "y.tab.c"
    break;

  case 50: /* exp: '(' exp ')'  */
#line 474 "parser.y"
                  {char * s = cat("(", (yyvsp[-1].rec)->code, ")", "", "", "");
                   freeRecord((yyvsp[-1].rec));
                   (yyval.rec) = createRecord(s, "");
                   free(s);}
#line 2007 "y.tab.c"
    break;

  case 51: /* exp: exp EQUALS term  */
#line 478 "parser.y"
                        {char * s = cat((yyvsp[-2].rec)->code, " == ", (yyvsp[0].rec)->code, "", "", "");
                         freeRecord((yyvsp[-2].rec));
                         freeRecord((yyvsp[0].rec));
                         (yyval.rec) = createRecord(s, "");
                         free(s);}
#line 2017 "y.tab.c"
    break;

  case 52: /* exp: exp DIFF term  */
#line 483 "parser.y"
                      {char * s = cat((yyvsp[-2].rec)->code, " != ", (yyvsp[0].rec)->code, "", "", "");
                      freeRecord((yyvsp[-2].rec));
                      freeRecord((yyvsp[0].rec));
                      (yyval.rec) = createRecord(s, "");
                      free(s);}
#line 2027 "y.tab.c"
    break;

  case 53: /* exp: exp LESS term  */
#line 488 "parser.y"
                      {char * s = cat((yyvsp[-2].rec)->code, " < ", (yyvsp[0].rec)->code, "", "", "");
                      freeRecord((yyvsp[-2].rec));
                      freeRecord((yyvsp[0].rec));
                      (yyval.rec) = createRecord(s, "");
                      free(s);}
#line 2037 "y.tab.c"
    break;

  case 54: /* exp: exp GREATER term  */
#line 493 "parser.y"
                         {char * s = cat((yyvsp[-2].rec)->code, " > ", (yyvsp[0].rec)->code, "", "", "");
                         freeRecord((yyvsp[-2].rec));
                         freeRecord((yyvsp[0].rec));
                         (yyval.rec) = createRecord(s, "");
                         free(s);}
#line 2047 "y.tab.c"
    break;

  case 55: /* exp: exp LESSEQUALS term  */
#line 498 "parser.y"
                            {char * s = cat((yyvsp[-2].rec)->code, " <= ", (yyvsp[0].rec)->code, "", "", "");
                            freeRecord((yyvsp[-2].rec));
                            freeRecord((yyvsp[0].rec));
                            (yyval.rec) = createRecord(s, "");
                            free(s);}
#line 2057 "y.tab.c"
    break;

  case 56: /* exp: exp GREATEREQUALS term  */
#line 503 "parser.y"
                               {char * s = cat((yyvsp[-2].rec)->code, " >= ", (yyvsp[0].rec)->code, "", "", "");
                               freeRecord((yyvsp[-2].rec));
                               freeRecord((yyvsp[0].rec));
                               (yyval.rec) = createRecord(s, "");
                               free(s);}
#line 2067 "y.tab.c"
    break;

  case 57: /* exp: exp AND term  */
#line 508 "parser.y"
                     {char * s = cat((yyvsp[-2].rec)->code, " && ", (yyvsp[0].rec)->code, "", "", "");
                     freeRecord((yyvsp[-2].rec));
                     freeRecord((yyvsp[0].rec));
                     (yyval.rec) = createRecord(s, "");
                     free(s);}
#line 2077 "y.tab.c"
    break;

  case 58: /* exp: exp OR term  */
#line 513 "parser.y"
                    {char * s = cat((yyvsp[-2].rec)->code, " || ", (yyvsp[0].rec)->code, "", "", "");
                    freeRecord((yyvsp[-2].rec));
                    freeRecord((yyvsp[0].rec));
                    (yyval.rec) = createRecord(s, "");
                    free(s);}
#line 2087 "y.tab.c"
    break;

  case 59: /* exp: exp XOR term  */
#line 518 "parser.y"
                     {char * s = cat((yyvsp[-2].rec)->code, " ^ ", (yyvsp[0].rec)->code, "", "", "");
                     freeRecord((yyvsp[-2].rec));
                     freeRecord((yyvsp[0].rec));
                     (yyval.rec) = createRecord(s, "");
                     free(s);}
#line 2097 "y.tab.c"
    break;

  case 60: /* exp: NOT exp  */
#line 523 "parser.y"
                {char * s = cat("!", (yyvsp[0].rec)->code, "", "", "", "");
                  freeRecord((yyvsp[0].rec));
                  (yyval.rec) = createRecord(s, "");
                  free(s);}
#line 2106 "y.tab.c"
    break;

  case 61: /* exp: exp PLUS term  */
#line 527 "parser.y"
                      {char * s = cat((yyvsp[-2].rec)->code, " + ", (yyvsp[0].rec)->code, "", "", "");
                      freeRecord((yyvsp[-2].rec));
                      freeRecord((yyvsp[0].rec));
                      (yyval.rec) = createRecord(s, "");
                      free(s);}
#line 2116 "y.tab.c"
    break;

  case 62: /* exp: exp MINUS term  */
#line 532 "parser.y"
                       {char * s = cat((yyvsp[-2].rec)->code, " - ", (yyvsp[0].rec)->code, "", "", "");
                       freeRecord((yyvsp[-2].rec));
                       freeRecord((yyvsp[0].rec));
                       (yyval.rec) = createRecord(s, "");
                       free(s);}
#line 2126 "y.tab.c"
    break;

  case 63: /* exp: exp MULT term  */
#line 537 "parser.y"
                      {char * s = cat((yyvsp[-2].rec)->code, " * ", (yyvsp[0].rec)->code, "", "", "");
                      freeRecord((yyvsp[-2].rec));
                      freeRecord((yyvsp[0].rec));
                      (yyval.rec) = createRecord(s, "");
                      free(s);}
#line 2136 "y.tab.c"
    break;

  case 64: /* exp: exp DIVISION term  */
#line 542 "parser.y"
                          {char * s = cat((yyvsp[-2].rec)->code, " / ", (yyvsp[0].rec)->code, "", "", "");
                       freeRecord((yyvsp[-2].rec));
                       freeRecord((yyvsp[0].rec));
                       (yyval.rec) = createRecord(s, "");
                       free(s);}
#line 2146 "y.tab.c"
    break;

  case 65: /* exp: exp EXPOENT term  */
#line 547 "parser.y"
                         {char * s = cat("pow(", (yyvsp[-2].rec)->code, ", ", (yyvsp[0].rec)->code, ")", "");
                         freeRecord((yyvsp[-2].rec));
                         freeRecord((yyvsp[0].rec));
                         (yyval.rec) = createRecord(s, "");
                         free(s);}
#line 2156 "y.tab.c"
    break;

  case 66: /* term: factor  */
#line 554 "parser.y"
                     {(yyval.rec) = (yyvsp[0].rec);}
#line 2162 "y.tab.c"
    break;

  case 67: /* factor: ID  */
#line 557 "parser.y"
                     {(yyval.rec) = createRecord((yyvsp[0].sValue), "");
                      free((yyvsp[0].sValue));}
#line 2169 "y.tab.c"
    break;

  case 68: /* factor: INT  */
#line 559 "parser.y"
                     {(yyval.rec) = createRecord((yyvsp[0].sValue), "");
                      free((yyvsp[0].sValue));}
#line 2176 "y.tab.c"
    break;

  case 69: /* factor: FLOAT  */
#line 561 "parser.y"
                     {(yyval.rec) = createRecord((yyvsp[0].sValue), "");
                      free((yyvsp[0].sValue));}
#line 2183 "y.tab.c"
    break;

  case 70: /* factor: DOUBLE  */
#line 563 "parser.y"
                     {(yyval.rec) = createRecord((yyvsp[0].sValue), "");
                      free((yyvsp[0].sValue));}
#line 2190 "y.tab.c"
    break;

  case 71: /* factor: BOOL_LIT  */
#line 565 "parser.y"
                     {(yyval.rec) = createRecord((yyvsp[0].sValue), "");
                      free((yyvsp[0].sValue));}
#line 2197 "y.tab.c"
    break;

  case 72: /* factor: STRING_LIT  */
#line 567 "parser.y"
                     {(yyval.rec) = createRecord((yyvsp[0].sValue), "");
                      free((yyvsp[0].sValue));}
#line 2204 "y.tab.c"
    break;

  case 73: /* call: ID '(' exps_op ')'  */
#line 571 "parser.y"
                          {char * s = cat((yyvsp[-3].sValue), "(", (yyvsp[-1].rec)->code, ")", "", "");
                           free((yyvsp[-3].sValue));
						   freeRecord((yyvsp[-1].rec));
                           (yyval.rec) = createRecord(s, "");
                           free(s);
                          }
#line 2215 "y.tab.c"
    break;

  case 74: /* exps_op: %empty  */
#line 579 "parser.y"
                {(yyval.rec) = createRecord("","");}
#line 2221 "y.tab.c"
    break;

  case 75: /* exps_op: exps  */
#line 580 "parser.y"
                {(yyval.rec) = (yyvsp[0].rec);}
#line 2227 "y.tab.c"
    break;

  case 76: /* exps: exp  */
#line 583 "parser.y"
                     {(yyval.rec) = (yyvsp[0].rec);}
#line 2233 "y.tab.c"
    break;

  case 77: /* exps: exp ',' exps  */
#line 584 "parser.y"
                     {char * s = cat((yyvsp[-2].rec)->code, ", ", (yyvsp[0].rec)->code, "", "", "");
                      freeRecord((yyvsp[-2].rec));
                      freeRecord((yyvsp[0].rec));
                      (yyval.rec) = createRecord(s, "");
                      free(s);                      
      				 }
#line 2244 "y.tab.c"
    break;


#line 2248 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 592 "parser.y"


int main (int argc, char ** argv) {
 	int codigo;

    if (argc != 3) {
       printf("Usage: $./compiler input.txt output.txt\nClosing application...\n");
       exit(0);
    }
    
    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2], "w");

    codigo = yyparse();

    fclose(yyin);
    fclose(yyout);

	return codigo;
}

int yyerror (char *msg) {
	fprintf (stderr, "%d: %s at '%s'\n", yylineno, msg, yytext);
	return 0;
}

char * cat(char * s1, char * s2, char * s3, char * s4, char * s5, char * s6){
  int tam;
  char * output;

  tam = strlen(s1) + strlen(s2) + strlen(s3) + strlen(s4) + strlen(s5) + strlen(s6) + 1;
  output = (char *) malloc(sizeof(char) * tam);
  
  if (!output){
    printf("Allocation problem. Closing application...\n");
    exit(0);
  }
  
  sprintf(output, "%s%s%s%s%s%s", s1, s2, s3, s4, s5, s6);
  
  return output;
}
