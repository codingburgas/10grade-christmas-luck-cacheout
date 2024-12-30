#include "BLL/lib/signin.h"

std::string createSignInFileLine(std::string& username, std::string& email, std::string& password)
{
    std::string inputLine;
    inputLine = username + " " + email + " " + password;
    return inputLine;
}
