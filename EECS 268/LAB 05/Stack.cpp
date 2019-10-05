#include "PrecondViolatedExcep.h"
#include "StackInterface.h"
#include "SLNode.h"
#include "Subprocess.h"

template<class Subprocess>
Stack::~StackInterface(std::string name) : name(name) {}

template<class Subprocess>
Stack::~StackInterface() {}

template<class Subprocess>
bool Stack::isEmpty() const{return (Stack::stackSize == 0);}

template<class Subprocess>
void Stack::push(const ItemType& newEntry){
    newPosition = 0;
    //
    SLNode<Subprocess>* newNodePtr = new SLNode<Subprocess>(newEntry);
    newNodePtr->setItem(newEntry);
    //
    if (newPosition == 0){
        newNodePtr->setNext(Stack::headPtr);
        Stack::headPtr = newNodePtr;
    } else {
        SLNode<Subprocess>* currPtr = Stack::headPtr;
        SLNode<Subprocess>* prevNodePtr = nullptr;
        for (int i=0; i<newPosition; i++){
            prevNodePtr = currPtr;
            currPtr = currPtr->getNext();
        }
        prevNodePtr->setNext(newNodePtr);
        newNodePtr->setNext(currPtr);
        prevNodePtr = nullptr;
        newNodePtr = nullptr;
        currPtr = nullptr;
    }
    newNodePtr = nullptr;
    Stack::stackSize++;
}

template<class Subprocess>
void Stack::pop(){
    position = 0;
    //
    SLNode<Subprocess>* curPtr = LinkedList::headPtr;
    if (position == 0) {
       headPtr = headPtr->getNext();
    } else {
        for (int i = 0; i<position-1; i++){
            curPtr=curPtr->getNext();
        }
       SLNode<Subprocess>* prevPtr = curPtr;
       curPtr=curPtr->getNext();
       prevPtr->setNext(curPtr->getNext());
    }
    curPtr->setNext(nullptr);
    delete curPtr;
    curPtr = nullptr;
    LinkedList::itemCount--;
}

template<class Subprocess>
Subprocess Stack::peek() const{
    position = 0;
    SLNode<Subprocess>* currPtr = LinkedList::headPtr;
    for (int i = 0; i<position; i++){
        if (currPtr->getNext() != nullptr) {
            currPtr = currPtr->getNext();
        }
    }
    if (currPtr == nullptr){
        throw PrecondViolatedExcep("Invalid subprocess index. ");
    } else {
        Subprocess subprocess(currPtr->getItem());
        currPtr = nullptr;
        return subprocess;
    }
}

