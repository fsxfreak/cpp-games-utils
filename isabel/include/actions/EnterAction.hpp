#ifndef ENTER_ACTION_HPP
#define ENTER_ACTION_HPP

#include <actions/Action.hpp>
#include <House.hpp>

class EnterAction : public Action
{
public:
    EnterAction(void *o);
    virtual void usage() const override;
    virtual void execute(const std::string& arg) const override;
private:
    House* house;
};

#endif