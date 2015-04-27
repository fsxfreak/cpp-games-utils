#include <iostream>
#include <InputHandler.hpp>
#include <House.hpp>
#include <Player.hpp>
#include <memory>
#include <utility>
#include <UniqueUtil.hpp>

#include <actions/EnterAction.hpp>
#include <actions/InventoryAction.hpp>
#include <actions/QuitAction.hpp>
#include <actions/SurveyAction.hpp>
#include <actions/RetrieveItemAction.hpp>

void generateControls(InputHandler& input, Player &player, House &house)
{
    input.addAction("survey", stdex::make_unique<SurveyAction>(&player));
    input.addAction("enter", stdex::make_unique<EnterAction>(&player, &house));
    input.addAction("use", nullptr);
    input.addAction("retrieve", stdex::make_unique<RetrieveItemAction>(&player));
    input.addAction("drop", nullptr);
    input.addAction("quit", stdex::make_unique<QuitAction>(&input));
    input.addAction("inventory", stdex::make_unique<InventoryAction>(&player));
}

int main()
{
    House house;
    Player player;
    player.moveTo(house.getRoom("living room"));

    InputHandler input;
    generateControls(input, player, house);
    
    do 
    {
        input.updateInput();
    } while (!input.isEndSignal);

    std::cout << "Thanks for playing." << std::endl;

    return 0;
}