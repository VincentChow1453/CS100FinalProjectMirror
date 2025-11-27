This README is just describing the changes I'm making in this branch.
My list of changes:
1. I renamed the Room class's TriggerEncounter() function to TriggerRoom(), and included a new implementation, which should be used as a template for the subclass implementations.
2. I created the EncounterMenu class, which should be a parent class to the EventMenu, BattleMenu, and ShopMenu classes.
    a. It has the DisplayMenu() and ChooseOption(int option) abstract functions with no implementation, 
    b. It also has the startEncounter(Room *newRoom) abstract function with an implementation.


This is the step by step process of how I'm thinking everything will work.
1. Using NavigationMenu, the player will move to a new room
2. NavigationMenu will call this room's TriggerRoom() function. 
    a.(TriggerRoom() is pure virtual, but I included an implementation as a template)
3. TriggerRoom() will:
    a.set the variable activated=true
    b.create a new EncounterMenu object called menu, then call menu.StartEncounter(Room* newRoom), sending in itself as a parameter.
4. StartEncounter(Room* newRoom) will:
    a.store newRoom in the currRoom variable
    b.call DisplayMenu()
        *DisplayMenu() just outputs some flavor text, the player's options, and asks the player for an action.
    c.Take in the player's input
    d.Call ChooseOption(int option).
        *This will execute the player's action
        *It will then either ask for the eplayer's input and recursively call itself, or it will simply finish and return.
5. StartEncounter(Room* newRoom) will then return to the NavigationMenu.
