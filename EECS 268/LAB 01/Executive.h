#ifndef EXECUTIVE_H
#define EXECUTIVE_H

using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include "CommandHandler.h"
#include "Player.h"

class Executive
{
    public:
        Executive();
        ~Executive();
        void run();
        bool readFile(string fileName,vector<Player> &players);
        bool goodChoice(int choice,int valid_choices[]);
        void getMenu(CommandHandler C);
};

#endif
