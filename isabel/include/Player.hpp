#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <items/Item.hpp>
#include <Room.hpp>
#include <vector>

class Player
{
public:
	Player() = default;

	void give(std::unique_ptr<Item> item);
	const std::vector<std::string> getItemNames() const;

	const Room* getCurrentRoom() const;
	void moveTo(const Room* room);
private:
    std::vector<std::unique_ptr<Item>> inventory;
    const Room* currentRoom = nullptr;
};

#endif
