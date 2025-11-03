#ifndef MAPNAVIGATIONMENU_HPP
#define MAPNAVIGATIONMENU_HPP
#include "DungeonMap.hpp"

class MapNavigationMenu {
    private:
    public:
        void GoLeft(DungeonMap* currMap);
        void GoRight(DungeonMap* currMap);
        void GoUp(DungeonMap* currMap);
        void GoDown(DungeonMap* currMap);
};

#endif /* MAPNAVIGATIONMENU_HPP */