#include <iostream>
#include <InputHandler.hpp>

int main()
{
    InputHandler input;
    
    do 
    {
        input.updateInput();      


    } while (!input.endSignal());

    return 0;
}