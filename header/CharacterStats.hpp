#pragma once
#include <string>

class CharacterStats {
public:
    int currentHP;
    int attack;
    int defense;
    int level;
    int currentXP;

    CharacterStats(int hp=100, int atk=10, int def=0, int lvl=1);

    void takeDamage(int dmg);
    void gainXP(int amount);
    void levelUp();
    bool isDead() const;
};
