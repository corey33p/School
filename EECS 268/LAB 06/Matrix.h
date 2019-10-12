#include <iostream>

#ifndef MATRIX_H
#define MATRIX_H


class Matrix {
    private:
        int size;
        double** m;
    public:
        Matrix(std::istream& inp, int n); // Create storage for n x n matrix and read its n*n values from "inp"
        Matrix(const Matrix& M, int n, int r, int c); // Create Sr,c(M); if M is nxn, the new matrix will be (n-1)x(n-1)
        double det() const; // implement the recursive algorithm outlined above
        void print();
};

#endif
