#ifndef CHARACTER_CLASS_HPP
#define CHARACTER_CLASS_HPP

#include <string>
#include <vector>
#include "ItemClass.hpp"

using namespace std;

class CharacterClass {
private:
    string classType;
    string name;
    int baseHealth;
    int baseMana;
    int baseStrength;
    int baseLevel;
    int gold;
    vector<string> inventory;

public:
    //constructor
    CharacterClass(const string& type = "Not set",
                   const string& name = "Not set",
                   int health = 0,
                   int mana = 0,
                   int strength = 0,
                   int level = 1,
                   int gold = 0);

    //display class funct
    void displayClassInfo() const;

    //getters
    string getClassType() const;
    string getName() const;
    int getBaseHealth() const;
    int getBaseMana() const;
    int getBaseStrength() const;
    int getBaseLevel() const;
    int getGold() const;
    const vector<string>& getInventory() const;

    //setters
    void setName(const string& name);
    void setClassType(const string& type);
    void setBaseHealth(int health);
    void setBaseMana(int mana);
    void setBaseStrength(int strength);
    void setBaseLevel(int level);
    void setGold(int amount);

    //inventory management
       

    void addItem(const string& item);
    void removeItem(const string& item);
    void displayInventory() const;
    void useItem(const Item& item);
};

#endif
