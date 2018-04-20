#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H


#include "action.h"
#include "condition.h"

#include <string>

class Philosopher
{
public:
    Philosopher(std::string name);

    void work(Condition& endCondition);

private:
    static Action eat_;
    static Action think_;

    std::string name_;

    void doAction(Action action, Condition& endCondition);
    void wait(int time);
};

#endif // PHILOSOPHER_H
