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

    //somehow return item by move?
    std::unique_ptr<Item> retrieveItem(const std::string& itemName);
    //somehow take item by move
    void leaveItem(std::unique_ptr<Item> item);

    void connectTo(Room *other);

    std::vector<Room*> getNeighbors() const;
private:
    std::list<std::unique_ptr<Item>> items;
    std::vector<Door> doors;
    const std::string name;
};

#endif