#include "gtest/gtest.h"
#include "MonsterStats.hpp"
#include "BattleRoom.hpp"
#include "BattleMenu.hpp"

// Character stub
class Character {
public:
    string getName() const { return "Player"; }
    void takeDamage(int dmg) {}
    void gainXP(int xp) {}
};

TEST(MonsterTest, TakeDamageAndDie) {
    Character player;
    MonsterStats goblin("Goblin", 50, 10, 20);

    goblin.takeDamage(50);
    EXPECT_TRUE(goblin.isDead());

    goblin.die(player); 
}

TEST(MonsterTest, AttackPlayer) {
    Character player;
    MonsterStats goblin("Goblin", 50, 30, 20);

    goblin.attack(player);
    EXPECT_EQ(goblin.getHealth(), 50); 
}

TEST(FailureTest, MonsterNotDeadIfHealthAboveZero) {
    MonsterStats goblin("Goblin", 50, 10, 20);
    goblin.takeDamage(30);
    EXPECT_FALSE(goblin.isDead());
}
