#include <iostream>
#include <InputHandler.hpp>

int main()
{
    InputHandler input;
    
    do 
    {
        input.updateInput();      


    } while (!input.isEndSignal);

    return 0;
}