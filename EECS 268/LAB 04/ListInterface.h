/*
@author - Corey Anderson
@file - ListInterface.h
@date - 10/1/2019
@brief - Pure virtual class from which the LinkedList will be derived.
*/

#ifndef LIST_INTERFACE
#define LIST_INTERFACE
#include "PrecondViolatedExcep.h"
using namespace std;
#include "Student.h"
// #include "SLNode.h"

template<class ItemType>
class ListInterface{
    public:
        virtual ~ListInterface() {}
        
        /*
        @preconditions -
        @postconditions -
        @return - True if there are no nodes in the list.
        */
        virtual bool isEmpty() const = 0;
        
        /*
        @preconditions -
        @postconditions -
        @return - The number of nodes in the list.
        */
        virtual int getLength() const = 0;
        
        /*
        @preconditions - Integer containing the index of the desired location
        of the new node will be recevied, as well as the information to store
        at the new entry.
        @postconditions - The new item will be added to the appropriate location
        in the list.
        @return - void
        */
        virtual void insert(int newPosition, const ItemType& newEntry) = 0;
        
        /*
        @preconditions - Index of the node to be removed from the list will
        be received.
        @postconditions - The desired node will be removed, and the adjacent
        nodes will be adjusted accordingly.
        @return - void
        */
        virtual void remove(int position) = 0;
        
        /*
        @preconditions -
        @postconditions - All nodes in the list will be removed.
        @return - void
        */
        virtual void clear() = 0;
        
        /*
        @preconditions - The position of a node will be received.
        @postconditions - The data at the specified position in the LinkedList
        will be obtained.
        @return - The data at the specified position in the LinkedList will
        be returned.
        */
        virtual ItemType getEntry(int position) const = 0;
        
        /*
        @preconditions - The position of the node will be received, as well as
        the data to be placed in the node.
        @postconditions - The data will be placed in the node, overwriting
        the existing data.
        @return - void
        */
        virtual void setEntry(int position, const ItemType& newEntry) = 0;
};
#endif
