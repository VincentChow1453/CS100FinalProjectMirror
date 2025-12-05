#include "Event4.hpp"
#include "CharacterSelectMenu.hpp"
#include <iostream>
using namespace std;

void Event4::displayMenu() const {
    cout << "A lost child asks for help.\n";
    cout << "1. Ignore them\n";
    cout << "2. Help them\n";
    cout << "3. Steal from them\n";
}

void Event4::chooseOption(int option) {
    CharacterClass* player = CharacterSelectMenu::player;

    while (true) {
        switch (option) {
            case 1:
                cout << "You walk past. Nothing happens. Shame on you.\n";
                return;
            case 2:
                cout << "You help the kid. Good deeds, huh? (+25 gold)\n";
                player->setGold(player->getGold() + 25);
                return;
            case 3:
                cout << "You steal from the kid... Wow that kid was rich! (+75 gold)\n";
                player->setGold(player->getGold() + 75);
                return;
            default:
                cout << "Enter 1, 2, or 3: ";
                cin.clear();
                cin.ignore(10000, '\n');
                cin >> option;
        }
    }
}
