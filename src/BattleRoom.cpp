#include "BattleRoom.hpp"
#include <iostream>
using namespace std;

void BattleRoom::TriggerRoom() {
    cout << "Entering Battle Room!\n";
    menu->startEncounter(this); 
}
