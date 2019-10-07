#ifndef _STACK
#define _STACK

#include "PrecondViolatedExcep.h"
#include "StackInterface.h"
#include "SLNode.h"

template<class ItemType>
class Stack : public StackInterface<ItemType>{
    private:
        int stackSize;
        SLNode<ItemType>* headPtr;
        std::string name;
    public:
        Stack(std::string nam);
        virtual ~Stack();
        bool isEmpty() const;
        void push(const ItemType& newEntry); // throw (PrecondViolatedExcep) 
        void pop(); // throw (PrecondViolatedExcep)
        ItemType peek() const; // throw (PrecondViolatedExcep)
        std::string getName();
};
#endif
