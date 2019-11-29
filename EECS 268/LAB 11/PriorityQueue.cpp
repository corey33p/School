/*
@author - Corey Anderson
@file - PriorityQueue.cpp
@date - 11/29/2019
@brief - A queue that will remain ordered based on some priority value.
*/

#include "Heap.h"
#include "PriorityQueue.h"
#include "Request.h"
#include "EmptyPriorityQueue.h"
#include "EmptyHeap.h"

template <class Request>
PriorityQueue<Request>::PriorityQueue(int initialSize){
    theHeap = new Heap<Request>(initialSize);
}

template <class Request>
PriorityQueue<Request>::PriorityQueue(const PriorityQueue<Request>& pq){
    Heap<Request> newHeap = *pq.theHeap;
    theHeap = new Heap<Request>(newHeap);
}

template <class Request>
PriorityQueue<Request>::~PriorityQueue(){ delete theHeap; }

template <class Request>
void PriorityQueue<Request>::enqueue(Request newEntry){
    Request r = Request(newEntry);
    theHeap->add(r);
}

template <class Request>
void PriorityQueue<Request>::dequeue() /* throw EmptyPriorityQueue */{
    try { theHeap->remove(); }
    catch (EmptyHeap &except) {
        throw EmptyPriorityQueue("The priority queue is empty.");
    }
}

template <class Request>
bool PriorityQueue<Request>::isEmpty() const{
    return theHeap->isEmpty();
}

template <class Request>
Request PriorityQueue<Request>::peekFront() const /* throw EmptyPriorityQueue */{
    Request request;
    try { request = theHeap->peekTop(); }
    catch (EmptyHeap &except) {
        throw EmptyPriorityQueue("The priority queue is empty.");
    }
    return request;
}

template class PriorityQueue<Request>;
