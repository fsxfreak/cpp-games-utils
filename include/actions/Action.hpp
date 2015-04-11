#ifndef ACTION_HPP
#define ACTION_HPP

class Action
{
public:
    Action(void *o) : obj(o) {}
    virtual void usage() const = 0;
    virtual void execute() const = 0;
protected:
    void* const obj;
};

#endif