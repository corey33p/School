using namespace std;
#include <iostream>
#include <string>
#include <sstream>
#include "Executive.h"
#include "Pokemon.h"
#include "BinaryNode.h"
#include "BinarySearchTree.h"

template<class Pokemon>
Executive<Pokemon>::Executive(std::string fileName){
    ifstream file(fileName);
    if (!file.good()) {
        cout<<"Bad filename."<<endl;
        return;
    }
    BinarySearchTree<int,Pokemon>* tree;
    bool rootMade = false;
    std::string line;
    while (std::getline(file, line)) {
        std::string aName = popText(line);
        // cout<<"aName: "<<aName<<endl;
        std::string pNum_str  = popText(line);
        std::string jName = popText(line);
        // cout<<"jName: "<<jName<<endl;
        stringstream ss(pNum_str);
        int pNum;
        ss >> pNum;
        // cout<<"pNum: "<<pNum<<endl;
        //
        Pokemon pokemon = Pokemon(aName,jName,pNum);
        if (!rootMade){
            tree = new BinarySearchTree<int,Pokemon>(pokemon);
            rootMade = true;
        }
        else { tree->add(pokemon); }
        cout<<endl;
        tree->inorderTraverse(visit);
    }
    // Pokemon a = Pokemon("Ekans","Arbo",23);
    // Pokemon b = Pokemon("Eevee","Eievui",133);
    // Pokemon c = Pokemon("Ivysaur","Fushigisou",2);
    // //
    // BinarySearchTree<int,Pokemon>* tree;
    // tree = new BinarySearchTree<int,Pokemon>(a);
    // //
    // tree->inorderTraverse(visit);
    // //
    // tree->add(b);
    // tree->inorderTraverse(visit);
    // //
    // tree->add(c);
    // tree->inorderTraverse(visit);
    delete tree;
}

template<class Pokemon>
std::string Executive<Pokemon>::popText(std::string& line){
    int tab_index = line.find_first_of("\t");
    std::string theWord = line.substr(0,tab_index);
    line = line.substr(tab_index+1,-1);
    return theWord;
}

template<class Pokemon>
void Executive<Pokemon>::visit(Pokemon& pokemon){
    pokemon.print();
}

template<class Pokemon>
Executive<Pokemon>::~Executive(){}

template class Executive<Pokemon>;
template class BinaryNode<Pokemon>;
