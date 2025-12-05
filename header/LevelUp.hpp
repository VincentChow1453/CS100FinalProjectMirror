#ifndef LEVELUP_HPP
#define LEVELUP_HPP

#include "CharacterClass.hpp"
#include "MonsterStats.hpp" // For accessing the Stage enum
#include <string> 

// Function to determine the current stage based on player level
Stage getStageFromPlayerLevel(CharacterClass* player);

// Function to grant experience points and check for level ups
void grantExperienceAndCheckLevelUp(CharacterClass* player, int xpGained);

// Function to return the required XP for the next level
// int currentLevel 매개변수 대신 CharacterClass* player 매개변수를 사용하도록 수정
int getRequiredXPForNextLevel(CharacterClass* player);

// Function to initialize player's current stats after game start or level up
void initializePlayerStats(CharacterClass* player);


// Implementation to calculate max health based on level
int calculateMaxHealthByLevel(CharacterClass* player);

// Implementation to calculate max mana based on level
int calculateMaxManaByLevel(CharacterClass* player);

// Implementation to calculate strength based on level
int calculateStrengthByLevel(CharacterClass* player);

// Function to return the current XP
int getCurrentXP();

// Function to display the stage start message
void displayStageStartMessage(Stage stage, const std::string& monsterName); 

// ---------------------------

#endif // LEVELUP_HPP
