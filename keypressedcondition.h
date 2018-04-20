#ifndef KEYPRESSEDCONDITION_H
#define KEYPRESSEDCONDITION_H


#include "condition.h"
#include "key.h"

class KeyPressedCondition : public Condition
{
public:
    KeyPressedCondition(Key& key);

    bool isMet() override;
    bool isNotMet() override;

private:
    Key& key_;
};

#endif // KEYPRESSEDCONDITION_H
