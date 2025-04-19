# Matrix Project

## AUTHORING
- Author: Kyle Wu 
- Class: CMSC 313 - Computer Organization & Assembly Language  
- Spring Semester 2025, M/W 8:00 am  

## Purpose of Software 
A simple matrix library implemented in both C++ and C. Program does basic matrix operations such as addition, scalar multiplication, and matrix multiplication.

## FILES

### C++ Implementation:
- matrix.h: Header file which has the Matrix class declaration.
- matrix.cpp: The implementation of the Matrix class.
- main.cpp: Used to test Matrix functionn/operations.

### C Implementation:


### Build Instructions
-g++ matrix.cpp main.cpp -o matrix_test
  

## Test Methodology for C++

### TESTING METHODOLOGY

For the C++ implementation, the matrices were hardcoded in main.cpp.
Here is each step of the operation to evaluate  D = A * B + C. 

1. Matrix A, B, and C were manually created and filled with values
  
2. Matrix Scalar Multiplication 
   - Multiply Matrix B by scalar 3 -> Matrix threeB = B.scalarMultiply(3);
     

3. Transpose Operation
   - Transpose Matrix C to get C^T -> Matrix CT = C.transpose();

4. Matrix Multiplication
  - Multiply (3 * B) by C^T

5. Matrix Addition
   -Add Matrix A to the result of the multiplication -> Matrix D = A.add(product);

Each step, display() was called to determine correctness of answer.




