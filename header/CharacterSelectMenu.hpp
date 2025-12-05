#pragma once
#include "../header/CharacterClass.hpp"
//#include "../header/mageClass.h"
//#include "../header/warriorClass.h"
//#include "../header/assassinClass.h"
#include <vector>
using namespace std;
class CharacterSelectMenu{
    private:
        static void displayClasses();
        static CharacterClass* selectCharacterHelper();
    public: 
        
        static CharacterClass* player;
        static void selectCharacter();

};