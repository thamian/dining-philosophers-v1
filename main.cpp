#include "condition.h"
#include "key.h"
#include "keypressedcondition.h"
#include "philosopher.h"

#include <thread>
#include <vector>

int main()
{
    std::unique_ptr<Key> key(new Key());
    std::unique_ptr<Condition> endCondition(new KeyPressedCondition(*key));

    std::thread keyPressDetector(&Key::waitForPress, std::ref(*key));

    std::vector<std::thread> philosophers;
    std::vector<std::string> philosophersNames = {"Confucius", "Plato", "Aristotle", "Socrates", "Pythagoras"};

    for (auto& name : philosophersNames)
    {
        philosophers.push_back(std::thread(&Philosopher::work, Philosopher(name), std::ref(*endCondition)));
    }

    keyPressDetector.join();
    for (auto& philosopher : philosophers)
    {
        if (philosopher.joinable())
        {
            philosopher.join();
        }
    }

    return 0;
}
