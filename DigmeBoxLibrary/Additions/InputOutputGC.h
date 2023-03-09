#if __has_include(<SDL.h>)

#ifndef VIRTUALDISPLAYGC_H
#define VIRTUALDISPLAYGC_H

#include <SDL.h>

#include "FlagsManager.h"
#include "..\Setting\Flags.h"

#define UNLIMITED_FPS 0x7F800000
#define RENDER_DEVICE 0xFFFFFFFF

#ifndef COLORGC_H
#define COLORGC_H
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
#endif

#ifndef BUTTONGC_H
#define BUTTONGC_H
    #define KEYBOARD_BUTTON_0               SDL_SCANCODE_0
    #define KEYBOARD_BUTTON_1               SDL_SCANCODE_1
    #define KEYBOARD_BUTTON_2               SDL_SCANCODE_2
    #define KEYBOARD_BUTTON_3               SDL_SCANCODE_3
    #define KEYBOARD_BUTTON_4               SDL_SCANCODE_4
    #define KEYBOARD_BUTTON_5               SDL_SCANCODE_5
    #define KEYBOARD_BUTTON_6               SDL_SCANCODE_6
    #define KEYBOARD_BUTTON_7               SDL_SCANCODE_7
    #define KEYBOARD_BUTTON_8               SDL_SCANCODE_8
    #define KEYBOARD_BUTTON_9               SDL_SCANCODE_9

    #define KEYBOARD_BUTTON_A               SDL_SCANCODE_A
    #define KEYBOARD_BUTTON_B               SDL_SCANCODE_B
    #define KEYBOARD_BUTTON_C               SDL_SCANCODE_C
    #define KEYBOARD_BUTTON_D               SDL_SCANCODE_D
    #define KEYBOARD_BUTTON_E               SDL_SCANCODE_E
    #define KEYBOARD_BUTTON_F               SDL_SCANCODE_F
    #define KEYBOARD_BUTTON_G               SDL_SCANCODE_G
    #define KEYBOARD_BUTTON_H               SDL_SCANCODE_H
    #define KEYBOARD_BUTTON_I               SDL_SCANCODE_I
    #define KEYBOARD_BUTTON_J               SDL_SCANCODE_J
    #define KEYBOARD_BUTTON_K               SDL_SCANCODE_K
    #define KEYBOARD_BUTTON_L               SDL_SCANCODE_L
    #define KEYBOARD_BUTTON_M               SDL_SCANCODE_M
    #define KEYBOARD_BUTTON_N               SDL_SCANCODE_N
    #define KEYBOARD_BUTTON_O               SDL_SCANCODE_O
    #define KEYBOARD_BUTTON_P               SDL_SCANCODE_P
    #define KEYBOARD_BUTTON_Q               SDL_SCANCODE_Q
    #define KEYBOARD_BUTTON_R               SDL_SCANCODE_R
    #define KEYBOARD_BUTTON_S               SDL_SCANCODE_S
    #define KEYBOARD_BUTTON_T               SDL_SCANCODE_T
    #define KEYBOARD_BUTTON_U               SDL_SCANCODE_U
    #define KEYBOARD_BUTTON_V               SDL_SCANCODE_V
    #define KEYBOARD_BUTTON_W               SDL_SCANCODE_W
    #define KEYBOARD_BUTTON_X               SDL_SCANCODE_X
    #define KEYBOARD_BUTTON_Y               SDL_SCANCODE_Y
    #define KEYBOARD_BUTTON_Z               SDL_SCANCODE_Z

    #define KEYBOARD_BUTTON_RETURN          SDL_SCANCODE_RETURN
    #define KEYBOARD_BUTTON_ESCAPE          SDL_SCANCODE_ESCAPE
    #define KEYBOARD_BUTTON_BACKSPACE       SDL_SCANCODE_BACKSPACE
    #define KEYBOARD_BUTTON_TAB             SDL_SCANCODE_TAB
    #define KEYBOARD_BUTTON_SPACE           SDL_SCANCODE_SPACE
    #define KEYBOARD_BUTTON_CAPSLOCK        SDL_SCANCODE_CAPSLOCK

    #define KEYBOARD_BUTTON_F1              SDL_SCANCODE_F1
    #define KEYBOARD_BUTTON_F2              SDL_SCANCODE_F2
    #define KEYBOARD_BUTTON_F3              SDL_SCANCODE_F3
    #define KEYBOARD_BUTTON_F4              SDL_SCANCODE_F4
    #define KEYBOARD_BUTTON_F5              SDL_SCANCODE_F5
    #define KEYBOARD_BUTTON_F6              SDL_SCANCODE_F6
    #define KEYBOARD_BUTTON_F7              SDL_SCANCODE_F7
    #define KEYBOARD_BUTTON_F8              SDL_SCANCODE_F8
    #define KEYBOARD_BUTTON_F9              SDL_SCANCODE_F9
    #define KEYBOARD_BUTTON_F10             SDL_SCANCODE_F10
    #define KEYBOARD_BUTTON_F11             SDL_SCANCODE_F11
    #define KEYBOARD_BUTTON_F12             SDL_SCANCODE_F12

    #define KEYBOARD_BUTTON_PRINTSCREEN     SDL_SCANCODE_PRINTSCREEN
    #define KEYBOARD_BUTTON_SCROLLLOCK      SDL_SCANCODE_SCROLLLOCK
    #define KEYBOARD_BUTTON_PAUSE           SDL_SCANCODE_PAUSE

    #define KEYBOARD_BUTTON_INSERT          SDL_SCANCODE_INSERT
    #define KEYBOARD_BUTTON_HOME            SDL_SCANCODE_HOME
    #define KEYBOARD_BUTTON_PAGEUP          SDL_SCANCODE_PAGEUP
    #define KEYBOARD_BUTTON_DELETE          SDL_SCANCODE_DELETE
    #define KEYBOARD_BUTTON_END             SDL_SCANCODE_END
    #define KEYBOARD_BUTTON_PAGEDOWN        SDL_SCANCODE_PAGEDOWN

    #define KEYBOARD_BUTTON_UP              SDL_SCANCODE_UP
    #define KEYBOARD_BUTTON_DOWN            SDL_SCANCODE_DOWN
    #define KEYBOARD_BUTTON_LEFT            SDL_SCANCODE_LEFT
    #define KEYBOARD_BUTTON_RIGHT           SDL_SCANCODE_RIGHT


    #define KEYBOARD_BUTTON_EQUALS          SDL_SCANCODE_EQUALS
    #define KEYBOARD_BUTTON_MINUS           SDL_SCANCODE_MINUS
    #define KEYBOARD_BUTTON_LEFTBRACKET     SDL_SCANCODE_LEFTBRACKET
    #define KEYBOARD_BUTTON_RIGHTBRACKET    SDL_SCANCODE_RIGHTBRACKET
    #define KEYBOARD_BUTTON_SEMICOLON       SDL_SCANCODE_SEMICOLON
    #define KEYBOARD_BUTTON_APOSTROPHE      SDL_SCANCODE_APOSTROPHE
    #define KEYBOARD_BUTTON_COMMA           SDL_SCANCODE_COMMA
    #define KEYBOARD_BUTTON_PERIOD          SDL_SCANCODE_PERIOD
    #define KEYBOARD_BUTTON_SLASH           SDL_SCANCODE_SLASH

    #define KEYBOARD_BUTTON_NUMLOCK         SDL_SCANCODE_NUMLOCKCLEAR
    #define KEYBOARD_BUTTON_KP_EQUALS       SDL_SCANCODE_KP_EQUALS
    #define KEYBOARD_BUTTON_KP_DIVIDE       SDL_SCANCODE_KP_DIVIDE
    #define KEYBOARD_BUTTON_KP_MULTIPLY     SDL_SCANCODE_KP_MULTIPLY
    #define KEYBOARD_BUTTON_KP_MINUS        SDL_SCANCODE_KP_MINUS
    #define KEYBOARD_BUTTON_KP_PLUS         SDL_SCANCODE_KP_PLUS
    #define KEYBOARD_BUTTON_KP_ENTER        SDL_SCANCODE_KP_ENTER
    #define KEYBOARD_BUTTON_KP_PERIOD       SDL_SCANCODE_KP_PERIOD

    #define KEYBOARD_BUTTON_KP_1            SDL_SCANCODE_KP_1
    #define KEYBOARD_BUTTON_KP_2            SDL_SCANCODE_KP_2
    #define KEYBOARD_BUTTON_KP_3            SDL_SCANCODE_KP_3
    #define KEYBOARD_BUTTON_KP_4            SDL_SCANCODE_KP_4
    #define KEYBOARD_BUTTON_KP_5            SDL_SCANCODE_KP_5
    #define KEYBOARD_BUTTON_KP_6            SDL_SCANCODE_KP_6
    #define KEYBOARD_BUTTON_KP_7            SDL_SCANCODE_KP_7
    #define KEYBOARD_BUTTON_KP_8            SDL_SCANCODE_KP_8
    #define KEYBOARD_BUTTON_KP_9            SDL_SCANCODE_KP_9
    #define KEYBOARD_BUTTON_KP_0            SDL_SCANCODE_KP_0

    #define KEYBOARD_BUTTON_LCTRL           SDL_SCANCODE_LCTRL
    #define KEYBOARD_BUTTON_LSHIFT          SDL_SCANCODE_LSHIFT
    #define KEYBOARD_BUTTON_LALT            SDL_SCANCODE_LALT
    #define KEYBOARD_BUTTON_LWIN            SDL_SCANCODE_LGUI
    #define KEYBOARD_BUTTON_RCTRL           SDL_SCANCODE_RCTRL
    #define KEYBOARD_BUTTON_RSHIFT          SDL_SCANCODE_RSHIFT
    #define KEYBOARD_BUTTON_RALT            SDL_SCANCODE_RALT
    #define KEYBOARD_BUTTON_RWIN            SDL_SCANCODE_RGUI

    #define MOUSE_BUTTON_LEFT               SDL_BUTTON_LEFT
    #define MOUSE_BUTTON_MIDDLE             SDL_BUTTON_MIDDLE
    #define MOUSE_BUTTON_RIGHT              SDL_BUTTON_RIGHT
#endif

uint32_t GetColor(uint8_t R, uint8_t G, uint8_t B, uint8_t A);
uint32_t SetAlpha(uint32_t color, uint8_t alpha);
uint8_t GetAlpha(uint32_t color);

class InputOutputGC : public FlagsManager
{
public:
    InputOutputGC(const char* name, int32_t width_screen, int32_t height_screen, int32_t width_render, int32_t height_render, uint32_t flag);
    ~InputOutputGC();

    //Status display
    int init();
    int getError();
    bool isWorkingDisplay();
    void enableDisplay();
    void disableDisplay();
    void restartDisplay();

    //Update
    void updateDisplay();

    //Get info of window and render
    bool isFullScreen();
    int32_t getWidthGlobalDisplay();
    int32_t getHeightGlobalDisplay();
    int32_t getWidthGlobalWindow();
    int32_t getHeightGlobalWindow();
    int32_t getWidthWindow();
    int32_t getHeightWindow();
    int32_t getWidthDisplay();
    int32_t getHeightDisplay();
    int32_t getWindowPositionX();
    int32_t getWindowPositionY();

    //Setting window
    void setFullScreen(bool toggle);
    void setWindowPosition(int32_t x, int32_t y);
    void resizeWindow(int32_t width, int32_t height);
    void setTitleWindow(const char* title);
    void setBorderlessWindow(bool toggle);
    void setResizableWindow(bool toggle);

    //Draw
    void fillDisplay(uint32_t color);
    void drawPixel(int32_t x, int32_t y, uint32_t color);
    void fastDrawPixel(int32_t x, int32_t y, uint32_t color);
    void drawPixelWithAlpha(int32_t x, int32_t y, uint32_t color);

    //Tools drawing
    void drawRect(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color);
    void drawFilledRect(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color);
    void drawCircle(int32_t x, int32_t y, int32_t radius, uint32_t color);
    void drawFilledCircle(int32_t x, int32_t y, int32_t radius, uint32_t color);
    void drawLineRect(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t size, uint32_t color);
    void drawLineCircle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t size, uint32_t color);

    //Get info of cursor
    int32_t getGlobalCursorX();
    int32_t getGlobalCursorY();
    int32_t getWindowCursorX();
    int32_t getWindowCursorY();
    int32_t getRenderCursorX();
    int32_t getRenderCursorY();
    bool isShowCursor();

    //Info of motion cursor
    int32_t getMotionCursorGlobalX();
    int32_t getMotionCursorGlobalY();
    int32_t getMotionCursorRenderX();
    int32_t getMotionCursorRenderY();
    bool isMotionMouse();

    //Setting cursor
    void setFixedCursor(bool toggle);
    void setCursor(int32_t x, int32_t y, bool show_cursor);

    //Keyboard
    bool isPressedKeyFromKeyboard(uint8_t key);
    bool isPressedKeyboard();
    bool isReleasedKeyboard();

    //Mouse
    bool isPressedKeyFromMouse(uint8_t key);
    bool isPressedMouse();
    bool isReleasedMouse();

    //Calculate FPS
    int32_t getFPS();
    float getElapsedTime();
    void setLimitFPS(int32_t fps);
protected:
    //Status display
    SDL_Window* window_;
    SDL_Renderer* renderer_;
    SDL_Texture* screen_;
    SDL_DisplayMode display_;

    //Info of display
    int32_t window_x_, window_y_;
    int32_t width_global_window_, height_global_window_;
    int32_t width_window_, height_window_;
    int32_t width_render_, height_render_;
    int32_t pitch_;
    uint32_t* pixels_;

    //Info mouse and keyboard
    SDL_Event event_;
    const uint8_t* state_;
    int32_t cursor_global_new_x_, cursor_global_new_y_;
    int32_t cursor_global_old_x_, cursor_global_old_y_;
    int32_t cursor_window_new_x_, cursor_window_new_y_;
    int32_t cursor_window_old_x_, cursor_window_old_y_;
    int32_t cursor_render_new_x_, cursor_render_new_y_;
    int32_t cursor_render_old_x_, cursor_render_old_y_;
    int32_t cursor_global_motion_x_, cursor_global_motion_y_;
    int32_t cursor_render_motion_x_, cursor_render_motion_y_;

    //Info of FPS
    float ms_per_frame_;
    int32_t fps_, limit_fps_;
    uint64_t now_, end_;
};

#endif
#else
    #error Please include library SDL2! (T_T)

#endif
