#include "../header/Room.hpp" 
#include "../header/EncounterMenu.hpp"
#include <iostream>
using namespace std;
void Room::TriggerRoom(){//This will be the general layout for all Room types.
    activated=true;
    EncounterMenu = menu;//Replace EncounterMenu with whatever menu you're working with, eg. BattleMenu, EventMenu, ShopMenu.
    menu.StartEncounter(this);
    cout<<"Room stub"<<endl;
}
