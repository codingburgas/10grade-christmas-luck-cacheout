#include "DAL/lib/files.h"

std::string getLine(std::fstream& file)
{
    std::string line;
    if (!file.eof())    // Check that end of file has not been reached
        std::getline(file, line);
    return line;
}

void writeInFile(std::fstream& file, std::string& line)     // Input a single line in file
{
    file << line << std::endl;
}

void writeInFileMult(std::fstream&file, std::string& line1, std::string& line2){    // Input multiple lines in file
    file << line1 << std::endl;
    file << line2 << std::endl;
}

void getFromFileReady(std::fstream& file, std::vector<readySetTitle>& titles, int& numTitles, int& numCards) {
    std::string fileLine1, fileLine2, fileLine3;

    // Read the first line (title)
    std::getline(file, fileLine1);

    // Create a new Title and set its name
    readySetTitle newTitle;
    newTitle.title = fileLine1;

    if(fileLine1.empty()){
        return;
    }

    while (!file.eof()) {    // Runs until end of file has been reached
        std::cout << "Loop in progress" << std::endl;

        // Read card information (frontSide and backSide)
        std::getline(file, fileLine2);
        std::getline(file, fileLine3);

        if (!fileLine2.empty()) {
            // Create a new Card and populate it
            readyCard newCard;
            newCard.frontSide = fileLine2;
            newCard.backSide = fileLine3;

            // Add the card to the current title
            newTitle.cards.push_back(newCard);

            // Increment the card count
            numCards++;
            std::cout << "Front Side: " << fileLine2 << std::endl;
            std::cout << "Back Side: " << fileLine3 << std::endl;
        } else {
            // If line is empty, start a new title
            titles.push_back(newTitle);  // Save the current title
            numTitles++;

            // Reset and read a new title
            newTitle = readySetTitle();  // Create a fresh Title object
            newTitle.title = fileLine3;

            // Reset card count for the new title
            numCards = 0;

            std::cout << "New title started: " << fileLine1 << std::endl;
        }
    }

    // Add the last title to the vector if it has data
    if (!newTitle.cards.empty()) {
        titles.push_back(newTitle);
        numTitles++;
    }
}

void getFromFileCustom(std::fstream& file, std::vector<customSetTitle>& titles, int& numTitles, int& numCards){
    std::string fileLine1, fileLine2, fileLine3;

    // Read the first line (title)
    std::getline(file, fileLine1);

    // Create a new Title and set its name
    customSetTitle newTitle;
    newTitle.title = fileLine1;

    while (!file.eof()) {
        std::cout << "Loop in progress" << std::endl;

        // Read card information (frontSide and backSide)
        std::getline(file, fileLine2);
        std::getline(file, fileLine3);

        if (!fileLine2.empty()) {
            // Create a new Card and populate it
            customCard newCard;
            newCard.frontSide = fileLine2;
            newCard.backSide = fileLine3;

            // Add the card to the current title
            newTitle.cards.push_back(newCard);

            // Increase the card count
            numCards++;
            std::cout << "Front Side: " << fileLine2 << std::endl;
            std::cout << "Back Side: " << fileLine3 << std::endl;
        } else {
            // If line is empty, start a new title
            titles.push_back(newTitle);  // Save the current title
            numTitles++;

            // Reset and read a new title
            newTitle = customSetTitle();  // Create a fresh Title object
            newTitle.title = fileLine3;

            // Reset card count for the new title
            numCards = 0;

            std::cout << "New title started: " << fileLine1 << std::endl;
        }
    }

    // Add the last title to the vector if it has data
    if (!newTitle.cards.empty()) {
        titles.push_back(newTitle);
        numTitles++;
    }
}


bool checkIfInFile(std::fstream& file, std::string& line)
{
    std::string fileLine;
    while (!file.eof())     // Run until end of file has been reached
    {
        std::getline(file, fileLine);
        if (fileLine == line)     // If the line exists in the file return true
        {
            return true;
        }
    }
    return false;
}

bool checkIfInFileLine(std::fstream& file, std::string& username, std::string email)
{
    std::string fileLine;
    while (!file.eof())     // Run until end of file has been reached
    {
        std::getline(file, fileLine);
        if (fileLine.find(username) != std::string::npos && fileLine.find(email) != std::string::npos)      // If both exist in the file return true
        {
            return true;
        }
    }
    return false;
}
