#pragma once
#include "Room.hpp" 
#include "BattleMenu.hpp" 

class BattleRoom : public Room {
private:
    BattleMenu* menu;

public:
    BattleRoom(BattleMenu* m) : menu(m) {}
    void TriggerRoom() override;
}; 
