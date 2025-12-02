#include "CharacterClass.h"
#include "MonsterStats.hpp"
#include "Combat.hpp"
#include "Skill.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <string>

// 전역 변수 g_playerCurrentHP는 main.cpp나 LevelUp.cpp에서 정의되므로 extern으로 선언
extern int g_playerCurrentHP; 

// 테스트 픽스처(Fixture) 설정: 공통적으로 사용될 객체들을 미리 정의
class CombatTests : public ::testing::Test {
protected:
    CharacterClass* player;
    MonsterStats* monster;
    Combat* combat;

    void SetUp() override {
        // 테스트 시작 전 실행: 플레이어와 몬스터 초기화
        // CharacterClass(classType, name, health, mana, strength, level, gold)
        player = new CharacterClass("Warrior", "Hero", 100, 50, 15, 1, 0);
        // MonsterStats(name, hp, damage, xp, gold, boss)
        monster = new MonsterStats("Goblin", 50, 10, 20, 5, false);
        combat = new Combat(player, monster);

        // g_playerCurrentHP 동기화 (전투 시스템에서 사용하므로 필요)
        g_playerCurrentHP = player->getBaseHealth(); 
    }

    void TearDown() override {
        // 테스트 종료 후 실행: 메모리 해제
        delete combat;
        delete monster;
        delete player;
    }
};

// -------------------------------------------------------------
// 기본 전투 로직 테스트
// -------------------------------------------------------------

TEST_F(CombatTests, InitialStateIsCorrect) {
    ASSERT_EQ(combat->getPlayerHP(), 100);
    ASSERT_EQ(combat->getMonsterHP(), 50);
    ASSERT_FALSE(combat->isPlayerDead());
    ASSERT_FALSE(combat->isMonsterDead());
}

TEST_F(CombatTests, PlayerDealsDamageWithBasicAttack) {
    // Slash 스킬 (index 0, Dmg 15) 사용
    // 플레이어 힘 15 -> 추가 피해 7.5 -> 총 피해 22
    combat->playerAttack(0); 

    // 몬스터 HP 50 -> 28
    EXPECT_EQ(combat->getMonsterHP(), 28);
    EXPECT_FALSE(combat->isMonsterDead());
}

TEST_F(CombatTests, MonsterDealsDamageToPlayer) {
    // 몬스터 기본 공격력 10
    combat->monsterAttack(); 

    // 플레이어 HP 100 -> 90 (g_playerCurrentHP도 90으로 업데이트됨)
    EXPECT_EQ(g_playerCurrentHP, 90); 
    EXPECT_FALSE(combat->isPlayerDead());
}

TEST_F(CombatTests, PlayerDefendsReducesDamage) {
    combat->playerDefend(); // 방어 활성화
    combat->monsterAttack(); // 몬스터 공격 (40% 피해 감소 적용)

    // 몬스터 공격력 10 * 0.4 = 4 피해
    // 플레이어 HP 100 -> 96
    EXPECT_EQ(g_playerCurrentHP, 96);
}

TEST_F(CombatTests, MonsterDeathCondition) {
    // 몬스터 HP를 1로 설정
    monster->setCurrentHP(1); 
    
    // Slash 공격으로 마무리
    combat->playerAttack(0); // 피해 22

    EXPECT_TRUE(combat->isMonsterDead());
    EXPECT_EQ(combat->getMonsterHP(), -21); // 1 - 22 = -21
}

// -------------------------------------------------------------
// 상태 이상 및 버프 테스트
// -------------------------------------------------------------

TEST_F(CombatTests, ApplyBurnStatusToMonster) {
    // Fireball 스킬 (Mage 스킬이지만 Warrior가 사용한다고 가정, 혹은 Combat::playerAttack 수정 필요)
    // 현재 Combat::playerAttack은 플레이어 클래스에 따라 스킬 가져옴.
    // 테스트 단순화를 위해 applyStatus 함수 직접 호출

    // 몬스터에게 BURN 적용 (스택 1)
    combat->applyStatus(nullptr, BURN); 
    
    // 상태 데미지 적용
    combat->applyStatusDamage(); // BURN 1스택당 7 데미지

    EXPECT_EQ(combat->getMonsterHP(), 43); // 50 - 7 = 43
}

TEST_F(CombatTests, ApplyDefenseBuffToPlayer) {
    // Iron Will 스킬 (Warrior index 3, Effect: Defense Up 50% 3턴)
    combat->playerAttack(3); 
    
    // 이 스킬은 몬스터 턴 스킵 로직이 있지만, 여기선 피해 감소만 확인
    
    // 몬스터 공격력 10
    combat->monsterAttack(); 

    // 50% 피해 감소 적용: 10 * 0.5 = 5 피해
    EXPECT_EQ(g_playerCurrentHP, 95); // 100 - 5 = 95

    // 지속 시간 감소 확인
    combat->updateDurations();
    combat->monsterAttack(); // 2번째 턴에도 버프 유지

    EXPECT_EQ(g_playerCurrentHP, 90); // 95 - 5 = 90
}
