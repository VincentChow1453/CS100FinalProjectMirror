#ifndef EVENT3_HPP
#define EVENT3_HPP

#include "Event.hpp"
#include <iostream>
#include "CharacterClass.hpp"
using namespace std;

class Event3 : public Event {
public:
    void displayMenu() const override;
    void chooseOption(int option, CharacterClass& player) override;
};

#endif
