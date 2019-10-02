/*
@author - Corey Anderson
@file - LinkedList.h
@date - 10/1/2019
@brief - LinkedList implementation, subclassed from ListInterface.h
*/

#ifndef LINKED_LIST
#define LINKED_LIST

using namespace std;
#include "ListInterface.h"
#include "SLNode.h"

template<class ItemType>
class LinkedList : public ListInterface<ItemType>{
    private:
        SLNode<ItemType>* headPtr;
        int itemCount;
        
        /*
        @preconditions - Will receive an object to match in the LinkedList.
        @postconditions - The pointer to the node containing the specified
        object will be found.
        @return - The pointer to the node containing the specified
        object will be returned.
        */
        SLNode<ItemType>* getPointerTo(const ItemType& target);
    public:
        LinkedList();
        virtual ~LinkedList();
        
        /*
        @preconditions -
        @postconditions - It will be determined whether the LinkedList is empty.
        @return - True or false whether the LinkedList is empty or not,
        respectively.
        */
        bool isEmpty() const;
        
        /*
        @preconditions -
        @postconditions - The length of the LinkedList will be obtained.
        @return - integer: the length of the LinkedList
        */
        int getLength() const;
        
        /*
        @preconditions - The position of the new node, as well as the object to
        place in that node will be received.
        @postconditions - The node will be created and incorporated into the LL
        appropriately, and the object will be placed in the node.
        @return - void
        */
        void insert(int newPosition, const ItemType& newEntry);
        
        /*
        @preconditions - The position of the item to be removed will be obtained
        @postconditions - The desired node in the list will be removed,
        and the node pointers adjusted accordingly.
        @return - void
        */
        void remove(int position);
        
        /*
        @preconditions -
        @postconditions - All nodes will be removed.
        @return - void
        */
        void clear();
        
        /*
        @preconditions - Desired position will be received.
        @postconditions - The data at the desired node will be found.
        @return - The data at the desired node will be returned.
        */
        ItemType getEntry(int position) const;
        
        /*
        @preconditions - The position for the entry to be modified will be
        received, as well as the new object to place in the node.
        @postconditions - The new data will be placed in the desired node.
        @return - void
        */
        void setEntry(int position, const ItemType& newEntry);
};
#endif
