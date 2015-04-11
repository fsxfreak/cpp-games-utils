#include <InputHandler.hpp>
#include <algorithm>
#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include <sstream>
#include <utility>

InputHandler::InputHandler()
{
	validInputs.emplace("survey", nullptr);
	validInputs.emplace("enter", nullptr);
	validInputs.emplace("use", nullptr);
	validInputs.emplace("retrieve", nullptr);
	validInputs.emplace("quit", nullptr);
}

std::vector<std::string> tokenizeString(const std::string &str)
{
	std::stringstream stream(str);
	std::istream_iterator<std::string> streamIt(stream);
	std::istream_iterator<std::string> end;

	return std::vector<std::string>(streamIt, end);
}

void InputHandler::updateInput()
{
	std::string input;
	std::getline(std::cin, input);

	std::vector<std::string> tokens = tokenizeString(input);

	if (tokens.size() > 2)
	{
		std::cout << "You inputted too many commands. (Limit two)." << std::endl;
		return;
	}

	const std::string command = tokens[0];
	const std::string argument = tokens[1];

	if (validInputs.find(command) == validInputs.end())
	{
		std::cout << "Invalid command: " << command << "." << std::endl;
		printValidCommands();
	}
}

void InputHandler::printValidCommands()
{
	std::cout << "Possible commands: ";
	for (const auto &e : validInputs) { std::cout << e.first << ", "; }
	std::cout << "\b\b." << std::endl;
}

bool InputHandler::endSignal() const
{
	return true;
}