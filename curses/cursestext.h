#ifndef CURSESTEXT_H
#define CURSESTEXT_H


#include "cursesobject.h"
#include "cursescolorpair.h"
#include "../file.h"

class CursesText : public CursesObject
{
public:
    CursesText(File& file);
    CursesText(std::vector<std::string> text);

    void set(CursesColorPair colorPair, int x, int y);

private:
    std::vector<std::string> text_;
    CursesColorPair colorPair_;
    int x_;
    int y_;
};

#endif // CURSESTEXT_H
