#include "PrecondViolatedExcep.h"
#include "QueueInterface.h"

using namespace std;

#ifndef _QUEUE
#define _QUEUE


template<class ItemType>
class Queue : public QueueInterface<ItemType>{
    private:
        int queueSize;
        
    public:
        virtual ~QueueInterface() {}
        virtual bool isEmpty() const = 0;
        virtual void enqueue(const ItemType& newEntry) /*throw (PrecondViolatedExcep)*/ = 0;
        virtual void dequeue() /*throw (PrecondViolatedExcep)*/ = 0;
        virtual ItemType peekFront() /*const throw (PrecondViolatedExcep)*/ = 0;
};
#endif
