/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
    ASSIGN = 264,                  /* ASSIGN  */
    MAIN = 265,                    /* MAIN  */
    END_MAIN = 266,                /* END_MAIN  */
    PRINT = 267,                   /* PRINT  */
    RETURN = 268,                  /* RETURN  */
    EQUALS = 269,                  /* EQUALS  */
    DIFF = 270,                    /* DIFF  */
    LESS = 271,                    /* LESS  */
    GREATER = 272,                 /* GREATER  */
    LESSEQUALS = 273,              /* LESSEQUALS  */
    GREATEREQUALS = 274,           /* GREATEREQUALS  */
    AND = 275,                     /* AND  */
    OR = 276,                      /* OR  */
    XOR = 277,                     /* XOR  */
    NOT = 278,                     /* NOT  */
    TYPE = 279,                    /* TYPE  */
    STRING_LIT = 280,              /* STRING_LIT  */
    BOOL_LIT = 281,                /* BOOL_LIT  */
    ID = 282,                      /* ID  */
    INT = 283,                     /* INT  */
    FLOAT = 284,                   /* FLOAT  */
    DOUBLE = 285,                  /* DOUBLE  */
    INCREMENT = 286,               /* INCREMENT  */
    DECREMENT = 287,               /* DECREMENT  */
    INCREMENT_ASSIGN = 288,        /* INCREMENT_ASSIGN  */
    DECREMENT_ASSIGN = 289,        /* DECREMENT_ASSIGN  */
    PLUS = 290,                    /* PLUS  */
    MINUS = 291,                   /* MINUS  */
    MULT = 292,                    /* MULT  */
    DIVISION = 293,                /* DIVISION  */
    EXPOENT = 294                  /* EXPOENT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parser.y"

	char * sValue;  /* string value */
	struct record * rec;
 

#line 109 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
