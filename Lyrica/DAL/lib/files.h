#ifndef FILES_H
#define FILES_H

#include <fstream>

std::string getLine(std::fstream& file);

int getFileSize(std::fstream& file);

void writeInFile(std::fstream& file, std::string& line);

bool checkIfInFile(std::fstream& file, std::string& line);

bool checkIfInFileLine(std::fstream& file, std::string& firstName, std::string lastName);

#endif // FILES_H
