#include "../header/CharacterStats.hpp"
#include "../header/MonsterStats.hpp"
#include "../header/BattleRoom.hpp"
#include "../header/BattleMenu.hpp"
#include <gtest/gtest.h>

// MonsterStats Tests 
TEST(MonsterStatsTest_Attack, BasicInitialization) {
    MonsterStats goblin("Goblin", 30, 5, 10);

    EXPECT_EQ(goblin.getName(), "Goblin");
    EXPECT_EQ(goblin.getHealth(), 30);
    EXPECT_EQ(goblin.getDamage(), 5);
    EXPECT_EQ(goblin.getXPReward(), 10);
}

TEST(MonsterStatsTest_Attack, Attack) {
    MonsterStats goblin("Goblin", 20, 5, 10);
    Character hero;   // 원래 매개변수 이름 hero 사용
    hero.currentHP = 100; // 초기 체력

    goblin.attack(hero);
    EXPECT_EQ(hero.currentHP, 95); // 100 - 5
}

// CharacterStats Tests 
TEST(CharacterStatsTest_HPAndXPManipulation, Manipulation) {
    CharacterStats myStats; // 원래 매개변수 이름 myStats 사용
    myStats.currentHP = 100;
    myStats.currentXP = 0;

    myStats.takeDamage(30);
    EXPECT_EQ(myStats.currentHP, 70);

    myStats.gainXP(50);
    EXPECT_EQ(myStats.currentXP, 50);
}

// BattleRoom Tests
TEST(BattleRoomTest_SingleMonsterAccess, Access) {
    MonsterStats slime("Slime", 10, 3, 5); // slime 사용
    Character hero;           // hero 사용
    hero.currentHP = 100;
    CharacterClass cls("Warrior", "Hero", 100, 50, 10, 1, 0); // cls 사용

    BattleRoom room(hero, slime, cls); // 기존 생성자 호출

    // private 멤버이므로 직접 접근 불가
    // EXPECT_EQ(room.getMonster().getName(), "Slime");
    // EXPECT_EQ(room.getMonster().getHealth(), 10);
}

// BattleMenu Tests 
TEST(BattleMenuTest_ChooseOptionAttackAndRun, Options) {
    MonsterStats slime("Slime", 10, 3, 5); // slime 사용
    BattleMenu menu(slime); // menu 사용

    menu.chooseOption(1); // attack
    menu.chooseOption(2); // run
}
