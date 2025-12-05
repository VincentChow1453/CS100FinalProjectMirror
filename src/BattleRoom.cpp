#include "BattleRoom.hpp"
#include <iostream>
using namespace std;
void BattleRoom::TriggerRoom() {
    cout << "Entering Battle Room!\n";
    BattleMenu new_menu_object; 
    new_menu_object.startEncounter(this);

} 
void BattleRoom::OutputMapSymbol()const{
    cout<<"B";
}