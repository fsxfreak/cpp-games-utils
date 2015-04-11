#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <items/Item.hpp>
#include <unordered_set>

class Room
{
public:
    Room(const std::string& name, const std::unordered_set<Item>& items);

    void printItems() const;
    const std::string& getName() const; //may not need this, may just need a pretty print
                                        //how to identify different rooms from each other?

    //somehow return item by move?
    Item retrieveItem(const std::string& item);
    //somehow take item by move
    void leaveItem(Item item);
protected:
    std::unordered_set<Item> items;
private:
    const std::string name;

};

#endif