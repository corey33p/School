/*
@author - Corey Anderson
@file - SLNode.h
@date - 10/1/2019
@brief - Declaration of the node object that will be used by the linked list.
*/

#ifndef SLNODE_H
#define SLNODE_H
using namespace std;

template <class T>
class SLNode
{
private:
    T item;
    SLNode* next;
public:
    SLNode(){}
    SLNode(T anItem) : item(anItem), next(nullptr) {}
    SLNode(T anItem, SLNode* nextSLNode) : item(anItem), next(nextSLNode) {}
    ~SLNode(){setNext(nullptr); }
    
    /*
    @preconditions -
    @postconditions -
    @return - The object contained in this node will be returned.
    */
    T getItem() const { return item; }
    
    /*
    @preconditions -
    @postconditions -
    @return - The pointer to the next node in the next list will be returned.
    */
    SLNode* getNext() const { return next; }
    
    /*
    @preconditions - The object to place in this node will be received.
    @postconditions - The object will be placed in the node.
    @return - void
    */
    void setItem(T newItem) { item = newItem; }
    
    /*
    @preconditions - The pointer to the desired next node will be received.
    @postconditions - The next node pointer will be updated.
    @return - void
    */
    void setNext(SLNode* nextSLNode) { next = nextSLNode; }
};

#endif
