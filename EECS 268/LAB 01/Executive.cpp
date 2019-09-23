using namespace std;
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <array>
#include <sstream>
#include "Executive.h"
#include "CommandHandler.h"
#include "Player.h"


Executive::Executive(){}
Executive::~Executive(){}

// preconditions: none
// postconditions: will get the name of the file, read the file, and create CommandHandler and Player objects
void Executive::run() {
    string fname;
    vector<string> lines;
    vector<Player> players;
    cout<<"Please enter the name of the file: ";
    cin>>fname;
    bool got_file = false;
    while (!got_file){
        got_file = readFile(fname,players);
        if (!got_file){
            cout<<"Please enter the name of the file: ";
            cin>>fname;
        }
    }
    CommandHandler C(players);
    getMenu(C);
}

// preconditions: filename received, vector of Player objects created
// postconditions: file will be read and vector of Player objects will be populated
bool Executive::readFile(string fileName,vector<Player> &players){
    std::ifstream in(fileName.c_str());
    if(!in) {
        std::cerr << "Cannot open the File : "<<fileName<<std::endl;
        return false;
    }
    string line;
    while (std::getline(in, line)) {
        int spaces_in_data = line.find(" ");
        if (spaces_in_data!=std::string::npos){
            players.push_back(line);
        }
        // if(line.size() > 0){
            // players.push_back(line);
        // }
    }
    in.close();
    return true;
}

// preconditions: will receive a list of choices and a specific choices
// postconditions: will determine if the choice is good based on the received list of good choices
bool Executive::goodChoice(int choice,int valid_choices[]){
    int i = 1;
    while (i <= 6){
        if (i == choice){
            return true;
        }
        i++;
    }
    return false;
}

// preconditions: CommandHandler and Player objects will be created and ready to use
// function will repeat until the program terminates
// postconditions: none
void Executive::getMenu(CommandHandler C){
    int choice = 0;
    int valid_choices[] = {1,2,3,4,5,6};
    string choice_input;
    while (choice != 6) {
        cout<<"-----------------------------------------\n";
        cout<<"Option 1: Print all RBs sorted by ranking\n";
        cout<<"Option 2: Print all RBs for a given team\n";
        cout<<"Option 3: Print a ranking range\n";
        cout<<"Option 4: Print a tier\n";
        cout<<"Option 5: Edit a ranking\n";
        cout<<"Option 6: Exit\n";
        cout<<"-----> ";
        cin>>choice_input;
        stringstream ss(choice_input);
        ss>>choice;
        cin.clear();
        while (cin.get() != '\n') {
            continue;
        }
        if (!goodChoice(choice,valid_choices)){
            std::cerr<<"Not a valid choice; please choose a number 1 through 6.\n";
        } else {
            C.doCommand(choice);
        }
    }
}
