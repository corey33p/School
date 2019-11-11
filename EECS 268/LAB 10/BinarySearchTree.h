#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

// #include "NotFoundException.h"
#include "BinaryNode.h"
// #include "InvalidSetEntryRequest.h"

template<class KeyType, class ItemType>
class BinarySearchTree {
    private:
       BinaryNode<ItemType>* rootPtr = nullptr;
    protected:
        BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr,
                                            BinaryNode<ItemType>* newNode);
        BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr,
                                          KeyType aKey,
                                          bool& success);
        BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodePtr);
        BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* subTreePtr,
                                                 ItemType& inorderSuccessor);
        BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr,KeyType aKey) const;
        //
        void preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
        void inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
        void postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
    public:
        BinarySearchTree();
        BinarySearchTree(const ItemType& rootItem);
        BinarySearchTree(const BinarySearchTree& tree);
        virtual ~BinarySearchTree();
        //
        bool isEmpty() const;
        int getHeight() const;
        int getNumberOfNodes() const;
        void add(const ItemType& newEntry);
        void remove(const KeyType& aKey) /* throw(NotFoundException) */;
        ItemType getEntry(const KeyType& aKey) const /* throw(NotFoundException) */;
        //
        void setEntry(const KeyType& aKey, const ItemType& item) const/* throw(NotFoundException, InvalidSetEntryRequest) */;
        bool contains(const KeyType& aKey) const;
        void clear();
        void preorderTraverse(void visit(ItemType&)) const;
        void inorderTraverse(void visit(ItemType&)) const;
        void postorderTraverse(void visit(ItemType&)) const;
        BinarySearchTree& operator=(const BinarySearchTree& rightHandSide);
};

#endif
