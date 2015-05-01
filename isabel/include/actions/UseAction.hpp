#ifndef USE_ACTION_HPP
#define USE_ACTION_HPP

#include <actions/Action.hpp>
#include <string>

class UseAction : public Action
{
public:
    UseAction(void *o);
    virtual void usage() const override;
    virtual void execute(const std::string& arg) const override;
};

#endif
