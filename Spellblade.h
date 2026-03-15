#ifndef SPELLBLADE_H
#define SPELLBLADE_H

#include "Warrior.h"
#include "MagicalEntity.h"

// Spellblade uses multiple inheritance
class Spellblade : public Warrior, public MagicalEntity
{
public:
    // Constructor
    // name, health, power, armor, mana, spellPower
    Spellblade(string name, int hp, int power,
               int armor, int mana, int spell);

    // Hybrid damage calculation
    int calculateHybridDamage();
};

#endif