#include <InputHandler.hpp>
#include <algorithm>
#include <string>
#include <iostream>
#include <iterator>
#include <memory>
#include <vector>
#include <sstream>
#include <utility>

//no c++14 in gcc 4.8.1
namespace stdex {

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

}

InputHandler::InputHandler()
{
    validInputs.emplace("survey", nullptr);
    validInputs.emplace("enter", nullptr);
    validInputs.emplace("use", nullptr);
    validInputs.emplace("retrieve", nullptr);
    validInputs.emplace("drop", nullptr);
    validInputs.emplace("quit", stdex::make_unique<QuitAction>(this));
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
    std::cout << "What would you like to do?" << std::endl;

    std::string input;
    std::getline(std::cin, input);

    if (input.size() == 0)
    {
        std::cout << "You inputted nothing. Try again." << std::endl;
        return;
    }

    std::vector<std::string> tokens = tokenizeString(input);

    if (tokens.size() > 2)
    {
        std::cout << "You inputted too many commands. Limit two." << std::endl;
        return;
    }

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