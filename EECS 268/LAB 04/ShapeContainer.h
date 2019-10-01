/*
@author - Cory Anderson
@file - ShapeContainer.h
@date - 9/23/2019
@brief - This data structure will hold and manage individual shape objects.
*/

#ifndef SHAPECONTAINER_H
#define SHAPECONTAINER_H

#include "Shape.h"
#include <stdexcept>

class ShapeContainer
{
    public:
        /*
        @preconditions - The size of the shape container will be known.
        @postconditions - The array of pointers which will contain the shape
        objects will be declared and initialized.
        @return - constructors don't return anything
        */
        ShapeContainer(int size);

        /*
        @preconditions - The program will have run and finished.
        @postconditions - The shape objects pointed to by m_arrayOfShapes will
        be deleted one by one, and then m_arrayOfShapes will be deleted also.
        @return - destructors don't return anything
        */
        ~ShapeContainer();

        /*
        @preconditions - The index for the desired shape will be passed in.
        @postconditions - The area of the shape at the particular index of the
        shape array will be calculated, assuming a shape exists at said index and
        that said index is valid.
        @return - The (double) area of the shape at the particular index of the
        shape array will be returned, assuming a shape exists at said index and
        that said index is valid.
        */
        double area(int index) const;

        /*
        @preconditions - The index for the desired shape will be passed in.
        @postconditions - The type of the shape will be ascertained, if the
        index is valid.
        @return - a std::string containing the type of shape
        */
        std::string shapeName(int index) const;

        /*
        @preconditions - The shape array will have been created. The index for
        the desired new shape will be received.
        @postconditions - The shape will be created if the index is valid.
        An existing shape at the index will be removed if necessary.
        @return - void
        */
        void add(Shape* shapePtr, int index);

        /*
        @preconditions - The index for the shape to be deleted will be received.
        @postconditions - If the index is valid, the shape at the index
        will be deleted, and the pointer to it in m_arrayOfShapes will be made
        a null pointer.
        @return - void
        */
        void remove(int index);
    private:
        Shape** m_arrayOfShapes;
        int m_size;
};

#endif
