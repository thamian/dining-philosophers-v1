#include "fork.h"

Fork::Fork(CursesText &forkObject, int defaultX, int defaultY) : forkObject_(forkObject), defaultX_(defaultX), defaultY_(defaultY), locked(false)
{

}

Fork::Fork(Fork &&fork) : forkObject_(fork.forkObject_), defaultX_(fork.defaultX_), defaultY_(fork.defaultY_), locked(false)
{

}

bool Fork::pickUp(std::pair<int, int> placeCoords)
{
    if (!locked)
    {
        std::unique_lock<std::mutex> lock(forkMutex_);
        if (lock.owns_lock()) {
            locked = true;
            forkObject_.moveTo(placeCoords.first, placeCoords.second);
        }
        return true;
    }
    else
    {
        std::unique_lock<std::mutex> lock(forkMutex_);
        if (conditionVariable_.wait_for(lock, std::chrono::seconds(1)) == std::cv_status::timeout)
        {
            return false;
        }
        else
        {
            if (lock.owns_lock()) {
                locked = true;
                forkObject_.moveTo(placeCoords.first, placeCoords.second);
            }
            return true;
        }
    }
}

void Fork::putOff()
{
    if (locked)
    {
        std::unique_lock<std::mutex> lock();
        locked = false;
        forkObject_.moveTo(defaultX_, defaultY_);
        conditionVariable_.notify_all();
    }
}
