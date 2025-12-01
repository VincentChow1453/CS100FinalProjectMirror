#include "EventMenu.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void eventMenu(CharacterClass& player) {
    srand(5); // fixed seed for testing (change/remove for randomness)

    int randomEvent = rand() % 4 + 1;

    switch (randomEvent) {
        case 1: event1(player); break;
        case 2: event2(player); break;
        case 3: event3(player); break;
        case 4: event4(player); break;
    }
}

//event 1: shady traveller
void event1(CharacterClass& player) {
    cout << "A shady traveler appears! What do you do?\n";

    while (true) {
        cout << "1. Leave\n";
        cout << "2. Attack him\n";
        cout << "3. Barter with him\n";

        int choice;
        cin >> choice;

        if (choice == 1) { event1Neutral(player); return; }
        if (choice == 2) { event1Bad(player); return; }
        if (choice == 3) { event1Good(player); return; }

        cout << "\nInvalid choice — please pick 1, 2, or 3.\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void event1Neutral(CharacterClass& player) {
    cout << "You decide to leave calmly. You feel an eerie stare on your back...\n";
}

void event1Bad(CharacterClass& player) {
    cout << "You attack the traveler, but he was a skilled fighter!\n";
    cout << "He wounds you before escaping. I can't believe you did that. (-10 health)\n";

    player.setBaseHealth(player.getBaseHealth() - 10);
}

void event1Good(CharacterClass& player) {
    cout << "You barter with the traveler.\n";
    cout << "You drive a hard bargain. Who knew you were such a good merchant? (+20 gold)\n";

    player.setGold(player.getGold() + 20);
}


//event 2: potion
void event2(CharacterClass& player) {
    cout << "You find a glowing potion on the ground.\n";

    while (true) {
        cout << "1. Ignore it\n";
        cout << "2. Drink it\n";
        cout << "3. Throw it away\n";

        int choice;
        cin >> choice;

        if (choice == 1) { event2Neutral(player); return; }
        if (choice == 2) { event2Good(player); return; }
        if (choice == 3) { event2Bad(player); return; }

        cout << "\nInvalid choice — please pick 1, 2, or 3.\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}


void event2Neutral(CharacterClass& player) {
    cout << "You leave the potion. Nothing happens. I can't believe you didn't drink a random substance you found!\n";
}

void event2Good(CharacterClass& player) {
    cout << "You drink the potion! It restores your mana. (+10 mana)\n";
    player.setBaseMana(player.getBaseMana() + 10);
}

void event2Bad(CharacterClass& player) {
    cout << "You throw it away, but it explodes! (-5 health)\n";
    player.setBaseHealth(player.getBaseHealth() - 5);
}


// event 3: chest
void event3(CharacterClass& player) {
    cout << "You discover a locked chest.\n";

    while (true) {
        cout << "1. Leave it\n";
        cout << "2. Pick the lock\n";
        cout << "3. Smash it open\n";

        int choice;
        cin >> choice;

        if (choice == 1) { event3Neutral(player); return; }
        if (choice == 2) { event3Good(player); return; }
        if (choice == 3) { event3Bad(player); return; }

        cout << "\nInvalid choice — please pick 1, 2, or 3.\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}


void event3Neutral(CharacterClass& player) {
    cout << "You walk away. Nothing changes. Not very adventurous, are we?\n";
}

void event3Good(CharacterClass& player) {
    cout << "You carefully pick the lock and find a rare gem! (+Rare Gem, +40 gold)\n";
    player.addItem("Rare Gem");
    player.setGold(player.getGold() + 40);
}

void event3Bad(CharacterClass& player) {
    cout << "You smash the chest. The contents spill everywhere and into the cracks of the ground. You scrounge up what you can. (+10 gold)\n";
    player.setGold(player.getGold() + 10);
}


//event 4: child
void event4(CharacterClass& player) {
    cout << "A lost child asks for help.\n";

    while (true) {
        cout << "1. Ignore them\n";
        cout << "2. Help them\n";
        cout << "3. Steal from them\n";

        int choice;
        cin >> choice;

        if (choice == 1) { event4Neutral(player); return; }
        if (choice == 2) { event4Good(player); return; }
        if (choice == 3) { event4Bad(player); return; }

        cout << "\nInvalid choice — please pick 1, 2, or 3.\n\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void event4Neutral(CharacterClass& player) {
    cout << "You walk past. Shame on you. Still, nothing happens.\n";
}

void event4Good(CharacterClass& player) {
    cout << "You help the child reunite with their parents!\n";
    cout << "They are grateful and reward you for your noble deed. (+25 gold)\n";
    player.setGold(player.getGold() + 25);
}

void event4Bad(CharacterClass& player) {
    cout << "You steal from the child...\n";
    cout << "Wow this kid was rich! Karma will probably get you though. (+75 gold)\n";
    player.setGold(player.getGold() + 75);
}
