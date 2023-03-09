#include "..\DigmeBox.h"

DigmeBox::DigmeBox(const char* name, int32_t width_screen, int32_t height_screen, int32_t width_render, int32_t height_render, uint32_t flag) :
    InputOutputGC(name, width_screen, height_screen, width_render, height_render, flag)
{
    randX_ = 0x14AE8F2D2ACC74BE;
    randY_ = 0xD3915EBCD4CCD674;
    randZ_ = 0xCB31FEE9473850F9;
}
DigmeBox::~DigmeBox()
{

}

//Update
void DigmeBox::update()
{
    updateDisplay();
}

//Random value
int64_t DigmeBox::getRandom64()
{
    uint64_t t;

    randX_ ^= randX_ << 32;
    randX_ ^= randX_ >> 10;
    randX_ ^= randX_ << 2;

    t = randX_;
    randX_ = randY_;
    randY_ = randZ_;
    randZ_ = t ^ randX_ ^ randY_;

    return randZ_;
}
int32_t DigmeBox::getRandom32()
{
    return (uint32_t)getRandom64();
}
int16_t DigmeBox::getRandom16()
{
    return (uint16_t)getRandom64();
}
int8_t DigmeBox::getRandom8()
{
    return (uint8_t)getRandom64();
}