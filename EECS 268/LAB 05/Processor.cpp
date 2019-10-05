using namespace std;
#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"
#include "SLNode.h"
#include "Processor.h"
#include "Subprocess.h"

template<class Stack, class Subprocess>
Processor::Subprocess(){}

template<class Stack, class Subprocess>
Processor::~Subprocess(){}

template<class Stack, class Subprocess>
void Processor::startProcess(std::string name,std::vector<std::string> subprocesses,std::vector<bool> canHandleExceptions){
    Stack<Subprocess> newProcess;
    Subprocess subprocess;
    
    // build process stack (of subprocesses)
    subprocessIndex = 0;
    for (auto & name : subprocesses) {
        subprocess = Subprocess(name,canHandleExceptions[subprocessIndex]);
        subprocessIndex++;
        newProcess.push_back(subprocess);
    
    // add process stack to processor queue
    Processor::queue.enqueue(newProcess);
}

template<class Stack, class Subprocess>
void Processor::process(){
    Stack<Subprocess> process = Processor::queue.peekFront();
    Subprocess subprocess = process.peek();
    Processor::currentSubprocessName = subprocess.getName();
    Processor::currentSubprocessCanHandle = subprocess.getcanHandleExceptions();
    process.pop();
    //
    if (process.isEmpty){
        Processor::queue.dequeue();
        Processor::status = "Process "+process.name+" has ended successfully\n";
    } else {
        queue.toBack();
        Processor::status = "Process "+process.name+" is running the function "+subprocess.name+"\n";
    }
}

template<class Stack, class Subprocess>
void Processor::throwException(){
    Stack<Subprocess> process = Processor::queue.peekFront();
    bool canHandle = process.peek().canHandleExceptions;
    while (!canHandle && !process.isEmpty){
        Processor::queue.dequeue();
        process = Processor::queue.peekFront();
        canHandle = process.peek().canHandleExceptions;
    }
    if (process.isEmpty){
        Processor::status = "Process "+process.name+" is ending due to an unhandled exception\n";
        queue.dequeue();
    } else {
        Processor::status = "Process "+process.name+" is running the function "+subprocess.name+"\n";
        queue.toBack();
    }
}

template<class Stack, class Subprocess>
void Processor::printStatus(){cout<<Processor::status<<endl;}





