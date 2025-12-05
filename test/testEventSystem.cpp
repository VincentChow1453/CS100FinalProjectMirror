#include <iostream>
#include <memory>
#include <cstdlib>
#include <ctime>

#include "EventMenu.hpp"
#include "EventRoom.hpp"
#include "CharacterClass.hpp"
using namespace std;

int main() {
    srand(time(nullptr));

    //create player
    CharacterClass player;
    player.setBaseHealth(100);
    player.setBaseMana(50);
    player.setGold(10);

    //create event room & assign a player
    EventRoom room;
    room.setPlayer(&player);

    //create event menu
    EventMenu menu;

    cout << "============================================\n";
    cout << "   EVENT SYSTEM TEST — STARTING\n";
    cout << "============================================\n\n";

    //run encounters
    for (int i = 1; i <= 5; i++) {
        cout << "---------- Encounter " << i << " ----------\n";

        cout << "Player Before Event:\n";
        cout << "  Health: " << player.getBaseHealth() << "\n";
        cout << "  Mana:   " << player.getBaseMana() << "\n";
        cout << "  Gold:   " << player.getGold() << "\n\n";

        //test
        menu.startEncounter(&room);

        cout << "\nPlayer After Event:\n";
        cout << "  Health: " << player.getBaseHealth() << "\n";
        cout << "  Mana:   " << player.getBaseMana() << "\n";
        cout << "  Gold:   " << player.getGold() << "\n";

        cout << "--------------------------------------------\n\n";
    }

    cout << "============================================\n";
    cout << "   EVENT SYSTEM TEST — COMPLETE\n";
    cout << "============================================\n";

    return 0;
}
