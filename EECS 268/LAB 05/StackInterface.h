#ifndef _STACK_INTERFACE
#define _STACK_INTERFACE

#include "PrecondViolatedExcep.h"

template<class ItemType>
class StackInterface
{
public:
    virtual ~StackInterface() {}
    virtual bool isEmpty() const = 0;
    virtual void push(const ItemType& newEntry) /* throw (PrecondViolatedExcep) */ = 0;
    virtual void pop() /* throw (PrecondViolatedExcep) */ = 0;
    virtual ItemType peek() const /* throw (PrecondViolatedExcep) */ = 0;

};
#endif
