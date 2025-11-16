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
        MapNavigationMenu(const int numRooms,const int newWidth,const int newHeight);
        DungeonMap* getMap();
        void GoLeft();
        void GoRight();
        void GoUp();
        void GoDown();
};

#endif /* MAPNAVIGATIONMENU_HPP */