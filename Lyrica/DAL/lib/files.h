#ifndef FILES_H
#define FILES_H

#include <fstream>
#include <iostream>
#include <vector>
#include "BLL/lib/readySets.h"
#include "BLL/lib/customset.h"

std::string getLine(std::fstream& file);

int getFileSize(std::fstream& file);

void writeInFile(std::fstream& file, std::string& line);

void writeInFileMult(std::fstream& file, std::string& line1, std::string& line2);

void getFromFileReady(std::fstream& file, std::vector<readySetTitle>& titles, int& numTitles, int& numCards);

void getFromFileCustom(std::fstream& file, std::vector<customSetTitle>& titles, int& numTitles, int& numCards);

bool checkIfInFile(std::fstream& file, std::string& line);

bool checkIfInFileLine(std::fstream& file, std::string& username, std::string email);

#endif // FILES_H
