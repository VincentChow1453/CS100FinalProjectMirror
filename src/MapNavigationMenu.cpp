#include "../header/MapNavigationMenu.hpp"
#include "../header/MapDisplayer.hpp"
#include <iostream>
using namespace std;
MapNavigationMenu::MapNavigationMenu(){
}
MapNavigationMenu::MapNavigationMenu(const int numRooms,const int newWidth,const int newHeight){
    map.setMap(generator.GenerateMap(numRooms, newWidth, newHeight,&map));
    map.setMapDimensions(newWidth, newHeight);
    //I also need a way to find the player coordinates
}
void MapNavigationMenu::GoLeft(){
    if(map.getPlayerX()==0||map.getMap()->at(map.getPlayerY()).at(map.getPlayerX()-1)==nullptr){//Tests if the player is trying to move out of the map or to an empty space.
        cout<<"Cannot go any further Left"<<endl;
       MapDisplayer::DisplayMap(&map);
        return;
    }
    map.setPlayerCoords(map.getPlayerX()-1,map.getPlayerY());
   MapDisplayer::DisplayMap(&map);
    map.getPlayerRoom()->TriggerRoom();
}
void MapNavigationMenu::GoRight(){
    if(map.getPlayerX()==map.getWidth()-1||map.getMap()->at(map.getPlayerY()).at(map.getPlayerX()+1)==nullptr){
        cout<<"Cannot go any further Right"<<endl;
       MapDisplayer::DisplayMap(&map);
        return;
    }
    map.setPlayerCoords(map.getPlayerX()+1,map.getPlayerY());
   MapDisplayer::DisplayMap(&map);
    map.getPlayerRoom()->TriggerRoom();
}
void MapNavigationMenu::GoUp(){
    if(map.getPlayerY()==map.getHeight()-1||map.getMap()->at(map.getPlayerY()+1).at(map.getPlayerX())==nullptr){
        cout<<"Cannot go any further Up"<<endl;
       MapDisplayer::DisplayMap(&map);
        return;
    }
    map.setPlayerCoords(map.getPlayerX(),map.getPlayerY()+1);
   MapDisplayer::DisplayMap(&map);
    map.getPlayerRoom()->TriggerRoom();
}
void MapNavigationMenu::GoDown(){
    if(map.getPlayerY()==0||map.getMap()->at(map.getPlayerY()-1).at(map.getPlayerX())==nullptr){
        cout<<"Cannot go any further Down"<<endl;
       MapDisplayer::DisplayMap(&map);
        return;
    }
    map.setPlayerCoords(map.getPlayerX(),map.getPlayerY()-1);
   MapDisplayer::DisplayMap(&map);
    map.getPlayerRoom()->TriggerRoom();
}
DungeonMap* MapNavigationMenu::getMap(){
    return &map;
}
