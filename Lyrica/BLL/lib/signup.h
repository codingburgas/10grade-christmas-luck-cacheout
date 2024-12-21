#ifndef SIGNUP_H
#define SIGNUP_H
#include "BLL/lib/precompileBLL.h"

bool checkPassword(std::string password);

bool checkValidity(const std::string& firstName, const std::string& lastName, const std::string& password);

bool checkFirstName(const std::string& firstName);

bool checkLastName(const std::string& lastName);

std::string createFileLine(std::string& loginFirstName, std::string& loginlastName, std::string& loginPassword);

#endif // SIGNUP_H
