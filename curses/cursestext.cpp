#include "cursestext.h"

#include <curses.h>

CursesText::CursesText(File& file) : text_(file.content())
{
    set(CursesColorPair::WHITE_BLACK, 0, 0);
}

CursesText::CursesText(std::vector<std::string> text) : text_(text)
{
    set(CursesColorPair::WHITE_BLACK, 0, 0);
}

CursesText::CursesText(CursesText &&cursesText)
{
    this->text_ = std::move(cursesText.text_);
    this->colorPair_ = cursesText.colorPair_;
    this->x_ = cursesText.x_;
    this->y_ = cursesText.y_;
}

void CursesText::set(CursesColorPair colorPair, int x, int y)
{
    std::lock_guard<std::mutex> lock(objectMutex_);
    colorPair_ = colorPair;
    x_ = x;
    y_ = y;
}

void CursesText::print()
{
    std::lock_guard<std::mutex> lock(objectMutex_);
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
    std::lock_guard<std::mutex> lock(objectMutex_);
    x_ = x;
    y_ = y;
}

void CursesText::clear(int x, int y)
{
    std::lock_guard<std::mutex> lock(objectMutex_);
    for (int i = 0; i < text_.size(); i++)
    {
        move(x_ + i, y_);
        attron(COLOR_PAIR(colorPair_));
        std::string spaces = "";
        spaces.insert(0, text_[i].size(), ' ');
        printw(spaces.data());
    }
    refresh();
}

std::pair<int, int> CursesText::position()
{
    std::lock_guard<std::mutex> lock(objectMutex_);
    return std::make_pair(x_, y_);
}

void CursesText::update(std::vector<std::string> text)
{
    std::lock_guard<std::mutex> lock(objectMutex_);
    text_ = text;
}

void CursesText::setColorPair(CursesColorPair colorPair)
{
    std::lock_guard<std::mutex> lock(objectMutex_);
    colorPair_ = colorPair;
}
