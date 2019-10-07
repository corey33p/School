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
    int z = 0;double a = 1/z;
    cout<<"queueSize: "<<Queue::queueSize<<endl;
    Queue::printQueue();
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
    cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!Queue::queueSize: "<<Queue::queueSize<<endl;
    if (Queue::queueSize > 1){
        SLNode<Stack>* oldHead = Queue::headPtr;
        Queue::headPtr = oldHead->getNext();
        oldHead->setNext(nullptr);
        SLNode<Stack>* curPtr = Queue::headPtr;
        //
        for (int i;i<Queue::queueSize;i++){
            cout<<"i: "<<i<<endl;
            curPtr=curPtr->getNext();
        }
        curPtr->setNext(oldHead);
        //
        curPtr = oldHead = nullptr;
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

template<class Stack>
int Queue<Stack>::getqueueSize(){ return Queue::queueSize;}

template<class Stack>
void Queue<Stack>::printQueue(){
    SLNode<Stack>* currPtr = Queue::headPtr;
    for (int i;i<Queue::queueSize;i++){
        cout<<"process name: "<<currPtr->getItem().getName()<<endl;
        currPtr=currPtr->getNext();
    }
}

// template class Stack<Subprocess>;
template class Queue<Stack<Subprocess>>;
