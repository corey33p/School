#ifndef _BINARY_NODE
#define _BINARY_NODE

template<class ItemType>
class BinaryNode {
    private:
        ItemType item;
        BinaryNode<ItemType>* leftPtr = nullptr;
        BinaryNode<ItemType>* rightPtr = nullptr;
    public:
        BinaryNode();
        BinaryNode(const ItemType& anItem);
        BinaryNode(const ItemType& anItem,
                  BinaryNode<ItemType>* leftPtr,
                  BinaryNode<ItemType>* rightPtr);
        void setItem(const ItemType& anItem);
        ItemType getItem() const;
        bool isLeaf() const;
        BinaryNode<ItemType>* getLeft() const;
        BinaryNode<ItemType>* getRight() const;
        void setLeft(BinaryNode<ItemType>* leftPtr);
        void setRight(BinaryNode<ItemType>* rightPtr);
};

#endif
