// Event4.hpp
#ifndef EVENT4_HPP
#define EVENT4_HPP

#include "Event.hpp"
#include <iostream>
using namespace std;

class Event4 : public Event {
public:
    void displayMenu() const override {
        cout << "A lost child asks for help.\n";
        cout << "1. Ignore them\n";
        cout << "2. Help them\n";
        cout << "3. Steal from them\n";
    }

    void chooseOption(int option, CharacterClass& player) override {
        while (true) {
            switch (option) {
                case 1:
                    cout << "You walk past. Nothing happens.\n";
                    return;
                case 2:
                    cout << "You help the kid! (+25 gold)\n";
                    player.setGold(player.getGold() + 25);
                    return;
                case 3:
                    cout << "You steal from the kid... (+75 gold)\n";
                    player.setGold(player.getGold() + 75);
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