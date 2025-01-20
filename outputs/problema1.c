#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>


int main(){
float x, y;
x = 4.5;
y = 2.3;
int c = 7;
float resultado = pow(x, 2) - y + c;
printf("O resultado da expressão x² - y + c é: %f \n", resultado);
}