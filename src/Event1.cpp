#include "Event1.hpp"
#include "CharacterSelectMenu.hpp"
#include <iostream>
using namespace std;

void Event1::displayMenu() const {
    cout << "A traveler offers you food.\n";
    cout << "1. Accept\n";
    cout << "2. Decline\n";
    cout << "3. Attack them\n";
}

void Event1::chooseOption(int option) {
    CharacterClass* player = CharacterSelectMenu::player;

    while (true) {
        switch (option) {
            case 1:
                cout << "You feel refreshed! (+5 health)\n";
                player->setBaseHealth(player->getBaseHealth() + 5);
                return;
            case 2:
                cout << "You walk away.\n";
                return;
            case 3:
                cout << "They fight back! Why did you do that? (-10 health)\n";
                player->setBaseHealth(player->getBaseHealth() - 10);
                return;
            default:
                cout << "Enter 1, 2, or 3: ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> option;
        }
    }
}
