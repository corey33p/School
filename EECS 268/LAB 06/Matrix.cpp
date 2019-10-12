#include "Matrix.h"
#include <math.h>    // pow
#include <string>
#include <iostream>
#include <algorithm> // max
using namespace std;

Matrix::Matrix(std::istream& inp, int n){
    size=n;
    Matrix::m = new double*[n];
    for (int i=0; i<n;i++){
        Matrix::m[i] = new double[n];
    }
    std::string next_input;
    for (int row = 0; row < Matrix::size; row++){
        for (int col = 0; col < Matrix::size; col++) {
            inp>>next_input;
            Matrix::m[row][col] = std::stod(next_input);
        }
    }
}

Matrix::Matrix(const Matrix& M, int n, int r, int c){
    Matrix::size = n-1;
    Matrix::m = new double*[n];
    for (int i=0; i<Matrix::size;i++){
        Matrix::m[i] = new double[Matrix::size];
    }
    int rowsPlaced = 0;
    int colsPlaced;
    for (int row = 0; row < n; row++){
        colsPlaced = 0;
        if (row != r) {
            for (int col = 0; col < n; col++) {
                if (col != c){
                    Matrix::m[rowsPlaced][colsPlaced]=M.m[row][col];
                    colsPlaced++;
                }
            }
            rowsPlaced++;
        }
    }
}

double Matrix::det() const{
    double d;
    if (Matrix::size == 2) {
        d = m[0][0]*m[1][1]-m[0][1]*m[1][0];
    } else {
        d = 0;
        for (int i=0; i < Matrix::size; i++) {
            Matrix submatrix = Matrix(*this, (int) Matrix::size, 0, (int) i);
            d = d + pow(-1,i)*(m[0][i]*submatrix.det());
        }
    }
    return d;
}

void Matrix::print() {
    cout<<endl;
    int max_size = 0;
    std::string val;
    
    // first for loop is to determine the necessary padding size for printing
    for (int row = 0; row < Matrix::size; row++){
        int size = 0;
        for (int col = 0; col < Matrix::size; col++) {
            val = std::to_string(m[row][col]);
            val.erase ( val.find_last_not_of('0') + 1, std::string::npos );
            val.erase ( val.find_last_not_of('.') + 1, std::string::npos );
            size = val.length();
            max_size = max(size,max_size);
        }
    }
    
    // the following loops will print the matrix
    std::string entry;
    for (int row = 0; row < Matrix::size; row++){
        for (int col = 0; col < Matrix::size; col++) {
            entry = "";
            val = "";
            val = std::to_string(m[row][col]);
            val.erase ( val.find_last_not_of('0') + 1, std::string::npos );
            val.erase ( val.find_last_not_of('.') + 1, std::string::npos );
            for (int i = 0; i< (int)(max_size-val.length());i++){
                entry = entry + " ";
            }
            entry = entry + val;
            cout<<entry<<" ";
        }
        cout<<endl;
    }
}
