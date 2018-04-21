#ifndef CURSESOBJECT_H
#define CURSESOBJECT_H


class CursesObject
{
public:
    virtual void print() = 0;
    virtual void moveTo(int x, int y) = 0;
    virtual void update() = 0;
};

#endif // CURSESOBJECT_H
