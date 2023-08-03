#include <stdint.h>
#include <string>

//Function for chars
void doubleToText(double a, char* text, int32_t size);

//Random value
int64_t getRandom64();
int32_t getRandom32();
int16_t getRandom16();
int8_t getRandom8();

//Function for color
uint32_t getColor(uint8_t R, uint8_t G, uint8_t B, uint8_t A);
uint32_t setAlpha(uint32_t color, uint8_t alpha);
uint8_t getAlpha(uint32_t color);