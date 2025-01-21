  %{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "./lib/record.h"
  #include "./lib/hashtable.h"
#include "./lib/scope.h"
#include "./lib/label_generator.h"
#include "./lib/function_hashtable.h"
#include "./lib/type_hashtable.h"
#include "./lib/label_generator.h"
  
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
  
   char * generateKey(char *, char *);
char * verificaEscopos(stack_scope * stack , char * id);
 hash_table_base *symbol_table;
stack_scope *stackScope;
function_table *functionTable;
type_table *typeTable;

  %}
  
  %union {
    char * sValue;         // string value
    struct record * rec;
  };
  
  %token FUNCTION END_FUNCTION 
  %token IF THEN ELSE END_IF WHILE END_WHILE FOR END_FOR ASSIGN
  %token MAIN END_MAIN 
  %token PRINT SCAN RETURN
  %token EQUALS DIFF LESS GREATER LESSEQUALS GREATEREQUALS
  %token AND OR XOR NOT
  %token <sValue> TYPE STRING_LIT BOOL_LIT ID VOID
  %token <sValue> INT FLOAT DOUBLE STRING
  %token <sValue> INCREMENT DECREMENT INCREMENT_ASSIGN DECREMENT_ASSIGN
  %token <sValue> PLUS MINUS MULT DIVISION EXPOENT 
  
  %type <rec> subprogs subprog args_op args arg ids main cmds cmd 
  %type <rec> cond return write read exp term factor call exps_op exps iteration for_incr 
  
  %left PLUS MINUS
  %left MULT DIVISION
  %left AND
  %left OR XOR
  %left EQUALS DIFF LESS GREATER LESSEQUALS GREATEREQUALS
  %right ASSIGN INCREMENT_ASSIGN DECREMENT_ASSIGN
  %right EXPOENT
  %right NOT
  %left '[' ']'
  
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
  
  subprog : TYPE FUNCTION ID {scope_push(stackScope, $3);} '(' args_op ')' cmds END_FUNCTION 
           {
            if(function_table_get(functionTable, $3) != NULL){
                yyerror("função já existente");
            }
            if(type_table_get(typeTable, $1) == NULL){
                yyerror("Tipo não encontrado");
            }

            function_table_set(functionTable, $3, $1, $6->code);
            char * s1 = cat($1, " ", $3, "(", $6->code, "");
            char * s2 = cat(s1, ")\n", "{\n", $8->code, "}", "");
            free(s1);
            free($1);
            free($3);
            freeRecord($6);
            freeRecord($8);
            $$ = createRecord(s2, "");
            free(s2);
            scope_pop(stackScope);
           }
           | TYPE '[' ']' '[' ']' FUNCTION ID {scope_push(stackScope, $7);} '(' args_op ')' cmds END_FUNCTION 
           {char * s1 = cat($1, " ", $7, "(", $10->code, "");
            char * s2 = cat(s1, ")\n", "{\n", $12->code, "}", "");
            free(s1);
            free($1);
            free($7);
            freeRecord($10);
            freeRecord($12);
            $$ = createRecord(s2, "");
            free(s2);
            scope_pop(stackScope);
           }
           | '(' TYPE ',' TYPE ')' FUNCTION ID {scope_push(stackScope, $7);} '(' args_op ')' cmds END_FUNCTION 
           {char * s1 = cat("(", $2, ", ", $4, ") ", $7);
            char * s2 = cat(s1, "(", $10->code, ")\n{\n", $12->code, "}");
            free(s1);
            free($2);
            free($4);
            free($7);
            freeRecord($10);
            freeRecord($12);
            $$ = createRecord(s2, "");
            free(s2);
            scope_pop(stackScope);
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
  
  arg : TYPE ids {
    if(type_table_get(typeTable, $1) == NULL){
                  yyerror("tipo invalido");
                }
    char * s = cat($1, " ", $2->code, "", "", "");
                free($1);
                freeRecord($2);
                $$ = createRecord(s, "");
                free(s);
               }
      | TYPE ids ',' arg {
        if(type_table_get(typeTable, $1) == NULL){
                  yyerror("tipo invalido");
                }
        char * s = cat($1, " ", $2->code, ", ", $4->code, "");
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
  
  main : MAIN {scope_push(stackScope, "main");} cmds END_MAIN {
    char * s = cat("int main(){\n", $3->code, "}", "", "", "");
                                  freeRecord($3);
                                  $$ = createRecord(s, "");
                                  free(s);
                                  scope_pop(stackScope);
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
  
  cmd : cond                    {$$ = $1;}
    | return                    {$$ = $1;}
    | write                     {$$ = $1;}
    | read                      {$$ = $1;}
    | iteration                 {$$ = $1;}
    | TYPE ID ASSIGN exp ';' {
      if(type_table_get(typeTable, $1) == NULL){
        yyerror("tipo não encontrado");
      }
      char *key = generateKey($2, scope_get(stackScope));
      if(hashtable_get(symbol_table, key) != NULL){
        yyerror("id já usada");
      }
      yyerror(key);
      hashtable_set(symbol_table, key, $1);
      free(key);
      char * s = cat($1, " ", $2, " = ", $4->code, ";");
                              free($1);
                              free($2);
                              freeRecord($4);
                              $$ = createRecord(s, "");
                              free(s);
      }
    | TYPE exps ';' {
      if(type_table_get(typeTable, $1) == NULL){
        yyerror("tipo não encontrado");
      }
      char * s = cat($1, " ", $2->code, ";", "", "");
                     free($1);
                     freeRecord($2);
                     $$ = createRecord(s, "");
                     free(s);
                    }
    | exps ';' {char * s = cat($1->code, ";", "", "", "", "");
                freeRecord($1);
                $$ = createRecord(s, "");
                free(s);
               }
    | ID ASSIGN exp ';' { 
        if(function_table_get(functionTable, $1) != NULL) {
          yyerror("id de função");
        }
        stack_scope * duplicate = scope_duplicate(stackScope);
        char * typeId = verificaEscopos(duplicate, $1);
        if(typeId == NULL){
          yyerror("id inexistente");
        }
        if(strcmp(typeId, $3->opt1) != 0){
          yyerror("tipos incompativeis");
        }
         char *s = cat($1, " = ", $3->code, ";", "", "");
         free($1);
         freeRecord($3);
         $$ = createRecord(s, "");
         free(s);
         free(typeId);
         scope_free(duplicate);
      }
    | ID INCREMENT ';' {
        if(function_table_get(functionTable, $1) != NULL) {
          yyerror("id de função");
        }
        stack_scope * duplicate = scope_duplicate(stackScope);
        char * typeId = verificaEscopos(duplicate, $1);
        if(typeId == NULL){
          yyerror("id inexistente");
        }
        if(!(strcmp(typeId, "int") == 0 || strcmp(typeId, "float") == 0 || strcmp(typeId, "double") == 0)){
          yyerror("operação restrita a tipos numericos");
        }
         char *s = cat($1, "++", ";", "", "", "");
         free($1);
         $$ = createRecord(s, "");
         free(s);
         free(typeId);
         scope_free(duplicate);
      }
    | ID DECREMENT ';' { 
      if(function_table_get(functionTable, $1) != NULL) {
          yyerror("id de função");
        }
        stack_scope * duplicate = scope_duplicate(stackScope);
        char * typeId = verificaEscopos(duplicate, $1);
        if(typeId == NULL){
          yyerror("id inexistente");
        }
        if(!(strcmp(typeId, "int") == 0 || strcmp(typeId, "float") == 0 || strcmp(typeId, "double") == 0)){
          yyerror("operação restrita a tipos numericos");
        }
         char *s = cat($1, "--", ";", "", "", "");
         free($1);
         $$ = createRecord(s, "");
         free(s);
         free(typeId);
         scope_free(duplicate);
      }
    | INCREMENT ID ';' { 
      if(function_table_get(functionTable, $2) != NULL) {
          yyerror("id de função");
        }
        stack_scope * duplicate = scope_duplicate(stackScope);
        char * typeId = verificaEscopos(duplicate, $2);
        if(typeId == NULL){
          yyerror("id inexistente");
        }
        if(!(strcmp(typeId, "int") == 0 || strcmp(typeId, "float") == 0 || strcmp(typeId, "double") == 0)){
          yyerror("operação restrita a tipos numericos");
        }
         char *s = cat("++", $2, ";", "", "", "");
         free($2);
         $$ = createRecord(s, "");
         free(s);
         free(typeId);
         scope_free(duplicate);
      }
    | DECREMENT ID ';' { 
      if(function_table_get(functionTable, $2) != NULL) {
          yyerror("id de função");
        }
        stack_scope * duplicate = scope_duplicate(stackScope);
        char * typeId = verificaEscopos(duplicate, $2);
        if(typeId == NULL){
          yyerror("id inexistente");
        }
        if(!(strcmp(typeId, "int") == 0 || strcmp(typeId, "float") == 0 || strcmp(typeId, "double") == 0)){
          yyerror("operação restrita a tipos numericos");
        }
         char *s = cat("--", $2, ";", "", "", "");
         free($2);
         $$ = createRecord(s, "");
         free(s);
         free(typeId);
         scope_free(duplicate);
      }
    | ID INCREMENT_ASSIGN exp ';' { 
      if(function_table_get(functionTable, $1) != NULL) {
          yyerror("id de função");
        }
        stack_scope * duplicate = scope_duplicate(stackScope);
        char * typeId = verificaEscopos(duplicate, $1);
        if(typeId == NULL){
          yyerror("id inexistente");
        }
        if(strcmp(typeId, $3->opt1) != 0){
          yyerror("tipos incompativeis");
        }
         char *s = cat($1, " += ", $3->code, ";", "", "");
         free($1);
         freeRecord($3);
         $$ = createRecord(s, "");
         free(s);
         free(typeId);
         scope_free(duplicate);

      }
    | ID DECREMENT_ASSIGN exp ';' { 
      if(function_table_get(functionTable, $1) != NULL) {
          yyerror("id de função");
        }
        stack_scope * duplicate = scope_duplicate(stackScope);
        char * typeId = verificaEscopos(duplicate, $1);
        if(typeId == NULL){
          yyerror("id inexistente");
        }
        if(strcmp(typeId, $3->opt1) != 0){
          yyerror("tipos incompativeis");
        }
         char *s = cat($1, " -= ", $3->code, ";", "", "");
         free($1);
         freeRecord($3);
         $$ = createRecord(s, "");
         free(s);
         free(typeId);
         scope_free(duplicate);
      }
    ;          
  
  cond : IF exp THEN cmds END_IF
      {
        scope_push(stackScope, generateLabel());
        // Incrementa o contador global
        int currentLabelIf = labelCounterIf++;
        
        // Gera rótulos únicos com base no contador
        char labelIf[30];
        char labelEndIf[30];
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
        scope_pop(stackScope);
      }
      | IF exp THEN cmds ELSE cmds END_IF
      {
        scope_push(stackScope, generateLabel());
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
        scope_pop(stackScope);
      }
      ;
  
  return : RETURN exp ';' {char * s = cat("return ", $2->code, ";", "", "", "");
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

  read : SCAN '(' exps ')' ';' {char * s = cat("scanf", "(", $3->code, ")", ";", "");
                                  freeRecord($3);
                                  $$ = createRecord(s, "");
                                  free(s);
                                 }
        ;
  iteration : WHILE '(' exp ')' {scope_push(stackScope, generateLabel());} cmds END_WHILE
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
        char *part2 = cat("goto ", labelEnd, ";\n", labelBody, ":\n{\n", $6->code);
        char *part3 = cat("}\n", "goto ", labelStart, ";\n", labelEnd, ": \n");
  
        // Concatenar todas as partes do código gerado
        char *s = cat(part1, part2, part3, "", "", "");
        free(part1);
        free(part2);
        free(part3);
        freeRecord($3);
        freeRecord($6);
        $$ = createRecord(s, "");
        free(s);
        scope_pop(stackScope);
    }
    | FOR '(' ID ';' exp ';' for_incr ')' {scope_push(stackScope, generateLabel());} cmds END_FOR
    {
      char * key = generateKey($3, scope_get(stackScope));
      hashtable_set(symbol_table, key, "int");
        // Gerar rótulos únicos para o laço
        int currentLabelFor = labelCounterFor++;
        char labelStart[30], labelEnd[30], labelBody[30];
  
        snprintf(labelStart, sizeof(labelStart), "label_for_start_%d", currentLabelFor);
        snprintf(labelEnd, sizeof(labelEnd), "label_for_end_%d", currentLabelFor);
        snprintf(labelBody, sizeof(labelBody), "label_for_body_%d", currentLabelFor);
  
        // Inicialização
        char *init = cat($3, ";\n", " ", "", "", "");
  
        // Condição (ajustada para if ((...) em vez de if (!(...))
        char *cond = cat("if ((", $5->code, ")) goto ", labelBody, ";\n", "");
        char *skipToEnd = cat("goto ", labelEnd, ";\n", "", "", "");
  
        // Incremento
        char *increment = cat($7->code, "", "", "", "", "");
  
        // Combinar as partes do laço
        char *part1 = cat("\n{\n", init, labelStart, ": ", cond, skipToEnd);
        char *part2 = cat(labelBody, ":\n{\n", $10->code, "}\n", increment, ";\n");
        char *part3 = cat("goto ", labelStart, ";\n", labelEnd, ": \n}\n", "");
  
        char *s = cat(part1, part2, part3, "", "", "");
        free(init);
        free(cond);
        free(skipToEnd);
        free(part1);
        free(part2);
        free(part3);
        free($3);
        freeRecord($5);
        freeRecord($7);
        freeRecord($10);
        $$ = createRecord(s, "");
        free(s);
        free(key);
        scope_pop(stackScope);
    }
    | FOR '(' ID ASSIGN exp ';' exp ';' for_incr ')' {scope_push(stackScope, generateLabel());} cmds END_FOR
    {
      if(strcmp($5->opt1, "int") != 0){
        yyerror("o id do for tem que receber int");
      }
      char * key = generateKey($3, scope_get(stackScope));
      hashtable_set(symbol_table, key, "int");
        // Gerar rótulos únicos para o laço
        int currentLabelFor = labelCounterFor++;
        char labelStart[30], labelEnd[30], labelBody[30];
  
        snprintf(labelStart, sizeof(labelStart), "label_for_start_%d", currentLabelFor);
        snprintf(labelEnd, sizeof(labelEnd), "label_for_end_%d", currentLabelFor);
        snprintf(labelBody, sizeof(labelBody), "label_for_body_%d", currentLabelFor);
  
        // Inicialização
        char *init = cat($3, " ", " = ", $5->code, ";\n", " ");
  
        // Condição (ajustada para if ((...) em vez de if (!(...))
        char *cond = cat("if ((", $7->code, ")) goto ", labelBody, ";\n", "");
        char *skipToEnd = cat("goto ", labelEnd, ";\n", "", "", "");
  
        // Incremento
        char *increment = cat($9->code, "", "", "", "", "");
  
        // Combinar as partes do laço
        char *part1 = cat("\n{\n", init, labelStart, ": ", cond, skipToEnd);
        char *part2 = cat(labelBody, ":\n{\n", $12->code, "}\n", increment, ";\n");
        char *part3 = cat("goto ", labelStart, ";\n", labelEnd, ": \n}\n", "");
  
        char *s = cat(part1, part2, part3, "", "", "");
        free(init);
        free(cond);
        free(skipToEnd);
        free(part1);
        free(part2);
        free(part3);
        free($3);
        freeRecord($5);
        freeRecord($7);
        freeRecord($9);
        freeRecord($12);
        $$ = createRecord(s, "");
        free(s);
        free(key);
        scope_pop(stackScope);
    }
    | FOR '(' TYPE ID ASSIGN exp ';' exp ';' for_incr ')' {scope_push(stackScope, generateLabel());} cmds END_FOR
    {
        if(type_table_get(typeTable, $3) == NULL){
          yyerror("tipo inexistente");
        }
        if(strcmp($3, $6->opt1) != 0){
          yyerror("tipos incompativeis");
        }
        char * key = generateKey($4, scope_get(stackScope));
        hashtable_set(symbol_table, key, $3);
        // Gerar rótulos únicos para o laço
        int currentLabelFor = labelCounterFor++;
        char labelStart[30], labelEnd[30], labelBody[30];
  
        snprintf(labelStart, sizeof(labelStart), "label_for_start_%d", currentLabelFor);
        snprintf(labelEnd, sizeof(labelEnd), "label_for_end_%d", currentLabelFor);
        snprintf(labelBody, sizeof(labelBody), "label_for_body_%d", currentLabelFor);
  
        // Inicialização
        char *init = cat($3, " ", $4, " = ", $6->code, ";\n");
  
        // Condição (ajustada para if ((...) em vez de if (!(...))
        char *cond = cat("if ((", $8->code, ")) goto ", labelBody, ";\n", "");
        char *skipToEnd = cat("goto ", labelEnd, ";\n", "", "", "");
  
        // Incremento
        char *increment = cat($10->code, "", "", "", "", "");
  
        // Combinar as partes do laço
        char *part1 = cat("\n{\n", init, labelStart, ": ", cond, skipToEnd);
        char *part2 = cat(labelBody, ":\n{\n", $13->code, "}\n", increment, ";\n");
        char *part3 = cat("goto ", labelStart, ";\n", labelEnd, ": \n}\n", "");
  
        char *s = cat(part1, part2, part3, "", "", "");
        free(init);
        free(cond);
        free(skipToEnd);
        free(part1);
        free(part2);
        free(part3);
        free($3);
        free($4);
        freeRecord($6);
        freeRecord($8);
        freeRecord($10);
        freeRecord($13);
        $$ = createRecord(s, "");
        free(s);
        free(key);
        scope_pop(stackScope);
    }
    | FOR '(' TYPE ID ':' ID ')' {scope_push(stackScope, generateLabel());} cmds END_FOR
    {
      if(type_table_get(typeTable, $3) == NULL){
        yyerror("tipo inexistente");
      }
      stack_scope * duplicate = scope_duplicate(stackScope);
      char *typeId = verificaEscopos(duplicate, $6);
      if(typeId == NULL){
        yyerror("id inexistente todos os escopos");
      }
      char * key = generateKey($4, scope_get(stackScope));
      hashtable_set(symbol_table, key, $3);
        // Incrementa o contador global de rótulos
        int currentLabelFor = labelCounterFor++;
        char labelStart[30], labelBody[30], labelEnd[30];
  
        snprintf(labelStart, sizeof(labelStart), "label_for_start_%d", currentLabelFor);
        snprintf(labelBody, sizeof(labelBody), "label_for_body_%d", currentLabelFor);
        snprintf(labelEnd, sizeof(labelEnd), "label_for_end_%d", currentLabelFor);
  
        // Determina o tamanho do array
        char *arrayLength = cat("sizeof(", $6, ") / sizeof(", $6, "[0])", "");
  
        // Inicialização: índice começa em 0
        char *init = cat("int ", $4, " = 0;\n", "", "", "");
  
        // Condição do laço: enquanto índice < tamanho do array
        char *cond = cat("if (", $4, " < ", arrayLength, ") goto ", labelBody);
        char *skipToEnd = cat("goto ", labelEnd, ";\n", "", "", "");
  
        // Corpo do laço: atribui o valor atual do array à variável auxiliar
        char *assignValue = cat($3, " aux = ", $6, "[", $4, "];\n");
        char *body = cat(labelBody, ":\n{\n", assignValue, $9->code, "}\n", "");
  
        // Incremento: avança o índice
        char *increment = cat($4, "++;\n", "", "", "", "");
  
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
        free($4);
        free($6);
        freeRecord($9);
  
        $$ = createRecord(s, "");
        free(s);
        free(key);
        free(typeId);
        scope_free(duplicate);
        scope_pop(stackScope);
    }
    ;
  
  for_incr : ID INCREMENT
    {
      if(function_table_get(functionTable, $1) != NULL) {
          yyerror("id de função");
        }
        char * key = generateKey($1, scope_get(stackScope));
        char * value = hashtable_get(symbol_table, key);
        if(value == NULL){
          yyerror("id inexistente incremento for");
        }
        if(!(strcmp(value, "int") == 0 || strcmp(value, "float") == 0 || strcmp(value, "double") == 0)){
          yyerror("operação restrita a tipos numericos");
        }
        char *s = cat($1, "++", "", "", "", "");
        free($1);
        $$ = createRecord(s, "");
        free(s);
        free(key);
        free(value);
    }
    | ID DECREMENT
    {
      if(function_table_get(functionTable, $1) != NULL) {
          yyerror("id de função");
        }
        char * key = generateKey($1, scope_get(stackScope));
        char * value = hashtable_get(symbol_table, key);
        if(value == NULL){
          yyerror("id inexistente incremento for");
        }
        if(!(strcmp(value, "int") == 0 || strcmp(value, "float") == 0 || strcmp(value, "double") == 0)){
          yyerror("operação restrita a tipos numericos");
        }
        char *s = cat($1, "--", "", "", "", "");
        free($1);
        $$ = createRecord(s, "");
        free(s);
        free(key);
        free(value);
    }
    | INCREMENT ID
    {
      if(function_table_get(functionTable, $2) != NULL) {
          yyerror("id de função");
        }
        char * key = generateKey($2, scope_get(stackScope));
        char * value = hashtable_get(symbol_table, key);
        if(value == NULL){
          yyerror("id inexistente incremento for");
        }
        if(!(strcmp(value, "int") == 0 || strcmp(value, "float") == 0 || strcmp(value, "double") == 0)){
          yyerror("operação restrita a tipos numericos");
        }
        char *s = cat("++", $2, "", "", "", "");
        free($2);
        $$ = createRecord(s, "");
        free(s);
        free(key);
        free(value);
    }
    | DECREMENT ID
    {
      if(function_table_get(functionTable, $2) != NULL) {
          yyerror("id de função");
        }
        char * key = generateKey($2, scope_get(stackScope));
        char * value = hashtable_get(symbol_table, key);
        if(value == NULL){
          yyerror("id inexistente incremento for");
        }
        if(!(strcmp(value, "int") == 0 || strcmp(value, "float") == 0 || strcmp(value, "double") == 0)){
          yyerror("operação restrita a tipos numericos");
        }
        char *s = cat("--", $2, "", "", "", "");
        free($2);
        $$ = createRecord(s, "");
        free(s);
        free(key);
        free(value);
    }
    | exp
    {
        $$ = $1;
    }
    ;
  
  exp : term        {$$ = $1;}
    | call        {$$ = $1;}
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
    | '(' exps ')' {char * s = cat("(", $2->code, ")", "", "", "");
                   freeRecord($2);
                   $$ = createRecord(s, "");
                   free(s);}
    | ID '[' exps ']'
                 {char *s = cat($1, "[", $3->code, "]", "", "");
                  free($1);
                  freeRecord($3);
                  $$ = createRecord(s, "");
                  free(s);}
    | ID '[' exps ']' '[' exps ']'
                 {char *sAux = cat($1, "[", $3->code, "]", "[", $6->code);
                  char *s =    cat(sAux, "]", "", "", "", "");
                  free($1);
                  freeRecord($3);
                  freeRecord($6);
                  $$ = createRecord(s, "");
                  free(s);}
    | '{' exps '}' {char * s = cat("{", $2->code, "}", "", "", "");
                   freeRecord($2);
                   $$ = createRecord(s, "");
                   free(s);}
    | ID '[' exps ']' ASSIGN exp  {char *s = cat($1, "[", $3->code, "] = ", $6->code, "");
                      free($1);
                      freeRecord($3);
                      freeRecord($6);
                      $$ = createRecord(s, "");
                      free(s);
    }
    | ID '[' exps ']' '[' exps ']' ASSIGN exp  {char *sAux = cat($1, "[", $3->code, "]", "[", $6->code);
                                                char *s =    cat(sAux, "] = ", $9->code, "", "", "");
                                                free($1);
                                                freeRecord($3);
                                                freeRecord($6);
                                                freeRecord($9);
                                                $$ = createRecord(s, "");
                                                free(s);
    }
    | ID '[' exps ']' '[' exps ']' INCREMENT_ASSIGN exp  {char *sAux = cat($1, "[", $3->code, "]", "[", $6->code);
                                                            char *s =    cat(sAux, "] = ", $9->code, "", "", "");
                                                            free($1);
                                                            freeRecord($3);
                                                            freeRecord($6);
                                                            freeRecord($9);
                                                            $$ = createRecord(s, "");
                                                            free(s);
    }
    | ID '[' exps ']' '[' exps ']' DECREMENT_ASSIGN exp  {char *sAux = cat($1, "[", $3->code, "]", "[", $6->code);
                                                            char *s =    cat(sAux, "] = ", $9->code, "", "", "");
                                                            free($1);
                                                            freeRecord($3);
                                                            freeRecord($6);
                                                            freeRecord($9);
                                                            $$ = createRecord(s, "");
                                                            free(s);
    }
    ;
  
  factor : ID          {$$ = createRecord($1, "");
                      free($1);}
       |INT          {$$ = createRecord($1, "int");
                      free($1);}
       | FLOAT       {$$ = createRecord($1, "float");
                      free($1);}
       | STRING       {$$ = createRecord($1, "string");
                      free($1);}
       | DOUBLE      {$$ = createRecord($1, "double");
                      free($1);}
       | BOOL_LIT    {$$ = createRecord($1, "");
                      free($1);}
       | STRING_LIT  {$$ = createRecord($1, "");
                      free($1);}
       | VOID         {$$ = createRecord($1, "");
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
    
  symbol_table = hashtable_create();
    stackScope = scope_create();
    functionTable = function_table_create();
    typeTable = type_table_create();
    scope_push(stackScope, "root");
    type_table_set(typeTable, "int", "integer" );
    type_table_set(typeTable, "float", "float" );
    type_table_set(typeTable, "double",  "double");
    type_table_set(typeTable, "bool", "boolean" );

    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2], "w");
  
    codigo = yyparse();
  
    fclose(yyin);
    fclose(yyout);

    hashtable_free(symbol_table);
    function_table_free(functionTable);
    type_table_free(typeTable);
    scope_free(stackScope);
  
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

char * generateKey(char * key, char * scope){
     int tam = strlen(key) + strlen(scope) + 1;
     char * output = (char *) malloc(sizeof(char) * tam);
     if (!output){
          printf("Allocation problem. Closing application...\n");
          exit(0);
     }
     sprintf(output, "%s#%s", key, scope);
     return output;
}

char * verificaEscopos(stack_scope * stack , char * id) {
    char * current = scope_get(stack);
    char * key;
    char * retorno;
    while(stack->top != NULL){
        key = generateKey(id, current);
        retorno = hashtable_get(symbol_table, key);
        if(retorno != NULL){
            free(key);
            free(current);
            return retorno;
        }
        free(key);
        free(current);

        scope_pop(stack);
        current = scope_get(stack);
    }
    free(current);
    return NULL;
}
