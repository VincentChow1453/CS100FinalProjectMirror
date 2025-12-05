#pragma once
#include "Room.hpp" 
#include "BattleMenu.hpp" 

class BattleRoom : public Room {
private:

public:
    BattleRoom() {} 
    void TriggerRoom() override;
};
