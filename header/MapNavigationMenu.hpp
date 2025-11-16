#ifndef MAPNAVIGATIONMENU_HPP
#define MAPNAVIGATIONMENU_HPP
#include "DungeonMap.hpp"
#include "MapGenerator.hpp"

class MapNavigationMenu {
    private:
        DungeonMap map;
    public:
        DungeonMap* getMap();
        void GoLeft();
        void GoRight();
        void GoUp();
        void GoDown();
};

#endif /* MAPNAVIGATIONMENU_HPP */