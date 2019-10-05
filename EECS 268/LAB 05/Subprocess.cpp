using namespace std;
#include <iostream>
#include <string>
#include "Subprocess.h"

Subprocess::Subprocess(std::string name,bool canHandleExceptions) name(name),canHandleExceptions(canHandleExceptions){}
Subprocess::~Subprocess(){}
string Subprocess::getName(){return Subprocess::name;}
bool Subprocess::getcanHandleExceptions(){return Subprocess::canHandleExceptions;}