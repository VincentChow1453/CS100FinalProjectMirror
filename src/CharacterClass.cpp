#include "CharacterClass.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;

//constructor
CharacterClass::CharacterClass(const string& type,
                                const string& name,
                                int health,
                                int mana,
                                int strength,
                                int level,
                                int gold) 
{
    setClassType(type);
    setName(name);
    setBaseHealth(health);
    setBaseMana(mana);
    setBaseStrength(strength);
    setBaseLevel(level);
    setGold(gold);
}



//display class info
void CharacterClass::displayClassInfo() const {
        cout << "Class Type: " << classType << endl
        << "Name: " << name << endl
        << "Health: " << baseHealth << endl
        << "Mana: " << baseMana << endl
        << "Strength: " << baseStrength << endl
        << "Level: " << baseLevel << endl
        << "Gold: " << gold << endl;
}


//getters
string CharacterClass::getClassType() const {return classType;}
string CharacterClass::getName() const {return name;}
int CharacterClass::getBaseHealth() const {return baseHealth;}
int CharacterClass::getBaseMana() const {return baseMana;}
int CharacterClass::getBaseStrength() const {return baseStrength;}
int CharacterClass::getBaseLevel() const {return baseLevel;}
int CharacterClass::getGold() const {return gold;}
const vector<string>& CharacterClass::getInventory() const {return inventory;}


//setters - throws an exception if invalid value is provided
void CharacterClass::setClassType(const std::string& type) {
    if (type.empty()) {
        throw invalid_argument("Class type cannot be empty.");
    }

    classType = type;
}

void CharacterClass::setName(const string& charName) {
    if (charName.empty()) {
        throw invalid_argument("Name cannot be empty.");
    }
    name = charName;
}

void CharacterClass::setBaseHealth(int health) {
    if (health < 0) {
        throw invalid_argument("Health cannot be negative.");
    }
    baseHealth = health;
}

void CharacterClass::setBaseMana(int mana) {
    if (mana < 0) {
        throw invalid_argument("Mana cannot be negative.");
    }
    
    baseMana = mana;
}

void CharacterClass::setBaseStrength(int strength) {
    if (strength < 0) {
        throw invalid_argument("Base strength cannot be negative.");
    }
    baseStrength = strength;
}

void CharacterClass::setBaseLevel(int level) {
    if (level < 1) {
        throw invalid_argument("Base level must be at least 1.");
    }
    baseLevel = level;
}

void CharacterClass::setGold(int amount) {
    if (amount < 0) {
        throw invalid_argument("Gold amount cannot be negative.");
    }
    gold = amount;
}

//inventory management

//add an item to inventory (setter)
void CharacterClass::addItem(const string& item) {
    if (item.empty())
        throw invalid_argument("Item name cannot be empty.");

    inventory.push_back(item);
}

//remove a certain item/uses a certain item
void CharacterClass::removeItem(const string& item) {
    vector<std::string>::iterator itemFinder = inventory.begin();

    //find the item manually (should be fine because there won't be that many items probably)
    while (itemFinder != inventory.end() && *itemFinder != item) {
        ++itemFinder;
    }

    //dont have the item
    if (itemFinder == inventory.end()) {
        throw std::invalid_argument("Item not found.");
    }

    //remove it
    inventory.erase(itemFinder);
}

//should display the inventory aesthetically ish
void CharacterClass::displayInventory() const {
    cout << "Inventory:" << endl;
    //no items
    if (inventory.empty()) {
        cout << "Empty ..." << endl;
        return;
    }

    //go through items
    vector<std::string>::const_iterator invDisplayer;
    for (invDisplayer = inventory.begin(); invDisplayer != inventory.end(); ++invDisplayer) {
        cout << " - " << *invDisplayer << endl;
    }
}


// edits characters stats
void CharacterClass::useItem(const Item& item) {
    if (item.type == "health") {
        baseHealth += item.amount;
    }

    else if (item.type == "mana") {
        baseMana += item.amount;
    }

    else if (item.type == "strength") {
        baseStrength += item.amount;
    }

    else {
        cout << "Unknown item type: " << item.type << endl;
    }
    // deletes item after use
    removeItem(item.name);
}
