#include "../header/DungeonMap.hpp"
#include <iostream>
using namespace std;
DungeonMap::~DungeonMap(){
    for(int i=0; i<mapMatrix.size();i++){
        for(int j=0;j<mapMatrix.at(i).size();j++){
            delete mapMatrix.at(i).at(j);
        }
    }
}
void DungeonMap::DisplayMap(){
    for(int y=mapMatrix.size()-1;y>=0;y--){//We start from y=mapMatrix.size() because we want the largest y-value to be printed first, at the top.
        for(int x=0;x<mapMatrix.at(y).size();x++){
            if(mapMatrix.at(y).at(x)==nullptr){
                cout<<"[ ]";
            }
            else if(x==playerX && y==playerY){
                cout<<"[H]";
            }
            else{
                cout<<"[X]";
            }
        }
        cout<<endl;
    }
}
int DungeonMap::getPlayerX(){
    return playerX;
}
int DungeonMap::getPlayerY(){
    return playerY;
}
int DungeonMap::getHeight(){
    return height;
}
int DungeonMap::getWidth(){
    return width;
}
void DungeonMap::setPlayerCoords(int x, int y){
    playerX=x;
    playerY=y;
}
void DungeonMap::setMapDimensions(int newWidth, int newHeight){
    height=newHeight;
    width=newWidth;
}