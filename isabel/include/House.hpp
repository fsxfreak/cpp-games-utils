#ifndef HOUSE_HPP
#define HOUSE_HPP

#include <vector>
#include <Room.hpp>
#include <items/Item.hpp>

class House
{
public:
    House();
private:
    std::vector<Room> rooms;
};

#endif