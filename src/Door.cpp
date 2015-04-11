#include <Door.hpp>

#include <iostream>

Door::Door(Room* const left, Room* const right)
    : isUnlocked(false), left(left), right(right)
{ }

Room* Door::getNextRoom(Room *fromThis) const
{
    if      (fromThis == left)  return right;
    else if (fromThis == right) return left;
    else                        return nullptr;
}

void Door::unlock(const Item& withItem)
{
    //if withItem matches requirement item
    isUnlocked = true;
}