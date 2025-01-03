#include "DAL/lib/files.h"

std::string getLine(std::fstream& file)
{
    std::string line;
    if (!file.eof())
        std::getline(file, line);
    return line;
}

int getFileSize(std::fstream& file)
{
    int fileSize = 0;
    while (!file.eof())
    {
        fileSize++;
    }
    return fileSize;
}

void writeInFile(std::fstream& file, std::string& line)
{
    file << std::endl;
    file << line << std::endl;
}

void writeInFileMult(std::fstream&file, std::string& line1, std::string& line2){
    file << line1 << std::endl;
    file << line2 << std::endl;
}

bool checkIfInFile(std::fstream& file, std::string& line)
{
    std::string fileLine;
    while (!file.eof())
    {
        std::getline(file, fileLine);
        if (fileLine == line)
        {
            return true;
        }
    }
    return false;
}

bool checkIfInFileLine(std::fstream& file, std::string& username, std::string email)
{
    std::string fileLine;
    while (!file.eof())
    {
        std::getline(file, fileLine);
        if (fileLine.find(username) != std::string::npos && fileLine.find(email) != std::string::npos)
        {
            return true;
        }
    }
    return false;
}
