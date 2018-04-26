#include "cursesterminal.h"

#include "cursescolorpair.h"

#include <thread>

#include <curses.h>

CursesTerminal::CursesTerminal(std::vector<std::shared_ptr<CursesObject>>& objects, std::vector<std::pair<int, int>> lastPositions) : objects_(std::move(objects)), lastPositions_(std::move(lastPositions))
{

}

void CursesTerminal::work(Condition& endCondition)
{
    init();
    while (endCondition.isNotMet())
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
        clear();
        for (auto& object : objects_)
        {
            object->print();
        }
    }
    close();
}

void CursesTerminal::init()
{
    initscr();
    start_color();
    curs_set(0);
    setColorPairs();
}

void CursesTerminal::close()
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
