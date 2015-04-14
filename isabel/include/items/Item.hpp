#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

//needs to be move enabled, copying disabled
//pick up item -> move item from Room to Player
//drop item -> move item from Player to Room
//use item -> destroy?

class Item
{
public:
	Item();
	Item(const std::string& name);
    const std::string& getName() const;
private:
    const std::string name;
};

#endif