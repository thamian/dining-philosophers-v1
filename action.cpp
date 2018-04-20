#include "action.h"

Action::Action(std::string name, int duration) : name_(name), duration_(duration)
{

}

std::string Action::name() const
{
    return name_;
}

int Action::duration() const
{
    return duration_;
}
