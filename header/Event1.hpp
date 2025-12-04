#ifndef EVENT1_HPP
#define EVENT1_HPP

#include "Event.hpp"
#include <iostream>
#include "CharacterClass.hpp"
using namespace std;

class Event1 : public Event {
public:
    void displayMenu() const override;
    void chooseOption(int option, CharacterClass& player) override;
};

#endif
