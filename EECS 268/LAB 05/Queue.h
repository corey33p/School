#ifndef _QUEUE
#define _QUEUE

#include "PrecondViolatedExcep.h"
#include "QueueInterface.h"
#include "SLNode.h"

using namespace std;

template<class ItemType>
class Queue : public QueueInterface<ItemType>{
    private:
        int queueSize;
        SLNode<ItemType>* headPtr;
    public:
        Queue();
        Queue(const Queue<ItemType>& q);
        virtual ~Queue();
        bool isEmpty() const;
        void enqueue(const ItemType& newEntry);
        void dequeue();
        void toBack();
        ItemType peekFront();
        int getqueueSize();
        void printQueue();
};
#endif
