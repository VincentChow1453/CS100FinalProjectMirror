#ifndef MAPNAVIGATIONMENU_HPP
#define MAPNAVIGATIONMENU_HPP
#include "DungeonMap.hpp"
#include "MapGenerator.hpp"
#include "MiscMenu.hpp"
class MapNavigationMenu : MiscMenu{
    private:
        DungeonMap map;
    protected:
        void displayMenu() const override;//helper class for startMenu
        void chooseOption(const int option) override;//helper class for startMenu
    public:
        void startMenu() override;
        MapNavigationMenu();
        MapNavigationMenu(const int numRooms,const int newWidth,const int newHeight);
        DungeonMap* getMap();
        void GoLeft();
        void GoRight();
        void GoUp();
        void GoDown();
};

#endif /* MAPNAVIGATIONMENU_HPP */