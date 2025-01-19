%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./lib/record.h"
#include "./lib/matrix.h"

int yylex(void);
int yyerror(char *s);
extern int yylineno;
extern char * yytext;
extern FILE * yyin, * yyout;

char * cat(char *, char *, char *, char *, char *, char *);
int labelCounterIf = 1; // Contador global para os rótulos goto if
int labelCounterIfElse = 1; // Contador global para os rótulos goto if-else
int labelCounterWhile = 1; // Contador global para os rótulos goto while

%}

%union {
	char * sValue;         // string value
	struct record * rec;
 };

%token FUNCTION END_FUNCTION 
%token IF THEN ELSE END_IF WHILE END_WHILE FOR ASSIGN
%token MAIN END_MAIN 
%token PRINT RETURN
%token EQUALS DIFF LESS GREATER LESSEQUALS GREATEREQUALS
%token AND OR XOR NOT
%token <sValue> TYPE STRING_LIT BOOL_LIT ID
%token <sValue> INT FLOAT DOUBLE
%token <sValue> INCREMENT DECREMENT INCREMENT_ASSIGN DECREMENT_ASSIGN
%token <sValue> PLUS MINUS MULT DIVISION EXPOENT 

%type <rec> subprogs subprog args_op args arg ids main cmds cmd dms dm mtr_row mtr_rows
%type <rec> cond return write exp term factor call exps_op exps iteration

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

cmd : cond                      {$$ = $1;}
    | return                    {$$ = $1;}
    | write                     {$$ = $1;}
    | iteration                 {$$ = $1;}
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
    | TYPE ID dms ';' {
      //int a[2];
      char *s = cat($1, " ", $2, $3->code, ";", "");
      free($1);
      free($2);
      freeRecord($3);
      $$ = createRecord(s, "");
      free(s);
    }
    | ID dms ASSIGN exp ';' { 
      char *s = cat($1, $2->code, " = ", $4->code, ";", "");
      free($1);
      freeRecord($2);
      freeRecord($4);
      $$ = createRecord(s, "");
      free(s);
    }
    | TYPE ID dms ASSIGN '(' mtr_rows ')' ';' { 
      char *s = cat($1, " ", $2, " ", "", "");
      char *s1 = cat(s, $3->code, " = {", $6->code, "};", "");
      free($1);
      free($2);
      freeRecord($3);
      freeRecord($6);
      $$ = createRecord(s1, "");
      free(s);
      free(s1);
    }
    ;     

dms: dm
    | dms dm {
      char *s = cat($1->code, $2->code, "", "", "", "");
      freeRecord($1);
      freeRecord($2);
      $$ = createRecord(s, "");
      free(s);
    } 
    ;

dm: '[' ']' { 
      char *s = cat("[", "]", "", "", "", "");
      $$ = createRecord(s, "");
      free(s);
     }
     | '[' term ']' {
      char *s = cat("[", $2->code, "]", "", "", "");
      freeRecord($2);
      $$ = createRecord(s, "");
      free(s);
     }
    ; 

mtr_rows: {
           $$ = createRecord("{}", "");
        }
        | mtr_row {
            char *s = cat($1->code, "", "", "", "", "");
            freeRecord($1);
            $$ = createRecord(s, "");
            free(s);
         }
         | mtr_row ',' mtr_rows  {
          char *s = cat($1->code, "," , $3->code, "", "", "");
          freeRecord($1);
          freeRecord($3);
          $$ = createRecord(s, "");
          free(s);
         }
         ;

mtr_row: '{' '}' {
          $$ = createRecord("{}", "");
        }
        | '{' exps '}' {
          char *s = cat("{", $2->code, "}", "", "", "");
          freeRecord($2);
          $$ = createRecord(s, "");
          free(s);
        }
        ;

cond : IF exp THEN cmds END_IF
      {
        // Incrementa o contador global
        int currentLabelIf = labelCounterIf++;
        
        // Gera rótulos únicos com base no contador
        char labelIf[20];
        char labelEndIf[20];
        snprintf(labelIf, sizeof(labelIf), "goto_if_%d", currentLabelIf);
        snprintf(labelEndIf, sizeof(labelEndIf), "goto_end_if_%d", currentLabelIf);

        // Etapa 1: Concatena até o "goto labelIf"
        char *part1 = cat("if ", $2->code, " {\n goto ", labelIf, "; \n", "");

        // Etapa 2: Concatena o "goto labelEndIf" e abre o bloco de código
        char *part2 = cat("} \n goto ", labelEndIf, "; \n", labelIf, ": \n", $4->code);

        // Etapa 3: Concatena o final com o "goto_end_if"
        char *s = cat(part1, part2, labelEndIf, ": \n", "", "");
        free(part1);
        free(part2);
        freeRecord($2);
        freeRecord($4);
        $$ = createRecord(s, "");
        free(s);
      }
      | IF exp THEN cmds ELSE cmds END_IF
      {
        // Incrementa o contador global
        int currentLabelIfElse = labelCounterIfElse++;
        
        // Gera rótulos únicos com base no contador
        char labelIf[20];
        char labelElse[20];
        char labelEndIfElse[20];
        snprintf(labelIf, sizeof(labelIf), "goto_if_c_%d", currentLabelIfElse);
        snprintf(labelElse, sizeof(labelElse), "goto_else_c_%d", currentLabelIfElse);
        snprintf(labelEndIfElse, sizeof(labelEndIfElse), "goto_end_if_else_%d", currentLabelIfElse);

        // Etapa 1: Concatena a condição e os rótulos de "then" e "else"
        char *part1 = cat("if ", $2->code, " {\n goto ", labelIf, "; \n", "");
        char *part2 = cat("} \n goto ", labelElse, "; \n", "", "", "");

        // Etapa 2: Concatena o bloco "then" com o rótulo de fim
        char *part3 = cat(labelIf, ": \n", $4->code, "goto ", labelEndIfElse, "; \n");

        // Etapa 3: Concatena o bloco "else" e o rótulo de fim
        char *part4 = cat(labelElse, ": \n", $6->code, labelEndIfElse, ": \n", "");

        // Concatenar as partes do código gerado
        char *s = cat(part1, part2, part3, part4, "", "");
        free(part1);
        free(part2);
        free(part3);
        free(part4);
        freeRecord($2);
        freeRecord($4);
        freeRecord($6);
        $$ = createRecord(s, "");
        free(s);
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

iteration : WHILE '(' exp ')' cmds END_WHILE
{
    // Incrementar o contador de rótulos para gerar identificadores únicos
    int currentLabelWhile = labelCounterWhile++;
    char labelStart[30], labelEnd[30], labelBody[30];

    // Criar rótulos únicos com base no contador
    snprintf(labelStart, sizeof(labelStart), "label_while_start_%d", currentLabelWhile);
    snprintf(labelEnd, sizeof(labelEnd), "label_while_end_%d", currentLabelWhile);
    snprintf(labelBody, sizeof(labelBody), "label_while_body_%d", currentLabelWhile);

    // Gerar as partes do código do bloco WHILE
    char *part1 = cat(labelStart, ": if ((", $3->code, ")) goto ", labelBody, ";\n");
    char *part2 = cat("goto ", labelEnd, ";\n", labelBody, ":\n", $5->code);
    char *part3 = cat("goto ", labelStart, ";\n", labelEnd, ": \n", "");

    // Concatenar todas as partes do código gerado
    char *s = cat(part1, part2, part3, "", "", "");
    free(part1);
    free(part2);
    free(part3);
    freeRecord($3);
    freeRecord($5);

    // Criar o registro final para a regra WHILE
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