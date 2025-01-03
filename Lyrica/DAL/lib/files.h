#ifndef FILES_H
#define FILES_H

#include <fstream>

std::string getLine(std::fstream& file);

int getFileSize(std::fstream& file);

void writeInFile(std::fstream& file, std::string& line);

void writeInFileMult(std::fstream& file, std::string& line1, std::string& line2);

bool checkIfInFile(std::fstream& file, std::string& line);

bool checkIfInFileLine(std::fstream& file, std::string& username, std::string email);

#endif // FILES_H
