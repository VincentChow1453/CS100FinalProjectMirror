#ifndef LEVELUP_HPP
#define LEVELUP_HPP

#include "CharacterClass.h"
#include "MonsterStats.hpp" // For accessing the Stage enum

// Function to determine the current stage based on player level
Stage getStageFromPlayerLevel(int playerLevel);

// Function to grant experience points and check for level ups (global XP management due to CharacterClass constraints)
void grantExperienceAndCheckLevelUp(CharacterClass* player, int xpGained);

// Function to display the stage start message
//void displayStageStartMessage(Stage stage, const std::string& monsterName); // Not defined in provided cpp

// Function to return the current XP (optional)
//int getCurrentXP(); // Not defined in provided cpp

// Function to return the required XP for the next level (optional)
int getRequiredXPForNextLevel(int currentLevel);

// [Added] Function to initialize/synchronize player's current stats after game start or level up
void initializePlayerStats(CharacterClass* player);

// Implementation to calculate fixed max health based on level
int calculateMaxHealthByLevel(int playerLevel);

// Implementation to calculate fixed max mana based on level
int calculateMaxManaByLevel(int playerLevel);

#endif
