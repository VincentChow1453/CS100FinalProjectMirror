#include "../header/MapGenerator.hpp"
#include <iostream>
#include <random>
using namespace std;
void MapGenerator::GenerateMap(int numRooms, const int mapWidth, const int mapHeight, DungeonMap* dunMapPtr){
    srand(time(0));//Initializes random function
    if(numRooms>mapWidth*mapHeight){
        throw runtime_error("ERROR in Generate Map. numRooms>mapWisth*mapHeight");
    }
    vector<vector<Room*>>* tempMap=new vector<vector<Room*>>;
    vector<Room*> tempRow;
    for(int x=0;x<mapWidth;x++){
        tempRow.push_back(nullptr);
    }
    for(int y=0; y<mapHeight;y++){
        tempMap->push_back(tempRow);
    }

    int entranceXPos=rand()%mapHeight;
    int entranceYPos=rand()%mapWidth;
    int currXPos=entranceXPos;
    int currYPos=entranceYPos;
    int randDirection;//0=left, 1=up, 2=right, 3=down
    while(numRooms>0){
        if(tempMap->at(currYPos).at(currXPos)==nullptr){//If we find an empty space then
            if(currXPos==entranceXPos&&currYPos==entranceYPos){//If that space is the entrance (i.e. on the first run)
                tempMap->at(currYPos).at(currXPos)=new Room;                                      //Replace Room with Entrance subclass
                
            }
            else{                                               //Otherwise
                tempMap->at(currYPos).at(currXPos)=new Room;                                      //Replace Room with a random selection of EventRoom BattleRoom and ShopRoom
            }
            numRooms--;
        }
        else{//Go to a nearby random empty space. Currently this runs a bit like a headless chicken.
            randDirection=rand()%4;
            if(randDirection== 0&& currXPos>0){//currXPos>0 means we can go farther left
                currXPos--;
            }
            else if(randDirection==1 && currYPos<mapHeight-1){//currYPos<mapHeight-1 means we can go farther up
                currYPos++;
            }
            else if(randDirection==2 && currXPos<mapWidth-1){//currXPos<mapWidth-1 means we can go farther right
                currXPos++;
            }
            else if (currYPos>0){//currYPos>0 means we can go farther down
                currYPos--;
            }
        }
    } 
    dunMapPtr->setPlayerCoords(entranceXPos,entranceYPos);
    dunMapPtr->setMapDimensions(mapWidth,mapHeight);
    dunMapPtr->setMap(tempMap);
}