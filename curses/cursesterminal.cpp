#include "cursescolorpair.h"
#include "cursesterminal.h"

#include <curses.h>

CursesTerminal::CursesTerminal()
{
    initscr();
    start_color();
    curs_set(0);
    setColorPairs();
}

CursesTerminal::~CursesTerminal()
{
    endwin();
}

void CursesTerminal::setColorPairs()
{
    init_pair(CursesColorPair::WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);
    init_pair(CursesColorPair::BLACK_WHITE, COLOR_BLACK, COLOR_WHITE);
    init_pair(CursesColorPair::YELLOW_BLACK, COLOR_YELLOW, COLOR_BLACK);
    init_pair(CursesColorPair::BLACK_YELLOW, COLOR_BLACK, COLOR_YELLOW);
    init_pair(CursesColorPair::CYAN_BLACK, COLOR_CYAN, COLOR_BLACK);
    init_pair(CursesColorPair::BLACK_CYAN, COLOR_BLACK, COLOR_CYAN);
}
