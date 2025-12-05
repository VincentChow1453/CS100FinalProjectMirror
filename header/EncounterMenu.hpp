#pragma once
#include "./CharacterClass.hpp"
#include "./Room.hpp"
class EncounterMenu{
    private:
        Room* currRoom;
        virtual void displayMenu() const;
        virtual void chooseOption(int option);
    public:
        virtual void startEncounter(Room *newRoom);
};