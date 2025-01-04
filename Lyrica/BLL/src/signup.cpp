#include "BLL/lib/signup.h"

bool checkPassword(std::string password)
{
    bool checkSize1 = false;
    bool checkSize2 = false;
    bool checkSpaces = false;
    bool checkUpper = false;
    bool checkSpecial = false;
    bool checkNumber = false;

    if (password.size() >= 6 && password.size() <= 16) checkSize1 = true;

    if(!password.empty()) checkSize2 = true;

    if (password.find(' ') != std::string::npos) checkSpaces = true;

    for (unsigned int i = 0; i < password.size(); i++)
    {
        if (password[i] >= 65 && password[i] <= 90) checkUpper = true;
        if (password[i] >= 48 && password[i] <= 57) checkNumber = true;
        if (!(password[i] >= 65 && password[i] <= 90) && !(password[i] >= 48 && password[i] <= 57) && !(password[i] >= 97 && password[i] <= 122)) checkSpecial = true;
    }

    if (checkSize1 && checkSize2 && checkUpper && checkNumber && checkSpecial && !checkSpaces)
        return true;
    else
        return false;
}

bool checkUsername(const std::string& username) {
    // Check if the username is non-empty and does not contain spaces
    bool checkSize = !username.empty();
    bool checkSpaces = (username.find(' ') == std::string::npos);

    return checkSize && checkSpaces;
}

bool checkEmail(const std::string& email) {
    // Check if the email is non-empty and does not contain spaces
    bool checkSize = !email.empty();
    bool checkSpaces = (email.find(' ') == std::string::npos);

    bool checkAt = false;
    size_t atPosition = email.find('@');
    if (atPosition != std::string::npos && email.find('@', atPosition + 1) == std::string::npos) {
        checkAt = true; // No '@' or more than one '@'
    }

    // Check if there is at least one character before and after the '@'
    bool checkBandA = false;
    if (atPosition != 0 && atPosition != email.size() - 1) {
        checkBandA = true;
    }

    // Check if the string contains a '.' after the '@'
    bool checkDot = false;
    size_t dotPosition = email.find('.', atPosition);
    if (dotPosition != std::string::npos && dotPosition != email.size() - 1) {
        checkDot = true; // No '.' or '.' at the end
    }

    return checkSize && checkSpaces && checkAt && checkBandA && checkDot;
}

bool checkValidity(const std::string& username, const std::string& email, const std::string& password) {
    bool check = false;
    if(checkPassword(password) && checkUsername(username) && checkEmail(email)) check = true;
    return check;
}

std::string createFileLine(std::string& username, std::string& email, std::string& password)
{
    std::string inputLine;
    inputLine = username + " " + email + " " + password;
    return inputLine;
}
