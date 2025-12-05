#include "../header/MapDisplayer.hpp" 
#include <iostream>
using namespace std;
void MapDisplayer::DisplayMap(const DungeonMap* map){
    vector<vector<Room*>>* mapMatrix=map->getMap();
    int playerX=map->getPlayerX();
    int playerY=map->getPlayerY();
    for(int y=mapMatrix->size()-1;y>=0;y--){//We start from y=mapMatrix->size() because we want the largest y-value to be printed first, at the top.
        for(int x=0;x<mapMatrix->at(y).size();x++){
            if(mapMatrix->at(y).at(x)==nullptr){
                cout<<"[ ]";
            }
            else if(x==playerX && y==playerY){
                cout<<"[H]";
            }
            else{
                cout<<"[";
                mapMatrix->at(y).at(x)->OutputMapSymbol();
                cout<<"]";
            }
        }
        cout<<endl;
    }
}