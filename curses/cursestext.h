#ifndef CURSESTEXT_H
#define CURSESTEXT_H


#include "cursesobject.h"
#include "../file.h"

class CursesText : public CursesObject
{
public:
    CursesText(File& file);
    CursesText(std::vector<std::string> text);

private:
    std::vector<std::string> text_;
};

#endif // CURSESTEXT_H
