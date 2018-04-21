#ifndef CURSESOBJECT_H
#define CURSESOBJECT_H


#include <mutex>

class CursesObject
{
public:
    virtual void print() = 0;
    virtual void moveTo(int x, int y) = 0;

protected:
    std::mutex objectMutex;
};

#endif // CURSESOBJECT_H
