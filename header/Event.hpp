#ifndef EVENT_HPP
#define EVENT_HPP

#include "CharacterSelectMenu.hpp"
#include <string>

class Event {
public:
    virtual ~Event() = default;
    virtual void displayMenu() const = 0;
    virtual void chooseOption(int option) = 0;
};

#endif