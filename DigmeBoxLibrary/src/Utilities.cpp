#include <Utilities.h>

#include <sstream>
#include <iomanip>
#include <ctime>

void doubleToText(double a, char* text, int32_t size)
{
  if (size < 4)
  {
    text[0] = '\0';
    return;
  }

  if (size > 22)
    size = 22;

  std::stringstream ss;
  ss << std::setprecision(size - 7) << a;

  for (int i = 0; i < size; i++)
    text[i] = ss.str().c_str()[i];
}

int64_t getRandom64()
{
  srand(time(NULL));

  static uint64_t t;
  static uint64_t randX_ = ((uint64_t)(uint32_t)rand()) << 32 | (uint32_t)rand();
  static uint64_t randY_ = ((uint64_t)(uint32_t)rand()) << 32 | (uint32_t)rand();
  static uint64_t randZ_ = ((uint64_t)(uint32_t)rand()) << 32 | (uint32_t)rand();

  randX_ ^= randX_ << 32;
  randX_ ^= randX_ >> 10;
  randX_ ^= randX_ << 2;

  t = randX_;
  randX_ = randY_;
  randY_ = randZ_;
  randZ_ = t ^ randX_ ^ randY_;

  return randZ_;
}
int32_t getRandom32()
{
  return (uint32_t)getRandom64();
}
int16_t getRandom16()
{
  return (uint16_t)getRandom64();
}
int8_t getRandom8()
{
  return (uint8_t)getRandom64();
}

uint32_t getColor(uint8_t R, uint8_t G, uint8_t B, uint8_t A)
{
  return (A << 24) | (R << 16) | (G << 8) | B;
}
uint32_t setAlpha(uint32_t color, uint8_t alpha)
{
  return (color & 0x00FFFFFF) | (alpha << 24);
}
uint8_t getAlpha(uint32_t color)
{
  return color >> 24;
}