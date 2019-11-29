#include "EmptyHeap.h"

EmptyHeap::EmptyHeap(const string& message):
    runtime_error("Empty Heap Exception: " + message) {}
