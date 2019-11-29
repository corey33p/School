#include "EmptyPriorityQueue.h"

EmptyPriorityQueue::EmptyPriorityQueue(const string& message):
    runtime_error("Empty Priority Queue Exception: " + message) {}
