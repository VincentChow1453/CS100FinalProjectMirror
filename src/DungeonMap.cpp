#include "../header/DungeonMap.hpp"
#include <iostream>
using namespace std;
DungeonMap::DungeonMap(){
    playerX=-1;
    playerY=-1;
    width=0;
    height=0;
    mapMatrix=new vector<vector<Room*>>;
}
DungeonMap::~DungeonMap(){
    if(mapMatrix!=nullptr){
        for(int i=0; i<mapMatrix->size();i++){
        for(int j=0;j<mapMatrix->at(i).size();j++){
            delete mapMatrix->at(i).at(j);
        }
    }
        delete mapMatrix;
    }

}
void DungeonMap::DisplayMap() const{
    for(int y=mapMatrix->size()-1;y>=0;y--){//We start from y=mapMatrix.size() because we want the largest y-value to be printed first, at the top.
        for(int x=0;x<mapMatrix->at(y).size();x++){
            if(mapMatrix->at(y).at(x)==nullptr){
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
int DungeonMap::getPlayerX() const{
    return playerX;
}
int DungeonMap::getPlayerY() const{
    return playerY;
}
int DungeonMap::getHeight() const{
    return height;
}
int DungeonMap::getWidth() const{
    return width;
}
void DungeonMap::setPlayerCoords(const int x,const int y){
    playerX=x;
    playerY=y;
}
void DungeonMap::setMapDimensions(const int newWidth,const int newHeight){
    height=newHeight;
    width=newWidth;
}
Room* DungeonMap::getRoom(const int x, const int y){
    if(x<0||x>=width||y<0||y>=height){
        throw runtime_error("getRoom error. Out of bounds");
    }
    return mapMatrix->at(y).at(x);
}
Room* DungeonMap::getPlayerRoom(){
    return mapMatrix->at(playerY).at(playerX);
}