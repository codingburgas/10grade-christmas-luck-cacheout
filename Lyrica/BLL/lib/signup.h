#ifndef SIGNUP_H
#define SIGNUP_H
#include "BLL/lib/precompileBLL.h"

bool checkPassword(std::string password);

bool checkValidity(const std::string& username, const std::string& lastName, const std::string& password);

bool checkUsername(const std::string& username);

bool checkEmail(const std::string& email);

std::string createFileLine(std::string& username, std::string& loginlastName, std::string& loginPassword);

#endif // SIGNUP_H
