// Event3.hpp
#ifndef EVENT3_HPP
#define EVENT3_HPP

#include "Event.hpp"
#include <iostream>
using namespace std;

class Event3 : public Event {
public:
    void displayMenu() const override {
        cout << "You discover a locked chest.\n";
        cout << "1. Leave it\n";
        cout << "2. Pick the lock\n";
        cout << "3. Smash it open\n";
    }

    void chooseOption(int option, CharacterClass& player) override {
        while (true) {
            switch (option) {
                case 1:
                    cout << "You walk away.\n";
                    return;
                case 2:
                    cout << "You find a Rare Gem! (+40 gold)\n";
                    player.addItem("Rare Gem");
                    player.setGold(player.getGold() + 40);
                    return;
                case 3:
                    cout << "You smash it open. (+10 gold)\n";
                    player.setGold(player.getGold() + 10);
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