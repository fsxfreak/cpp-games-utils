#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <actions/Action.hpp>
#include <memory>
#include <map>

class InputHandler
{
public:
    InputHandler();
    ~InputHandler() = default;

    void addAction(const std::string& name, std::unique_ptr<Action> action);

    void updateInput();
    
    bool isEndSignal;
private:
    InputHandler(const InputHandler&) = delete;
    InputHandler& operator=(const InputHandler&) = delete;
    InputHandler& operator=(InputHandler&&) = delete;

    std::map<std::string, std::unique_ptr<Action>> validInputs;

    void printValidCommands();
};

#endif
