#ifndef EXECUTIVE_H
#define EXECUTIVE_H

using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Map.h"

class Executive
{
    public:
        Executive();
        virtual ~Executive();
        void run(int argc, char** argv);
        bool readFile(string fileName,vector<string> &lines);
        
        template <typename Domain, typename Range>
        void parseDict(vector<string> data, Map<Domain, Range> &map);
        
        template <typename Domain1, typename Range1>
        void parseEmployees(vector<string> data, Map<Domain1, Range1> &map);
        
        template <typename Domain4, typename Range4>
        void parseManagers(vector<string> data, Map<Domain4, Range4> &map);
        
        template <typename Domain2, typename Range2, typename Domain3, typename Range3, typename Domain5, typename Range5>
        void runMenu(Map<Domain2, Range2> dictMap, Map<Domain3, Range3> employeeMap, Map<Domain5, Range5>);
};

#endif