#include "EncounterMenu.hpp"
#include <iostream>
using namespace std;
void EncounterMenu::startEncounter(Room *newRoom){
    thisRoom=newRoom;
    displayMenu();
    int option;
    cin>>option;
    chooseOption(option);
    //I'm thinking we will recursively call chooseOption(option) until we're finished with the encounter.
    //Once this function is finished, it will return to the navigation menu.
}