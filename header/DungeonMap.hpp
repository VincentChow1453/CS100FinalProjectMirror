#ifndef DUNGEONMAP_HPP
#define DUNGEONMAP_HPP
#include "Room.hpp"
#include "MapGenerator.hpp"
#include <vector>
using std::vector;
class DungeonMap {
    private:
        int playerX, playerY;
        int width,height;//width=x, height=y
        int floorLevel;
    public:
        DungeonMap();
        ~DungeonMap();
        vector<vector<Room*>>* mapMatrix=nullptr;
        Room* getRoom(const int x, const int y);
        Room* getPlayerRoom();
        void DisplayMap() const;
        int getPlayerX() const;
        int getPlayerY() const;
        int getWidth() const;
        int getHeight() const;
        void setPlayerCoords(const int x,const int y);
        void setMapDimensions(const int newWidth,const int newHeight);

};

#endif /* DUNGEONMAP_HPP */