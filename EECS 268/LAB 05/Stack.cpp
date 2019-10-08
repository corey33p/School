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
Stack<Subprocess>::~Stack() {
    while (Stack::stackSize > 0){
        Stack::pop();
    }
    Stack::headPtr=nullptr;
}

template<class Subprocess>
bool Stack<Subprocess>::isEmpty() const{return (Stack::stackSize == 0);}

template<class Subprocess>
void Stack<Subprocess>::push(const Subprocess& newEntry){
    int newPosition = Stack::stackSize;
    //
    SLNode<Subprocess>* newNodePtr = new SLNode<Subprocess>(newEntry);
    newNodePtr->setItem(newEntry);
    //
    if (newPosition == 0){
        // newNodePtr->setNext(Stack::headPtr);
        Stack::headPtr = newNodePtr;
    } else {
        SLNode<Subprocess>* currPtr = Stack::headPtr;
        SLNode<Subprocess>* prevNodePtr = nullptr;
        // for (int i=0; i<newPosition; i++){
        while (currPtr != nullptr){
            prevNodePtr = currPtr;
            currPtr = currPtr->getNext();
        }
        prevNodePtr->setNext(newNodePtr);
        prevNodePtr = nullptr;
        newNodePtr = nullptr;
        currPtr = nullptr;
    }
    newNodePtr = nullptr;
    Stack::stackSize++;
}

template<class Subprocess>
void Stack<Subprocess>::pop(){
    if (Stack::stackSize == 0){return;}
    // cout<<"Stack::stackSize1: "<<Stack::stackSize<<endl;
    //
    if (Stack::stackSize == 1) {
        delete Stack::headPtr;
        Stack::headPtr = nullptr;
        // Stack::headPtr = Stack::headPtr->getNext();
    } else if (Stack::stackSize == 2){
        SLNode<Subprocess>* nextPtr = Stack::headPtr->getNext();
        // nextPtr->setNext(nullptr);
        delete(nextPtr);
        Stack::headPtr->setNext(nullptr);
    }else {
        SLNode<Subprocess>* curPtr = Stack::headPtr;
        for (int i = 0; i<Stack::stackSize-2; i++){
            curPtr=curPtr->getNext();
        }
        SLNode<Subprocess>* prevPtr = curPtr;
        curPtr=curPtr->getNext();
        prevPtr->setNext(nullptr);
        prevPtr = nullptr;
        // curPtr->setNext(nullptr);
        delete curPtr;
        curPtr = nullptr;
    }
    Stack::stackSize--;
    // cout<<"Stack::stackSize2: "<<Stack::stackSize<<endl;
}

template<class Subprocess>
Subprocess Stack<Subprocess>::peek() const{
    int position = Stack::stackSize-1;
    //
    SLNode<Subprocess>* curPtr = Stack::headPtr;
    if (position == 1){
        Subprocess* subprocess;
        subprocess = new Subprocess(Stack::headPtr->getItem());
        curPtr = nullptr;
        return *subprocess;
    } else if (position > 1)  {
        for (int i = 0; i<position; i++){
            curPtr=curPtr->getNext();
        }
    }
    cout<<"position: "<<position<<endl;
    Subprocess* subprocess;
    subprocess = new Subprocess(curPtr->getItem());
    curPtr = nullptr;
    return *subprocess;
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
    currPtr = nullptr;
}

template<class Subprocess>
int Stack<Subprocess>::getstackSize(){return Stack::stackSize;}

template class Stack<Subprocess>;
