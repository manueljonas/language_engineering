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
  
  

#line 92 "y.tab.c"

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
    SCAN = 272,                    /* SCAN  */
    RETURN = 273,                  /* RETURN  */
    EQUALS = 274,                  /* EQUALS  */
    DIFF = 275,                    /* DIFF  */
    LESS = 276,                    /* LESS  */
    GREATER = 277,                 /* GREATER  */
    LESSEQUALS = 278,              /* LESSEQUALS  */
    GREATEREQUALS = 279,           /* GREATEREQUALS  */
    AND = 280,                     /* AND  */
    OR = 281,                      /* OR  */
    XOR = 282,                     /* XOR  */
    NOT = 283,                     /* NOT  */
    TYPE = 284,                    /* TYPE  */
    STRING_LIT = 285,              /* STRING_LIT  */
    BOOL_LIT = 286,                /* BOOL_LIT  */
    ID = 287,                      /* ID  */
    VOID = 288,                    /* VOID  */
    INT = 289,                     /* INT  */
    FLOAT = 290,                   /* FLOAT  */
    DOUBLE = 291,                  /* DOUBLE  */
    STRING = 292,                  /* STRING  */
    INCREMENT = 293,               /* INCREMENT  */
    DECREMENT = 294,               /* DECREMENT  */
    INCREMENT_ASSIGN = 295,        /* INCREMENT_ASSIGN  */
    DECREMENT_ASSIGN = 296,        /* DECREMENT_ASSIGN  */
    PLUS = 297,                    /* PLUS  */
    MINUS = 298,                   /* MINUS  */
    MULT = 299,                    /* MULT  */
    DIVISION = 300,                /* DIVISION  */
    EXPOENT = 301                  /* EXPOENT  */
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
  

#line 194 "y.tab.c"

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
  YYSYMBOL_SCAN = 17,                      /* SCAN  */
  YYSYMBOL_RETURN = 18,                    /* RETURN  */
  YYSYMBOL_EQUALS = 19,                    /* EQUALS  */
  YYSYMBOL_DIFF = 20,                      /* DIFF  */
  YYSYMBOL_LESS = 21,                      /* LESS  */
  YYSYMBOL_GREATER = 22,                   /* GREATER  */
  YYSYMBOL_LESSEQUALS = 23,                /* LESSEQUALS  */
  YYSYMBOL_GREATEREQUALS = 24,             /* GREATEREQUALS  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_XOR = 27,                       /* XOR  */
  YYSYMBOL_NOT = 28,                       /* NOT  */
  YYSYMBOL_TYPE = 29,                      /* TYPE  */
  YYSYMBOL_STRING_LIT = 30,                /* STRING_LIT  */
  YYSYMBOL_BOOL_LIT = 31,                  /* BOOL_LIT  */
  YYSYMBOL_ID = 32,                        /* ID  */
  YYSYMBOL_VOID = 33,                      /* VOID  */
  YYSYMBOL_INT = 34,                       /* INT  */
  YYSYMBOL_FLOAT = 35,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 36,                    /* DOUBLE  */
  YYSYMBOL_STRING = 37,                    /* STRING  */
  YYSYMBOL_INCREMENT = 38,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 39,                 /* DECREMENT  */
  YYSYMBOL_INCREMENT_ASSIGN = 40,          /* INCREMENT_ASSIGN  */
  YYSYMBOL_DECREMENT_ASSIGN = 41,          /* DECREMENT_ASSIGN  */
  YYSYMBOL_PLUS = 42,                      /* PLUS  */
  YYSYMBOL_MINUS = 43,                     /* MINUS  */
  YYSYMBOL_MULT = 44,                      /* MULT  */
  YYSYMBOL_DIVISION = 45,                  /* DIVISION  */
  YYSYMBOL_EXPOENT = 46,                   /* EXPOENT  */
  YYSYMBOL_47_ = 47,                       /* '['  */
  YYSYMBOL_48_ = 48,                       /* ']'  */
  YYSYMBOL_49_ = 49,                       /* '('  */
  YYSYMBOL_50_ = 50,                       /* ')'  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_52_ = 52,                       /* ';'  */
  YYSYMBOL_53_ = 53,                       /* ':'  */
  YYSYMBOL_54_ = 54,                       /* '{'  */
  YYSYMBOL_55_ = 55,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_prog = 57,                      /* prog  */
  YYSYMBOL_subprogs = 58,                  /* subprogs  */
  YYSYMBOL_subprog = 59,                   /* subprog  */
  YYSYMBOL_args_op = 60,                   /* args_op  */
  YYSYMBOL_args = 61,                      /* args  */
  YYSYMBOL_arg = 62,                       /* arg  */
  YYSYMBOL_ids = 63,                       /* ids  */
  YYSYMBOL_main = 64,                      /* main  */
  YYSYMBOL_cmds = 65,                      /* cmds  */
  YYSYMBOL_cmd = 66,                       /* cmd  */
  YYSYMBOL_cond = 67,                      /* cond  */
  YYSYMBOL_return = 68,                    /* return  */
  YYSYMBOL_write = 69,                     /* write  */
  YYSYMBOL_read = 70,                      /* read  */
  YYSYMBOL_iteration = 71,                 /* iteration  */
  YYSYMBOL_for_incr = 72,                  /* for_incr  */
  YYSYMBOL_exp = 73,                       /* exp  */
  YYSYMBOL_term = 74,                      /* term  */
  YYSYMBOL_factor = 75,                    /* factor  */
  YYSYMBOL_call = 76,                      /* call  */
  YYSYMBOL_exps_op = 77,                   /* exps_op  */
  YYSYMBOL_exps = 78                       /* exps  */
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   538

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  225

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
      49,    50,     2,     2,    51,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    53,    52,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    54,     2,    55,     2,     2,     2,     2,
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
      45,    46
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    63,    64,    72,    83,    94,   108,   109,
     112,   113,   121,   127,   136,   141,   148,   149,   157,   158,
     159,   160,   161,   162,   169,   175,   180,   187,   193,   199,
     205,   211,   218,   227,   253,   290,   297,   304,   310,   336,
     375,   415,   456,   510,   517,   524,   531,   538,   544,   545,
     546,   551,   556,   561,   566,   571,   576,   581,   586,   591,
     595,   600,   605,   610,   615,   622,   623,   627,   633,   641,
     645,   652,   661,   670,   681,   683,   685,   687,   689,   691,
     693,   695,   700,   708,   709,   712,   713
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
  "FOR", "END_FOR", "ASSIGN", "MAIN", "END_MAIN", "PRINT", "SCAN",
  "RETURN", "EQUALS", "DIFF", "LESS", "GREATER", "LESSEQUALS",
  "GREATEREQUALS", "AND", "OR", "XOR", "NOT", "TYPE", "STRING_LIT",
  "BOOL_LIT", "ID", "VOID", "INT", "FLOAT", "DOUBLE", "STRING",
  "INCREMENT", "DECREMENT", "INCREMENT_ASSIGN", "DECREMENT_ASSIGN", "PLUS",
  "MINUS", "MULT", "DIVISION", "EXPOENT", "'['", "']'", "'('", "')'",
  "','", "';'", "':'", "'{'", "'}'", "$accept", "prog", "subprogs",
  "subprog", "args_op", "args", "arg", "ids", "main", "cmds", "cmd",
  "cond", "return", "write", "read", "iteration", "for_incr", "exp",
  "term", "factor", "call", "exps_op", "exps", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-170)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -18,     5,   -13,    32,    40,   -18,     2,   -10,    15,  -170,
      46,  -170,  -170,    21,    25,    42,   435,    39,    41,    45,
      47,   435,   435,   445,  -170,  -170,    73,  -170,  -170,  -170,
    -170,  -170,    57,    59,   435,   435,    58,    46,  -170,  -170,
    -170,  -170,  -170,   376,  -170,  -170,  -170,    50,    68,    60,
      48,   -40,    -2,   435,    24,   435,   435,   151,  -170,    20,
      53,   435,    55,    63,   435,   435,   435,   435,    64,    65,
      56,    69,  -170,  -170,   470,   470,   470,   470,   470,   470,
     470,   470,   470,   470,   470,   470,   470,   470,   435,  -170,
      77,    75,  -170,    66,   107,   116,    46,   110,    91,    13,
      78,    88,  -170,   435,  -170,   185,  -170,  -170,   196,   230,
      92,    89,  -170,  -170,  -170,  -170,  -170,    94,  -170,  -170,
    -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,  -170,
    -170,  -170,  -170,  -170,    95,    46,    68,   111,   113,    51,
      46,    -3,   435,   435,    90,    98,   241,  -170,  -170,  -170,
      14,  -170,    68,   143,  -170,   114,   115,    46,  -170,   149,
     435,   133,   275,   286,  -170,  -170,  -170,   435,   435,  -170,
    -170,    68,    68,   159,  -170,   320,   119,   435,   410,   134,
     131,   135,   136,  -170,   435,    46,   331,    54,   158,   166,
     141,   409,   -11,    46,    46,   365,   171,   410,  -170,  -170,
    -170,  -170,    46,   435,   435,   435,   195,   197,   410,  -170,
     150,   190,   134,   134,   134,  -170,  -170,   163,    46,  -170,
      46,   202,   212,  -170,  -170
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,     0,     0,     3,     0,     0,     0,     1,
      16,     2,     4,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    79,    74,    81,    75,    76,
      78,    77,     0,     0,     0,     0,     0,    16,    18,    19,
      20,    21,    22,    85,    48,    65,    49,     0,     8,     0,
       0,    74,     0,     0,     0,     0,     0,     0,    59,    74,
       0,     0,     0,     0,     0,     0,     0,    83,     0,     0,
       0,     0,    15,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
       0,     0,     9,    10,     0,     0,    16,     0,     0,     0,
       0,     0,    35,     0,    24,     0,    27,    28,     0,     0,
       0,     0,    84,    29,    30,    66,    69,    74,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    60,    61,    62,
      63,    64,    86,    14,    12,    16,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,     0,    26,    31,    32,
      67,    82,     0,     0,    11,     0,     0,    16,    33,     0,
       0,     0,     0,     0,    36,    37,    23,     0,     0,    13,
       5,     8,     8,     0,    38,     0,     0,     0,     0,    70,
       0,     0,     0,    34,     0,    16,     0,    74,     0,     0,
       0,    47,    68,    16,    16,     0,     0,     0,    43,    44,
      45,    46,    16,     0,     0,     0,     0,     0,     0,    42,
       0,     0,    71,    72,    73,     6,     7,     0,    16,    39,
      16,     0,     0,    40,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -170,  -170,   220,  -170,  -159,    96,    74,  -170,  -170,   -36,
    -170,  -170,  -170,  -170,  -170,  -170,  -169,   -16,   451,  -170,
    -170,  -170,   -20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     5,    91,    92,    93,   134,    11,    36,
      37,    38,    39,    40,    41,    42,   190,    43,    44,    45,
      46,   111,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      52,    73,   203,    60,    96,    57,    58,    66,     6,    67,
     160,     1,   181,   182,    70,    71,     8,    74,    75,    76,
      77,    78,    79,    80,    81,    82,   142,   167,   210,   204,
     205,     2,     9,   103,    13,   100,   101,    97,    14,   217,
      83,    84,    85,    86,    87,   105,   110,   112,   108,   109,
     161,    16,     7,    98,    10,    17,    99,    18,   157,   158,
     139,   168,    19,    20,    21,   143,    15,    66,   132,    67,
      48,    50,    49,    72,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    61,   146,    53,    68,
      54,    69,   198,   199,    55,    34,    56,    90,    95,   153,
      35,    66,    89,    67,   159,   104,   115,   106,    94,   133,
     137,    62,    63,    64,    65,   107,   113,   114,   136,   138,
      66,   173,    67,   141,   116,   135,   162,   163,   144,    74,
      75,    76,    77,    78,    79,    80,    81,    82,   145,   151,
     150,    66,   164,   155,   175,   156,   152,   170,   180,   196,
     165,   179,    83,    84,    85,    86,    87,   206,   207,   174,
     140,   186,   191,   171,   172,   176,   211,   183,   195,   185,
      74,    75,    76,    77,    78,    79,    80,    81,    82,   192,
      87,   191,   221,   209,   222,   193,   194,   212,   213,   214,
     200,   202,   191,    83,    84,    85,    86,    87,   201,   215,
     218,   216,   219,   102,    74,    75,    76,    77,    78,    79,
      80,    81,    82,   220,   223,    74,    75,    76,    77,    78,
      79,    80,    81,    82,   224,    12,   169,    83,    84,    85,
      86,    87,   154,     0,     0,     0,     0,   147,    83,    84,
      85,    86,    87,     0,     0,     0,     0,     0,   148,    74,
      75,    76,    77,    78,    79,    80,    81,    82,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
       0,     0,    83,    84,    85,    86,    87,     0,     0,     0,
       0,     0,   149,    83,    84,    85,    86,    87,     0,     0,
       0,     0,     0,   166,    74,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,     0,     0,    83,    84,    85,
      86,    87,     0,     0,     0,     0,     0,   177,    83,    84,
      85,    86,    87,     0,     0,     0,     0,     0,   178,    74,
      75,    76,    77,    78,    79,    80,    81,    82,     0,     0,
      74,    75,    76,    77,    78,    79,    80,    81,    82,     0,
       0,     0,    83,    84,    85,    86,    87,     0,     0,     0,
       0,     0,   184,    83,    84,    85,    86,    87,     0,     0,
       0,     0,     0,   197,    74,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,     0,     0,    83,    84,    85,
      86,    87,     0,     0,     0,     0,     0,   208,    83,    84,
      85,    86,    87,     0,     0,     0,     0,    88,    74,    75,
      76,    77,    78,    79,    80,    81,    82,     0,    22,     0,
      24,    25,   187,    27,    28,    29,    30,    31,   188,   189,
       0,    83,    84,    85,    86,    87,     0,     0,     0,    34,
       0,     0,     0,    22,    35,    24,    25,    51,    27,    28,
      29,    30,    31,    22,     0,    24,    25,    59,    27,    28,
      29,    30,    31,     0,    34,     0,     0,     0,     0,    35,
       0,     0,     0,     0,    34,     0,     0,     0,     0,    35,
      24,    25,   117,    27,    28,    29,    30,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,    35,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131
};

static const yytype_int16 yycheck[] =
{
      16,    37,    13,    23,     6,    21,    22,    47,     3,    49,
      13,    29,   171,   172,    34,    35,    29,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    13,    13,   197,    40,
      41,    49,     0,    13,    32,    55,    56,    53,    48,   208,
      42,    43,    44,    45,    46,    61,    66,    67,    64,    65,
      53,     5,    47,    29,    14,     9,    32,    11,     7,     8,
      96,    47,    16,    17,    18,    52,    51,    47,    88,    49,
      49,    29,    47,    15,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    13,   103,    49,    32,
      49,    32,    38,    39,    49,    49,    49,    29,    50,   135,
      54,    47,    52,    49,   140,    52,    50,    52,    48,    32,
       3,    38,    39,    40,    41,    52,    52,    52,    52,     3,
      47,   157,    49,    32,    55,    50,   142,   143,    50,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    50,    50,
      48,    47,    52,    32,   160,    32,    51,     4,   168,   185,
      52,   167,    42,    43,    44,    45,    46,   193,   194,    10,
      50,   177,   178,    49,    49,    32,   202,     8,   184,    50,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    48,
      46,   197,   218,    12,   220,    50,    50,   203,   204,   205,
      32,    50,   208,    42,    43,    44,    45,    46,    32,     4,
      50,     4,    12,    52,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    50,    12,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    12,     5,   152,    42,    43,    44,
      45,    46,   136,    -1,    -1,    -1,    -1,    52,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    52,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    52,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    -1,    52,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    52,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    51,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    28,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    42,    43,    44,    45,    46,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    28,    54,    30,    31,    32,    33,    34,
      35,    36,    37,    28,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    49,    -1,    -1,    -1,    -1,    54,
      -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    54,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    54,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    29,    49,    57,    58,    59,     3,    47,    29,     0,
      14,    64,    58,    32,    48,    51,     5,     9,    11,    16,
      17,    18,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    49,    54,    65,    66,    67,    68,
      69,    70,    71,    73,    74,    75,    76,    78,    49,    47,
      29,    32,    73,    49,    49,    49,    49,    73,    73,    32,
      78,    13,    38,    39,    40,    41,    47,    49,    32,    32,
      78,    78,    15,    65,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    42,    43,    44,    45,    46,    51,    52,
      29,    60,    61,    62,    48,    50,     6,    73,    29,    32,
      78,    78,    52,    13,    52,    73,    52,    52,    73,    73,
      78,    77,    78,    52,    52,    50,    55,    32,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    78,    32,    63,    50,    52,     3,     3,    65,
      50,    32,    13,    52,    50,    50,    73,    52,    52,    52,
      48,    50,    51,    65,    61,    32,    32,     7,     8,    65,
      13,    53,    73,    73,    52,    52,    52,    13,    47,    62,
       4,    49,    49,    65,    10,    73,    32,    52,    52,    73,
      78,    60,    60,     8,    52,    50,    73,    32,    38,    39,
      72,    73,    48,    50,    50,    73,    65,    52,    38,    39,
      32,    32,    50,    13,    40,    41,    65,    65,    52,    12,
      72,    65,    73,    73,    73,     4,     4,    72,    50,    12,
      50,    65,    65,    12,    12
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    60,    60,
      61,    61,    62,    62,    63,    64,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    67,    67,    68,    69,    70,    71,    71,
      71,    71,    71,    72,    72,    72,    72,    72,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    75,    75,    75,    75,    75,    75,
      75,    75,    76,    77,    77,    78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     8,    12,    12,     0,     1,
       1,     3,     2,     4,     1,     3,     0,     2,     1,     1,
       1,     1,     1,     5,     3,     2,     4,     3,     3,     3,
       3,     4,     4,     5,     7,     3,     5,     5,     6,    10,
      12,    13,     9,     2,     2,     2,     2,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     3,     3,     1,     3,     4,     7,     3,
       6,     9,     9,     9,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     0,     1,     1,     3
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
#line 53 "parser.y"
                       {
                      char *headers = "#include<stdio.h>\n#include<stdlib.h>\n#include<stdbool.h>\n#include<math.h>\n\n";
                      char *s = cat(headers, (yyvsp[-1].rec)->code, "\n", (yyvsp[0].rec)->code, "", "");
                      fprintf(yyout, "%s", s);
                      freeRecord((yyvsp[-1].rec));
                      freeRecord((yyvsp[0].rec));
                      free(s);                          
                     }
#line 1459 "y.tab.c"
    break;

  case 3: /* subprogs: %empty  */
#line 63 "parser.y"
                              {(yyval.rec) = createRecord("","");}
#line 1465 "y.tab.c"
    break;

  case 4: /* subprogs: subprog subprogs  */
#line 64 "parser.y"
                            {char * s = cat((yyvsp[-1].rec)->code, "\n", (yyvsp[0].rec)->code, "", "", "");
                             freeRecord((yyvsp[-1].rec));
                             freeRecord((yyvsp[0].rec));
                             (yyval.rec) = createRecord(s, "");
                             free(s);
                            }
#line 1476 "y.tab.c"
    break;

  case 5: /* subprog: TYPE FUNCTION ID '(' args_op ')' cmds END_FUNCTION  */
#line 73 "parser.y"
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
#line 1491 "y.tab.c"
    break;

  case 6: /* subprog: TYPE '[' ']' '[' ']' FUNCTION ID '(' args_op ')' cmds END_FUNCTION  */
#line 84 "parser.y"
           {char * s1 = cat((yyvsp[-11].sValue), " ", (yyvsp[-5].sValue), "(", (yyvsp[-3].rec)->code, "");
            char * s2 = cat(s1, ")\n", "{\n", (yyvsp[-1].rec)->code, "}", "");
            free(s1);
            free((yyvsp[-11].sValue));
            free((yyvsp[-5].sValue));
            freeRecord((yyvsp[-3].rec));
            freeRecord((yyvsp[-1].rec));
            (yyval.rec) = createRecord(s2, "");
            free(s2);
           }
#line 1506 "y.tab.c"
    break;

  case 7: /* subprog: '(' TYPE ',' TYPE ')' FUNCTION ID '(' args_op ')' cmds END_FUNCTION  */
#line 95 "parser.y"
           {char * s1 = cat("(", (yyvsp[-10].sValue), ", ", (yyvsp[-8].sValue), ") ", (yyvsp[-5].sValue));
            char * s2 = cat(s1, "(", (yyvsp[-3].rec)->code, ")\n{\n", (yyvsp[-1].rec)->code, "}");
            free(s1);
            free((yyvsp[-10].sValue));
            free((yyvsp[-8].sValue));
            free((yyvsp[-5].sValue));
            freeRecord((yyvsp[-3].rec));
            freeRecord((yyvsp[-1].rec));
            (yyval.rec) = createRecord(s2, "");
            free(s2);
           }
#line 1522 "y.tab.c"
    break;

  case 8: /* args_op: %empty  */
#line 108 "parser.y"
                  {(yyval.rec) = createRecord("","");}
#line 1528 "y.tab.c"
    break;

  case 9: /* args_op: args  */
#line 109 "parser.y"
                {(yyval.rec) = (yyvsp[0].rec);}
#line 1534 "y.tab.c"
    break;

  case 10: /* args: arg  */
#line 112 "parser.y"
                      {(yyval.rec) = (yyvsp[0].rec);}
#line 1540 "y.tab.c"
    break;

  case 11: /* args: arg ';' args  */
#line 113 "parser.y"
                    {char * s = cat((yyvsp[-2].rec)->code, "; ", (yyvsp[0].rec)->code, "", "", "");
                     freeRecord((yyvsp[-2].rec));
                     freeRecord((yyvsp[0].rec));
                     (yyval.rec) = createRecord(s, "");
                     free(s);
                    }
#line 1551 "y.tab.c"
    break;

  case 12: /* arg: TYPE ids  */
#line 121 "parser.y"
                 {char * s = cat((yyvsp[-1].sValue), " ", (yyvsp[0].rec)->code, "", "", "");
                free((yyvsp[-1].sValue));
                freeRecord((yyvsp[0].rec));
                (yyval.rec) = createRecord(s, "");
                free(s);
               }
#line 1562 "y.tab.c"
    break;

  case 13: /* arg: TYPE ids ',' arg  */
#line 127 "parser.y"
                         {char * s = cat((yyvsp[-3].sValue), " ", (yyvsp[-2].rec)->code, ", ", (yyvsp[0].rec)->code, "");
                free((yyvsp[-3].sValue));
                freeRecord((yyvsp[-2].rec));
                freeRecord((yyvsp[0].rec));
                (yyval.rec) = createRecord(s, "");
                free(s);
               }
#line 1574 "y.tab.c"
    break;

  case 14: /* ids: ID  */
#line 136 "parser.y"
                   {(yyval.rec) = createRecord((yyvsp[0].sValue), "");
                  free((yyvsp[0].sValue));
                 }
#line 1582 "y.tab.c"
    break;

  case 15: /* main: MAIN cmds END_MAIN  */
#line 141 "parser.y"
                            {char * s = cat("int main(){\n", (yyvsp[-1].rec)->code, "}", "", "", "");
                                  freeRecord((yyvsp[-1].rec));
                                  (yyval.rec) = createRecord(s, "");
                                  free(s);
                                 }
#line 1592 "y.tab.c"
    break;

  case 16: /* cmds: %empty  */
#line 148 "parser.y"
                   {(yyval.rec) = createRecord("","");}
#line 1598 "y.tab.c"
    break;

  case 17: /* cmds: cmd cmds  */
#line 149 "parser.y"
                 {char * s = cat((yyvsp[-1].rec)->code, "\n", (yyvsp[0].rec)->code, "", "", "");
                  freeRecord((yyvsp[-1].rec));
                  freeRecord((yyvsp[0].rec));
                  (yyval.rec) = createRecord(s, "");
                  free(s);
                 }
#line 1609 "y.tab.c"
    break;

  case 18: /* cmd: cond  */
#line 157 "parser.y"
                                {(yyval.rec) = (yyvsp[0].rec);}
#line 1615 "y.tab.c"
    break;

  case 19: /* cmd: return  */
#line 158 "parser.y"
                                {(yyval.rec) = (yyvsp[0].rec);}
#line 1621 "y.tab.c"
    break;

  case 20: /* cmd: write  */
#line 159 "parser.y"
                                {(yyval.rec) = (yyvsp[0].rec);}
#line 1627 "y.tab.c"
    break;

  case 21: /* cmd: read  */
#line 160 "parser.y"
                                {(yyval.rec) = (yyvsp[0].rec);}
#line 1633 "y.tab.c"
    break;

  case 22: /* cmd: iteration  */
#line 161 "parser.y"
                                {(yyval.rec) = (yyvsp[0].rec);}
#line 1639 "y.tab.c"
    break;

  case 23: /* cmd: TYPE ID ASSIGN exp ';'  */
#line 162 "parser.y"
                             {char * s = cat((yyvsp[-4].sValue), " ", (yyvsp[-3].sValue), " = ", (yyvsp[-1].rec)->code, ";");
                              free((yyvsp[-4].sValue));
                              free((yyvsp[-3].sValue));
                              freeRecord((yyvsp[-1].rec));
                              (yyval.rec) = createRecord(s, "");
                              free(s);
      }
#line 1651 "y.tab.c"
    break;

  case 24: /* cmd: TYPE exps ';'  */
#line 169 "parser.y"
                    {char * s = cat((yyvsp[-2].sValue), " ", (yyvsp[-1].rec)->code, ";", "", "");
                     free((yyvsp[-2].sValue));
                     freeRecord((yyvsp[-1].rec));
                     (yyval.rec) = createRecord(s, "");
                     free(s);
                    }
#line 1662 "y.tab.c"
    break;

  case 25: /* cmd: exps ';'  */
#line 175 "parser.y"
               {char * s = cat((yyvsp[-1].rec)->code, ";", "", "", "", "");
                freeRecord((yyvsp[-1].rec));
                (yyval.rec) = createRecord(s, "");
                free(s);
               }
#line 1672 "y.tab.c"
    break;

  case 26: /* cmd: ID ASSIGN exp ';'  */
#line 180 "parser.y"
                        { 
         char *s = cat((yyvsp[-3].sValue), " = ", (yyvsp[-1].rec)->code, ";", "", "");
         free((yyvsp[-3].sValue));
         freeRecord((yyvsp[-1].rec));
         (yyval.rec) = createRecord(s, "");
         free(s);
      }
#line 1684 "y.tab.c"
    break;

  case 27: /* cmd: ID INCREMENT ';'  */
#line 187 "parser.y"
                       { 
         char *s = cat((yyvsp[-2].sValue), "++", ";", "", "", "");
         free((yyvsp[-2].sValue));
         (yyval.rec) = createRecord(s, "");
         free(s);
      }
#line 1695 "y.tab.c"
    break;

  case 28: /* cmd: ID DECREMENT ';'  */
#line 193 "parser.y"
                       { 
         char *s = cat((yyvsp[-2].sValue), "--", ";", "", "", "");
         free((yyvsp[-2].sValue));
         (yyval.rec) = createRecord(s, "");
         free(s);
      }
#line 1706 "y.tab.c"
    break;

  case 29: /* cmd: INCREMENT ID ';'  */
#line 199 "parser.y"
                       { 
         char *s = cat("++", (yyvsp[-1].sValue), ";", "", "", "");
         free((yyvsp[-1].sValue));
         (yyval.rec) = createRecord(s, "");
         free(s);
      }
#line 1717 "y.tab.c"
    break;

  case 30: /* cmd: DECREMENT ID ';'  */
#line 205 "parser.y"
                       { 
         char *s = cat("--", (yyvsp[-1].sValue), ";", "", "", "");
         free((yyvsp[-1].sValue));
         (yyval.rec) = createRecord(s, "");
         free(s);
      }
#line 1728 "y.tab.c"
    break;

  case 31: /* cmd: ID INCREMENT_ASSIGN exp ';'  */
#line 211 "parser.y"
                                  { 
         char *s = cat((yyvsp[-3].sValue), " += ", (yyvsp[-1].rec)->code, ";", "", "");
         free((yyvsp[-3].sValue));
         freeRecord((yyvsp[-1].rec));
         (yyval.rec) = createRecord(s, "");
         free(s);
      }
#line 1740 "y.tab.c"
    break;

  case 32: /* cmd: ID DECREMENT_ASSIGN exp ';'  */
#line 218 "parser.y"
                                  { 
         char *s = cat((yyvsp[-3].sValue), " -= ", (yyvsp[-1].rec)->code, ";", "", "");
         free((yyvsp[-3].sValue));
         freeRecord((yyvsp[-1].rec));
         (yyval.rec) = createRecord(s, "");
         free(s);
      }
#line 1752 "y.tab.c"
    break;

  case 33: /* cond: IF exp THEN cmds END_IF  */
#line 228 "parser.y"
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
#line 1782 "y.tab.c"
    break;

  case 34: /* cond: IF exp THEN cmds ELSE cmds END_IF  */
#line 254 "parser.y"
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
#line 1821 "y.tab.c"
    break;

  case 35: /* return: RETURN exp ';'  */
#line 290 "parser.y"
                          {char * s = cat("return ", (yyvsp[-1].rec)->code, ";", "", "", "");
                         freeRecord((yyvsp[-1].rec));
                         (yyval.rec) = createRecord(s, "");
                         free(s);
                        }
#line 1831 "y.tab.c"
    break;

  case 36: /* write: PRINT '(' exps ')' ';'  */
#line 297 "parser.y"
                                 {char * s = cat("printf", "(", (yyvsp[-2].rec)->code, ")", ";", "");
                                  freeRecord((yyvsp[-2].rec));
                                  (yyval.rec) = createRecord(s, "");
                                  free(s);
                                 }
#line 1841 "y.tab.c"
    break;

  case 37: /* read: SCAN '(' exps ')' ';'  */
#line 304 "parser.y"
                               {char * s = cat("scanf", "(", (yyvsp[-2].rec)->code, ")", ";", "");
                                  freeRecord((yyvsp[-2].rec));
                                  (yyval.rec) = createRecord(s, "");
                                  free(s);
                                 }
#line 1851 "y.tab.c"
    break;

  case 38: /* iteration: WHILE '(' exp ')' cmds END_WHILE  */
#line 311 "parser.y"
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
        char *part2 = cat("goto ", labelEnd, ";\n", labelBody, ":\n{\n", (yyvsp[-1].rec)->code);
        char *part3 = cat("}\n", "goto ", labelStart, ";\n", labelEnd, ": \n");
  
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
#line 1881 "y.tab.c"
    break;

  case 39: /* iteration: FOR '(' ID ';' exp ';' for_incr ')' cmds END_FOR  */
#line 337 "parser.y"
    {
        // Gerar rótulos únicos para o laço
        int currentLabelFor = labelCounterFor++;
        char labelStart[30], labelEnd[30], labelBody[30];
  
        snprintf(labelStart, sizeof(labelStart), "label_for_start_%d", currentLabelFor);
        snprintf(labelEnd, sizeof(labelEnd), "label_for_end_%d", currentLabelFor);
        snprintf(labelBody, sizeof(labelBody), "label_for_body_%d", currentLabelFor);
  
        // Inicialização
        char *init = cat((yyvsp[-7].sValue), ";\n", " ", "", "", "");
  
        // Condição (ajustada para if ((...) em vez de if (!(...))
        char *cond = cat("if ((", (yyvsp[-5].rec)->code, ")) goto ", labelBody, ";\n", "");
        char *skipToEnd = cat("goto ", labelEnd, ";\n", "", "", "");
  
        // Incremento
        char *increment = cat((yyvsp[-3].rec)->code, "", "", "", "", "");
  
        // Combinar as partes do laço
        char *part1 = cat("\n{\n", init, labelStart, ": ", cond, skipToEnd);
        char *part2 = cat(labelBody, ":\n{\n", (yyvsp[-1].rec)->code, "}\n", increment, ";\n");
        char *part3 = cat("goto ", labelStart, ";\n", labelEnd, ": \n}\n", "");
  
        char *s = cat(part1, part2, part3, "", "", "");
        free(init);
        free(cond);
        free(skipToEnd);
        free(part1);
        free(part2);
        free(part3);
        free((yyvsp[-7].sValue));
        freeRecord((yyvsp[-5].rec));
        freeRecord((yyvsp[-3].rec));
        freeRecord((yyvsp[-1].rec));
        (yyval.rec) = createRecord(s, "");
        free(s);
    }
#line 1924 "y.tab.c"
    break;

  case 40: /* iteration: FOR '(' ID ASSIGN exp ';' exp ';' for_incr ')' cmds END_FOR  */
#line 376 "parser.y"
    {
        // Gerar rótulos únicos para o laço
        int currentLabelFor = labelCounterFor++;
        char labelStart[30], labelEnd[30], labelBody[30];
  
        snprintf(labelStart, sizeof(labelStart), "label_for_start_%d", currentLabelFor);
        snprintf(labelEnd, sizeof(labelEnd), "label_for_end_%d", currentLabelFor);
        snprintf(labelBody, sizeof(labelBody), "label_for_body_%d", currentLabelFor);
  
        // Inicialização
        char *init = cat((yyvsp[-9].sValue), " ", " = ", (yyvsp[-7].rec)->code, ";\n", " ");
  
        // Condição (ajustada para if ((...) em vez de if (!(...))
        char *cond = cat("if ((", (yyvsp[-5].rec)->code, ")) goto ", labelBody, ";\n", "");
        char *skipToEnd = cat("goto ", labelEnd, ";\n", "", "", "");
  
        // Incremento
        char *increment = cat((yyvsp[-3].rec)->code, "", "", "", "", "");
  
        // Combinar as partes do laço
        char *part1 = cat("\n{\n", init, labelStart, ": ", cond, skipToEnd);
        char *part2 = cat(labelBody, ":\n{\n", (yyvsp[-1].rec)->code, "}\n", increment, ";\n");
        char *part3 = cat("goto ", labelStart, ";\n", labelEnd, ": \n}\n", "");
  
        char *s = cat(part1, part2, part3, "", "", "");
        free(init);
        free(cond);
        free(skipToEnd);
        free(part1);
        free(part2);
        free(part3);
        free((yyvsp[-9].sValue));
        freeRecord((yyvsp[-7].rec));
        freeRecord((yyvsp[-5].rec));
        freeRecord((yyvsp[-3].rec));
        freeRecord((yyvsp[-1].rec));
        (yyval.rec) = createRecord(s, "");
        free(s);
    }
#line 1968 "y.tab.c"
    break;

  case 41: /* iteration: FOR '(' TYPE ID ASSIGN exp ';' exp ';' for_incr ')' cmds END_FOR  */
#line 416 "parser.y"
    {
        // Gerar rótulos únicos para o laço
        int currentLabelFor = labelCounterFor++;
        char labelStart[30], labelEnd[30], labelBody[30];
  
        snprintf(labelStart, sizeof(labelStart), "label_for_start_%d", currentLabelFor);
        snprintf(labelEnd, sizeof(labelEnd), "label_for_end_%d", currentLabelFor);
        snprintf(labelBody, sizeof(labelBody), "label_for_body_%d", currentLabelFor);
  
        // Inicialização
        char *init = cat((yyvsp[-10].sValue), " ", (yyvsp[-9].sValue), " = ", (yyvsp[-7].rec)->code, ";\n");
  
        // Condição (ajustada para if ((...) em vez de if (!(...))
        char *cond = cat("if ((", (yyvsp[-5].rec)->code, ")) goto ", labelBody, ";\n", "");
        char *skipToEnd = cat("goto ", labelEnd, ";\n", "", "", "");
  
        // Incremento
        char *increment = cat((yyvsp[-3].rec)->code, "", "", "", "", "");
  
        // Combinar as partes do laço
        char *part1 = cat("\n{\n", init, labelStart, ": ", cond, skipToEnd);
        char *part2 = cat(labelBody, ":\n{\n", (yyvsp[-1].rec)->code, "}\n", increment, ";\n");
        char *part3 = cat("goto ", labelStart, ";\n", labelEnd, ": \n}\n", "");
  
        char *s = cat(part1, part2, part3, "", "", "");
        free(init);
        free(cond);
        free(skipToEnd);
        free(part1);
        free(part2);
        free(part3);
        free((yyvsp[-10].sValue));
        free((yyvsp[-9].sValue));
        freeRecord((yyvsp[-7].rec));
        freeRecord((yyvsp[-5].rec));
        freeRecord((yyvsp[-3].rec));
        freeRecord((yyvsp[-1].rec));
        (yyval.rec) = createRecord(s, "");
        free(s);
    }
#line 2013 "y.tab.c"
    break;

  case 42: /* iteration: FOR '(' TYPE ID ':' ID ')' cmds END_FOR  */
#line 457 "parser.y"
    {
        // Incrementa o contador global de rótulos
        int currentLabelFor = labelCounterFor++;
        char labelStart[30], labelBody[30], labelEnd[30];
  
        snprintf(labelStart, sizeof(labelStart), "label_for_start_%d", currentLabelFor);
        snprintf(labelBody, sizeof(labelBody), "label_for_body_%d", currentLabelFor);
        snprintf(labelEnd, sizeof(labelEnd), "label_for_end_%d", currentLabelFor);
  
        // Determina o tamanho do array
        char *arrayLength = cat("sizeof(", (yyvsp[-3].sValue), ") / sizeof(", (yyvsp[-3].sValue), "[0])", "");
  
        // Inicialização: índice começa em 0
        char *init = cat("int ", (yyvsp[-5].sValue), " = 0;\n", "", "", "");
  
        // Condição do laço: enquanto índice < tamanho do array
        char *cond = cat("if (", (yyvsp[-5].sValue), " < ", arrayLength, ") goto ", labelBody);
        char *skipToEnd = cat("goto ", labelEnd, ";\n", "", "", "");
  
        // Corpo do laço: atribui o valor atual do array à variável auxiliar
        char *assignValue = cat((yyvsp[-6].sValue), " aux = ", (yyvsp[-3].sValue), "[", (yyvsp[-5].sValue), "];\n");
        char *body = cat(labelBody, ":\n{\n", assignValue, (yyvsp[-1].rec)->code, "}\n", "");
  
        // Incremento: avança o índice
        char *increment = cat((yyvsp[-5].sValue), "++;\n", "", "", "", "");
  
        // Combinar as partes do laço
        char *part1 = cat("\n{\n", init, labelStart, ": ", cond, ";\n");
        char *part2 = cat(skipToEnd, body, increment, "goto ", labelStart, ";\n");
        char *part3 = cat(labelEnd, ": \n}\n", "", "", "", "");
  
        // Código final
        char *s = cat(part1, part2, part3, "", "", "");
  
        free(arrayLength);
        free(init);
        free(cond);
        free(skipToEnd);
        free(assignValue);
        free(body);
        free(increment);
        free(part1);
        free(part2);
        free(part3);
        free((yyvsp[-5].sValue));
        free((yyvsp[-3].sValue));
        freeRecord((yyvsp[-1].rec));
  
        (yyval.rec) = createRecord(s, "");
        free(s);
    }
#line 2069 "y.tab.c"
    break;

  case 43: /* for_incr: ID INCREMENT  */
#line 511 "parser.y"
    {
        char *s = cat((yyvsp[-1].sValue), "++", "", "", "", "");
        free((yyvsp[-1].sValue));
        (yyval.rec) = createRecord(s, "");
        free(s);
    }
#line 2080 "y.tab.c"
    break;

  case 44: /* for_incr: ID DECREMENT  */
#line 518 "parser.y"
    {
        char *s = cat((yyvsp[-1].sValue), "--", "", "", "", "");
        free((yyvsp[-1].sValue));
        (yyval.rec) = createRecord(s, "");
        free(s);
    }
#line 2091 "y.tab.c"
    break;

  case 45: /* for_incr: INCREMENT ID  */
#line 525 "parser.y"
    {
        char *s = cat("++", (yyvsp[0].sValue), "", "", "", "");
        free((yyvsp[0].sValue));
        (yyval.rec) = createRecord(s, "");
        free(s);
    }
#line 2102 "y.tab.c"
    break;

  case 46: /* for_incr: DECREMENT ID  */
#line 532 "parser.y"
    {
        char *s = cat("--", (yyvsp[0].sValue), "", "", "", "");
        free((yyvsp[0].sValue));
        (yyval.rec) = createRecord(s, "");
        free(s);
    }
#line 2113 "y.tab.c"
    break;

  case 47: /* for_incr: exp  */
#line 539 "parser.y"
    {
        (yyval.rec) = (yyvsp[0].rec);
    }
#line 2121 "y.tab.c"
    break;

  case 48: /* exp: term  */
#line 544 "parser.y"
                    {(yyval.rec) = (yyvsp[0].rec);}
#line 2127 "y.tab.c"
    break;

  case 49: /* exp: call  */
#line 545 "parser.y"
                  {(yyval.rec) = (yyvsp[0].rec);}
#line 2133 "y.tab.c"
    break;

  case 50: /* exp: exp EQUALS term  */
#line 546 "parser.y"
                        {char * s = cat((yyvsp[-2].rec)->code, " == ", (yyvsp[0].rec)->code, "", "", "");
                         freeRecord((yyvsp[-2].rec));
                         freeRecord((yyvsp[0].rec));
                         (yyval.rec) = createRecord(s, "");
                         free(s);}
#line 2143 "y.tab.c"
    break;

  case 51: /* exp: exp DIFF term  */
#line 551 "parser.y"
                      {char * s = cat((yyvsp[-2].rec)->code, " != ", (yyvsp[0].rec)->code, "", "", "");
                      freeRecord((yyvsp[-2].rec));
                      freeRecord((yyvsp[0].rec));
                      (yyval.rec) = createRecord(s, "");
                      free(s);}
#line 2153 "y.tab.c"
    break;

  case 52: /* exp: exp LESS term  */
#line 556 "parser.y"
                      {char * s = cat((yyvsp[-2].rec)->code, " < ", (yyvsp[0].rec)->code, "", "", "");
                      freeRecord((yyvsp[-2].rec));
                      freeRecord((yyvsp[0].rec));
                      (yyval.rec) = createRecord(s, "");
                      free(s);}
#line 2163 "y.tab.c"
    break;

  case 53: /* exp: exp GREATER term  */
#line 561 "parser.y"
                         {char * s = cat((yyvsp[-2].rec)->code, " > ", (yyvsp[0].rec)->code, "", "", "");
                         freeRecord((yyvsp[-2].rec));
                         freeRecord((yyvsp[0].rec));
                         (yyval.rec) = createRecord(s, "");
                         free(s);}
#line 2173 "y.tab.c"
    break;

  case 54: /* exp: exp LESSEQUALS term  */
#line 566 "parser.y"
                            {char * s = cat((yyvsp[-2].rec)->code, " <= ", (yyvsp[0].rec)->code, "", "", "");
                            freeRecord((yyvsp[-2].rec));
                            freeRecord((yyvsp[0].rec));
                            (yyval.rec) = createRecord(s, "");
                            free(s);}
#line 2183 "y.tab.c"
    break;

  case 55: /* exp: exp GREATEREQUALS term  */
#line 571 "parser.y"
                               {char * s = cat((yyvsp[-2].rec)->code, " >= ", (yyvsp[0].rec)->code, "", "", "");
                               freeRecord((yyvsp[-2].rec));
                               freeRecord((yyvsp[0].rec));
                               (yyval.rec) = createRecord(s, "");
                               free(s);}
#line 2193 "y.tab.c"
    break;

  case 56: /* exp: exp AND term  */
#line 576 "parser.y"
                     {char * s = cat((yyvsp[-2].rec)->code, " && ", (yyvsp[0].rec)->code, "", "", "");
                     freeRecord((yyvsp[-2].rec));
                     freeRecord((yyvsp[0].rec));
                     (yyval.rec) = createRecord(s, "");
                     free(s);}
#line 2203 "y.tab.c"
    break;

  case 57: /* exp: exp OR term  */
#line 581 "parser.y"
                    {char * s = cat((yyvsp[-2].rec)->code, " || ", (yyvsp[0].rec)->code, "", "", "");
                    freeRecord((yyvsp[-2].rec));
                    freeRecord((yyvsp[0].rec));
                    (yyval.rec) = createRecord(s, "");
                    free(s);}
#line 2213 "y.tab.c"
    break;

  case 58: /* exp: exp XOR term  */
#line 586 "parser.y"
                     {char * s = cat((yyvsp[-2].rec)->code, " ^ ", (yyvsp[0].rec)->code, "", "", "");
                     freeRecord((yyvsp[-2].rec));
                     freeRecord((yyvsp[0].rec));
                     (yyval.rec) = createRecord(s, "");
                     free(s);}
#line 2223 "y.tab.c"
    break;

  case 59: /* exp: NOT exp  */
#line 591 "parser.y"
                {char * s = cat("!", (yyvsp[0].rec)->code, "", "", "", "");
                  freeRecord((yyvsp[0].rec));
                  (yyval.rec) = createRecord(s, "");
                  free(s);}
#line 2232 "y.tab.c"
    break;

  case 60: /* exp: exp PLUS term  */
#line 595 "parser.y"
                      {char * s = cat((yyvsp[-2].rec)->code, " + ", (yyvsp[0].rec)->code, "", "", "");
                      freeRecord((yyvsp[-2].rec));
                      freeRecord((yyvsp[0].rec));
                      (yyval.rec) = createRecord(s, "");
                      free(s);}
#line 2242 "y.tab.c"
    break;

  case 61: /* exp: exp MINUS term  */
#line 600 "parser.y"
                       {char * s = cat((yyvsp[-2].rec)->code, " - ", (yyvsp[0].rec)->code, "", "", "");
                       freeRecord((yyvsp[-2].rec));
                       freeRecord((yyvsp[0].rec));
                       (yyval.rec) = createRecord(s, "");
                       free(s);}
#line 2252 "y.tab.c"
    break;

  case 62: /* exp: exp MULT term  */
#line 605 "parser.y"
                      {char * s = cat((yyvsp[-2].rec)->code, " * ", (yyvsp[0].rec)->code, "", "", "");
                      freeRecord((yyvsp[-2].rec));
                      freeRecord((yyvsp[0].rec));
                      (yyval.rec) = createRecord(s, "");
                      free(s);}
#line 2262 "y.tab.c"
    break;

  case 63: /* exp: exp DIVISION term  */
#line 610 "parser.y"
                          {char * s = cat((yyvsp[-2].rec)->code, " / ", (yyvsp[0].rec)->code, "", "", "");
                           freeRecord((yyvsp[-2].rec));
                           freeRecord((yyvsp[0].rec));
                           (yyval.rec) = createRecord(s, "");
                           free(s);}
#line 2272 "y.tab.c"
    break;

  case 64: /* exp: exp EXPOENT term  */
#line 615 "parser.y"
                         {char * s = cat("pow(", (yyvsp[-2].rec)->code, ", ", (yyvsp[0].rec)->code, ")", "");
                         freeRecord((yyvsp[-2].rec));
                         freeRecord((yyvsp[0].rec));
                         (yyval.rec) = createRecord(s, "");
                         free(s);}
#line 2282 "y.tab.c"
    break;

  case 65: /* term: factor  */
#line 622 "parser.y"
                       {(yyval.rec) = (yyvsp[0].rec);}
#line 2288 "y.tab.c"
    break;

  case 66: /* term: '(' exps ')'  */
#line 623 "parser.y"
                   {char * s = cat("(", (yyvsp[-1].rec)->code, ")", "", "", "");
                   freeRecord((yyvsp[-1].rec));
                   (yyval.rec) = createRecord(s, "");
                   free(s);}
#line 2297 "y.tab.c"
    break;

  case 67: /* term: ID '[' exps ']'  */
#line 628 "parser.y"
                 {char *s = cat((yyvsp[-3].sValue), "[", (yyvsp[-1].rec)->code, "]", "", "");
                  free((yyvsp[-3].sValue));
                  freeRecord((yyvsp[-1].rec));
                  (yyval.rec) = createRecord(s, "");
                  free(s);}
#line 2307 "y.tab.c"
    break;

  case 68: /* term: ID '[' exps ']' '[' exps ']'  */
#line 634 "parser.y"
                 {char *sAux = cat((yyvsp[-6].sValue), "[", (yyvsp[-4].rec)->code, "]", "[", (yyvsp[-1].rec)->code);
                  char *s =    cat(sAux, "]", "", "", "", "");
                  free((yyvsp[-6].sValue));
                  freeRecord((yyvsp[-4].rec));
                  freeRecord((yyvsp[-1].rec));
                  (yyval.rec) = createRecord(s, "");
                  free(s);}
#line 2319 "y.tab.c"
    break;

  case 69: /* term: '{' exps '}'  */
#line 641 "parser.y"
                   {char * s = cat("{", (yyvsp[-1].rec)->code, "}", "", "", "");
                   freeRecord((yyvsp[-1].rec));
                   (yyval.rec) = createRecord(s, "");
                   free(s);}
#line 2328 "y.tab.c"
    break;

  case 70: /* term: ID '[' exps ']' ASSIGN exp  */
#line 645 "parser.y"
                                  {char *s = cat((yyvsp[-5].sValue), "[", (yyvsp[-3].rec)->code, "] = ", (yyvsp[0].rec)->code, "");
                      free((yyvsp[-5].sValue));
                      freeRecord((yyvsp[-3].rec));
                      freeRecord((yyvsp[0].rec));
                      (yyval.rec) = createRecord(s, "");
                      free(s);
    }
#line 2340 "y.tab.c"
    break;

  case 71: /* term: ID '[' exps ']' '[' exps ']' ASSIGN exp  */
#line 652 "parser.y"
                                               {char *sAux = cat((yyvsp[-8].sValue), "[", (yyvsp[-6].rec)->code, "]", "[", (yyvsp[-3].rec)->code);
                                                char *s =    cat(sAux, "] = ", (yyvsp[0].rec)->code, "", "", "");
                                                free((yyvsp[-8].sValue));
                                                freeRecord((yyvsp[-6].rec));
                                                freeRecord((yyvsp[-3].rec));
                                                freeRecord((yyvsp[0].rec));
                                                (yyval.rec) = createRecord(s, "");
                                                free(s);
    }
#line 2354 "y.tab.c"
    break;

  case 72: /* term: ID '[' exps ']' '[' exps ']' INCREMENT_ASSIGN exp  */
#line 661 "parser.y"
                                                         {char *sAux = cat((yyvsp[-8].sValue), "[", (yyvsp[-6].rec)->code, "]", "[", (yyvsp[-3].rec)->code);
                                                            char *s =    cat(sAux, "] = ", (yyvsp[0].rec)->code, "", "", "");
                                                            free((yyvsp[-8].sValue));
                                                            freeRecord((yyvsp[-6].rec));
                                                            freeRecord((yyvsp[-3].rec));
                                                            freeRecord((yyvsp[0].rec));
                                                            (yyval.rec) = createRecord(s, "");
                                                            free(s);
    }
#line 2368 "y.tab.c"
    break;

  case 73: /* term: ID '[' exps ']' '[' exps ']' DECREMENT_ASSIGN exp  */
#line 670 "parser.y"
                                                         {char *sAux = cat((yyvsp[-8].sValue), "[", (yyvsp[-6].rec)->code, "]", "[", (yyvsp[-3].rec)->code);
                                                            char *s =    cat(sAux, "] = ", (yyvsp[0].rec)->code, "", "", "");
                                                            free((yyvsp[-8].sValue));
                                                            freeRecord((yyvsp[-6].rec));
                                                            freeRecord((yyvsp[-3].rec));
                                                            freeRecord((yyvsp[0].rec));
                                                            (yyval.rec) = createRecord(s, "");
                                                            free(s);
    }
#line 2382 "y.tab.c"
    break;

  case 74: /* factor: ID  */
#line 681 "parser.y"
                       {(yyval.rec) = createRecord((yyvsp[0].sValue), "");
                      free((yyvsp[0].sValue));}
#line 2389 "y.tab.c"
    break;

  case 75: /* factor: INT  */
#line 683 "parser.y"
                     {(yyval.rec) = createRecord((yyvsp[0].sValue), "");
                      free((yyvsp[0].sValue));}
#line 2396 "y.tab.c"
    break;

  case 76: /* factor: FLOAT  */
#line 685 "parser.y"
                     {(yyval.rec) = createRecord((yyvsp[0].sValue), "");
                      free((yyvsp[0].sValue));}
#line 2403 "y.tab.c"
    break;

  case 77: /* factor: STRING  */
#line 687 "parser.y"
                      {(yyval.rec) = createRecord((yyvsp[0].sValue), "");
                      free((yyvsp[0].sValue));}
#line 2410 "y.tab.c"
    break;

  case 78: /* factor: DOUBLE  */
#line 689 "parser.y"
                     {(yyval.rec) = createRecord((yyvsp[0].sValue), "");
                      free((yyvsp[0].sValue));}
#line 2417 "y.tab.c"
    break;

  case 79: /* factor: BOOL_LIT  */
#line 691 "parser.y"
                     {(yyval.rec) = createRecord((yyvsp[0].sValue), "");
                      free((yyvsp[0].sValue));}
#line 2424 "y.tab.c"
    break;

  case 80: /* factor: STRING_LIT  */
#line 693 "parser.y"
                     {(yyval.rec) = createRecord((yyvsp[0].sValue), "");
                      free((yyvsp[0].sValue));}
#line 2431 "y.tab.c"
    break;

  case 81: /* factor: VOID  */
#line 695 "parser.y"
                      {(yyval.rec) = createRecord((yyvsp[0].sValue), "");
                      free((yyvsp[0].sValue));}
#line 2438 "y.tab.c"
    break;

  case 82: /* call: ID '(' exps_op ')'  */
#line 700 "parser.y"
                            {char * s = cat((yyvsp[-3].sValue), "(", (yyvsp[-1].rec)->code, ")", "", "");
                           free((yyvsp[-3].sValue));
                           freeRecord((yyvsp[-1].rec));
                           (yyval.rec) = createRecord(s, "");
                           free(s);
                          }
#line 2449 "y.tab.c"
    break;

  case 83: /* exps_op: %empty  */
#line 708 "parser.y"
                  {(yyval.rec) = createRecord("","");}
#line 2455 "y.tab.c"
    break;

  case 84: /* exps_op: exps  */
#line 709 "parser.y"
                {(yyval.rec) = (yyvsp[0].rec);}
#line 2461 "y.tab.c"
    break;

  case 85: /* exps: exp  */
#line 712 "parser.y"
                       {(yyval.rec) = (yyvsp[0].rec);}
#line 2467 "y.tab.c"
    break;

  case 86: /* exps: exp ',' exps  */
#line 713 "parser.y"
                     {char * s = cat((yyvsp[-2].rec)->code, ", ", (yyvsp[0].rec)->code, "", "", "");
                      freeRecord((yyvsp[-2].rec));
                      freeRecord((yyvsp[0].rec));
                      (yyval.rec) = createRecord(s, "");
                      free(s);                      
                     }
#line 2478 "y.tab.c"
    break;


#line 2482 "y.tab.c"

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

#line 721 "parser.y"

  
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
