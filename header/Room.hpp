#ifndef ROOM_HPP
#define ROOM_HPP
#include <string>
using namespace std;
class Room{
    private:
        bool activated;
    public:
        virtual void TriggerRoom();
        virtual void OutputMapSymbol() const;
};
#endif
