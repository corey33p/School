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
    rootPtr = copyTree(tree.rootPtr);
}

template<class key, class Pokemon>
BinarySearchTree<key,Pokemon>::~BinarySearchTree(){
    clear(rootPtr);
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
    if (contains(newEntry.getPNum())){ throw std::runtime_error("Key already exists in BST."); }
    BinaryNode<Pokemon>* newNodePtr = new BinaryNode<Pokemon>(newEntry);
    rootPtr = insertInorder(rootPtr,newNodePtr);
}

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::remove(const key& aKey) {
    if (!contains(aKey)){ throw std::runtime_error("Item not in tree."); }
    else { removeValue(rootPtr,aKey); }
}

template<class key, class Pokemon>
Pokemon BinarySearchTree<key,Pokemon>::getEntry(const key& aKey) const {
    BinaryNode<Pokemon>* node = findNode(rootPtr,aKey);
    if (node == nullptr) {
        throw std::runtime_error("Item not in tree");
    } else {
        return node->getItem();
    }
}

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::setEntry(const key& aKey, const Pokemon& item) const
    /* throw(NotFoundException, InvalidSetEntryRequest) */{}

template<class key, class Pokemon>
bool BinarySearchTree<key,Pokemon>::contains(const key& aKey) const{
    BinaryNode<Pokemon>* node;
    node = findNode(rootPtr,aKey);
    if (node == nullptr) { return false; }
    else { return true; }
}

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::clear(BinaryNode<Pokemon>* treePtr){
    if (treePtr!=nullptr){
        clear(treePtr->getLeft());
        clear(treePtr->getRight());
        delete treePtr;
    }
}

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::preorderTraverse(void visit(Pokemon&)) const{
    preorder(visit,rootPtr);
}

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::inorderTraverse(void visit(Pokemon&)) const{
    inorder(visit,rootPtr);
}

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::postorderTraverse(void visit(Pokemon&)) const{
    postorder(visit,rootPtr);
}

template<class key, class Pokemon>
BinarySearchTree<key,Pokemon>& BinarySearchTree<key,Pokemon>::operator=(const BinarySearchTree<key,Pokemon>& rightHandSide){
    cout<<"HERE"<<endl;
    clear(rootPtr);
	rootPtr = this->copyTree(rightHandSide.rootPtr);
	return *this;
}

/////////////////
////////protected
/////////////////

template<typename KeyType, typename ItemType>
BinaryNode<ItemType>* BinarySearchTree<KeyType, ItemType>::copyTree(const BinaryNode<ItemType>* treePtr) const {
    if (treePtr == nullptr) { return nullptr; }
    BinaryNode<Pokemon>* newNode = new BinaryNode<Pokemon>(treePtr->getItem());
    newNode->setLeft(copyTree(treePtr->getLeft()));
    newNode->setRight(copyTree(treePtr->getRight()));
    return newNode;
}

template<class key, class Pokemon>
BinaryNode<Pokemon>* BinarySearchTree<key,Pokemon>::insertInorder(BinaryNode<Pokemon>* subTreePtr,
                                   BinaryNode<Pokemon>* newNode){
    if (subTreePtr == nullptr) { return newNode; }
    else if (newNode->getItem() < subTreePtr->getItem().getPNum()){
        BinaryNode<Pokemon>* tempPtr = insertInorder(subTreePtr->getLeft(),newNode);
        subTreePtr->setLeft(tempPtr);
    } else {
        BinaryNode<Pokemon>* tempPtr = insertInorder(subTreePtr->getRight(),newNode);
        subTreePtr->setRight(tempPtr);
    }
    return subTreePtr;
}

template<class key, class Pokemon>
BinaryNode<Pokemon>* BinarySearchTree<key,Pokemon>::removeValue(BinaryNode<Pokemon>* subTreePtr,key aKey){
    BinaryNode<Pokemon>* tempPtr;
    if (subTreePtr == nullptr){
        return nullptr;
    } else if(subTreePtr->getItem()==aKey){
        subTreePtr = removeNode(subTreePtr);
        return subTreePtr;
    } else if(subTreePtr->getItem()>aKey){
        tempPtr = removeValue(subTreePtr->getLeft(),aKey);
        subTreePtr->setLeft(tempPtr);
        return subTreePtr;
    } else {
        tempPtr = removeValue(subTreePtr->getRight(),aKey);
        subTreePtr->setRight(tempPtr);
        return subTreePtr;
    }
}


template<class key, class Pokemon>
BinaryNode<Pokemon>* BinarySearchTree<key,Pokemon>::removeNode(BinaryNode<Pokemon>* nodePtr){
    if (nodePtr->isLeaf()){
        cout<<"check1"<<endl;
        delete nodePtr;
        nodePtr = nullptr;
        return nodePtr;
    } else if (nodePtr->getLeft() == nullptr || nodePtr->getRight() == nullptr){
        cout<<"check2"<<endl;
        BinaryNode<Pokemon>* newNode;
        newNode = nodePtr->getLeft();
        if (newNode == nullptr) { // if left child is empty
            cout<<"check2.5"<<endl;
            newNode = nodePtr->getRight();
        }
        delete nodePtr;
        nodePtr = nullptr;
        return newNode;
    } else {
        cout<<"check3"<<endl;
        Pokemon pokemon;
        BinaryNode<Pokemon>* newNode = removeLeftmostNode(nodePtr->getRight(),pokemon);
        // newNode->getRight()->setRight();
        nodePtr->setRight(newNode);
        nodePtr->setItem(pokemon);
        return nodePtr;
    }
}

template<class key, class Pokemon>
BinaryNode<Pokemon>* BinarySearchTree<key,Pokemon>::removeLeftmostNode(BinaryNode<Pokemon>* subTreePtr,
                                        Pokemon& inorderSuccessor){
    if (subTreePtr->getLeft() == nullptr){
        inorderSuccessor = subTreePtr->getItem();
        return removeNode(subTreePtr);
    } else {
        return removeLeftmostNode(subTreePtr->getLeft(),inorderSuccessor);
    }
}

template<class key, class Pokemon>
BinaryNode<Pokemon>* BinarySearchTree<key,Pokemon>::findNode(BinaryNode<Pokemon>* treePtr,
    key aKey) const{
    if (treePtr == nullptr) { return nullptr; }
    else if (treePtr->getItem() == aKey) { return treePtr; }
    else if (treePtr->getItem() > aKey) { return findNode(treePtr->getLeft(), aKey); }
    else { return findNode(treePtr->getRight(),aKey); }
}

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::preorder(void visit(Pokemon&), BinaryNode<Pokemon>* treePtr) const{
    if (treePtr != nullptr){
        Pokemon pokemon = treePtr->getItem();
        visit(pokemon);
        if (treePtr->getLeft() != nullptr){
            preorder(visit, treePtr->getLeft());
        }
        if (treePtr->getRight() != nullptr){
            preorder(visit, treePtr->getRight());
        }
    }
}

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::inorder(void visit(Pokemon&), BinaryNode<Pokemon>* treePtr) const{
    if (treePtr != nullptr){
        inorder(visit, treePtr->getLeft());
        Pokemon pokemon = treePtr->getItem();
        visit(pokemon);
        inorder(visit, treePtr->getRight());
    }
}

template<class key, class Pokemon>
void BinarySearchTree<key,Pokemon>::postorder(void visit(Pokemon&), BinaryNode<Pokemon>* treePtr) const{
    if (treePtr != nullptr){
        if (treePtr->getLeft() != nullptr){
            postorder(visit, treePtr->getLeft());
        }
        if (treePtr->getRight() != nullptr){
            postorder(visit, treePtr->getRight());
        }
        Pokemon pokemon = treePtr->getItem();
        visit(pokemon);
    }
}

void visit(Pokemon&){}

template class BinarySearchTree<int,Pokemon>;
