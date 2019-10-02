#include "PrecondViolatedExcep.h"
#include "QueueInterface.h"

using namespace std;

virtual ~QueueInterface() {}
virtual bool isEmpty() const = 0;
virtual void enqueue(const ItemType& newEntry) /*throw (PrecondViolatedExcep)*/ = 0;
virtual void dequeue() /*throw (PrecondViolatedExcep)*/ = 0;
virtual ItemType peekFront() /*const throw (PrecondViolatedExcep)*/ = 0;
