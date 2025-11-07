//stub
#include "../header/MapGenerator.hpp"
#include <iostream>
using std::vector;
vector<vector<Room*>> MapGenerator::GenerateMap(int numRooms){
    std::cout<<"GenerateMap stub. Return a 5x5 vector. Rows 1-4 should be empty, Row 5 should be full"<<std::endl;
    vector<vector<Room*>> tempMap;
    
    for(int i=0;i<4;i++){//Create 4 empty columns
        vector<Room*> tempColumn;
        for(int i=0; i<5;i++){//Create a empty column
            Room* tempRoom=nullptr;
            tempColumn.push_back(tempRoom);
        }
        tempMap.push_back(tempColumn);
    }
    vector<Room*> tempColumn;//Create a full column
    for(int i=0; i<5;i++){
        Room* tempRoom=new Room();
        tempColumn.push_back(tempRoom);
    }
    tempMap.push_back(tempColumn);
    return tempMap;
}