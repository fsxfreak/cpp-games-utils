#include <actions/InventoryAction.hpp>
#include <Player.hpp>
#include <iostream>

InventoryAction::InventoryAction(void *o) : Action(o) {}

void InventoryAction::usage() const
{ std::cout << "To look at what items you have, "
            << "input \'inventory\'." << std::endl; }

void InventoryAction::execute(const std::string& arg) const 
{
    Player *player = static_cast<Player*>(obj);
    const std::vector<std::string> items = player->getItemNames();

    if (items.size() == 0)
    {
        std::cout << "I am carrying nothing." << std::endl;
        return;
    }

    auto it = items.begin();
    auto itend = items.end();
    std::cout << "I\'m carrying "; 
    for (; it != itend; ++it)
    {
        if ((it == items.end() - 1) && (it != items.begin()))
        {
            if (items.size() == 2)
                std::cout << "\b\b ";

            std::cout << "and ";
        }

        std::cout << "a " << *it << ", ";
    }
    std::cout << "\b\b." << std::endl;
}