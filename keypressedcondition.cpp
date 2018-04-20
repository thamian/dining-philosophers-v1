#include "keypressedcondition.h"

KeyPressedCondition::KeyPressedCondition(Key &key) : key_(key)
{

}

bool KeyPressedCondition::isMet()
{
    return key_.wasPressed();
}

bool KeyPressedCondition::isNotMet()
{
    return !key_.wasPressed();
}
