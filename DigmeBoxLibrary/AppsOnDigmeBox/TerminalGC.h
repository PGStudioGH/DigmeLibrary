#ifndef TERMINALGC_H
#define TERMINALGC_H

#include <fstream>
#include <sstream>
#include <iomanip>

#include "..\DigmeBox.h"

#define SIZE_HEADER   16
#define SYMBOL_WIDTH  8
#define SYMBOL_HEIGHT 8

#ifndef SYMBOLGC_H
#define SYMBOLGC_H
    #define SYM_PI   (char)243
    #define SYM_DEG  (char)248
    #define SYM_RUB  (char)249
    #define SYM_EURO (char)250
    #define SYM_SQRT (char)251
#endif

//Convert cyrillic from Windows-1251 to CP866
template <size_t N> struct toRus
{
    char text[N];

    consteval toRus(char const (&src_text)[N])
    {
        for (int i = 0; i < N; i++)
        {
            if ((uint8_t)'À' <= (uint8_t)src_text[i] && (uint8_t)src_text[i] <= (uint8_t)'ï')
                text[i] = ((uint8_t)src_text[i] - (uint8_t)'À') + 128;
            else if ((uint8_t)'ð' <= (uint8_t)src_text[i] && (uint8_t)src_text[i] <= (uint8_t)'ÿ')
                text[i] = ((uint8_t)src_text[i] - (uint8_t)'ð') + 224;
            else if (src_text[i] == '¨')
                text[i] = (uint8_t)240;
            else if (src_text[i] == '¸')
                text[i] = (uint8_t)241;
            else text[i] = src_text[i];
        }
    }
};
template <toRus R> consteval const char* operator "" _rus() { return R.text; }

class TerminalGC : public DigmeBox
{
public:
    TerminalGC(const char* name, int32_t width_screen, int32_t height_screen, int32_t width_render, int32_t height_render, uint32_t flag);
    ~TerminalGC();

    //Update
    void updateTerminal();

    //Control files
    void loadFont(const char* path);
    void deleteFont();

    //Setting cursor
    void setPositionCursor(int32_t x, int32_t y);
    void setForegroundColor(uint32_t foreground_color);
    void setBackgroundColor(uint32_t background_color);
    void setTextColor(uint32_t foreground_color, uint32_t background_color);

    //Draw
    void fillColorTerminal(uint32_t foreground_color, uint32_t background_color);
    void clearTerminal();
    void drawSymbol(int32_t x, int32_t y, char sym);

    //Convert value to chars
    void doubleToText(double a, char* text, int32_t size);

    //Input symbol
    char getSymbolFromKeyboard();

    //Output symbols
    TerminalGC& operator<<(bool a);
    TerminalGC& operator<<(uint16_t a);
    TerminalGC& operator<<(int16_t a);
    TerminalGC& operator<<(uint32_t a);
    TerminalGC& operator<<(int32_t a);
    TerminalGC& operator<<(uint64_t a);
    TerminalGC& operator<<(int64_t a);
    TerminalGC& operator<<(float a);
    TerminalGC& operator<<(double a);
    TerminalGC& operator<<(const char* text);
    TerminalGC& operator<<(char c);
    char exactDouble(double a, char size);
    char fixedDouble(double a, char size);
private:
    //Pixel data
    int32_t size_pixels_symbols_;
    uint8_t* pixels_symbols_;

    //Characteristic of symbol
    int32_t width_symbol_, height_symbol_;

    //Buffer chars
    int32_t index_;
    uint32_t current_foreground_color_;
    uint32_t current_background_color_;
    int32_t cols_, lines_, size_;
    uint8_t* buffer_chars_;
    uint32_t* buffer_foreground_color_;
    uint32_t* buffer_background_color_;
};

#ifdef TERMINAL_DEBUG
    constexpr int size_symbols = SYMBOL_WIDTH * 16 * SYMBOL_HEIGHT * 16 / 8;
    char symbols[size_symbols]{};
    void LoadSymbolsBMP(const char* path)
    {
        std::fstream in(path, std::ios::binary | std::ios::in);

        if (in.is_open())
        {
            in.seekp(0, std::ios::end);
            int size_file = (int)in.tellp();
            in.seekp(0);
            char* file = new char[size_file];
            in.read(file, size_file);
            in.close();

            if (size_file > 14 && file[0] == 'B' && file[1] == 'M')
            {
                for (int i = 0; i < SYMBOL_HEIGHT * 16; i++)
                    for (int j = 0; j < SYMBOL_WIDTH * 2; j++)
                        symbols[i * (SYMBOL_WIDTH * 2) + j] = file[size_file - (SYMBOL_WIDTH * 2 + 2) - i * (SYMBOL_WIDTH * 2) + j];
            }

            delete[] file;
        }
    }
    void SaveSymbolsFGC(const char* path)
    {
        static int header[SIZE_HEADER / 4]{};
        std::fstream out(path, std::ios::binary | std::ios::out);

        header[0] = ('F') | ('G' << 8) | ('C' << 16) | ('@' << 24);     //ID Field
        header[1] = (SYMBOL_HEIGHT) | (SYMBOL_WIDTH << 16);             //Size of symbol
        header[2] = SYMBOL_WIDTH * 16; header[3] = SYMBOL_HEIGHT * 16;  //Size of pixels

        out.write((char*)header, SIZE_HEADER);                          //Header
        out.write(symbols, size_symbols);                               //Pixel data
        out.write("\0\0", 2);                                           //End

        out.close();
    }
    void SaveSymbolsH(const char* path)
    {
        std::fstream out(path, std::ios::binary | std::ios::out);

        out.write("const uint64_t default_font[] = {\n", 34);

        for (int i = 0; i < SYMBOL_HEIGHT * 16; i++)
        {
            out.write("\t", 1);

            for (int j = 0; j < SYMBOL_WIDTH * 2; j += 8)
            {
                out.write("0x", 2);
                char value[2];

                showHEX(symbols[i * (SYMBOL_WIDTH * 2) + j + 7], value);
                out.write(value, 2);
                showHEX(symbols[i * (SYMBOL_WIDTH * 2) + j + 6], value);
                out.write(value, 2);
                showHEX(symbols[i * (SYMBOL_WIDTH * 2) + j + 5], value);
                out.write(value, 2);
                showHEX(symbols[i * (SYMBOL_WIDTH * 2) + j + 4], value);
                out.write(value, 2);
                showHEX(symbols[i * (SYMBOL_WIDTH * 2) + j + 3], value);
                out.write(value, 2);
                showHEX(symbols[i * (SYMBOL_WIDTH * 2) + j + 2], value);
                out.write(value, 2);
                showHEX(symbols[i * (SYMBOL_WIDTH * 2) + j + 1], value);
                out.write(value, 2);
                showHEX(symbols[i * (SYMBOL_WIDTH * 2) + j + 0], value);
                out.write(value, 2);

                out.write(", ", 2);
            }

            out.write("\n", 1);
        }

        out.write("};", 2);

        out.close();
    }
#endif

#endif
