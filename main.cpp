#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Hero.h"
#include "Warrior.h"
#include "Knight.h"
#include "Guild.h"

using namespace std;

// ANSI color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Function to generate a random hero
Hero* generateRandomHero() {
    string names[] = {"Aragorn","Legolas","Gimli","Boromir","Frodo","Eowyn"};
    int index = rand() % 6;
    int hp = 50 + rand() % 101;       // Health between 50-150
    int power = 20 + rand() % 81;     // Power between 20-100
    return new Hero(names[index], hp, power);
}

// Function to generate a random Warrior
Hero* generateRandomWarrior() {
    string names[] = {"Gimli","Thorin","Haldir","Faramir","Dain"};
    int index = rand() % 5;
    int hp = 80 + rand() % 101;       // 80-180
    int power = 30 + rand() % 71;     // 30-100
    int armor = 10 + rand() % 21;     // 10-30
    return new Warrior(names[index], hp, power, armor);
}

// Function to generate a random Knight
Hero* generateRandomKnight() {
    string names[] = {"Arthur","Lancelot","Gawain","Percival"};
    int index = rand() % 4;
    int hp = 100 + rand() % 101;      // 100-200
    int power = 40 + rand() % 81;     // 40-120
    int armor = 15 + rand() % 26;     // 15-40
    int charge = 10 + rand() % 21;    // 10-30
    return new Knight(names[index], hp, power, armor, charge);
}

int main() {
    srand(time(0));
    Guild guild("DragonSlayers");
    int choice;

    do {
        cout << CYAN << "\n====== DRAGONSLAYERS GUILD MENU ======" << RESET << endl;
        cout << YELLOW << "1. Add Hero" << RESET << endl;
        cout << YELLOW << "2. Add Warrior" << RESET << endl;
        cout << YELLOW << "3. Add Knight" << RESET << endl;
        cout << YELLOW << "4. Generate Random Hero" << RESET << endl;
        cout << YELLOW << "5. Show Guild Members" << RESET << endl;
        cout << YELLOW << "6. Show Guild Statistics" << RESET << endl;
        cout << YELLOW << "7. Simulate Battle (Total Guild Power)" << RESET << endl;
        cout << YELLOW << "8. Clear Guild (Delete all heroes)" << RESET << endl;
        cout << RED << "0. Exit Program" << RESET << endl;
        cout << GREEN << "Enter your choice: " << RESET;
        cin >> choice;

        switch(choice) {
            case 1: {
                string name;
                int hp, power;
                cout << BLUE << "Enter Hero Name: " << RESET; cin >> name;
                cout << BLUE << "Enter Health: " << RESET; cin >> hp;
                cout << BLUE << "Enter Power: " << RESET; cin >> power;
                guild += new Hero(name, hp, power);
                cout << GREEN << "Hero added to guild." << RESET << endl;
                break;
            }
            case 2: {
                string name;
                int hp, power, armor;
                cout << BLUE << "Enter Warrior Name: " << RESET; cin >> name;
                cout << BLUE << "Enter Health: " << RESET; cin >> hp;
                cout << BLUE << "Enter Power: " << RESET; cin >> power;
                cout << BLUE << "Enter Armor Rating: " << RESET; cin >> armor;
                guild += new Warrior(name, hp, power, armor);
                cout << GREEN << "Warrior added to guild." << RESET << endl;
                break;
            }
            case 3: {
                string name;
                int hp, power, armor, charge;
                cout << BLUE << "Enter Knight Name: " << RESET; cin >> name;
                cout << BLUE << "Enter Health: " << RESET; cin >> hp;
                cout << BLUE << "Enter Power: " << RESET; cin >> power;
                cout << BLUE << "Enter Armor Rating: " << RESET; cin >> armor;
                cout << BLUE << "Enter Charge Bonus: " << RESET; cin >> charge;
                guild += new Knight(name, hp, power, armor, charge);
                cout << GREEN << "Knight added to guild." << RESET << endl;
                break;
            }
            case 4: {
                int type;
                cout << MAGENTA << "Generate: 1-Hero 2-Warrior 3-Knight: " << RESET;
                cin >> type;
                Hero* randomHero = nullptr;
                if(type == 1) randomHero = generateRandomHero();
                else if(type == 2) randomHero = generateRandomWarrior();
                else if(type == 3) randomHero = generateRandomKnight();
                else {
                    cout << RED << "Invalid type!" << RESET << endl;
                    break;
                }
                guild += randomHero;
                cout << GREEN << "Random hero generated and added!" << RESET << endl;
                break;
            }
            case 5:
                cout << guild;
                break;
            case 6:
                guild.displayGuildStats();
                break;
            case 7:
                cout << GREEN << "Battle Simulation: Total Guild Power = "
                     << guild.calculateTotalGuildPower() << RESET << endl;
                break;
            case 8:
                cout << RED << "Clearing guild heroes..." << RESET << endl;
                break;
            case 0:
                cout << CYAN << "Exiting program..." << RESET << endl;
                break;
            default:
                cout << RED << "Invalid choice! Try again." << RESET << endl;
        }

    } while(choice != 0);

    return 0;
}