#include "MonsterStats.hpp"
#include "CharacterStats.hpp"
#include <algorithm>
#include <iostream>

MonsterStats::MonsterStats(const string& n, int h, int d, int xp)
    : name(n), health(h), damage(d), xpReward(xp) {}

string MonsterStats::getName() const { return name; }
int MonsterStats::getHealth() const { return health; }
int MonsterStats::getDamage() const { return damage; }
int MonsterStats::getXPReward() const { return xpReward; }

void MonsterStats::takeDamage(int dmg){
    health -= dmg;
    if(health < 0) health = 0;
}

bool MonsterStats::isDead() const { return health <= 0; }

void MonsterStats::attack(CharacterStats& player){
    int actualDamage = std::max(0, damage - player.defense/2);
    player.takeDamage(actualDamage);
    std::cout << name << " attacks! You take " << actualDamage << " damage.\n";
}
