#ifndef EVENT_HPP
#define EVENT_HPP

#include "CharacterClass.hpp"
#include <string>

class Event {
public:
    virtual ~Event() = default;
    virtual void displayMenu() const = 0;
    virtual void chooseOption(int option, CharacterClass& player) = 0;
};

#endif