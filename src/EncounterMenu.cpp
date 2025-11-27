#include "EncounterMenu.hpp"
#include <iostream>
using namespace std;
void EncounterMenu::displayMenu() const{
    cout<<"EncounterMenu DisplayMenu() stub"<<endl;
}
void EncounterMenu::chooseOption(int option){
    cout<<"EncounterMenu ChooseOption("<<option<<") stub"<<endl;
}
void EncounterMenu::startEncounter(Room *newRoom){
    currRoom=newRoom;
    displayMenu();
    int option;
    //cin>>option;
    option=1;//stub
    chooseOption(option);
    //I'm thinking we will recursively call chooseOption(option) until we're finished with the encounter.
    //Once this function is finished, it will return to the navigation menu.
}