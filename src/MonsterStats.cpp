#include "MonsterStats.hpp"
// Constructor initializing monster attributes
MonsterStats::MonsterStats(const std::string& n, int h, int d, int x)
    : name(n), health(h), damage(d), xpReward(x) {}
// Getters for monster attributes
const std::string& MonsterStats::getName() const { return name; }
int MonsterStats::getHealth() const { return health; }
int MonsterStats::getDamage() const { return damage; }
int MonsterStats::getXPReward() const { return xpReward; }
// Methods to manipulate monster state
void MonsterStats::takeDamage(int dmg) {
    health -= dmg;
    if (health < 0) health = 0;
}
// Check if the monster is dead
bool MonsterStats::isDead() const { return health <= 0; }
// Monster attacks the player character
void MonsterStats::attack(Character& player) {
    player.takeDamage(damage);
}
// Handle monster death and reward the player
void MonsterStats::die(Character& player) {
    if (isDead()) player.gainXP(xpReward);
}
