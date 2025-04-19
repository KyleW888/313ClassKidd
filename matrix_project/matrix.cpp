#include "matrix.h"
#include <iostream>
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
//used for testing and validation 
void Matrix::display() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

// Matrix addition
Matrix Matrix::add(const Matrix& other) const {
    Matrix sum(rows, columns);  
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            sum.data[i][j] = data[i][j] + other.data[i][j]; 
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

Matrix Matrix::multiply(const Matrix& other) const {
    Matrix product(rows, other.columns);  

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.columns; ++j) {
            product.data[i][j] = 0;
            for (int k = 0; k < columns; ++k) {
                product.data[i][j] += data[i][k] * other.data[k][j];  
            }
        }
    }

    return product;  
}
Matrix Matrix::transpose() const {
    Matrix transposed(columns, rows);  
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            transposed.data[j][i] = data[i][j];  
        }
    }
    return transposed;
}
