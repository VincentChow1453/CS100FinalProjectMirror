#pragma once
#include "Room.hpp"
class EntranceRoom:Room{
    public:
        virtual void TriggerRoom() override;//=0; //Room should be an abstract class once we create its subclasses.
};
