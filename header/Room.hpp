#ifndef ROOM_H
#define ROOM_H
#include "player.hpp"


class Room {
private:
    bool activated;

public:
    virtual void TriggerEncounter(Player& player) = 0; // PURE VIRTUAL = abstract class
    virtual ~Room() = default;            // recommended for polymorphism
};

#endif // ROOM_H
