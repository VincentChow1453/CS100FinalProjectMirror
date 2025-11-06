#include "CharacterStats.h"
#include <iostream>

void CharacterStats::displayInfo() const {
    std::cout << "Name: " << name << "\n";
    std::cout << "Class Type: " << classType << "\n";
    std::cout << "Health: " << health << "\n";
    std::cout << "Mana: " << mana << "\n";
    std::cout << "Strength: " << strength << "\n";
    std::cout << "Level: " << level << "\n";
    std::cout << "Inventory:\n";
    playerInv.displayInventory();
    }