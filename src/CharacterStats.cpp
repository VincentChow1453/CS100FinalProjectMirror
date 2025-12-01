#include "CharacterStats.hpp"
#include <iostream>

CharacterStats::CharacterStats(int hp, int atk, int def, int lvl)
    : currentHP(hp), attack(atk), defense(def), level(lvl), currentXP(0) {}

void CharacterStats::takeDamage(int dmg){
    currentHP -= dmg;
    if(currentHP < 0) currentHP = 0;
}

void CharacterStats::gainXP(int amount){
    currentXP += amount;
    if(currentXP >= 100){ // 예시: 100 XP마다 레벨업
        currentXP -= 100;
        levelUp();
    }
}

bool CharacterStats::isDead() const{
    return currentHP <= 0;
}

void CharacterStats::levelUp(){
    level++;
    attack += 2;
    defense += 1;
    currentHP += 20; // 최대HP 증가
    std::cout << "\n LEVEL UP! New Level: " << level << "\n";
}
