using namespace std;
#include <iostream>
#include <time.h>
#include <random>
#include <fstream>
#include "Executive.h"
#include "mergeSort.cpp"
#include "quickSort.cpp"
#include "selectionSort.cpp"
#include "bubbleSort.cpp"
#include "insertionSort.cpp"

Executive::Executive(std::string fileName){
    ifstream file(fileName);
    if (!file.good()) {
        cout<<"Bad filename."<<endl;
        return;
    }
    std::string whichLab;
    file >> whichLab;
    int count;
    file >> count;
    std::string state;
    file >> state;
    std::string method;
    file >> method;
    double time = Executive::sort(count,state,method);
    cout<<"time: "<<time<<endl;
}

void Executive::generate(int n){
    if (listExists){delete [] Executive::theList;}
    Executive::size = n;
    Executive::theList = new double[n];
    //
    double lower_bound = 0;
    double upper_bound = 100000;
    std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
    std::default_random_engine re;
    for (int i = 0;i<n;i++){
        double randy = unif(re);
        Executive::theList[i]=randy;
    }
    Executive::listExists = true;
}

void Executive::printList(){
    // for (int i = 0;i<Executive::size;i++){
    //     cout<<"Executive::theList["<<i<<"]: "<<Executive::theList[i]<<endl;
    // }
    for (int i = 0;i<Executive::size;i++){
        if (i == Executive::size-1){
            cout<<Executive::theList[i]<<endl;
        } else {
            cout<<Executive::theList[i]<<", ";
        }
    }
}

Executive::~Executive(){
    delete [] Executive::theList;
}

// lab9 <data_size> <random|ascending|descending> <selection|insertion|bubble|merge|quick>
double Executive::sort(int count,std::string state,std::string method){
    cout<<"Sorting n = "<<count<<"; "<<state<<"; "<<method<<endl;
    Executive::generate(count);
    if (state=="robot"){ Executive::robotSort();};
    if (state!="random"){
        // quickSort(Executive::theList,0,count-1);
        mergeSort(Executive::theList,count);
        // selectionSort(Executive::theList,count);
        // bubbleSort(Executive::theList,count);
        // insertionSort(Executive::theList,count);
    } 
    if (state=="descending"){
        Executive::reverseList(Executive::theList,0,count-1);
    }
    clock_t start;
    clock_t end;
    if (method=="selection"){
        start = clock();
        selectionSort(Executive::theList,count);
        end = clock();
    } else if (method=="insertion"){
        start = clock();
        insertionSort(Executive::theList,count);
        end = clock();
    } else if (method=="bubble"){
        start = clock();
        bubbleSort(Executive::theList,count);
        end = clock();
    } else if (method=="merge"){
        start = clock();
        mergeSort(Executive::theList,count);
        end = clock();
    } else if (method=="quick"){
        start = clock();
        selectionSort(Executive::theList,count);
        end = clock();
    }
    double time = (end - start) / (double) CLOCKS_PER_SEC;
    return time;
}

void Executive::reverseList(double arr[], int start, int end){
    while (start < end) { 
        double temp = arr[start];  
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    }  
}

void Executive::robotSort(){
    std::string methods[5] = {"selection","insertion","bubble","merge","quick"};
    std::string states[3] = {"random","ascending","descending"};
    int testsPer = 11;
    // int testsPer = 6;
    int ranges[5][2] = {{50000,500000},{50000,500000},{50000,500000},{500000,100000000},{50000,500000}};
    // int ranges[5][2] = {{50000,100000},{50000,100000},{50000,100000},{500000,10000000},{50000,100000}};
    std::string output = "";
    int methodIndex = 0;
    for (auto & method : methods) {
        output.append(method);
        output.append("\n");
        for (auto & state : states) {
            output.append(state);
            output.append("\n");
            int start = ranges[methodIndex][0];
            int end = ranges[methodIndex][1];
            double increment = (end - start) / double (testsPer-1);
            for (int i = 0;i<testsPer;i++) {
                int length = start + i * increment;
                if ((method == "insertion")||(method == "bubble")){
                    if (state == "ascending"){
                        length = length * 100;
                    }
                }
                double time = Executive::sort(length,state,method);
                cout<<"    time: "<<time<<endl;
                output.append(std::to_string(length));
                output.append(", ");
                output.append(std::to_string(time));
                output.append("\n");
            }
        }
        methodIndex++;
        output.append("\n");
    }
    std::ofstream out("output.txt");
    out << output;
    out.close();
    return;
}