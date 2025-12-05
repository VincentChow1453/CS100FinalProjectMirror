#ifndef DUNGEONGENERATOR_HPP
#define DUNGEONGENERATOR_HPP
#include "Room.hpp"
#include <vector>
#include "DungeonMap.hpp"
using std::vector;

class MapGenerator {
    private:
    public:
        static void GenerateMap(int numRooms, const int mapWidth, const int mapHeight, DungeonMap* dunMapPtr);
};

#endif /* DUNGEONGENERATOR_HPP */