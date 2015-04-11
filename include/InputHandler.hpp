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
    void updateInput();

    bool endSignal() const;
private:
    InputHandler(const InputHandler&) = delete;
    InputHandler& operator=(const InputHandler&) = delete;
    InputHandler& operator=(InputHandler&&) = delete;

    /*
    std::unique_ptr<PlayerAction> survey;
    std::unique_ptr<PlayerAction> enterRoom;
    std::unique_ptr<PlayerAction> useItem;
    std::unique_ptr<PlayerAction> pickUpItem;
    std::unique_ptr<SystemAction> quit;
    */

    std::map<std::string, std::unique_ptr<Action>> validInputs;

    void printValidCommands();

    bool isEndSignal;
};

#endif
