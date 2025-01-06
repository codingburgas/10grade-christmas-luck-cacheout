#include "BLL/lib/readySets.h"

readySetTitle::readySetTitle(){
    title = "";
    numCards = 0;
}

readySet::readySet() {
    numTitles = 0;
    titles.resize(1); // Ensure at least one title
    titles[0].cards.resize(1); // Ensure at least one card for the first title
    titles[0].cards[0].frontSide = "";
    titles[0].cards[0].backSide = "";
}

readyCard::readyCard() {
    frontSide = "";
    backSide = "";
}

namespace readySetsNS{
readySet readySets;
int numTitles = 0;
int numCards = 0;
bool active = false;
bool knowAnswer = true;
}
