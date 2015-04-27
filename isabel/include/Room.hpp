#ifndef ROOM_HPP
#define ROOM_HPP

#include <Door.hpp>
#include <string>
#include <items/Item.hpp>
#include <list>
#include <memory>
#include <vector>

class Door;

class Room
{
public:
    Room(const std::string& name, std::list<std::unique_ptr<Item>> items);
    Room(Room&& other);

    void printItems() const;
    void printNeighbors() const;
    void printPrettyName() const;
    const std::string& getName() const;

    std::unique_ptr<Item> retrieveItem(const std::string& itemName);
    void leaveItem(std::unique_ptr<Item> item);
    const int getUIDForItem(const std::string& itemName) const; 

    std::shared_ptr<Door> connectTo(Room *other);
    std::shared_ptr<Door> getDoorTo(const std::string& roomName) const;
private:
    std::list<std::unique_ptr<Item>> items;
    std::vector<std::shared_ptr<Door>> doors;
    const std::string name;
};

#endif