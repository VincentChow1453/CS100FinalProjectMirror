#include "BattleMenu.hpp"
#include <iostream>
using namespace std;

// Character stub
class Character {
public:
    string getName() const { return "Player"; }
    void takeDamage(int dmg) {}
    void gainXP(int xp) {}
};

BattleMenu::BattleMenu(MonsterStats &m) : monster(m), selection_choice(0) {}

void BattleMenu::displayMenu() const {
    cout << "1. Attack\n2. Run" << endl;
}

void BattleMenu::chooseOption(int selection) {
    selection_choice = selection;
}

void BattleMenu::run(Character &player) {
    if (selection_choice == 1) {
        cout << player.getName() << " attacks " << monster.getName() << "!" << endl;
        monster.takeDamage(50); 
        if (monster.isDead()) {
            monster.die(player);
        } else {
            monster.attack(player);
        }
    } else if (selection_choice == 2) {
        cout << player.getName() << " runs away!" << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }
}
