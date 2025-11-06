#ifndef CHARACTERSELECTOR_H
#define CHARACTERSELECTOR_H

#include <vector>
#include <string>
#include "CharacterClass.h"

class CharacterSelector {
private:
    std::vector<CharacterClass> availableClasses;
    CharacterClass* selectedClass;

    public:
    CharacterSelector();
    
    void displayOptions();
    void selectClass(const std::string& className);
    void displaySelection();
    void startGame();
};

#endif // CHARACTERSELECTOR_H