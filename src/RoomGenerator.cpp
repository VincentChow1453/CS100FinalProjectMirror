#include "RoomGenerator.hpp"
#include <random>
//currently a stub
static BattleRoom* RoomGenerator::generateBattleRoom(){
    return new BattleRoom();
}
static ShopRoom* RoomGenerator::generateShopRoom(){
    return new ShopRoom();
}
static EventRoom* generateEventRoom(){
    return new EventRoom();
}
static Room* RoomGenerator::generateRandomRoom(){
    srand(time(0));//Initializes random function
    const int BATTLE_ROOM_WEIGHT=10;//Currently, each room is equally likely.
    const int EVENT_ROOM_WEIGHT=10;//
    const int SHOP_ROOM_WEIGHT=10;//
    int selection=rand()%(BATTLE_ROOM_WEIGHT+EVENT_ROOM_WEIGHT+SHOP_ROOM_WEIGHT);
    Room* newRoom=nullptr;
    if(selection<=BATTLE_ROOM_WEIGHT){
        newRoom=generateBattleRoom();
        return newRoom;
    }
    else if (selection<=BATTLE_ROOM_WEIGHT+EVENT_ROOM_WEIGHT){
        newRoom=generateEventRoom();
        return newRoom;
    }
    else{
        newRoom=generateShopRoom();
        return newRoom;
    }
}