#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

typedef struct {
 int numerador;
 int denominador;
} rational_t;
int mdc(int n, int m)
{
int resto;
if (m - (m / n) * n == 0) {
 goto goto_if_1; 
} 
 goto goto_end_if_1; 
goto_if_1: 
return n;
goto_end_if_1: 

if (n - (n / m) * m == 0) {
 goto goto_if_2; 
} 
 goto goto_end_if_2; 
goto_if_2: 
return m;
goto_end_if_2: 

if (m > n) {
 goto goto_if_3; 
} 
 goto goto_end_if_3; 
goto_if_3: 
resto = m - (m / n) * n;
return mdc(n, resto);
goto_end_if_3: 

if (n > m) {
 goto goto_if_4; 
} 
 goto goto_end_if_4; 
goto_if_4: 
resto = n - (n / m) * m;
return mdc(m, resto);
goto_end_if_4: 

}

int main(){
int n, m, resultado;
printf("Digite dois números naturais estritamente positivos:\n");
printf("n: ");
scanf("%d", &n);
printf("m: ");
scanf("%d", &m);
if (n <= 0 || m <= 0) {
 goto goto_if_c_1; 
} 
 goto goto_else_c_1; 
goto_if_c_1: 
printf("Erro: Os números devem ser estritamente positivos.\n");
goto goto_end_if_else_1; 
goto_else_c_1: 
resultado = mdc(n, m);
printf("O maior divisor comum de n (%d) e m (%d) é: %d.\n", n, m, resultado);
goto_end_if_else_1: 

}