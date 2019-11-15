#ifndef POKEMON_H
#define POKEMON_H

#include <string>

using namespace std;

class Pokemon{
    private:
        std::string a_name;
        std::string j_name;
        int pokedexNumber;
    public:
        Pokemon();
        Pokemon(const Pokemon&);
        Pokemon(std::string a_name,std::string j_name,int pokedexNumber);
        ~Pokemon();
        void print();
        int getPNum() const;
        std::string getAName() const;
        std::string getJName() const;
        //
        bool operator>(const int& pNum){
            if (pNum < Pokemon::pokedexNumber){ return true; }
            else { return false; }
        }
        bool operator<(const int& pNum){
            if (pNum > Pokemon::pokedexNumber){ return true; }
            else { return false; }
        }
        bool operator=(const int& pNum){
            if (pNum == Pokemon::pokedexNumber){ return true; }
            else { return false; }
        }
};

#endif
