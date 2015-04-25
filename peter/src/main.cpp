#include <curses.h>
#include <iostream>
#include <Input.hpp>
#include <Scramble.hpp>
#include <Timer.hpp>
#include <Times.hpp>
#include <chrono>


int main()
{
    initscr();
    noecho();
    keypad(stdscr, true);
    nodelay(stdscr, true);
    scrollok(stdscr, true);
    curs_set(false);

    //TODO printer class with support for printing to different regions
    int maxRows;
    int maxCols;
    getmaxyx(stdscr, maxRows, maxCols);

    ct::Times times;
    ct::Timer timer(&times);
    std::string currentScramble = ct::generateScramble();

    ct::Inputs input = ct::checkInput();
    bool quit = false;
    while (!quit) 
    {
        refresh();
        erase();

        switch (input)
        {
        case ct::Inputs::QUIT: quit = true; break;
        case ct::Inputs::TOGGLE_TIMER: 
            timer.toggle(); 
            if (!timer.isRunning())
                currentScramble = ct::generateScramble();
            break;
        case ct::Inputs::INVALID: ct::printAvailableInputs(); break;
        default: break;
        }

        mvprintw((maxRows / 2) - 10, (maxCols / 2) - 40, "%s", currentScramble.c_str());
        mvprintw((maxRows / 2) - 5, (maxCols / 2) - 3, "%f", timer.elapsed());
        float five = times.getAverageOf(static_cast<unsigned int>(5));
        float twelve = times.getAverageOf(static_cast<unsigned int>(12));
        float hundred = times.getAverageOf(static_cast<unsigned int>(100));
        mvprintw((maxRows / 2) + 1, (maxCols / 2) - 13, "AVG5: %f", five);
        mvprintw((maxRows / 2) + 2, (maxCols / 2) - 13, "AVG12: %f", twelve);
        mvprintw((maxRows / 2) + 3, (maxCols / 2) - 13, "AVG100: %f", hundred);

        mvprintw((maxRows / 2) + 5, (maxCols / 2) + 10, "Best: %f", times.getBestSingle());
        mvprintw((maxRows / 2) + 6, (maxCols / 2) + 10, "Worst: %f", times.getWorstSingle());
        mvprintw((maxRows / 2) + 7, (maxCols / 2) + 10, "Stddev: %f", times.getStdDevSession());

        input = ct::checkInput();
    }

    endwin();
    std::cout << "Quitting timer." << std::endl;

    return 0;
}