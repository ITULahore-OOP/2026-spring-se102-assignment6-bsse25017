#ifndef KNIGHT_H
#define KNIGHT_H

#include "Warrior.h"

class Knight : public Warrior
{
private:
    int chargeBonus;

public:
    Knight(string name, int hp, int power, int armor, int charge);

    int calculateBurstDamage() const;
};

#endif