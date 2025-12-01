#ifndef DUNGEONGENERATOR_HPP
#define DUNGEONGENERATOR_HPP
#include "Room.hpp"
#include <vector>
using std::vector;

class MapGenerator {
    private:
    public:
        static vector<vector<Room*>>* GenerateMap(int numRooms, const int mapWidth, const int mapHeight);
};

#endif /* DUNGEONGENERATOR_HPP */