#include "BattleRoom.hpp"

BattleRoom::BattleRoom(const MonsterStats& m) : monster(m) {}

MonsterStats& BattleRoom::getMonster() { return monster; }
