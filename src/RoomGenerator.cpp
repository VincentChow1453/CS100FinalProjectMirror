#include "RoomGenerator.hpp"
#include <random>
//currently a stub
static BattleRoom* RoomGenerator::generateBattleRoom(){
    BattleRoom newRoom;
    return newRoom;
}
static shopRoom* RoomGenerator::generateShopRoom(){
    ShopRoom newRoom;
    return newRoom;
}
//static EventRoom* generateEventRoom(){
//  EventRoom newRoom;
//  return newRoom;
//}
static Room* RoomGenerator::generateRandomRoom(){
    srand(time(0));//Initializes random function
    const int NUM_ROOM_TYPES=2;//just 2 until we get an eventRoom class
    int choice=rand()%NUM_ROOM_TYPES;//0=BattleRoom, 1=shopRoom, 2=EventRoom
    if(choice==0){
        //BattleRoom newRoom;
        //return newRoom;
    }
    else if (choice==1){
        //shopRoom newRoom;
        //return newRoom;
    }
    else{
        //eventRoom newRoom;
        //return newRoom;
    }

    Room newRoom;
    return newRoom;
}