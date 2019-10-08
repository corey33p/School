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
Queue<Stack>::Queue(const Queue<Stack> &q) {Queue::queueSize = q.queueSize; }

template<class Stack>
Queue<Stack>::~Queue() {
    while (Queue::queueSize > 0){
        Queue::dequeue();
    }
    Queue::headPtr=nullptr;
}

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
    SLNode<Stack>* nextPtr = Queue::headPtr->getNext();
    delete headPtr;
    headPtr=nextPtr;
    nextPtr = nullptr;
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
        for (int i;i<Queue::queueSize-2;i++){
            cout<<"i: "<<i<<endl;
            curPtr=curPtr->getNext();
        }
        curPtr->setNext(oldHead);
        //
        curPtr = nullptr;
        oldHead = nullptr;
    }
}

template<class Stack>
Stack Queue<Stack>::peekFront(){
    Stack* stack;
    stack = new Stack(Queue::headPtr->getItem());
    return *stack;
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
