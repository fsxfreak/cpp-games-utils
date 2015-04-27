#include <actions/RetrieveItemAction.hpp>
#include <iostream>
#include <Player.hpp>

RetrieveItemAction::RetrieveItemAction(void *o) : Action(o) {}

void RetrieveItemAction::usage() const 
{ std::cout << "To pick up an item from a room, "
			<< "input \'retrieve\' \'item-name\'." << std::endl; }

void RetrieveItemAction::execute(const std::string& arg) const
{
	Player* player = static_cast<Player*>(obj);
	player->getCurrentRoom();
}