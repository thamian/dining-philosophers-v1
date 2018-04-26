#ifndef FORK_H
#define FORK_H


#include "curses/cursestext.h"

#include <atomic>
#include <condition_variable>
#include <mutex>

class Fork
{
public:
    Fork(CursesText& forkObject, int defaultX, int defaultY);
    Fork(Fork&& fork);

    bool pickUp(std::pair<int, int> placeCoords);
    void putOff();

private:
    std::mutex forkMutex_;
    std::atomic_bool locked;

    bool isAvailable();

    std::condition_variable conditionVariable_;

    CursesText& forkObject_;
    int defaultX_;
    int defaultY_;
};

#endif // FORK_H
