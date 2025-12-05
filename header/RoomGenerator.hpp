#include "Room.hpp"
#include "BattleRoom.hpp"
#include "ShopRoom.hpp"
#include "EventRoom.hpp"
//currently a stub
class RoomGenerator{
    private:
    public:
        static BattleRoom* generateBattleRoom();
        static ShopRoom* generateShopRoom();
        static EventRoom* generateEventRoom();
        static Room* generateRandomRoom();
};