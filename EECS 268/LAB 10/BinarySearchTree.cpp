// #include "NotFoundException.h"
#include "BinaryNode.h"
#include "Pokemon.h"
#include "BinarySearchTree.h"
// #include "InvalidSetEntryRequest.h"
#include <memory>
#include <iostream>

/////////////////
////////   public
/////////////////

template<class key, class Pokemon>
BinarySearchTree<key,Pokemon>::BinarySearchTree(){}

template<class key, class Pokemon>
BinarySearchTree<key,Pokemon>::BinarySearchTree(const Pokemon& rootItem){
    rootPtr = new BinaryNode<Pokemon>(rootItem);
}

template<class key, class Pokemon>
BinarySearchTree<key,Pokemon>::BinarySearchTree(const BinarySearchTree& tree){
    rootPtr = new BinaryNode<Pokemon>(tree.rootPtr);
}

template<class key, class Pokemon>
BinarySearchTree<key,Pokemon>::~BinarySearchTree(){
    if (!isEmpty()){
        clear(rootPtr);
    }
}

template<class key, class Pokemon>
bool BinarySearchTree<key,Pokemon>::isEmpty() const{
    if (rootPtr == nullptr) { return true; }
    else { return false; }
}

template<class key, class Pokemon>
int BinarySearchTree<key,Pokemon>::getHeight() const{return 0;}

template<class key, class Pokemon>
int BinarySearchTree<key,Pokemon>::getNumberOfNodes() const{
    return 0;
}

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::add(const Pokemon& newEntry){
    BinaryNode<Pokemon>* newNodePtr = new BinaryNode<Pokemon>(newEntry);
    rootPtr = insertInorder(rootPtr,newNodePtr);
}

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::remove(const key& aKey) /* throw(NotFoundException) */{}

// template<class key, class Pokemon>
// Pokemon BinarySearchTree<key,Pokemon>::getEntry(const key& aKey) const /* throw(NotFoundException) */{
    
// }

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::setEntry(const key& aKey, const Pokemon& item) const
    /* throw(NotFoundException, InvalidSetEntryRequest) */{}
    
template<class key, class Pokemon>
bool BinarySearchTree<key,Pokemon>::contains(const key& aKey) const{return true;}

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::clear(BinaryNode<Pokemon>* treePtr){
    if (treePtr->isLeaf()){ delete treePtr; }
    else {
        if (treePtr->getLeft()->isLeaf()){
            delete treePtr->getLeft();
        } else {
            clear(treePtr->getLeft());
        }
        if (treePtr->getRight()->isLeaf()){
            delete treePtr->getRight();
        } else {
            clear(treePtr->getRight());
        }
        delete treePtr;
    }
}

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::preorderTraverse(void visit(Pokemon&)) const{}

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::inorderTraverse(void visit(Pokemon&)) const{
    inorder(visit,rootPtr);
}

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::postorderTraverse(void visit(Pokemon&)) const{}

// template<class key, class Pokemon>
// BinarySearchTree<key,Pokemon>& BinarySearchTree<key,Pokemon>::operator=(const BinarySearchTree<key,Pokemon>& rightHandSide){}

/////////////////
////////protected
/////////////////

template<class key, class Pokemon>
BinaryNode<Pokemon>* BinarySearchTree<key,Pokemon>::insertInorder(BinaryNode<Pokemon>* subTreePtr,
                                   BinaryNode<Pokemon>* newNode){
    BinaryNode<Pokemon>* tempPtr = nullptr;
    if (subTreePtr == nullptr) { return newNode; }
    else if (newNode->getItem() < subTreePtr->getItem().getPNum()){
        tempPtr = insertInorder(subTreePtr->getLeft(),newNode);
        subTreePtr->setLeft(tempPtr);
    } else {
        tempPtr = insertInorder(subTreePtr->getRight(),newNode);
        subTreePtr->setRight(tempPtr);
    }
    return subTreePtr;
}

// template<class key, class Pokemon>
// BinaryNode<Pokemon>* BinarySearchTree<key,Pokemon>::removeValue(BinaryNode<Pokemon>* subTreePtr,
                                 // key,
                                 // bool& success){
    
// }

// template<class key, class Pokemon>
// BinaryNode<Pokemon>* BinarySearchTree<key,Pokemon>::removeNode(BinaryNode<Pokemon>* nodePtr){
//
// }

// template<class key, class Pokemon>
// BinaryNode<Pokemon>* BinarySearchTree<key,Pokemon>::removeLeftmostNode(BinaryNode<Pokemon>* subTreePtr,
                                        // Pokemon& inorderSuccessor){
    
// }

// template<class key, class Pokemon>
// BinaryNode<Pokemon>* BinarySearchTree<key,Pokemon>::findNode(BinaryNode<Pokemon>* treePtr,
    // key) const{
    
// }

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::preorder(void visit(Pokemon&), BinaryNode<Pokemon>* treePtr) const{
    if (treePtr != nullptr){
        Pokemon pokemon = treePtr->getItem();
        visit(pokemon);
        if (treePtr->getLeft() != nullptr){
            inorder(visit, treePtr->getLeft());
        }
        if (treePtr->getRight() != nullptr){
            inorder(visit, treePtr->getRight());
        }
    }
}

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::inorder(void visit(Pokemon&), BinaryNode<Pokemon>* treePtr) const{
    if (treePtr != nullptr){
        if (treePtr->getLeft() != nullptr){
            inorder(visit, treePtr->getLeft());
        }
        Pokemon pokemon = treePtr->getItem();
        visit(pokemon);
        if (treePtr->getRight() != nullptr){
            inorder(visit, treePtr->getRight());
        }
    }
}

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::postorder(void visit(Pokemon&), BinaryNode<Pokemon>* treePtr) const{
    if (treePtr != nullptr){
        if (treePtr->getLeft() != nullptr){
            inorder(visit, treePtr->getLeft());
        }
        if (treePtr->getRight() != nullptr){
            inorder(visit, treePtr->getRight());
        }
        Pokemon pokemon = treePtr->getItem();
        visit(pokemon);
    }
}

void visit(Pokemon&){}

template class BinarySearchTree<int,Pokemon>;
