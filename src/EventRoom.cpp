#include "../header/EventRoom.hpp" 
#include "../header/EventMenu.hpp"
#include <iostream>
using namespace std;
void EventRoom::TriggerRoom(){
    activated=true;
    EventMenu menu;
    menu.startEncounter(this);
}
void EventRoom::OutputMapSymbol()const{
    cout<<"E";
}