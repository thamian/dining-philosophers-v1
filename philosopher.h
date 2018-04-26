#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H


#include "condition.h"
#include "fork.h"
#include "philosopherstatus.h"

#include <string>

class Philosopher
{
public:
    Philosopher(std::string name, PhilosopherStatus& philosopherStatus, Fork& leftFork, Fork& rightFork, std::pair<int, int> leftForkCoords, std::pair<int, int> rightForkCoords);

    void work(Condition& endCondition);

private:
    static Action eat_;
    static Action think_;
    static Action wait_;

    std::string name_;
    Fork& leftFork_;
    Fork& rightFork_;
    PhilosopherStatus& philosopherStatus_;

    std::pair<int, int> leftForkCoords_;
    std::pair<int, int> rightForkCoords_;

    void doAction(Action action, Condition& endCondition);
    void wait(int time);
};

#endif // PHILOSOPHER_H
