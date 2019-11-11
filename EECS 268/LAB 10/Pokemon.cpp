#include "Pokemon.h"
#include <iostream>

Pokemon::Pokemon(){}

Pokemon::Pokemon(const Pokemon &p2){
    a_name = p2.a_name;
    j_name = p2.j_name;
    pokedexNumber = p2.pokedexNumber;
}

Pokemon::Pokemon(std::string _a_name,std::string _j_name,int _pokedexNumber){
    Pokemon::a_name = _a_name;
    Pokemon::j_name = _j_name;
    Pokemon::pokedexNumber = _pokedexNumber;
}

Pokemon::~Pokemon(){}

void Pokemon::print(){
    cout<<pokedexNumber<<": "<<a_name<<", "<<j_name<<endl;
}

int Pokemon::getPNum(){
    return pokedexNumber;
}