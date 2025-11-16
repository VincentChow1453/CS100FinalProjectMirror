#include "MonsterStats.hpp"
#include <iostream>
using namespace std;

// Character stub
class Character {
public:
    string getName() const { return "Player"; }
    void takeDamage(int dmg) {}
    void gainXP(int xp) {}
};

MonsterStats::MonsterStats(string n, int h, int d, int x)
    : name(n), health(h), damage(d), xp(x) {}

string MonsterStats::getName() const { return name; }
int MonsterStats::getHealth() const { return health; }
int MonsterStats::getDamage() const { return damage; }
int MonsterStats::getXP() const { return xp; }

void MonsterStats::attack(Character &player) {
    cout << name << " attacks " << player.getName() << " for " << damage << " damage!" << endl;
    player.takeDamage(damage);
}

void MonsterStats::takeDamage(int amount) {
    health -= amount;
    if (health < 0) health = 0;
}

bool MonsterStats::isDead() const {
    return health <= 0;
}

void MonsterStats::die(Character &player) {
    cout << name << " is defeated! " << player.getName()
         << " gains " << xp << " XP." << endl;
    player.gainXP(xp);
}
