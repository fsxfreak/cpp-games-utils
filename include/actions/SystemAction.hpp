#ifndef SYSTEM_ACTION_HPP
#define SYSTEM_ACTION_HPP

#include <InputHandler.hpp>
#include <actions/Action.hpp>

class InputHandler;

class SystemAction : public Action
{
public:
    virtual void execute(InputHandler* const handler) const = 0;
};

#endif
