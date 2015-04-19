#include <iostream>
#include <InputHandler.hpp>
#include <House.hpp>
#include <Player.hpp>
#include <memory>
#include <utility>

#include <actions/QuitAction.hpp>
#include <actions/SurveyAction.hpp>

//no c++14 in gcc 4.8.1
namespace stdex {
	template<typename T, typename... Args>
	std::unique_ptr<T> make_unique(Args&&... args) {
	    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
	}
}
void generateControls(InputHandler& input, Player &player)
{
    input.addAction("survey", stdex::make_unique<SurveyAction>(&player));
    input.addAction("enter", nullptr);
    input.addAction("use", nullptr);
    input.addAction("retrieve", nullptr);
    input.addAction("drop", nullptr);
    input.addAction("quit", stdex::make_unique<QuitAction>(&input));
}

int main()
{
    House house;
    Player player(&house.getRooms()[0]);

    InputHandler input;
    generateControls(input, player);

    do 
    {
        input.updateInput();
    } while (!input.isEndSignal);

    std::cout << "Thanks for playing." << std::endl;

    return 0;
}