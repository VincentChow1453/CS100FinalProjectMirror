#ifndef EVENT3_HPP
#define EVENT3_HPP

#include "Event.hpp"
<<<<<<< HEAD
=======
#include <iostream>
#include "CharacterClass.hpp"
using namespace std;
>>>>>>> 0108ca4 (Edited Monster's SkillStats and MaxHealth and MaxMana logics)

class Event3 : public Event {
public:
    void displayMenu() const override;
    void chooseOption(int option, CharacterClass& player) override;
};

#endif
