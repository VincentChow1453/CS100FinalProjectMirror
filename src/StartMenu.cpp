#include "../header/StartMenu.hpp"
#include "../header/MapNavigationMenu.hpp"
#include <iostream>
using namespace std;
void StartMenu::LoadGameOption(){
    cout<<"LoadGameOption() stub. Pretend there's a list of saved games here to chose from."<<endl;
    OpenMenu();
}
void StartMenu::SettingsOption(){
    cout<<"SettingsOption() stub. Pretend there's a bunch of settings and options and even more choices to make here"<<endl;
    OpenMenu();
}
void StartMenu::StartNewGameOption(){
    cout<<"StartNewGameOption() stub"<<endl;
    
}
void StartMenu::OpenMenu(){
    cout<<"Welcome to GAME NAME. Please pick an option by typing in a number, or anything to start a new game."<<endl;
    cout<<"1. Start a New Game"<<endl;
    cout<<"2. Settings and Options"<<endl;
    cout<<"3. Load Saved Game"<<endl;
    string playerChoice;//It's string because the player can technically enter anything to start the game because I'm too lazy for input validation.
    cin>>playerChoice;
    if(playerChoice=="2"){
        SettingsOption();
        return;
    }
    if(playerChoice=="3"){
        LoadGameOption();
        return;
    }
    StartNewGameOption();
}