#include <Player.hpp>

void Player::give(std::unique_ptr<Item> item) { inventory.push_back(std::move(item)); }

const std::vector<std::string> Player::getItemNames() const
{
	if (inventory.size() == 0)
		return {};

	std::vector<std::string> itemNames;
	for (auto &e : inventory)
	{
		itemNames.push_back(e->getName());
	}
	return itemNames;
}

Room* Player::getCurrentRoom() const { return currentRoom; }
void Player::moveTo(Room* room) { currentRoom = room; }