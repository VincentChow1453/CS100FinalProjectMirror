#include <iostream>
#include "CharacterSelectMenu.hpp"
using namespace std;
void CharacterSelectMenu::displayClasses() const{
    cout<<"Here are the classes available to you."<<endl;
    cout<<"1. Mage"<<endl;
    cout<<"2. Warrior"<<endl;
    cout<<"3. Assassin"<<endl;
    cout<<"Select one of them by entering a number"<<endl;
}
CharacterClass CharacterSelectMenu::selectCharacterHelper(const int option){
    if(option==1){
        cout<<"You have selected the Mage."<<endl;
        return CharacterClass("Mage","",0,0,0,0,0);//replace this with mageClass
    }
    if(option==2){
        cout<<"You have selected the Warrior."<<endl;
        return CharacterClass("Warrior","",0,0,0,0,0);//replace this with warriorClass
    }
    if(option==3){
        cout<<"You have selected the Assassin."<<endl;
        return CharacterClass("Assassin","",0,0,0,0,0);//replace this with assassinClass
    }
    throw runtime_error("Invalid character option");
}
CharacterClass CharacterSelectMenu::selectCharacter(){
    displayClasses();
    int playerChoice;
    cin>>playerChoice;
    return selectCharacterHelper(playerChoice);
}