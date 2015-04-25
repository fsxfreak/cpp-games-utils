#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <items/Item.hpp>
#include <Room.hpp>
#include <vector>

class Player
{
public:
	Player() = default;

	Room* getCurrentRoom() const;
	void moveTo(Room* room);
private:
    std::vector<Item> inventory;
    Room* currentRoom = nullptr;
};

#endif
