#include "../header/CharacterClass.h"
//#include "../header/mageClass.h"
//#include "../header/warriorClass.h"
//#include "../header/assassinClass.h"
#include <vector>
using namespace std;
class CharacterSelectMenu{
    private:
        static void displayClasses() const;
        static CharacterClass selectCharacter(const int option);
    public: 
        static CharacterClass selectCharacter();

};