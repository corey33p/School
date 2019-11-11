using namespace std;
#include <iostream>
#include <string>
#include "Executive.h"
#include "Pokemon.h"
#include "BinaryNode.h"

template<class Pokemon>
Executive<Pokemon>::Executive(std::string fileName){
    ifstream file(fileName);
    if (!file.good()) {
        cout<<"Bad filename."<<endl;
        return;
    }
    Pokemon a = Pokemon("Ekans","Arbo",23);
    Pokemon b = Pokemon("Eevee","Eievui",133);
    Pokemon c = Pokemon("Ivysaur","Fushigisou",2);
    //
    BinaryNode<Pokemon>* rightPtr;
    rightPtr = new BinaryNode<Pokemon>(b);
    //
    BinaryNode<Pokemon>* leftPtr;
    leftPtr = new BinaryNode<Pokemon>(c);
    //
    BinaryNode<Pokemon>* rootPtr;
    rootPtr = new BinaryNode<Pokemon>(a,leftPtr,rightPtr);
    //
    rightPtr=nullptr;
    leftPtr=nullptr;
    leftPtr = rootPtr->getLeft();
    rightPtr = rootPtr->getRight();
    //
    leftPtr->getItem().print();
    rightPtr->getItem().print();    
}

template<class Pokemon>
std::string Executive<Pokemon>::popText(std::string& line){
    int tab_index = line.find_first_of("\t");
    std::string theWord = line.substr(0,tab_index);
    line = line.substr(tab_index+1,-1);
    return theWord;
}

template<class Pokemon>
Executive<Pokemon>::~Executive(){}

template class Executive<Pokemon>;
template class BinaryNode<Pokemon>;