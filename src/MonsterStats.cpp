#include "MonsterStats.hpp"

MonsterStats::MonsterStats(const std::string& n, int h, int d, int x)
    : name(n), health(h), damage(d), xpReward(x) {}

const std::string& MonsterStats::getName() const { return name; }
int MonsterStats::getHealth() const { return health; }
int MonsterStats::getDamage() const { return damage; }
int MonsterStats::getXPReward() const { return xpReward; }

void MonsterStats::takeDamage(int dmg) {
    health -= dmg;
     if (health < 0) health = 0;
}

bool MonsterStats::isDead() const {
    return health <= 0;
}

void MonsterStats::attack(Character& player) {
    player.takeDamage(damage);
}

void MonsterStats::die(Character& player) {
    player.gainXP(xpReward);
}
