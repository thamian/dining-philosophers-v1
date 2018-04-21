#include "cursestext.h"

CursesText::CursesText(File& file) : text_(file.content())
{
    set(CursesColorPair::BLACK_WHITE, 0, 0);
}

CursesText::CursesText(std::vector<std::string> text) : text_(text)
{
    set(CursesColorPair::BLACK_WHITE, 0, 0);
}

void CursesText::set(CursesColorPair colorPair, int x, int y)
{
    colorPair_ = colorPair;
    x_ = x;
    y_ = y;
}

void CursesText::print()
{
    std::lock_guard<std::mutex> lock(objectMutex);
    for (int i = 0; i < text_.size(); i++)
    {
        move(x_ + i, y_);
        attron(COLOR_PAIR(colorPair_));
        printw(text_[i].data());
    }
    refresh();
}

void CursesText::moveTo(int x, int y)
{
    std::lock_guard<std::mutex> lock(objectMutex);
    x_ = x;
    y_ = y;
}
