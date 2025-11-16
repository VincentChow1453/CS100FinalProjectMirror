#ifndef DUNGEONMAP_HPP
#define DUNGEONMAP_HPP
#include "Room.hpp"
#include "MapGenerator.hpp"
#include <vector>
using std::vector;
class DungeonMap {
    private:
        int playerX, playerY;
        int width=5,height=5;//width=x, height=y
        int floorLevel;
        MapGenerator generator;
    public:
        ~DungeonMap();
        vector<vector<Room*>> mapMatrix;
        void DisplayMap();
        int getPlayerX();
        int getPlayerY();
        int getWidth();
        int getHeight();
        void setPlayerCoords(int x, int y);

};

#endif /* DUNGEONMAP_HPP */