#include <iostream>
#include <InputHandler.hpp>
#include <House.hpp>
#include <memory>
#include <utility>

#include <actions/QuitAction.hpp>

//no c++14 in gcc 4.8.1
namespace stdex {
	template<typename T, typename... Args>
	std::unique_ptr<T> make_unique(Args&&... args) {
	    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
	}
}

int main()
{
    InputHandler input;
    House house;

    input.addAction("survey", nullptr);
    input.addAction("enter", nullptr);
    input.addAction("use", nullptr);
    input.addAction("retrieve", nullptr);
    input.addAction("drop", nullptr);
    input.addAction("quit", stdex::make_unique<QuitAction>(&input));
    
    do 
    {
        input.updateInput();      
    } while (!input.isEndSignal);

    std::cout << "Thanks for playing." << std::endl;

    return 0;
}