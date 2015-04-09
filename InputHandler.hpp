#ifndef INPUT_HANDLER_HPP
#define INPUT_HANDLER_HPP

#include <Action.hpp>
#include <memory>

class InputHandler
{
public:
    InputHandler();
    ~InputHandler();
    void updateInput();

    bool endSignal();
private:
    InputHandler(const InputHandler&) = delete;
    InputHandler& operator=(const InputHandler&) = delete;
    InputHandler& operator=(InputHandler&&) = delete;

    std::unique_ptr<Action> lookAround;
    std::unique_ptr<Action> enterRoom;
    std::unique_ptr<Action> useItem;
    std::unique_ptr<Action> pickUpItem;
};

#endif
