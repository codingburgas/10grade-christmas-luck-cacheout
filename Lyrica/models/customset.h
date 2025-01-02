#ifndef CUSTOMSET_H
#define CUSTOMSET_H
#include<string>
#include <vector>

#include "card.h"
class customSet
{
public:
    customSet();

    int numCards;
    std::string title;
    std::vector<card> cards;
};
#endif // CUSTOMSET_H
