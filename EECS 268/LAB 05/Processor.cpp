using namespace std;
#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
#include "SLNode.h"
#include "Processor.h"
#include "Subprocess.h"

// template <template<class Subprocess> class Stack>
Processor::Processor(){Processor::status = "-";}

// template <template<class Subprocess> class Stack>
Processor::~Processor(){}

// template <template<class Subprocess> class Stack>
void Processor::startProcess(std::string name,std::vector<std::string> subprocesses,std::vector<bool> canHandleExceptions){
    Stack<Subprocess>* newProcess;
    newProcess = new Stack<Subprocess>(name);
    Subprocess* subprocess;
    
    // build process stack (of subprocesses)
    int subprocessIndex = 0;
    for (auto & subName : subprocesses) {
        subprocess = new Subprocess(subName,canHandleExceptions[subprocessIndex]);
        subprocessIndex++;
        newProcess->push(*subprocess);
    }
    if (Processor::status == "-"){
        Processor::status = "Process "+name+" is running the function "+subprocess->getName();
    }
    
    // add process stack to processor queue
    Processor::queue.enqueue(*newProcess);
    newProcess = nullptr;
    subprocess = nullptr;
}

// template <template<class Subprocess> class Stack>
void Processor::process(){
    Stack<Subprocess>* process;
    process = new Stack<Subprocess>(Processor::queue.peekFront());
    Subprocess* subprocess;
    subprocess = new Subprocess(process->peek());
    process->pop();
    //
    if (process->isEmpty()){
        Processor::queue.dequeue();
        Processor::status = "Process "+process->getName()+" has ended successfully\n";
    } else {
        queue.toBack();
        Processor::status = "Process "+process->getName()+" is running the function "+subprocess->getName();
    }
    delete process;
    process = nullptr;
    delete subprocess;
    subprocess = nullptr;
}

// template <template<class Subprocess> class Stack>
void Processor::throwException(){
    Stack<Subprocess>* process = nullptr;
    process = new Stack<Subprocess>(Processor::queue.peekFront());
    // cout<<"uaeoueooaueaoeuaoeuaoeuprocess->isEmpty(): "<<process->isEmpty()<<endl;
    Subprocess* subprocess = nullptr;
    subprocess = new Subprocess(process->peek());
    // cout<<"aoesnuthoansethutuaotnuehoasueBBBBBBBBBBBBBBB"<<endl;
    bool canHandle = subprocess->getcanHandleExceptions();
    while ((!canHandle) && (!process->isEmpty())){
        // cout<<"\ncanHandle: "<<canHandle<<endl;
        // cout<<"process->isEmpty(): "<<process->isEmpty()<<endl;
        // Processor::queue.peekFront().pop();
        // delete process;
        // process = new Stack<Subprocess>(Processor::queue.peekFront());
        // cout<<"process->getName(): "<<process->getName()<<endl;
        // cout<<"process->getstackSize(): "<<process->getstackSize()<<endl;
        process->pop();
        delete subprocess;
        // cout<<"process->getstackSize(): "<<process->getstackSize()<<endl;
        subprocess =  new Subprocess(process->peek());
        if (process->isEmpty()){
            canHandle = subprocess->getcanHandleExceptions();
        }
    }
    if (Processor::queue.isEmpty()){
        Processor::status = "No processes are running";
    } else {
        Subprocess subprocess = process->peek();
        if (process->isEmpty()){
            Processor::status = "Process "+process->getName()+" is ending due to an unhandled exception\n";
            queue.dequeue();
        } else {
            Processor::status = "Process "+process->getName()+" is running the function "+subprocess.getName();
            queue.toBack();
        }
    }
    delete process;
    delete subprocess;
    process = nullptr;
    subprocess = nullptr;
}

// template <template<class Subprocess> class Stack>
void Processor::printStatus(){cout<<Processor::status<<endl;}

// template class Stack<Subprocess>;
template class Queue<Stack<Subprocess>>;
// template class Queue<template class Stack<Subprocess>>;
