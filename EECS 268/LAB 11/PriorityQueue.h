/*
@author - Corey Anderson
@file - PriorityQueue.h
@date - 11/29/2019
@brief - A queue that will remain ordered based on some priority value.
*/

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include "Heap.h"

template <typename T>
class PriorityQueue{
    public:
    	PriorityQueue(int initialSize);
    	PriorityQueue(const PriorityQueue<T>& pq); // The copy constructor
    	~PriorityQueue();

        /*
        @pre - Will receive the new entry to be added to the queue.
        @post - Will add the item to the queue at the correct location.
        @return - void
        */
    	void enqueue(T newEntry);

        /*
        @pre -
        @post - Will remove the item at the front of the queue, or throw an
        exception if the queue is empty.
        @return - void
        */
    	void dequeue() /* throw EmptyPriorityQueue */;

        /*
        @pre -
        @post - Evaluates whether the queue is empty.
        @return - Returns true if the queue is empty or false if the queue is not empty.
        */
    	bool isEmpty() const;

        /*
        @pre -
        @post - Throws exception of the queue is empty, otherwise returns the
        item at the front of the queue.
        @return - templated itemtype item at the frant of the queue.
        */
    	T peekFront() const /* throw EmptyPriorityQueue */;
    private:
    	Heap<T>* theHeap;
};

#endif
