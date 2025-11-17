#include "MonsterStats.hpp"
#include "Character.hpp"
#include "BattleRoom.hpp"
#include <gtest/gtest.h>

// MonsterStats Tests
TEST(MonsterStatsTest, BasicInitialization) {
    MonsterStats slime("Slime", 20, 5, 10);

    // Check name
    EXPECT_EQ(slime.getName(), "Slime");
    // Check HP
    EXPECT_EQ(slime.getHealth(), 20);
    // Check damage
    EXPECT_EQ(slime.getDamage(), 5);
    // Check XP reward
    EXPECT_EQ(slime.getXPReward(), 10);
}

TEST(MonsterStatsTest, AttackPlayer) {
    MonsterStats goblin("Goblin", 30, 8, 15);
    Character player;
    int initialHP = player.getHP();

    // Monster attacks the player
    goblin.attack(player);

    // Check if player's HP decreased correctly
    EXPECT_EQ(player.getHP(), initialHP - goblin.getDamage());
}

TEST(MonsterStatsTest, ExactDamageKill) {
    MonsterStats orc("Orc", 10, 7, 20);
    Character hero;
    int initialHP = hero.getHP();

    // Deal exact damage to kill the monster
    orc.takeDamage(orc.getHealth());

    // Monster should be dead
    EXPECT_TRUE(orc.isDead());
    // Player HP should remain unchanged
    EXPECT_EQ(hero.getHP(), initialHP);
}

// Character Tests
TEST(CharacterTest, HPAndXPManipulation) {
    Character hero;

    // Reduce HP
    hero.takeDamage(30);
    // Check HP reduction
    EXPECT_EQ(hero.getHP(), 70);

    // Increase XP
    hero.gainXP(50);
    // Check XP increase
    EXPECT_EQ(hero.getXP(), 50);
}

// BattleRoom Tests
TEST(BattleRoomTest, SingleMonsterAccess) {
    MonsterStats troll("Troll", 40, 10, 25);
    BattleRoom room(troll);

    // Access the monster in the battle room
    MonsterStats& monsterRef = room.getMonster();

    // Check if the monster's name matches
    EXPECT_EQ(monsterRef.getName(), "Troll");
    // Check if the monster's HP matches
    EXPECT_EQ(monsterRef.getHealth(), 40);
}
