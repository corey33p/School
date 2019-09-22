#ifndef SHAPECONTAINER_H
#define SHAPECONTAINER_H

#include "Shape.h"
#include <stdexcept>

class ShapeContainer
{
    public:
        ShapeContainer(int size); //initialize pointers in m_arrayOfShapes to nullptr
        ~ShapeContainer();
        double area(int index) const; //throws a std::runtime_error if index is invalid, meaning out of range OR index has nullptr 
        std::string shapeName(int index) const; //throws a std::runtime_error if index is invalid, meaning out of range OR index has nullptr
        void add(Shape* shapePtr, int index); //throws a std::runtime_error if index is invalid OR if shapePtr is nullptr
        void remove(int index); //throws a std::runtime_error if the index is invalid OR there is no object to delete
    private:
        Shape** m_arrayOfShapes;
        int m_size;
};

#endif