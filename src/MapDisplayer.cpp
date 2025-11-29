#include "../header/MapDisplayer.hpp" 
void MapDisplayer::DisplayMap(const DungeonMap* map) const{
    vector<vector<Room*>> mapMatrix=map->getMap();
    for(int y=mapMatrix->size()-1;y>=0;y--){//We start from y=mapMatrix->size() because we want the largest y-value to be printed first, at the top.
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