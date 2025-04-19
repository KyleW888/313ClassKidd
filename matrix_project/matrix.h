#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matrix {
public:
int rows;
    int columns;        
    double** data;
    // Constructor
    Matrix(int r, int c);

    // Destructor 
    ~Matrix();

    void display() const;

    //const for all of these to prevent any changes to the matrices 
    Matrix add(const Matrix& other) const;
    Matrix scalarMultiply(double scalar) const;
    Matrix multiply(const Matrix& other) const;
    Matrix transpose() const;
};

#endif 
