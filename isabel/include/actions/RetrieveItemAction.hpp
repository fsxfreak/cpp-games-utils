#ifndef RETRIEVE_ITEM_ACTION
#define RETRIEVE_ITEM_ACTION

#include <actions/Action.hpp>

class RetrieveItemAction : public Action
{
public:
    RetrieveItemAction(void *o);
    virtual void usage() const override;
    virtual void execute(const std::string& arg) const override;
private:
    
};

#endif