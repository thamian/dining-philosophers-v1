#include "cursestext.h"

CursesText::CursesText(File& file) : text_(file.content())
{

}

CursesText::CursesText(std::vector<std::string> text) : text_(text)
{

}
