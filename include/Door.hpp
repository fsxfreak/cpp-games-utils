#ifndef DOOR_HPP
#define DOOR_HPP

#include <Room.hpp>

//it's like a pointer, but with checks

class Door
{
public:
    Door(Room* const left, Room* const right);

    void unlock(const Item& withItem);

    //can I overload operator-> lol
    Room* getNextRoom(Room *fromThis) const;
private:
    bool isUnlocked;
    //TODO add item requirement to unlock

    Room *const left;
    Room *const right;
};

#endif