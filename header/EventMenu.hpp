#ifndef EVENT_MENU_H
#define EVENT_MENU_H

#include "CharacterClass.h"
#include <string>

void eventMenu(CharacterClass& player);

// each event handler
void event1(CharacterClass& player);
void event2(CharacterClass& player);
void event3(CharacterClass& player);
void event4(CharacterClass& player);

// outcome effect functions
void event1Good(CharacterClass& player);
void event1Bad(CharacterClass& player);
void event1Neutral(CharacterClass& player);

void event2Good(CharacterClass& player);
void event2Bad(CharacterClass& player);
void event2Neutral(CharacterClass& player);

void event3Good(CharacterClass& player);
void event3Bad(CharacterClass& player);
void event3Neutral(CharacterClass& player);

void event4Good(CharacterClass& player);
void event4Bad(CharacterClass& player);
void event4Neutral(CharacterClass& player);

#endif