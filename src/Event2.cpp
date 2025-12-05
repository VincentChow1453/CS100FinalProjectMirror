#include "Event2.hpp"
#include <iostream>
using namespace std;

void Event2::displayMenu() const {
    cout << "You find a glowing potion on the ground.\n";
    cout << "1. Ignore it\n";
    cout << "2. Drink it\n";
    cout << "3. Throw it away\n";
}

void Event2::chooseOption(int option, CharacterClass& player) {
    while (true) {
        switch (option) {
            case 1:
                cout << "You leave the potion. Nothing happens.\n";
                return;

            case 2:
                cout << "You drink it! (+10 mana)\n";
                player.setBaseMana(player.getBaseMana() + 10);
                return;

            case 3:
                cout << "You throw it away — it explodes! (-5 health)\n";
                player.setBaseHealth(player.getBaseHealth() - 5);
                return;

            default:
                cout << "Invalid choice — please pick 1, 2, or 3: ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> option;
        }
    }
}
