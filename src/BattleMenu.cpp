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
#include <stdexcept> 

#include "../header/CharacterClass.hpp" 
#include "../header/Skill.hpp" 
#include "../header/Items.hpp"
#include "../header/LevelUp.hpp" 
#include "CharacterSelectMenu.hpp" 


// Default Constructor: Initializes combat using the static player pointer.
BattleMenu::BattleMenu() : combat(CharacterSelectMenu::player, new MonsterStats()) {
    // Monster needs to be set separately or within startEncounter if needed.
}


// Helper function to get the string name of a status effect type.
std::string getStatusName(StatusEffectType status) {
    switch (status) {
        case NONE: return ""; // Not displayed on screen
        case BURN: return "BURN";
        case POISON: return "POISON";
        case FREEZE: return "FREEZE";
        case PARALYSIS: return "PARALYSIS";
        case DOOM: return "DOOM";
        default: return "UNKNOWN";
    }
}

// Displays current combat status (HP, MP, Monster HP/Damage).
void BattleMenu::displayMenu() const {
    std::cout << "\n--- Turn Start ---\n";
    std::cout << combat.getPlayerName() << " HP: " << CharacterSelectMenu::player->getBaseHealth() 
         << "/" << calculateMaxHealthByLevel(CharacterSelectMenu::player) 
         << " | MP: " << combat.getPlayerMana() << "/" << CharacterSelectMenu::player->getBaseMana()
         << "\n" << combat.getMonsterName() << " HP: " << combat.getMonsterHP() << "/" << combat.monster->getMaxHP()
         << " | Damage: " << combat.monster->getDamage() << std::endl;
    std::cout << "----------------------------------------\n"; 
}

// Handles the selection of a specific menu option (e.g., Run).
void BattleMenu::chooseOption(int option) {
    switch (option) {
        case 4: // Run
            std::cout << "Do you want to run away? (y/n): ";
            char confirm;
            std::cin >> confirm;
            if (confirm == 'y' || confirm == 'Y') {
                if (rand() % 2 == 0) {
                    std::cout << combat.getPlayerName() << " successfully ran away!\n";
                    fledSuccessfully = true; 
                } else {
                    std::cout << combat.getPlayerName() << " failed to run away!\n";
                }
            }
            break;
        default:
            break;
    }
}

// The main loop controlling the battle encounter logic.
void BattleMenu::startEncounter(Room* newRoom) {
    std::cout << "Battle started!\n";

    std::vector<Skill> skills;
    if (CharacterSelectMenu::player->getClassType() == "Warrior") { skills = Skill::getWarriorSkills(); }
    else if (CharacterSelectMenu::player->getClassType() == "Mage") { skills = Skill::getMageSkills(); }
    else if (CharacterSelectMenu::player->getClassType() == "Assassin") { skills = Skill::getAssassinSkills(); }
    else { skills = Skill::getWarriorSkills(); } // Default case
    // Main battle loop
    while(!combat.isMonsterDead() && !combat.isPlayerDead() && !fledSuccessfully) {

        combat.applyStatusDamage(); 

        if (combat.isMonsterDead() || combat.isPlayerDead() || fledSuccessfully) {
            break; 
        }

        displayMenu();
        
        bool turnSpent = false;

        // Player turn loop
        while (!turnSpent && !fledSuccessfully) {
            std::cout << "Choose your action:\n";
            std::cout << "1. Attack\n";
            std::cout << "2. Use Item\n";
            std::cout << "3. Stats\n";
            std::cout << "4. Run\n";
            std::cout << "----------------------------------------\n"; 

            int choice;
            std::cout << "Enter choice: ";
            if (!(std::cin >> choice)) {
                std::cout << "Invalid input. Please enter a valid number.\n";
                std::cin.clear(); 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                if (choice == 1) {
                    std::cout << "Select a skill:\n";
                    for (size_t i = 0; i < skills.size(); ++i) { 
                       // Skill display logic here (removed verbose comments)
                    }
                    int skillChoice;
                    std::cout << "Enter skill choice: ";
                     if (!(std::cin >> skillChoice)) {
                         std::cout << "Invalid input. Please enter a valid number.\n";
                         std::cin.clear(); 
                         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    } else if (skillChoice >= 1 && skillChoice <= skills.size()) {
                        combat.playerAttack(skillChoice - 1);
                        turnSpent = true; 
                    } else {
                        std::cout << "Invalid skill choice. Please choose again (Turn not spent).\n";
                    }
                } else if (choice == 2) {
                    const std::vector<std::string>& inventory = CharacterSelectMenu::player->getInventory();
                    int itemIndex = inventory.size() + 1;
                    if (inventory.empty()) {
                        std::cout << "Inventory is empty! (Turn not spent).\n";
                    } else {
                        // Inventory display logic here (removed verbose comments)
                        
                        int itemChoice;
                        std::cout << "Enter item choice: ";
                        if (!(std::cin >> itemChoice)) {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Invalid input. Please enter a valid number.\n";
                        } else if (itemChoice >= 1 && itemChoice <= inventory.size()) {
                            std::string selectedItem = inventory[itemChoice - 1];  
                            Item* item = getItemByName(selectedItem);
                            if (item) {
                                std::cout << "Using " << selectedItem << " as a consumable!\n";
                            }
                            if (item) {
                                int oldHP = CharacterSelectMenu::player->getBaseHealth();
                                int oldMP = CharacterSelectMenu::player->getBaseMana(); 
                                int oldStr = CharacterSelectMenu::player->getBaseStrength();
            
                                Item itemToUse = *item;
                                itemToUse.amount = 1;
            
                                CharacterSelectMenu::player->useItem(itemToUse);
            
                                int hpDiff = CharacterSelectMenu::player->getBaseHealth() - oldHP;
                                int mpDiff = CharacterSelectMenu::player->getBaseMana() - oldMP; 
                                int strDiff = CharacterSelectMenu::player->getBaseStrength() - oldStr;
            
                                if (hpDiff > 0) { std::cout << combat.getPlayerName() << " restored " << hpDiff << " HP!\n"; }
                                if (mpDiff > 0) { std::cout << combat.getPlayerName() << " restored " << mpDiff << " MP!\n"; }
                                if (strDiff > 0) { std::cout << combat.getPlayerName() << "'s strength increased by " << strDiff << "!\n"; }
            
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
                    CharacterSelectMenu::player->displayClassInfo();
                    std::cout << "----------------------------------------\n"; 
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
                std::cout << combat.getPlayerName() << " HP is now: " << CharacterSelectMenu::player->getBaseHealth() 
                          << "/" << calculateMaxHealthByLevel(CharacterSelectMenu::player) << std::endl;
            } else {
                std::cout << CharacterSelectMenu::player->getName() << " is paralyzed and cannot attack this turn!\n";
            }
        }
        std::cout << "----------------------------------------\n"; 
        combat.updateDurations();
    }
    
    returnToMap();
} 

// Prints a final message upon exiting the battle menu system.
void BattleMenu::returnToMap() {
    std::cout << "Returning to the main map/previous room from BattleMenu. [FINAL]\n";
}
