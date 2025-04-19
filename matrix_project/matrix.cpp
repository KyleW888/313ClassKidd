#include "matrix.h"
#include <iostream>
#include <stdexcept>  // Include for std::invalid_argument
using namespace std;

Matrix::Matrix(int r, int c) {
    rows = r;
    columns = c;
    data = new double*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new double[columns]();
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

// Used for testing and validation
void Matrix::display() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

// Matrix addition
Matrix Matrix::add(const Matrix& rhs) const {
    if (rows != rhs.rows || columns != rhs.columns) {
        throw std::invalid_argument("Matrices cannot be added");
    }

    Matrix sum(rows, columns);  
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            sum.data[i][j] = data[i][j] + rhs.data[i][j]; 
        }
    }
    return sum;  
}

// Scalar multiplication
Matrix Matrix::scalarMultiply(double scalar) const {
    Matrix product(rows, columns);  
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            product.data[i][j] = data[i][j] * scalar;  
        }
    }

    return product;  
}

// Matrix multiplication
Matrix Matrix::multiply(const Matrix& rhs) const {
    if (columns != rhs.rows) {
        throw std::invalid_argument("Matrices cannot be multiplied");
    }
    Matrix product(rows, rhs.columns);  
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rhs.columns; ++j) {
            product.data[i][j] = 0;
            for (int k = 0; k < columns; ++k) {
                product.data[i][j] += data[i][k] * rhs.data[k][j];  
            }
        }
    }

    return product;  
}

// Matrix transposition
Matrix Matrix::transpose() const {
    Matrix transposed(columns, rows);  
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            transposed.data[j][i] = data[i][j];  
        }
    }
    return transposed;
}
