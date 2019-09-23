using namespace std;
#include <iostream>
#include "Player.h"
#include <string>
#include <sstream>


Player::Player() {}

// preconditions: the line from the text file for the player will be received
// postconditions: the line will be stored into a class variable
Player::Player(string textLine):textLine(textLine){
    parseLineFromFile();
}
Player::~Player(){}

// preconditions: the line from the text file for the player will be received
// postconditions: the line will be parsed and player data added accordingly
void Player::parseLineFromFile(){
    string line = Player::textLine;
    // first name
    int end_index = line.find_first_of(" ");
    Player::firstName = line.substr(0,end_index);
    int first_index = line.find_first_of(" ");
    // last name
    first_index = line.find_first_of(" ");
    line = line.substr(first_index,-1);
    first_index = line.find_first_not_of(" ");
    line = line.substr(first_index,-1);
    end_index = line.find_first_of(" ");
    Player::lastName = line.substr(0,end_index);
    // team
    first_index = line.find_first_of(" ");
    line = line.substr(first_index,-1);
    first_index = line.find_first_not_of(" ");
    line = line.substr(first_index,-1);
    end_index = line.find_first_of(" ");
    Player::team = line.substr(0,end_index);
    // bye-week
    first_index = line.find_first_of(" ");
    line = line.substr(first_index,-1);
    first_index = line.find_first_not_of(" ");
    line = line.substr(first_index,-1);
    end_index = line.find_first_of(" ");
    Player::byeWeek = line.substr(0,end_index);
    // expert ranking
    first_index = line.find_first_of(" ");
    line = line.substr(first_index,-1);
    first_index = line.find_first_not_of(" ");
    line = line.substr(first_index,-1);
    end_index = line.find_first_of(" ");
    Player::expertRank = line.substr(0,end_index);
    // personal tier
    first_index = line.find_first_of(" ");
    line = line.substr(first_index,-1);
    first_index = line.find_first_not_of(" ");
    line = line.substr(first_index,-1);
    end_index = line.find_first_of(" ");
    Player::personalTier = line.substr(0,end_index);
    return;
}

// preconditions: the player data will already be obtained as member variables
// postcanditions: the player data will be printed according to specified format
void Player::printPlayer(){
    cout<<Player::expertRank<<": "<<Player::lastName<<", "<<Player::firstName<<" "<<Player::team<<" "<<Player::byeWeek<<" ("<<Player::personalTier<<")\n";
}

// preconditions: firstName will be initialized
// postconditions: firstName will be returned
string Player::getfirstName(){return Player::firstName;}

// preconditions: lastName will be initialized
// postconditions: lastName will be returned
string Player::getlastName(){return Player::lastName;}

// preconditions: team will be initialized
// postconditions: team will be returned
string Player::getTeam(){return Player::team;}

// preconditions: byeWeek will be initialized
// postconditions: byeWeek will be returned
string Player::getbyeWeek(){return Player::byeWeek;}

// preconditions: expertRank will be initialized
// postconditions: expertRank will be returned
string Player::getexpertRank(){return Player::expertRank;}

// preconditions: expertRank will be initialized
// postconditions: expertRank will be returned
int Player::int_getexpertRank(){
    stringstream ss(Player::expertRank);
    int expertRank;
    ss>>expertRank;
    return expertRank;
}

// preconditions: newRank will be initialized, new value will be received
// postconditions: expertRank will be updated
void Player::changeRank(int newRank){
    stringstream ss;
    ss << newRank;
    string str = ss.str();
    Player::expertRank = str;
    // this->expertRank = newRank;
}

// preconditions: personalTier will be initialized
// postconditions: personalTier will be returned
string Player::getpersonalTier(){return Player::personalTier;}
