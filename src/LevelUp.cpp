#include "LevelUp.hpp"
#include <iostream>
#include <algorithm> // std::min 사용
#include "MonsterStats.hpp" 

using namespace std;

// CharacterClass를 수정할 수 없으므로, XP 관리를 위한 전역 변수를 '정의'합니다.
int g_currentXP = 0;
// 현재 체력 전역 변수를 여기서 '정의'합니다 (링커 오류 해결).
int g_playerCurrentHP = 0; 


// 플레이어 레벨에 따라 현재 스테이지를 결정하는 함수 구현
Stage getStageFromPlayerLevel(int playerLevel) {
    int stageIndex = (playerLevel - 1) / 10; 
    if (stageIndex >= static_cast<int>(BOSS)) { return BOSS; }
    if (stageIndex < 0) { return STAGE1; }
    return static_cast<Stage>(stageIndex);
}

// 다음 레벨업에 필요한 XP 계산 구현
int getRequiredXPForNextLevel(int currentLevel) {
    return currentLevel * 100; 
}

// 레벨에 따른 고정 최대 체력을 계산하는 함수 구현
int calculateMaxHealthByLevel(int playerLevel) {
    return 90 + (playerLevel * 10); 
}

// 레벨에 따른 고정 최대 마나를 계산하는 함수 구현
int calculateMaxManaByLevel(int playerLevel) {
    return 45 + (playerLevel * 5); 
}


// 게임 시작 또는 레벨업 후 플레이어의 현재 스탯을 초기화/동기화하는 함수
void initializePlayerStats(CharacterClass* player) {
    int maxHP = calculateMaxHealthByLevel(player->getBaseLevel());
    int maxMP = calculateMaxManaByLevel(player->getBaseLevel());

    // CharacterClass의 baseHealth/baseMana (최대값 역할)를 설정
    player->setBaseHealth(maxHP);
    player->setBaseMana(maxMP);

    // 전역 변수인 현재 체력/마나를 최대값으로 설정
    g_playerCurrentHP = maxHP;
    // g_playerCurrentMP = maxMP; // 마나 동기화도 필요하다면 여기서 처리
}


// 경험치 추가 및 레벨업 체크 함수
void grantExperienceAndCheckLevelUp(CharacterClass* player, int xpGained){
    g_currentXP += xpGained; 
    cout << player->getName() << " gained " << xpGained << " experience points!\n";

    int requiredXP = getRequiredXPForNextLevel(player->getBaseLevel());

    while (g_currentXP >= requiredXP){
        // 레벨업 처리: baseLevel만 먼저 증가시킵니다.
        player->setBaseLevel(player->getBaseLevel()+1);

        // [수정] 스탯 업데이트 및 현재 체력 동기화를 전용 함수로 처리
        initializePlayerStats(player);
        
        cout << player->getName() << " leveled up to " << player->getBaseLevel() << "!\n";
        
        requiredXP = getRequiredXPForNextLevel(player->getBaseLevel());
    }

    cout << "Current XP: " << g_currentXP << " / " << requiredXP << "\n";
}

// 테스트를 위해 현재 XP를 반환하는 함수 (선택사항, 사용하지 않으면 경고 무시 가능)
int getCurrentXP() {
    return g_currentXP;
}

// 스테이지 시작 메시지 출력 함수 (선택사항, 사용하지 않으면 경고 무시 가능)
void displayStageStartMessage(Stage stage, const std::string& monsterName) {
    // 구현 내용 추가 필요
    cout << "--- Stage Start: Encountering " << monsterName << " ---\n";
}
