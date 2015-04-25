#ifndef HOUSE_HPP
#define HOUSE_HPP

#include <vector>
#include <Room.hpp>
#include <items/Item.hpp>

class House
{
public:
    House();
    
    Room* getRoom(const std::string& roomName, Room* fromRoom = nullptr);
private:
    std::vector<Room> rooms;
};

#endif