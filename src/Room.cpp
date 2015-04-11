#include <Room.hpp>

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

Room::Room(const std::string& name, const std::list<Item>& items) 
    : items(items), name(name) 
{ }

void Room::printItems() const
{
    std::cout << "This room contains: ";
    for (auto e : items)
    {
        std::cout << e.getName() << ", ";
    }
    std::cout << "\b\b." << std::endl;
}

const std::string& Room::getName() const { return name; }

Item Room::retrieveItem(const std::string& item)
{
    //find item in list
    //remove from list
    //return by move from list
    return Item();
}

void Room::leaveItem(Item item)
{
    items.push_back(item);
}

void Room::connectTo(Room *other)
{
    auto doorExistsAlready = [&] (const Door& door) {
        return door.getNextRoom(this) == other;
    };
    if (std::find_if(doors.begin(), doors.end(), doorExistsAlready) 
        != doors.end())
    {
        doors.emplace_back(this, other);
    }
}