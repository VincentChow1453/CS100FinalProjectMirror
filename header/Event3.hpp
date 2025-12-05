#ifndef EVENT3_HPP
#define EVENT3_HPP

#include "Event.hpp"

class Event3 : public Event {
public:
    void displayMenu() const override;
    void chooseOption(int option) override;
};

#endif
