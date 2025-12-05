#include "RoomGenerator.hpp"
#include <random>
//currently a stub
BattleRoom* RoomGenerator::generateBattleRoom(){
    return new BattleRoom();
}
ShopRoom* RoomGenerator::generateShopRoom(){
    return new ShopRoom();
}
EventRoom* RoomGenerator::generateEventRoom(){
    return new EventRoom();
}
Room* RoomGenerator::generateRandomRoom(){
    const int BATTLE_ROOM_WEIGHT=10;//Currently, each room is equally likely.
    const int EVENT_ROOM_WEIGHT=10;//
    const int SHOP_ROOM_WEIGHT=10;//
    int selection=rand()%(BATTLE_ROOM_WEIGHT+EVENT_ROOM_WEIGHT+SHOP_ROOM_WEIGHT);
    if(selection<=BATTLE_ROOM_WEIGHT){
        return generateBattleRoom();
    }
    else if (selection<=BATTLE_ROOM_WEIGHT+EVENT_ROOM_WEIGHT){
        return generateEventRoom();
    }
    else{
        return generateShopRoom();
    }
}