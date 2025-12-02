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

#include "../header/CharacterClass.h" 
#include "../header/Skill.hpp" 
#include "../header/Items.hpp" 

// Extern declaration for the current HP global variable defined in main.cpp/LevelUp.cpp
extern int g_playerCurrentHP; 

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

void BattleMenu::displayMenu() const {
    std::cout << "\n--- Turn Start ---\n";
    // Use g_playerCurrentHP for current health, player->getBaseHealth() for max health
    std::cout << combat.getPlayerName() << " HP: " << g_playerCurrentHP << "/" << combat.player->getBaseHealth()
         << " | MP: " << combat.getPlayerMana() << "/" << combat.player->getBaseMana()
         << "\n" << combat.getMonsterName() << " HP: " << combat.getMonsterHP() << "/" << combat.monster->getMaxHP()
         << " | Damage: " << combat.monster->getDamage() << std::endl;
    std::cout << "----------------------------------------\n"; // Divider line
}

void BattleMenu::chooseOption(int option) {
    switch (option) {
        case 4: // Run
            std::cout << "Do you want to run away? (y/n): ";
            char confirm;
            std::cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                if (rand() % 2 == 0) {
                    std::cout << combat.getPlayerName() << " successfully ran away!\n";
                    // g_playerCurrentHP = 0; // !! This line was removed to prevent instant Game Over !!
                    fledSuccessfully = true; // Set the flag instead
                } else {
                    std::cout << combat.getPlayerName() << " failed to run away!\n";
                }
            }
            break;
        default:
            break;
    }
}

void BattleMenu::startEncounter(Room* newRoom) {
    std::cout << "Battle started!\n";
    
    std::vector<Skill> skills;
    if (combat.player->getClassType() == "Warrior") { skills = Skill::getWarriorSkills(); }
    else if (combat.player->getClassType() == "Mage") { skills = Skill::getMageSkills(); }
    else if (combat.player->getClassType() == "Assassin") { skills = Skill::getAssassinSkills(); }
    else { skills = Skill::getWarriorSkills(); }

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
                std::cin.clear();
                while (std::cin.get() != '\n'); 
            } else {
                if (choice == 1) {
                    std::cout << "Select a skill:\n";
                    for (size_t i = 0; i < skills.size(); ++i) {
                        std::cout << i + 1 << ". " << skills[i].getName() 
                             << " (Dmg: " << skills[i].getDamage() 
                             << ", Mana: " << skills[i].getManaCost();
                        
                        // Display status effect if not NONE
                        std::string statusName = getStatusName(skills[i].getStatus());
                        if (!statusName.empty()) {
                            std::cout << ", Status: " << statusName;
                        }

                        // Display special effects (like Iron Will)
                        if (skills[i].getEffect() == EFFECT_PLAYER_DEFENSE_UP) {
                            std::cout << ", Effect: Defense Up (" << skills[i].getEffectDuration() << " turns)";
                        }

                        std::cout << ")\n";
                    }
                    int skillChoice;
                    std::cout << "Enter skill choice: ";
                     if (!(std::cin >> skillChoice)) {
                         std::cout << "Invalid input. Please enter a valid number.\n";
                         std::cin.clear();
                         while (std::cin.get() != '\n');
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
                    if (inventory.empty()) {
                        std::cout << "Inventory is empty! (Turn not spent).\n";
                    } else {
                        std::map<std::string, int> itemCounts;
                        for (std::vector<std::string>::const_iterator it = inventory.begin(); it != inventory.end(); ++it) {
                             itemCounts[*it]++;
                        }
                        std::vector<std::string> uniqueItems;
                        std::cout << "Inventory:\n";
                        int itemIndex = 1;
                        for (std::map<std::string, int>::const_iterator it = itemCounts.begin(); it != itemCounts.end(); ++it) {
                            uniqueItems.push_back(it->first);
                            std::cout << itemIndex++ << ". " << it->first << " x" << it->second << "\n";
                        }
                        std::cout << itemIndex << ". Back to main menu\n";
                        std::cout << "----------------------------------------\n"; // Divider line

                        int itemChoice;
                        std::cout << "Enter item choice: ";
                        if (!(std::cin >> itemChoice)) {
                            std::cout << "Invalid input. Please enter a valid number.\n";
                            std::cin.clear();
                            while (std::cin.get() != '\n');
                        } else if (itemChoice >= 1 && itemChoice < itemIndex) {
                            std::string selectedItem = uniqueItems[itemChoice - 1];
                            
                            std::cout << "Using " << selectedItem << " as a consumable!\n";
                            
                            if (selectedItem == "Bandage") {
                                int healAmount = 20;
                                g_playerCurrentHP = std::min(g_playerCurrentHP + healAmount, combat.player->getBaseHealth()); 
                                std::cout << combat.getPlayerName() << " restored " << healAmount << " HP!\n";
                                combat.player->removeItem(selectedItem);
                                turnSpent = true; 
                            } else if (selectedItem == "Health Potion") {
                                int healAmount = 50;
                                g_playerCurrentHP = std::min(g_playerCurrentHP + healAmount, combat.player->getBaseHealth()); 
                                std::cout << combat.getPlayerName() << " restored " << healAmount << " HP!\n";
                                combat.player->removeItem(selectedItem);
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
                } else if (choice == 3) {
                    combat.player->displayClassInfo();
                    std::cout << "----------------------------------------\n"; // Divider line
                } else if (choice == 4) {
                    chooseOption(choice); // This calls the function that sets fledSuccessfully = true if escape succeeds
                    // If escape is successful, the outer while loop condition handles breaking the loop next iteration.
                } else {
                    std::cout << "Invalid choice. Please choose again (Turn not spent).\n";
                }
            }
        }
        
        // Monster attack phase: only proceeds if no one is dead and player hasn't fled
        if(!combat.isMonsterDead() && !combat.isPlayerDead() && !fledSuccessfully) {
            if (!combat.isPlayerParalyzed()) { 
                combat.monsterAttack();
                // g_playerCurrentHP is updated inside monsterAttack
                std::cout << combat.getPlayerName() << " HP is now: " << g_playerCurrentHP << "/" << combat.player->getBaseHealth() << std::endl;
            } else {
                std::cout << combat.getPlayerName() << " is paralyzed and cannot attack this turn!\n";
            }
        }
        std::cout << "----------------------------------------\n"; // Divider line
        combat.updateDurations();
    }
    
    returnToMap();
}

void BattleMenu::returnToMap() {
    std::cout << "Returning to the main map/previous room from BattleMenu. [FINAL]\n";
}
