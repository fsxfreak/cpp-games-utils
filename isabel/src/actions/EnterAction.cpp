#include <actions/EnterAction.hpp>
#include <iostream>
#include <Player.hpp>

EnterAction::EnterAction(void *o, House* house) : Action(o), house(house) {}

void EnterAction::usage() const
{ std::cout << "To enter a room, input \'enter\' \'name-of-room\'."; }

void EnterAction::execute(const std::string& arg) const
{
	Player* player = static_cast<Player*>(obj);

	Room *dest = house->getRoom(arg, player->getCurrentRoom());

	if (!dest)
	{
		std::cout << "The room \'" << arg << "\' was not found." << std::endl;
		return;
	}
	static_cast<Player*>(obj)->moveTo(dest);
}