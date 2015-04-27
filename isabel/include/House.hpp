#ifndef HOUSE_HPP
#define HOUSE_HPP

#include <vector>
#include <Room.hpp>
#include <items/Item.hpp>

class House
{
public:
    House();
    
    Room* getRoom(const std::string& roomName);
private:
    std::vector<Room> rooms;
};

#endif