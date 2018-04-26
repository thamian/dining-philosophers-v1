#include "philosopher.h"

#include <thread>

#include <cstdlib>
#include <cstdio>
#include <ctime>

Philosopher::Philosopher(std::string name, PhilosopherStatus& philosopherStatus, Fork& leftFork, Fork& rightFork, std::pair<int, int> leftForkCoords, std::pair<int, int> rightForkCoords) : name_(name), philosopherStatus_(philosopherStatus), leftFork_(leftFork), rightFork_(rightFork), leftForkCoords_(leftForkCoords), rightForkCoords_(rightForkCoords)
{
    philosopherStatus_.setName(name_);
}

void Philosopher::work(Condition& endCondition)
{
    while (endCondition.isNotMet())
    {
        doAction(think_, endCondition);
        while (true)
        {
            doAction(wait_, endCondition);
            if (rightFork_.pickUp(rightForkCoords_))
            {
                if (leftFork_.pickUp(leftForkCoords_))
                {
                    doAction(eat_, endCondition);
                    leftFork_.putOff();
                    rightFork_.putOff();
                    break;
                }
                rightFork_.putOff();
            }
        }
    }
}

Action Philosopher::eat_ = Action("eat", 200);
Action Philosopher::think_ = Action("think", 350);
Action Philosopher::wait_ = Action("wait", 50);

void Philosopher::doAction(Action action, Condition& endCondition)
{
    for (int i = 0; i < 11; i++)
    {
        if (endCondition.isNotMet())
        {
            wait(action.duration() + rand() % 50);
            philosopherStatus_.updateAction(action, i);
            philosopherStatus_.update();
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
