#pragma once
#include "CharacterClass.hpp"
#include "MonsterStats.hpp"
#include "Skill.hpp"
#include <string>
#include <vector>

class Combat {
public:
    CharacterClass* player;
    MonsterStats* monster;
private:
    bool playerDefending;
    StatusEffectType playerStatus; 
    StatusEffectType monsterStatus;
    int playerBurnStacks;
    int playerPoisonStacks;
    int monsterBurnStacks;
    int monsterPoisonStacks;
    int freezeDuration;
    int monsterDoomStacks;
    int playerDefenseBuffDuration;
    int playerDefenseBuffValue;
// ... (rest of the class definition remains the same) ...
public:
    Combat(CharacterClass* p, MonsterStats* m);
    void playerAttack(int skillIndex); 
    void monsterAttack();
    void playerDefend();
    void applyStatus(CharacterClass* target, StatusEffectType statusType);
    void applyStatusDamage(); 
    void updateDurations(); 

    bool isMonsterDead() const;
    bool isPlayerDead() const;
    bool isPlayerParalyzed() const; 
    int getPlayerHP() const;
    int getPlayerMana() const;
    int getMonsterHP() const;
    std::string getPlayerName() const;
    std::string getMonsterName() const;
    int getMonsterXPReward() const;
    int getMonsterGoldReward() const;
    
    // Additional: Function to check if a specific skill index is a defense buff effect
    bool isSkillDefenseBuff(int skillIndex); 

    void setPlayerHP(int newHP);
};
