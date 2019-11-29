#ifndef _EMPTY_PQ_EXCEP
#define _EMPTY_PQ_EXCEP
using namespace std;

#include <stdexcept>
#include <string>
#include "EmptyPriorityQueue.h"

class EmptyPriorityQueue : public runtime_error{
   public:
       EmptyPriorityQueue(const string& message = "");
};
#endif
