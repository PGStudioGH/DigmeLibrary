#ifndef FLAGSMANAGER_H
#define FLAGSMANAGER_H

class FlagsManager
{
public:
    FlagsManager(unsigned int flag = 0);
    ~FlagsManager();

    bool getFlag(unsigned int flag);
    void setFlag(unsigned int flag, bool toggle);
    void switchFlag(unsigned int flag);
private:
    unsigned int flags_;
};

#endif