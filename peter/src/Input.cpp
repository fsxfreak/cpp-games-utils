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
    const int UP_ARROW = 259;
    const int DOWN_ARROW = 258;
    const int ENTER = 10;

    switch (ch)
    {
    case 'q': case 'Q': return Inputs::QUIT;
    case INTERRUPT:     return Inputs::QUIT;
    case SPACEBAR:      return Inputs::TOGGLE_TIMER;
    case 'v': case 'V': return Inputs::VIEW_AVERAGES;
    case UP_ARROW:      return Inputs::UP;
    case DOWN_ARROW:    return Inputs::DOWN;
    case ENTER:         return Inputs::SELECT;
    case ERR:           return Inputs::CONTINUE;
    default:            return Inputs::INVALID;
    }
}

void printAvailableInputs()
{

}

}