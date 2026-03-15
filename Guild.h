#ifndef GUILD_H
#define GUILD_H

#include <iostream>
#include <string>
#include "Hero.h"

using namespace std;

class Guild
{
private:
    string guildName;
    Hero* roster[15];
    int memberCount;

public:
    Guild(string name);
    ~Guild();

    void operator+=(Hero* newHero);

    int calculateTotalGuildPower() const;

    void displayGuildStats() const;

    friend ostream& operator<<(ostream& os, const Guild& g);
};

#endif