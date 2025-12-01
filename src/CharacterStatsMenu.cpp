#include "CharacterStatsMenu.hpp"
#include <iostream>

void CharacterStatsMenu::showStats(const CharacterStats& stats){
    std::cout << "\n===== CHARACTER STATS =====\n";
    std::cout << "HP: " << stats.currentHP << "\n";
    std::cout << "Attack: " << stats.attack << "\n";
    std::cout << "Defense: " << stats.defense << "\n";
    std::cout << "Level: " << stats.level << "\n";
    std::cout << "XP: " << stats.currentXP << "/100\n";
    std::cout << "===========================\n";
}
