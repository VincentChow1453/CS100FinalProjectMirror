#include "Room.hpp"
#include "BattleRoom.hpp"
#include "shopRoom.hpp"
//#include "eventRoom.hpp"
#include "MonsterStats.hpp"
//#include "Item.hpp"
//#include "Event_Encounter"
//currently a stub
class RoomGenerator{
    private:
        vector<MonsterStats> monsterList;
        // vector<Item> itemList;
        // vector<Event_Encounter> eventList;
    public:
        static BattleRoom* generateBattleRoom();
        static shopRoom* generateShopRoom();
        //static EventRoom* generateEventRoom();
        static Room* generateRandomRoom();
};