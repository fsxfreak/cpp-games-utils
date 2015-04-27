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

const int Room::getUIDForItem(const std::string& itemName) const
{
    std::list<std::unique_ptr<Item>>::const_iterator item
        = std::find_if(items.begin(), items.end(),
            [&] (const std::unique_ptr<Item>& item) -> bool {
                return itemName.compare(item->getName()) == 0;
            }
        );

    return item != items.end() ? (*item)->getUID() : -1;
}

std::shared_ptr<Door> Room::connectTo(Room *other)
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
        
        return *existingDoor;
    }

    doors.emplace_back(std::make_shared<Door>(this, other));

    return other->connectTo(this);
}

std::shared_ptr<Door> Room::getDoorTo(const std::string& roomName) const
{
    auto lowercase = 
        [] (std::string str) -> std::string {
            std::transform(str.begin(), str.end(), str.begin(), ::tolower);
            return str;
        };

    auto insensitiveCompare =
        [&] (std::string left, std::string right) -> bool {
            char sanitize[] = " \'";

            for (int i = 0; i < 2; i++)
            {
                left.erase(std::remove(left.begin(), left.end(), sanitize[i]), left.end());
                right.erase(std::remove(right.begin(), right.end(), sanitize[i]), right.end());
            }

            left = lowercase(left);
            right = lowercase(right);

            return left.compare(right) == 0;
        };

    auto doorIterator = std::find_if (doors.begin(), doors.end(),
        [&] (const std::shared_ptr<Door>& door) {
            return insensitiveCompare(door->getNextRoom(this)->getName(), roomName);
        }
    );

    return doorIterator != doors.end() ? *doorIterator : nullptr;
}