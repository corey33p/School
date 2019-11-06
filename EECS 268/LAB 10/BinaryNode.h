#ifndef _BINARY_NODE
#define _BINARY_NODE

template<class ItemType>
class BinaryNode {
    private:
        ItemType item;
        BinaryNode<ItemType>* leftChildPtr;
        BinaryNode<ItemType>* rightChildPtr;
    public:
        BinaryNode();
        BinaryNode(const ItemType& anItem);
        BinaryNode(const ItemType& anItem,
                  BinaryNode<ItemType>* leftPtr,
                  BinaryNode<ItemType>* rightPtr);
        void setItem(const ItemType& anItem);
        ItemType getItem() const;
        bool isLeaf() const;
        BinaryNode<ItemType>* getLeftChildPtr() const;
        BinaryNode<ItemType>* getRightChildPtr() const;
        void setLeftChildPtr(BinaryNode<ItemType>* leftPtr);
        void setRightChildPtr(BinaryNode<ItemType>* rightPtr);
};

#include "BinaryNode.cpp"

#endif
