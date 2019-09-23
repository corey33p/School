#ifndef PLAYER_H
#define PLAYER_H

using namespace std;
#include <iostream>
#include <string>

class Player
{
    private:
        string textLine;
        string firstName;
        string lastName;
        string team;
        string byeWeek;
        string expertRank;
        string personalTier;
    public:
        Player();
        Player(string text_line);
        ~Player();
        void parseLineFromFile();
        void printPlayer();
        string getfirstName();
        string getlastName();
        string getTeam();
        string getbyeWeek();
        string getexpertRank();
        int int_getexpertRank();
        void changeRank(int newRank);
        string getpersonalTier();
};

#endif
