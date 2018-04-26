#ifndef PHILOSOPHERSTATUS_H
#define PHILOSOPHERSTATUS_H


#include "curses/cursesprogressbar.h"
#include "curses/cursestext.h"
#include "action.h"

class PhilosopherStatus
{
public:
    PhilosopherStatus(CursesText& philosopher, CursesText& hud, CursesProgressBar& progressBar);

    void update();
    void updateAction(Action& action, int progress);
    void setName(std::string name);

private:
    std::string philosopherName_;
    Action* action_;
    int progress_;
    CursesText& philosopher_;
    CursesText& hud_;
    CursesProgressBar& progressBar_;

    std::vector<std::string> generateHud();
};

#endif // PHILOSOPHERSTATUS_H
