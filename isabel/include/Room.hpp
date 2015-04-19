#ifndef ROOM_HPP
#define ROOM_HPP

#include <Door.hpp>
#include <string>
#include <items/Item.hpp>
#include <list>
#include <vector>

class Door;

class Room
{
public:
    Room(const std::string& name, std::list<Item> items);

    void printItems() const;
    void printNeighbors();
    void printPrettyName() const;
    const std::string& getName() const; //may not need this, may just need a pretty print
                                        //how to identify different rooms from each other?

    //somehow return item by move?
    Item retrieveItem(const std::string& item);
    //somehow take item by move
    void leaveItem(Item item);

    void connectTo(Room *other);
private:
    std::list<Item> items;
    std::vector<Door> doors;
    const std::string name;
};

#endif