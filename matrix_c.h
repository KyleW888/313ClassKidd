// matrix_c.h
#ifndef MATRIX_C_H
#define MATRIX_C_H

typedef struct { //basically struct Matrix
    int rows;
    int columns;
    double** data;
} Matrix;

Matrix create_matrix(int rows, int cols);  // C constructor
void free_matrix(Matrix* m);               // C destructor
void display(Matrix* m);
void add(Matrix* result, Matrix* A, Matrix* B);
void scalarMultiply(Matrix* result, Matrix* A, double scalar);
void multiply(Matrix* result, Matrix* A, Matrix* B);
void transpose(Matrix* result, Matrix* A);


#endif
