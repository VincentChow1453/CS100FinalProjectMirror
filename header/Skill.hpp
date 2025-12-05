#ifndef SKILL_HPP_UNIQUE_GUARD
#define SKILL_HPP_UNIQUE_GUARD

#include <string>
#include <vector>

using namespace std;

// Enum for additional skill effects (other than status effects)
enum SkillEffectType {
    EFFECT_NONE,
    EFFECT_PLAYER_DEFENSE_UP
};

enum StatusEffectType {
    NONE,
    BURN,
    POISON,
    FREEZE,
    PARALYSIS,
    DOOM
};

class Skill {
private:
    string name;
    int damage;
    int manaCost;
    StatusEffectType status;
    SkillEffectType effect; // Additional effect type
    int effectDuration;     // Effect duration (turns)
    int effectValue;        // Effect value (e.g., defense increase amount, probability)

public:
    // Constructor declaration
    Skill(string n, int dmg, int mana, StatusEffectType s, SkillEffectType e = EFFECT_NONE, int dur = 0, int val = 0);
    Skill() : name(""), damage(0), manaCost(0), status(NONE), effect(EFFECT_NONE), effectDuration(0), effectValue(0) {}

    // Getter declarations
    string getName() const;
    int getDamage() const;
    int getManaCost() const;
    StatusEffectType getStatus() const;
    SkillEffectType getEffect() const;
    int getEffectDuration() const;
    int getEffectValue() const;

    static vector<Skill> getWarriorSkills();
    static vector<Skill> getMageSkills();
    static vector<Skill> getAssassinSkills();
};

#endif // SKILL_HPP_UNIQUE_GUARD
