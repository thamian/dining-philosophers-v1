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
