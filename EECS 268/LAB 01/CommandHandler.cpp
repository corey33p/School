using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include "CommandHandler.h"
#include "Player.h"
#include <climits> // INT_MAX


CommandHandler::CommandHandler(vector<Player> _players): players(_players){}
CommandHandler::~CommandHandler(){}

// preconditions: CommandHandler::players created
// will print the players in order based on their expert ranking
//postconditions: players will be printed
void CommandHandler::printByRanking(){
    int minRank = 32767;
    int maxRank = 0;
    for (auto & player : CommandHandler::players) {
        stringstream ss(player.getexpertRank());
        int expertRank;
        ss>>expertRank;
        if (expertRank < minRank){
            minRank = expertRank;
        }
        if (expertRank > maxRank) {
            maxRank = expertRank;
        }
    }
    for (int i=minRank; i<= maxRank; i++){
        for (auto & player : CommandHandler::players) {
            stringstream ss(player.getexpertRank());
            int expertRank;
            ss>>expertRank;
            if (expertRank == i){
                player.printPlayer();
            }
        }
    }
}

// preconditions: CommandHandler::players created
// receives a user specified team and prints Players of that team
// postconditions: RB's will be printed from a certain team
void CommandHandler::printRBsByTeam(){
    cout<<"What team would you like to view? ";
    string choice;
    cin>>choice;
    cin.clear();
    while (cin.get() != '\n') {
        continue;
    }
    bool printed_any = false;
    for (auto & player : CommandHandler::players) {
        if (player.getTeam() == choice){
            player.printPlayer();
            printed_any = true;
        }
    }
    if (!printed_any){
        cout<<"Found no players on this team. "<<endl;
    }
}

// preconditions: CommandHandler::players created
// receives a user specified tier and prints Players within that printTier
// postconditions: RB's will be printed from within user specified tier
void CommandHandler::printTier(){
    cout<<"What tier would you like to view? ";
    int choice;
    cin>>choice;
    while (!cin.good()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<<"Invalid entry. What tier would you like to view? ";
        cin>>choice;
    }
    cin.clear();
    while (cin.get() != '\n') {
    continue;
    }
    bool printed_any = false;
    for (auto & player : CommandHandler::players) {
        stringstream ss(player.getpersonalTier());
        int personalTier;
        ss>>personalTier;
        if (personalTier == choice){
            player.printPlayer();
            printed_any = true;
        }
    }
    if (!printed_any){
        cout<<"Found no players in this tier. "<<endl;
    }
}

// preconditions: CommandHandler::players created
// will receive first and last name of the player whose rank will be changed, desired rank,
// and finally change the rank and adjust other players's ranks accordingly
// postconditions: ranks will be updated as specified, and the new RB list will be printed
void CommandHandler::editRanking(){
    // first name
    cout<<"Please enter the first name of the player whose rank you wish to change. ";
    string firstName;
    cin>>firstName;
    cin.clear();
    while (cin.get() != '\n') {
    continue;
    }
    // last name
    cout<<"Please enter the last name of the player whose rank you wish to change. ";
    string lastName;
    cin>>lastName;
    cin.clear();
    while (cin.get() != '\n') {
    continue;
    }
    // check if the player name is valid
    bool playerFound = false;
    for (auto & player : CommandHandler::players) {
        if ((player.getfirstName() == firstName) && (player.getlastName() == lastName)){
            playerFound = true;
        }
    }
    if (!playerFound) {
        cout<<"Player not found in records.\n";
        return;
    }
    // get new rank
    cout<<"Please enter new rank for the player. ";
    int newRank;
    cin>>newRank;
    while (!cin.good()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<<"Invalid entry. Please enter new rank for the player. ";
        cin>>newRank;
    }
    cin.clear();
    while (cin.get() != '\n') {
    continue;
    }
    // get current rank
    int playerRank;
    int maxRank = 0;
    for (auto & player : CommandHandler::players) {
        if ((player.getfirstName() == firstName) && (player.getlastName() == lastName)){
            playerRank = player.int_getexpertRank();
            player.changeRank(-1); // temporarily remove the player from the valid ranks
        }
        if (player.int_getexpertRank()>maxRank){
            maxRank = player.int_getexpertRank();
        }
    }
    // check if the new desired rank is valid
    if ((newRank < 1) || (newRank >maxRank)){
        cout<<"This would not be a valid rank.\n";
    }
    // adjust the ranks
    if (playerRank > newRank){ // moving up in the ranks
        for (int i=playerRank; i>= newRank; i--){
            for (auto & player : CommandHandler::players) {
                if (player.int_getexpertRank() == i) {
                    player.changeRank(i+1);
                }
            }
        }
    } else if (newRank > playerRank){ // moving down in the ranks
        for (int i=playerRank; i<= newRank; i++){
            for (auto & player : CommandHandler::players) {
                if (player.int_getexpertRank() == i) {
                    player.changeRank(i-1);
                }
            }
        }
    }
    for (auto & player : CommandHandler::players) { // give the player the new rank
        if (player.int_getexpertRank() == -1){
            player.changeRank(newRank);
        }
    }
    CommandHandler::printByRanking();
}

// preconditions: CommandHandler::players created
// will obtain a range of ranks from the user, verify validity of the range, and print RB's within that range
// RB's within the specified range will be printed
void CommandHandler::printRankingRange(){
    cout<<"View RB's by range of ranks\n";
    int rangeMin;
    cout<<"What is the minimum rank in the range? ";
    cin>>rangeMin;
    while (!cin.good()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<<"Invalid entry. What is the minimum rank in the range? ";
        cin>>rangeMin;
    }
    cin.clear();
    while (cin.get() != '\n') {
    continue;
    }
    int rangeMax;
    cout<<"What is the maximum rank in the range? ";
    cin>>rangeMax;
    while (!cin.good()){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<<"Invalid entry. What is the minimum rank in the range? ";
        cin>>rangeMax;
    }
    cin.clear();
    while (cin.get() != '\n') {
    continue;
    }
    if (rangeMin > rangeMax){
        cout<<"Invalid range! Exiting to menu.\n";
    }else{
        bool printed_any = false;
        for (int i=rangeMin; i<= rangeMax; i++){
            for (auto & player : CommandHandler::players) {
                stringstream ss(player.getexpertRank());
                int rank;
                ss>>rank;
                if ((rank <= rangeMax) && (rank >= rangeMin) && (rank == i)) {
                    player.printPlayer();
                    printed_any = true;
                }
            }
        }
        if (!printed_any){
            cout<<"Found no players in this rank range. "<<endl;
        }
    }
}

// preconditions: CommandHandler::players created, user command choice received
// postconditions: specified command will be executed
void CommandHandler::doCommand(int choice){
    if (choice == 1){
        printByRanking();
    } else if (choice == 2){
        printRBsByTeam();
    } else if (choice == 3){
        printRankingRange();
    } else if (choice == 4){
        printTier();
    } else if (choice == 5){
        editRanking();
    } else{
        return;
    }
}

// preconditions: CommandHandler::players created, specific player passed into method
// postconditions: the player will be printed
void CommandHandler::printPlayer(Player player){
    player.printPlayer();
    system("pause");
    return;
}
