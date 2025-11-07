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
    public:
        vector<vector<Room*>> GenerateMap(int numRooms);
};

#endif /* DUNGEONGENERATOR_HPP */