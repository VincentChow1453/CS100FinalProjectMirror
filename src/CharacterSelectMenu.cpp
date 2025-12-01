#include <iostream>
#include "CharacterSelectMenu.hpp"
using namespace std;
void CharacterSelectMenu::displayClasses(){
    cout<<"Here are the classes available to you."<<endl;
    cout<<"1. Mage"<<endl;
    cout<<"2. Warrior"<<endl;
    cout<<"3. Assassin"<<endl;
}
CharacterClass CharacterSelectMenu::selectCharacterHelper(){
    cout<<"Select a character by entering a number"<<endl;
    int playerChoice;
    cin>>playerChoice;
    if(!cin>>playerChoice){
        cin.clear();
        throw runtime_error("Invalid input for selectCharacterHelper()");
    }
    if(playerChoice==1){
        cout<<"You have selected the Mage."<<endl;
    }
    else if(playerChoice==2){
        cout<<"You have selected the Warrior."<<endl;
    }
    else if(playerChoice==3){
        cout<<"You have selected the Assassin."<<endl;
    }
    else{
        throw runtime_error("Invalid character select option");
    }
    cout<<"Now your hero needs a name. Please enter a name."<<endl;
    string newName;
    cin>>newName;
    if(playerChoice==1){
        cout<<"You have selected the wize Mage "<<newName<<"."<<endl;
        return CharacterClass("Mage",newName,1,1,1,1,1);//replace this with mageClass
    }
    if(playerChoice==2){
        cout<<"You have selected the brave Warrior "<<newName<<"."<<endl;
        return CharacterClass("Warrior",newName,1,1,1,1,1);//replace this with warriorClass
    }
    cout<<"You are the sneaky Assassin "<<newName<<"."<<endl;
    return CharacterClass("Assassin",newName,1,1,1,1,1);//replace this with assassinClass
}
CharacterClass CharacterSelectMenu::selectCharacter(){
    displayClasses();
    return selectCharacterHelper();
}