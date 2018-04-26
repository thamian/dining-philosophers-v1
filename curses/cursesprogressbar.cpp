#include "cursesprogressbar.h"

#include <curses.h>

CursesProgressBar::CursesProgressBar(int x, int y) : x_(x), y_(y), progress_(0), colorPair_(CursesColorPair::WHITE_BLACK)
{

}

CursesProgressBar::CursesProgressBar(CursesProgressBar&& cursesProgressBar)
{
    this->progress_ = cursesProgressBar.progress_;
    this->colorPair_ = cursesProgressBar.colorPair_;
    this->x_ = cursesProgressBar.x_;
    this->y_ = cursesProgressBar.y_;
}

void CursesProgressBar::print()
{
    std::lock_guard<std::mutex> lock(objectMutex_);
    move(x_, y_);
    attron(COLOR_PAIR(CursesColorPair::BLACK_WHITE));
    printw(" ");
    move(x_, y_ + 11);
    printw(" ");

    move(x_, y_ + 1);
    attron(COLOR_PAIR(CursesColorPair::WHITE_BLACK));
    for (int i = 0; i < 10; i++)
    {
        printw(" ");
    }
    refresh();

    move(x_, y_ + 1);
    attron(COLOR_PAIR(colorPair_));

    for (int i = 0; i < progress_; i++)
    {
        printw(" ");
    }
    refresh();
}

void CursesProgressBar::moveTo(int x, int y)
{
    std::lock_guard<std::mutex> lock(objectMutex_);
    x_ = x;
    y_ = y;
}

void CursesProgressBar::clear(int x, int y)
{

}

std::pair<int, int> CursesProgressBar::position()
{
    std::lock_guard<std::mutex> lock(objectMutex_);
    return std::make_pair(x_, y_);
}

void CursesProgressBar::updateProgress(int progress, CursesColorPair colorPair)
{
    std::lock_guard<std::mutex> lock(objectMutex_);
    progress_ = progress;
    colorPair_ = colorPair;
}
