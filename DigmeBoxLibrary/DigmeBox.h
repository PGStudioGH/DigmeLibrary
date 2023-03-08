#ifndef DIGMEBOX_H
#define DIGMEBOX_H

#include "Additions\InputOutputGC.h"

#define NUMBER_PI 3.14159265358979323846264338327950288
#define NUMBER_E  2.71828182845904523536028747135266250

class DigmeBox : public InputOutputGC
{
public:
    DigmeBox(const char* name, int32_t width_screen, int32_t height_screen, int32_t width_render, int32_t height_render, uint32_t flag);
    ~DigmeBox();

    //Update
    void update();

    //Random value
    int64_t getRandom64();
    int32_t getRandom32();
    int16_t getRandom16();
    int8_t getRandom8();
protected:
    //Random value
    uint64_t randX_, randY_, randZ_;
};

#endif