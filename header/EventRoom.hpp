#ifndef EVENTROOM_HPP
#define EVENTROOM_HPP

#include "Room.hpp"

class EventRoom : public Room {
private:
    bool activated = false;

public:
    void TriggerRoom() override;
};

#endif
