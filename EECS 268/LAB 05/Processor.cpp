using namespace std;
#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
#include "SLNode.h"
#include "Processor.h"
#include "Subprocess.h"

// template <template<class Subprocess> class Stack>
Processor::Processor(){}

// template <template<class Subprocess> class Stack>
Processor::~Processor(){}

// template <template<class Subprocess> class Stack>
void Processor::startProcess(std::string name,std::vector<std::string> subprocesses,std::vector<bool> canHandleExceptions){
    Stack<Subprocess> newProcess(name);
    Subprocess subprocess;
    
    // build process stack (of subprocesses)
    int subprocessIndex = 0;
    for (auto & name : subprocesses) {
        subprocess = Subprocess(name,canHandleExceptions[subprocessIndex]);
        subprocessIndex++;
        newProcess.push(subprocess);
    }
    
    // add process stack to processor queue
    Processor::queue.enqueue(newProcess);
}

// template <template<class Subprocess> class Stack>
void Processor::process(){
    Stack<Subprocess> process = Processor::queue.peekFront();
    Subprocess subprocess = process.peek();
    process.pop();
    //
    if (process.isEmpty()){
        Processor::queue.dequeue();
        Processor::status = "Process "+process.getName()+" has ended successfully\n";
    } else {
        queue.toBack();
        Processor::status = "Process "+process.getName()+" is running the function "+subprocess.getName()+"\n";
    }
}

// template <template<class Subprocess> class Stack>
void Processor::throwException(){
    Stack<Subprocess> process = Processor::queue.peekFront();
    bool canHandle = process.peek().getcanHandleExceptions();
    while (!canHandle && !process.isEmpty()){
        Processor::queue.dequeue();
        process = Processor::queue.peekFront();
        canHandle = process.peek().getcanHandleExceptions();
    }
    Subprocess subprocess = process.peek();
    if (process.isEmpty()){
        Processor::status = "Process "+process.getName()+" is ending due to an unhandled exception\n";
        queue.dequeue();
    } else {
        Processor::status = "Process "+process.getName()+" is running the function "+subprocess.getName()+"\n";
        queue.toBack();
    }
}

// template <template<class Subprocess> class Stack>
void Processor::printStatus(){cout<<Processor::status<<endl;}

// template class Stack<Subprocess>;
template class Queue<Stack<Subprocess>>;
// template class Queue<template class Stack<Subprocess>>;


