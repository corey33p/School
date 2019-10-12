#include <iostream>

#ifndef FIELD_H
#define FIELD_H


class Field {
    private:
        int** field;
        int** steps;
        int size[2];
    public:
        Field(std::istream& inp, int rows, int cols); // Create storage for n x n matrix and read its n*n values from "inp"
        void start();
        void step(int** f, int** s, bool original);
        void printSteps();
        void printField();
};

#endif
