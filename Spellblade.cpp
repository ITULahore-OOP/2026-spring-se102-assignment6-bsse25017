#include "Spellblade.h"

// Constructor
// Calls constructors of both parent classes
Spellblade::Spellblade(string name, int hp, int power,
                       int armor, int mana, int spell)
    : Warrior(name, hp, power, armor),
      MagicalEntity(mana, spell)
{
}

// Hybrid damage = physical power + magical power
int Spellblade::calculateHybridDamage()
{
    return basePower + spellPower;
}