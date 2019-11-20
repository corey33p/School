/*
@author - Corey Anderson
@file - Executive.h
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

#ifndef EXECUTIVE_H
#define EXECUTIVE_H

using namespace std;
#include <iostream>
#include <fstream>
#include <string>

template<class ItemType>
class Executive{
    public:
        // Constructor will read in the file and proceed to user menu interactions.
        // precondition: filename will be received
        // postcondition: file will be read in and menu loop will be executed
        // return: none
        Executive(std::string fileName);
        
        // visit function will be passed to the BST traversal methods. It will
        // receive a pokemon reference and print the pokemon information.
        // precondition: pokemon object will be received
        // postcondition: pokemon print method will be called
        // return: none
        static void visit(ItemType&);
        virtual ~Executive();
    private:
        
        // precondition: will receive a reference to a line from a tab separated data file
        // postcondition: will remove the first word in the line
        // return: string; the first word in the line
        std::string popText(std::string& line);
};

#endif

// template class BinaryNode<Pokemon>;
