#ifndef CUSTOMSET_H
#define CUSTOMSET_H
#include<string>
#include <vector>

class card
{
public:
    card();
    std::string frontSide;
    std::string backSide;
};



class customSetTitle
{
public:
    customSetTitle();
    int numCards;
    std::string title;
    std::vector<card> cards;
};



class customSet
{
public:
    customSet();
    int numTitles;
    std::vector<customSetTitle> titles;
};

#endif // CUSTOMSET_H
