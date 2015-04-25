#include <Player.hpp>

Room* Player::getCurrentRoom() const { return currentRoom; }

void Player::moveTo(Room* room) { currentRoom = room; }