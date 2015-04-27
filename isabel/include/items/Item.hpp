#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

//needs to be move enabled, copying disabled
//pick up item -> move item from Room to Player
//drop item -> move item from Player to Room
//use item -> destroy?
//solutoin::std::unique_ptr<Item>

class Item
{
public:
	Item();
	Item(const std::string& name);
	Item(Item&& other);

	Item(const Item& other) = default;
	Item& operator=(const Item& other) = default;

    const std::string& getName() const;
    const int getUID() const;
private:
    const std::string name;
    const int uniqueID;
	static int generateUID(const std::string& name);
};

#endif