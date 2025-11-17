#pragma once
#include <string>
// Simple Character class for battle simulation
class Character {
private:
    int hp;
    int xp;

public:
    Character() : hp(100), xp(0) {}

    void takeDamage(int dmg) { hp -= dmg; if (hp < 0) hp = 0; }
    void gainXP(int amount) { xp += amount; }

    int getHP() const { return hp; }
    int getXP() const { return xp; }
};
