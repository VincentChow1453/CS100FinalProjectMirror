#ifndef CHARACTERSTATS_H
#define CHARACTERSTATS_H

#include <string>
#include "Inventory.h"

class CharacterStats {
private:
    std::string name;
    std::string classType;
    int health;
    int mana;
    int strength;
    int level;
    Inventory playerInv;
   
    public:
     void displayInfo() const;
};

#endif // CHARACTERCLASS_H