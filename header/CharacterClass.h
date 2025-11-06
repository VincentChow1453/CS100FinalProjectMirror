#ifndef CHARACTERCLASS_H
#define CHARACTERCLASS_H

#include <string>

class CharacterClass {
private:
    std::string classType;

     int baseHealth;
    int baseMana;
    int baseStrength;
    int baseLevel;

public:
    void displayClassInfo() const;
};

#endif // CHARACTERCLASS_H