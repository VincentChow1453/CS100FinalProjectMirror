#include "../header/MapNavigationMenu.hpp"
#include <iostream>
using namespace std;
MapNavigationMenu::MapNavigationMenu(){
}
MapNavigationMenu::MapNavigationMenu(const int numRooms,const int newWidth,const int newHeight){
    map.mapMatrix=MapGenerator::GenerateMap(numRooms, newWidth, newHeight);
    map.setMapDimensions(newWidth, newHeight);
    //I also need a way to find the player coordinates
}
void MapNavigationMenu::GoLeft(){
    if(map.getPlayerX()==0||map.mapMatrix->at(map.getPlayerY()).at(map.getPlayerX()-1)==nullptr){//Tests if the player is trying to move out of the map or to an empty space.
        cout<<"Cannot go any further Left"<<endl;
        map.DisplayMap();
        return;
    }
    map.setPlayerCoords(map.getPlayerX()-1,map.getPlayerY());
    map.DisplayMap();
    map.getPlayerRoom()->TriggerRoom();
}
void MapNavigationMenu::GoRight(){
    if(map.getPlayerX()==map.getWidth()-1||map.mapMatrix->at(map.getPlayerY()).at(map.getPlayerX()+1)==nullptr){
        cout<<"Cannot go any further Right"<<endl;
        map.DisplayMap();
        return;
    }
    map.setPlayerCoords(map.getPlayerX()+1,map.getPlayerY());
    map.DisplayMap();
    map.getPlayerRoom()->TriggerRoom();
}
void MapNavigationMenu::GoUp(){
    if(map.getPlayerY()==map.getHeight()-1||map.mapMatrix->at(map.getPlayerY()+1).at(map.getPlayerX())==nullptr){
        cout<<"Cannot go any further Up"<<endl;
        map.DisplayMap();
        return;
    }
    map.setPlayerCoords(map.getPlayerX(),map.getPlayerY()+1);
    map.DisplayMap();
    map.getPlayerRoom()->TriggerRoom();
}
void MapNavigationMenu::GoDown(){
    if(map.getPlayerY()==0||map.mapMatrix->at(map.getPlayerY()-1).at(map.getPlayerX())==nullptr){
        cout<<"Cannot go any further Down"<<endl;
        map.DisplayMap();
        return;
    }
    map.setPlayerCoords(map.getPlayerX(),map.getPlayerY()-1);
    map.DisplayMap();
    map.getPlayerRoom()->TriggerRoom();
}
DungeonMap* MapNavigationMenu::getMap(){
    return &map;
}
