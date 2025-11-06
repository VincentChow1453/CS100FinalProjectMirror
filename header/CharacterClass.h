#ifndef CHARACTERCLASS_H
#define CHARACTERCLASS_H

#include <string>
#include "Inventory.h"

class Character;

class CharacterClass {
private:
    std::string name;
    std::string characterType;
    int health;
    int mana;
    int strength;
    int level;
    Inventory playerInv;
    Character* selectedClass; //Reference to the selected character

    public:
     void displayInfo() const;
};

#endif // CHARACTERCLASS_H