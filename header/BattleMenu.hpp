#pragma once
#include "MonsterStats.hpp"

// BattleMenu handles the interaction during a battle encounter
class BattleMenu {
private:
    int selection_choice;
    MonsterStats monster;
// Displays the battle options to the player
    void displayMenu() const;
    void returnToMap();
// Initiates the battle encounter
public:
    BattleMenu(const MonsterStats& m);
    void startEncounter();
    void chooseOption(int selection);
    void run();
};
