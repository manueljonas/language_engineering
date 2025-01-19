#ifndef MATRIX_OPERATIONS_H
#define MATRIX_OPERATIONS_H

typedef struct {
    int rows;
    int cols;
    double** data;
} Matrix;

Matrix* create_matrix(int rows, int cols);
void free_matrix(Matrix* matrix);
void print_matrix(Matrix* matrix);
Matrix* add_matrices(Matrix* A, Matrix* B);
Matrix* multiply_matrices(Matrix* A, Matrix* B);
Matrix* transpose_matrix(Matrix* matrix);

#endif