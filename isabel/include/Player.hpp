#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <items/Item.hpp>
#include <Room.hpp>
#include <vector>

class Player
{
public:
	Player(Room* startingRoom);
private:
    std::vector<Item> inventory;
    Room *currentRoom;
};

#endif
