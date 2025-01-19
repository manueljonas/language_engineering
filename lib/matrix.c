#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// typedef struct {
//     int rows;
//     int cols;
//     double** data;
// } Matrix;

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
            printf("%.2f ", matrix->data[i][j]);
        }
        printf("\n");
    }
}

Matrix* add_matrices(Matrix* A, Matrix* B) {
    if (A->rows != B->rows || A->cols != B->cols) {
        fprintf(stderr, "Error: Matrices must have the same dimensions to add.\n");
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
        fprintf(stderr, "Error: Number of columns in A must equal number of rows in B.\n");
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

// int main() {
//     Matrix* A = create_matrix(2, 3);
//     Matrix* B = create_matrix(2, 3);

//     A->data[0][0] = 1; A->data[0][1] = 2; A->data[0][2] = 3;
//     A->data[1][0] = 4; A->data[1][1] = 5; A->data[1][2] = 6;

//     B->data[0][0] = 7; B->data[0][1] = 8; B->data[0][2] = 9;
//     B->data[1][0] = 10; B->data[1][1] = 11; B->data[1][2] = 12;

//     printf("Matrix A:\n");
//     print_matrix(A);

//     printf("Matrix B:\n");
//     print_matrix(B);

//     Matrix* C = add_matrices(A, B);
//     if (C) {
//         printf("Matrix A + B:\n");
//         print_matrix(C);
//         free_matrix(C);
//     }

//     Matrix* D = transpose_matrix(A);
//     printf("Transpose of A:\n");
//     print_matrix(D);

//     free_matrix(A);
//     free_matrix(B);
//     free_matrix(D);

//     return 0;
// }
