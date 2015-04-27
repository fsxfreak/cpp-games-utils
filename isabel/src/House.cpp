#include <algorithm>
#include <House.hpp>
#include <string>
#include <iostream>

#include <UniqueUtil.hpp>
#include <memory>

//will serve as a pseudo json file describing the house and the items it contains

/*
 * need these below variadic functions because no
 * std::initializier_list support for unmovable types
 */
template <typename T>
void addItem(std::list<std::unique_ptr<Item>>& roomItems
           , T itemName)
{
    roomItems.push_back(stdex::make_unique<Item>(itemName));
}

template <typename T, typename... Args>
void addItem(std::list<std::unique_ptr<Item>>& roomItems
           , T itemName
           , Args&&... restItems)
{
    addItem(roomItems, itemName);
    addItem(roomItems, restItems...);
}

template <typename T, typename... Args>
Room constructRoom(const std::string &name
                 , T itemName
                 , Args&&... restItems)
{
    std::list<std::unique_ptr<Item>> items;
    addItem(items, itemName, restItems...);
    return Room(name, std::move(items));
}

House::House()
{
    rooms.push_back(constructRoom("living room", "couch", "vase"));
    rooms.push_back(constructRoom("dining room", "plate", "wine glass"));
    rooms.push_back(constructRoom("kitchen", "knife", "pan", "pot"));
    rooms.push_back(constructRoom("hallway", "painting", "box"));
    rooms.push_back(constructRoom("garage", "bicycle pump"));
    rooms.push_back(constructRoom("Kyle\'s room", "pillow", "desk"));
    rooms.push_back(constructRoom("Leon\'s room", "computer", "book", "rocket light"));
    rooms.push_back(constructRoom("bathroom", "toilet paper", "toothpaste"));
    rooms.push_back(constructRoom("closet", "flashlight", "battery"));
    rooms.push_back(constructRoom("master bedroom", "lamp", "laptop", "pile of documents"));

    auto *livingRoom = &rooms[0];
    auto *diningRoom = &rooms[1];
    auto *kitchen    = &rooms[2];
    auto *hallway    = &rooms[3];
    auto *garage     = &rooms[4];
    auto *kyle       = &rooms[5];
    auto *leon       = &rooms[6];
    auto *bathroom   = &rooms[7];
    auto *closet     = &rooms[8];
    auto *masterbed  = &rooms[9];
    
    livingRoom->connectTo(diningRoom);
    livingRoom->connectTo(kitchen);
    livingRoom->connectTo(hallway);

    diningRoom->connectTo(livingRoom);
    diningRoom->connectTo(kitchen);
    diningRoom->connectTo(hallway);

    kitchen->connectTo(livingRoom);
    kitchen->connectTo(diningRoom);
    kitchen->connectTo(hallway);

    hallway->connectTo(livingRoom);
    hallway->connectTo(diningRoom);
    hallway->connectTo(kitchen);
    hallway->connectTo(garage);
    hallway->connectTo(kyle);
    hallway->connectTo(leon);
    hallway->connectTo(bathroom);
    hallway->connectTo(closet);
    hallway->connectTo(masterbed);

    garage->connectTo(hallway);

    kyle->connectTo(hallway);

    leon->connectTo(hallway);

    bathroom->connectTo(hallway);

    closet->connectTo(hallway);

    masterbed->connectTo(hallway);
}

Room* House::getRoom(const std::string& roomName, Room* fromRoom)
{
    auto lowercase = 
        [] (std::string str) -> std::string {
            std::transform(str.begin(), str.end(), str.begin(), ::tolower);
            return str;
        };

    auto insensitiveCompare =
        [&] (std::string left, std::string right) -> bool {
            char sanitize[] = " \'";

            for (int i = 0; i < 2; i++)
            {
                left.erase(std::remove(left.begin(), left.end(), sanitize[i]), left.end());
                right.erase(std::remove(right.begin(), right.end(), sanitize[i]), right.end());
            }

            left = lowercase(left);
            right = lowercase(right);

            return left.compare(right) == 0;
        };

    //no room specified, can find whole house
    if (!fromRoom)
    {
        auto itend = rooms.end();
        for (auto it = rooms.begin(); it != itend; ++it)
        {
            if (insensitiveCompare(roomName, it->getName()))
                return &(*it);
        } 
    }
    else    //room specified, constrained to what doors room is connected to
    {
        std::vector<Room*> validSearchSpace = fromRoom->getNeighbors();
        auto itend = validSearchSpace.end();
        for (auto it = validSearchSpace.begin(); it != itend; ++it)
        {
            if (insensitiveCompare(roomName, (*it)->getName()))
                return *it;
        }
    }
    

    return nullptr;
}