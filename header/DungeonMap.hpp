#ifndef DUNGEONMAP_HPP
#define DUNGEONMAP_HPP
#include "Room.hpp"
#include <vector>
using std::vector;
class DungeonMap {
    private:
        int playerX, playerY;
        int mapWidth,mapHeight;//width=x, height=y
        int floorLevel;
    public:
        vector<vector<Room*>> mapMatrix;
        void DisplayMap();

};

#endif /* DUNGEONMAP_HPP */