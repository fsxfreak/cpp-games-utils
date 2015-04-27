#include <actions/EnterAction.hpp>
#include <iostream>
#include <Player.hpp>

EnterAction::EnterAction(void *o) : Action(o) {}

void EnterAction::usage() const
{ std::cout << "To enter a room, input \'enter\' \'name-of-room\'."; }

void EnterAction::execute(const std::string& arg) const
{
    Player* player = static_cast<Player*>(obj);

    std::shared_ptr<Door> door = player->getCurrentRoom()->getDoorTo(arg);

    if (!door)
    {
        std::cout << "The room \'" << arg << "\' was not found." << std::endl;
    }
    else
    {
    	if (door->locked()) std::cout << "The door to that room is locked!" << std::endl;
    	else static_cast<Player*>(obj)->moveTo(door->getNextRoom(player->getCurrentRoom()));
    }
}