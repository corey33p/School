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
    }
    LinkedList::itemCount++;
}

template<class Student>
void LinkedList<Student>::remove(int position) {
    if (position < 0){
        throw PrecondViolatedExcep ("Invalid student index. ");
    } else if (position > LinkedList::itemCount) {
        throw PrecondViolatedExcep ("Invalid student index. ");
    }
    SLNode<Student>* currPtr = LinkedList::headPtr;
    SLNode<Student>* prevNodePtr = nullptr;
    for (int i = 0; i<position; i++){
        prevNodePtr = currPtr;
        currPtr = currPtr->getNext();
    }
    SLNode<Student>* nextNodePtr = currPtr->getNext();
    delete currPtr;
    prevNodePtr->setNext(nextNodePtr);
    LinkedList::itemCount--;
}

template<class Student>
void LinkedList<Student>::clear(){
    SLNode<Student>* currPtr = LinkedList::headPtr;
    SLNode<Student>* prevNodePtr = nullptr;
    for (int i = 0; i<LinkedList::itemCount; i++){
        prevNodePtr = currPtr;
        currPtr = currPtr->getNext();
        prevNodePtr->setNext(nullptr);
        delete currPtr;
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
        currPtr = currPtr->getNext();
    }
    return currPtr->getItem();
}

template<class Student>
void LinkedList<Student>::setEntry(int position, const Student& newEntry) {
    
}
template class LinkedList<Student>;