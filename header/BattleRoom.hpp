#ifndef BATTLEROOM_HPP
#define BATTLEROOM_HPP

#include "MonsterStats.hpp"

class Character; 

class BattleRoom {
private:
    MonsterStats monster;

public:
    BattleRoom(MonsterStats m);
    void TriggerEncounter(Character &player);
    MonsterStats& getMonster();
};

#endif
