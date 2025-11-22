#include "../header/Room.hpp" 
#include "../header/EncounterMenu.hpp"
#include <iostream>
using namespace std;
void Room::TriggerEncounter(){//This will be the general layout for all Room types.
    activated=true;
    EncounterMenu = menu;//Replace this line with whatever menu you're working with.
    menu.StartEncounter(this);
    cout<<"Room stub"<<endl;
}
