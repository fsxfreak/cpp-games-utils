#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <items/Item.hpp>
#include <Room.hpp>
#include <vector>

class Player
{
public:
	Player(Room* startingRoom);

	Room * const getCurrentRoom() const;

private:
    std::vector<Item> inventory;
    Room * const currentRoom;
};

#endif
