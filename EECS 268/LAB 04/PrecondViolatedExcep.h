/*
@author - Corey Anderson
@file - PrecondViolatedExcep.h
@date - 10/1/2019
@brief - Custom error object, subclassed from logic_error
*/

#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP
using namespace std;

#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep : public logic_error{
   public:
       PrecondViolatedExcep(const string& message = "");
};
#endif
