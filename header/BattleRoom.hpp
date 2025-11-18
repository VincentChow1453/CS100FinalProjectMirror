#pragma once
#include "MonsterStats.hpp"
// BattleRoom represents a room where a battle with a monster occurs
class BattleRoom {
private:
    MonsterStats monster;
    // Additional attributes can be added as needed
public:
    BattleRoom(const MonsterStats& m);
    MonsterStats& getMonster();
    void TriggerEncounter(); // placeholder for encounter logic
};
