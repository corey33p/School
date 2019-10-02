#ifndef _STACK
#define _STACK

#include "PrecondViolatedExcep.h"
#include "StackInterface.h"

template<class ItemType>
class Stack : public StackInterface<ItemType>{
    public:
        virtual ~StackInterface() {}
        virtual bool isEmpty() const = 0;
        virtual void push(const ItemType& newEntry) /* throw (PrecondViolatedExcep) */ = 0;
        virtual void pop() /* throw (PrecondViolatedExcep) */ = 0;
        virtual ItemType peek() const /* throw (PrecondViolatedExcep) */ = 0;
};
#endif
