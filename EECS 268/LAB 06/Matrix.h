/*
@author - Corey Anderson
@file - Matrix.h
@date - 10/12/2019
@brief - A matrix class with a recursive function for evaluating the
         determinant of the matrix.
*/

#include <iostream>

#ifndef MATRIX_H
#define MATRIX_H


class Matrix {
    private:
        int size;
        double** m;
    public:
        // This constructor will read in a matrix from a file stream.
        Matrix(std::istream& inp, int n);
        
        // This constructor is used for creating submatrices that will be used
        // in the recursively defined determinant method.
        Matrix(const Matrix& M, int n, int r, int c);
        ~Matrix();
        
        // det() will recursively evaluate the determinant of the matrix.
        // The base case is a 2x2 matrix, [[a,b],[c,d]] for which the
        // determinant is ac-bd. Determinants of square matrices m of size
        // n>2 are evaluated by
        // sum (i from 0 to n) of ((-1)^n)*m[0][i]*det(submatrix[0][i])
        // where a submatrix[0][i] is defined my removing row 0 and column i
        // from matrix M.
        double det() const; // implement the recursive algorithm outlined above
        
        // Used to print the matrix to the console. Spacing / padding will be
        // relative to the types and sizes of the elements the matrix contains.
        void print();
};

#endif
