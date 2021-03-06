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
        
        // precondition: receives an already existing Binary Search Tree
        // postcondition: creates a deep copy of a BST by copyTree(...)
        // return:
        BinarySearchTree(const BinarySearchTree& tree);
        
        // precondition:
        // postcondition: BST will be deleted
        // return:
        virtual ~BinarySearchTree();
        //
        // precondition:
        // postcondition: will be evaluated whether the BST is empty
        // return: True if headptr null, false if headptr not null
        bool isEmpty() const;
        
        // precondition:
        // postcondition: height of BST will be evaluated
        // return: int; height of BST
        int getHeight() const;
        
        // precondition:
        // postcondition: number of nodes in the BST will be evaluated
        // return: int; number of nodes
        int getNumberOfNodes() const;
        
        // precondition: neceives reference to ItemType object to be inserted
        //               in the new node
        // postcondition: node created, placed in tree, ItemType object added to node
        // return:
        void add(const ItemType& newEntry);
        
        // precondition: KeyType of node to be deleted will be received
        // postcondition: node to be deleted will be deleted if it exists
        //                exception will be thrown otherwise
        // return:
        void remove(const KeyType& aKey);
        
        // precondition: KeyType of the node to be retrieved will be received
        // postcondition:
        // return: ItemType; ItemType object matching key
        ItemType getEntry(const KeyType& aKey) const /* throw(NotFoundException) */;
        //
        
        // precondition: KeyType key of node to be searched for will be received
        // postcondition:
        // return: bool; true iff ItemType matching node is found in truee
        bool contains(const KeyType& aKey) const;
        
        // precondition: receive a pointer to a BST to be cleared
        // postcondition: BST will be cleared at and below received pointer
        // return: BinaryNode<ItemType>* leftPtr
        void clear(BinaryNode<ItemType>* treePtr);
        
        // precondition: visit function received defining behaviour during traversal
        // postcondition: BST will be traversed in preorder fashion, executing the
        //                visit function at each step
        // return:
        void preorderTraverse(void visit(ItemType&)) const;
        
        // precondition: visit function received defining behaviour during traversal
        // postcondition: BST will be traversed in inorder fashion, executing the
        //                visit function at each step
        // return:
        void inorderTraverse(void visit(ItemType&)) const;
        
        // precondition: visit function received defining behaviour during traversal
        // postcondition: BST will be traversed in postorder fashion, executing the
        //                visit function at each step
        // return:
        void postorderTraverse(void visit(ItemType&)) const;
        
        // precondition: RHS of = operator will be received, which is another BST
        // postcondition: BST will be cleared and copied, matching RHS of = operator
        // return: copy of the BST on the right side of the = operator
        BinarySearchTree& operator=(const BinarySearchTree& rightHandSide);
};

#endif
