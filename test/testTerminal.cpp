#include "../header/MapGenerator.hpp"
#include "../header/DungeonMap.hpp"
#include "../header/MapNavigationMenu.hpp"
#include <iostream>
using  namespace std;
int main(){
    MapGenerator generator;
    int numRooms=10;
    int newMapWidth=5;
    int newMapHeight=5;
    DungeonMap map;
    map.mapMatrix=generator.GenerateMap(numRooms, newMapWidth, newMapHeight);
    map.setMapDimensions(newMapHeight,newMapWidth);
    int countedRooms=0;
    for(int y=0;y<map.getHeight();y++){
        for(int x=0; x<map.getWidth();x++){
            if(map.mapMatrix->at(y).at(x)!=nullptr){
                countedRooms++;
            }
        }
    }
    map.DisplayMap();
}

