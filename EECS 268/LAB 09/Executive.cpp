using namespace std;
#include <iostream>
#include <random>
#include "Executive.h"

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
    Executive::generate(count);
    Executive::printList();
}

void Executive::generate(int n){
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
