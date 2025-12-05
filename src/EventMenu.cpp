#include "EventMenu.hpp"
#include "CharacterSelectMenu.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

EventMenu::EventMenu() {
    events.push_back(make_unique<Event1>());
    events.push_back(make_unique<Event2>());
    events.push_back(make_unique<Event3>());
    events.push_back(make_unique<Event4>());
}

void EventMenu::startEncounter(Room* newRoom) {
    srand(time(nullptr));

    int idx = rand() % events.size();
    Event* currentEvent = events[idx].get();

    //get global player
    CharacterClass* player = CharacterSelectMenu::player;
    if (!player) {
        cout << "Error: Player not selected yet!\n";
        return;
    }

    currentEvent->displayMenu();

    int option;
    cin >> option;

    currentEvent->chooseOption(option);
}
