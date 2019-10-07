#include "PrecondViolatedExcep.h"
#include "StackInterface.h"
#include "SLNode.h"
#include "Subprocess.h"
#include "Stack.h"

template<class Subprocess>
Stack<Subprocess>::Stack(std::string nam) : name(nam) {
    Stack::stackSize = 0;
}

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
    //
    SLNode<Subprocess>* oldHead = Stack::headPtr;
    Stack::headPtr = Stack::headPtr->getNext();
    delete oldHead;
    oldHead = nullptr;
    Stack::stackSize--;
}

template<class Subprocess>
Subprocess Stack<Subprocess>::peek() const{
    if (Stack::stackSize == 0){
        throw PrecondViolatedExcep("Invalid subprocess index. ");
    } else {
        Subprocess subprocess(Stack::headPtr->getItem());
        // currPtr = nullptr;
        return subprocess;
    }
}

template<class Subprocess>
std::string Stack<Subprocess>::getName(){return Stack::name;}

template<class Subprocess>
void Stack<Subprocess>::printStack(){
    SLNode<Subprocess>* currPtr = Stack::headPtr;
    for (int i;i<Stack::stackSize;i++){
        cout<<"subprocess name: "<<currPtr->getItem().getName()<<endl;
        currPtr=currPtr->getNext();
    }
}

template<class Subprocess>
int Stack<Subprocess>::getstackSize(){return Stack::stackSize;}

template class Stack<Subprocess>;
