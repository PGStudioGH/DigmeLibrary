#if __has_include(<SDL2/SDL.h>)
#ifndef DIGMEBOX_CORE_H
#define DIGMEBOX_CORE_H

// O------------------------------------------------------------------------------O
// | INCLUDES                                                                     |
// O------------------------------------------------------------------------------O
#pragma region includes

/**
 * USE SDL2 API TO CREATE AND MANAGE A WINDOW
 * USE SDL_IMAGE API TO LOAD PNG AND JPG IMAGE
 */
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/**
 * USE SOME C/C++ STANDART LIBRARY
 */
#include <vector>

/**
 * USE SOME LIBRARY BY GC
*/
#include <Utilities.h>

#pragma endregion

// O------------------------------------------------------------------------------O
// | MACROS                                                                       |
// O------------------------------------------------------------------------------O
#pragma region macros

/**
 * MACROS
*/
#define DIGMEBOX_MAIN() int main(int argc, char* argv[])
#define DB_true true
#define DB_false false
#define INFINITY 1.0f / 0.0f
#define DB_out *this

/**
 * FLAGS FOR DIGMEBOX CORE
*/
#define DB_WORKING_DIGMEBOX_CORE   0x00000001
#define DB_HARDWARE_ACCELERATED    0x00000002
#define DB_FULLSCREEN              0x00000004
#define DB_CURSOR_SHOW             0x00000008
#define DB_STOP_ON_IDLE            0x00000010
#define DB_IDLE                    0x00000020
#define DB_FULL_FLAGS              0xFFFFFFFF

/**
 * COLORS
*/
#define C_NULL                      0x00000000u

//Alpha
#define A_TRANSPARENT               0x00FFFFFFu
#define A_HALF_TRANSPARENT          0x7FFFFFFFu
#define A_OPAGUE                    0xFFFFFFFFu

//Basic colors
#define C_BLACK                     0xFF000000u
#define C_GRAY                      0xFF808080u
#define C_SILVER                    0xFFC0C0C0u
#define C_WHITE                     0xFFFFFFFFu
#define C_MAGENTA                   0xFFFF00FFu
#define C_PURPLE                    0xFF800080u
#define C_RED                       0xFFFF0000u
#define C_MAROON                    0xFF800000u
#define C_YELLOW                    0xFFFFFF00u
#define C_OLIVE                     0xFF808000u
#define C_LIME                      0xFF00FF00u
#define C_GREEN                     0xFF008000u
#define C_AQUA                      0xFF00FFFFu
#define C_TEAI                      0xFF008080u
#define C_BLUE                      0xFF0000FFu
#define C_NAVY                      0xFF000080u

//Red colors
#define C_INDIAN_RED                0xFFCD5C5Cu
#define C_LIGHT_CORAL               0xFFF08080u
#define C_SALMON                    0xFFFA8072u
#define C_DARK_SALMON               0xFFE9967Au
#define C_LIGHT_SALMON              0xFFFFA07Au
#define C_CRIMSON                   0xFFDC143Cu
#define C_FIRE_BRICK                0xFFB22222u
#define C_DARK_RED                  0xFF8B0000u

//Pink colors
#define C_PINK                      0xFFFFC0CBu
#define C_LIGHT_PINK                0xFFFFB6C1u
#define C_HOT_PINK                  0xFFFF69B4u
#define C_DEEP_PINK                 0xFFFF1493u
#define C_MEDIUM_VIOLET_RED         0xFFC71585u
#define C_PALE_VIOLET_RED           0xFFDB7093u

//Orange colors
#define C_CORAL                     0xFFFF7F50u
#define C_TOMATO                    0xFFFF6347u
#define C_ORANGE_RED                0xFFFF4500u
#define C_DARK_ORANGE               0xFFFF8C00u
#define C_ORANGE                    0xFFFFA500u

//Yellow colors
#define C_GOLD                      0xFFFFD700u
#define C_LIGHT_YELLOW              0xFFFFFFE0u
#define C_LEMON_CHIFFON             0xFFFFFACDu
#define C_LIGHT_GOLDENROD_YELLOW    0xFFFAFAD2u
#define C_PAPAYA_WHIP               0xFFFFEFD5u
#define C_MOCCASIN                  0xFFFFE4B5u
#define C_PEACH_PUFF                0xFFFFDAB9u   
#define C_PALE_GOLDEROD             0xFFEEE8AAu
#define C_KHAKI                     0xFFF0E68Cu
#define C_DARK_KHAKI                0xFFBDB76Bu

//Purple colors
#define C_LAVENDER                  0xFFE6E6FAu
#define C_THISTLE                   0xFFD8BFD8u
#define C_PLUM                      0xFFDDA0DDu
#define C_VIOLET                    0xFFEE82EEu
#define C_ORCHID                    0xFFDA70D6u
#define C_MEDIUM_ORCHID             0xFFBA55D3u
#define C_MEDIUM_PURPLE             0xFF9370DBu
#define C_BLUE_VIOLET               0xFF8A2BE2u
#define C_DARK_VIOLET               0xFF9400D3u
#define C_DARK_ORCHID               0xFF9932CCu
#define C_DARK_MAGENTA              0xFF8B008Bu
#define C_INDIGO                    0xFF4B0082u
#define C_STATE_BLUE                0xFF6A5ACDu
#define C_DARK_STATE_BLUE           0xFF483D8Bu

//Brown colors
#define C_CORNSILK                  0xFFFFF8DCu
#define C_BLANCHED_ALMOND           0xFFFFEBCDu
#define C_BISQUE                    0xFFFFE4C4u
#define C_NAVAJO_WHITE              0xFFFFDEADu
#define C_WHEAT                     0xFFF5DEB3u
#define C_BURLY_WOOD                0xFFDEB887u
#define C_TAN                       0xFFD2B48Cu
#define C_ROSY_BROWN                0xFFBC8F8Fu
#define C_SANDY_BROWN               0xFFF4A460u
#define C_GOLDENROD                 0xFFDAA520u
#define C_DARK_GOLDENROD            0xFFB8860Bu
#define C_PERU                      0xFFCD853Fu
#define C_CHOCOLATE                 0xFFD2691Eu
#define C_SADDLE_BROWN              0xFF8B4513u
#define C_SINNA                     0xFFA0522Du
#define C_BROWN                     0xFFA52A2Au

//Green colors
#define C_GREEN_YELLOW              0xFFADFF2Fu
#define C_CHARTREUSE                0xFF7FFF00u
#define C_LAWN_GREEN                0xFF7CFC00u
#define C_LIME_GREEN                0xFF32CD32u
#define C_PALE_GREEN                0xFF98FB98u
#define C_LIGHT_GREEN               0xFF90EE90u
#define C_MEDIUM_SPRING_GREEN       0xFF00FA9Au
#define C_SPRING_GREEN              0xFF00FF7Fu
#define C_MEDIUM_SEA_GREEN          0xFF3CB371u
#define C_SEA_GREEN                 0xFF2E8B57u
#define C_FOREST_GREEN              0xFF228B22u
#define C_DARK_GREEN                0xFF006400u
#define C_YELLOW_GREEN              0xFF9ACD32u
#define C_OLIVE_DRAB                0xFF6B8E23u
#define C_DARK_OLIVE_GREEN          0xFF556B2Fu
#define C_MEDIUM_AQUAMARINE         0xFF66CDAAu
#define C_DARK_SEA_GREEN            0xFF8FBC8Fu
#define C_LIGHT_SEA_GREEN           0xFF20B2AAu
#define C_DARK_CYAN                 0xFF008B8Bu

//Blue colors
#define C_LIGHT_CYAN                0xFFE0FFFFu
#define C_PALE_TURQUOISE            0xFFAFEEEEu
#define C_AQUAMARINE                0xFF7FFFD4u
#define C_TURQUOISE                 0xFF40E0D0u
#define C_MEDIUM_TURQUOISE          0xFF48D1CCu
#define C_DARK_TURQUOISE            0xFF00CED1u
#define C_CADET_BLUE                0xFF5F9EA0u
#define C_STEEL_BLUE                0xFF4682B4u
#define C_LIGHT_STEEL_BLUE          0xFFB0C4DEu
#define C_POWDER_BLUE               0xFFB0E0E6u
#define C_LIGHT_BLUE                0xFFADD8E6u
#define C_SKY_BLUE                  0xFF87CEEBu
#define C_LIGHT_SKY_BLUE            0xFF87CEFAu
#define C_DEEP_SKY_BLUE             0xFF00BFFFu
#define C_DODGER_BLUE               0xFF1E90FFu
#define C_CORNFLOWER_BLUE           0xFF6495EDu
#define C_MEDIUM_STATE_BLUE         0xFF7B68EEu
#define C_ROYAL_BLUE                0xFF4169E1u
#define C_MEDIUM_BLUE               0xFF0000CDu
#define C_DARK_BLUE                 0xFF00008Bu
#define C_MIDNIGHT_BLUE             0xFF191970u

//White colors
#define C_SNOW                      0xFFFFFAFAu
#define C_HONEYDEW                  0xFFF0FFF0u
#define C_MINT_CREAM                0xFFF5FFFAu
#define C_AZURE                     0xFFF0FFFFu
#define C_ALICE_BLUE                0xFFF0F8FFu
#define C_GHOST_WHITE               0xFFF8F8FFu
#define C_WHITE_SMOKE               0xFFF5F5F5u
#define C_SEASHELL                  0xFFFFF5EEu
#define C_BEIGE                     0xFFF5F5DCu
#define C_OLD_LACE                  0xFFFDF5E6u
#define C_FLORAL_WHITE              0xFFFFFAF0u
#define C_IVORY                     0xFFFFFFF0u
#define C_ANTIQUE_WHITE             0xFFFAEBD7u
#define C_LINEN                     0xFFFAF0E6u
#define C_LAVENDER_BLUSH            0xFFFFF0F5u
#define C_MISTY_ROSE                0xFFFFE4E1u

//Gray colors
#define C_GAINSBORO                 0xFFDCDCDCu
#define C_LIGHT_GRAY                0xFFD3D3D3u
#define C_DARK_GRAY                 0xFFA9A9A9u
#define C_DIM_GRAY                  0xFF696969u
#define C_LIGHT_STATE_GRAY          0xFF778899u
#define C_STATE_GRAY                0xFF708090u
#define C_DARK_STATE_GRAY           0xFF2F4F4Fu

/**
 * KEYBOARD BUTTONS
*/
#define KEYBOARD_BUTTON_0               SDLK_0
#define KEYBOARD_BUTTON_1               SDLK_1
#define KEYBOARD_BUTTON_2               SDLK_2
#define KEYBOARD_BUTTON_3               SDLK_3
#define KEYBOARD_BUTTON_4               SDLK_4
#define KEYBOARD_BUTTON_5               SDLK_5
#define KEYBOARD_BUTTON_6               SDLK_6
#define KEYBOARD_BUTTON_7               SDLK_7
#define KEYBOARD_BUTTON_8               SDLK_8
#define KEYBOARD_BUTTON_9               SDLK_9

#define KEYBOARD_BUTTON_A               SDLK_a
#define KEYBOARD_BUTTON_B               SDLK_b
#define KEYBOARD_BUTTON_C               SDLK_c
#define KEYBOARD_BUTTON_D               SDLK_d
#define KEYBOARD_BUTTON_E               SDLK_e
#define KEYBOARD_BUTTON_F               SDLK_f
#define KEYBOARD_BUTTON_G               SDLK_g
#define KEYBOARD_BUTTON_H               SDLK_h
#define KEYBOARD_BUTTON_I               SDLK_i
#define KEYBOARD_BUTTON_J               SDLK_j
#define KEYBOARD_BUTTON_K               SDLK_k
#define KEYBOARD_BUTTON_L               SDLK_l
#define KEYBOARD_BUTTON_M               SDLK_m
#define KEYBOARD_BUTTON_N               SDLK_n
#define KEYBOARD_BUTTON_O               SDLK_o
#define KEYBOARD_BUTTON_P               SDLK_p
#define KEYBOARD_BUTTON_Q               SDLK_q
#define KEYBOARD_BUTTON_R               SDLK_r
#define KEYBOARD_BUTTON_S               SDLK_s
#define KEYBOARD_BUTTON_T               SDLK_t
#define KEYBOARD_BUTTON_U               SDLK_u
#define KEYBOARD_BUTTON_V               SDLK_v
#define KEYBOARD_BUTTON_W               SDLK_w
#define KEYBOARD_BUTTON_X               SDLK_x
#define KEYBOARD_BUTTON_Y               SDLK_y
#define KEYBOARD_BUTTON_Z               SDLK_z

#define KEYBOARD_BUTTON_RETURN          SDLK_RETURN
#define KEYBOARD_BUTTON_ESCAPE          SDLK_ESCAPE
#define KEYBOARD_BUTTON_BACKSPACE       SDLK_BACKSPACE
#define KEYBOARD_BUTTON_TAB             SDLK_TAB
#define KEYBOARD_BUTTON_SPACE           SDLK_SPACE
#define KEYBOARD_BUTTON_CAPSLOCK        SDLK_CAPSLOCK

#define KEYBOARD_BUTTON_F1              SDLK_F1
#define KEYBOARD_BUTTON_F2              SDLK_F2
#define KEYBOARD_BUTTON_F3              SDLK_F3
#define KEYBOARD_BUTTON_F4              SDLK_F4
#define KEYBOARD_BUTTON_F5              SDLK_F5
#define KEYBOARD_BUTTON_F6              SDLK_F6
#define KEYBOARD_BUTTON_F7              SDLK_F7
#define KEYBOARD_BUTTON_F8              SDLK_F8
#define KEYBOARD_BUTTON_F9              SDLK_F9
#define KEYBOARD_BUTTON_F10             SDLK_F10
#define KEYBOARD_BUTTON_F11             SDLK_F11
#define KEYBOARD_BUTTON_F12             SDLK_F12

#define KEYBOARD_BUTTON_PRINTSCREEN     SDLK_PRINTSCREEN
#define KEYBOARD_BUTTON_SCROLLLOCK      SDLK_SCROLLLOCK
#define KEYBOARD_BUTTON_PAUSE           SDLK_PAUSE

#define KEYBOARD_BUTTON_INSERT          SDLK_INSERT
#define KEYBOARD_BUTTON_HOME            SDLK_HOME
#define KEYBOARD_BUTTON_PAGEUP          SDLK_PAGEUP
#define KEYBOARD_BUTTON_DELETE          SDLK_DELETE
#define KEYBOARD_BUTTON_END             SDLK_END
#define KEYBOARD_BUTTON_PAGEDOWN        SDLK_PAGEDOWN

#define KEYBOARD_BUTTON_UP              SDLK_UP
#define KEYBOARD_BUTTON_DOWN            SDLK_DOWN
#define KEYBOARD_BUTTON_LEFT            SDLK_LEFT
#define KEYBOARD_BUTTON_RIGHT           SDLK_RIGHT


#define KEYBOARD_BUTTON_EQUALS          SDLK_EQUALS
#define KEYBOARD_BUTTON_MINUS           SDLK_MINUS
#define KEYBOARD_BUTTON_LEFTBRACKET     SDLK_LEFTBRACKET
#define KEYBOARD_BUTTON_RIGHTBRACKET    SDLK_RIGHTBRACKET
#define KEYBOARD_BUTTON_SEMICOLON       SDLK_SEMICOLON
#define KEYBOARD_BUTTON_COMMA           SDLK_COMMA
#define KEYBOARD_BUTTON_PERIOD          SDLK_PERIOD
#define KEYBOARD_BUTTON_SLASH           SDLK_SLASH

#define KEYBOARD_BUTTON_NUMLOCK         SDLK_NUMLOCKCLEAR
#define KEYBOARD_BUTTON_KP_EQUALS       SDLK_KP_EQUALS
#define KEYBOARD_BUTTON_KP_DIVIDE       SDLK_KP_DIVIDE
#define KEYBOARD_BUTTON_KP_MULTIPLY     SDLK_KP_MULTIPLY
#define KEYBOARD_BUTTON_KP_MINUS        SDLK_KP_MINUS
#define KEYBOARD_BUTTON_KP_PLUS         SDLK_KP_PLUS
#define KEYBOARD_BUTTON_KP_ENTER        SDLK_KP_ENTER
#define KEYBOARD_BUTTON_KP_PERIOD       SDLK_KP_PERIOD

#define KEYBOARD_BUTTON_KP_1            SDLK_KP_1
#define KEYBOARD_BUTTON_KP_2            SDLK_KP_2
#define KEYBOARD_BUTTON_KP_3            SDLK_KP_3
#define KEYBOARD_BUTTON_KP_4            SDLK_KP_4
#define KEYBOARD_BUTTON_KP_5            SDLK_KP_5
#define KEYBOARD_BUTTON_KP_6            SDLK_KP_6
#define KEYBOARD_BUTTON_KP_7            SDLK_KP_7
#define KEYBOARD_BUTTON_KP_8            SDLK_KP_8
#define KEYBOARD_BUTTON_KP_9            SDLK_KP_9
#define KEYBOARD_BUTTON_KP_0            SDLK_KP_0

#define KEYBOARD_BUTTON_LCTRL           SDLK_LCTRL
#define KEYBOARD_BUTTON_LSHIFT          SDLK_LSHIFT
#define KEYBOARD_BUTTON_LALT            SDLK_LALT
#define KEYBOARD_BUTTON_LWIN            SDLK_LGUI
#define KEYBOARD_BUTTON_RCTRL           SDLK_RCTRL
#define KEYBOARD_BUTTON_RSHIFT          SDLK_RSHIFT
#define KEYBOARD_BUTTON_RALT            SDLK_RALT
#define KEYBOARD_BUTTON_RWIN            SDLK_RGUI

/**
 * MOUSE KEYS
*/
#define MOUSE_BUTTON_LEFT               SDL_BUTTON_LEFT
#define MOUSE_BUTTON_MIDDLE             SDL_BUTTON_MIDDLE
#define MOUSE_BUTTON_RIGHT              SDL_BUTTON_RIGHT

/**
 * SOME SYMBOLS FOR TERMINAL
*/
#define SYM_PI   (char)243
#define SYM_DEG  (char)248
#define SYM_RUB  (char)249
#define SYM_EURO (char)250
#define SYM_SQRT (char)251

#pragma endregion

// O------------------------------------------------------------------------------O
// | SPRGC                                                                        |
// O------------------------------------------------------------------------------O
#pragma region spr_gc

class SprGC
{
public:
  //Constructor and deconstructor
  SprGC();
  SprGC(int32_t width, int32_t height);
  SprGC(uint32_t *pixels, int32_t width, int32_t height);
  SprGC(const char *path);
  ~SprGC();
  
  //Edit sprite
  void create(int32_t width, int32_t height);
  void setPixel(int32_t x, int32_t y, uint32_t color);
  void loadSprFromArray(uint32_t *pixels, int32_t width, int32_t height);
  void loadSprFromImage(const char *path);
  void clearSpr();

  //Get info of sprite
  uint32_t* getPixels();
  uint32_t getPixel(int32_t x, int32_t y);
  int32_t getWidth();
  int32_t getHeight();
private:
  friend class DigmeBox_Core;

  SDL_Rect rect_;
  uint32_t* pixels_;
  SDL_Surface* surface_;
  SDL_Texture* texture_;
};

#pragma endregion

// O------------------------------------------------------------------------------O
// | TEXTGC                                                                       |
// O------------------------------------------------------------------------------O
#pragma region text_gc

class TextGC
{
public:
  TextGC();
  TextGC(int32_t cols, int32_t lines);
  TextGC(int32_t cols, int32_t lines, const char* path);
  ~TextGC();

  void create(int32_t cols, int32_t lines);

  //Update
  void update();

  //Control font
  void loadFont(const char* path);
  void deleteFont();

  //Setting cursor
  void setCaretPosition(int32_t x, int32_t y);
  void setCaretForegroundColor(uint32_t foreground_color);
  void setCaretBackgroundColor(uint32_t background_color);
  void setCaretColor(uint32_t foreground_color, uint32_t background_color);

  //Draw
  void changeColor(uint32_t foreground_color, uint32_t background_color);
  void clear();
  void drawSymbol(int32_t x, int32_t y, char sym);

  //Output symbols
  TextGC& operator<<(bool a);
  TextGC& operator<<(uint16_t a);
  TextGC& operator<<(int16_t a);
  TextGC& operator<<(uint32_t a);
  TextGC& operator<<(int32_t a);
  TextGC& operator<<(uint64_t a);
  TextGC& operator<<(int64_t a);
  TextGC& operator<<(float a);
  TextGC& operator<<(double a);
  TextGC& operator<<(const char* text);
  TextGC& operator<<(char c);
  char exactDouble(double a, char size);
  char fixedDouble(double a, char size);

  //Get info of sprite
  uint32_t* getPixels();
  uint32_t getPixel(int32_t x, int32_t y);
  int32_t getWidth();
  int32_t getHeight();
private:
  friend class DigmeBox_Core;

  SprGC sprite_;

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

#pragma endregion

// O------------------------------------------------------------------------------O
// | DIGMEBOX CORE                                                                |
// O------------------------------------------------------------------------------O
#pragma region digmebox_core

class DigmeBox_Core
{

/**
 * INIT
*/
#pragma region init

public:
  //Constructor and deconstructor
  DigmeBox_Core();
  DigmeBox_Core(const char* name, int32_t width_window, int32_t height_window, int32_t width_render, int32_t height_render, uint32_t flag);
  ~DigmeBox_Core();

  //Init
  int DB_init();
  const char* DB_getError();

  //Create a window
  void DB_createWindow(const char* name, int32_t width_window, int32_t height_window, int32_t width_render, int32_t height_render, uint32_t flag);
  void DB_initSprGC(SprGC* spr);
  void DB_initTextGC(TextGC* text);

#pragma endregion

/**
 * WINDOW SYSTEM
*/
#pragma region window_system

public:
  //Manage flags
  bool DB_getFlag(uint32_t flag);
  void DB_setFlag(uint32_t flag, bool toggle);
  void DB_switchFlag(uint32_t flag);
  
  //Status DigmeBox Core
  bool DB_isWorkingDigmeBoxCore();
  void DB_enableDigmeBoxCore();
  void DB_disableDigmeBoxCore();
  void DB_restartDigmeBoxCore();

  //Update
  void DB_updateDigmeBoxCore();

  //Get info of window and render
  bool DB_isFullScreen();
  bool DB_isChangedSizeWindow();

  //Get resolution
  int32_t DB_getResolutionMonitorScreenByWidth();
  int32_t DB_getResolutionMonitorScreenByHeight();
  int32_t DB_getResolutionWindowByWidth();
  int32_t DB_getResolutionWindowByHeight();
  int32_t DB_getResolutionRenderedWindowByWidth();
  int32_t DB_getResolutionRenderedWindowByHeight();
  int32_t DB_getResolutionRenderByWidth();
  int32_t DB_getResolutionRenderByHeight();

  //Get position
  int32_t DB_getWindowPositionX();
  int32_t DB_getWindowPositionY();

  //Setting window
  void DB_setFullScreen(bool toggle);
  void DB_setWindowPosition(int32_t x, int32_t y);
  void DB_setWindowTitle(const char* title);
  void DB_setWindowBorderless(bool toggle);
  void DB_setWindowResizable(bool toggle);
  void DB_resizeWindow(int32_t width, int32_t height);
  void DB_resizeRender(int32_t width_render, int32_t height_render);

  //Draw
  void DB_fill(uint32_t color);
  void DB_drawPixel(int32_t x, int32_t y, uint32_t color);
  void DB_fastDrawPixel(int32_t x, int32_t y, uint32_t color);
  void DB_drawPixelWithBlend(int32_t x, int32_t y, uint32_t color);

  //Draw sprite
  void DB_drawSprite(int32_t x, int32_t y, SprGC* spr);
  void DB_drawPixels(int32_t x, int32_t y, const uint32_t* pixels, int32_t width, int32_t height);

  //Draw sprite with blending
  void DB_drawSpriteWithBlend(int32_t x, int32_t y, SprGC* spr);
  void DB_drawPixelsWithBlend(int32_t x, int32_t y, const uint32_t* pixels, int32_t width, int32_t height);

  //Draw text
  void DB_drawText(int32_t x, int32_t y, TextGC* text);

  //Draw text with blending
  void DB_drawTextWithBlend(int32_t x, int32_t y, TextGC* text);

  //Draw with GPU
  void DB_drawDecalSprite(int32_t x, int32_t y, SprGC* spr);
  void DB_drawDecalText(int32_t x, int32_t y, TextGC* text);

  //Tools drawing
  void DB_drawRect(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color);
  void DB_drawFilledRect(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color);
  void DB_drawCircle(int32_t x, int32_t y, int32_t radius, uint32_t color);
  void DB_drawFilledCircle(int32_t x, int32_t y, int32_t radius, uint32_t color);
  void DB_drawLineRect(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t size, uint32_t color);
  void DB_drawLineCircle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t size, uint32_t color);

  //Tools drawing with blending
  void DB_drawRectWithBlend(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color);
  void DB_drawFilledRectWithBlend(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color);
  void DB_drawCircleWithBlend(int32_t x, int32_t y, int32_t radius, uint32_t color);
  void DB_drawFilledCircleWithBlend(int32_t x, int32_t y, int32_t radius, uint32_t color);
  void DB_drawLineRectWithBlend(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t size, uint32_t color);
  void DB_drawLineCircleWithBlend(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t size, uint32_t color);

  //Get info of cursor
  bool DB_isCursorShow();
  int32_t DB_getCursorOnMonitorScreenX();
  int32_t DB_getCursorOnMonitorScreenY();
  int32_t DB_getCursorOnWindowX();
  int32_t DB_getCursorOnWindowY();
  int32_t DB_getCursorOnRenderX();
  int32_t DB_getCursorOnRenderY();

  //Info of motion cursor
  bool DB_isCursorMotion();
  int32_t DB_getCursorMotionX();
  int32_t DB_getCursorMotionY();

  //Setting cursor
  void DB_setCursorRelative(bool toggle);
  void DB_setCursor(int32_t x, int32_t y, bool show_cursor);

  //Keyboard
  bool DB_isPressedButtonFromKeyboard(int32_t key);
  bool DB_isPressedKeyboard();
  bool DB_isReleasedKeyboard();

  //Mouse
  bool DB_isPressedKeyFromMouse(int32_t key);
  bool DB_isPressedMouse();
  bool DB_isReleasedMouse();

  //Calculate FPS
  int32_t DB_getFPS();
  float DB_getElapsedTime();
  void DB_delayWithFPS();

  //Setting limit FPS
  void DB_setFPSLimit(int32_t fps);
  void DB_setFPSLimitOnIdle(int32_t fps);
  void DB_setStopOnIdle(bool toggle);
private:
  //flags
  uint32_t flags_;

  //Status display
  SDL_Window* window_;
  SDL_Renderer* renderer_;
  SDL_Texture* screen_;
  SDL_DisplayMode display_;

  //Vector of sprites for decal drawing
  std::vector<SDL_Rect> rects_;
  std::vector<SprGC*> decals_;

  //Info of display
  int32_t window_position_x_, window_position_y_;
  int32_t window_width_, window_height_;
  int32_t rendered_window_width_, rendered_window_height_;
  int32_t render_width_, render_height_;

  //Data of screen
  int32_t pitch_;
  uint32_t* pixels_;

  //Info mouse and keyboard
  SDL_Event event_;
  const uint8_t* state_;
  int32_t cursor_monitor_x_, cursor_monitor_y_;
  int32_t cursor_window_x_, cursor_window_y_;
  int32_t cursor_render_x_, cursor_render_y_;
  int32_t cursor_motion_x_, cursor_motion_y_;

  //Info of FPS
  float limit_ms_per_frame_;
  float fps_, limit_fps_, limit_idle_fps_;
  uint64_t now_, end_;

#pragma endregion

/**
 * TERMINAL SYSTEM
*/
#pragma region terminal_system

public:
  //Restart
  void DB_restartTerminal();

  //Update
  void DB_updateTerminal();

  //Control font
  void DB_loadFontTerminal(const char* path);
  void DB_deleteFontTerminal();

  //Setting cursor
  void DB_setCaretPositionTerminal(int32_t x, int32_t y);
  void DB_setCaretForegroundColorTerminal(uint32_t foreground_color);
  void DB_setCaretBackgroundColorTerminal(uint32_t background_color);
  void DB_setCaretColorTerminal(uint32_t foreground_color, uint32_t background_color);

  //Draw
  void DB_changeColorTerminal(uint32_t foreground_color, uint32_t background_color);
  void DB_clearTerminal();
  void DB_drawSymbolTerminal(int32_t x, int32_t y, char sym);

  //Input symbol
  char DB_getSymbolFromKeyboard();

  //Output symbols
  DigmeBox_Core& operator<<(bool a);
  DigmeBox_Core& operator<<(uint16_t a);
  DigmeBox_Core& operator<<(int16_t a);
  DigmeBox_Core& operator<<(uint32_t a);
  DigmeBox_Core& operator<<(int32_t a);
  DigmeBox_Core& operator<<(uint64_t a);
  DigmeBox_Core& operator<<(int64_t a);
  DigmeBox_Core& operator<<(float a);
  DigmeBox_Core& operator<<(double a);
  DigmeBox_Core& operator<<(const char* text);
  DigmeBox_Core& operator<<(char c);
  char DB_exactDouble(double a, char size);
  char DB_fixedDouble(double a, char size);
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

#pragma endregion

};

#pragma endregion

#endif
#else
  #error Please include library SDL2! (T_T)
#endif