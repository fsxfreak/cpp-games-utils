#include <Room.hpp>

#include <algorithm>
#include <iostream>
#include <list>
#include <memory>
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

Room::Room(const std::string& name, std::list<std::unique_ptr<Item>> items) 
    : items(std::move(items)), name(name) 
{ }

Room::Room(Room&& other)
    : items(std::move(other.items)), name(std::move(other.name)) 
{ }

void Room::printItems() const
{
    if (items.size() == 0)
    {
        std::cout << "This room has nothing of use in it." << std::endl;
        return;
    }

    std::cout << "This room contains: ";
    for (auto& e : items)
    {
        std::cout << e->getName() << ", ";
    }
    std::cout << "\b\b." << std::endl;
}

void Room::printNeighbors() const
{
    if (doors.size() == 0)
        return;

    std::string verb = doors.size() > 1 ? "are " : "is ";
    std::string doorNoun = doors.size() > 1 ? " doors" : " door";
    std::cout << "There " << verb << doors.size() 
              << doorNoun << " in this room leading to ";

    std::vector<std::shared_ptr<Door>>::const_iterator it = doors.begin();
    std::vector<std::shared_ptr<Door>>::const_iterator itend = doors.end();
    for (; it != itend; ++it)
    {
        if (it == doors.end() - 1 && it != doors.begin())
        {
            if (doors.size() == 2)
                std::cout << "\b\b ";
            std::cout << "and ";
        }
            

        std::cout << transformSpecialName((*it)->getNextRoom(this)->getName())
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

std::unique_ptr<Item> Room::retrieveItem(const std::string& itemName)
{
    auto item = std::find_if(items.begin(), items.end(), 
                    [&] (const std::unique_ptr<Item>& item) -> bool {
                        return itemName.compare(item->getName()) == 0;
                    }
                );

    if (item == items.end()) return nullptr;

    std::unique_ptr<Item> pItem = std::move(*item);
    items.erase(item);

    return pItem;
}

void Room::leaveItem(std::unique_ptr<Item> item)
{
    items.push_back(std::move(item));
}

void Room::connectTo(Room *other)
{
    std::vector<std::shared_ptr<Door>> otherDoors = other->doors;

    std::vector<std::shared_ptr<Door>>::iterator existingDoor 
        = std::find_if(otherDoors.begin(), otherDoors.end(),
            [&] (const std::shared_ptr<Door>& door) -> bool {
                return door->getNextRoom(other) == this;
            }
    );

    if (existingDoor != otherDoors.end())
    {
        auto iAlreadyHaveDoor = 
            [&] (const std::shared_ptr<Door>& door) {
                return door == *existingDoor;
            };

        if (std::find_if (doors.begin(), doors.end(), iAlreadyHaveDoor) == doors.end())
            doors.push_back(std::shared_ptr<Door>(*existingDoor));
        
        return;
    }

    doors.emplace_back(std::make_shared<Door>(this, other));
    other->connectTo(this);
}

std::vector<Room*> Room::getNeighbors() const
{
    std::vector<Room*> neighbors;
    std::for_each (doors.begin(), doors.end(),
        [&] (const std::shared_ptr<Door>& door) {
            neighbors.push_back(door->getNextRoom(this));
        }
    );
    return neighbors;
}