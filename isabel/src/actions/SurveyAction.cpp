#include <actions/SurveyAction.hpp>
#include <Player.hpp>
#include <iostream> 	

SurveyAction::SurveyAction(void *o) : Action(o) {}

void SurveyAction::usage() const
{ std::cout << "To look around the room, simply input \'survey\'."; }

void SurveyAction::execute(const std::string& arg) const
{ 
	Player* player = static_cast<Player*>(obj);

	player->getCurrentRoom()->printPrettyName();
	player->getCurrentRoom()->printItems();
	player->getCurrentRoom()->printNeighbors();
}