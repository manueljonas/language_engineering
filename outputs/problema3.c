#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>

typedef struct {
 int numerador;
 int denominador;
} rational_t;

int main(){
int m1, n1, m2, n2;
int matriz1[10000], matriz2[10000], soma[10000], produto[10000];
printf("Digite as dimensões da primeira matriz (linhas e colunas): ");
scanf("%d %d", &m1, &n1);
printf("Digite os elementos da primeira matriz:\n");

{
int i = 0;
label_for_start_2: if ((i < m1)) goto label_for_body_2;
goto label_for_end_2;
label_for_body_2:
{

{
int j = 0;
label_for_start_1: if ((j < n1)) goto label_for_body_1;
goto label_for_end_1;
label_for_body_1:
{
scanf("%d", &matriz1[i * n1 + j]);
}
j++;
goto label_for_start_1;
label_for_end_1: 
}

}
i++;
goto label_for_start_2;
label_for_end_2: 
}

printf("Digite as dimensões da segunda matriz (linhas e colunas): ");
scanf("%d %d", &m2, &n2);
printf("Digite os elementos da segunda matriz:\n");

{
int i = 0;
label_for_start_4: if ((i < m2)) goto label_for_body_4;
goto label_for_end_4;
label_for_body_4:
{

{
int j = 0;
label_for_start_3: if ((j < n2)) goto label_for_body_3;
goto label_for_end_3;
label_for_body_3:
{
scanf("%d", &matriz2[i * n2 + j]);
}
j++;
goto label_for_start_3;
label_for_end_3: 
}

}
i++;
goto label_for_start_4;
label_for_end_4: 
}

if (m1 == m2 && n1 == n2) {
 goto goto_if_c_1; 
} 
 goto goto_else_c_1; 
goto_if_c_1: 

{
int i = 0;
label_for_start_6: if ((i < m1)) goto label_for_body_6;
goto label_for_end_6;
label_for_body_6:
{

{
int j = 0;
label_for_start_5: if ((j < n1)) goto label_for_body_5;
goto label_for_end_5;
label_for_body_5:
{
soma[i * n1 + j] = matriz1[i * n1 + j] + matriz2[i * n2 + j];
}
j++;
goto label_for_start_5;
label_for_end_5: 
}

}
i++;
goto label_for_start_6;
label_for_end_6: 
}

printf("Soma das matrizes:\n");

{
int i = 0;
label_for_start_8: if ((i < m1)) goto label_for_body_8;
goto label_for_end_8;
label_for_body_8:
{

{
int j = 0;
label_for_start_7: if ((j < n1)) goto label_for_body_7;
goto label_for_end_7;
label_for_body_7:
{
printf("%d ", soma[i * n1 + j]);
}
j++;
goto label_for_start_7;
label_for_end_7: 
}

printf("\n");
}
i++;
goto label_for_start_8;
label_for_end_8: 
}

goto goto_end_if_else_1; 
goto_else_c_1: 
printf("As matrizes não podem ser somadas, pois as dimensões são incompatíveis.\n");
goto_end_if_else_1: 

if (n1 == m2) {
 goto goto_if_c_2; 
} 
 goto goto_else_c_2; 
goto_if_c_2: 

{
int i = 0;
label_for_start_11: if ((i < m1)) goto label_for_body_11;
goto label_for_end_11;
label_for_body_11:
{

{
int j = 0;
label_for_start_10: if ((j < n2)) goto label_for_body_10;
goto label_for_end_10;
label_for_body_10:
{
produto[i * n2 + j] = 0;

{
int k = 0;
label_for_start_9: if ((k < n1)) goto label_for_body_9;
goto label_for_end_9;
label_for_body_9:
{
produto[i * n2 + j] = produto[i * n2 + j] + matriz1[i * n1 + k] * matriz2[k * n2 + j];
}
k++;
goto label_for_start_9;
label_for_end_9: 
}

}
j++;
goto label_for_start_10;
label_for_end_10: 
}

}
i++;
goto label_for_start_11;
label_for_end_11: 
}

printf("Produto das matrizes:\n");

{
int i = 0;
label_for_start_13: if ((i < m1)) goto label_for_body_13;
goto label_for_end_13;
label_for_body_13:
{

{
int j = 0;
label_for_start_12: if ((j < n2)) goto label_for_body_12;
goto label_for_end_12;
label_for_body_12:
{
printf("%d ", produto[i * n2 + j]);
}
j++;
goto label_for_start_12;
label_for_end_12: 
}

printf("\n");
}
i++;
goto label_for_start_13;
label_for_end_13: 
}

goto goto_end_if_else_2; 
goto_else_c_2: 
printf("As matrizes não podem ser multiplicadas, pois o número de colunas da primeira matriz não é igual ao número de linhas da segunda matriz.\n");
goto_end_if_else_2: 

}