#include "../header/EventRoom.hpp" 
#include "../header/EventMenu.hpp"
#include <iostream>
using namespace std;
void EventRoom::TriggerRoom(){//This will be the general layout for all Room types.
    activated=true;
    EventMenu menu;//Replace EncounterMenu with whatever menu you're working with, eg. BattleMenu, EventMenu, ShopMenu.
    menu.startEncounter(this);
    cout<<"Room TriggerRoom() stub"<<endl;
}
void EventRoom::OutputMapSymbol()const{
    cout<<"E";
}