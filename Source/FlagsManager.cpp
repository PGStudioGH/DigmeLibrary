#include "../Additions/FlagsManager.h"

FlagsManager::FlagsManager(unsigned int flag)
{
    flags_ = flag;
}
FlagsManager::~FlagsManager(){}

bool FlagsManager::getFlag(unsigned int flag)
{
    return flags_ & flag;
}
void FlagsManager::setFlag(unsigned int flag, bool toggle)
{
    if (toggle == 1) flags_ |= flag;
    else flags_ &= ~flag;
}
void FlagsManager::switchFlag(unsigned int flag)
{
    flags_ ^= flag;
}