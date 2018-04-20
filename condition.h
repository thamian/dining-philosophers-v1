#ifndef CONDITION_H
#define CONDITION_H


class Condition
{
public:
    virtual bool isMet() = 0;
    virtual bool isNotMet() = 0;
};

#endif // CONDITION_H
