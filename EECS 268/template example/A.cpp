#include "A.h"
#include "B.h"

template<class B>
A<B>::A(){}

template<class B>
A<B>::A(B& anItem){
    item = anItem;
}

template<class B>
B A<B>::getItem() const{
    return item;
}

template class A<B>;