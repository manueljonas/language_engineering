#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

typedef struct {
 int numerador;
 int denominador;
} rational_t;

int main(){
int num;
int intervalo1 = 0;
int intervalo2 = 0;
int intervalo3 = 0;
int intervalo4 = 0;
printf("Digite números inteiros (digite um número negativo para terminar a RODADA): \n");
label_while_start_1: if ((true)) goto label_while_body_1;
goto label_while_end_1;
label_while_body_1:
{
scanf("%d", &num);
if (num >= 0) {
 goto goto_if_c_1; 
} 
 goto goto_else_c_1; 
goto_if_c_1: 
if (num >= 0 && num <= 25) {
 goto goto_if_1; 
} 
 goto goto_end_if_1; 
goto_if_1: 
intervalo1++;
goto_end_if_1: 

if (num >= 26 && num <= 50) {
 goto goto_if_2; 
} 
 goto goto_end_if_2; 
goto_if_2: 
intervalo2++;
goto_end_if_2: 

if (num >= 51 && num <= 75) {
 goto goto_if_3; 
} 
 goto goto_end_if_3; 
goto_if_3: 
intervalo3++;
goto_end_if_3: 

if (num >= 76 && num <= 100) {
 goto goto_if_4; 
} 
 goto goto_end_if_4; 
goto_if_4: 
intervalo4++;
goto_end_if_4: 

goto goto_end_if_else_1; 
goto_else_c_1: 
printf("Quantidade de números em cada intervalo:\n");
printf("[0, 25]: %d\n", intervalo1);
printf("[26, 50]: %d\n", intervalo2);
printf("[51, 75]: %d\n", intervalo3);
printf("[76, 100]: %d\n", intervalo4);
return 0;
goto_end_if_else_1: 

}
goto label_while_start_1;
label_while_end_1: 

}