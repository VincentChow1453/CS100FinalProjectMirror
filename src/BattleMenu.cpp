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
#include <stdexcept> // Added for exception handling

#include "../header/CharacterClass.hpp" 
#include "../header/Skill.hpp" 
#include "../header/Items.hpp"
#include "../header/LevelUp.hpp" // Include LevelUp functions for max stat calculation


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
    // Use player->getBaseHealth() for current health
    std::cout << combat.getPlayerName() << " HP: " << combat.player->getBaseHealth() << "/" << combat.player->getBaseHealth()
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

    // --- Stats Initialization Logic (As requested, using character's current state) ---
    // Note: The character enters battle with stats set in CharacterSelectMenu/LevelUp system.
    // We do not force a reset here.
    // ----------------------------------------------------------------------------------
    
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
                    const std::vector<std::string> Inventory = combat.player->getInventory();
                    if (Inventory.empty()) {
                        std::cout << "Inventory is empty! (Turn not spent).\n";
                    } else {
                        std::map<std::string, int> itemCounts;
                        for (std::vector<std::string>::const_iterator it = Inventory.begin(); it != Inventory.end(); ++it) {
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
                            
                            // --- Use LevelUp functions to calculate max stats for item healing limit ---
                            int maxHP = calculateMaxHealthByLevel(combat.player);
                            int maxMP = calculateMaxManaByLevel(combat.player);

                            if (selectedItem == "Bandage") {
                                int healAmount = 20;
                                int newHP = std::min(combat.player->getBaseHealth() + healAmount, maxHP); 
                                combat.player->setBaseHealth(newHP); 
                                std::cout << combat.getPlayerName() << " restored " << healAmount << " HP!\n";
                                combat.player->removeItem(selectedItem);
                                turnSpent = true; 
                            } else if (selectedItem == "Health Potion") {
                                int healAmount = 50;
                                int newHP = std::min(combat.player->getBaseHealth() + healAmount, maxHP); 
                                combat.player->setBaseHealth(newHP); 
                                std::cout << combat.getPlayerName() << " restored " << healAmount << " HP!\n";
                                combat.player->removeItem(selectedItem);
                                turnSpent = true; 
                            } else if (selectedItem == "Apple") {
                                int manaAmount = 15;
                                int newMana = std::min(combat.getPlayerMana() + manaAmount, maxMP);
                                combat.player->setBaseMana(newMana);
                                combat.player->removeItem(selectedItem);
                                turnSpent = true; 
                            } else if (selectedItem == "Protein Bar") {
                                int manaAmount = 40;
                                int newMana = std::min(combat.getPlayerMana() + manaAmount, maxMP);
                                combat.player->setBaseMana(newMana);
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
                // HP update is handled within monsterAttack via setBaseHealth()
                std::cout << combat.getPlayerName() << " HP is now: " << combat.player->getBaseHealth() << "/" << combat.player->getBaseHealth() << std::endl;
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
