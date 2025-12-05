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
BattleMenu::BattleMenu() : combat(CharacterSelectMenu::player, nullptr) {}

std::string getStatusName(StatusEffectType status) {
    switch (status) {
        case NONE: return ""; 
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
    std::cout << combat.getPlayerName() << " HP: " << CharacterSelectMenu::player->getBaseHealth() 
         << "/" << calculateMaxHealthByLevel(CharacterSelectMenu::player) 
         << " | MP: " << combat.getPlayerMana() << "/" << CharacterSelectMenu::player->getBaseMana()
         << "\n" << combat.getMonsterName() << " HP: " << combat.getMonsterHP() << "/" << combat.monster->getMaxHP()
         << " | Damage: " << combat.monster->getDamage() << std::endl;
    std::cout << "----------------------------------------\n"; 
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

void BattleMenu::startEncounter(Room* newRoom) {
    std::cout << "Battle started!\n";

    // Dynamically create the monster when the encounter starts.
    delete combat.monster; 
    combat.monster = MonsterStats::createRandomMonster(STAGE1).release(); 
    
    if (combat.monster == nullptr) {
        std::cerr << "Error: Failed to create a monster for the encounter!" << std::endl;
        return; 
    }

    std::vector<Skill> skills;
    if (CharacterSelectMenu::player->getClassType() == "Warrior") { skills = Skill::getWarriorSkills(); }
    else if (CharacterSelectMenu::player->getClassType() == "Mage") { skills = Skill::getMageSkills(); }
    else if (CharacterSelectMenu::player->getClassType() == "Assassin") { skills = Skill::getAssassinSkills(); }
    else { skills = Skill::getWarriorSkills(); } 

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
                    // Attack menu
                    while(!turnSpent) {
                        std::cout << "Select a skill:\n";
                        for (size_t i = 0; i < skills.size(); ++i) { 
                            std::cout << i + 1 << ". " << skills[i].getName() 
                                << " (Dmg: " << skills[i].getDamage() 
                                << ", Mana: " << skills[i].getManaCost();
                            
                            std::string statusName = getStatusName(skills[i].getStatus());
                            if (!statusName.empty()) {
                                std::cout << ", Status: " << statusName;
                            }

                            if (skills[i].getEffect() == EFFECT_PLAYER_DEFENSE_UP) {
                                std::cout << ", Effect: Defense Up (" << skills[i].getEffectDuration() << " turns)";
                            }

                            std::cout << ")\n";
                        }
                        std::cout << skills.size() + 1 << ". Back\n"; // Back option

                        int skillChoice;
                        std::cout << "Enter skill choice: ";
                         if (!(std::cin >> skillChoice)) {
                             std::cout << "Invalid input. Please enter a valid number.\n";
                             std::cin.clear(); 
                             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        } else if (skillChoice >= 1 && skillChoice <= skills.size()) {
                            combat.playerAttack(skillChoice - 1);
                            turnSpent = true; 
                        } else if (skillChoice == skills.size() + 1) {
                            break; // Exit skill menu loop, return to main action menu
                        } else {
                            std::cout << "Invalid skill choice. Please choose again.\n";
                        }
                    }
                } else if (choice == 2) {
                    // Item menu
                    const std::vector<std::string>& inventory = CharacterSelectMenu::player->getInventory();
                    
                    while(!turnSpent) {
                        if (inventory.empty()) {
                            std::cout << "Inventory is empty!\n";
                            break; // Exit item menu loop if empty
                        }
                        
                        std::cout << "Inventory:\n";
                        for (size_t i = 0; i < inventory.size(); i++) {
                            std::cout << i + 1 << ". " << inventory[i] << "\n";
                        }
                        std::cout << inventory.size() + 1 << ". Back\n"; // Back option
                        std::cout << "----------------------------------------\n"; 

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
                        } else if (itemChoice == inventory.size() + 1) {
                             break; // Exit item menu loop, return to main action menu
                        } else {
                            std::cout << "Invalid choice.\n";
                        }
                    }
                }
                if (choice == 3) {
                    CharacterSelectMenu::player->displayClassInfo();
                    std::cout << "----------------------------------------\n"; 
                } else if (choice == 4) {
                    chooseOption(choice); 
                } else {
                    std::cout << "Invalid choice. Please choose again.\n";
                }
            }
        }

        // Monster attack phase
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

    // Clean up dynamically allocated monster memory after the battle ends.
    delete combat.monster;
    combat.monster = nullptr; 
} 

void BattleMenu::returnToMap() {
    std::cout << "Returning to the main map/previous room from BattleMenu. [FINAL]\n";
}
