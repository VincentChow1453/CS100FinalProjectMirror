#ifndef ROOM_HPP
#define ROOM_HPP
#include <string>
using namespace std;
class Room{
    private:
        bool activated;
    public:
        virtual ~Room()=default;
        virtual void TriggerRoom();//=0; //Room should be an abstract class once we create its subclasses.
        virtual void OutputMapSymbol() const;
};
#endif //ROOM_HPP
