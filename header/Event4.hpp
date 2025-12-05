#ifndef EVENT4_HPP
#define EVENT4_HPP

#include "Event.hpp"

class Event4 : public Event {
public:
    void displayMenu() const override;
    void chooseOption(int option) override;
};

#endif
