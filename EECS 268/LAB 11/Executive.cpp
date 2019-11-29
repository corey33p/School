/*
@author - Corey Anderson
@file - Executive.h
@date - 11/29/2019
@brief - Executive object will process an input file with commands
which will be handled by a priority queue which will use a max heap backend.
*/

#include <string>
#include <sstream>
#include <time.h>
#include <iostream>
#include "Executive.h"
#include "Heap.h"
#include "Request.h"
#include "EmptyPriorityQueue.h"

using namespace std;

template<class Request>
Executive<Request>::Executive(std::string fileName){
    ifstream file(fileName);
    if (!file.good()) {
        cout<<"Bad filename."<<endl;
        return;
    }
    std::string line;
    std::getline(file, line);
    stringstream ss(line);
    int initialSize;
    ss >> initialSize;
    PriorityQueue<Request>* queue = new PriorityQueue<Request>(initialSize);
    while (std::getline(file, line)) {
        std::getline(file,line);
        std::string firstWord = popWord(line);
        if (firstWord == "request"){
            std::string firstName = popWord(line);
            std::string lastName  = popWord(line);
            std::string priorityNum = popWord(line);
            stringstream ss(priorityNum);
            int pNum;
            ss >> pNum;
            Request request = Request(firstName,lastName,pNum);
            queue->enqueue(request);
        } else if (firstWord == "fix") {
            bool isException = false;
            Request request;
            try { request = queue->peekFront(); }
            catch (EmptyPriorityQueue &except){
                cout<< except.what() << '\n';
                isException = true;
            }
            if (!isException){
                std::string firstName = request.getfirstName();
                std::string lastName = request.getlastName();
                cout<<"Fixing "<<firstName<<" "<<lastName<<"'s power station."<<endl;
                queue->dequeue();
            }
        } else if (firstWord == "status") {
            if (!queue->isEmpty()){
                cout<<"========== Assuming no new requests, the current set of service requests will be processed as follows ==========="<<endl;
                showStatus(*queue);
                cout<<"========= End of Status =============="<<endl;
            } else {
                cout<<"========== There are no items in the queue =========="<<endl;
            }
        }
    }
    cout<<"========= End of file encountered. Processing remaining requests. =============="<<endl;
    bool processingRequests = true;
    while (processingRequests) {
        Request request;
        try { request = queue->peekFront(); }
        catch (EmptyPriorityQueue &except){
            processingRequests = false;
        }
        if (processingRequests){
            std::string firstName = request.getfirstName();
            std::string lastName = request.getlastName();
            cout<<"Fixing "<<firstName<<" "<<lastName<<"'s power station."<<endl;
            queue->dequeue();
        }
    }
    delete queue;
}

template<class Request>
std::string Executive<Request>::popWord(std::string& line){
    int tab_index = line.find_first_of(" ");
    std::string theWord = line.substr(0,tab_index);
    line = line.substr(tab_index+1,-1);
    return theWord;
}

template<class Request>
void Executive<Request>::showStatus(PriorityQueue<Request> pq){
    while (!pq.isEmpty()){
        Request request = pq.peekFront();
        request.print();
        pq.dequeue();
    }
}

template<class Request>
Executive<Request>::~Executive(){}

template class Executive<Request>;
template class Heap<Request>;
