#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

template <typename Domain, typename Range>
class Map
{
    public:
        Map(){}
        Map(int n){
            Map::numEntries = n;
        }
        virtual ~Map(){}
        void add(Domain d, Range r){
            Map::dArray.push_back(d);
            Map::rArray.push_back(r);
        }
        bool lookup(Domain d){
            bool foundSomething = false;
            int i = 0;
            for (auto & line : Map::dArray){
                if (line == d){
                    cout<<d<<": ";
                    Map::rArray[i].print();
                    foundSomething = true;
                }
                i++;
            }
            return foundSomething;
        }
        // Range setRange(Domain d,){
            // for (auto & line : Map::dArray){
                // if (line == d){
                    // Map::rArray =
                // }
                // i++;
            // }
        // }
        void printMap(){
            int i = 0;
            for (auto & line : Map::dArray){
                cout<<line<<": "<<Map::dArray[i]<<endl;
                i++;
            }
        }
    private:
        int numEntries;
        vector<Domain> dArray;
        vector<Range> rArray;
        // Domain* dArray;
        // Range* rArray;
};

#endif
