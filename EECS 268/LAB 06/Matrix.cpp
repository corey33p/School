#include "Matrix.h"
#include <string>

Matrix::Matrix(std::istream& inp, int n){
    size=n;
    Matrix::m = new double*[n];
    for (int i=0; i<n;i++){
        Matrix::m[i] = new double[n];
    }
    for (int row = 0; row < Matrix::size; row++){
        for (int col = 0; row < Matrix::size; col++) {
            inp>>Matrix::m[row][col];
        }
    }
}

Matrix::Matrix(const Matrix& M, int n, int r, int c){
    Matrix::size = n;
    Matrix::m = new double*[n];
    for (int i=0; i<n;i++){
        Matrix::m[i] = new double[n];
    }
    int rowsPlaced;
    int colsPlaced;
    for (int row = 0; row < Matrix::size; row++){
        colsPlaced = 0;
        for (int col = 0; row < Matrix::size; col++) {
            if ((row != r) && (col != c)){
                Matrix::m[rowsPlaced][colsPlaced]=M[row][col];
                colsPlaced++;
            }
        }
        rowsPlaced++;
    }
}

double Matrix::det() const{
    double d;
    if (Matrix::size == 2) {
        d = m[0][0]*m[1][1]-m[0][1]*m[1][0];
    } else {
        d = 0;
        for (int i; i < Matrix::size; i++) {
            Matrix submatrix = Matrix(Matrix::m, Matrix::size, 0, i);
            d = d + m[0][i]*submatrix.det();
        }
    }
    return d
}

void Matrix::print() {
    for (int row = 0; row < Matrix::size; row++){
        for (int col = 0; row < Matrix::size; col++) {
            string entry = m[row][col];
            for (int i = 0; i< (4- entry.length());i++){
                entry = " " + entry;
            }
            cout<<entry<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
