#include <iostream>

#ifndef CITY_H
#define CITY_H

class City {
    private:
        int** city;
        int numberOfSewers;
        int** sewerLocations;
        int size[2];
        int start[2];
        bool sewerFound;
    public:
        City(std::istream& inp, int rows, int cols, int sRow, int sCol);
        virtual ~City();
        void begin();
        void findSewers();
        // int** step(int** c, int curRow, int curCol);
        void step(int** c, int curRow, int curCol);
        void printCity();
};

#endif
