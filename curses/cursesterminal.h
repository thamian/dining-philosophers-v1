#ifndef CURSESTERMINAL_H
#define CURSESTERMINAL_H


#include "../condition.h"
#include "cursesobject.h"

#include <memory>
#include <vector>

class CursesTerminal
{
public:
    CursesTerminal(std::vector<std::shared_ptr<CursesObject>>& objects, std::vector<std::pair<int, int>> lastPositions);

    void work(Condition& endCondition);

private:
    std::vector<std::shared_ptr<CursesObject>> objects_;
    std::vector<std::pair<int, int>> lastPositions_;

    void init();
    void close();
    void setColorPairs();
};

#endif // CURSESTERMINAL_H
