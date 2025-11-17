#pragma once
#include <string>
#include "Character.hpp"
// MonsterStats holds the stats and behaviors of a monster in the game
class MonsterStats {
private:
    std::string name;
    int health;
    int damage;
    int xpReward;
// Additional attributes can be added as needed
public:
    MonsterStats(const std::string& n, int h, int d, int x);
// Getters for monster attributes
    const std::string& getName() const;
    int getHealth() const;
    int getDamage() const;
    int getXPReward() const;
// Methods to manipulate monster state
    void takeDamage(int dmg);
    bool isDead() const;
    void attack(Character& player);
    void die(Character& player);
};
