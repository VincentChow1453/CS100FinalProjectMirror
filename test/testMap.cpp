#include "gtest/gtest.h"
#include "../header/MapGenerator.hpp"
#include "../header/DungeonMap.hpp"
#include "../header/MapNavigationMenu.hpp"
#include "../header/Room.hpp"
#include "../header/MapDisplayer.hpp"
#include <iostream>
using  namespace std;
TEST(DungeonMap, testSetPlayerCoordsEmptyMap){
    DungeonMap map;
    int newMapHeight=0, newMapWidth=0;
    map.setPlayerCoords(0,0);
    map.setMapDimensions(newMapHeight,newMapWidth);
    ASSERT_TRUE((map.getPlayerX()==0)&&(map.getPlayerY()==0));
}
TEST(DungeonMap, testSetPlayerCoordsPopulatedMap){
    DungeonMap map;
    vector<Room*> tempMapRow;
    int newMapHeight=5, newMapWidth=5;
    for(int i=0; i<5;i++){
        tempMapRow.push_back(nullptr);
    }
    map.getMap()->push_back(tempMapRow);
    for(int i=1;i<5;i++){
        for(int j=0; j<5;j++){
            tempMapRow.at(j)=(nullptr);
        }
        map.getMap()->push_back(tempMapRow);
    }
    map.setMapDimensions(newMapHeight,newMapWidth);
    map.setPlayerCoords(1,1);
    ASSERT_TRUE((map.getPlayerX()==1)&&(map.getPlayerY()==1));
}
TEST(DungeonMap, testBottomRowOutput){
    testing::internal::CaptureStdout();
    DungeonMap map;
    vector<Room*> tempMapRow;
    int newMapHeight=5, newMapWidth=5;
    for(int i=0; i<5;i++){
        tempMapRow.push_back(new Room);
    }
    map.getMap()->push_back(tempMapRow);
    for(int i=1;i<5;i++){
        for(int j=0; j<5;j++){
            tempMapRow.at(j)=(nullptr);
        }
        map.getMap()->push_back(tempMapRow);
    }
    map.setMapDimensions(newMapHeight,newMapWidth);
    MapDisplayer::DisplayMap(&map);
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "[ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ]\n[X][X][X][X][X]\n");
    //[ ][ ][ ][ ][ ]
    //[ ][ ][ ][ ][ ]
    //[ ][ ][ ][ ][ ]
    //[ ][ ][ ][ ][ ]
    //[X][X][X][X][X]
}
TEST(DungeonMap, testPlayerPosition){
    testing::internal::CaptureStdout();
    DungeonMap map;
    vector<Room*> tempMapRow;
    int newMapHeight=5, newMapWidth=5;
    for(int x=0;x<5;x++){
        tempMapRow.push_back(new Room);
    }
    map.getMap()->push_back(tempMapRow);//The last added row is on the bottom
    for(int y=0;y<4;y++){
        for(int x=0; x<5;x++){
            tempMapRow.at(x)=(nullptr);
        }
        map.getMap()->push_back(tempMapRow);
    }
    map.setMapDimensions(newMapHeight,newMapWidth);
    map.setPlayerCoords(0,0);
    MapDisplayer::DisplayMap(&map);
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "[ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ]\n[H][X][X][X][X]\n");
    //[ ][ ][ ][ ][ ]
    //[ ][ ][ ][ ][ ]
    //[ ][ ][ ][ ][ ]
    //[ ][ ][ ][ ][ ]
    //[H][X][X][X][X]
}
TEST(DungeonMap, testLeftColumn){
    testing::internal::CaptureStdout();
    DungeonMap map;
    vector<Room*> tempMapRow;
    int newMapHeight=5, newMapWidth=5;
    tempMapRow.push_back(new Room);
    for(int j=1; j<5;j++){
        tempMapRow.push_back(nullptr);
    }
    map.getMap()->push_back(tempMapRow);
    for(int i=0;i<4;i++){
        tempMapRow.at(0)=new Room;
        for(int j=1; j<5;j++){
            tempMapRow.at(j)=nullptr;
        }
        map.getMap()->push_back(tempMapRow);
    }
    map.setMapDimensions(newMapHeight,newMapWidth);
    map.setPlayerCoords(0,0);
    MapDisplayer::DisplayMap(&map);
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "[X][ ][ ][ ][ ]\n[X][ ][ ][ ][ ]\n[X][ ][ ][ ][ ]\n[X][ ][ ][ ][ ]\n[H][ ][ ][ ][ ]\n");
    //[X][ ][ ][ ][ ]
    //[X][ ][ ][ ][ ]
    //[X][ ][ ][ ][ ]
    //[X][ ][ ][ ][ ]
    //[H][ ][ ][ ][ ]
}
TEST(DungeonMapMenu, testSuccessfullLeft){
    testing::internal::CaptureStdout();
    MapNavigationMenu mapMenu;
    DungeonMap* map=mapMenu.getMap();
    vector<Room*> tempMapRow;
    int newMapHeight=5, newMapWidth=5;
        for(int x=0;x<5;x++){
        tempMapRow.push_back(new Room);
    }
    map->getMap()->push_back(tempMapRow);//The last added row is on the bottom
    for(int y=0;y<4;y++){
        for(int x=0; x<5;x++){
            tempMapRow.at(x)=(nullptr);
        }
        map->getMap()->push_back(tempMapRow);
    }
    map->setMapDimensions(newMapHeight,newMapWidth);
    map->setPlayerCoords(1,0);
    //[ ][ ][ ][ ][ ]
    //[ ][ ][ ][ ][ ]
    //[ ][ ][ ][ ][ ]
    //[ ][ ][ ][ ][ ]
    //[X][H][X][X][X]
    mapMenu.GoLeft();
    //[ ][ ][ ][ ][ ]
    //[ ][ ][ ][ ][ ]
    //[ ][ ][ ][ ][ ]
    //[ ][ ][ ][ ][ ]
    //[H][X][X][X][X]
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "[ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ]\n[H][X][X][X][X]\nEncounterMenu DisplayMenu() stub\nEncounterMenu ChooseOption(1) stub\nRoom TriggerRoom() stub\n");
}
TEST(DungeonMapMenu, testLeftOutOfBounds){
    testing::internal::CaptureStdout();
    MapNavigationMenu mapMenu;
    DungeonMap* map=mapMenu.getMap();
    vector<Room*> tempMapRow;
    int newMapHeight=5, newMapWidth=5;
    for(int x=0;x<5;x++){
        tempMapRow.push_back(new Room);
    }
    map->getMap()->push_back(tempMapRow);//The last added row is on the bottom
    for(int y=0;y<4;y++){
        for(int x=0; x<5;x++){
            tempMapRow.at(x)=(nullptr);
        }
        map->getMap()->push_back(tempMapRow);
    }
    map->setMapDimensions(newMapHeight,newMapWidth);
    map->setPlayerCoords(0,0);
    //[ ][ ][ ][ ][ ]
    //[ ][ ][ ][ ][ ]
    //[ ][ ][ ][ ][ ]
    //[ ][ ][ ][ ][ ]
    //[H][X][X][X][X]
    mapMenu.GoLeft();
    //[ ][ ][ ][ ][ ]
    //[ ][ ][ ][ ][ ]
    //[ ][ ][ ][ ][ ]
    //[ ][ ][ ][ ][ ]
    //[H][X][X][X][X]
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Cannot go any further Left\n[ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ]\n[ ][ ][ ][ ][ ]\n[H][X][X][X][X]\n");
}
TEST(DungeonMapMenu, testLeftEmptyRoom){
    testing::internal::CaptureStdout();
    MapNavigationMenu mapMenu;
    DungeonMap* map=mapMenu.getMap();
    vector<Room*> tempMapRow;
    int newMapHeight=5, newMapWidth=5;
    for(int x=0;x<5;x++){
        tempMapRow.push_back(nullptr);
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    for(int x=0; x<5;x++){
        tempMapRow.at(x)=(new Room);
    }
    map->getMap()->push_back(tempMapRow);
    for(int x=0;x<5;x++){
        tempMapRow.at(x)=nullptr;
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    map->setMapDimensions(newMapHeight,newMapWidth);
    map->setPlayerCoords(2,3);
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    //[X][X][H][X][X]
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    mapMenu.GoLeft();
    //[ ][ ][X][ ][ ]
    //[ ][ ][H][ ][ ]
    //[X][X][X][X][X]
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Cannot go any further Left\n[ ][ ][X][ ][ ]\n[ ][ ][H][ ][ ]\n[X][X][X][X][X]\n[ ][ ][X][ ][ ]\n[ ][ ][X][ ][ ]\n");
}
TEST(DungeonMapMenu, testRightSuccessful){
    testing::internal::CaptureStdout();
    MapNavigationMenu mapMenu;
    DungeonMap* map=mapMenu.getMap();
    vector<Room*> tempMapRow;
    int newMapHeight=5, newMapWidth=5;
    for(int x=0;x<5;x++){
        tempMapRow.push_back(nullptr);
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    for(int x=0; x<5;x++){
        tempMapRow.at(x)=(new Room);
    }
    map->getMap()->push_back(tempMapRow);
    for(int x=0;x<5;x++){
        tempMapRow.at(x)=nullptr;
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    map->setMapDimensions(newMapHeight,newMapWidth);
    map->setPlayerCoords(2,2);
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    //[X][X][H][X][X]
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    mapMenu.GoRight();
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    //[X][X][X][H][X]
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "[ ][ ][X][ ][ ]\n[ ][ ][X][ ][ ]\n[X][X][X][H][X]\n[ ][ ][X][ ][ ]\n[ ][ ][X][ ][ ]\nEncounterMenu DisplayMenu() stub\nEncounterMenu ChooseOption(1) stub\nRoom TriggerRoom() stub\n");
}
TEST(DungeonMapMenu, testRightOutOfBounds){
    testing::internal::CaptureStdout();
    MapNavigationMenu mapMenu;
    DungeonMap* map=mapMenu.getMap();
    vector<Room*> tempMapRow;
    int newMapHeight=5, newMapWidth=5;
    for(int x=0;x<5;x++){
        tempMapRow.push_back(nullptr);
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    for(int x=0; x<5;x++){
        tempMapRow.at(x)=(new Room);
    }
    map->getMap()->push_back(tempMapRow);
    for(int x=0;x<5;x++){
        tempMapRow.at(x)=nullptr;
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    map->setMapDimensions(newMapHeight,newMapWidth);
    map->setPlayerCoords(4,2);
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    //[X][X][X][X][H]
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    mapMenu.GoRight();
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    //[X][X][X][X][H]
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Cannot go any further Right\n[ ][ ][X][ ][ ]\n[ ][ ][X][ ][ ]\n[X][X][X][X][H]\n[ ][ ][X][ ][ ]\n[ ][ ][X][ ][ ]\n");
}
TEST(DungeonMapMenu, testRightEmptyRoom){
    testing::internal::CaptureStdout();
    MapNavigationMenu mapMenu;
    DungeonMap* map=mapMenu.getMap();
    vector<Room*> tempMapRow;
    int newMapHeight=5, newMapWidth=5;
    for(int x=0;x<5;x++){
        tempMapRow.push_back(nullptr);
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    for(int x=0; x<5;x++){
        tempMapRow.at(x)=(new Room);
    }
    map->getMap()->push_back(tempMapRow);
    for(int x=0;x<5;x++){
        tempMapRow.at(x)=nullptr;
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    map->setMapDimensions(newMapHeight,newMapWidth);
    map->setPlayerCoords(2,3);
    //[ ][ ][X][ ][ ]
    //[ ][ ][H][ ][ ]
    //[X][X][X][X][X]
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    mapMenu.GoRight();
    //[ ][ ][X][ ][ ]
    //[ ][ ][H][ ][ ]
    //[X][X][X][X][X]
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Cannot go any further Right\n[ ][ ][X][ ][ ]\n[ ][ ][H][ ][ ]\n[X][X][X][X][X]\n[ ][ ][X][ ][ ]\n[ ][ ][X][ ][ ]\n");
}
TEST(DungeonMapMenu, testUpSuccessful){
    testing::internal::CaptureStdout();
    MapNavigationMenu mapMenu;
    DungeonMap* map=mapMenu.getMap();
    vector<Room*> tempMapRow;
    int newMapHeight=5, newMapWidth=5;
    for(int x=0;x<5;x++){
        tempMapRow.push_back(nullptr);
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    for(int x=0; x<5;x++){
        tempMapRow.at(x)=(new Room);
    }
    map->getMap()->push_back(tempMapRow);
    for(int x=0;x<5;x++){
        tempMapRow.at(x)=nullptr;
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    map->setMapDimensions(newMapWidth,newMapHeight);
    map->setPlayerCoords(2,2);
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    //[X][X][H][X][X]
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    mapMenu.GoUp();
    //[ ][ ][X][ ][ ]
    //[ ][ ][H][ ][ ]
    //[X][X][X][X][X]
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "[ ][ ][X][ ][ ]\n[ ][ ][H][ ][ ]\n[X][X][X][X][X]\n[ ][ ][X][ ][ ]\n[ ][ ][X][ ][ ]\nEncounterMenu DisplayMenu() stub\nEncounterMenu ChooseOption(1) stub\nRoom TriggerRoom() stub\n");
}
TEST(DungeonMapMenu, testUpOutOfBounds){
    testing::internal::CaptureStdout();
    MapNavigationMenu mapMenu;
    DungeonMap* map=mapMenu.getMap();
    vector<Room*> tempMapRow;
    int newMapHeight=5, newMapWidth=5;
    for(int x=0;x<5;x++){
        tempMapRow.push_back(nullptr);
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    for(int x=0; x<5;x++){
        tempMapRow.at(x)=(new Room);
    }
    map->getMap()->push_back(tempMapRow);
    for(int x=0;x<5;x++){
        tempMapRow.at(x)=nullptr;
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    map->setMapDimensions(newMapWidth,newMapHeight);
    map->setPlayerCoords(2,4);
    //[ ][ ][H][ ][ ]
    //[ ][ ][X][ ][ ]
    //[X][X][X][X][X]
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    mapMenu.GoUp();
    //[ ][ ][H][ ][ ]
    //[ ][ ][X][ ][ ]
    //[X][X][X][X][X]
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Cannot go any further Up\n[ ][ ][H][ ][ ]\n[ ][ ][X][ ][ ]\n[X][X][X][X][X]\n[ ][ ][X][ ][ ]\n[ ][ ][X][ ][ ]\n");
}
TEST(DungeonMapMenu, testUpEmptyRoom){
    testing::internal::CaptureStdout();
    MapNavigationMenu mapMenu;
    DungeonMap* map=mapMenu.getMap();
    vector<Room*> tempMapRow;
    int newMapHeight=5, newMapWidth=5;
    for(int x=0;x<5;x++){
        tempMapRow.push_back(nullptr);
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    for(int x=0; x<5;x++){
        tempMapRow.at(x)=(new Room);
    }
    map->getMap()->push_back(tempMapRow);
    for(int x=0;x<5;x++){
        tempMapRow.at(x)=nullptr;
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    map->setMapDimensions(newMapWidth,newMapHeight);
    map->setPlayerCoords(3,2);
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    //[X][X][X][H][X]
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    mapMenu.GoUp();
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    //[X][X][X][H][X]
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Cannot go any further Up\n[ ][ ][X][ ][ ]\n[ ][ ][X][ ][ ]\n[X][X][X][H][X]\n[ ][ ][X][ ][ ]\n[ ][ ][X][ ][ ]\n");
}
TEST(DungeonMapMenu, testDownSuccessful){
    testing::internal::CaptureStdout();
    MapNavigationMenu mapMenu;
    DungeonMap* map=mapMenu.getMap();
    vector<Room*> tempMapRow;
    int newMapHeight=5, newMapWidth=5;
    for(int x=0;x<5;x++){
        tempMapRow.push_back(nullptr);
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    for(int x=0; x<5;x++){
        tempMapRow.at(x)=(new Room);
    }
    map->getMap()->push_back(tempMapRow);
    for(int x=0;x<5;x++){
        tempMapRow.at(x)=nullptr;
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    map->setMapDimensions(newMapHeight,newMapWidth);
    map->setPlayerCoords(2,2);
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    //[X][X][H][X][X]
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    mapMenu.GoDown();
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    //[X][X][X][X][X]
    //[ ][ ][H][ ][ ]
    //[ ][ ][X][ ][ ]
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "[ ][ ][X][ ][ ]\n[ ][ ][X][ ][ ]\n[X][X][X][X][X]\n[ ][ ][H][ ][ ]\n[ ][ ][X][ ][ ]\nEncounterMenu DisplayMenu() stub\nEncounterMenu ChooseOption(1) stub\nRoom TriggerRoom() stub\n");
}
TEST(DungeonMapMenu, testDownOutOfBounds){
    testing::internal::CaptureStdout();
    MapNavigationMenu mapMenu;
    DungeonMap* map=mapMenu.getMap();
    vector<Room*> tempMapRow;
    int newMapHeight=5, newMapWidth=5;
    for(int x=0;x<5;x++){
        tempMapRow.push_back(nullptr);
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    for(int x=0; x<5;x++){
        tempMapRow.at(x)=(new Room);
    }
    map->getMap()->push_back(tempMapRow);
    for(int x=0;x<5;x++){
        tempMapRow.at(x)=nullptr;
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    map->setMapDimensions(newMapHeight,newMapWidth);
    map->setPlayerCoords(2,0);
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    //[X][X][X][X][X]
    //[ ][ ][X][ ][ ]
    //[ ][ ][H][ ][ ]
    mapMenu.GoDown();
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    //[X][X][X][X][X]
    //[ ][ ][X][ ][ ]
    //[ ][ ][H][ ][ ]
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Cannot go any further Down\n[ ][ ][X][ ][ ]\n[ ][ ][X][ ][ ]\n[X][X][X][X][X]\n[ ][ ][X][ ][ ]\n[ ][ ][H][ ][ ]\n");
}
TEST(DungeonMapMenu, testDownEmptyRoom){
    testing::internal::CaptureStdout();
    MapNavigationMenu mapMenu;
    DungeonMap* map=mapMenu.getMap();
    vector<Room*> tempMapRow;
    int newMapHeight=5, newMapWidth=5;
    for(int x=0;x<5;x++){
        tempMapRow.push_back(nullptr);
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    for(int x=0; x<5;x++){
        tempMapRow.at(x)=(new Room);
    }
    map->getMap()->push_back(tempMapRow);
    for(int x=0;x<5;x++){
        tempMapRow.at(x)=nullptr;
    }
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    tempMapRow.at(2)=new Room;
    map->getMap()->push_back(tempMapRow);
    map->setMapDimensions(newMapHeight,newMapWidth);
    map->setPlayerCoords(3,2);
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    //[X][X][X][H][X]
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    mapMenu.GoDown();
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    //[X][X][X][H][X]
    //[ ][ ][X][ ][ ]
    //[ ][ ][X][ ][ ]
    string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Cannot go any further Down\n[ ][ ][X][ ][ ]\n[ ][ ][X][ ][ ]\n[X][X][X][H][X]\n[ ][ ][X][ ][ ]\n[ ][ ][X][ ][ ]\n");
}
TEST(MapGenerator, testNumRooms){
    MapGenerator generator;
    int numRooms=10;
    int newMapWidth=10;
    int newMapHeight=10;
    DungeonMap map;
    map.setMap(generator.GenerateMap(numRooms, newMapWidth, newMapHeight));
    map.setMapDimensions(newMapHeight,newMapWidth);
    int countedRooms=0;
    for(int y=0;y<map.getHeight();y++){
        for(int x=0; x<map.getWidth();x++){
            if(map.getMap()->at(y).at(x)!=nullptr){
                countedRooms++;
            }
        }
    }
    EXPECT_EQ(countedRooms,numRooms);
}