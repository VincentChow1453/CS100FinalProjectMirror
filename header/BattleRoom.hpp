#pragma once
#include "Room.hpp" 
#include "BattleMenu.hpp" 

class BattleRoom : public Room {
private:

public:
    void TriggerRoom() override;
    void OutputMapSymbol() const override;
}; 
