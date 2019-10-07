#include "PrecondViolatedExcep.h"
#include "QueueInterface.h"
#include "SLNode.h"
#include "Queue.h"
#include "Stack.h"
#include "Subprocess.h"

using namespace std;

template<class Stack>
Queue<Stack>::Queue(){ Queue::queueSize = 0; }

template<class Stack>
Queue<Stack>::~Queue() {}

template<class Stack>
bool Queue<Stack>::isEmpty() const{ return (Queue::queueSize == 0);}

template<class Stack>
void Queue<Stack>::enqueue(const Stack& newEntry){
    int newPosition = Queue::queueSize;
    //
    SLNode<Stack>* newNodePtr = new SLNode<Stack>(newEntry);
    newNodePtr->setItem(newEntry);
    //
    if (newPosition == 0){
        newNodePtr->setNext(Queue::headPtr);
        Queue::headPtr = newNodePtr;
    } else {
        SLNode<Stack>* currPtr = Queue::headPtr;
        SLNode<Stack>* prevNodePtr = nullptr;
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

template<class Stack>
void Queue<Stack>::dequeue(){
    int position = Queue::queueSize-1;
    //
    SLNode<Stack>* curPtr = Queue::headPtr;
    //
    for (int i = 0; i<position-1; i++){
        curPtr=curPtr->getNext();
    }
    SLNode<Stack>* prevPtr = curPtr;
    curPtr=curPtr->getNext();
    prevPtr->setNext(curPtr->getNext());
    //
    curPtr->setNext(nullptr);
    delete curPtr;
    curPtr = nullptr;
    Queue::queueSize--;
}

template<class Stack>
void Queue<Stack>::toBack(){
    if (Queue::queueSize > 1){
        SLNode<Stack>* curPtr = Queue::headPtr;
        SLNode<Stack>* oldHead = Queue::headPtr;
        Queue::headPtr = curPtr->getNext();
        //
        SLNode<Stack>* nextPtr = curPtr;
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
}

template<class Stack>
Stack Queue<Stack>::peekFront(){
    int position = Queue::queueSize-1;
    //
    SLNode<Stack>* currPtr = Queue::headPtr;
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

// template class Stack<Subprocess>;
template class Queue<Stack<Subprocess>>;