#ifndef EVENT2_HPP
#define EVENT2_HPP

#include "Event.hpp"

class Event2 : public Event {
public:
    void displayMenu() const override;
    void chooseOption(int option, CharacterClass& player) override;
};

#endif
