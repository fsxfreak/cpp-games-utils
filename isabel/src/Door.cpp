#include <Door.hpp>

#include <iostream>

Door::Door(Room* const left, Room* const right)
    : isUnlocked(true), left(left), right(right)
{ }

const Room* Door::getNextRoom(const Room* fromThis) const
{
    if      (fromThis == left)  return right;
    else if (fromThis == right) return left;
    else                        return nullptr;
}

bool Door::locked() { return !isUnlocked; }

void Door::unlock(const Item& withItem)
{
    if (withItem.getUID() == lockRequirement)
    	isUnlocked = true;
}

void Door::require(int itemUID) { isUnlocked = false; lockRequirement = itemUID; }