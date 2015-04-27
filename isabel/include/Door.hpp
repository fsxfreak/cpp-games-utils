#ifndef DOOR_HPP
#define DOOR_HPP

#include <Room.hpp>
#include <items/Item.hpp>

//it's like a double ended pointer, but with checks

class Room;

class Door
{
public:
    Door(Room* const left, Room* const right);
    void unlock(const Item& withItem);
    bool locked();
    void require(int itemUID);
    const Room* getNextRoom(const Room* fromThis) const;
private:
    bool isUnlocked;
    int lockRequirement;

    Room *const left;
    Room *const right;
};

#endif