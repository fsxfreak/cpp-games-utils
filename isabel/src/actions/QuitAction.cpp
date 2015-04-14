#include <actions/QuitAction.hpp>
#include <InputHandler.hpp>
#include <iostream>

QuitAction::QuitAction(void *o) : Action(o) {}

void QuitAction::usage() const
{ std::cout << "To quit the game, simply input \'quit\'."; }

void QuitAction::execute(const std::string& arg) const 
{ (static_cast<InputHandler*>(obj))->isEndSignal = true; }