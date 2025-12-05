#ifndef MAPNAVIGATIONMENU_HPP
#define MAPNAVIGATIONMENU_HPP
#include "DungeonMap.hpp"
#include "MapGenerator.hpp"
#include "CharacterSelectMenu.hpp"
class MapNavigationMenu{
    private:
        DungeonMap map;
    protected:
        void displayMenu() const ;//helper class for startMenu
        void chooseOption(const int option) ;//helper class for startMenu
    public:
        void startMenu() ;
        ~MapNavigationMenu();
        MapNavigationMenu();
        MapNavigationMenu(const int numRooms,const int newWidth,const int newHeight);
        DungeonMap* getMap();
        void GoLeft();
        void GoRight();
        void GoUp();
        void GoDown();
};

#endif /* MAPNAVIGATIONMENU_HPP */