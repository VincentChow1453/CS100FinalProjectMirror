#ifndef ROOM_HPP
#define ROOM_HPP
class Room{
    private:
        bool activated;
    public:
        virtual void TriggerRoom()=0; //Room should be an abstract class once we create its subclasses.
};
#endif //ROOM_HPP
