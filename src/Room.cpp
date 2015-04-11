#include <Room.hpp>

#include <iostream>
#include <unordered_set>
#include <string>

Room::Room(const std::string& name, const std::unordered_set<Item>& items) 
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
    //insert item into list
    items.push_back(item);
}