#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>

#include "CharacterSelectMenu.hpp"
#include "EventMenu.hpp"
#include "EventRoom.hpp"

using namespace std;

int main() {
    srand(time(nullptr));

    cout << "============================================\n";
    cout << "   EVENT SYSTEM TEST — STARTING\n";
    cout << "============================================\n\n";

    // -----------------------------------------
    // Create a global player through Select Menu
    // -----------------------------------------
    CharacterSelectMenu::player = new CharacterClass();
    CharacterSelectMenu::player->setBaseHealth(100);
    CharacterSelectMenu::player->setBaseMana(50);
    CharacterSelectMenu::player->setGold(10);

    CharacterClass* player = CharacterSelectMenu::player;

    // -----------------------------------------
    // Create EventRoom + EventMenu
    // -----------------------------------------
    EventRoom room;
    EventMenu menu;

    // -----------------------------------------
    // Test loop
    // -----------------------------------------
    for (int i = 1; i <= 5; i++) {
        cout << "---------- Encounter " << i << " ----------\n";

        cout << "Player Before Event:\n";
        cout << "  Health: " << player->getBaseHealth() << "\n";
        cout << "  Mana:   " << player->getBaseMana() << "\n";
        cout << "  Gold:   " << player->getGold() << "\n\n";

        // The NEW API:
        // EventMenu::startEncounter(EventRoom*)
        menu.startEncounter(&room);

        cout << "\nPlayer After Event:\n";
        cout << "  Health: " << player->getBaseHealth() << "\n";
        cout << "  Mana:   " << player->getBaseMana() << "\n";
        cout << "  Gold:   " << player->getGold() << "\n";

        cout << "--------------------------------------------\n\n";
    }

    cout << "============================================\n";
    cout << "   EVENT SYSTEM TEST — COMPLETE\n";
    cout << "============================================\n";

    // cleanup
    delete CharacterSelectMenu::player;
    CharacterSelectMenu::player = nullptr;

    return 0;
}
