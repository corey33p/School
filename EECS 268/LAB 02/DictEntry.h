#ifndef DICTENTRY_H
#define DICTENTRY_H

using namespace std;
#include <iostream>
#include <string>

class DictEntry
{
    private:
        string word;
        string definition;
    public:
        DictEntry();
        DictEntry(string text_line);
        ~DictEntry();
        void print();
};

#endif