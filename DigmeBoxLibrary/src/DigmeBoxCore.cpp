#include <DigmeBoxCore.h>

// O------------------------------------------------------------------------------O
// | INCLUDES                                                                     |
// O------------------------------------------------------------------------------O
#pragma region includes

#include <fstream>
#include <sstream>
#include <iomanip>

#pragma endregion

// O------------------------------------------------------------------------------O
// | STATIC VARIABLES                                                             |
// O------------------------------------------------------------------------------O
#pragma region static_variables

const uint64_t default_font[256] =
{
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
const char KEY_WITH_SHIFT[256] =
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
const char KEY_FROM_KEYPAD[16] =
{
  '/', '*', '-', '+','\r', '1', '2', '3',
  '4', '5', '6', '7', '8', '9', '0', '.',
};

#pragma endregion

// O------------------------------------------------------------------------------O
// | SPRGC                                                                        |
// O------------------------------------------------------------------------------O
#pragma region spr_gc

SprGC::SprGC()
{
  rect_.x = 0;
  rect_.y = 0;
  rect_.w = 0;
  rect_.h = 0;
  texture_ = nullptr;
  surface_ = nullptr;
}
SprGC::SprGC(int32_t width, int32_t height)
{
  SprGC();
  create(width, height);
}
SprGC::SprGC(uint32_t *pixels, int32_t width, int32_t height)
{
  SprGC();
  loadSprFromArray(pixels, width, height);
}
SprGC::SprGC(const char* path)
{
  SprGC();
  loadSprFromImage(path);
}
SprGC::~SprGC()
{
  if (texture_ != nullptr)
    SDL_DestroyTexture(texture_);
  if (surface_ != nullptr)
    SDL_FreeSurface(surface_);
}

void SprGC::create(int32_t width, int32_t height)
{
  if (0 < width && 0 < height)
  {
    if (texture_ != nullptr)
      SDL_DestroyTexture(texture_);
    if (surface_ != nullptr)
      SDL_FreeSurface(surface_);

    rect_.w = width;
    rect_.h = height;
    texture_ = nullptr;
    surface_ = SDL_CreateRGBSurfaceWithFormat(0, width, height, 8, SDL_PIXELFORMAT_ARGB8888);
  }
}
void SprGC::setPixel(int32_t x, int32_t y, uint32_t color)
{
  if ((uint32_t)x < (uint32_t)rect_.w && (uint32_t)y < (uint32_t)rect_.h)
  {
    if (texture_ != nullptr)
      pixels_[y * rect_.w + x] = color;
    else if (surface_ != nullptr)
      *(uint32_t*)((uint8_t*)surface_->pixels + y * surface_->pitch + x * 4) = color;
  }
}
void SprGC::loadSprFromArray(uint32_t *pixels, int32_t width, int32_t height)
{
  if (0 < width && 0 < height)
  {
    if (texture_ != nullptr)
      SDL_DestroyTexture(texture_);
    if (surface_ != nullptr)
      SDL_FreeSurface(surface_);

    rect_.w = width;
    rect_.h = height;
    texture_ = nullptr;
    surface_ = SDL_CreateRGBSurfaceFrom(pixels, width, height, 8, width * 4, 0, 0, 0, 0);
  }
}
void SprGC::loadSprFromImage(const char *path)
{
  SDL_Surface* new_img = IMG_Load(path);
  if (new_img != NULL)
  {
    if (texture_ != nullptr)
      SDL_DestroyTexture(texture_);
    if (surface_ != nullptr)
      SDL_FreeSurface(surface_);

    surface_ = SDL_ConvertSurfaceFormat(new_img, SDL_PIXELFORMAT_ARGB8888, 0);

    rect_.w = surface_->w;
    rect_.h = surface_->h;
    texture_ = nullptr;

    SDL_FreeSurface(new_img);
  }
}
void SprGC::clearSpr()
{
  if (texture_ != nullptr)
    SDL_DestroyTexture(texture_);
  if (surface_ != nullptr)
    SDL_FreeSurface(surface_);

  rect_.x = 0;
  rect_.y = 0;
  rect_.w = 0;
  rect_.h = 0;
  texture_ = nullptr;
  surface_ = nullptr;
}

uint32_t* SprGC::getPixels()
{
  if (texture_ != nullptr)
    return pixels_;
  else if (surface_ != nullptr)
    return (uint32_t*)surface_->pixels;
  return nullptr;
}
uint32_t SprGC::getPixel(int32_t x, int32_t y)
{
  if ((uint32_t)x < rect_.w && (uint32_t)y < rect_.h)
  {
    if (texture_ != nullptr)
      return pixels_[y * rect_.w + x];
    else if (surface_ != nullptr)
      return *(uint32_t*)((uint8_t*)surface_->pixels + y * surface_->pitch + x * 4);
  }
  return (uint32_t)NULL;
}
int32_t SprGC::getWidth()
{
  return rect_.w;
}
int32_t SprGC::getHeight()
{
  return rect_.h;
}

#pragma endregion

// O------------------------------------------------------------------------------O
// | TEXTGC                                                                       |
// O------------------------------------------------------------------------------O
#pragma region text_gc

//Constructor and deconstructor
TextGC::TextGC()
{
  //Pixel data
  size_pixels_symbols_ = 0;
  pixels_symbols_ = nullptr;

  //Characteristic of symbol
  width_symbol_ = 0;
  height_symbol_ = 0;

  //Buffer chars
  index_ = 0;
  current_foreground_color_ = 0;
  current_background_color_ = 0;
  cols_ = 0;
  lines_ = 0;
  size_ = 0;
  buffer_chars_ = nullptr;
  buffer_foreground_color_ = nullptr;
  buffer_background_color_ = nullptr;
}
TextGC::TextGC(int32_t cols, int32_t lines)
{
  TextGC();
  create(cols, lines);
}
TextGC::TextGC(int32_t cols, int32_t lines, const char* path)
{
  TextGC();
  create(cols, lines);
  loadFont(path);
}
TextGC::~TextGC()
{
  if (pixels_symbols_ != (uint8_t*)default_font && pixels_symbols_ != nullptr)
    delete[] pixels_symbols_;
  if (buffer_chars_ != nullptr)
    delete[] buffer_chars_;
  if (buffer_foreground_color_ != nullptr)
    delete[] buffer_foreground_color_;
  if (buffer_background_color_ != nullptr)
    delete[] buffer_background_color_;
}

//Create a window
void TextGC::create(int32_t cols, int32_t lines)
{
  if (pixels_symbols_ != (uint8_t*)default_font && pixels_symbols_ != nullptr)
    delete[] pixels_symbols_;
  if (buffer_chars_ != nullptr)
    delete[] buffer_chars_;
  if (buffer_foreground_color_ != nullptr)
    delete[] buffer_foreground_color_;
  if (buffer_background_color_ != nullptr)
    delete[] buffer_background_color_;

  width_symbol_ = 8;
  height_symbol_ = 8;
  size_pixels_symbols_ = 2048;
  pixels_symbols_ = (uint8_t*)default_font;
  cols_ = cols;
  lines_ = lines;
  size_ = cols_ * lines_;
  buffer_chars_ = new uint8_t[size_]{};
  buffer_foreground_color_ = new uint32_t[size_]{};
  buffer_background_color_ = new uint32_t[size_]{};
  index_ = 0;
  current_foreground_color_ = C_WHITE;
  current_background_color_ = C_NULL;

  sprite_.create(width_symbol_ * cols_, height_symbol_ * lines_);
}

//Update
void TextGC::update()
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
            sprite_.setPixel(pix_x + j + 0, pix_y + i, buffer_foreground_color_[index]);
          else
            sprite_.setPixel(pix_x + j + 0, pix_y + i, buffer_background_color_[index]);
          if (pixels_symbols_[choose] & 0x40)
            sprite_.setPixel(pix_x + j + 1, pix_y + i, buffer_foreground_color_[index]);
          else
            sprite_.setPixel(pix_x + j + 1, pix_y + i, buffer_background_color_[index]);
          if (pixels_symbols_[choose] & 0x20)
            sprite_.setPixel(pix_x + j + 2, pix_y + i, buffer_foreground_color_[index]);
          else
            sprite_.setPixel(pix_x + j + 2, pix_y + i, buffer_background_color_[index]);
          if (pixels_symbols_[choose] & 0x10)
            sprite_.setPixel(pix_x + j + 3, pix_y + i, buffer_foreground_color_[index]);
          else
            sprite_.setPixel(pix_x + j + 3, pix_y + i, buffer_background_color_[index]);
          if (pixels_symbols_[choose] & 0x08)
            sprite_.setPixel(pix_x + j + 4, pix_y + i, buffer_foreground_color_[index]);
          else
            sprite_.setPixel(pix_x + j + 4, pix_y + i, buffer_background_color_[index]);
          if (pixels_symbols_[choose] & 0x04)
            sprite_.setPixel(pix_x + j + 5, pix_y + i, buffer_foreground_color_[index]);
          else
            sprite_.setPixel(pix_x + j + 5, pix_y + i, buffer_background_color_[index]);
          if (pixels_symbols_[choose] & 0x02)
            sprite_.setPixel(pix_x + j + 6, pix_y + i, buffer_foreground_color_[index]);
          else
            sprite_.setPixel(pix_x + j + 6, pix_y + i, buffer_background_color_[index]);
          if (pixels_symbols_[choose] & 0x01)
            sprite_.setPixel(pix_x + j + 7, pix_y + i, buffer_foreground_color_[index]);
          else
            sprite_.setPixel(pix_x + j + 7, pix_y + i, buffer_background_color_[index]);
          choose++;
        }
      }
    }
  }
}

//Control font
void TextGC::loadFont(const char* path)
{
  if (pixels_symbols_ != nullptr)
  {
    std::fstream in(path, std::ios::binary | std::ios::in);

    if (in.is_open())
    {
      uint32_t header[16 / 4]{};
      in.read((char*)header, 16);

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

      sprite_.create(width_symbol_ * cols_, height_symbol_ * lines_);
    }
  }
}
void TextGC::deleteFont()
{
  if (pixels_symbols_ != nullptr)
  {
    if (pixels_symbols_ != (uint8_t*)default_font)
    {
      delete[] pixels_symbols_;

      width_symbol_ = 8;
      height_symbol_ = 8;
      size_pixels_symbols_ = 2048;
      pixels_symbols_ = (uint8_t*)default_font;

      sprite_.create(width_symbol_ * cols_, height_symbol_ * lines_);
    }
  }
}

//Setting cursor
void TextGC::setCaretPosition(int32_t x, int32_t y)
{
  index_ = y * cols_ + x;
}
void TextGC::setCaretForegroundColor(uint32_t foreground_color)
{
  current_foreground_color_ = foreground_color;
}
void TextGC::setCaretBackgroundColor(uint32_t background_color)
{
  current_background_color_ = background_color;
}
void TextGC::setCaretColor(uint32_t foreground_color, uint32_t background_color)
{
  current_foreground_color_ = foreground_color;
  current_background_color_ = background_color;
}

//Draw
void TextGC::changeColor(uint32_t foreground_color, uint32_t background_color)
{
  SDL_memset4(buffer_foreground_color_, foreground_color, cols_ * lines_);
  SDL_memset4(buffer_background_color_, background_color, cols_ * lines_);
}
void TextGC::clear()
{
  index_ = 0;
  SDL_memset(buffer_chars_, '\0', cols_ * lines_);
  SDL_memset4(buffer_foreground_color_, 0, cols_ * lines_);
  SDL_memset4(buffer_background_color_, 0, cols_ * lines_);
}
void TextGC::drawSymbol(int32_t x, int32_t y, char sym)
{
  if ((uint32_t)x < (uint32_t)cols_ && (uint32_t)y < (uint32_t)lines_)
  {
    uint32_t choose = y * cols_ + x;
    buffer_chars_[choose] = sym;
    buffer_foreground_color_[choose] = current_foreground_color_;
    buffer_background_color_[choose] = current_background_color_;
  }
}

//Output symbols
TextGC& TextGC::operator<<(bool a)
{
  *this << (a ? "true" : "false");
  return *this;
}
TextGC& TextGC::operator<<(uint16_t a)
{
  std::stringstream ss;
  ss << a;
  *this << ss.str().c_str();

  return *this;
}
TextGC& TextGC::operator<<(int16_t a)
{
  std::stringstream ss;
  ss << a;
  *this << ss.str().c_str();

  return *this;
}
TextGC& TextGC::operator<<(uint32_t a)
{
  std::stringstream ss;
  ss << a;
  *this << ss.str().c_str();

  return *this;
}
TextGC& TextGC::operator<<(int32_t a)
{
  std::stringstream ss;
  ss << a;
  *this << ss.str().c_str();

  return *this;
}
TextGC& TextGC::operator<<(uint64_t a)
{
  std::stringstream ss;
  ss << a;
  *this << ss.str().c_str();

  return *this;
}
TextGC& TextGC::operator<<(int64_t a)
{
  std::stringstream ss;
  ss << a;
  *this << ss.str().c_str();

  return *this;
}
TextGC& TextGC::operator<<(float a)
{
  std::stringstream ss;
  ss << a;
  *this << ss.str().c_str();

  return *this;
}
TextGC& TextGC::operator<<(double a)
{
  std::stringstream ss;
  ss << a;
  *this << ss.str().c_str();

  return *this;
}
TextGC& TextGC::operator<<(const char* text)
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
      else
        index_ = index_ / cols_ * cols_;
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
TextGC& TextGC::operator<<(char c)
{
  if (pixels_symbols_ != nullptr)
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
      else
        index_ = index_ / cols_ * cols_;
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
  }

  return *this;
}
char TextGC::exactDouble(double a, char size)
{
  if (size > 15) size = 15;

  std::stringstream ss;
  ss << std::setprecision(size) << a;
  *this << ss.str().c_str();

  return '\0';
}
char TextGC::fixedDouble(double a, char size)
{
  std::stringstream ss;
  ss << std::fixed << std::setprecision(size) << a;
  *this << ss.str().c_str();

  return '\0';
}

//Get info of sprite
uint32_t* TextGC::getPixels()
{
  return sprite_.getPixels();
}
uint32_t TextGC::getPixel(int32_t x, int32_t y)
{
  return sprite_.getPixel(x, y);
}
int32_t TextGC::getWidth()
{
  return sprite_.getWidth();
}
int32_t TextGC::getHeight()
{
  return sprite_.getHeight();
}

#pragma endregion

// O------------------------------------------------------------------------------O
// | INIT DIGMEBOX CORE                                                           |
// O------------------------------------------------------------------------------O
#pragma region init

//Constructor and deconstructor
DigmeBox_Core::DigmeBox_Core()
{
  //flags
  flags_ = 0;

  //Status display
  window_ = nullptr;
  renderer_ = nullptr;
  screen_ = nullptr;

  //Info of display
  window_position_x_ = 0;
  window_position_y_ = 0;
  window_width_ = 0;
  window_height_ = 0;
  rendered_window_width_ = 0;
  rendered_window_height_ = 0;
  render_width_ = 0;
  render_height_ = 0;

  //Data of screen
  pitch_ = 0;
  pixels_ = nullptr;

  //Info mouse and keyboard
  cursor_monitor_x_ = 0;
  cursor_monitor_y_ = 0;
  cursor_window_x_ = 0;
  cursor_window_y_ = 0;
  cursor_render_x_ = 0;
  cursor_render_y_ = 0;
  cursor_motion_x_ = 0;
  cursor_motion_y_ = 0;

  //Info of FPS
  limit_ms_per_frame_ = 0.0f;
  fps_ = 0.0f;
  limit_fps_ = 0.0f;
  limit_idle_fps_ = 0.0f;
  now_ = 0;
  end_ = 0;

  //Pixel data
  size_pixels_symbols_ = 0;
  pixels_symbols_ = nullptr;

  //Characteristic of symbol
  width_symbol_ = 0;
  height_symbol_ = 0;

  //Buffer chars
  index_ = 0;
  current_foreground_color_ = 0;
  current_background_color_ = 0;
  cols_ = 0;
  lines_ = 0;
  size_ = 0;
  buffer_chars_ = nullptr;
  buffer_foreground_color_ = nullptr;
  buffer_background_color_ = nullptr;
}
DigmeBox_Core::DigmeBox_Core(const char* name, int32_t width_window, int32_t height_window, int32_t width_render, int32_t height_render, uint32_t flag)
{
  DigmeBox_Core();
  DB_createWindow(name, width_window, height_window, width_render, height_render, flag);
}
DigmeBox_Core::~DigmeBox_Core()
{
  if (pixels_symbols_ != (uint8_t*)default_font && pixels_symbols_ != nullptr)
    delete[] pixels_symbols_;
  if (buffer_chars_ != nullptr)
    delete[] buffer_chars_;
  if (buffer_foreground_color_ != nullptr)
    delete[] buffer_foreground_color_;
  if (buffer_background_color_ != nullptr)
    delete[] buffer_background_color_;
  if (screen_ != nullptr)
    SDL_DestroyTexture(screen_);
  if (renderer_ != nullptr)
    SDL_DestroyRenderer(renderer_);
  if (window_ != nullptr)
    SDL_DestroyWindow(window_);
  SDL_Quit();
  IMG_Quit();
}

//Init
int DigmeBox_Core::DB_init()
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
    return 2;
  if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0)
    return 2;
  if (window_ == nullptr)
    return 1;
  if (renderer_ == nullptr)
    return 1;
  if (screen_ == nullptr)
    return 1;
  return 0;
}
const char* DigmeBox_Core::DB_getError()
{
  return SDL_GetError();
}

//Create a window
void DigmeBox_Core::DB_createWindow(const char* name, int32_t width_window, int32_t height_window, int32_t width_render, int32_t height_render, uint32_t flag)
{
  DB_setFlag(flag, 1);

  //Display and screen
  window_width_ = width_window;
  window_height_ = height_window;
  rendered_window_width_ = width_window;
  rendered_window_height_ = height_window;
  render_width_ = width_render;
  render_height_ = height_render;

  //FPS
  limit_fps_ = INFINITY;
  limit_idle_fps_ = INFINITY;
  now_ = SDL_GetPerformanceCounter();

  //Create window
  window_ = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, rendered_window_width_, rendered_window_height_, SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
  SDL_GetWindowPosition(window_, &window_position_x_, &window_position_y_);

  //Create renderer
  if (DB_getFlag(DB_HARDWARE_ACCELERATED))
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
  else
    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_SOFTWARE);
  SDL_RenderSetLogicalSize(renderer_, render_width_, render_height_);
  SDL_RenderSetIntegerScale(renderer_, SDL_FALSE);

  //Create texture for rendering screen
  screen_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, render_width_, render_height_);
  SDL_LockTexture(screen_, NULL, (void**)&pixels_, &pitch_);

  //Get info display
  SDL_GetCurrentDisplayMode(0, &display_);

  //Input and event
  DB_setFlag(DB_CURSOR_SHOW, 1);
  SDL_ShowCursor(SDL_ENABLE);
  SDL_SetRelativeMouseMode(SDL_FALSE);
  SDL_PollEvent(&event_);
  state_ = SDL_GetKeyboardState(NULL);
  SDL_SetHintWithPriority(SDL_HINT_MOUSE_RELATIVE_MODE_WARP, "1", SDL_HINT_OVERRIDE);
  SDL_GetGlobalMouseState(&cursor_monitor_x_, &cursor_monitor_y_);
  SDL_GetMouseState(&cursor_window_x_, &cursor_window_y_);
  cursor_render_x_ = (int32_t)((cursor_window_x_ - (window_width_ - rendered_window_width_) / 2.0f) * (render_width_ * 1.0f / rendered_window_width_));
  cursor_render_y_ = (int32_t)((cursor_window_y_ - (window_height_ - rendered_window_height_) / 2.0f) * (render_height_ * 1.0f / rendered_window_height_));
  cursor_motion_x_ = 0; cursor_motion_y_ = 0;

  //Create terminal
  width_symbol_ = 8;
  height_symbol_ = 8;
  size_pixels_symbols_ = 2048;
  pixels_symbols_ = (uint8_t*)default_font;
  cols_ = render_width_ / width_symbol_;
  lines_ = render_height_ / height_symbol_;
  size_ = cols_ * lines_;
  buffer_chars_ = new uint8_t[size_]{};
  buffer_foreground_color_ = new uint32_t[size_]{};
  buffer_background_color_ = new uint32_t[size_]{};
  index_ = 0;
  current_foreground_color_ = C_WHITE;
  current_background_color_ = C_NULL;
}
void DigmeBox_Core::DB_initSprGC(SprGC* spr)
{
  if (renderer_ == nullptr)
    return;

  if (spr->texture_ == nullptr)
  {
    if (spr->surface_ == nullptr)
      return;
    spr->texture_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, spr->rect_.w, spr->rect_.h);
    SDL_SetTextureBlendMode(spr->texture_, SDL_BLENDMODE_BLEND);
    SDL_UpdateTexture(spr->texture_, NULL, spr->surface_->pixels, spr->surface_->pitch);
    SDL_LockTexture(spr->texture_, NULL, (void**)&spr->pixels_, &pitch_);
    SDL_FreeSurface(spr->surface_);
    spr->surface_ = nullptr;
  }
}
void DigmeBox_Core::DB_initTextGC(TextGC* text)
{
  if (renderer_ == nullptr)
    return;

  if (text->sprite_.texture_ == nullptr)
  {
    if (text->sprite_.surface_ == nullptr)
      return;
    text->sprite_.texture_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, text->sprite_.rect_.w, text->sprite_.rect_.h);
    SDL_SetTextureBlendMode(text->sprite_.texture_, SDL_BLENDMODE_BLEND);
    SDL_UpdateTexture(text->sprite_.texture_, NULL, text->sprite_.surface_->pixels, text->sprite_.surface_->pitch);
    SDL_LockTexture(text->sprite_.texture_, NULL, (void**)&text->sprite_.pixels_, &pitch_);
    SDL_FreeSurface(text->sprite_.surface_);
    text->sprite_.surface_ = nullptr;
  }
}

#pragma endregion

// O------------------------------------------------------------------------------O
// | WINDOW SYSTEM ON DIGMEBOX CORE                                               |
// O------------------------------------------------------------------------------O
#pragma region window_system

//Manage flags
bool DigmeBox_Core::DB_getFlag(uint32_t flag)
{
  return flags_ & flag;
}
void DigmeBox_Core::DB_setFlag(uint32_t flag, bool toggle)
{
  if (toggle == 1)
    flags_ |= flag;
  else
    flags_ &= ~flag;
}
void DigmeBox_Core::DB_switchFlag(uint32_t flag)
{
  flags_ ^= flag;
}

//Status DigmeBox Core
bool DigmeBox_Core::DB_isWorkingDigmeBoxCore()
{
  return DB_getFlag(DB_WORKING_DIGMEBOX_CORE);
}
void DigmeBox_Core::DB_enableDigmeBoxCore()
{
  DB_setFlag(DB_WORKING_DIGMEBOX_CORE, 1);
}
void DigmeBox_Core::DB_disableDigmeBoxCore()
{
  DB_setFlag(DB_WORKING_DIGMEBOX_CORE, 0);
}
void DigmeBox_Core::DB_restartDigmeBoxCore()
{
  DB_setFlag(DB_FULL_FLAGS, 0);
  DB_fill(C_BLACK);
  DB_setFullScreen(0);
  limit_ms_per_frame_ = 0.0f;
}

//Update
void DigmeBox_Core::DB_updateDigmeBoxCore()
{
  //Draw screen
  SDL_UnlockTexture(screen_);
  SDL_RenderClear(renderer_);
  SDL_RenderCopy(renderer_, screen_, NULL, NULL);

  //Draw all sprites
  for (int i = 0; i < decals_.size(); i++)
  {
    SDL_UnlockTexture(decals_[i]->texture_);
    SDL_RenderCopy(renderer_, decals_[i]->texture_, NULL, &rects_[i]);
  }

  //Update screen
  SDL_RenderPresent(renderer_);

  //Lock all screen and textures
  SDL_LockTexture(screen_, NULL, (void**)&pixels_, &pitch_);
  while(decals_.size() > 0)
  {
    SDL_LockTexture(decals_[0]->texture_, NULL, (void**)&decals_[0]->pixels_, &pitch_);
    rects_.erase(rects_.begin());
    decals_.erase(decals_.begin());
  }

  //Update window
  SDL_GetWindowSize(window_, &window_width_, &window_height_);
  SDL_GetWindowPosition(window_, &window_position_x_, &window_position_y_);
  if ((float)render_width_ / render_height_ < (float)window_width_ / window_height_)
  {
    rendered_window_width_ = (int32_t)(window_width_ * ((float)render_width_ / render_height_) / ((float)window_width_ / window_height_) + 0.5f);
    rendered_window_height_ = window_height_;
  }
  else if ((float)render_width_ / render_height_ > (float)window_width_ / window_height_)
  {
    rendered_window_width_ = window_width_;
    rendered_window_height_ = (int32_t)(window_height_ * ((float)window_width_ / window_height_) / ((float)render_width_ / render_height_) + 0.5f);
  }
  else
  {
    rendered_window_width_ = window_width_;
    rendered_window_height_ = window_height_;
  }

  //Update cursor and event
  SDL_PollEvent(&event_);
  SDL_GetGlobalMouseState(&cursor_monitor_x_, &cursor_monitor_y_);
  SDL_GetMouseState(&cursor_window_x_, &cursor_window_y_);
  cursor_render_x_ = (int32_t)((cursor_window_x_ - (window_width_ - rendered_window_width_) / 2.0f) * (render_width_ * 1.0f / rendered_window_width_));
  cursor_render_y_ = (int32_t)((cursor_window_y_ - (window_height_ - rendered_window_height_) / 2.0f) * (render_height_ * 1.0f / rendered_window_height_));
  SDL_GetRelativeMouseState(&cursor_motion_x_, &cursor_motion_y_);

  if (event_.window.event == SDL_WINDOWEVENT_FOCUS_LOST)
    DB_setFlag(DB_IDLE, 1);
  if (event_.window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
    DB_setFlag(DB_IDLE, 0);
  if (event_.type == SDL_QUIT)
    DB_setFlag(DB_WORKING_DIGMEBOX_CORE, 0);

  //Calculate FPS and delay
  if (DB_getFlag(DB_IDLE) && DB_getFlag(DB_STOP_ON_IDLE))
    limit_ms_per_frame_ = 75.0f;
  else if (DB_getFlag(DB_IDLE))
    limit_ms_per_frame_ = 1000.0f / limit_idle_fps_;
  else
    limit_ms_per_frame_ = 1000.0f / limit_fps_;

  DB_delayWithFPS();

  //Only stop-idle
  while (DB_getFlag(DB_IDLE) && DB_getFlag(DB_STOP_ON_IDLE))
  {
    DB_delayWithFPS();
    
    SDL_PollEvent(&event_);
    if (event_.window.event == SDL_WINDOWEVENT_FOCUS_GAINED)
      DB_setFlag(DB_IDLE, 0);
    if (event_.type == SDL_QUIT)
    {
      DB_setFlag(DB_WORKING_DIGMEBOX_CORE, 0);
      DB_setFlag(DB_IDLE, 0);
    }
  }
}

//Get info of window and render
bool DigmeBox_Core::DB_isFullScreen()
{
  return DB_getFlag(DB_FULLSCREEN);
}
bool DigmeBox_Core::DB_isChangedSizeWindow()
{
  return event_.type == SDL_WINDOWEVENT && event_.window.event == SDL_WINDOWEVENT_SIZE_CHANGED;
}

//Get resolution
int32_t DigmeBox_Core::DB_getResolutionMonitorScreenByWidth()
{
  return display_.w;
}
int32_t DigmeBox_Core::DB_getResolutionMonitorScreenByHeight()
{
  return display_.h;
}
int32_t DigmeBox_Core::DB_getResolutionWindowByWidth()
{
  return window_width_;
}
int32_t DigmeBox_Core::DB_getResolutionWindowByHeight()
{
  return window_height_;
}
int32_t DigmeBox_Core::DB_getResolutionRenderedWindowByWidth()
{
  return rendered_window_width_;
}
int32_t DigmeBox_Core::DB_getResolutionRenderedWindowByHeight()
{
  return rendered_window_height_;
}
int32_t DigmeBox_Core::DB_getResolutionRenderByWidth()
{
  return render_width_;
}
int32_t DigmeBox_Core::DB_getResolutionRenderByHeight()
{
  return render_height_;
}

//Get position
int32_t DigmeBox_Core::DB_getWindowPositionX()
{
  return window_position_x_;
}
int32_t DigmeBox_Core::DB_getWindowPositionY()
{
  return window_position_y_;
}

//Setting window
void DigmeBox_Core::DB_setFullScreen(bool toggle)
{
  DB_setFlag(DB_FULLSCREEN, toggle);
  SDL_SetWindowFullscreen(window_, DB_getFlag(DB_FULLSCREEN) ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);
  SDL_GetWindowSize(window_, &window_width_, &window_height_);
  SDL_WarpMouseGlobal(display_.w >> 1, display_.h >> 1);
}
void DigmeBox_Core::DB_setWindowPosition(int32_t x, int32_t y)
{
  window_position_x_ = x;
  window_position_y_ = y;
  SDL_SetWindowPosition(window_, x, y);
}
void DigmeBox_Core::DB_setWindowTitle(const char* title)
{
  SDL_SetWindowTitle(window_, title);
}
void DigmeBox_Core::DB_setWindowBorderless(bool toggle)
{
  if (toggle)
    SDL_SetWindowBordered(window_, SDL_FALSE);
  else
    SDL_SetWindowBordered(window_, SDL_TRUE);
}
void DigmeBox_Core::DB_setWindowResizable(bool toggle)
{
  if (toggle)
    SDL_SetWindowResizable(window_, SDL_TRUE);
  else
    SDL_SetWindowResizable(window_, SDL_FALSE);
}
void DigmeBox_Core::DB_resizeWindow(int32_t width, int32_t height)
{
  window_width_ = width;
  window_height_ = height;
  if ((float)render_width_ / render_height_ < (float)window_width_ / window_height_)
  {
    rendered_window_width_ = (int32_t)(window_width_ * ((float)render_width_ / render_height_) / ((float)window_width_ / window_height_) + 0.5f);
    rendered_window_height_ = window_height_;
  }
  else if ((float)render_width_ / render_height_ > (float)window_width_ / window_height_)
  {
    rendered_window_width_ = window_width_;
    rendered_window_height_ = (int32_t)(window_height_ * ((float)window_width_ / window_height_) / ((float)render_width_ / render_height_) + 0.5f);
  }
  else
  {
    rendered_window_width_ = window_width_;
    rendered_window_height_ = window_height_;
  }
  SDL_SetWindowSize(window_, width, height);
}
void DigmeBox_Core::DB_resizeRender(int32_t width_render, int32_t height_render)
{
  render_width_ = width_render;
  render_height_ = height_render;
  if ((float)render_width_ / render_height_ < (float)window_width_ / window_height_)
  {
    rendered_window_width_ = (int32_t)(window_width_ * ((float)render_width_ / render_height_) / ((float)window_width_ / window_height_) + 0.5f);
    rendered_window_height_ = window_height_;
  }
  else if ((float)render_width_ / render_height_ > (float)window_width_ / window_height_)
  {
    rendered_window_width_ = window_width_;
    rendered_window_height_ = (int32_t)(window_height_ * ((float)window_width_ / window_height_) / ((float)render_width_ / render_height_) + 0.5f);
  }
  else
  {
    rendered_window_width_ = window_width_;
    rendered_window_height_ = window_height_;
  }
  SDL_RenderSetLogicalSize(renderer_, render_width_, render_height_);
  SDL_UnlockTexture(screen_);
  SDL_DestroyTexture(screen_);
  screen_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, render_width_, render_height_);
  SDL_LockTexture(screen_, NULL, (void**)&pixels_, &pitch_);
}

//Draw
void DigmeBox_Core::DB_fill(uint32_t color)
{
  SDL_memset4(pixels_, color, render_width_ * render_height_);
}
void DigmeBox_Core::DB_drawPixel(int32_t x, int32_t y, uint32_t color)
{
  if ((uint32_t)x < (uint32_t)render_width_ && (uint32_t)y < (uint32_t)render_height_)
    pixels_[y * render_width_ + x] = color;
}
void DigmeBox_Core::DB_fastDrawPixel(int32_t x, int32_t y, uint32_t color)
{
  pixels_[y * render_width_ + x] = color;
}
void DigmeBox_Core::DB_drawPixelWithBlend(int32_t x, int32_t y, uint32_t color)
{
  if ((uint32_t)x < (uint32_t)render_width_ && (uint32_t)y < (uint32_t)render_height_)
  {
    uint8_t alpha = color >> 24;
    if (alpha != (uint8_t)0x00)
    {
      uint32_t& current_color = pixels_[y * render_width_ + x];
      if (alpha == (uint8_t)0xFF)
        current_color = color;
      else
      {
        current_color = 
          ((((((color & 0xFF00FF) - (current_color & 0xFF00FF)) * (alpha + 1)) >> 8) + current_color) & 0xFF00FF) |
          ((((((color & 0x00FF00) - (current_color & 0x00FF00)) * (alpha + 1)) >> 8) + current_color) & 0x00FF00);
      }
    }
  }
}

//Draw sprite
void DigmeBox_Core::DB_drawSprite(int32_t x, int32_t y, SprGC* spr)
{
  for (int32_t i = 0; i < spr->rect_.w; i++)
    for (int32_t j = 0; j < spr->rect_.h; j++)
      DB_drawPixel(x + i, y + j, spr->getPixels()[j * spr->rect_.w + i]);
}
void DigmeBox_Core::DB_drawPixels(int32_t x, int32_t y, const uint32_t* pixels, int32_t width, int32_t height)
{
  for (int32_t i = 0; i < width; i++)
    for (int32_t j = 0; j < height; j++)
      DB_drawPixel(x + i, j + y, pixels[j * width + i]);
}

//Draw sprite with blending
void DigmeBox_Core::DB_drawSpriteWithBlend(int32_t x, int32_t y, SprGC* spr)
{
  for (int32_t i = 0; i < spr->rect_.w; i++)
    for (int32_t j = 0; j < spr->rect_.h; j++)
      DB_drawPixelWithBlend(x + i, y + j, spr->getPixels()[j * spr->rect_.w + i]);
}
void DigmeBox_Core::DB_drawPixelsWithBlend(int32_t x, int32_t y, const uint32_t* pixels, int32_t width, int32_t height)
{
  for (int32_t i = 0; i < width; i++)
    for (int32_t j = 0; j < height; j++)
      DB_drawPixelWithBlend(x + i, j + y, pixels[j * width + i]);
}

//Draw text
void DigmeBox_Core::DB_drawText(int32_t x, int32_t y, TextGC* text)
{
  for (int32_t i = 0; i < text->sprite_.rect_.w; i++)
    for (int32_t j = 0; j < text->sprite_.rect_.h; j++)
      DB_drawPixel(x + i, y + j, text->sprite_.getPixels()[j * text->sprite_.rect_.w + i]);
}

//Draw text with blend
void DigmeBox_Core::DB_drawTextWithBlend(int32_t x, int32_t y, TextGC* text)
{
  for (int32_t i = 0; i < text->sprite_.rect_.w; i++)
    for (int32_t j = 0; j < text->sprite_.rect_.h; j++)
      DB_drawPixelWithBlend(x + i, y + j, text->sprite_.getPixels()[j * text->sprite_.rect_.w + i]);
}

//Draw with GPU
void DigmeBox_Core::DB_drawDecalSprite(int32_t x, int32_t y, SprGC* spr)
{
  if (renderer_ == nullptr)
    return;

  if (spr->texture_ == nullptr)
  {
    if (spr->surface_ == nullptr)
      return;
    spr->texture_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, spr->rect_.w, spr->rect_.h);
    SDL_SetTextureBlendMode(spr->texture_, SDL_BLENDMODE_BLEND);
    SDL_UpdateTexture(spr->texture_, NULL, spr->surface_->pixels, spr->surface_->pitch);
    SDL_LockTexture(spr->texture_, NULL, (void**)&spr->pixels_, &pitch_);
    SDL_FreeSurface(spr->surface_);
    spr->surface_ = nullptr;
  }

  SDL_Rect temp = { x, y, spr->rect_.w, spr->rect_.h };

  rects_.push_back(temp);
  decals_.push_back(spr);
}
void DigmeBox_Core::DB_drawDecalText(int32_t x, int32_t y, TextGC* text)
{
  if (renderer_ == nullptr)
    return;

  if (text->sprite_.texture_ == nullptr)
  {
    if (text->sprite_.surface_ == nullptr)
      return;
    text->sprite_.texture_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, text->sprite_.rect_.w, text->sprite_.rect_.h);
    SDL_SetTextureBlendMode(text->sprite_.texture_, SDL_BLENDMODE_BLEND);
    SDL_UpdateTexture(text->sprite_.texture_, NULL, text->sprite_.surface_->pixels, text->sprite_.surface_->pitch);
    SDL_LockTexture(text->sprite_.texture_, NULL, (void**)&text->sprite_.pixels_, &pitch_);
    SDL_FreeSurface(text->sprite_.surface_);
    text->sprite_.surface_ = nullptr;
  }

  SDL_Rect temp = { x, y, text->sprite_.rect_.w, text->sprite_.rect_.h };

  rects_.push_back(temp);
  decals_.push_back(&text->sprite_);
}

//Tools drawing
void DigmeBox_Core::DB_drawRect(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color)
{
  DB_drawFilledRect(x1, y1, x2, y1, color);
  DB_drawFilledRect(x1, y1 + 1, x1, y2, color);
  DB_drawFilledRect(x1 + 1, y2, x2, y2, color);
  DB_drawFilledRect(x2, y1 + 1, x2, y2 - 1, color);
}
void DigmeBox_Core::DB_drawFilledRect(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color)
{
  for (int32_t i = y2; i >= y1; i--)
    for (int32_t j = x2; j >= x1; j--)
      DB_drawPixel(j, i, color);
}
void DigmeBox_Core::DB_drawCircle(int32_t x, int32_t y, int32_t radius, uint32_t color)
{
  int32_t x0 = 0;
  int32_t y0 = radius;
  int32_t delta = 1 - 2 * radius;
  int32_t error = 0;
  while (y0 >= 0)
  {
    DB_drawPixel(x + x0, y + y0, color);
    DB_drawPixel(x + x0, y - y0, color);
    DB_drawPixel(x - x0 + 1, y + y0, color);
    DB_drawPixel(x - x0 + 1, y - y0, color);
    error = 2 * (delta + y0) - 1;
    if (delta < 0 && error <= 0)
    {
      ++x0;
      delta += 2 * x0 + 1;
      continue;
    }
    error = 2 * (delta - x0) - 1;
    if (delta > 0 && error > 0)
    {
      --y0;
      delta += 1 - 2 * y0;
      continue;
    }
    ++x0;
    delta += 2 * (x0 - y0);
    --y0;
  }
}
void DigmeBox_Core::DB_drawFilledCircle(int32_t x, int32_t y, int32_t radius, uint32_t color)
{
  int32_t x0 = 0;
  int32_t y0 = radius;
  int32_t delta = 1 - 2 * radius;
  int32_t error = 0;
  while (y0 >= 0)
  {
    DB_drawFilledRect(x - x0 + 1, y + y0, x + x0, y + y0, color);
    DB_drawFilledRect(x - x0 + 1, y - y0, x + x0, y - y0, color);
    error = 2 * (delta + y0) - 1;
    if (delta < 0 && error <= 0)
    {
      ++x0;
      delta += 2 * x0 + 1;
      continue;
    }
    error = 2 * (delta - x0) - 1;
    if (delta > 0 && error > 0)
    {
      --y0;
      delta += 1 - 2 * y0;
      continue;
    }
    ++x0;
    delta += 2 * (x0 - y0);
    --y0;
  }
}
void DigmeBox_Core::DB_drawLineRect(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t size, uint32_t color)
{
  const bool carry = size % 2;
  const int32_t deltaX = abs(x2 - x1);
  const int32_t deltaY = abs(y2 - y1);
  const int32_t signX = x1 < x2 ? 1 : -1;
  const int32_t signY = y1 < y2 ? 1 : -1;
  int32_t error = deltaX - deltaY;
  size = size / 2;
  DB_drawFilledRect(x2 - size + 1 - carry, y2 - size + 1 - carry, x2 + size, y2 + size, color);
  while (x1 != x2 || y1 != y2)
  {
    DB_drawFilledRect(x1 - size + 1 - carry, y1 - size + 1 - carry, x1 + size, y1 + size, color);
    int32_t error2 = error * 2;
    if (error2 > -deltaY)
    {
      error -= deltaY;
      x1 += signX;
    }
    if (error2 < deltaX)
    {
      error += deltaX;
      y1 += signY;
    }
  }
}
void DigmeBox_Core::DB_drawLineCircle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t size, uint32_t color)
{
  const bool carry = size % 2;
  const int32_t deltaX = abs(x2 - x1);
  const int32_t deltaY = abs(y2 - y1);
  const int32_t signX = x1 < x2 ? 1 : -1;
  const int32_t signY = y1 < y2 ? 1 : -1;
  int32_t error = deltaX - deltaY;
  size = size / 2;
  DB_drawFilledRect(x2 - size + 1 - carry, y2 - size + 1 - carry, x2 + size, y2 + size, color);
  while (x1 != x2 || y1 != y2)
  {
    DB_drawFilledRect(x1 - size + 1 - carry, y1 - size + 1 - carry, x1 + size, y1 + size, color);
    int32_t error2 = error * 2;
    if (error2 > -deltaY)
    {
      error -= deltaY;
      x1 += signX;
    }
    if (error2 < deltaX)
    {
      error += deltaX;
      y1 += signY;
    }
  }
}

//Tools drawing with blending
void DigmeBox_Core::DB_drawRectWithBlend(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color)
{
  DB_drawFilledRectWithBlend(x1, y1, x2, y1, color);
  DB_drawFilledRectWithBlend(x1, y1 + 1, x1, y2, color);
  DB_drawFilledRectWithBlend(x1 + 1, y2, x2, y2, color);
  DB_drawFilledRectWithBlend(x2, y1 + 1, x2, y2 - 1, color);
}
void DigmeBox_Core::DB_drawFilledRectWithBlend(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color)
{
  for (int32_t i = y2; i >= y1; i--)
    for (int32_t j = x2; j >= x1; j--)
      DB_drawPixelWithBlend(j, i, color);
}
void DigmeBox_Core::DB_drawCircleWithBlend(int32_t x, int32_t y, int32_t radius, uint32_t color)
{
  int32_t x0 = 0;
  int32_t y0 = radius;
  int32_t delta = 1 - 2 * radius;
  int32_t error = 0;
  while (y0 >= 0)
  {
    DB_drawPixelWithBlend(x + x0, y + y0, color);
    DB_drawPixelWithBlend(x + x0, y - y0, color);
    DB_drawPixelWithBlend(x - x0 + 1, y + y0, color);
    DB_drawPixelWithBlend(x - x0 + 1, y - y0, color);
    error = 2 * (delta + y0) - 1;
    if (delta < 0 && error <= 0)
    {
      ++x0;
      delta += 2 * x0 + 1;
      continue;
    }
    error = 2 * (delta - x0) - 1;
    if (delta > 0 && error > 0)
    {
      --y0;
      delta += 1 - 2 * y0;
      continue;
    }
    ++x0;
    delta += 2 * (x0 - y0);
    --y0;
  }
}
void DigmeBox_Core::DB_drawFilledCircleWithBlend(int32_t x, int32_t y, int32_t radius, uint32_t color)
{
  int32_t x0 = 0;
  int32_t y0 = radius;
  int32_t delta = 1 - 2 * radius;
  int32_t error = 0;
  while (y0 >= 0)
  {
    DB_drawFilledRectWithBlend(x - x0 + 1, y + y0, x + x0, y + y0, color);
    DB_drawFilledRectWithBlend(x - x0 + 1, y - y0, x + x0, y - y0, color);
    error = 2 * (delta + y0) - 1;
    if (delta < 0 && error <= 0)
    {
      ++x0;
      delta += 2 * x0 + 1;
      continue;
    }
    error = 2 * (delta - x0) - 1;
    if (delta > 0 && error > 0)
    {
      --y0;
      delta += 1 - 2 * y0;
      continue;
    }
    ++x0;
    delta += 2 * (x0 - y0);
    --y0;
  }
}
void DigmeBox_Core::DB_drawLineRectWithBlend(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t size, uint32_t color)
{
  const bool carry = size % 2;
  const int32_t deltaX = abs(x2 - x1);
  const int32_t deltaY = abs(y2 - y1);
  const int32_t signX = x1 < x2 ? 1 : -1;
  const int32_t signY = y1 < y2 ? 1 : -1;
  int32_t error = deltaX - deltaY;
  size = size / 2;
  DB_drawFilledRectWithBlend(x2 - size + 1 - carry, y2 - size + 1 - carry, x2 + size, y2 + size, color);
  while (x1 != x2 || y1 != y2)
  {
    DB_drawFilledRectWithBlend(x1 - size + 1 - carry, y1 - size + 1 - carry, x1 + size, y1 + size, color);
    int32_t error2 = error * 2;
    if (error2 > -deltaY)
    {
      error -= deltaY;
      x1 += signX;
    }
    if (error2 < deltaX)
    {
      error += deltaX;
      y1 += signY;
    }
  }
}
void DigmeBox_Core::DB_drawLineCircleWithBlend(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t size, uint32_t color)
{
  const int32_t deltaX = abs(x2 - x1);
  const int32_t deltaY = abs(y2 - y1);
  const int32_t signX = x1 < x2 ? 1 : -1;
  const int32_t signY = y1 < y2 ? 1 : -1;
  int32_t error = deltaX - deltaY;
  DB_drawFilledCircleWithBlend(x2, y2, size / 2, color);
  while (x1 != x2 || y1 != y2)
  {
    DB_drawFilledCircleWithBlend(x1, y1, size / 2, color);
    int32_t error2 = error * 2;
    if (error2 > -deltaY)
    {
      error -= deltaY;
      x1 += signX;
    }
    if (error2 < deltaX)
    {
      error += deltaX;
      y1 += signY;
    }
  }
}

//Get info of cursor
bool DigmeBox_Core::DB_isCursorShow()
{
  return DB_getFlag(DB_CURSOR_SHOW);
}
int32_t DigmeBox_Core::DB_getCursorOnMonitorScreenX()
{
  return cursor_monitor_x_;
}
int32_t DigmeBox_Core::DB_getCursorOnMonitorScreenY()
{
  return cursor_monitor_y_;
}
int32_t DigmeBox_Core::DB_getCursorOnWindowX()
{
  return cursor_window_x_;
}
int32_t DigmeBox_Core::DB_getCursorOnWindowY()
{
  return cursor_window_y_;
}
int32_t DigmeBox_Core::DB_getCursorOnRenderX()
{
  return cursor_render_x_;
}
int32_t DigmeBox_Core::DB_getCursorOnRenderY()
{
  return cursor_render_y_;
}

//Info of motion cursor
bool DigmeBox_Core::DB_isCursorMotion()
{
  return event_.type == SDL_MOUSEMOTION;
}
int32_t DigmeBox_Core::DB_getCursorMotionX()
{
  return cursor_motion_x_;
}
int32_t DigmeBox_Core::DB_getCursorMotionY()
{
  return cursor_motion_y_;
}

//Setting cursor
void DigmeBox_Core::DB_setCursorRelative(bool toggle)
{
  if (toggle == true)
    SDL_SetRelativeMouseMode(SDL_TRUE);
  else
    SDL_SetRelativeMouseMode(SDL_FALSE);
}
void DigmeBox_Core::DB_setCursor(int32_t x, int32_t y, bool show_cursor)
{
  DB_setFlag(DB_CURSOR_SHOW, show_cursor);
  SDL_WarpMouseGlobal(x, y);
  SDL_ShowCursor(DB_getFlag(DB_CURSOR_SHOW));
}

//Keyboard
bool DigmeBox_Core::DB_isPressedButtonFromKeyboard(int32_t key)
{
  return state_[SDL_GetScancodeFromKey(key)];
}
bool DigmeBox_Core::DB_isPressedKeyboard()
{
  return event_.type == SDL_KEYDOWN;
}
bool DigmeBox_Core::DB_isReleasedKeyboard()
{
  return event_.type == SDL_KEYUP;
}

//Mouse
bool DigmeBox_Core::DB_isPressedKeyFromMouse(int32_t key)
{
  return event_.button.button == key;
}
bool DigmeBox_Core::DB_isPressedMouse()
{
  return event_.type == SDL_MOUSEBUTTONDOWN;
}
bool DigmeBox_Core::DB_isReleasedMouse()
{
  return event_.type == SDL_MOUSEBUTTONUP;
}

//Calculate FPS
int32_t DigmeBox_Core::DB_getFPS()
{
  return (int32_t)fps_;
}
float DigmeBox_Core::DB_getElapsedTime()
{
  if (fps_ < 1.0f)
    return 1.0f;
  return 1.0f / fps_;
}
void DigmeBox_Core::DB_delayWithFPS()
{
  end_ = SDL_GetPerformanceCounter();
  float elapsed_ms = (float)(end_ - now_) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
  if (elapsed_ms < limit_ms_per_frame_)
  {
    float ms_left = limit_ms_per_frame_ - elapsed_ms;
    SDL_Delay((uint32_t)ms_left);

    float missed_ms = ms_left - ms_left;
    now_ = SDL_GetPerformanceCounter();
    float delayed_ms = 0.0f;
    while (delayed_ms < missed_ms)
    {
      end_ = SDL_GetPerformanceCounter();
      delayed_ms = (float)(end_ - now_) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
    }

    elapsed_ms += ms_left + delayed_ms;
  }
  fps_ = 1.0f / (elapsed_ms / 1000.0f);
  now_ = SDL_GetPerformanceCounter();
}

//Setting limit FPS
void DigmeBox_Core::DB_setFPSLimit(int32_t fps)
{
  limit_ms_per_frame_ = 1000.0f / (float)fps;
  limit_fps_ = (float)fps;
}
void DigmeBox_Core::DB_setFPSLimitOnIdle(int32_t fps)
{
  limit_idle_fps_ = (float)fps;
}
void DigmeBox_Core::DB_setStopOnIdle(bool toggle)
{
  DB_setFlag(DB_STOP_ON_IDLE, toggle);
}

#pragma endregion

// O------------------------------------------------------------------------------O
// | TERMINAL SYSTEM ON DIGMEBOX CORE                                             |
// O------------------------------------------------------------------------------O
#pragma region terminal_system

//Restart
void DigmeBox_Core::DB_restartTerminal()
{
  if (pixels_symbols_ != nullptr)
  {
    if (pixels_symbols_ != (uint8_t*)default_font)
    {
      delete[] pixels_symbols_;
      width_symbol_ = 8;
      height_symbol_ = 8;
      size_pixels_symbols_ = 2048;
      pixels_symbols_ = (uint8_t*)default_font;
    }
    delete[] buffer_chars_;
    delete[] buffer_foreground_color_;
    delete[] buffer_background_color_;
    
    cols_ = render_width_ / width_symbol_;
    lines_ = render_height_ / height_symbol_;
    size_ = cols_ * lines_;
    buffer_chars_ = new uint8_t[size_]{};
    buffer_foreground_color_ = new uint32_t[size_]{};
    buffer_background_color_ = new uint32_t[size_]{};
    index_ = 0;
    current_foreground_color_ = C_WHITE;
    current_background_color_ = C_NULL;
  }
}

//Update
void DigmeBox_Core::DB_updateTerminal()
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
            DB_drawPixelWithBlend(pix_x + j + 0, pix_y + i, buffer_foreground_color_[index]);
          else
            DB_drawPixelWithBlend(pix_x + j + 0, pix_y + i, buffer_background_color_[index]);
          if (pixels_symbols_[choose] & 0x40)
            DB_drawPixelWithBlend(pix_x + j + 1, pix_y + i, buffer_foreground_color_[index]);
          else
            DB_drawPixelWithBlend(pix_x + j + 1, pix_y + i, buffer_background_color_[index]);
          if (pixels_symbols_[choose] & 0x20)
            DB_drawPixelWithBlend(pix_x + j + 2, pix_y + i, buffer_foreground_color_[index]);
          else
            DB_drawPixelWithBlend(pix_x + j + 2, pix_y + i, buffer_background_color_[index]);
          if (pixels_symbols_[choose] & 0x10)
            DB_drawPixelWithBlend(pix_x + j + 3, pix_y + i, buffer_foreground_color_[index]);
          else
            DB_drawPixelWithBlend(pix_x + j + 3, pix_y + i, buffer_background_color_[index]);
          if (pixels_symbols_[choose] & 0x08)
            DB_drawPixelWithBlend(pix_x + j + 4, pix_y + i, buffer_foreground_color_[index]);
          else
            DB_drawPixelWithBlend(pix_x + j + 4, pix_y + i, buffer_background_color_[index]);
          if (pixels_symbols_[choose] & 0x04)
            DB_drawPixelWithBlend(pix_x + j + 5, pix_y + i, buffer_foreground_color_[index]);
          else
            DB_drawPixelWithBlend(pix_x + j + 5, pix_y + i, buffer_background_color_[index]);
          if (pixels_symbols_[choose] & 0x02)
            DB_drawPixelWithBlend(pix_x + j + 6, pix_y + i, buffer_foreground_color_[index]);
          else
            DB_drawPixelWithBlend(pix_x + j + 6, pix_y + i, buffer_background_color_[index]);
          if (pixels_symbols_[choose] & 0x01)
            DB_drawPixelWithBlend(pix_x + j + 7, pix_y + i, buffer_foreground_color_[index]);
          else
            DB_drawPixelWithBlend(pix_x + j + 7, pix_y + i, buffer_background_color_[index]);
          choose++;
        }
      }
    }
  }
}

//Control font
void DigmeBox_Core::DB_loadFontTerminal(const char* path)
{
  if (pixels_symbols_ != nullptr)
  {
    std::fstream in(path, std::ios::binary | std::ios::in);

    if (in.is_open())
    {
      uint32_t header[16 / 4]{};
      in.read((char*)header, 16);

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

      cols_ = render_width_ / width_symbol_;
      lines_ = render_height_ / height_symbol_;
      size_ = cols_ * lines_;
      buffer_chars_ = new uint8_t[size_]{};
      buffer_foreground_color_ = new uint32_t[size_]{};
      buffer_background_color_ = new uint32_t[size_]{};
      index_ = 0;
    }
  }
}
void DigmeBox_Core::DB_deleteFontTerminal()
{
  if (pixels_symbols_ != nullptr)
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
      cols_ = render_width_ / width_symbol_;
      lines_ = render_height_ / height_symbol_;
      size_ = cols_ * lines_;
      buffer_chars_ = new uint8_t[size_]{};
      buffer_foreground_color_ = new uint32_t[size_]{};
      buffer_background_color_ = new uint32_t[size_]{};
      index_ = 0;
    }
  }
}

//Setting cursor
void DigmeBox_Core::DB_setCaretPositionTerminal(int32_t x, int32_t y)
{
  index_ = y * cols_ + x;
}
void DigmeBox_Core::DB_setCaretForegroundColorTerminal(uint32_t foreground_color)
{
  current_foreground_color_ = foreground_color;
}
void DigmeBox_Core::DB_setCaretBackgroundColorTerminal(uint32_t background_color)
{
  current_background_color_ = background_color;
}
void DigmeBox_Core::DB_setCaretColorTerminal(uint32_t foreground_color, uint32_t background_color)
{
  current_foreground_color_ = foreground_color;
  current_background_color_ = background_color;
}

//Draw
void DigmeBox_Core::DB_changeColorTerminal(uint32_t foreground_color, uint32_t background_color)
{
  SDL_memset4(buffer_foreground_color_, foreground_color, cols_ * lines_);
  SDL_memset4(buffer_background_color_, background_color, cols_ * lines_);
}
void DigmeBox_Core::DB_clearTerminal()
{
  index_ = 0;
  SDL_memset(buffer_chars_, '\0', cols_ * lines_);
  SDL_memset4(buffer_foreground_color_, 0, cols_ * lines_);
  SDL_memset4(buffer_background_color_, 0, cols_ * lines_);
}
void DigmeBox_Core::DB_drawSymbolTerminal(int32_t x, int32_t y, char sym)
{
  if ((uint32_t)x < (uint32_t)cols_ && (uint32_t)y < (uint32_t)lines_)
  {
    uint32_t choose = y * cols_ + x;
    buffer_chars_[choose] = sym;
    buffer_foreground_color_[choose] = current_foreground_color_;
    buffer_background_color_[choose] = current_background_color_;
  }
}

//Input symbol
char DigmeBox_Core::DB_getSymbolFromKeyboard()
{
  if (event_.type == SDL_KEYDOWN)
  {
    int in = event_.key.keysym.sym;

    if (SDLK_KP_DIVIDE <= in && in <= SDLK_KP_PERIOD)
      return KEY_FROM_KEYPAD[in - SDLK_KP_DIVIDE];

    if (in & 0xFFFFFF00)
      return 0;

    if (state_[SDL_GetScancodeFromKey(KEYBOARD_BUTTON_LSHIFT)] || state_[SDL_GetScancodeFromKey(KEYBOARD_BUTTON_RSHIFT)])
      return KEY_WITH_SHIFT[(char)in];

    return (char)in;
  }

  return 0;
}

//Output symbols
DigmeBox_Core& DigmeBox_Core::operator<<(bool a)
{
  *this << (a ? "true" : "false");
  return *this;
}
DigmeBox_Core& DigmeBox_Core::operator<<(uint16_t a)
{
  std::stringstream ss;
  ss << a;
  *this << ss.str().c_str();

  return *this;
}
DigmeBox_Core& DigmeBox_Core::operator<<(int16_t a)
{
  std::stringstream ss;
  ss << a;
  *this << ss.str().c_str();

  return *this;
}
DigmeBox_Core& DigmeBox_Core::operator<<(uint32_t a)
{
  std::stringstream ss;
  ss << a;
  *this << ss.str().c_str();

  return *this;
}
DigmeBox_Core& DigmeBox_Core::operator<<(int32_t a)
{
  std::stringstream ss;
  ss << a;
  *this << ss.str().c_str();

  return *this;
}
DigmeBox_Core& DigmeBox_Core::operator<<(uint64_t a)
{
  std::stringstream ss;
  ss << a;
  *this << ss.str().c_str();

  return *this;
}
DigmeBox_Core& DigmeBox_Core::operator<<(int64_t a)
{
  std::stringstream ss;
  ss << a;
  *this << ss.str().c_str();

  return *this;
}
DigmeBox_Core& DigmeBox_Core::operator<<(float a)
{
  std::stringstream ss;
  ss << a;
  *this << ss.str().c_str();

  return *this;
}
DigmeBox_Core& DigmeBox_Core::operator<<(double a)
{
  std::stringstream ss;
  ss << a;
  *this << ss.str().c_str();

  return *this;
}
DigmeBox_Core& DigmeBox_Core::operator<<(const char* text)
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
      else
        index_ = index_ / cols_ * cols_;
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
DigmeBox_Core& DigmeBox_Core::operator<<(char c)
{
  if (pixels_symbols_ != nullptr)
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
      else
        index_ = index_ / cols_ * cols_;
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
  }

  return *this;
}
char DigmeBox_Core::DB_exactDouble(double a, char size)
{
  if (size > 15) size = 15;

  std::stringstream ss;
  ss << std::setprecision(size) << a;
  *this << ss.str().c_str();

  return '\0';
}
char DigmeBox_Core::DB_fixedDouble(double a, char size)
{
  std::stringstream ss;
  ss << std::fixed << std::setprecision(size) << a;
  *this << ss.str().c_str();

  return '\0';
}

#pragma endregion