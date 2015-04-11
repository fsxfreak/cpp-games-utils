#ifndef ACTION_HPP
#define ACTION_HPP

#include <Player.hpp>
#include <actions/Action.hpp>

class PlayerAction : public Action
{
public:
    virtual void execute(Player* const onPlayer) const = 0;
};

#endif
