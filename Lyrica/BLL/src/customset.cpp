#include "BLL/lib/customset.h"

customSetTitle::customSetTitle(){
    title = "";
    numCards = 0;
}

customSet::customSet() {
    numTitles = 0;
    titles.resize(1); // Ensure at least one title
    titles[0].cards.resize(1); // Ensure at least one card for the first title
    titles[0].cards[0].frontSide = "";
    titles[0].cards[0].backSide = "";
}

customCard::customCard() {
    frontSide = "";
    backSide = "";
}

namespace customSetsNS{
customSet customSets;
int numTitles = 0;
int numCards = 0;
bool active = false;
bool knowAnswer = true;
}
