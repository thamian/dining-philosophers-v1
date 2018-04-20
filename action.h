#ifndef ACTION_H
#define ACTION_H


#include <string>

class Action
{
public:
    Action(std::string name, int duration);

    std::string name() const;
    int duration() const;

private:
    const std::string name_;
    const int duration_;
};

#endif // ACTION_H
