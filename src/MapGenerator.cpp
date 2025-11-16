#include "../header/MapGenerator.hpp"
#include <iostream>
#include <random>
using namespace std;
vector<vector<Room*>> MapGenerator::GenerateMap(int targetNumRooms){
    vector<vector<Room*>> tempMap;
    int entranceX, entranceY;
    entranceX=rand()%mapHeight;//These are the coords where the player will start
    entranceY=rand()%mapWidth;
    return GenerateMapHelper(targetNumRooms, targetNumRooms, entranceX, entranceY,tempMap);
}
vector<vector<Room*>> MapGenerator::GenerateMapHelper(int targetNumRooms, int numRoomsLeft,int entranceX, int entranceY, vector<vector<Room*>> currMap){
    vector<vector<Room*>> tempMap;
    Room* currRoom=tempMap.at(entranceX).at(entranceY);
    float new
    if(){

    }
    return GenerateMapHelper(targetNumRooms, numRoomsLeft, entranceX, entranceY,tempMap);
}