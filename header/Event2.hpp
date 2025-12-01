// Event2.hpp
#ifndef EVENT2_HPP
#define EVENT2_HPP

#include "Event.hpp"
#include <iostream>
using namespace std;

class Event2 : public Event {
public:
    void displayMenu() const override {
        cout << "You find a glowing potion on the ground.\n";
        cout << "1. Ignore it\n";
        cout << "2. Drink it\n";
        cout << "3. Throw it away\n";
    }

    void chooseOption(int option, CharacterClass& player) override {
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
};

#endif