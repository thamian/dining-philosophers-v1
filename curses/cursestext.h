#ifndef CURSESTEXT_H
#define CURSESTEXT_H


#include "../file.h"
#include "cursescolorpair.h"
#include "cursesobject.h"

class CursesText : public CursesObject
{
public:
    CursesText();
    CursesText(File& file);
    CursesText(std::vector<std::string> text);
    CursesText(CursesText&& cursesText);

    void set(CursesColorPair colorPair, int x, int y);
    void print() override;
    void moveTo(int x, int y) override;
    void clear(int x, int y) override;
    std::pair<int, int> position() override;
    void update(std::vector<std::string> text);
    void setColorPair(CursesColorPair colorPair);

private:
    std::vector<std::string> text_;
    CursesColorPair colorPair_;
    int x_;
    int y_;
};

#endif // CURSESTEXT_H
