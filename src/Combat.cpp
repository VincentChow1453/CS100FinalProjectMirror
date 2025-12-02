#include "Combat.hpp" 
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> // For min, max

using namespace std;

Combat::Combat(CharacterClass* p, MonsterStats* m) 
    : player(p), monster(m), playerDefending(false), playerStatus(NONE), monsterStatus(NONE),
      playerBurnStacks(0), playerPoisonStacks(0), monsterBurnStacks(0), monsterPoisonStacks(0),
      freezeDuration(0), playerDefenseBuffDuration(0), playerDefenseBuffValue(0) {}

void Combat::playerAttack(int skillIndex) {
    vector<Skill> skills;
    if (player->getClassType() == "Warrior") { skills = Skill::getWarriorSkills(); }
    else if (player->getClassType() == "Mage") { skills = Skill::getMageSkills(); }
    else if (player->getClassType() == "Assassin") { skills = Skill::getAssassinSkills(); }
    else { skills = Skill::getWarriorSkills(); }

    if (skillIndex >= 0 && skillIndex < skills.size()) {
        Skill selectedSkill = skills[skillIndex];
        // Mana check logic needed (omitted here)

        int baseDmg = selectedSkill.getDamage();
        int totalDmg = baseDmg + (player->getBaseStrength() / 2); 

        // Apply additional effects (buffs)
        if (selectedSkill.getEffect() == EFFECT_PLAYER_DEFENSE_UP) {
            playerDefenseBuffDuration = selectedSkill.getEffectDuration();
            playerDefenseBuffValue = selectedSkill.getEffectValue();
            cout << player->getName() << " casts " << selectedSkill.getName() << "! Defense increased by " << playerDefenseBuffValue << "% for " << playerDefenseBuffDuration << " turns.\n";
            return; // Using a buff skill skips the monster's attack this turn.
        }

        monster->setCurrentHP(monster->getCurrentHP() - totalDmg);
        cout << player->getName() << " uses " << selectedSkill.getName() << " and deals " << totalDmg << " damage to " << monster->getName() << "!\n";
        
        // Apply status effect
        if (selectedSkill.getStatus() != NONE) {
            applyStatus(nullptr, selectedSkill.getStatus()); // Apply to monster
        }
    } else {
        cout << "Invalid skill index.\n";
    }
}

void Combat::monsterAttack() {
    // If frozen, damage is reduced by 40%
    float damageMultiplier = (freezeDuration > 0) ? 0.6f : 1.0f;
    int dmg = static_cast<int>(monster->getDamage() * damageMultiplier);
    
    // Apply player defense buff
    if (playerDefenseBuffDuration > 0) {
        dmg = static_cast<int>(dmg * (1.0f - (playerDefenseBuffValue / 100.0f)));
    }

    dmg = playerDefending ? static_cast<int>(dmg*0.4) : dmg;
    
    // Use try-catch because CharacterClass::setBaseHealth might throw an exception if health goes negative
    try {
        player->setBaseHealth(player->getBaseHealth() - dmg); 
    } catch (const std::invalid_argument& e) {
        std::cerr << "Warning: monsterAttack caught exception: " << e.what() << std::endl;
        player->setBaseHealth(0); // Ensure health is 0 if it would be negative
    }

    cout << monster->getName() << " attacks " << player->getName() << " for " << dmg << " damage!\n";
    playerDefending = false;

    // Apply status effects probabilistically based on monster type
    string mName = monster->getName();
    int chance = rand() % 100;

    if (mName == "Slime" && chance < 80) { // 80% chance POISON
        applyStatus(player, POISON);
    } else if ((mName == "Necromancer" || mName == "Witch") && chance < 50) { // 50% chance BURN
        applyStatus(player, BURN);
    } else if ((mName == "Dark Knight" || mName == "Death Dragon") && chance < 30) { // 30% chance PARALYSIS
        applyStatus(player, PARALYSIS);
    } else if ((mName == "Harpy" || mName == "Minotaur") && chance < 50) { // 50% chance FREEZE
         applyStatus(player, FREEZE);
    }
}

void Combat::playerDefend() {
    playerDefending = true;
    cout << player->getName() << " braces for defense!\n";
}

void Combat::applyStatus(CharacterClass* target, StatusEffectType statusType) {
    bool toPlayer = (target != nullptr);

    if (toPlayer) {
        if (statusType == BURN) playerBurnStacks = min(3, playerBurnStacks + 1);
        else if (statusType == POISON) playerPoisonStacks = min(8, playerPoisonStacks + 1);
        else if (statusType == FREEZE) freezeDuration = 2;
        // else if (statusType == PARALYSIS) { /* Paralysis application logic (requires turn skip) */ }
        
        cout << (toPlayer ? player->getName() : monster->getName()) << " is now affected by status: " << statusType << "!\n";

    } else { // Apply to monster
        if (statusType == BURN) monsterBurnStacks = min(3, monsterBurnStacks + 1);
        else if (statusType == POISON) monsterPoisonStacks = min(8, monsterPoisonStacks + 1);
        
         cout << (toPlayer ? player->getName() : monster->getName()) << " is now affected by status: " << statusType << "!\n";
    }
}

void Combat::applyStatusDamage() {
    // Use try-catch for status damage application as well
    if (playerBurnStacks > 0) {
        int dmg = playerBurnStacks * 7;
        try {
            player->setBaseHealth(player->getBaseHealth() - dmg);
        } catch (const std::invalid_argument& e) {
             player->setBaseHealth(0); 
        }
        cout << player->getName() << " takes " << dmg << " damage from BURN (" << playerBurnStacks << " stacks)!\n";
    }
    if (playerPoisonStacks > 0) {
        int dmg = playerPoisonStacks * 5;
        try {
            player->setBaseHealth(player->getBaseHealth() - dmg);
        } catch (const std::invalid_argument& e) {
             player->setBaseHealth(0); 
        }
        cout << player->getName() << " takes " << dmg << " damage from POISON (" << playerPoisonStacks << " stacks)!\n";
    }

    if (monsterBurnStacks > 0) {
        int dmg = monsterBurnStacks * 7;
        monster->setCurrentHP(monster->getCurrentHP() - dmg);
        cout << monster->getName() << " takes " << dmg << " damage from BURN (" << monsterBurnStacks << " stacks)!\n";
    }
    if (monsterPoisonStacks > 0) {
        int dmg = monsterPoisonStacks * 5;
        monster->setCurrentHP(monster->getCurrentHP() - dmg);
        cout << monster->getName() << " takes " << dmg << " damage from POISON (" << monsterPoisonStacks << " stacks)!\n";
    }
}

void Combat::updateDurations() {
    if (freezeDuration > 0) {
        freezeDuration--;
        if (freezeDuration == 0) cout << player->getName() << " is no longer frozen.\n";
    }
    if (playerDefenseBuffDuration > 0) {
        playerDefenseBuffDuration--;
        if (playerDefenseBuffDuration == 0) cout << player->getName() << " defense buff wore off.\n";
    }
}

bool Combat::isMonsterDead() const { return monster->getCurrentHP() <= 0; }
bool Combat::isPlayerDead() const { return player->getBaseHealth() <= 0; }
bool Combat::isPlayerParalyzed() const { return playerStatus == PARALYSIS; }

bool Combat::isSkillDefenseBuff(int skillIndex) {
    vector<Skill> skills;
    if (player->getClassType() == "Warrior") { skills = Skill::getWarriorSkills(); }
    else if (player->getClassType() == "Mage") { skills = Skill::getMageSkills(); }
    else if (player->getClassType() == "Assassin") { skills = Skill::getAssassinSkills(); }
    else { skills = Skill::getWarriorSkills(); }

    if (skillIndex >= 0 && skillIndex < skills.size()) {
        return skills[skillIndex].getEffect() == EFFECT_PLAYER_DEFENSE_UP;
    }
    return false;
}

int Combat::getPlayerHP() const { return player->getBaseHealth(); }
int Combat::getPlayerMana() const { return player->getBaseMana(); }
int Combat::getMonsterHP() const { return monster->getCurrentHP(); }
std::string Combat::getPlayerName() const { return player->getName(); }
std::string Combat::getMonsterName() const { return monster->getName(); }
int Combat::getMonsterXPReward() const { return monster->getXPReward(); }
int Combat::getMonsterGoldReward() const { return monster->getGoldReward(); }

void Combat::setPlayerHP(int newHP) {
    try {
        player->setBaseHealth(newHP); 
    } catch (const std::invalid_argument& e) {
        std::cerr << "Caught expected exception during setPlayerHP sync: " << e.what() << std::endl;
        player->setBaseHealth(0); 
    }
}
