/*
@author - Corey Anderson
@file - BinarySearchTree.h
@date - 11/20/2019
@brief - Will implement a binary search tree. Templated with the type of the
object stored in the nodes, and the type of keys used in sorting the tree.
*/

#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "BinaryNode.h"

template<class KeyType, class ItemType>
class BinarySearchTree {
    private:
        BinaryNode<ItemType>* rootPtr = nullptr;
    protected:
        // copyTree creates a deep copy of an existing BinarySearchTree
        // precondition: receive a tree to be copied
        // postcondition: Each node will be copied with the new operator
        //                to construct the copy of the BST
        // return: BinaryNode<ItemType>*; copy of tree
        BinaryNode<ItemType>* copyTree(const BinaryNode<ItemType>* treePtr) const;
        
        // precondition:
        // postcondition: node will be inserted at the correct spot in the BST
        // return: BinaryNode<ItemType>*; root of the BST
        BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr,
                                            BinaryNode<ItemType>* newNode);
                                            
        // precondition: value exists in BST
        // postcondition: value will be removed from the BST via removeNode(...)
        // return: BinaryNode<ItemType>*; pointer to the subTree of the node removed
        BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr,
                                          KeyType aKey);
      
        // precondition: node exists in BST
        // postcondition: node will be removed from the BST
        // note: if the node to be deleted has two children, the value in the node
        //       will be replaced with the inorder successor, and the previous
        //       node containing the inorder successor will be removed via removeNode
        // return: BinaryNode<ItemType>* subTreePtr of the node removed
        BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodePtr);
        
        // BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* subTreePtr,
        //                                          ItemType& inorderSuccessor);
        
        // precondition: called only from remove node, when a node containing two
        //               children is attempted to be removed
        // postcondition: reference of the ItemType contained in the node removed
        //                will be updated with the value of the ItemType in the
        //                inorder successor
        // return:
        void getLeftmostItem(BinaryNode<ItemType>* subTreePtr,
                                      ItemType& inorderSuccessor);
      
        // precondition: node containing a certain ItemType object exists
        // postcondition: node containing a certain ItemType object will be found
        // return: BinaryNode<ItemType>*; ptr to node containing ItemType object
        BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr,KeyType aKey) const;
        //
        
        // precondition: visit function and a BST pointer received
        // postcondition: visit function will be evaluated at the parent and children
        //                nodes at times dictated by the traversal type
        // return:
        void preorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
        void inorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
        void postorder(void visit(ItemType&), BinaryNode<ItemType>* treePtr) const;
    public:
        BinarySearchTree();
        
        // precondition: item to place in root node will be received
        // postcondition: BST created, root node created with specified item
        // return:
        BinarySearchTree(const ItemType& rootItem);
        
        // precondition:
        // postcondition:
        // return: BinaryNode<ItemType>* leftPtr
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
        void clear(BinaryNode<ItemType>* treePtr);
        void preorderTraverse(void visit(ItemType&)) const;
        void inorderTraverse(void visit(ItemType&)) const;
        void postorderTraverse(void visit(ItemType&)) const;
        BinarySearchTree& operator=(const BinarySearchTree& rightHandSide);
};

#endif
