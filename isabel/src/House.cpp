#include <House.hpp>

House::House()
{
    rooms.push_back( {"Living Room",    { Item() }} );
    rooms.push_back( {"Dining Room",    { Item() }} );
    rooms.push_back( {"Kitchen",        { Item() }} );
    rooms.push_back( {"Hallway",        { Item() }} );
    rooms.push_back( {"Garage",         { Item() }} );
    rooms.push_back( {"Kyle\'s Room",   { Item() }} );
    rooms.push_back( {"Leon\'s Room",   { Item() }} );
    rooms.push_back( {"Bathroom",       { Item() }} );
    rooms.push_back( {"Closet",         { Item() }} );
    rooms.push_back( {"Master Bedroom", { Item() }} );

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