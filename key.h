#ifndef KEY_H
#define KEY_H

#include <atomic>

class Key
{
public:
    Key();

    void waitForPress();
    bool wasPressed();

private:
    std::atomic_bool pressed_;

    void press();
};

#endif // KEY_H
