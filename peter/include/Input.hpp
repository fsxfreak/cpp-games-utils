#ifndef INPUT_HPP
#define INPUT_HPP

namespace ct
{

enum class Inputs
{
    QUIT,
    TOGGLE_TIMER,
    VIEW_AVERAGES,
    UP,
    DOWN,
    SELECT,
    INVALID,
    CONTINUE
};

Inputs checkInput();
void printAvailableInputs();

}

#endif