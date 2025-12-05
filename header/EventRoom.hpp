#ifndef EVENTROOM_HPP
#define EVENTROOM_HPP

#include "Room.hpp"
#include "CharacterClass.hpp"

class EventRoom : public Room {
private:
    bool activated = false;
    CharacterClass* player = nullptr;

public: 
    void setPlayer(CharacterClass* p) { player = p; }
    CharacterClass* getPlayer() { return player; }

    void TriggerRoom() override;
};

#endif