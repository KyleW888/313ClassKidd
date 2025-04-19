#include "matrix.h"
#include <iostream>
#include <stdexcept>  // Include for exception handling
using namespace std;

int main() {
    Matrix A(2, 2);
    A.data[0][0] = 6;
    A.data[0][1] = 4;
    A.data[1][0] = 8;
    A.data[1][1] = 3;
    
    Matrix B(2, 3);
    B.data[0][0] = 1;
    B.data[0][1] = 2;
    B.data[0][2] = 3;
    B.data[1][0] = 4;
    B.data[1][1] = 5;
    B.data[1][2] = 6;

    Matrix C(2, 3);
    C.data[0][0] = 2;
    C.data[0][1] = 4;
    C.data[0][2] = 6;
    C.data[1][0] = 1;
    C.data[1][1] = 3;
    C.data[1][2] = 5;

    try {
    
        Matrix threeB = B.scalarMultiply(3);
        cout << "3 * Matrix B:" << endl;
        threeB.display();

        Matrix CT = C.transpose();
        cout << "Matrix C Transposed (C^T):" << endl;
        CT.display();

     
        Matrix product = threeB.multiply(CT);
        cout << "(3 * Matrix B) * Matrix C^T:" << endl;
        product.display();

      
        Matrix D = A.add(product);
        cout << "Matrix D = A + (3 * B) * C^T:" << endl;
        D.display();
    }
    catch (const std::invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
