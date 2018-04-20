#include "key.h"

#include <iostream>

Key::Key() : pressed_(false)
{

}

void Key::waitForPress()
{
    std::cin.ignore();      // For now, it works for 'Enter' key.
    press();
}

bool Key::wasPressed()
{
    return pressed_;
}

void Key::press()
{
    pressed_ = true;
}
