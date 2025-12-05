#pragma once

#include "EncounterMenu.hpp"
#include "Combat.hpp"
#include "CharacterClass.hpp"
#include "MonsterStats.hpp"
#include <vector>

class BattleMenu : public EncounterMenu {
private:
    Combat combat;
    bool fledSuccessfully = false; // Flag to indicate successful escape

public:
    BattleMenu();
    
    BattleMenu(CharacterClass* player, MonsterStats* monster) : combat(player, monster) {}

    void startEncounter(Room* newRoom) override;
    void returnToMap();
    
    void displayMenu() const override; 
    void chooseOption(int option) override;
    
    bool hasFled() const { return fledSuccessfully; } 
};
