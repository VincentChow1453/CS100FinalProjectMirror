#include "../header/MapNavigationMenu.hpp"
#include <iostream>
using namespace std;
MapNavigationMenu::MapNavigationMenu(){}
MapNavigationMenu::displayMenu(){
    cout<<"Here is the current map of the dungeon."<<endl;
    cout<<"Key: [ ]=Empty space; [X]=Room; [H]=You are Here."<<endl;
    map.DisplayMap();
    cout<<"Here are the actions you may take"<<endl;
    cout<<"1. Go Up."<<endl;
    cout<<"2. Go Left."<<endl;
    cout<<"3. Go Down."<<endl;
    cout<<"4. Go Right."<<endl;
}
MapNavigationMenu::chooseOption(const int option){
    if(option==1){
        GoUp();
    }
    else if(option==2){
        GoLeft();
    }
    else if(option==3){
        GoDown();
    }
    else if(option==4){
        GoRight();
    }
    else{
        throw runtime_error("Invalid MapNavigationMenu input. Input must be 1234 or wasd.");
    }
}
MapNavigationMenu::startMenu(){
    displayMenu();
    int playerChoice;
    cin>>playerChoice;
    if(!cin>>playerChoice){
        throw runtime_error("Inalid playerChoice in MapNavigationmenu::startMenu().");
    }
    chooseOption(playerChoice);
    startMenu();
}
MapNavigationMenu::MapNavigationMenu(const int numRooms,const int newWidth,const int newHeight){
    map.mapMatrix=generator.GenerateMap(numRooms, newWidth, newHeight);
    map.setMapDimensions(newWidth, newHeight);
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
