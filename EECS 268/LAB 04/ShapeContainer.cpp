/*
@author - Cory Anderson
@file - ShapeContainer.cpp
@date - 9/23/2019
@brief - This data structure will hold and manage individual shape objects.
*/

#include "ShapeContainer.h"
#include "Shape.h"
#include <stdexcept>
#include <string>
using namespace std;


ShapeContainer::ShapeContainer(int size){  //initialize pointers in m_arrayOfShapes to nullptr
    ShapeContainer::m_size = size;
    ShapeContainer::m_arrayOfShapes = new Shape*[size];
    for (int i = 0; i < ShapeContainer::m_size; i++) {
       ShapeContainer::m_arrayOfShapes[i]=nullptr;
    }
}

ShapeContainer::~ShapeContainer(){
    for (int i = 0; i < ShapeContainer::m_size; i++) {
       delete ShapeContainer::m_arrayOfShapes[i];
    }
    delete [] ShapeContainer::m_arrayOfShapes;
}

double ShapeContainer::area(int index) const { //throws a std::exception if index is invalid, meaning out of range OR index has nullptr
    if ((index < 0) || (index >= ShapeContainer::m_size) || (ShapeContainer::m_arrayOfShapes[index] == nullptr)){
        // throw std::range_error("Does not exist!");
        throw std::exception();
    }
    return ShapeContainer::m_arrayOfShapes[index]->area();
}

std::string ShapeContainer::shapeName(int index) const{ //throws a std::range_error if index is invalid, meaning out of range OR index has nullptr
    if ((index < 0) || (index >= ShapeContainer::m_size) || (ShapeContainer::m_arrayOfShapes[index] == nullptr)){
        throw std::range_error("Does not exist!");
    }
    // cout<<"check"<<endl;
    return ShapeContainer::m_arrayOfShapes[index]->shapeName();
    // cout<<"check2"<<endl;
}

void ShapeContainer::add(Shape* shapePtr, int index){ //throws a std::exception if index is invalid OR if shapePtr is nullptr
    if ((index < 0) || (index >= ShapeContainer::m_size)){
        // throw std::range_error("Array index does not exist; could not add shape!");
        throw std::exception();
    }
    ShapeContainer::m_arrayOfShapes[index] = shapePtr;
}

void ShapeContainer::remove(int index){ //throws a std::exception if the index is invalid OR there is no object to delete
    if ((index < 0) || (index >= ShapeContainer::m_size)){
        // throw std::range_error("Array index does not exist; could not delete shape!");
        throw std::exception();
    } else if  (ShapeContainer::m_arrayOfShapes[index] == nullptr){
        // throw std::range_error("No shape exists at this index; could not delete shape!");
        throw std::exception();
    }
    delete ShapeContainer::m_arrayOfShapes[index];
    ShapeContainer::m_arrayOfShapes[index]=nullptr;
}
