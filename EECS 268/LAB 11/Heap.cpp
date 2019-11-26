#include <math.h>
#include "Heap.h"
#include "Request.h"
#include <string>
#include <iostream>

template <class Request>
Heap<Request>::Heap(int initialSize){
    int height = 1+(log(initialSize)/log(2));
    sizeOfArray = pow(2,height)-1;
    theHeap = new Request*[sizeOfArray];
}

template <class Request>
Heap<Request>::Heap(const Heap<Request>& oldHeap){
    sizeOfArray = oldHeap.sizeOfArray;
    theHeap = new Request*[sizeOfArray];
    for (int i = 0;i<sizeOfArray;i++){
        std::string fName = oldHeap.theHeap[i]->getfirstName();
        std::string lName = oldHeap.theHeap[i]->getlastName();
        int pNum = oldHeap.theHeap[i]->getpriorityNumber();
        theHeap[i]=new Request(fName,lName,pNum);
    }
}

template <class Request>
void Heap<Request>::doubleTheSize(){
    int oldHeight = 1+(log(sizeOfArray)/log(2));
    int oldSizeOfArray =sizeOfArray;
    sizeOfArray = pow(2,oldHeight+1)-1;
    Request** tmpPtr = theHeap;
    theHeap = new Request*[sizeOfArray];
    for (int i = 0;i<oldSizeOfArray;i++){
        if (tmpPtr[i]!=nullptr){
            theHeap[i]=tmpPtr[i];
            tmpPtr[i]=nullptr;
        }
    }
    delete[] tmpPtr;
}

template <class Request>
Heap<Request>::~Heap(){
    for (int i = 0;i<sizeOfArray;i++){
        if (theHeap[i]){
            delete theHeap[i];
            theHeap[i] = nullptr;
        }
    }
    delete[] theHeap;
    theHeap = nullptr;
}

template <class Request>
void Heap<Request>::add(Request* newItem){
    if (numItemsInHeap < sizeOfArray){
        theHeap[numItemsInHeap] = newItem;
        numItemsInHeap++;
        bool percolationComplete = false;
        int curIndex = numItemsInHeap-1;
        int loopindex = 0;
        while (!percolationComplete){
            if (curIndex == 0) { percolationComplete = true; }
            else {
                int parentIndex = (curIndex - 1) / 2;
                if (theHeap[curIndex]->getpriorityNumber() < theHeap[parentIndex]->getpriorityNumber()) {
                    percolationComplete = true;
                } else {
                    Request* tempPtr = theHeap[curIndex];
                    theHeap[curIndex] = theHeap[parentIndex];
                    theHeap[parentIndex] = tempPtr;
                    tempPtr = nullptr;
                    curIndex = parentIndex;
                }
            }
            loopindex++;
            int height = 1+(log(numItemsInHeap)/log(2));
            if (loopindex > height){ return; }
        }
    } else {
        doubleTheSize();
        add(newItem);
    }
}

template <class Request>
bool Heap<Request>::isEmpty() const{ return numItemsInHeap == 0;}

template <class Request>
void Heap<Request>::remove() /* throw EmptyHeap */{}

template <class Request>
Request Heap<Request>::peekTop() const /* throw EmptyHeap */{
    if (numItemsInHeap == 0){ //throw EmptyHeap
    } else {
        Request item = Request(theHeap[0]->getfirstName(),theHeap[0]->getlastName(),theHeap[0]->getpriorityNumber());
        return item;
    }
}

template <class Request>
void Heap<Request>::print(){
    int height = 1+(log(numItemsInHeap)/log(2));
    int maxVal = theHeap[0]->getpriorityNumber();
    std::string max = std::to_string(maxVal);
    int spacing = max.length()+1;
    if (spacing % 2 == 1){ spacing++; }
    spacing = 4;
    std::string the_str = "";
    int space_locations_len = spacing*pow(2,height-2)-2;
    int space_locations[space_locations_len];

    for (int i=0; i<space_locations_len; i++) {
        space_locations[i]=0;
    }
    int i = 0;
    for (int j=pow(2,height-1)-1; j<pow(2,height)-1; j++) {
        space_locations[j]=i*spacing;
        i++;
    }

    for (int row=height-1; row>-1; row--){
        cout<<endl;
        std::string row_str = "";
        int line_location = 0;
        int len_of_full_bottom_row = pow(2,(height-1));
        for (int entry = pow(2,row)-1;entry<pow(2,row+1)-1;entry++){
            if (entry < numItemsInHeap) {
                int value = theHeap[entry]->getpriorityNumber();
                int len_entry = std::to_string(value).length();
                if (row == (height-1)){
                    for (int i = 0; i < (spacing - len_entry);i++){
                        row_str = row_str + " ";
                        line_location++;
                    }
                    row_str = row_str + std::to_string(value);
                    line_location=line_location + len_entry;
                } else {
                    int child_1_pos = space_locations[entry*2+1];
                    int child_2_pos = space_locations[entry*2+2];
                    int new_pos = (child_1_pos + child_2_pos) / 2;
                    space_locations[entry] = new_pos;
                    int line_location_static = line_location;
                    for (int i = 0;i<(new_pos - line_location_static);i++){
                        row_str = row_str + " ";
                        line_location++;
                    }
                    for (int i = 0; i < (spacing - len_entry);i++){
                        row_str = row_str + " ";
                        line_location++;
                    }
                    row_str = row_str + std::to_string(value);
                    line_location+=len_entry;
                }
            }
        }
        row_str = row_str + "\n";
        the_str = row_str + the_str;
    }
    cout<<the_str;
}

template class Heap<Request>;
