#ifndef CURSESPROGRESSBAR_H
#define CURSESPROGRESSBAR_H


#include "cursescolorpair.h"
#include "cursesobject.h"

class CursesProgressBar : public CursesObject
{
public:
    CursesProgressBar(int x, int y);
    CursesProgressBar(CursesProgressBar&& cursesProgressBar);

    void print() override;
    void moveTo(int x, int y) override;
    void clear(int x, int y) override;
    std::pair<int, int> position() override;
    void updateProgress(int progress, CursesColorPair colorPair);

private:
    int x_;
    int y_;
    int progress_;
    CursesColorPair colorPair_;
};

#endif // CURSESPROGRESSBAR_H
