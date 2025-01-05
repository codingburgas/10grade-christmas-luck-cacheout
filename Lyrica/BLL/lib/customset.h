#ifndef CUSTOMSET_H
#define CUSTOMSET_H
#include <string>
#include <vector>

class customCard
{
public:
    customCard();
    std::string frontSide;
    std::string backSide;
};



class customSetTitle
{
public:
    customSetTitle();
    int numCards;
    std::string title;
    std::vector<customCard> cards;
};



class customSet
{
public:
    customSet();
    int numTitles;
    std::vector<customSetTitle> titles;
};

namespace customSetsNS{
extern customSet customSets;
}

#endif // CUSTOMSET_H
