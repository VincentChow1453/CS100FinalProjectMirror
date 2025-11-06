#include "CharacterClass.h"
#include <iostream>

void CharacterClass::displayClassInfo() const {
    std::cout << "Class: " << classType << "\n";
    std::cout << "Base Health: " << baseHealth << "\n";
    std::cout << "Base Mana: " << baseMana << "\n";
    std::cout << "Base Strength: " << baseStrength << "\n";
    std::cout << "Base Level: " << baseLevel << "\n";
}