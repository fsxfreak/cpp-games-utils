#include <InputHandler.hpp>
#include <algorithm>
#include <string>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>
#include <sstream>
#include <utility>


InputHandler::InputHandler()
{
}

void InputHandler::addAction(const std::string& name, std::unique_ptr<Action> action)
{
    validInputs.emplace(name, std::move(action));
}

std::vector<std::string> tokenizeString(const std::string &str)
{
    unsigned int index = str.find(' ');

    if (index != std::string::npos)
        return { str.substr(0, index), str.substr(index + 1, str.size()) };

    return { str };
}

void InputHandler::updateInput()
{
    std::cout << "What would you like to do?" << std::endl;

    std::string input;
    std::getline(std::cin, input);

    if (input.size() == 0)
    {
        std::cout << "You inputted nothing. Try again." << std::endl;
        return;
    }

    std::vector<std::string> tokens = tokenizeString(input);

    const std::string command = tokens[0];
    const std::string argument = tokens.size() == 2 ? tokens[1] : "";

    auto it = validInputs.find(command);
    if (it == validInputs.end())
    {
        std::cout << "Invalid command: " << command << "." << std::endl;
        printValidCommands();
    }
    else
    {
        auto& action = it->second;
        if (action) action->execute(argument);
        else std::cout << "Whoops, this control has no implementation. "
                       << "Contact the dev." 
                       << std::endl;
    }
}

void InputHandler::printValidCommands()
{
    std::cout << "Possible commands: ";
    for (const auto &e : validInputs) { std::cout << e.first << ", "; }
    std::cout << "\b\b." << std::endl;
}