using namespace std;
#include <iostream>
#include "Executive.h"
#include "A.h"
#include "B.h"

template<class B>
Executive<B>::Executive(){
    B b = B(4);
    A<B>* a = new A<B>(b);
    cout<<"a->getItem().c: "<<a->getItem().c<<endl;
    //
    delete a;
    a = nullptr;
}

template<class B>
Executive<B>::~Executive(){}

template class Executive<B>;
template class A<B>;