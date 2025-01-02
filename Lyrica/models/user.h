#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "customset.h"
using namespace std;

class user
{
public:
    user();
    std::vector<customSet> customSets;

};

#endif // USER_H
extern user currentUser;
