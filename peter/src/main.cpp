#include <curses.h>
#include <iostream>

int main()
{
    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, true);
    scrollok(stdscr, true);

    while (true) {
        int ch = getch();
        if (ch != ERR) {
            ungetch(ch);
            std::cout << getch() << std::endl;
        }
    }
}