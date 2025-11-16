#ifndef MAPNAVIGATIONMENU_HPP
#define MAPNAVIGATIONMENU_HPP
#include "DungeonMap.hpp"
#include "MapGenerator.hpp"

class MapNavigationMenu {
    private:
        DungeonMap map;
        MapGenerator generator;
    public:
        MapNavigationMenu();
        MapNavigationMenu(int numRooms, int newWidth, int newHeight);
        DungeonMap* getMap();
        void GoLeft();
        void GoRight();
        void GoUp();
        void GoDown();
};

#endif /* MAPNAVIGATIONMENU_HPP */