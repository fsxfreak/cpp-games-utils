#include <iostream>
#include <InputHandler.hpp>

int main()
{
    InputHandler input;
    
    do 
    {
        input.updateInput();      
    } while (!input.isEndSignal);

    std::cout << "Thanks for playing." << std::endl;

    return 0;
}