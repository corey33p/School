#ifndef COMMANDHANDLER_H
#define COMMANDHANDLER_H

using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include "Player.h"

class CommandHandler
{
    private:
        vector<Player> players;
    public:
        CommandHandler(vector<Player> _players);
        ~CommandHandler();
        void printByRanking();
        void printRBsByTeam();
        void printRankingRange();
        void printTier();
        void editRanking();
        void doCommand(int choice);
        void printPlayer(Player player);
};

#endif
