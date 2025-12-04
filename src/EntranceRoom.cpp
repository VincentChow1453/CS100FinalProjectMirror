#include "../header/EntranceRoom.hpp" 
#include "../header/EncounterMenu.hpp"
#include <iostream>
using namespace std;
void EntranceRoom::TriggerRoom(){//Entrance doesn't do anything when you enter it.
    cout<<"This is the entrance. There is nothing more here for you to do."<<endl;
    return;
}
