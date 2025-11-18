#include "../header/Character.hpp"
#include "../header/MonsterStats.hpp"
#include "../header/BattleRoom.hpp"
#include "../header/BattleMenu.hpp"
#include <gtest/gtest.h>

// MonsterStats Tests 
TEST(MonsterStatsTest, BasicInitialization) {
    MonsterStats goblin("Goblin", 30, 5, 10);

    EXPECT_EQ(goblin.getName(), "Goblin");
    EXPECT_EQ(goblin.getHealth(), 30);
    EXPECT_EQ(goblin.getDamage(), 5);
    EXPECT_EQ(goblin.getXPReward(), 10);
}

TEST(MonsterStatsTest, AttackAndDie) {
    MonsterStats goblin("Goblin", 20, 5, 10);
    Character hero;

    goblin.attack(hero);
    EXPECT_EQ(hero.getHP(), 95); // 100 - 5

    goblin.takeDamage(20);
    EXPECT_TRUE(goblin.isDead());

    goblin.die(hero);
    EXPECT_EQ(hero.getXP(), 10); // hero gains xp
}

// Character Tests 
TEST(CharacterTest, HPAndXPManipulation) {
    Character hero;

    hero.takeDamage(30);
    EXPECT_EQ(hero.getHP(), 70);

    hero.gainXP(50);
    EXPECT_EQ(hero.getXP(), 50);
}

// BattleRoom Tests
TEST(BattleRoomTest, SingleMonsterAccess) {
    MonsterStats slime("Slime", 10, 3, 5);
    BattleRoom room(slime);

    MonsterStats& monsterRef = room.getMonster();
    EXPECT_EQ(monsterRef.getName(), "Slime");
    EXPECT_EQ(monsterRef.getHealth(), 10);
}

// BattleMenu Tests 
TEST(BattleMenuTest, ChooseOptionAttack) {
    MonsterStats slime("Slime", 10, 3, 5);
    BattleMenu menu(slime);

    // Simulate player choosing attack
    menu.chooseOption(1); // attack
    // No hp/xp changes here because BattleMenu only prints for now
}

TEST(BattleMenuTest, ChooseOptionRun) {
    MonsterStats slime("Slime", 10, 3, 5);
    BattleMenu menu(slime);

    // Simulate player choosing run
    menu.chooseOption(2); // run
    // Should just call returnToMap (prints message)
}
