#ifndef MONSTERSTATS_HPP
#define MONSTERSTATS_HPP

#include <string>
using namespace std;

class Character; 

class MonsterStats {
private:
    string name;
    int health;
    int damage;
    int xp;

public:
    MonsterStats(string n, int h, int d, int x);

    string getName() const;
    int getHealth() const;
    int getDamage() const;
    int getXP() const;

    void attack(Character &player);
    void takeDamage(int amount);
    bool isDead() const;
    void die(Character &player);
};

#endif
