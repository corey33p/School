#ifndef LIST_INTERFACE
#define LIST_INTERFACE
#include "PrecondViolatedExcep.h"
using namespace std;
#include "Student.h"
// #include "SLNode.h"

template<class ItemType>
class ListInterface{
    public:
        virtual ~ListInterface() {}
        virtual bool isEmpty() const = 0;
        virtual int getLength() const = 0;
        virtual void insert(int newPosition, const ItemType& newEntry) = 0;
        virtual void remove(int position) = 0;
        virtual void clear() = 0;
        virtual ItemType getEntry(int position) const = 0;
        virtual void setEntry(int position, const ItemType& newEntry) = 0;
};
#endif

