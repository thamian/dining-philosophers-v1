#ifndef CURSESTERMINAL_H
#define CURSESTERMINAL_H


#include "cursesobject.h"

#include <memory>
#include <vector>

class CursesTerminal
{
public:
    CursesTerminal(std::vector<std::unique_ptr<CursesObject>>& objects);
    ~CursesTerminal();

private:
    std::vector<std::unique_ptr<CursesObject>> objects_;

    void setColorPairs();
};

#endif // CURSESTERMINAL_H
