#ifndef _EMPTY_HEAP_EXCEP
#define _EMPTY_HEAP_EXCEP
using namespace std;

#include <stdexcept>
#include <string>

using namespace std;

class EmptyHeap : public runtime_error{
   public:
       EmptyHeap(const string& message = "");
};
#endif
