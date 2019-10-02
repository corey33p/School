/*
@author - Corey Anderson
@file - PrecondViolatedExcep.h
@date - 10/1/2019
@brief - Custom error object, subclassed from logic_error
*/

#include "PrecondViolatedExcep.h"

PrecondViolatedExcep::PrecondViolatedExcep(const string& message):
    logic_error("Precondition Violated Exception: " + message) {}
