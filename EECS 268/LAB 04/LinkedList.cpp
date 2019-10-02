/*
@author - Corey Anderson
@file - LinkedList.cpp
@date - 10/1/2019
@brief - LinkedList implementation, subclassed from ListInterface.h
*/

#include "PrecondViolatedExcep.h"
#include "SLNode.h"
#include "ListInterface.h"
#include "LinkedList.h"
#include "Student.h"
using namespace std;

template<class Student>
LinkedList<Student>::LinkedList() {
    LinkedList::itemCount = 0;
}

template<class Student>
LinkedList<Student>::~LinkedList() {
    LinkedList<Student>::clear();
    LinkedList::headPtr = nullptr;
}

template<class Student>
bool LinkedList<Student>::isEmpty() const {
    return LinkedList::itemCount == 0;
}

template<class Student>
int LinkedList<Student>::getLength() const {
    return LinkedList::itemCount;
}

template<class Student>
void LinkedList<Student>::insert(int newPosition, const Student& newEntry) {
    if (newPosition == -1) { newPosition = LinkedList::itemCount; }
    if (newPosition < 0){
        throw PrecondViolatedExcep("Invalid student index. ");
    } else if (newPosition > LinkedList::itemCount) {
        throw PrecondViolatedExcep("Invalid student index. ");
    }
    //
    SLNode<Student>* newNodePtr = new SLNode<Student>(newEntry);
    // SLNode<Student>* newNodePtr = new SLNode<Student>();
    newNodePtr->setItem(newEntry);
    //
    if (newPosition == 0){
        newNodePtr->setNext(LinkedList::headPtr);
        LinkedList::headPtr = newNodePtr;
    } else {
        SLNode<Student>* currPtr = LinkedList::headPtr;
        SLNode<Student>* prevNodePtr = nullptr;
        for (int i=0; i<newPosition; i++){
            prevNodePtr = currPtr;
            currPtr = currPtr->getNext();
        }
        prevNodePtr->setNext(newNodePtr);
        newNodePtr->setNext(currPtr);
        prevNodePtr = nullptr;
        newNodePtr = nullptr;
        currPtr = nullptr;
    }
    newNodePtr = nullptr;
    LinkedList::itemCount++;
}

template<class Student>
void LinkedList<Student>::remove(int position) {
    if (position < 0){
        throw PrecondViolatedExcep ("Invalid student index. ");
    } else if (position > LinkedList::itemCount) {
        throw PrecondViolatedExcep ("Invalid student index. ");
    }
    //
    SLNode<Student>* curPtr = LinkedList::headPtr;
    if (position == 0) {
       headPtr = headPtr->getNext();
    } else {
        for (int i = 0; i<position-1; i++){
            curPtr=curPtr->getNext();
        }
       SLNode<Student>* prevPtr = curPtr;
       curPtr=curPtr->getNext();
       prevPtr->setNext(curPtr->getNext());
    }
    curPtr->setNext(nullptr);
    delete curPtr;
    curPtr = nullptr;
    LinkedList::itemCount--;
}

template<class Student>
void LinkedList<Student>::clear(){
    while (LinkedList::itemCount > 0){
        LinkedList::remove(0);
    }
}

template<class Student>
Student LinkedList<Student>::getEntry(int position) const {
    if (position < 0){
        throw PrecondViolatedExcep ("Invalid student index. ");
    } else if (position > LinkedList::itemCount) {
        throw PrecondViolatedExcep ("Invalid student index. ");
    }
    SLNode<Student>* currPtr = LinkedList::headPtr;
    for (int i = 0; i<position; i++){
        if (currPtr->getNext() != nullptr) {
            currPtr = currPtr->getNext();
        }
    }
    if (currPtr == nullptr){
        throw PrecondViolatedExcep("Invalid student index. ");
    } else {
        Student student(currPtr->getItem());
        currPtr = nullptr;
        return student;;
    }
}

template<class Student>
void LinkedList<Student>::setEntry(int position, const Student& newEntry) {
    if (position < 0){
        throw PrecondViolatedExcep ("Invalid student index. ");
    } else if (position > LinkedList::itemCount) {
        throw PrecondViolatedExcep ("Invalid student index. ");
    }
    //
    SLNode<Student>* curPtr = LinkedList::headPtr;
    for (int i = 0; i<position; i++){
        curPtr=curPtr->getNext();
    }
    curPtr->setItem(newEntry);
    curPtr=nullptr;
}

template class LinkedList<Student>;
