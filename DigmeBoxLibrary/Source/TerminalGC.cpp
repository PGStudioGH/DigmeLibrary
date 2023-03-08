#include "..\AppsOnDigmeBox\TerminalGC.h"

const uint64_t default_font[] = {
    0x00760010007E7E00, 0xFE1000701C000000, 0x00D6003828FF8100, 0x6054003838000000, 0x00DC6C5444DBA500, 0x3028001C70000000, 0x00009210FEFF8100, 0x18C6003838000000,
    0x00766C5444DBA500, 0x302800701C000000, 0x00D6003828E79900, 0x6054000000000000, 0x00DC001000FF8100, 0xFE10007C7C000000, 0x00000000007E7E00, 0x0000000000000000,
    0x3018000010301018, 0xD836823800000010, 0x1830101010183830, 0x6C6CC66CD8360038, 0x0C602838920C7C60, 0x36D86CD66C6C826C, 0x06C0447CD6FED6FE, 0x1AB0BABA36D8C6C6,
    0x0C6028387C0C9260, 0x36D8D66C6C6C6C82, 0x1830101038181030, 0x6C6C6CC6D8363800, 0x3018000010301018, 0xD836388200001000, 0x0000000000000000, 0x0000000000000000,
    0x187042106C6C6000, 0x0200000000003838, 0x18D8A67EFE6CF000, 0x0600000010000C60, 0x08704CD06C24F000, 0x0C000000106C06C0, 0x10DA187C6C48F000, 0x18007C007C3806C0,
    0x00CE34166C006000, 0x300000C0106C06C0, 0x00C66AFCFE000000, 0x60C000C010000C60, 0x007CC4106C006000, 0xC0C0004000003838, 0x0000000000000000, 0x0000008000000000,
    0xFE7CFE1E7C7C787C, 0x7C00000000007C7C, 0xC6C6C036C6C618CE, 0xC6180030C0C0C6C6, 0x0CC0FC66060C18C6, 0x060C7C60C0C0C6C6, 0x18FC06C63C3818C6, 0x3C0600C000007E7C,
    0x30C606FE066018C6, 0x300C7C60C0C006C6, 0x60C6C606C6C018E6, 0x0018003040C0C6C6, 0xC07C7C067CFE7C7C, 0x3000000000007C7C, 0x0000000000000000, 0x0000000000000000,
    0x7EFEFEF87CFC387C, 0x7CC6C6C0C61EFCC6, 0xC0C0C0CCC6C66CC6, 0xC6E6EEC0CC0630C6, 0xC0C0C0C6C0C6C6D6, 0xC6F6FEC0D80630C6, 0xDEF8F8C6C0FCC6D6, 0xC6DED6C0F00630FE,
    0xC6C0C0C6C0C6FEDC, 0xC6CEC6C0D8C630C6, 0xC6C0C0CCC6C6C6C0, 0xC6C6C6C0CCC630C6, 0x7EC0FEF87CFCC67C, 0x7CC6C6FEC67CFCC6, 0x0000000000000000, 0x0000000000000000,
    0xC6C6C6FC7CFC7CFC, 0x00103E80F8FEC6C6, 0xC6C6C630C6C6C6C6, 0x003806C0C00EC6EE, 0xC6C6C630C0C6C6C6, 0x006C0660C01CEE7C, 0xD6C6C6307CFCC6FC, 0x00C60630C0387C38,
    0xFE6CC63006D8DEC0, 0x00000618C070387C, 0xEE38C630C6CCCCC0, 0x0000060CC0E038EE, 0xC6107C307CC67AC0, 0x7C003E06F8FE38C6, 0x0000000000000000, 0x0000000000000000,
    0x001C000600C00080, 0x000000F0C00618C0, 0x0030000600C00040, 0x00000030C00000C0, 0x7EFE7C7E7CFC7C00, 0x7CFCFC30C60678FC, 0xC630C6C6C6C60600, 0xC6C6D630CC0618C6,
    0x7E30FEC6C0C67E00, 0xC6C6D630F80618C6, 0x0630C0C6C6C6C600, 0xC6C6D630CCC618C6, 0x7C307C7E7CFC7E00, 0x7CC6D61EC67CFEC6, 0x0000000000000000, 0x0000000000000000,
    0x0000003000000000, 0x1000383838000000, 0x0000003000000000, 0x38000C3860000000, 0xC6C6C6FE7EDC7EFC, 0x4C760C3860FEC6C6, 0xD6C6C630C0E6C6C6, 0x4CD60E38E01CC66C,
    0xD66CC630FEC07EFC, 0x86DC0C3860386C38, 0xFE38C63006C006C0, 0x86000C386070386C, 0x6C107C3EFCC006C0, 0xFE00383838FEF0C6, 0x0000000000000000, 0x0000000000000000,
    0x7CD6FE7CFEFCFC38, 0xFE7CC6C67EC628C6, 0xC6D6C06CC0C6C06C, 0xC6C6C6EE66CC10CE, 0x067CC06CC0C6C0C6, 0xC6C6C6FE66D8C6DE, 0x1C38F86CC0FCFCC6, 0xC6C6FED666F0CED6,
    0x067CC06CC0C6C6FE, 0xC6C6C6C666D8DEF6, 0xC6D6C0FEC0C6C6C6, 0xC6C6C6C666CCF6E6, 0x7CD6FEC6C0FCFCC6, 0xC67CC6C6C6C6E6C6, 0x0000000000000000, 0x0000000000000000,
    0xC6CCC610C6FC7CFC, 0x7E9C7CC0C6E0D6D6, 0xC6CCEE7CC630C6C6, 0xC6B6C6C0C660D6D6, 0xC6CC7CD66C30C0C6, 0xC6B606C0C660D6D6, 0xFECC38D63C30C0FC, 0x7EF61EFCE67CD6D6,
    0x06CC7CD61830C0C0, 0x36B606C6D666D6D6, 0x06FEEE7C3030C6C0, 0x66B6C6C6D666FED6, 0x0606C61060307CC0, 0xC69C7CFCE67C06FE, 0x0000000000000000, 0x0000000000000000,
    0x0000000000007E00, 0x0000000000000000, 0x000000000000C000, 0x0000000000002800, 0x7CD67C7CFEFCFC7C, 0xFE7CC6C67EC610C6, 0xC6D6C66CC0C6C606, 0xC6C6C6EE66CCCECE,
    0x1C7CFE6CC0FCC67E, 0xC6C6FEFE66F8DEDE, 0xC6D6C0FEC0C6C6C6, 0xC6C6C6D666CCF6F6, 0x7CD67CC6C0FC7C7E, 0xC67CC6C6C6C6E6E6, 0x0000000000000000, 0x0000000000000000,
    0x0036181818EE5533, 0x0018363600363600, 0x0036181818BBAACC, 0x0018363600363600, 0x0036F81818EE5533, 0x00F836F6FE36F6F8, 0xFEF618F818BBAACC, 0xF818FE0606360618,
    0x3636F81818EE5533, 0x18F800FEF636F6F8, 0x3636181818BBAACC, 0x1800000036363618, 0x3636181818EE5533, 0x1800000036363618, 0x3636181818BBAACC, 0x1800000036363618,
    0x3618180018001818, 0x1836003600360036, 0x3618180018001818, 0x1836003600360036, 0x361F180018001818, 0xFFF7FF37FFF73F37, 0x3718FFFF1FFFFF1F, 0x0000003000003030,
    0x361F180018180000, 0xFFF7FF37F7FF373F, 0x3618180018180000, 0x0036003636003600, 0x3618180018180000, 0x0036003636003600, 0x3618180018180000, 0x0036003636003600,
    0x3600001836000036, 0xFF0FF000FF001818, 0x3600001836000036, 0xFF0FF000FF001818, 0x36001F1F3600FF36, 0xFF0FF000FF0018FF, 0xFF3F18183FFF00FF, 0xFF0FF000FF1FF818,
    0x36361F1F0036FF00, 0x000FF0FFFF1800FF, 0x3636180000361800, 0x000FF0FFFF180018, 0x3636180000361800, 0x000FF0FFFF180018, 0x3636180000361800, 0x000FF0FFFF180018,
    0x0000000000000000, 0x0000000000000000, 0x0000001000000000, 0x0000000000000000, 0xC6CCEE7CC6FC7CFC, 0x7E9C7CC0C6E0D6D6, 0xC6CC7CD66C30C6C6, 0xC6B6C6C0C660D6D6,
    0xFECC38D63C30C0FC, 0x7EF61EFCE67CD6D6, 0x06FE7C7C1830C6C0, 0x36B6C6C6D666FED6, 0x0606EE10F0307CC0, 0x669C7CFCE67C06FE, 0x0000000000000000, 0x0000000000000000,
    0xC0FF030000106C6C, 0x00000000063E7CE0, 0xC0FF030000100000, 0x007C7C00066066A0, 0xC0000300FE7C7CFE, 0x007C440006F866E0, 0xC00003006C10C6C0, 0x007C4400CC60FC00,
    0xC00003006C10FEF8, 0x007C44004CF86000, 0xC00003006C00C0C0, 0x007C7C006C60FE00, 0xC00003FF6C7C7CFE, 0x00000000383E6000, 0xC00003FF00000000, 0x0000000000000000,
};

//symbols with shift
static constexpr char KEY_WITH_SHIFT[256] =
{
    '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0', //0   -  15
    '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0', //16  -  31
     ' ', '!', '"', '#', '$', '%', '&', '"', '(', ')', '*', '+', '<', '_', '>', '?', //32  -  47
     ')', '!', '@', '#', '$', '%', '^', '&', '*', '(', ':', ':', '<', '+', '>', '?', //48  -  63
     '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', //64  -  79
     'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '{', '|', '}', '^', '_', //80  -  95
     '~', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', //96  - 111
     'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '{', '0', '}', '~', '0', //112 - 127
    '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0', //128 - 143
    '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0', //144 - 159
    '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0', //160 - 175
    '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0', //176 - 191
    '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0', //192 - 207
    '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0', //208 - 223
    '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0', //224 - 239
    '\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0', //240 - 255
};

//symbols from keypad
static constexpr char KEY_FROM_KEYPAD[16] =
{
    '/', '*', '-', '+', '\r', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '0', '.'
};

TerminalGC::TerminalGC(const char* name, int32_t width_screen, int32_t height_screen, int32_t width_render, int32_t height_render, uint32_t flag) :
    DigmeBox(name, width_screen, height_screen, width_render, height_render, flag)
{
    width_symbol_ = 8;
    height_symbol_ = 8;
    size_pixels_symbols_ = 2048;
    pixels_symbols_ = (uint8_t*)default_font;
    cols_ = getWidthDisplay() / width_symbol_;
    lines_ = getHeightDisplay() / height_symbol_;
    size_ = cols_ * lines_;
    buffer_chars_ = new uint8_t[size_]{};
    buffer_foreground_color_ = new uint32_t[size_]{};
    buffer_background_color_ = new uint32_t[size_]{};
    index_ = 0;
    current_foreground_color_ = C_WHITE;
    current_background_color_ = C_NULL;
}
TerminalGC::~TerminalGC()
{
    if (pixels_symbols_ != (uint8_t*)default_font) delete[] pixels_symbols_;
    delete[] buffer_chars_;
    delete[] buffer_foreground_color_;
    delete[] buffer_background_color_;
}

//Update
void TerminalGC::updateTerminal()
{
    for (int32_t y = 0; y < lines_; y++)
    {
        for (int32_t x = 0; x < cols_; x++)
        {
            int32_t index = y * cols_ + x;

            int32_t pos_x = buffer_chars_[index] % 16 * width_symbol_ / 8;
            int32_t pos_y = buffer_chars_[index] / 16 * height_symbol_;

            int32_t pix_x = x * width_symbol_;
            int32_t pix_y = y * height_symbol_;

            for (int32_t i = 0; i < height_symbol_; i++)
            {
                int32_t choose = (pos_y + i) * width_symbol_ * 2 + pos_x;
                for (int32_t j = 0; j < width_symbol_; j += 8)
                {
                    if (pixels_symbols_[choose] & 0x80)
                        drawPixelWithAlpha(pix_x + j, pix_y + i, buffer_foreground_color_[index]);
                    else drawPixelWithAlpha(pix_x + j, pix_y + i, buffer_background_color_[index]);
                    if (pixels_symbols_[choose] & 0x40)
                        drawPixelWithAlpha(pix_x + j + 1, pix_y + i, buffer_foreground_color_[index]);
                    else drawPixelWithAlpha(pix_x + j + 1, pix_y + i, buffer_background_color_[index]);
                    if (pixels_symbols_[choose] & 0x20)
                        drawPixelWithAlpha(pix_x + j + 2, pix_y + i, buffer_foreground_color_[index]);
                    else drawPixelWithAlpha(pix_x + j + 2, pix_y + i, buffer_background_color_[index]);
                    if (pixels_symbols_[choose] & 0x10)
                        drawPixelWithAlpha(pix_x + j + 3, pix_y + i, buffer_foreground_color_[index]);
                    else drawPixelWithAlpha(pix_x + j + 3, pix_y + i, buffer_background_color_[index]);
                    if (pixels_symbols_[choose] & 0x08)
                        drawPixelWithAlpha(pix_x + j + 4, pix_y + i, buffer_foreground_color_[index]);
                    else drawPixelWithAlpha(pix_x + j + 4, pix_y + i, buffer_background_color_[index]);
                    if (pixels_symbols_[choose] & 0x04)
                        drawPixelWithAlpha(pix_x + j + 5, pix_y + i, buffer_foreground_color_[index]);
                    else drawPixelWithAlpha(pix_x + j + 5, pix_y + i, buffer_background_color_[index]);
                    if (pixels_symbols_[choose] & 0x02)
                        drawPixelWithAlpha(pix_x + j + 6, pix_y + i, buffer_foreground_color_[index]);
                    else drawPixelWithAlpha(pix_x + j + 6, pix_y + i, buffer_background_color_[index]);
                    if (pixels_symbols_[choose] & 0x01)
                        drawPixelWithAlpha(pix_x + j + 7, pix_y + i, buffer_foreground_color_[index]);
                    else drawPixelWithAlpha(pix_x + j + 7, pix_y + i, buffer_background_color_[index]);
                    choose++;
                }
            }
        }
    }
}

//Control files
void TerminalGC::loadFont(const char* path)
{
    std::fstream in(path, std::ios::binary | std::ios::in);

    if (in.is_open())
    {
        uint32_t header[SIZE_HEADER / 4]{};
        in.read((char*)header, SIZE_HEADER);

        if (header[0] != (('F') | ('G' << 8) | ('C' << 16) | ('@' << 24)))
            return;

        if (pixels_symbols_ != (uint8_t*)default_font)
            delete[] pixels_symbols_;

        width_symbol_ = (uint16_t)(header[1] >> 16);
        height_symbol_ = (uint16_t)header[1];

        size_pixels_symbols_ = header[2] * header[3] / 8;
        pixels_symbols_ = new uint8_t[size_pixels_symbols_];

        in.read((char*)pixels_symbols_, size_pixels_symbols_);
        in.close();

        delete[] buffer_chars_;
        delete[] buffer_foreground_color_;
        delete[] buffer_background_color_;

        cols_ = getWidthDisplay() / width_symbol_;
        lines_ = getHeightDisplay() / height_symbol_;
        size_ = cols_ * lines_;
        buffer_chars_ = new uint8_t[size_]{};
        buffer_foreground_color_ = new uint32_t[size_]{};
        buffer_background_color_ = new uint32_t[size_]{};
        index_ = 0;
    }
}
void TerminalGC::deleteFont()
{
    if (pixels_symbols_ != (uint8_t*)default_font)
    {
        delete[] pixels_symbols_;
        delete[] buffer_chars_;
        delete[] buffer_foreground_color_;
        delete[] buffer_background_color_;

        width_symbol_ = 8;
        height_symbol_ = 8;
        size_pixels_symbols_ = 2048;
        pixels_symbols_ = (uint8_t*)default_font;
        cols_ = getWidthDisplay() / width_symbol_;
        lines_ = getHeightDisplay() / height_symbol_;
        size_ = cols_ * lines_;
        buffer_chars_ = new uint8_t[size_]{};
        buffer_foreground_color_ = new uint32_t[size_]{};
        buffer_background_color_ = new uint32_t[size_]{};
        index_ = 0;
    }
}

//Setting cursor
void TerminalGC::setPositionCursor(int32_t x, int32_t y)
{
    index_ = y * cols_ + x;
}
void TerminalGC::setForegroundColor(uint32_t foreground_color)
{
    current_foreground_color_ = foreground_color;
}
void TerminalGC::setBackgroundColor(uint32_t background_color)
{
    current_background_color_ = background_color;
}
void TerminalGC::setTextColor(uint32_t foreground_color, uint32_t background_color)
{
    current_foreground_color_ = foreground_color;
    current_background_color_ = background_color;
}

//Draw
void TerminalGC::fillColorTerminal(uint32_t foreground_color, uint32_t background_color)
{
    SDL_memset4(buffer_foreground_color_, foreground_color, cols_ * lines_);
    SDL_memset4(buffer_background_color_, background_color, cols_ * lines_);
}
void TerminalGC::clearTerminal()
{
    index_ = 0;
    memset(buffer_chars_, '\0', cols_ * lines_);
}
void TerminalGC::drawSymbol(int32_t x, int32_t y, char sym)
{
    if (x < 0 || cols_ <= x || y < 0 || lines_ <= y) return;

    uint32_t choose = y * cols_ + x;
    buffer_chars_[choose] = sym;
    buffer_foreground_color_[choose] = current_foreground_color_;
    buffer_background_color_[choose] = current_background_color_;
}

//Convert value to chars
void TerminalGC::doubleToText(double a, char* text, int32_t size)
{
    if (size < 4)
    {
        text[0] = '\0';
        return;
    }

    if (a == 0.0f)
    {
        text[0] = '0';
        text[1] = '.';
        text[2] = '0';
        text[3] = '\0';
        return;
    }

    if (size > 22) size = 22;

    std::stringstream ss;
    ss << std::setprecision(size - 7) << a;

    for (int i = 0; i < size; i++) text[i] = ss.str().c_str()[i];
}

//Input symbol
char TerminalGC::getSymbolFromKeyboard()
{
    if (event_.type == SDL_KEYDOWN)
    {
        int in = event_.key.keysym.sym;

        if (SDLK_KP_DIVIDE <= in && in <= SDLK_KP_PERIOD)
            return KEY_FROM_KEYPAD[in - SDLK_KP_DIVIDE];

        if (in & 0xFFFFFF00)
            return 0;

        if (state_[KEYBOARD_BUTTON_LSHIFT] || state_[KEYBOARD_BUTTON_RSHIFT])
            return KEY_WITH_SHIFT[(char)in];

        return (char)in;
    }

    return 0;
}

//Output symbols
TerminalGC& TerminalGC::operator<<(bool a)
{
    *this << (a ? "true" : "false");
    return *this;
}
TerminalGC& TerminalGC::operator<<(uint16_t a)
{
    if (a == 0)
    {
        *this << '0';
        return *this;
    }

    std::stringstream ss;
    ss << a;
    *this << ss.str().c_str();

    return *this;
}
TerminalGC& TerminalGC::operator<<(int16_t a)
{
    if (a == 0)
    {
        *this << '0';
        return *this;
    }

    std::stringstream ss;
    ss << a;
    *this << ss.str().c_str();

    return *this;
}
TerminalGC& TerminalGC::operator<<(uint32_t a)
{
    if (a == 0)
    {
        *this << '0';
        return *this;
    }

    std::stringstream ss;
    ss << a;
    *this << ss.str().c_str();

    return *this;
}
TerminalGC& TerminalGC::operator<<(int32_t a)
{
    if (a == 0)
    {
        *this << '0';
        return *this;
    }

    std::stringstream ss;
    ss << a;
    *this << ss.str().c_str();

    return *this;
}
TerminalGC& TerminalGC::operator<<(uint64_t a)
{
    if (a == 0)
    {
        *this << '0';
        return *this;
    }

    std::stringstream ss;
    ss << a;
    *this << ss.str().c_str();

    return *this;
}
TerminalGC& TerminalGC::operator<<(int64_t a)
{
    if (a == 0)
    {
        *this << '0';
        return *this;
    }

    std::stringstream ss;
    ss << a;
    *this << ss.str().c_str();

    return *this;
}
TerminalGC& TerminalGC::operator<<(float a)
{
    if (a == 0.0f)
    {
        *this << "0.0";
        return *this;
    }

    std::stringstream ss;
    ss << a;
    *this << ss.str().c_str();

    return *this;
}
TerminalGC& TerminalGC::operator<<(double a)
{
    if (a == 0.0f)
    {
        *this << "0.0";
        return *this;
    }

    std::stringstream ss;
    ss << a;
    *this << ss.str().c_str();

    return *this;
}
TerminalGC& TerminalGC::operator<<(const char* text)
{
    for (int i = 0; index_ <= size_; i++)
    {
        if (text[i] == '\0')
            return *this;

        if (text[i] == '\a')
            continue;

        if (text[i] == '\n')
        {
            if (index_ < (size_ - cols_))
                index_ = (index_ / cols_ + 1) * cols_;
        }
        else if (text[i] == '\f')
            index_ = 0;
        else if (text[i] == '\r')
        {
            if (index_ == size_)
                index_ = size_ - cols_;
            else index_ = index_ / cols_ * cols_;
        }
        else if (text[i] == '\b')
        {
            buffer_chars_[index_] = '\0';
            if (index_ != 0 && index_ != size_ - 1)
                index_ = index_ - 1;
        }
        else
        {
            buffer_chars_[index_] = text[i];
            buffer_foreground_color_[index_] = current_foreground_color_;
            buffer_background_color_[index_] = current_background_color_;
            if (index_ != size_ - 1)
                index_ = index_ + 1;
        }
    }

    return *this;
}
TerminalGC& TerminalGC::operator<<(char c)
{
    if (c == '\0' || c == '\a')
        return *this;

    if (c == '\n')
    {
        if (index_ < (size_ - cols_))
            index_ = (index_ / cols_ + 1) * cols_;
    }
    else if (c == '\f')
        index_ = 0;
    else if (c == '\r')
    {
        if (index_ == size_)
            index_ = size_ - cols_;
        else index_ = index_ / cols_ * cols_;
    }
    else if (c == '\b')
    {
        buffer_chars_[index_] = '\0';
        if (index_ != 0 && index_ != size_ - 1)
            index_ = index_ - 1;
    }
    else if (index_ <= size_)
    {
        buffer_chars_[index_] = c;
        buffer_foreground_color_[index_] = current_foreground_color_;
        buffer_background_color_[index_] = current_background_color_;
        if (index_ != size_ - 1)
            index_ = index_ + 1;
    }

    return *this;
}
char TerminalGC::exactDouble(double a, char size)
{
    if (a == 0.0f)
    {
        *this << "0.0";
        return '\0';
    }

    if (size > 15) size = 15;

    std::stringstream ss;
    ss << std::setprecision(size) << a;
    *this << ss.str().c_str();

    return '\0';
}
char TerminalGC::fixedDouble(double a, char size)
{
    if (a == 0.0f)
    {
        *this << "0.0";
        return '\0';
    }

    std::stringstream ss;
    ss << std::fixed << std::setprecision(size) << a;
    *this << ss.str().c_str();

    return '\0';
}