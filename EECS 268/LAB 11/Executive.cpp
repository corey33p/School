#include <string>
#include <sstream>
#include <time.h>
#include <iostream>
#include "Executive.h"
#include "Heap.h"
#include "Request.h"

using namespace std;

template<class Request>
Executive<Request>::Executive(std::string fileName){
    ifstream file(fileName);
    if (!file.good()) {
        cout<<"Bad filename."<<endl;
        return;
    }
    srand(time(0));
    Heap<Request>* heap = new Heap<Request>(2);
    for (int i = 0;i<31;i++){
        int priority = rand()%100;
        Request* r = new Request("Abc","Def",priority);
        heap->add(r);
    }
    heap->print();
    Request topItem = heap->peekTop();
    topItem.print();
    delete heap;
}

template<class Request>
std::string Executive<Request>::popText(std::string& line){
    int tab_index = line.find_first_of("\t");
    std::string theWord = line.substr(0,tab_index);
    line = line.substr(tab_index+1,-1);
    return theWord;
}

template<class Request>
Executive<Request>::~Executive(){}

template class Executive<Request>;
template class Heap<Request>;
