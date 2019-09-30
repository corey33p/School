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
        SLNode<ItemType>* getPointerTo(const ItemType& target);
    public:
        LinkedList();
        virtual ~LinkedList();
        bool isEmpty() const;
        int getLength() const;
        void insert(int newPosition, const ItemType& newEntry);
        void remove(int position);
        void clear();
        ItemType getEntry(int position) const;
        void setEntry(int position, const ItemType& newEntry);
};
#endif

