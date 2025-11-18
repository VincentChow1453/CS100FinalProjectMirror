#include "BattleMenu.hpp"
#include <iostream>
// Constructor initializing the battle menu with a monster
BattleMenu::BattleMenu(const MonsterStats& m) : monster(m), selection_choice(0) {}
// Displays the battle options to the player
void BattleMenu::displayMenu() const {
    std::cout << "1. Attack\n2. Run\n";
}
// Returns to the map (placeholder function)
void BattleMenu::returnToMap() {
    std::cout << "Returning to map...\n";
}
// Starts the battle encounter
void BattleMenu::startEncounter() {
    std::cout << "Battle started with " << monster.getName() << "!\n";
}
// Handles the player's choice during the battle
void BattleMenu::chooseOption(int selection) {
    selection_choice = selection;
    if (selection_choice == 1) {
        std::cout << "You attack " << monster.getName() << "!\n";
    } else {
        returnToMap();
    }
}
// Runs the battle menu interaction
void BattleMenu::run() {
    displayMenu();
    chooseOption(selection_choice);
}
