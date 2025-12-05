#include "../header/Skill.hpp" 
#include <iostream>
#include <vector>

using namespace std;

// Constructor definition
Skill::Skill(string n, int dmg, int mana, StatusEffectType s, SkillEffectType e, int dur, int val) 
    : name(n), damage(dmg), manaCost(mana), status(s), effect(e), effectDuration(dur), effectValue(val) {}

// Getter function definitions
string Skill::getName() const { return name; }
int Skill::getDamage() const { return damage; }
int Skill::getManaCost() const { return manaCost; }
StatusEffectType Skill::getStatus() const { return status; }
SkillEffectType Skill::getEffect() const { return effect; }
int Skill::getEffectDuration() const { return effectDuration; }
int Skill::getEffectValue() const { return effectValue; }

// Static function to return a vector of all Warrior skills
vector<Skill> Skill::getWarriorSkills() {
    return { 
        Skill("Slash", 15, 0, NONE), 
        // Adjusting damage/mana ratio
        Skill("Power Strike", 30, 10, NONE), 
        Skill("Earthquake", 45, 20, PARALYSIS),
        // [Modified] Iron Will: Base damage increased to 20 + Defense buff (50% defense for 3 turns)
        Skill("Iron Will", 20, 15, NONE, EFFECT_PLAYER_DEFENSE_UP, 3, 50) 
    };
}

// Static function to return a vector of all Mage skills
vector<Skill> Skill::getMageSkills() {
    return { 
        Skill("Fireball", 25, 10, BURN), // Damage increased
        Skill("Ice Spike", 35, 15, FREEZE), // Damage increased
        Skill("Lightning Bolt", 45, 20, PARALYSIS), // Damage increased
        // Self-Harm Bolt maintains high damage vs. risk concept
        Skill("Self-Harm Bolt", 60, 30, FREEZE) 
    };
}

// Static function to return a vector of all Assassin skills
vector<Skill> Skill::getAssassinSkills() {
    return { 
        Skill("Stab", 15, 0, NONE), 
        Skill("Poison Blade", 25, 10, POISON), // Damage increased
        Skill("Shadow Strike", 40, 20, NONE), // Damage increased
        Skill("Toxic Jab", 35, 15, POISON) // Damage increased
    };
}
