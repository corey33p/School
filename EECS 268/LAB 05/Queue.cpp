#include "PrecondViolatedExcep.h"
#include "QueueInterface.h"
#include "SLNode.h"

using namespace std;

template<class Stack,class Subprocess>
Queue::Queue(){ Queue::queueSize = 0; }

template<class Stack,class Subprocess>
Queue::~Queue() {}

template<class Stack,class Subprocess>
bool Queue::isEmpty() const{ return (Queue::queueSize == 0);}

template<class Stack,class Subprocess>
void Queue::enqueue(const ItemType& newEntry){
    newPosition = Queue::queueSize;
    //
    SLNode<Stack<Subprocess>>* newNodePtr = new SLNode<Stack<Subprocess>>(newEntry);
    newNodePtr->setItem(newEntry);
    //
    if (newPosition == 0){
        newNodePtr->setNext(Queue::headPtr);
        Queue::headPtr = newNodePtr;
    } else {
        SLNode<Stack<Subprocess>>* currPtr = Queue::headPtr;
        SLNode<Stack<Subprocess>>* prevNodePtr = nullptr;
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
    Queue::queueSize++;
    }
}

template<class Stack,class Subprocess>
void Queue::dequeue(){
    position = Queue::queueSize-1;
    //
    SLNode<Stack<Subprocess>>* curPtr = Queue::headPtr;
    //
    for (int i = 0; i<position-1; i++){
        curPtr=curPtr->getNext();
    }
    SLNode<Stack<Subprocess>>* prevPtr = curPtr;
    curPtr=curPtr->getNext();
    prevPtr->setNext(curPtr->getNext());
    //
    curPtr->setNext(nullptr);
    delete curPtr;
    curPtr = nullptr;
    Queue::queueSize--;
}

template<class Stack,class Subprocess>
void toBack(){
    if (Queue::queueSize > 1){
        SLNode<Stack<Subprocess>>* curPtr = Queue::headPtr;
        SLNode<Stack<Subprocess>>* oldHead = Queue::headPtr;
        Queue::headPtr = curPtr->getNext();
        //
        SLNode<Stack<Subprocess>>* nextPtr = curPtr;
        while (nextPtr != nullptr){
            nextPtr=nextPtr->getNext();
            if (nextPtr != nullptr){
                curPtr = curPtr->getNext();
            }
        }
        curPtr->setNext(oldHead);
        //
        curPtr->setNext(nullptr);
        curPtr = nextPtr = oldHead = nullptr;
}

template<class Stack,class Subprocess>
Stack Queue::peekFront(){
    position = Queue::queueSize-1;
    //
    SLNode<Stack<Subprocess>>* currPtr = LinkedList::headPtr;
    for (int i = 0; i<position; i++){
        if (currPtr->getNext() != nullptr) {
            currPtr = currPtr->getNext();
        }
    }
    if (currPtr == nullptr){
        throw PrecondViolatedExcep("Invalid subprocess index. ");
    } else {
        Stack stack(currPtr->getItem());
        currPtr = nullptr;
        return stack;
    }
}

template<class Stack,class Subprocess>
void Queue::popStack(){
    Queue::headPtr->