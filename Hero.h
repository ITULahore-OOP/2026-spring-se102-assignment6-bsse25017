#ifndef HERO_H
#define HERO_H

#include <string>
using namespace std;

class Hero
{
protected:
    string heroName;
    int health;
    int basePower;

public:
    Hero(string name, int hp, int power);
    ~Hero();

    // const getters (needed for test 5)
    string getName() const;
    int getHealth() const;
    int getPower() const;

    void takeDamage(int damage);

    bool operator>(const Hero& other) const;
    int operator+(const Hero& other) const;
};

#endif