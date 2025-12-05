#pragma once
#include "Room.hpp"
class EntranceRoom:public Room{
    public:
        virtual void TriggerRoom() override;
};
