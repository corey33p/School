#include "BinaryNode.h"
#include "Pokemon.h"

template<class Pokemon>
BinaryNode<Pokemon>::BinaryNode(){}

template<class Pokemon>
BinaryNode<Pokemon>::BinaryNode(const Pokemon& anItem){
    setItem(anItem);
}

template<class Pokemon>
BinaryNode<Pokemon>::BinaryNode(const Pokemon& anItem,
                                BinaryNode<Pokemon>* leftPtr,
                                BinaryNode<Pokemon>* rightPtr){
    setItem(anItem);
    setLeft(leftPtr);
    setRight(rightPtr);
}

template<class Pokemon>
BinaryNode<Pokemon>::BinaryNode(const BinaryNode* node){
    item = node->getItem();
    if (node->getLeft() != nullptr){
        leftPtr = new BinaryNode<Pokemon>(node->getLeft());
    }
    if (node->getRight() != nullptr){
        rightPtr = new BinaryNode<Pokemon>(node->getRight());
    }
}

template<class Pokemon>
BinaryNode<Pokemon>::~BinaryNode(){}

template<class Pokemon>
void BinaryNode<Pokemon>::setItem(const Pokemon& anItem){
    item = anItem;
}

template<class Pokemon>
Pokemon BinaryNode<Pokemon>::getItem() const{
    return item;
}

template<class Pokemon>
bool BinaryNode<Pokemon>::isLeaf() const{
    if ((leftPtr == nullptr) && (rightPtr == nullptr)){
        return true;
    } else {
        return false;
    }
}

template<class Pokemon>
BinaryNode<Pokemon>* BinaryNode<Pokemon>::getLeft() const{
    return leftPtr;
}

template<class Pokemon>
BinaryNode<Pokemon>* BinaryNode<Pokemon>::getRight() const{
    return rightPtr;
}

template<class Pokemon>
void BinaryNode<Pokemon>::setLeft(BinaryNode<Pokemon>* newLeft){
    if (leftPtr != nullptr){
        delete leftPtr;
        leftPtr = nullptr;
    }
    leftPtr = newLeft;
}

template<class Pokemon>
void BinaryNode<Pokemon>::setRight(BinaryNode<Pokemon>* newRight){
    if (rightPtr != nullptr){
        delete rightPtr;
        rightPtr = nullptr;
    }
    rightPtr = newRight;
}

template class BinaryNode<Pokemon>;
