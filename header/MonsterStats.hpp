#ifndef MONSTERSTATS_HPP
#define MONSTERSTATS_HPP

#include <string>
#include <vector>
#include <memory> // For unique_ptr usage
using namespace std;

// Enum defining the game stages
enum Stage { STAGE1, STAGE2, STAGE3, STAGE4, STAGE5, BOSS };

class MonsterStats {
private:
    string name;
    int maxHP;
    int currentHP;
    int damage;
    int xpReward;
    int goldReward;
    bool isBoss;

public:
    MonsterStats(string n = "Goblin", int h = 50, int a = 10, int xp = 20, int gold = 5, bool boss = false);

    // Getter functions
    string getName() const;
    int getMaxHP() const;
    int getCurrentHP() const;
    int getDamage() const;
    int getXPReward() const;
    int getGoldReward() const;
    bool getIsBoss() const;
    void setCurrentHP(int hp);

    // Static functions to manage monsters
    static vector<MonsterStats> getMonsters(Stage stage);
    static unique_ptr<MonsterStats> createRandomMonster(Stage stage);
};

#endif
