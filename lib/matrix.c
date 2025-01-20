#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

Matrix* create_matrix(int rows, int cols) {
    Matrix* matrix = (Matrix*)malloc(sizeof(Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (double**)malloc(rows * sizeof(double*));

    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (double*)calloc(cols, sizeof(double));
    }

    return matrix;
}

void free_matrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

void print_matrix(Matrix* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            printf("%d", (int)matrix->data[i][j]);
            if (j < matrix->cols - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

Matrix* add_matrices(Matrix* A, Matrix* B) {
    if (A->rows != B->rows || A->cols != B->cols) {
        fprintf(stderr, "Error: Matrizes devem ter o mesmo tamanho.\n");
        return NULL;
    }

    Matrix* result = create_matrix(A->rows, A->cols);

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->cols; j++) {
            result->data[i][j] = A->data[i][j] + B->data[i][j];
        }
    }

    return result;
}

Matrix* multiply_matrices(Matrix* A, Matrix* B) {
    if (A->cols != B->rows) {
        fprintf(stderr, "Error: Colunas de A deve ser o mesmo número de Linhas de B.\n");
        return NULL;
    }

    Matrix* result = create_matrix(A->rows, B->cols);

    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->cols; j++) {
            for (int k = 0; k < A->cols; k++) {
                result->data[i][j] += A->data[i][k] * B->data[k][j];
            }
        }
    }

    return result;
}

Matrix* transpose_matrix(Matrix* matrix) {
    Matrix* result = create_matrix(matrix->cols, matrix->rows);

    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            result->data[j][i] = matrix->data[i][j];
        }
    }

    return result;
}

int* get_data(const char *str, int *size) {
    int *result = malloc(strlen(str) * sizeof(int)); 
    *size = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            result[*size] = str[i] - '0';
            (*size)++;
        }
    }

    return result;
}

char* clean_params(const char *str) {
    int i = 0, j = 0;
    int len = strlen(str);
    
    char *nova_str = malloc(len + 1);

    if (nova_str == NULL) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }

    while (str[i] != '\0') {
        if (str[i] != '{' && str[i] != '}' && str[i] != ' ') {
            nova_str[j] = str[i];
            j++;
        }
        i++;
    }

    nova_str[j] = '\0';

    return nova_str;
}

Matrix* parse_matrix_string(const char* input, int rows, int cols) {

    input = clean_params(input);

    Matrix* matrix = create_matrix(rows, cols);
   
    int k = 0;
    int size = 0;


    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix->data[i][j] = get_data(input, &size)[k];
            k++; 
        }
    }
    
    print_matrix(matrix);
    return matrix;
}