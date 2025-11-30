#include <iostream>
#include "StartMenu.hpp"
#include "CharacterSelectMenu.hpp"
#include "MapNavigationMenu.hpp"
#include "MapDisplayer.hpp"
using namespace std;

int main(){
    StartMenu::OpenMenu();
    CharacterSelectMenu::selectCharacter();
    MapNavigationMenu mapMenu(10,5,5);
    cout<<endl<<"Now we will enter the dungeon."<<endl;
    mapMenu.startMenu();

}