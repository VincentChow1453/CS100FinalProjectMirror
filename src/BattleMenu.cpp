#include "BattleMenu.hpp"
#include <iostream>
using namespace std;

BattleMenu::BattleMenu(const MonsterStats& m) : selection_choice(0), monster(m) {}

void BattleMenu::displayMenu() const {
    cout << "1. Attack\n2. Run\n";
}

void BattleMenu::chooseOption(int choice) {
    selection_choice = choice;
    if (selection_choice == 1) {
        cout << "You attack " << monster.getName() << "!\n";
    } else {
        cout << "You try to run!\n";
    }
}

void BattleMenu::run() {
    displayMenu();
    chooseOption(1); // default attack for test
}
