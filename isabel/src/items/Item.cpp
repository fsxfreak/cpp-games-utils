#include <items/Item.hpp>

Item::Item() : name("default") {}
Item::Item(const std::string& name) : name(name) {}
const std::string& Item::getName() const { return name; }