#include "key.h"

#include <thread>

int main()
{
    std::unique_ptr<Key> key(new Key());

    std::thread keyPressDetector(&Key::waitForPress, std::ref(*key));

    keyPressDetector.join();

    return 0;
}
