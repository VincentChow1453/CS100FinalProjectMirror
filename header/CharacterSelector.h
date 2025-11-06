#ifndef CHARACTERSELECTOR_H
#define CHARACTERSELECTOR_H

#include <vector>
#include <string>
#include "CharacterClass.h"

class CharacterSelector {
private:
    std::vector<Character> availableClasses;
    Character* selectedClass;

    public:
    void displayOptions();
    void selectClass(const std::string& className);
    void displaySelection();
    void startGame();
};

#endif // CHARACTERSELECTOR_H