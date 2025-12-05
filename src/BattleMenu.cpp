#include "BattleMenu.hpp"
#include <iostream>
#include <limits> 
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <algorithm> 
#include <string> 
#include <cstdio> 
#include <stdexcept> // For exception handling

#include "../header/CharacterClass.hpp" 
#include "../header/Skill.hpp" 
#include "../header/Items.hpp"
#include "../header/LevelUp.hpp" // Include LevelUp functions for max stat calculation


// --- 기본 생성자 구현 (링커 오류 해결) ---
// Combat 클래스가 CharacterClass* 및 MonsterStats*를 nullptr로 초기화할 수 있다고 가정합니다.
BattleMenu::BattleMenu() : combat(nullptr, nullptr) {
    // 필요한 경우 여기에 추가 초기화 로직을 배치합니다.
}
// ----------------------------------------


/**
 * @brief Helper function to get the string name of a status effect type.
 * @param status The StatusEffectType enum value.
 * @return The string representation of the status effect.
 */
std::string getStatusName(StatusEffectType status) {
    switch (status) {
        case NONE: return ""; // Return empty string for NONE (not displayed on screen)
        case BURN: return "BURN";
        case POISON: return "POISON";
        case FREEZE: return "FREEZE";
        case PARALYSIS: return "PARALYSIS";
        case DOOM: return "DOOM";
        default: return "UNKNOWN";
    }
}

/**
 * @brief Displays the current combat status (HP, MP, Monster HP/Damage) at the start of a turn.
 */
void BattleMenu::displayMenu() const {
    std::cout << "\n--- Turn Start ---\n";
    // Use calculateMaxHealthByLevel for player's max health calculation
    std::cout << combat.getPlayerName() << " HP: " << combat.player->getBaseHealth() 
         << "/" << calculateMaxHealthByLevel(combat.player) // Using helper function to get Max HP
         << " | MP: " << combat.getPlayerMana() << "/" << combat.player->getBaseMana()
         << "\n" << combat.getMonsterName() << " HP: " << combat.getMonsterHP() << "/" << combat.monster->getMaxHP()
         << " | Damage: " << combat.monster->getDamage() << std::endl;
    std::cout << "----------------------------------------\n"; // Divider line
}

/**
 * @brief Handles the selection of a specific menu option (e.g., Run).
 * @param option The chosen menu option ID.
 */
void BattleMenu::chooseOption(int option) {
    switch (option) {
        case 4: // Run
            std::cout << "Do you want to run away? (y/n): ";
            char confirm;
            std::cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                if (rand() % 2 == 0) {
                    std::cout << combat.getPlayerName() << " successfully ran away!\n";
                    fledSuccessfully = true; // Set the flag instead
                } else {
                    std::cout << combat.getPlayerName() << " failed to run away!\n";
                }
            }
            break;
        default:
            // Other options might be handled in the main loop switch
            break;
    }
}

/**
 * @brief The main loop controlling the battle encounter logic.
 * @param newRoom Pointer to the current room (used for context).
 */
void BattleMenu::startEncounter(Room* newRoom) {
    std::cout << "Battle started!\n";

    std::vector<Skill> skills;
    if (combat.player->getClassType() == "Warrior") { skills = Skill::getWarriorSkills(); }
    else if (combat.player->getClassType() == "Mage") { skills = Skill::getMageSkills(); }
    else if (combat.player->getClassType() == "Assassin") { skills = Skill::getAssassinSkills(); }
    else { skills = Skill::getWarriorSkills(); } // Default case

    // Main battle loop: continue as long as monster/player is alive AND player hasn't fled
    while(!combat.isMonsterDead() && !combat.isPlayerDead() && !fledSuccessfully) {
        
        combat.applyStatusDamage(); 

        // Re-check conditions after status damage is applied
        if (combat.isMonsterDead() || combat.isPlayerDead() || fledSuccessfully) {
            break; 
        }

        displayMenu();
        
        bool turnSpent = false;

        // Player turn loop: continue until turn is spent OR player flees
        while (!turnSpent && !fledSuccessfully) {
            std::cout << "Choose your action:\n";
            std::cout << "1. Attack\n";
            std::cout << "2. Use Item\n";
            std::cout << "3. Stats\n";
            std::cout << "4. Run\n";
            std::cout << "----------------------------------------\n"; // Divider line

            int choice;
            std::cout << "Enter choice: ";
            if (!(std::cin >> choice)) {
                std::cout << "Invalid input. Please enter a valid number.\n";
                std::cin.clear(); // Fixed std::cin::clear() call
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Use ignore to clear buffer
            } else {
                if (choice == 1) {
                    std::cout << "Select a skill:\n";
                    for (size_t i = 0; i < skills.size(); ++i) {
                        // ... (skill display logic) ...
                    }
                    int skillChoice;
                    std::cout << "Enter skill choice: ";
                     if (!(std::cin >> skillChoice)) {
                         std::cout << "Invalid input. Please enter a valid number.\n";
                         std::cin.clear(); // Fixed std::cin::clear() call
                         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Use ignore to clear buffer
                    } else if (skillChoice >= 1 && skillChoice <= skills.size()) {
                        combat.playerAttack(skillChoice - 1);
                        if (combat.isSkillDefenseBuff(skillChoice - 1)) {
                           // Monster turn skip is handled inside Combat::playerAttack
                        }
                        turnSpent = true; 
                    } else {
                        std::cout << "Invalid skill choice. Please choose again (Turn not spent).\n";
                    }
                } else if (choice == 2) {
                    const std::vector<std::string>& inventory = combat.player->getInventory();
                    int itemIndex = inventory.size() + 1;
                    if (inventory.empty()) {
                        std::cout << "Inventory is empty! (Turn not spent).\n";
                    } else {
                        // ... (inventory display logic) ...

                        int itemChoice;
                        std::cout << "Enter item choice: ";
                        if (!(std::cin >> itemChoice)) {
                            std::cin.clear(); // Fixed std::cin::clear() call
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Invalid input. Please enter a valid number.\n";
                        } else if (itemChoice >= 1 && itemChoice <= inventory.size()) {
                            std::string selectedItem = inventory[itemChoice - 1];  
                        Item* item = getItemByName(selectedItem);
                          if (item) {
                            // ... (item use logic) ...
                          }
                    if (item) {
                        int oldHP = combat.player->getBaseHealth();
                        int oldMP = combat.player->getBaseMana(); 
                        int oldStr = combat.player->getBaseStrength();
    
                        Item itemToUse = *item;
                        itemToUse.amount = 1;
    
                        combat.player->useItem(itemToUse);
    
                        int hpDiff = combat.player->getBaseHealth() - oldHP;
                        int mpDiff = combat.player->getBaseMana() - oldMP; 
                        int strDiff = combat.player->getBaseStrength() - oldStr;
    
                            if (hpDiff > 0) { /* ... */ }
                            if (mpDiff > 0) { /* ... */ }
                            if (strDiff > 0) { /* ... */ }
    
                         turnSpent = true;
                        } else {
                            std::cout << "This item cannot be used in battle! (Turn not spent).\n";
                        }
                        } else if (itemChoice == itemIndex) {
                            std::cout << "Returning to main menu (Turn not spent).\n";
                        } else {
                            std::cout << "Invalid choice (Turn not spent).\n";
                        }
                    }
                }
                if (choice == 3) {
                    combat.player->displayClassInfo();
                    std::cout << "----------------------------------------\n"; // Divider line
                } else if (choice == 4) {
                    chooseOption(choice); 
                } else {
                    std::cout << "Invalid choice. Please choose again (Turn not spent).\n";
                }
            }
        }

        // Monster attack phase: only proceeds if no one is dead and player hasn't fled
        if(!combat.isMonsterDead() && !combat.isPlayerDead() && !fledSuccessfully) {
            if (!combat.isPlayerParalyzed()) { 
                combat.monsterAttack();
                std::cout << combat.getPlayerName() << " HP is now: " << combat.player->getBaseHealth() 
                          << "/" << calculateMaxHealthByLevel(combat.player) << std::endl;
            } else {
                std::cout << combat.getPlayerName() << " is paralyzed and cannot attack this turn!\n";
            }
        }
        std::cout << "----------------------------------------\n"; // Divider line
        combat.updateDurations();
    }
    
    // End of startEncounter function logic
    returnToMap();
} 

/**
 * @brief Prints a final message upon exiting the battle menu system.
 */
void BattleMenu::returnToMap() {
    std::cout << "Returning to the main map/previous room from BattleMenu. [FINAL]\n";
}
