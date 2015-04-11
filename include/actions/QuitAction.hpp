#ifndef QUIT_ACTION_HPP
#define QUIT_ACTION_HPP

#include <actions/Action.hpp>

class QuitAction : public Action
{
public:
    QuitAction(void *o);
    virtual void usage() const override;
    virtual void execute() const override;
};

#endif
