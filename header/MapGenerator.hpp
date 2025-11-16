#ifndef DUNGEONGENERATOR_HPP
#define DUNGEONGENERATOR_HPP
#include "Room.hpp"
#include <vector>
using std::vector;

class MapGenerator {
    private:
        int currX, currY;
        int numRoomsLeft;
        int entranceX,entranceY;
        int mapWidth;//x
        int mapHeight;//y
        vector<vector<Room*>> GenerateMapHelper(int targetNumRooms, int numRoomsLeft,int entranceX, int entranceY, vector<vector<Room*>> currMap);
    public:
        vector<vector<Room*>> GenerateMap(int targetNumRooms);
};

#endif /* DUNGEONGENERATOR_HPP */