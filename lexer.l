%{
  #include <stdio.h>
  #include "y.tab.h"
  
  extern int yyerror (char *msg);  
  int isUnaryMinus = 1;           // Variável para controlar se o MINUS é unário ou binário
%}

%option yylineno

%%

[ \t\r]+                {}
[\n]+                   {}
[0-9]+                  {yylval.sValue = strdup(yytext); 
                         return INT;}
[0-9]+\.[0-9]+          {yylval.sValue = strdup(yytext);
                         return FLOAT;}
[0-9]+\.[0-9]+([eE][+-]?[0-9]+)? {yylval.sValue = strdup(yytext);
                                  return DOUBLE;}
"def"                   {return FUNCTION;}
"end_def"               {return END_FUNCTION;}
"="                     {return(ASSIGN); }
"+="                    {return(INCREMENT_ASSIGN);}
"-="                    {return(DECREMENT_ASSIGN);}
"++"                    {return(INCREMENT);}
"--"                    {return(DECREMENT);}
[iI][fF]                {return IF;}
[tT][hH][eE][nN]        {return THEN;}
[eE][lL][sS][eE]        {return ELSE;}
[eE][nN][dD][_][iI][fF] {return END_IF;}
"=="                    {return(EQUALS);}
"!="                    {return(DIFF);}
"<"                     {return(LESS);}
">"                     {return(GREATER);}
"<="                    {return(LESSEQUALS);}
">="                    {return(GREATEREQUALS);}
"and"                   {return(AND);}
"or"                    {return(OR);}
"xor"                   {return(XOR);}
"not"                   {return(NOT);}
"while"                 {return(WHILE);}
"end_while"             {return(END_WHILE);}
"for"                   {return(FOR);}
"end_for"               {return(END_FOR);}
"+"                     {return(PLUS);}
"-"                     {if (isUnaryMinus) {
                                        isUnaryMinus = 0; 
                                        return UMINUS;  // Tratar como operador unário
                                    } else {
                                        return MINUS;   // Tratar como operador binário
                                    }}
"*"                     {return(MULT);}
"/"                     {return(DIVISION);}
"^"                     {return(EXPOENT);}
"main"                  {return MAIN;}
"end_main"              {return END_MAIN;}
"print"                 {return PRINT;}
"scan"                  {return SCAN;}
"return"                {return RETURN;}
"("                     {return yytext[0];}
")"                     {return yytext[0];}
"["                     {return yytext[0];}
"]"                     {return yytext[0];}
"{"                     {return yytext[0];}
"}"                     {return yytext[0];}
","                     {return yytext[0];}
":"                     {return yytext[0];}
";"                     {return yytext[0];}
\.                      {return DOT;}
"int"                   {yylval.sValue = strdup("int"); 
                         return TYPE;}
"int&"                  {yylval.sValue = strdup("int&"); 
                         return TYPE;}
"float"                 {yylval.sValue = strdup("float"); 
                         return TYPE;}
"rational_t"            {yylval.sValue = strdup("rational_t"); 
                         return TYPE;}
"double"                {yylval.sValue = strdup("double"); 
                         return TYPE;}
"bool"                  {yylval.sValue = strdup("bool"); 
                         return TYPE;}
"string"                 {yylval.sValue = strdup("string"); 
                         return TYPE;}
"void"                 {yylval.sValue = strdup("void"); 
                         return TYPE;}
"true"                  {yylval.sValue = strdup("true"); 
                         return BOOL_LIT;}                       
"false"                 {yylval.sValue = strdup("false"); 
                         return BOOL_LIT;}
\"(\\.|[^\"])*\"        {yylval.sValue = strdup(yytext); 
                         return STRING_LIT;}                       
&?[a-zA-Z_][a-zA-Z0-9_]*&?    {yylval.sValue = strdup(yytext); isUnaryMinus = 0;
                         return ID;}
\/\/.*                  {}
\/\*([^*]|\*+[^\/])*\*+\/ {}
.                       {fprintf(stderr, "Erro léxico: caractere inválido '%s' na linha %d\n", yytext, yylineno);
                         exit(1);}
%%

#ifndef yywrap
   int yywrap (void) {return 1;}
#endif