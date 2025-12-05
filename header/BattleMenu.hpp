#pragma once
#include "EncounterMenu.hpp"
#include "Combat.hpp"
#include "CharacterClass.hpp"
#include "MonsterStats.hpp"

class BattleMenu : public EncounterMenu {
private:
    Combat combat;
    bool fledSuccessfully = false; // Added: Flag to indicate successful escape

public:
    BattleMenu(CharacterClass* player, MonsterStats* monster) : combat(player, monster) {}

    void startEncounter(Room* newRoom) override;
    void returnToMap();
    
    // Implementation declarations for vtable error resolution and EncounterMenu inheritance
    void displayMenu() const override; 
    void chooseOption(int option) override;
    
    bool hasFled() const { return fledSuccessfully; } // Added: Getter for escape flag
};
