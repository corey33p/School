using namespace std;
#include <iostream>
#include <string>
#include "DictEntry.h"


DictEntry::DictEntry(){}
DictEntry::DictEntry(string text_line){
    int space_index = text_line.find_first_of(" ");
    DictEntry::word = text_line.substr(0,space_index);
    DictEntry::definition = text_line.substr(space_index,-1);
}
DictEntry::~DictEntry(){}
void DictEntry::print(){
    cout<<DictEntry::definition<<endl;
}
    
