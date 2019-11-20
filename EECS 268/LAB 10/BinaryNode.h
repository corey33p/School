/*
@author - Corey Anderson
@file - BinaryNode.h
@date - 11/20/2019
@brief - Will implement BinaryNode objects which will be used in the construction
of the tree structure.
*/

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
        
        // This constructor create a node with null child pointers and an existing
        // ItemType object.
        // precondition: ItemType object will be received.
        // postcondition: Node created with null children.
        // return: none
        BinaryNode(const ItemType& anItem);
        
        // This constructor create a node with user specified child pointers and an existing
        // ItemType object.
        // precondition: ItemType object and child pointers will be received.
        // postcondition: Node created and child pointers will be set.
        // return: none
        BinaryNode(const ItemType& anItem,
                  BinaryNode<ItemType>* leftPtr,
                  BinaryNode<ItemType>* rightPtr);
        
        // This constructor create a node from the data in an existing node,
        // very much like a copy constructor.
        // precondition: ItemType object will be received.
        // postcondition: Node created with null children.
        // return: none
        BinaryNode(const BinaryNode* node);
        
        ~BinaryNode();
        
        // This constructor create a node from the data in an existing node,
        // very much like a copy constructor.
        // precondition: ItemType object will be received.
        // postcondition: Node created with null children.
        // return: none
        void setItem(const ItemType& anItem);
        
        // precondition: ItemType object will exist in the node.
        // postcondition:
        // return: ItemType object contained in the node.
        ItemType getItem() const;
        
        // precondition:
        // postcondition:
        // return: True if and only if child pointers are both null
        bool isLeaf() const;
        
        // precondition:
        // postcondition:
        // return: BinaryNode<ItemType>* leftPtr
        BinaryNode<ItemType>* getLeft() const;
        
        // precondition:
        // postcondition:
        // return: BinaryNode<ItemType>* rightPtr
        BinaryNode<ItemType>* getRight() const;
        
        // precondition: new leftPtr will be received
        // postcondition: leftPtr will be updated
        // return:
        void setLeft(BinaryNode<ItemType>* leftPtr);
        
        // precondition: new rightPtr will be received
        // postcondition: rightPtr will be updated
        // return:
        void setRight(BinaryNode<ItemType>* rightPtr);
};

#endif
