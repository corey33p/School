#ifndef _QUEUE_INTERFACE
#define _QUEUE_INTERFACE

#include "PrecondViolatedExcep.h"

template<class ItemType>
class QueueInterface

{
public:
    virtual ~QueueInterface() {}
    virtual bool isEmpty() const = 0;
    virtual void enqueue(const ItemType& newEntry) /*throw (PrecondViolatedExcep)*/ = 0;
    virtual void dequeue() /*throw (PrecondViolatedExcep)*/ = 0;
    virtual ItemType peekFront() /*const throw (PrecondViolatedExcep)*/ = 0;
};
#endif
