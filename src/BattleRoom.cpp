#include "BattleRoom.hpp"
#include <iostream>
using namespace std;

// Character stub
class Character {
public:
    string getName() const { return "Player"; }
    void takeDamage(int dmg) {}
    void gainXP(int xp) {}
};

BattleRoom::BattleRoom(MonsterStats m) : monster(m) {}

void BattleRoom::TriggerEncounter(Character &player) {
    cout << "A wild " << monster.getName() << " appeared!" << endl;
}

MonsterStats& BattleRoom::getMonster() {
    return monster;
}
