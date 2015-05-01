#include <actions/UseAction.hpp>
#include <iostream>
#include <Player.hpp>

UseAction::UseAction(void *o) : Action(o) {}

void UseAction::usage() const
{ std::cout << "To use an item, input \'use\' \'item-name\' \'room-name\'." << std::endl;}

void UseAction::execute(const std::string& arg) const
{
    Player* player = static_cast<Player*>(obj);

    unsigned int index = arg.find(' ');
    const std::string itemName = arg.substr(0, index);
    const std::string roomName = arg.substr(index + 1, arg.size());

    std::cout << itemName << std::endl;
    std::cout << roomName << std::endl;

    const Room* currentRoom = player->getCurrentRoom();
    std::shared_ptr<Door> lockedDoor = currentRoom->getDoorTo(roomName);
    lockedDoor->unlock(currentRoom->getUIDForItem(itemName));
}
