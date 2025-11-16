#ifndef ROOM_H
#define ROOM_H
class Room{
    private:
        bool activated;
    public:
        void virtual TriggerEncounter();//=0; //Room should be an abstract class once we create its subclasses.
};
#endif //ROOM_HPP