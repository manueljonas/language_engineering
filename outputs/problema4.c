#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

typedef struct {
 int numerador;
 int denominador;
} rational_t;
int mdc(int a, int b)
{
a = abs(a);
b = abs(b);
label_while_start_1: if ((b != 0)) goto label_while_body_1;
goto label_while_end_1;
label_while_body_1:
{
if (a > b) {
 goto goto_if_c_1; 
} 
 goto goto_else_c_1; 
goto_if_c_1: 
a = a - b;
goto goto_end_if_else_1; 
goto_else_c_1: 
b = b - a;
goto_end_if_else_1: 

}
goto label_while_start_1;
label_while_end_1: 

return a;
}
rational_t simplificar(rational_t r)
{
int divisor = mdc(r.numerador, r.denominador);
r.numerador = r.numerador / divisor;
r.denominador = r.denominador / divisor;
if (r.denominador < 0) {
 goto goto_if_1; 
} 
 goto goto_end_if_1; 
goto_if_1: 
r.numerador = -r.numerador;
r.denominador = -r.denominador;
goto_end_if_1: 

return r;
}
rational_t criarRacional(int a, int b)
{
rational_t resultado;
if (b == 0) {
 goto goto_if_c_2; 
} 
 goto goto_else_c_2; 
goto_if_c_2: 
printf("Erro: Denominador não pode ser zero.\n");
resultado.numerador = 0;
resultado.denominador = 1;
goto goto_end_if_else_2; 
goto_else_c_2: 
resultado.numerador = a;
resultado.denominador = b;
goto_end_if_else_2: 

return simplificar(resultado);
}
bool saoIguais(rational_t r1, rational_t r2)
{
if (r1.numerador * r2.denominador == r2.numerador * r1.denominador) {
 goto goto_if_c_3; 
} 
 goto goto_else_c_3; 
goto_if_c_3: 
return true;
goto goto_end_if_else_3; 
goto_else_c_3: 
return false;
goto_end_if_else_3: 

}
rational_t somarRacionais(rational_t r1, rational_t r2)
{
rational_t resultado;
resultado.numerador = r1.numerador * r2.denominador + r2.numerador * r1.denominador;
resultado.denominador = r1.denominador * r2.denominador;
return simplificar(resultado);
}
rational_t negarRacional(rational_t r)
{
rational_t resultado;
resultado.numerador = -r.numerador;
resultado.denominador = r.denominador;
return simplificar(resultado);
}
rational_t subtrairRacionais(rational_t r1, rational_t r2)
{
return somarRacionais(r1, negarRacional(r2));
}
rational_t multiplicarRacionais(rational_t r1, rational_t r2)
{
rational_t resultado;
resultado.numerador = r1.numerador * r2.numerador;
resultado.denominador = r1.denominador * r2.denominador;
return simplificar(resultado);
}
rational_t inverterRacional(rational_t r)
{
rational_t resultado;
if (r.numerador == 0) {
 goto goto_if_c_4; 
} 
 goto goto_else_c_4; 
goto_if_c_4: 
printf("Erro: Não é possível inverter um número racional com numerador zero.\n");
resultado.numerador = 0;
resultado.denominador = 1;
goto goto_end_if_else_4; 
goto_else_c_4: 
resultado.numerador = r.denominador;
resultado.denominador = r.numerador;
goto_end_if_else_4: 

return simplificar(resultado);
}
rational_t dividirRacionais(rational_t r1, rational_t r2)
{
return multiplicarRacionais(r1, inverterRacional(r2));
}

int main(){
rational_t r1, r2, resultado;
r1 = criarRacional(3, 4);
r2 = criarRacional(5, 6);
if (saoIguais(r1, r2)) {
 goto goto_if_c_5; 
} 
 goto goto_else_c_5; 
goto_if_c_5: 
printf("Os números racionais são iguais.\n");
goto goto_end_if_else_5; 
goto_else_c_5: 
printf("Os números racionais são diferentes.\n");
goto_end_if_else_5: 

resultado = somarRacionais(r1, r2);
printf("Soma: %d/%d\n", resultado.numerador, resultado.denominador);
resultado = negarRacional(r1);
printf("Negação de r1: %d/%d\n", resultado.numerador, resultado.denominador);
resultado = subtrairRacionais(r1, r2);
printf("Subtração: %d/%d\n", resultado.numerador, resultado.denominador);
resultado = multiplicarRacionais(r1, r2);
printf("Multiplicação: %d/%d\n", resultado.numerador, resultado.denominador);
resultado = inverterRacional(r1);
printf("Inverso de r1: %d/%d\n", resultado.numerador, resultado.denominador);
resultado = dividirRacionais(r1, r2);
printf("Divisão: %d/%d\n", resultado.numerador, resultado.denominador);
}