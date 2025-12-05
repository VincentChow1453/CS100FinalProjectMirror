#ifndef EVENT1_HPP
#define EVENT1_HPP

#include "Event.hpp"

class Event1 : public Event {
public:
    void displayMenu() const override;
    void chooseOption(int option) override;
};

#endif
