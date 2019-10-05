#ifndef SLNODE_H
#define SLNODE_H
using namespace std;

template <class T>
class SLNode
{
private:
    T item;
    SLNode* next;
public:
    SLNode(){}
    SLNode(T anItem) : item(anItem), next(nullptr) {}
    SLNode(T anItem, SLNode* nextSLNode) : item(anItem), next(nextSLNode) {}
    ~SLNode(){setNext(nullptr); }
    T getItem() const { return item; }
    SLNode* getNext() const { return next; }
    void setItem(T newItem) { item = newItem; }
    void setNext(SLNode* nextSLNode) { next = nextSLNode; }
};

#endif
