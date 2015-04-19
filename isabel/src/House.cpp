#include <House.hpp>

//will serve as a pseudo json file describing the house and the items it contains

House::House()
{
    rooms.push_back( {"living room",    { Item() }} );
    rooms.push_back( {"dining room",    { Item() }} );
    rooms.push_back( {"kitchen",        { Item() }} );
    rooms.push_back( {"hallway",        { Item() }} );
    rooms.push_back( {"garage",         { Item() }} );
    rooms.push_back( {"Kyle\'s room",   { Item() }} );
    rooms.push_back( {"Leon\'s room",   { Item() }} );
    rooms.push_back( {"bathroom",       { Item() }} );
    rooms.push_back( {"closet",         { Item() }} );
    rooms.push_back( {"master bedroom", { Item() }} );

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

//mainly for testing, morerobust way of getting single room later
std::vector<Room>& House::getRooms() 
{
    return rooms;
}