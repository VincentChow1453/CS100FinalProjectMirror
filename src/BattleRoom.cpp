#include "BattleRoom.hpp"
#include <iostream>
// Constructor initializing the BattleRoom with a monster
BattleRoom::BattleRoom(const MonsterStats& m) : monster(m) {}
// Returns a reference to the monster in the room
MonsterStats& BattleRoom::getMonster() { return monster; }
// Placeholder for encounter logic
void BattleRoom::TriggerEncounter() {
    std::cout << "Encounter started with " << monster.getName() << "!\n";
}
