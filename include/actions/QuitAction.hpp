#ifndef QUIT_ACTION_HPP
#define QUIT_ACTION_HPP

#include <actions/SystemAction.hpp>

class QuitAction : public SystemAction
{
public:
	virtual void usage() const override;
    virtual void execute(InputHandler* const handler) const override;
};

#endif
