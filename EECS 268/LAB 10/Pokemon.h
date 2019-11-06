#ifndef POKEMON_H
#define POKEMON_H

using namespace std;

class Pokemon{
    private:
        std::string a_name;
        std::string j_name;
        int pokedexNumber;
    public:
        Executive(std::string fileName);
        virtual ~Executive();
        Pokemon operator>(int& pNum){
            if (pNum < Pokemon::pokedexNumber){ return true; }
            else { return false; }
        }
        Pokemon
            
};

#endif
