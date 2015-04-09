#ifndef ACTION_HPP
#define ACTION_HPP

#include <Player.hpp>

class Action
{
public:
    virtual void execute(const Player& onPlayer) const = 0;
};

#endif
