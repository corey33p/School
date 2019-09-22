#include "ShapeContainer.h"
#include "Shape.h"
#include <stdexcept>
#include <string>
using namespace std;


ShapeContainer::ShapeContainer(int size){  //initialize pointers in m_arrayOfShapes to nullptr
    ShapeContainer::m_size = size;
    ShapeContainer::m_arrayOfShapes = new Shape*[size];
    // ShapeContainer::m_arrayOfShapes = {nullptr};
}

ShapeContainer::~ShapeContainer(){
    delete [] ShapeContainer::m_arrayOfShapes;
}

double ShapeContainer::area(int index) const { //throws a std::runtime_error if index is invalid, meaning out of range OR index has nullptr 
    if ((index < 0) || (index >= ShapeContainer::m_size) || (ShapeContainer::m_arrayOfShapes[index] == nullptr)){
        throw std::range_error("Does not exist!");
    }
    return ShapeContainer::m_arrayOfShapes[index]->area();
}

std::string ShapeContainer::shapeName(int index) const{ //throws a std::runtime_error if index is invalid, meaning out of range OR index has nullptr
    if ((index < 0) || (index >= ShapeContainer::m_size) || (ShapeContainer::m_arrayOfShapes[index] == nullptr)){
        throw std::range_error("Does not exist!");
    }
    cout<<"check"<<endl;
    return ShapeContainer::m_arrayOfShapes[index]->shapeName();
    cout<<"check2"<<endl;
}

void ShapeContainer::add(Shape* shapePtr, int index){ //throws a std::runtime_error if index is invalid OR if shapePtr is nullptr
    if ((index < 0) || (index >= ShapeContainer::m_size)){
        throw std::range_error("Does not exist!");
    }
    // if (ShapeContainer::m_arrayOfShapes[index] != nullptr) {
        // ShapeContainer::remove(index);
    // }
    ShapeContainer::m_arrayOfShapes[index] = shapePtr; 
}

void ShapeContainer::remove(int index){ //throws a std::runtime_error if the index is invalid OR there is no object to delete
    if ((index < 0) || (index >= ShapeContainer::m_size) || (ShapeContainer::m_arrayOfShapes[index] == nullptr)){
        throw std::range_error("Does not exist!");
    }
    delete ShapeContainer::m_arrayOfShapes[index];
    ShapeContainer::m_arrayOfShapes[index]=nullptr;
}
