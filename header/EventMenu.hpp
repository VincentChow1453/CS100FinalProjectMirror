#ifndef EVENTMENU_HPP
#define EVENTMENU_HPP

#include <vector>
#include <memory>
#include "Event.hpp"
#include "Event1.hpp"
#include "Event2.hpp"
#include "Event3.hpp"
#include "Event4.hpp"
#include "Room.hpp"

class EventMenu {
private:
    std::vector<std::unique_ptr<Event>> events;

public:
    EventMenu();
    void startEncounter(Room* newRoom);
};

#endif
