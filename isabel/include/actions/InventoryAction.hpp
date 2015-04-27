#ifndef INVENTORY_ACTION
#define INVENTORY_ACTION

#include <actions/Action.hpp>

class InventoryAction : public Action
{
public:
    InventoryAction(void *o);
    virtual void usage() const override;
    virtual void execute(const std::string& arg) const override;
};

#endif