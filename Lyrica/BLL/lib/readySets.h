#ifndef READYSETS_H
#define READYSETS_H
#include <iostream>
#include <vector>

class readyCard
{
public:
    readyCard();
    std::string frontSide;
    std::string backSide;
};



class readySetTitle
{
public:
    readySetTitle();
    int numCards;
    std::string title;
    std::vector<readyCard> cards;
};



class readySet
{
public:
    readySet();
    int numTitles;
    std::vector<readySetTitle> titles;
};

namespace readySetsNS{
extern readySet readySets;
extern int numTitles;
extern int numCards;
extern bool active;
extern bool knowAnswer;
}

#endif // READYSETS_H
