#pragma once
#include "./Room.hpp"

class EncounterMenu{
    private:
        Room* currRoom;
        virtual void displayMenu() const=0;
        virtual void chooseOption(int option)=0;
    public:
        virtual void startEncounter(Room *newRoom)=0;
};