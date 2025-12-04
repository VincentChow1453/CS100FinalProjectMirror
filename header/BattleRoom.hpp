#pragma once
#include "CharacterStats.hpp"
#include "MonsterStats.hpp"
#include "CharacterClass.hpp"
#include <string>

class BattleRoom {
private:
    CharacterStats& playerStats; // 전투 중 실시간 스탯 관리 (참조)
    MonsterStats monster;
    CharacterClass& playerClass;

public:
    BattleRoom(CharacterStats& stats, MonsterStats m, CharacterClass& cls);
    MonsterStats& getMonster() { return monster; }

    void startBattle();
    void useItem(const std::string& itemName); // 회복 아이템만 적용
    void applyEquipment(); // 전투 시작 시 장비 효과 적용
};
