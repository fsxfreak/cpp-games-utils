#include <curses.h>
#include <iostream>
#include <Input.hpp>
#include <Timer.hpp>

int main()
{
    initscr();
    noecho();
    keypad(stdscr, true);
    nodelay(stdscr, true);
    scrollok(stdscr, true);

    ct::Timer timer;

    ct::Inputs input = ct::checkInput();
    bool quit = false;
    while (!quit) 
    {
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

        std::cout << timer.elapsed().count() / 1000.0f << std::endl;
        refresh();
        erase();

        input = ct::checkInput();
    }

    std::cout << "Quitting timer." << std::endl;
    endwin();
    return 0;
}