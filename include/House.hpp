#ifndef HOUSE_HPP
#define HOUSE_HPP

#include <vector>
#include <Room.hpp>

class House
{
public:
    House();
private:
    std::vector<Room> rooms;
};

#endif