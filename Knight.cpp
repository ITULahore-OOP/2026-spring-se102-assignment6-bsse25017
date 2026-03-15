#include "Knight.h"

Knight::Knight(string name, int hp, int power, int armor, int charge)
    : Warrior(name, hp, power, armor)
{
    chargeBonus = charge;
}

int Knight::calculateBurstDamage() const
{
    return basePower + chargeBonus;
}