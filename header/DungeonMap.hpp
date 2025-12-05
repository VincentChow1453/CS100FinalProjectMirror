#ifndef DUNGEONMAP_HPP
#define DUNGEONMAP_HPP
#include "Room.hpp"
#include <vector>
using std::vector;
class DungeonMap {
    private:
        int playerX, playerY;
        int width,height;//width=x, height=y
        int floorLevel;
        vector<vector<Room*>>* mapMatrix=nullptr;
    public:
        DungeonMap();
        ~DungeonMap();
        vector<vector<Room*>>* getMap() const;
        vector<vector<Room*>>* getMap();
        void setMap(vector<vector<Room*>>* newMapPtr);
        Room* getRoom(const int x, const int y);
        Room* getPlayerRoom();
        int getPlayerX() const;
        int getPlayerY() const;
        int getWidth() const;
        int getHeight() const;
        void setPlayerCoords(const int x,const int y);
        void setMapDimensions(const int newWidth,const int newHeight);

};

#endif /* DUNGEONMAP_HPP */