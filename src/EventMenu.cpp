#include "EventMenu.hpp"
#include "EventRoom.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

EventMenu::EventMenu() {
    events.push_back(std::make_unique<Event1>());
    events.push_back(std::make_unique<Event2>());
    events.push_back(std::make_unique<Event3>());
    events.push_back(std::make_unique<Event4>());
}

void EventMenu::startEncounter(Room* newRoom) {
    srand(time(nullptr));

    int idx = rand() % events.size();
    Event* currentEvent = events[idx].get();

    // Convert generic Room* to EventRoom*
    EventRoom* er = dynamic_cast<EventRoom*>(newRoom);
    if (!er) {
        cout << "Error: This room cannot trigger an event.\n";
        return;
    }

    CharacterClass* player = er->getPlayer();
    if (!player) {
        cout << "Error: No player assigned to room.\n";
        return;
    }

    currentEvent->displayMenu();

    int option;
    cin >> option;

    currentEvent->chooseOption(option, *player);
}
