#include "../header/MapNavigationMenu.hpp"
#include "../header/MapDisplayer.hpp"
#include <iostream>
using namespace std;
MapNavigationMenu::MapNavigationMenu(){}
MapNavigationMenu::MapNavigationMenu(const int numRooms,const int newWidth,const int newHeight){
    MapGenerator::GenerateMap(numRooms, newWidth, newHeight,&map);
}
void MapNavigationMenu::displayMenu()const{
    cout<<"Here is the current map of the dungeon."<<endl;
    cout<<"Key: [ ]=Empty space; [X]=Entrance Room; [B]=Battle Room; [E]=Event Room; [S]=Shop Room; [H]=You are Here."<<endl;
    MapDisplayer::DisplayMap(&map);
    cout<<"Here are the actions you may take"<<endl;
    cout<<"1. Go Up."<<endl;
    cout<<"2. Go Left."<<endl;
    cout<<"3. Go Down."<<endl;
    cout<<"4. Go Right."<<endl;
    cout<<"5. Exit Game."<<endl;
}
void MapNavigationMenu::chooseOption(const int option){
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
        throw runtime_error("Invalid MapNavigationMenu input. Input must be 1234.");
    }
}
void MapNavigationMenu::startMenu(){
    displayMenu();
    int playerChoice;
    cin>>playerChoice;
    if(!cin>>playerChoice){
        throw runtime_error("Inalid playerChoice in MapNavigationmenu::startMenu().");
    }
    if(playerChoice==5){
        return;
    }
    chooseOption(playerChoice);
    cout<<endl;
    startMenu();
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
