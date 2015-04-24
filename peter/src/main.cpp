#include <curses.h>
#include <iostream>
#include <Input.hpp>
#include <Timer.hpp>
#include <Times.hpp>

int main()
{
    initscr();
    noecho();
    keypad(stdscr, true);
    nodelay(stdscr, true);
    scrollok(stdscr, true);

    ct::Times times;
    ct::Timer timer(&times);

    ct::Inputs input = ct::checkInput();
    bool quit = false;
    while (!quit) 
    {
        refresh();
        erase();

        switch (input)
        {
        case ct::Inputs::QUIT: quit = true; break;
        case ct::Inputs::TOGGLE_TIMER: timer.toggle(); break;
        case ct::Inputs::VIEW_AVERAGES: break;
        case ct::Inputs::UP: break;
        case ct::Inputs::DOWN: break;
        case ct::Inputs::SELECT: break;
        case ct::Inputs::INVALID: ct::printAvailableInputs(); break;
        default: break;
        }

        std::cout << timer.elapsed() << std::endl;
        input = ct::checkInput();
    }

    endwin();
    std::cout << "Quitting timer." << std::endl;

    return 0;
}