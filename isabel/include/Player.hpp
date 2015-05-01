#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <items/Item.hpp>
#include <Room.hpp>
#include <string>
#include <vector>

class Player
{
public:
	Player() = default;

	const int getUIDForItem(const std::string& itemName) const;
	void give(std::unique_ptr<Item> item);
	std::unique_ptr<Item> take(const std::string& itemName);

	const std::vector<std::string> getItemNames() const;

	Room* getCurrentRoom() const;
	void moveTo(Room* room);
private:
    std::vector<std::unique_ptr<Item>> inventory;
    Room* currentRoom = nullptr;
};

#endif
