/*
@author - Corey Anderson
@file - Heap.h
@date - 11/29/2019
@brief - Max heap data structure.
*/

#ifndef HEAP_H
#define HEAP_H

template <class T>
class Heap {
    public:
    	Heap(int initialSize);
    	Heap(const Heap<T>& heap); // The copy constructor
    	~Heap();

        /*
        @pre - Will receive templated item by reference to add to the heap
        @post - Will add the item to the heap at the end of the complete binary
        tree, and then percolate the item up the tree to preserve the maxheap property.
        @return - void
        */
    	void add(T& newItem);

        /*
        @pre - heap will exist
        @post - will evaluete whether the heap is empty
        @return - true if the heap is empty, false if the heap is not empty
        */
    	bool isEmpty() const;

        /*
        @pre -
        @post - Will remove an item from the heap. Gets the item at the root of
        the tree, replaces it with the item in the last node of the level order traversal,
        deletes said last node, and then percolates the root object down the tree
        until the max heap property is preserved.
        @return - void
        */
    	void remove() /* throw EmptyHeap */;

        /*
        @pre -
        @post - Gets the templated item contained within the head of the heap,
        or throws an exception if the heap is empty.
        @return - Item obtained from the head of the heap.
        */
    	T peekTop() const /* throw EmptyHeap */;

        // /*
        // @comment - Ad hoc function for the Request class as the templated item,
        // will print the binary tree by the priority number values of the requests
        // in the heap.
        // @pre -
        // @post - Tree will be printed with correct spacing.
        // @return - void
        // */
        // void print();
    private:
    	T** theHeap;
    	int sizeOfArray;
        int height;
    	int numItemsInHeap=0;

        /*
        @pre - Heap will exist.
        @post - The size of the heap array will be doubled, and the new array
        will be updated with the existing values in the old array. 
        @return - void
        */
        void doubleTheSize();
};

#endif
