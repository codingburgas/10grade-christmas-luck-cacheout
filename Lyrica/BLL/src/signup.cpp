#include "BLL/lib/signup.h"

bool checkPassword(std::string password)
{
    bool checkSize = false;
    bool checkSpaces = false;
    bool checkUpper = false;
    bool checkSpecial = false;
    bool checkNumber = false;

    if (password.size() >= 6 && password.size() <= 16) checkSize = true;

    if (password.find(' ') != std::string::npos) checkSpaces = true;

    for (unsigned int i = 0; i < password.size(); i++)
    {
        if (password[i] >= 65 && password[i] <= 90) checkUpper = true;
        if (password[i] >= 48 && password[i] <= 57) checkNumber = true;
        if (!(password[i] >= 65 && password[i] <= 90) && !(password[i] >= 48 && password[i] <= 57) && !(password[i] >= 97 && password[i] <= 122)) checkSpecial = true;
    }

    if (checkSize && checkUpper && checkNumber && checkSpecial && !checkSpaces)
        return true;
    else
        return false;
}

bool checkValidity(const std::string& username, const std::string& email, const std::string& password) {
    return checkPassword(password) && checkUsername(username) && checkEmail(email);
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

    return checkSize && checkSpaces;
}

std::string createFileLine(std::string& username, std::string& email, std::string& password)
{
    std::string inputLine;
    inputLine = username + " " + email + " " + password;
    return inputLine;
}
