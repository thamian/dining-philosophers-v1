#include "cursesterminal.h"

#include <curses.h>

CursesTerminal::CursesTerminal()
{
    initscr();
    start_color();
    curs_set(0);
}

CursesTerminal::~CursesTerminal()
{
    endwin();
}
