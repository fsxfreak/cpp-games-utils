#include <Player.hpp>

Player::Player(Room* startingRoom)
	: currentRoom(startingRoom)
{}

Room * const Player::getCurrentRoom() const { return currentRoom; }