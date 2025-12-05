#pragma once
#include "Room.hpp"
#include "BattleRoom.hpp"
#include "ShopRoom.hpp"
#include "EventRoom.hpp"
class RoomGenerator{
    private:
    public:
        static BattleRoom* generateBattleRoom();
        static ShopRoom* generateShopRoom();
        static EventRoom* generateEventRoom();
        static Room* generateRandomRoom();
};