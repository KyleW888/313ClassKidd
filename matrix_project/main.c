#include "matrix_c.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Matrix A 
    Matrix A = create_matrix(2, 2);
    A.data[0][0] = 6;
    A.data[0][1] = 4;
    A.data[1][0] = 8;
    A.data[1][1] = 3;

    // Matrix B 
    Matrix B = create_matrix(2, 3);
    B.data[0][0] = 1;
    B.data[0][1] = 2;
    B.data[0][2] = 3;
    B.data[1][0] = 4;
    B.data[1][1] = 5;
    B.data[1][2] = 6;

    // M<atrix C (
    Matrix C = create_matrix(2, 3);
    C.data[0][0] = 2;
    C.data[0][1] = 4;
    C.data[0][2] = 6;
    C.data[1][0] = 1;
    C.data[1][1] = 3;
    C.data[1][2] = 5;

    Matrix threeB = create_matrix(2, 3); //new matrix to hold new values
    scalarMultiply(&threeB, &B, 3); // pass in address of threeB(result), B(hard coded matrix), 3(scalar value)
    printf("3 * Matrix B:\n");
    display(&threeB);

    Matrix CT = create_matrix(3, 2);  //new matrix to hold new values
    transpose(&CT, &C); // CT(result), C(hard coded matrix)
    printf("Matrix C Transposed (C^T):\n");
    display(&CT);

    Matrix product = create_matrix(2, 2);  // multiplication of 2x3 and 3x2 gives a 2x2 matrix
    multiply(&product, &threeB, &CT); //product(result), threeB and CT are the matrices to be multiplied
    printf("(3 * Matrix B) * Matrix C^T:\n");
    display(&product);

    Matrix D = create_matrix(2, 2); //final matrix
    add(&D, &A, &product); //add Matrix a and Matrix product
    printf("Matrix D = A + (3 * B) * C^T:\n");
    display(&D);

    // manually deallocate everything 
    free_matrix(&A);
    free_matrix(&B);
    free_matrix(&C);
    free_matrix(&threeB);
    free_matrix(&CT);
    free_matrix(&product);
    free_matrix(&D);

    return 0;
}
