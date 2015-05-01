#include <Player.hpp>
#include <algorithm>

void Player::give(std::unique_ptr<Item> item) { inventory.push_back(std::move(item)); }

std::unique_ptr<Item> Player::take(const std::string& itemName)
{
	return nullptr;
}

const int Player::getUIDForItem(const std::string& itemName) const 
{
	std::vector<std::unique_ptr<Item>>::const_iterator item
        = std::find_if(inventory.begin(), inventory.end(),
            [&] (const std::unique_ptr<Item>& item) -> bool {
                return itemName.compare(item->getName()) == 0;
            }
        );

    return item != inventory.end() ? (*item)->getUID() : -1;
}

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