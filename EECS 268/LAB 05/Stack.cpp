#include "PrecondViolatedExcep.h"
#include "StackInterface.h"
#include "SLNode.h"
#include "Subprocess.h"
#include "Stack.h"

template<class Subprocess>
Stack<Subprocess>::Stack(std::string nam) : name(nam) {}

template<class Subprocess>
Stack<Subprocess>::~Stack() {}

template<class Subprocess>
bool Stack<Subprocess>::isEmpty() const{return (Stack::stackSize == 0);}

template<class Subprocess>
void Stack<Subprocess>::push(const Subprocess& newEntry){
    int newPosition = 0;
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
void Stack<Subprocess>::pop(){
    int position = 0;
    //
    SLNode<Subprocess>* curPtr = Stack::headPtr;
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
    Stack::stackSize--;
}

template<class Subprocess>
Subprocess Stack<Subprocess>::peek() const{
    // int position = 0;
    SLNode<Subprocess>* currPtr = Stack::headPtr;
    // for (int i = 0; i<position; i++){
    //     if (currPtr->getNext() != nullptr) {
    //         currPtr = currPtr->getNext();
    //     }
    // }
    if (Stack::stackSize == 0){
        throw PrecondViolatedExcep("Invalid subprocess index. ");
    } else {
        Subprocess subprocess(currPtr->getItem());
        currPtr = nullptr;
        return subprocess;
    }
}

template<class Subprocess>
std::string Stack<Subprocess>::getName(){return Stack::name;}

template class Stack<Subprocess>;
