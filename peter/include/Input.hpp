#ifndef INPUT_HPP
#define INPUT_HPP

namespace ct
{

enum class Inputs
{
    QUIT,
    TOGGLE_TIMER,
    INVALID,
    CONTINUE
};

Inputs checkInput();
void printAvailableInputs();

}

#endif