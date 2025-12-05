#include "Event1.hpp"
#include <iostream>
using namespace std;

void Event1::displayMenu() const {
    cout << "A shady traveler appears! What do you do?\n";
    cout << "1. Leave\n";
    cout << "2. Attack him\n";
    cout << "3. Barter with him\n";
}

void Event1::chooseOption(int option, CharacterClass& player) {
    while (true) {
        switch (option) {
            case 1:
                cout << "You leave calmly. You feel an eerie stare...\n";
                return;

            case 2:
                cout << "You attack him! (-10 health)\n";
                player.setBaseHealth(player.getBaseHealth() - 10);
                return;

            case 3:
                cout << "You barter and earn gold! (+20 gold)\n";
                player.setGold(player.getGold() + 20);
                return;

            default:
                cout << "Invalid choice — please pick 1, 2, or 3: ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> option;
        }
    }
}
