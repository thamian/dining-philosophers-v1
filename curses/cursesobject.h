#ifndef CURSESOBJECT_H
#define CURSESOBJECT_H


#include <mutex>

class CursesObject
{
public:
    virtual void print() = 0;
    virtual void moveTo(int x, int y) = 0;
    virtual void clear(int x, int y) = 0;
    virtual std::pair<int, int> position() = 0;

protected:
    std::mutex objectMutex_;
};

#endif // CURSESOBJECT_H
