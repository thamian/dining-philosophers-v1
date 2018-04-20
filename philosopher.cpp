#include "philosopher.h"

#include <chrono>
#include <thread>

Philosopher::Philosopher(std::string name) : name_(name)
{

}

void Philosopher::work(Condition& endCondition)
{
    while (endCondition.isNotMet())
    {
        doAction(eat_, endCondition);
        doAction(think_, endCondition);
    }
}

Action Philosopher::eat_ = Action("eat", 200);
Action Philosopher::think_ = Action("think", 400);

void Philosopher::doAction(Action action, Condition& endCondition)
{
    for (int i = 0; i < 10; i++)
    {
        if (endCondition.isNotMet())
        {
            wait(action.duration());
        }
        else
        {
            break;
        }
    }
}

void Philosopher::wait(int time)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
}
