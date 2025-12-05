#include "LevelUp.hpp"
#include <iostream>
#include <algorithm> // For std::max
#include "MonsterStats.hpp" 
#include "CharacterClass.hpp" 

using namespace std;

int g_currentXP = 0;


Stage getStageFromPlayerLevel(CharacterClass* player) {
    int playerLevel = player->getBaseLevel();
    int stageIndex = (playerLevel - 1) / 10; 
    if (stageIndex >= static_cast<int>(BOSS)) { return BOSS; }
    if (stageIndex < 0) { return STAGE1; }
    return static_cast<Stage>(stageIndex);
}

int getRequiredXPForNextLevel(CharacterClass* player) {
    return player->getBaseLevel() * 100; 
}


// Calculate the maximum possible health value for a given level
int calculateMaxHealthByLevel(CharacterClass* player) {
    int playerLevel = player->getBaseLevel();
    // Formula based on previous test results (e.g., Lvl 1 = 100, Lvl 10 = 190)
    return 90 + (playerLevel * 10); 
}

// Calculate max mana by level
int calculateMaxManaByLevel(CharacterClass* player) {
    int playerLevel = player->getBaseLevel();
    // Formula based on previous test results (e.g., Lvl 1 = 50, Lvl 10 = 95)
    return 45 + (playerLevel * 5); 
}

// Calculate strength stat by level
int calculateStrengthByLevel(CharacterClass* player) {
    int playerLevel = player->getBaseLevel();
    // Formula based on previous test results (e.g., Lvl 1 = 15, Lvl 10 = 60)
    return 10 + (playerLevel * 5); 
}
// ---------------------------------------------------------------------


// --- 3. Player stats initialization function (set Current HP/MP/Strength) ---
void initializePlayerStats(CharacterClass* player) {
    // 함수 시그니처는 이미 player*를 받으므로 변경 없음

    // Calculate new current stats based on player's level
    int newHealth = calculateMaxHealthByLevel(player);
    int newMana = calculateMaxManaByLevel(player);
    int newStrength = calculateStrengthByLevel(player);

    player->setBaseHealth(newHealth); // Set the current Health
    player->setBaseMana(newMana);   // Set the current Mana
    player->setBaseStrength(newStrength); // Set the current Strength
}


void grantExperienceAndCheckLevelUp(CharacterClass* player, int xpGained){
    g_currentXP += xpGained; 
    cout << player->getName() << " gained " << xpGained << " experience points!\n";

    int requiredXP = getRequiredXPForNextLevel(player); 

    while (g_currentXP >= requiredXP){
        player->setBaseLevel(player->getBaseLevel()+1);
        // Update stats to new level's max stats
        initializePlayerStats(player); 
        
        cout << player->getName() << " leveled up to " << player->getBaseLevel() << "!\n";
        
        // Fix: Use this for XP carry-over to enable multiple level ups in one go
        g_currentXP -= requiredXP; 
        
        requiredXP = getRequiredXPForNextLevel(player); 
    }

    cout << "Current XP: " << g_currentXP << " / " << requiredXP << "\n";
}

int getCurrentXP() {
    return g_currentXP;
}

void displayStageStartMessage(Stage stage, const std::string& monsterName) {
    // 이 함수는 Stage enum과 monsterName만 사용하므로 변경 없음
    cout << "--- Stage Start: Encountering " << monsterName << " ---\n";
}
