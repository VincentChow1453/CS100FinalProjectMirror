#ifndef EVENTMENU_HPP
#define EVENTMENU_HPP

#include "Event.hpp"
#include "Event1.hpp"
#include "Event2.hpp"
#include "Event3.hpp"
#include "Event4.hpp"
#include "Room.hpp"
#include <vector>
#include <memory>

class EventMenu {
private:
    Room* currRoom{};
    vector<unique_ptr<Event>> events;

public:
    EventMenu();
    void startEncounter(Room* newRoom);
};

#endif