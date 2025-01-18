%{
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

%}

%union {
	char * sValue;  /* string value */
	struct record * rec;
 };

%token FUNCTION END_FUNCTION 
%token IF THEN ELSE END_IF ASSIGN
%token MAIN END_MAIN 
%token PRINT RETURN
%token EQUALS DIFF LESS GREATER LESSEQUALS GREATEREQUALS
%token AND OR XOR NOT
%token <sValue> TYPE STRING_LIT BOOL_LIT ID
%token <sValue> INT FLOAT DOUBLE
%token <sValue> INCREMENT DECREMENT INCREMENT_ASSIGN DECREMENT_ASSIGN
%token <sValue> PLUS MINUS MULT DIVISION EXPOENT 

%type <rec> subprogs subprog args_op args arg ids main cmds cmd 
%type <rec> cond return write exp term factor call exps_op exps

%left PLUS MINUS
%left MULT DIVISION
%left AND
%left OR XOR
%left EQUALS DIFF LESS GREATER LESSEQUALS GREATEREQUALS
%right EXPOENT
%right NOT

%start prog

%%
prog : subprogs main {
                      char *headers = "#include<stdio.h>\n#include<stdlib.h>\n#include<stdbool.h>\n#include<math.h>\n\n";
                      char *s = cat(headers, $1->code, "\n", $2->code, "", "");
                      fprintf(yyout, "%s", s);
                      freeRecord($1);
                      freeRecord($2);
                      free(s);                          
                     }
     ;

subprogs :                  {$$ = createRecord("","");}
         | subprog subprogs {char * s = cat($1->code, "\n", $2->code, "", "", "");
                             freeRecord($1);
                             freeRecord($2);
                             $$ = createRecord(s, "");
                             free(s);
                            } 
         ;

subprog : TYPE FUNCTION ID '(' args_op ')' cmds END_FUNCTION 
           {char * s1 = cat($1, " ", $3, "(", $5->code, "");
            char * s2 = cat(s1, ")\n", "{\n", $7->code, "}", "");
            free(s1);
            free($1);
            free($3);
            freeRecord($5);
            freeRecord($7);
            $$ = createRecord(s2, "");
            free(s2);
           }
        ;

args_op :       {$$ = createRecord("","");}
        | args  {$$ = $1;}
        ;        

args : arg          {$$ = $1;}
     | arg ';' args {char * s = cat($1->code, "; ", $3->code, "", "", "");
                     freeRecord($1);
                     freeRecord($3);
                     $$ = createRecord(s, "");
                     free(s);
                    }
     ;

arg : TYPE ids {char * s = cat($1, " ", $2->code, "", "", "");
                free($1);
                freeRecord($2);
                $$ = createRecord(s, "");
                free(s);
               }
      | TYPE ids ',' arg {char * s = cat($1, " ", $2->code, ", ", $4->code, "");
                free($1);
                freeRecord($2);
                freeRecord($4);
                $$ = createRecord(s, "");
                free(s);
               }
    ;

ids : ID         {$$ = createRecord($1, "");
                  free($1);
                 }
    ;

main : MAIN cmds END_MAIN {char * s = cat("int main(){\n", $2->code, "}", "", "", "");
                                  freeRecord($2);
                                  $$ = createRecord(s, "");
                                  free(s);
                                 }
          ;

cmds :           {$$ = createRecord("","");}
     | cmd cmds  {char * s = cat($1->code, "\n", $2->code, "", "", "");
                  freeRecord($1);
                  freeRecord($2);
                  $$ = createRecord(s, "");
                  free(s);
                 }
     ;

cmd : cond   {$$ = $1;}
    | return {$$ = $1;}
    | write  {$$ = $1;}
    | TYPE ID ASSIGN exp ';' {char * s = cat($1, " ", $2, " = ", $4->code, ";");
                              free($1);
                              free($2);
                              freeRecord($4);
                              $$ = createRecord(s, "");
                              free(s);
      }
    | TYPE exp ';' {char * s = cat($1, " ", $2->code, ";", "", "");
                     free($1);
                     freeRecord($2);
                     $$ = createRecord(s, "");
                     free(s);
                    }
    | TYPE exp ',' cmd {char * s = cat($1, " ", $2->code, ", ", $4->code, "");
                        free($1);
                        freeRecord($2);
                        freeRecord($4);
                        $$ = createRecord(s, "");
                        free(s);
                       }
    | exp ',' cmd {char * s = cat($1->code, ", ", $3->code, "", "", "");
                        freeRecord($1);
                        freeRecord($3);
                        $$ = createRecord(s, "");
                        free(s);
                       }
    | exp ';' {char * s = cat($1->code, ";", "", "", "", "");
                freeRecord($1);
                $$ = createRecord(s, "");
                free(s);
               }
    | ID ASSIGN exp ';' { 
         char *s = cat($1, " = ", $3->code, ";", "", "");
         free($1);
         freeRecord($3);
         $$ = createRecord(s, "");
         free(s);
      }
    | ID INCREMENT ';' { 
         char *s = cat($1, "++", ";", "", "", "");
         free($1);
         $$ = createRecord(s, "");
         free(s);
      }
    | ID DECREMENT ';' { 
         char *s = cat($1, "--", ";", "", "", "");
         free($1);
         $$ = createRecord(s, "");
         free(s);
      }
    | INCREMENT ID ';' { 
         char *s = cat("++", $2, ";", "", "", "");
         free($2);
         $$ = createRecord(s, "");
         free(s);
      }
    | DECREMENT ID ';' { 
         char *s = cat("--", $2, ";", "", "", "");
         free($2);
         $$ = createRecord(s, "");
         free(s);
      }
    | ID INCREMENT_ASSIGN exp ';' { 
         char *s = cat($1, " += ", $3->code, ";", "", "");
         free($1);
         freeRecord($3);
         $$ = createRecord(s, "");
         free(s);
      }
    | ID DECREMENT_ASSIGN exp ';' { 
         char *s = cat($1, " -= ", $3->code, ";", "", "");
         free($1);
         freeRecord($3);
         $$ = createRecord(s, "");
         free(s);
      }
    ;          
/*
cond : IF exp THEN cmds END_IF     {char * s = cat("if ", $2->code, " {\n", $4->code, "}", "");
                                    freeRecord($2);
                                    freeRecord($4);
                                    $$ = createRecord(s, "");
                                    free(s);
                                   }
     | IF exp THEN cmds ELSE cmds END_IF 
                                 {char * s1 = cat("if ", $2->code, " {\n", $4->code, "}", "");
                                  char * s2 = cat(s1, "\nelse ", "{\n", $6->code, "}", "");
                                  free(s1);
                                  freeRecord($2);
                                  freeRecord($4);
                                  freeRecord($6);
                                  $$ = createRecord(s2, "");
                                  free(s2);
                                 }
            ;
*/

cond : IF exp THEN cmds END_IF     {char * s = cat("if ", $2->code, " {\n", $4->code, "}", "");
                                    freeRecord($2);
                                    freeRecord($4);
                                    $$ = createRecord(s, "");
                                    free(s);
                                   }
     | IF exp THEN cmds ELSE cmds END_IF 
                                 {char * s1 = cat("if ", $2->code, " {\n", $4->code, "}", "");
                                  char * s2 = cat(s1, "\nelse ", "{\n", $6->code, "}", "");
                                  free(s1);
                                  freeRecord($2);
                                  freeRecord($4);
                                  freeRecord($6);
                                  $$ = createRecord(s2, "");
                                  free(s2);
                                 }
            ;

return : RETURN exp ';'{char * s = cat("return ", $2->code, ";", "", "", "");
                         freeRecord($2);
                         $$ = createRecord(s, "");
                         free(s);
                        }
        ;

write : PRINT '(' exps ')' ';' {char * s = cat("printf", "(", $3->code, ")", ";", "");
                                  freeRecord($3);
                                  $$ = createRecord(s, "");
                                  free(s);
                                 }
        ;

exp : term        {$$ = $1;}
    | call        {$$ = $1;}
    | '(' exp ')' {char * s = cat("(", $2->code, ")", "", "", "");
                   freeRecord($2);
                   $$ = createRecord(s, "");
                   free(s);}
    | exp EQUALS term   {char * s = cat($1->code, " == ", $3->code, "", "", "");
                         freeRecord($1);
                         freeRecord($3);
                         $$ = createRecord(s, "");
                         free(s);}
    | exp DIFF term   {char * s = cat($1->code, " != ", $3->code, "", "", "");
                      freeRecord($1);
                      freeRecord($3);
                      $$ = createRecord(s, "");
                      free(s);}
    | exp LESS term   {char * s = cat($1->code, " < ", $3->code, "", "", "");
                      freeRecord($1);
                      freeRecord($3);
                      $$ = createRecord(s, "");
                      free(s);}
    | exp GREATER term   {char * s = cat($1->code, " > ", $3->code, "", "", "");
                         freeRecord($1);
                         freeRecord($3);
                         $$ = createRecord(s, "");
                         free(s);}
    | exp LESSEQUALS term   {char * s = cat($1->code, " <= ", $3->code, "", "", "");
                            freeRecord($1);
                            freeRecord($3);
                            $$ = createRecord(s, "");
                            free(s);}
    | exp GREATEREQUALS term   {char * s = cat($1->code, " >= ", $3->code, "", "", "");
                               freeRecord($1);
                               freeRecord($3);
                               $$ = createRecord(s, "");
                               free(s);}
    | exp AND term   {char * s = cat($1->code, " && ", $3->code, "", "", "");
                     freeRecord($1);
                     freeRecord($3);
                     $$ = createRecord(s, "");
                     free(s);}
    | exp OR term   {char * s = cat($1->code, " || ", $3->code, "", "", "");
                    freeRecord($1);
                    freeRecord($3);
                    $$ = createRecord(s, "");
                    free(s);}
    | exp XOR term   {char * s = cat($1->code, " ^ ", $3->code, "", "", "");
                     freeRecord($1);
                     freeRecord($3);
                     $$ = createRecord(s, "");
                     free(s);}
    | NOT exp   {char * s = cat("!", $2->code, "", "", "", "");
                  freeRecord($2);
                  $$ = createRecord(s, "");
                  free(s);}
    | exp PLUS term   {char * s = cat($1->code, " + ", $3->code, "", "", "");
                      freeRecord($1);
                      freeRecord($3);
                      $$ = createRecord(s, "");
                      free(s);}
    | exp MINUS term   {char * s = cat($1->code, " - ", $3->code, "", "", "");
                       freeRecord($1);
                       freeRecord($3);
                       $$ = createRecord(s, "");
                       free(s);}
    | exp MULT term   {char * s = cat($1->code, " * ", $3->code, "", "", "");
                      freeRecord($1);
                      freeRecord($3);
                      $$ = createRecord(s, "");
                      free(s);}
    | exp DIVISION term   {char * s = cat($1->code, " / ", $3->code, "", "", "");
                       freeRecord($1);
                       freeRecord($3);
                       $$ = createRecord(s, "");
                       free(s);}
    | exp EXPOENT term   {char * s = cat("pow(", $1->code, ", ", $3->code, ")", "");
                         freeRecord($1);
                         freeRecord($3);
                         $$ = createRecord(s, "");
                         free(s);}
    ;       

term : factor        {$$ = $1;}
     ;

factor : ID          {$$ = createRecord($1, "");
                      free($1);}
       |INT          {$$ = createRecord($1, "");
                      free($1);}
       | FLOAT       {$$ = createRecord($1, "");
                      free($1);}
       | DOUBLE      {$$ = createRecord($1, "");
                      free($1);}
       | BOOL_LIT    {$$ = createRecord($1, "");
                      free($1);}
       | STRING_LIT  {$$ = createRecord($1, "");
                      free($1);}
       ;

call : ID '(' exps_op ')' {char * s = cat($1, "(", $3->code, ")", "", "");
                           free($1);
						   freeRecord($3);
                           $$ = createRecord(s, "");
                           free(s);
                          }    
          ;

exps_op :       {$$ = createRecord("","");}
        | exps  {$$ = $1;}
        ;

exps : exp           {$$ = $1;}
     | exp ',' exps  {char * s = cat($1->code, ", ", $3->code, "", "", "");
                      freeRecord($1);
                      freeRecord($3);
                      $$ = createRecord(s, "");
                      free(s);                      
      				 }
     ;        

%%

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