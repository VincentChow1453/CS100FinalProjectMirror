#include "MonsterStats.hpp"
#include <cstdlib> // For rand(), srand()
#include <iostream>
#include <vector>

MonsterStats::MonsterStats(string n, int hp, int dmg, int xp, int gold, bool boss)
    : name(n), maxHP(hp), currentHP(hp), damage(dmg), xpReward(xp), goldReward(gold), isBoss(boss) {}

string MonsterStats::getName() const { return name; }
int MonsterStats::getMaxHP() const { return maxHP; }
int MonsterStats::getCurrentHP() const { return currentHP; }
int MonsterStats::getDamage() const { return damage; }
int MonsterStats::getXPReward() const { return xpReward; }
int MonsterStats::getGoldReward() const { return goldReward; }
bool MonsterStats::getIsBoss() const { return isBoss; }
void MonsterStats::setCurrentHP(int hp) { currentHP = hp; }

// Static function: Returns a list of potential monsters for a given stage
vector<MonsterStats> MonsterStats::getMonsters(Stage stage) {
    switch(stage) {
        case STAGE1:
            return { MonsterStats("Goblin", 60, 5, 10, 5),
                     MonsterStats("Wolf", 50, 7, 12, 6),
                     MonsterStats("Slime", 30, 4, 8, 3) };
        case STAGE2:
            return { MonsterStats("Orc", 100, 10, 20, 10),
                     MonsterStats("Bandit", 80, 12, 25, 12),
                     MonsterStats("Troll", 120, 15, 30, 15) };
        case STAGE3:
            return { MonsterStats("Necromancer", 150, 20, 40, 20),
                     MonsterStats("Skeleton", 130, 18, 35, 18),
                     MonsterStats("Dark Knight", 180, 25, 50, 25) };
        case STAGE4:
            return { MonsterStats("Harpy", 200, 28, 55, 30),
                     MonsterStats("Ogre", 220, 30, 60, 35),
                     MonsterStats("Witch", 180, 24, 50, 28) };
        case STAGE5:
            return { MonsterStats("Golem", 250, 32, 70, 40),
                     MonsterStats("Vampire", 240, 30, 65, 38),
                     MonsterStats("Minotaur", 260, 35, 75, 42) };
        case BOSS:
            return { MonsterStats("Death Dragon", 500, 30, 100, 100, true) };
        default:
            return {};
    }
}

// Static function: Creates a unique instance of a random monster based on the stage
unique_ptr<MonsterStats> MonsterStats::createRandomMonster(Stage stage) {
    vector<MonsterStats> monsters = MonsterStats::getMonsters(stage);
    if (monsters.empty()) return nullptr;

    int randomIndex = rand() % monsters.size();
    MonsterStats selected = monsters[randomIndex];

    return unique_ptr<MonsterStats>(new MonsterStats(
        selected.getName(), 
        selected.getMaxHP(), 
        selected.getDamage(), 
        selected.getXPReward(), 
        selected.getGoldReward(),
        selected.getIsBoss()
    ));
}
