#ifndef BATTLEROOM_HPP
#define BATTLEROOM_HPP

#include "MonsterStats.hpp"

class BattleRoom {
private:
    MonsterStats monster;

public:
    BattleRoom(const MonsterStats& m);
    MonsterStats& getMonster();
};

#endif
