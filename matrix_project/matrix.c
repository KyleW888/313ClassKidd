
#include "matrix_c.h"
#include <stdio.h>
#include <stdlib.h>

Matrix create_matrix(int rows, int cols) { //normal function not like C++ where this would be a constructor 
    Matrix m; //manually create Matrix m
    m.rows = rows; //setting member variables 
    m.columns = cols;

    m.data = (double**)malloc(rows * sizeof(double*)); // same as data = new double*[rows];
                                                       // malloc returns void* normally, the extra* causes it to return a double**
                                                       // pointer to a pointer to double
                                                       //allocates a block of memory large enough to hold rows number of double* pointers.

    for (int i = 0; i < rows; i++) {
        m.data[i] = (double*)calloc(cols, sizeof(double)); //calloc() for zero-initialization
    }

    return m;
}

void free_matrix(Matrix* m) { //passing in pointer to the Matrix
    for (int i = 0; i < m->rows; i++) {
        free(m->data[i]);  // deallocate each row
    }
    free(m->data);         // manually deallocate the array of row pointers
}

void display(Matrix* m) {
    for (int i = 0; i < m->rows; ++i) {
        for (int j = 0; j < m->columns; ++j) {
            printf("%f ", m->data[i][j]);
        }
        printf("\n");
    }
}

void add(Matrix* result, Matrix* A, Matrix* B) {
    if (A->rows != B->rows || A->columns != B->columns) {//must be same size 
        printf("Cannot add matrices\n");
        return;
    }


    for (int i = 0; i < A->rows; ++i) { //same logic as c+++
        for (int j = 0; j < A->columns; ++j) {
            result->data[i][j] = A->data[i][j] + B->data[i][j]; //stores sum 
    }
}
}


void scalarMultiply(Matrix* result, Matrix* A, double scalar) {
    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
            result->data[i][j] = A->data[i][j] * scalar;  //same logic as c++, product is saved in result 
        }
    }
}

void multiply(Matrix* result, Matrix* A, Matrix* B) {
    //(A's columns must match B's rows)
    if (A->columns != B->rows) {
        printf("Matrices cannot be multiplied\n");
        return;
    }

    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < B->columns; ++j) {
            result->data[i][j] = 0; //initialize to 0 for safety
            for (int k = 0; k < A->columns; ++k) {
                result->data[i][j] += A->data[i][k] * B->data[k][j];  
            }
        }
    }
}

void transpose(Matrix* result, Matrix* A) {
    for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
            result->data[j][i] = A->data[i][j];  //swap values - same logic as C++
        }
    }
}
