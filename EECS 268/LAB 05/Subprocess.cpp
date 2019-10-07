using namespace std;
#include <iostream>
#include <string>
#include "Subprocess.h"

Subprocess::Subprocess(){}
Subprocess::Subprocess(std::string nam,bool canHandleExceptions) : name(nam),canHandleExceptions(canHandleExceptions){}
Subprocess::~Subprocess(){}
string Subprocess::getName(){return Subprocess::name;}
bool Subprocess::getcanHandleExceptions(){return Subprocess::canHandleExceptions;}