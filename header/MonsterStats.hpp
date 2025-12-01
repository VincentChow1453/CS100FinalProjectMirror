#pragma once
#include "CharacterStats.hpp"
#include <string>
#include "CharacterStats.hpp"
using namespace std;

class CharacterStats;

class MonsterStats {
private:
    string name;
    int health;
    int damage;
    int xpReward;

public:
    MonsterStats(const string& n, int h, int d, int xp);

    string getName() const;
    int getHealth() const;
    int getDamage() const;
    int getXPReward() const;

    void takeDamage(int dmg);
    bool isDead() const;
    void attack(CharacterStats& player);
};
