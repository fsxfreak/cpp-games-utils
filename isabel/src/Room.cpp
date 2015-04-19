#include <Room.hpp>

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

//lowercase strings if not Someone's bedroom
//append "the" if not someone's bedroom
std::string transformSpecialName(const std::string& str)
{
    bool isSpecial = str.find('\'') != std::string::npos;

    std::string copy = str;
    if (isSpecial)
        return copy;
    
    copy.insert(0, "the ");

    return copy;
}

Room::Room(const std::string& name, std::list<Item> items) 
    : items(std::move(items)), name(name) 
{ }

void Room::printItems() const
{
    std::cout << "This room contains: ";
    for (auto& e : items)
    {
        std::cout << e.getName() << ", ";
    }
    std::cout << "\b\b." << std::endl;
}

void Room::printNeighbors() 
{
    if (doors.size() == 0)
        return;

    std::cout << "There are " << doors.size() 
              << " doors in this room leading to ";

    for (unsigned int i = 0; i < doors.size(); i++)
    {
        if (i == doors.size() - 1)
            std::cout << "and ";

        std::cout << transformSpecialName(doors[i].getNextRoom(this)->getName())
                  << ", ";
    }

    std::cout << "\b\b." << std::endl;
}

const std::string& Room::getName() const { return name; }

void Room::printPrettyName() const
{
    std::string print = "You are in ";
    print += transformSpecialName(name) + ".";
    std::cout << print << std::endl;
}

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
        == doors.end())
    {

        doors.emplace_back(this, other);
    }
}
