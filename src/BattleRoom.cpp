#include "BattleRoom.hpp"
#include "CharacterClass.h"
#include "CharacterStatsMenu.hpp"
#include <iostream>
#include <algorithm>

BattleRoom::BattleRoom(CharacterStats& stats, MonsterStats m, CharacterClass& cls)
    : playerStats(stats), monster(m), playerClass(cls) {}

void BattleRoom::applyEquipment(){
    for(const auto& item : playerClass.getInventory()){
        if(item.find("Sword") != std::string::npos)
            playerStats.attack += 5;
        else if(item.find("Armor") != std::string::npos)
            playerStats.defense += 3;
    }
}

void BattleRoom::useItem(const std::string& itemName){
    if(itemName == "Bandage")
        playerStats.currentHP += 10;
    else if(itemName == "Health Potion")
        playerStats.currentHP += 30;

    if(playerStats.currentHP > playerClass.getBaseHealth())
        playerStats.currentHP = playerClass.getBaseHealth();

    playerClass.removeItem(itemName);
}

void BattleRoom::startBattle(){
    applyEquipment();
    std::cout << "Battle started with " << monster.getName() << "!\n";

    while(!monster.isDead() && !playerStats.isDead()){
        CharacterStatsMenu::showStats(playerStats);
        std::cout << "Choose action: 1.Attack 2.Use Item 3.Run\n";
        int choice;
        std::cin >> choice;

        if(choice == 1){
            int dmg = std::max(0, playerStats.attack - monster.getDamage()/2);
            monster.takeDamage(dmg);
            std::cout << "You dealt " << dmg << " damage!\n";
        }
        else if(choice == 2){
            const auto& inv = playerClass.getInventory();
            if(inv.empty()){ std::cout << "Inventory empty!\n"; continue; }
            std::cout << "Inventory:\n";
            for(int i=0;i<inv.size();i++)
                std::cout << i+1 << ". " << inv[i] << "\n";
            int itemChoice;
            std::cin >> itemChoice;
            if(itemChoice>0 && itemChoice<=inv.size())
                useItem(inv[itemChoice-1]);
        }
        else{
            std::cout << "You ran away!\n";
            return;
        }

        if(!monster.isDead())
            monster.attack(playerStats);
    }

    if(monster.isDead()){
        std::cout << monster.getName() << " defeated! Gained " << monster.getXPReward() << " XP.\n";
        playerStats.gainXP(monster.getXPReward());
        CharacterStatsMenu::showStats(playerStats);
    }
}
