#include <items/Item.hpp>
#include <array>
#include <random>
#include <iostream>

std::random_device rd;
std::mt19937 mt(rd());
int Item::generateUID(const std::string& name)
{
	int uid = 0;

	typedef std::uniform_int_distribution<int> between;

	std::array<int, 3> randis;
	for (unsigned int i = 0; i < randis.size(); i++) 
	{ 
		between distribution(0, name.size() - 1);
		randis[i] = distribution(mt);
	}

	between xordist(1000, 5000);
	uid += (name[randis[0]] ^ xordist(mt)) 
	    + ((name[randis[1]] ^ xordist(mt)) * (name[randis[2]] ^ xordist(mt)));

	between distribution(31, 45);
	uid += distribution(mt) ^ xordist(mt);
	uid *= distribution(mt);

	return uid;
}

Item::Item() : name("default"), uniqueID(generateUID(name)) {}
Item::Item(const std::string& name) : name(name), uniqueID(generateUID(name)) { }
Item::Item(Item&& other) : name(std::move(other.name)), uniqueID(std::move(other.uniqueID)) { }
const std::string& Item::getName() const { return name; }
const int Item::getUID() const { return uniqueID; }