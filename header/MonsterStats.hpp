#ifndef MONSTERSTATS_HPP
#define MONSTERSTATS_HPP

#include <string>
#include "Character.hpp"

class MonsterStats {
private:
    std::string name;
    int health;
    int damage;
    int xpReward;

public:
    MonsterStats(const std::string& n, int h, int d, int x);

    // getters
    const std::string& getName() const;
    int getHealth() const;
    int getDamage() const;
    int getXPReward() const;

    // battle functions
    void takeDamage(int dmg);
    bool isDead() const;
    void attack(Character& player);
    void die(Character& player);
};

#endif
