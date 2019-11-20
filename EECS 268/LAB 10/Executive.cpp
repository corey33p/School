/*
@author - Corey Anderson
@file - Executive.cpp
@date - 11/20/2019
@brief - Will read in a tab separated text file of pokedex entries and
add them to the binary search tree. Then will enter a menu allowing the user
to interact with the pokedex in various ways, including

1) adding pokedex entry
2) search the tree for an existing pokemon,
3) printing  the pokedex tree with inorder, preorder or postorder traversal method
4) make one deep copy of the pokedex and perform all future operations
   on either the copy or the main tree
5) removing an existing pokedex entry
6) exit the program
*/

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
    //                       //
    // open file, build tree //
    //                       //
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
        std::string pNum_str  = popText(line);
        std::string jName = popText(line);
        stringstream ss(pNum_str);
        int pNum;
        ss >> pNum;
        //
        Pokemon pokemon = Pokemon(aName,jName,pNum);
        if (!rootMade){
            tree = new BinarySearchTree<int,Pokemon>(pokemon);
            rootMade = true;
        }
        else {
            try {tree->add(pokemon); }
            catch (std::runtime_error){
                cout<<"Error: Pokedex number "<<pokemon.getPNum()<<" already exists."<<endl;
            }
        }
    }
    //                 //
    // menu operations //
    //                 //
    BinarySearchTree<int,Pokemon>* copy;
    bool copyExists = false;
    int command = 0;
    while (command != 6){
        cout<<"\nChoose a Pokedex command\n"
            <<"1) add\n"
            <<"2) search\n"
            <<"3) print\n"
            <<"4) copy\n"
            <<"5) remove\n"
            <<"6) quit\n"
            <<"---> ";
       cin>>command;
       while (!cin) {
           cin.clear();
           while (cin.get() != '\n') { continue; }
           cout<<"Invalid command.\n---> ";
           cin>>command;
       }
       if (command == 1){
           string aName;
           string jName;
           int pNum;
           cout<<"American name: ";
           cin>> aName;
           cout<<"Japanese name: ";
           cin>> jName;
           cout<<"Pokedex number: ";
           cin>> pNum;
           while (!cin) {
               cin.clear();
               while (cin.get() != '\n') { continue; }
               cout<<"Invalid input. Enter Pokedex number: ";
               cin>>pNum;
           }
           if (copyExists){
               int treeChoice;
               cout<<"Add to copy or main?\n"
                   <<"1) main\n"
                   <<"2) copy\n"
                   <<"---> ";
               cin>>treeChoice;
               if (treeChoice == 1){
                   Pokemon pokemon = Pokemon(aName,jName,pNum);
                   try{
                       tree->add(pokemon);
                   } catch (std::runtime_error){
                       cout<<"Error: Pokedex number "<<pokemon.getPNum()<<" already exists."<<endl;
                   }
               } else if (treeChoice == 2){
                   Pokemon pokemon = Pokemon(aName,jName,pNum);
                   try{
                       copy->add(pokemon);
                   } catch (std::runtime_error){
                       cout<<"Error: Pokedex number "<<pokemon.getPNum()<<" already exists."<<endl;
                   }
               } else { cout<<"Bad tree choice.";}
           } else {
               Pokemon pokemon = Pokemon(aName,jName,pNum);
               try {
                   tree->add(pokemon);
               } catch (std::runtime_error){
                   cout<<"Error: Pokedex number "<<pokemon.getPNum()<<" already exists."<<endl;
               }
           }
       } else if (command == 2){
           int key;
           cout<<"Enter pokedex number to search for: ";
           cin>>key;
           if (copyExists){
               int treeChoice;
               cout<<"Search copy or main?\n"
                   <<"1) main\n"
                   <<"2) copy\n"
                   <<"---> ";
               cin>>treeChoice;
               if (treeChoice == 1){
                   if (tree->contains(key)){
                       try{
                           Pokemon pokemon = tree->getEntry(key);
                           pokemon.print();
                       } catch (std::runtime_error){
                           cout<<"Error: Pokedex number not found."<<endl;
                       }
                   } else { cout<<"Main pokedex does not contain this pokemon."<<endl; }
               } else if (treeChoice == 2){
                   if (copy->contains(key)){
                       try {
                           Pokemon pokemon = copy->getEntry(key);
                           pokemon.print();
                       } catch (std::runtime_error){
                           cout<<"Error: Pokedex number not found."<<endl;
                       }
                   } else { cout<<"Copy pokedex does not contain this pokemon."<<endl; }
               } else { cout<<"Bad tree choice.";}
           } else {
               if (tree->contains(key)){
                   try {
                       Pokemon pokemon = tree->getEntry(key);
                       pokemon.print();
                   } catch (std::runtime_error){
                       cout<<"Error: Pokedex number not found."<<endl;
                   }
               } else { cout<<"Pokedex does not contain this pokemon."<<endl; }
           }
       } else if (command == 3){
           int traversalType;
           cout<<"Choose a traversal type\n"
               <<"1) inorder\n"
               <<"2) preorder\n"
               <<"3) postorder\n"
               <<"---> ";
           cin>>traversalType;
           if (copyExists) {
               int treeChoice;
               cout<<"Print copy or main?\n"
                   <<"1) main\n"
                   <<"2) copy\n"
                   <<"---> ";
               cin>>treeChoice;
               if (treeChoice == 1){
                   if (traversalType == 1) {
                       cout<<endl;
                       tree->inorderTraverse(visit);
                   } else if (traversalType == 2) {
                       cout<<endl;
                       tree->preorderTraverse(visit);
                   } else if (traversalType == 3) {
                       cout<<endl;
                       tree->postorderTraverse(visit);
                   } else {
                       cout<<"Invalid traversal choice."<<endl;
                   }
               } else if (treeChoice == 2){
                   if (traversalType == 1) {
                       cout<<endl;
                       copy->inorderTraverse(visit);
                   } else if (traversalType == 2) {
                       cout<<endl;
                       copy->preorderTraverse(visit);
                   } else if (traversalType == 3) {
                       cout<<endl;
                       copy->postorderTraverse(visit);
                   } else {
                       cout<<"Invalid traversal choice."<<endl;
                   }
               } else { cout<<"Bad tree choice."<<endl;}
           } else {
               if (traversalType == 1) {
                   cout<<endl;
                   tree->inorderTraverse(visit);
               } else if (traversalType == 2) {
                   cout<<endl;
                   tree->preorderTraverse(visit);
               } else if (traversalType == 3) {
                   cout<<endl;
                   tree->postorderTraverse(visit);
               } else {
                   cout<<"Invalid traversal choice."<<endl;
               }
           }
       } else if (command == 4){
           if (!copyExists) {
               copy = new BinarySearchTree<int,Pokemon>(*tree);
               copyExists = true;
               cout<<"Copy has been created."<<endl;
           } else { cout<<"A copy already exists."<<endl; }
       } else if (command == 5){
           int pNum;
           cout<<"Pokedex number to delete: ";
           cin>> pNum;
           while (!cin) {
               cin.clear();
               while (cin.get() != '\n') { continue; }
               cout<<"Invalid input. Enter Pokedex number: ";
               cin>>pNum;
           }
           if (copyExists){
               int treeChoice;
               cout<<"Remove from copy or main?\n"
                   <<"1) main\n"
                   <<"2) copy\n"
                   <<"---> ";
               cin>>treeChoice;
               if (treeChoice == 1){
                   try{
                       tree->remove(pNum);
                   } catch (std::runtime_error){
                       cout<<"Error: Pokedex number doesn't exist."<<endl;
                   }
               } else if (treeChoice == 2){
                   try{
                       copy->remove(pNum);
                   } catch (std::runtime_error){
                       cout<<"Error: Pokedex number doesn't exist."<<endl;
                   }
               } else { cout<<"Bad tree choice.";}
           } else {
               try {
                   tree->remove(pNum);
               } catch (std::runtime_error){
                   cout<<"Error: Pokedex number doesn't exist."<<endl;
               }
           }
       } else if (command == 6){
           delete tree;
           if (copyExists){ delete copy; }
       } else {
           cout<<"Invalid command."<<endl;
       }
   }
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
