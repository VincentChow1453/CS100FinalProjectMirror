#ifndef DUNGEONMAP_HPP
#define DUNGEONMAP_HPP
#include "DungeonMap.hpp"
#include "Room.hpp"
#include <vector>
using std::vector;

class MapGenerator {
    private:
        int currX, currY;
        int numRoomsLeft;
        int entranceX,entranceY;
    public:
        vector<vector<Room>>* GenerateMap(int numRooms);
};

#endif /* DUNGEONMAP_HPP */