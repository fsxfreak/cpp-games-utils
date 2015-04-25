#include <Input.hpp>
#include <curses.h>
#include <iostream>

namespace ct
{

Inputs checkInput()
{
    int ch = getch();

    const int INTERRUPT = 3;
    const int SPACEBAR = 32;

    switch (ch)
    {
    case 'q': case 'Q': return Inputs::QUIT;
    case INTERRUPT:     return Inputs::QUIT;
    case SPACEBAR:      return Inputs::TOGGLE_TIMER;
    case ERR:           return Inputs::CONTINUE;
    default:            return Inputs::INVALID;
    }
}

void printAvailableInputs()
{

}

}