#include "CharacterSelector.h"
#include <iostream>

void CharacterSelector::displayOptions() {
    std::cout << "Available classes:\n";
    }

void CharacterSelector::selectClass(const std::string& className) {
    std::cout << "Selected class: " << className << "\n";
}

void CharacterSelector::displaySelection() {
    if (selectedClass) {
        std::cout << "Displaying selected class info...\n";
        selectedClass->displayClassInfo();
    } else {
        std::cout << "No class selected yet.\n";
    }
}

void CharacterSelector::startGame() {
    std::cout << "Starting game...\n";
}