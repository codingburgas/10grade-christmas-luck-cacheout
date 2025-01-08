#include "BLL/lib/signup.h"

bool checkPassword(std::string password)
{
    bool checkSize = false;
    bool checkEmpty = false;
    bool checkSpaces = false;
    bool checkUpper = false;
    bool checkSpecial = false;
    bool checkNumber = false;

    if (password.size() >= 6 && password.size() <= 16) checkSize = true;   // Check that password is the correct size

    if(!password.empty()) checkEmpty = true;    //

    if (password.find(' ') != std::string::npos) checkSpaces = true;

    for (unsigned int i = 0; i < password.size(); i++)      // Run until the end of password has been reached
    {
        if (password[i] >= 65 && password[i] <= 90) checkUpper = true;      // Check if there is an upper case letter
        if (password[i] >= 48 && password[i] <= 57) checkNumber = true;      // Check if there is a number
        if (!(password[i] >= 65 && password[i] <= 90) && !(password[i] >= 48 && password[i] <= 57) && !(password[i] >= 97 && password[i] <= 122)) checkSpecial = true;      // Check if there is a special character
    }

    if (checkSize && checkEmpty && checkUpper && checkNumber && checkSpecial && !checkSpaces)   // If password is inside the parameters return true
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
    // Check if all credentials are valid
    bool check = false;
    if(checkPassword(password) && checkUsername(username) && checkEmail(email)) check = true;
    return check;
}

std::string createFileLine(std::string& username, std::string& email, std::string& password)
{
    // Input all credentials in the file
    std::string inputLine;
    inputLine = username + " " + email + " " + password;
    return inputLine;
}
