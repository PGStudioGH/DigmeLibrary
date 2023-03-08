#include "..\Additions\InputOutputGC.h"

uint32_t GetColor(uint8_t R, uint8_t G, uint8_t B, uint8_t A)
{
    return (A << 24) | (R << 16) | (G << 8) | B;
}
uint32_t SetAlpha(uint32_t color, uint8_t alpha)
{
    return (color & 0x00FFFFFF) | (alpha << 24);
}
uint8_t GetAlpha(uint32_t color)
{
    return color >> 24;
}

InputOutputGC::InputOutputGC(const char* name, int32_t width_screen, int32_t height_screen, int32_t width_render, int32_t height_render, uint32_t flag)
{
    setFlag(flag, 1);

    //Display and screen
    width_window_ = width_screen;
    height_window_ = height_screen;
    width_render_ = width_render;
    height_render_ = height_render;
    pitch_ = 0;
    pixels_ = nullptr;

    //FPS
    limit_fps_ = UNLIMITED_FPS;
    ms_per_frame_ = 0.0f;
    fps_ = 0;
    now_ = SDL_GetPerformanceCounter();
    end_ = 0;

    //Create window
    window_ = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width_window_, height_window_,
        SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_GetWindowPosition(window_, &window_x_, &window_y_);

    //Create renderer
    if (getFlag(HARDWARE_ACCELERATED))
        renderer_ = SDL_CreateRenderer(window_, RENDER_DEVICE, SDL_RENDERER_ACCELERATED);
    else renderer_ = SDL_CreateRenderer(window_, RENDER_DEVICE, SDL_RENDERER_SOFTWARE);
    SDL_RenderSetLogicalSize(renderer_, width_render_, height_render_);
    SDL_RenderSetIntegerScale(renderer_, SDL_FALSE);

    //Create texture for rendering screen
    screen_ = SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING, width_render_, height_render_);
    SDL_LockTexture(screen_, NULL, (void**)&pixels_, &pitch_);
    pitch_ /= sizeof int32_t;

    //Get info display
    SDL_GetCurrentDisplayMode(0, &display_);

    //Clear display
    fillDisplay(C_BLACK);

    //Input and event
    setFlag(CURSOR_SHOW, 1);
    SDL_PollEvent(&event_);
    state_ = SDL_GetKeyboardState(NULL);
    SDL_GetGlobalMouseState(&cursor_global_new_x_, &cursor_global_new_y_);
    SDL_GetMouseState(&cursor_window_new_x_, &cursor_window_new_y_);
    cursor_render_new_x_ = (int32_t)((cursor_window_new_x_ - (width_global_window_ - width_window_) / 2.0f) * (width_render_ * 1.0f / width_window_));
    cursor_render_new_y_ = (int32_t)((cursor_window_new_y_ - (height_global_window_ - height_window_) / 2.0f) * (height_render_ * 1.0f / height_window_));
    cursor_global_old_x_ = cursor_global_new_x_;
    cursor_global_old_y_ = cursor_global_new_y_;
    cursor_window_old_x_ = cursor_window_new_x_;
    cursor_window_old_y_ = cursor_window_new_y_;
    cursor_render_old_x_ = cursor_render_new_x_;
    cursor_render_old_y_ = cursor_render_new_y_;
    cursor_global_motion_x_ = 0; cursor_global_motion_y_ = 0;
    cursor_render_motion_x_ = 0; cursor_render_motion_y_ = 0;
}
InputOutputGC::~InputOutputGC()
{
    SDL_DestroyTexture(screen_);
    screen_ = nullptr;
    SDL_DestroyRenderer(renderer_);
    renderer_ = nullptr;
    SDL_DestroyWindow(window_);
    window_ = nullptr;
    SDL_Quit();
}

//Status display
int InputOutputGC::init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return 1;
    if (window_ == nullptr) return 1;
    if (renderer_ == nullptr) return 1;
    if (screen_ == nullptr) return 1;
    return 0;
}
int InputOutputGC::getError()
{
    return (int)(int64_t)SDL_GetError();
}
bool InputOutputGC::isWorkingDisplay()
{
    return getFlag(WORKING_DISPLAY);
}
void InputOutputGC::enableDisplay()
{
    setFlag(WORKING_DISPLAY, 1);
}
void InputOutputGC::disableDisplay()
{
    setFlag(WORKING_DISPLAY, 0);
}
void InputOutputGC::restartDisplay()
{
    setFlag(FULL_FLAGS, 0);
    fillDisplay(C_BLACK);
    setFullScreen(0);
    setTitleWindow("VirtualScreen");
    ms_per_frame_ = 0.0f;
}

//Update
void InputOutputGC::updateDisplay()
{
    //Output display from pixels
    SDL_UnlockTexture(screen_);
    SDL_RenderCopy(renderer_, screen_, NULL, NULL);
    SDL_RenderPresent(renderer_);
    SDL_LockTexture(screen_, NULL, (void**)&pixels_, &pitch_);
    pitch_ /= sizeof int32_t;

    //Calculate FPS and delay
    end_ = SDL_GetPerformanceCounter();
    float elapsed_ms = (float)(end_ - now_) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
    if (elapsed_ms < ms_per_frame_)
    {
        float ms_left = ms_per_frame_ - elapsed_ms;
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
    fps_ = (int32_t)(1.0f / (elapsed_ms / 1000.0f));
    now_ = SDL_GetPerformanceCounter();

    //Update window
    SDL_GetWindowSize(window_, &width_global_window_, &height_global_window_);
    SDL_GetWindowPosition(window_, &window_x_, &window_y_);
    if ((float)width_render_ / height_render_ < (float)width_global_window_ / height_global_window_)
    {
        width_window_ = (int32_t)(width_global_window_ * ((float)width_render_ / height_render_) / ((float)width_global_window_ / height_global_window_) + 0.5f);
        height_window_ = height_global_window_;
    }
    else if ((float)width_render_ / height_render_ > (float)width_global_window_ / height_global_window_)
    {
        width_window_ = width_global_window_;
        height_window_ = (int32_t)(height_global_window_ * ((float)width_global_window_ / height_global_window_) / ((float)width_render_ / height_render_) + 0.5f);
    }
    else
    {
        width_window_ = width_global_window_;
        height_window_ = height_global_window_;
    }

    //Update cursor and event
    if (getFlag(FIXED_CURSOR))
    {
        cursor_global_old_x_ = display_.w / 2;
        cursor_global_old_y_ = display_.h / 2;
        cursor_window_old_x_ = width_window_ / 2;
        cursor_window_old_y_ = height_window_ / 2;
        cursor_render_old_x_ = width_render_ / 2;
        cursor_render_old_y_ = height_render_ / 2;
    }
    else
    {
        cursor_global_old_x_ = cursor_global_new_x_;
        cursor_global_old_y_ = cursor_global_new_y_;
        cursor_window_old_x_ = cursor_window_new_x_;
        cursor_window_old_y_ = cursor_window_new_y_;
        cursor_render_old_x_ = cursor_render_new_x_;
        cursor_render_old_y_ = cursor_render_new_y_;
    }
    SDL_GetGlobalMouseState(&cursor_global_new_x_, &cursor_global_new_y_);
    SDL_GetMouseState(&cursor_window_new_x_, &cursor_window_new_y_);
    cursor_render_new_x_ = (int32_t)((cursor_window_new_x_ - (width_global_window_ - width_window_) / 2.0f) * (width_render_ * 1.0f / width_window_));
    cursor_render_new_y_ = (int32_t)((cursor_window_new_y_ - (height_global_window_ - height_window_) / 2.0f) * (height_render_ * 1.0f / height_window_));
    cursor_global_motion_x_ = cursor_global_new_x_ - cursor_global_old_x_;
    cursor_global_motion_y_ = cursor_global_new_y_ - cursor_global_old_y_;
    cursor_render_motion_x_ = cursor_render_new_x_ - cursor_render_old_x_;
    cursor_render_motion_y_ = cursor_render_new_y_ - cursor_render_old_y_;
    if (getFlag(FIXED_CURSOR)) SDL_WarpMouseGlobal(display_.w / 2, display_.h / 2);

    SDL_PollEvent(&event_);

    //Update event
    if (event_.window.event == SDL_WINDOWEVENT_FOCUS_LOST) ms_per_frame_ = 75.0f;
    if (event_.window.event == SDL_WINDOWEVENT_FOCUS_GAINED) ms_per_frame_ = 1000.0f / limit_fps_;
    if (event_.type == SDL_QUIT) setFlag(WORKING_DISPLAY, 0);
}

//Get info of window and render
bool InputOutputGC::isFullScreen()
{
    return getFlag(FULLSCREEN);
}
int32_t InputOutputGC::getWidthGlobalDisplay()
{
    return display_.w;
}
int32_t InputOutputGC::getHeightGlobalDisplay()
{
    return display_.h;
}
int32_t InputOutputGC::getWidthGlobalWindow()
{
    SDL_GetWindowSize(window_, &width_global_window_, &height_global_window_);
    return width_global_window_;
}
int32_t InputOutputGC::getHeightGlobalWindow()
{
    SDL_GetWindowSize(window_, &width_global_window_, &height_global_window_);
    return height_global_window_;
}
int32_t InputOutputGC::getWidthWindow()
{
    return width_window_;
}
int32_t InputOutputGC::getHeightWindow()
{
    return height_window_;
}
int32_t InputOutputGC::getWidthDisplay()
{
    return width_render_;
}
int32_t InputOutputGC::getHeightDisplay()
{
    return height_render_;
}
int32_t InputOutputGC::getWindowPositionX()
{
    SDL_GetWindowPosition(window_, &window_x_, &window_y_);
    return window_x_;
}
int32_t InputOutputGC::getWindowPositionY()
{
    SDL_GetWindowPosition(window_, &window_x_, &window_y_);
    return window_y_;
}

//Setting window
void InputOutputGC::setFullScreen(bool toggle)
{
    setFlag(FULLSCREEN, toggle);
    SDL_SetWindowFullscreen(window_, getFlag(FULLSCREEN ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0));
    SDL_GetWindowSize(window_, &width_global_window_, &height_global_window_);
    SDL_WarpMouseGlobal(display_.w >> 1, display_.h >> 1);
}
void InputOutputGC::setWindowPosition(int32_t x, int32_t y)
{
    SDL_SetWindowPosition(window_, x, y);
}
void InputOutputGC::resizeWindow(int32_t width, int32_t height)
{
    SDL_SetWindowSize(window_, width, height);
}
void InputOutputGC::setTitleWindow(const char* title)
{
    SDL_SetWindowTitle(window_, title);
}
void InputOutputGC::setBorderlessWindow(bool toggle)
{
    if (toggle) SDL_SetWindowBordered(window_, SDL_FALSE);
    else SDL_SetWindowBordered(window_, SDL_TRUE);
}
void InputOutputGC::setResizableWindow(bool toggle)
{
    if (toggle) SDL_SetWindowResizable(window_, SDL_TRUE);
    else SDL_SetWindowResizable(window_, SDL_FALSE);
}

//Draw
void InputOutputGC::fillDisplay(uint32_t color)
{
    SDL_memset4(pixels_, color, width_render_ * height_render_);
}
void InputOutputGC::drawPixel(int32_t x, int32_t y, uint32_t color)
{
    if (x < 0 || width_render_ <= x || y < 0 || height_render_ <= y) return;
    pixels_[y * width_render_ + x] = color;
}
void InputOutputGC::fastDrawPixel(int32_t x, int32_t y, uint32_t color)
{
    pixels_[y * width_render_ + x] = color;
}
void InputOutputGC::drawPixelWithAlpha(int32_t x, int32_t y, uint32_t color)
{
    static int32_t index;
    static uint8_t new_color[4]{};
    static uint8_t current_color[4]{};

    if (x < 0 || width_render_ <= x || y < 0 || height_render_ <= y) return;

    *(uint32_t*)new_color = color;
    if (new_color[3] == (uint8_t)0x00) return;
    
    index = y * width_render_ + x;

    if (new_color[3] == (uint8_t)0xFF) pixels_[index] = *(uint32_t*)new_color;
    else if (new_color[3] == (uint8_t)0x7F) pixels_[index] =
        ((((*(uint32_t*)new_color & 0xFF00FF) + (pixels_[index] & 0xFF00FF)) >> 1) & 0xFF00FF) |
        ((((*(uint32_t*)new_color & 0x00FF00) + (pixels_[index] & 0x00FF00)) >> 1) & 0x00FF00);
    else
    {
        *(uint32_t*)current_color = pixels_[index];

        current_color[2] = (((new_color[2] - current_color[2]) * (new_color[3] + 1)) >> 8) + current_color[2];
        current_color[1] = (((new_color[1] - current_color[1]) * (new_color[3] + 1)) >> 8) + current_color[1];
        current_color[0] = (((new_color[0] - current_color[0]) * (new_color[3] + 1)) >> 8) + current_color[0];

        //Draw
        pixels_[index] = *(uint32_t*)current_color;
    }
}

//Tools drawing
void InputOutputGC::drawRect(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color)
{
    drawFilledRect(x1, y1, x2, y1, color);
    drawFilledRect(x1, y1 + 1, x1, y2, color);
    drawFilledRect(x1 + 1, y2, x2, y2, color);
    drawFilledRect(x2, y1 + 1, x2, y2 - 1, color);
}
void InputOutputGC::drawFilledRect(int32_t x1, int32_t y1, int32_t x2, int32_t y2, uint32_t color)
{
    for (int32_t i = y2; i >= y1; i--)
        for (int32_t j = x2; j >= x1; j--)
            drawPixel(j, i, color);
}
void InputOutputGC::drawCircle(int32_t x, int32_t y, int32_t radius, uint32_t color)
{
    int32_t x0 = 0;
    int32_t y0 = radius;
    int32_t delta = 1 - 2 * radius;
    int32_t error = 0;
    while (y >= 0) {
        drawPixel(x + x0, y + y0, color);
        drawPixel(x + x0, y - y0, color);
        drawPixel(x - x0 + 1, y + y0, color);
        drawPixel(x - x0 + 1, y - y0, color);
        error = 2 * (delta + y0) - 1;
        if (delta < 0 && error <= 0) {
            ++x0;
            delta += 2 * x0 + 1;
            continue;
        }
        error = 2 * (delta - x0) - 1;
        if (delta > 0 && error > 0) {
            --y0;
            delta += 1 - 2 * y0;
            continue;
        }
        ++x0;
        delta += 2 * (x0 - y0);
        --y0;
    }
}
void InputOutputGC::drawFilledCircle(int32_t x, int32_t y, int32_t radius, uint32_t color)
{
    int32_t x0 = 0;
    int32_t y0 = radius;
    int32_t delta = 1 - 2 * radius;
    int32_t error = 0;
    while (y >= 0) {
        drawFilledRect(x - x0 + 1, y + y0, x + x0, y + y0, color);
        drawFilledRect(x - x0 + 1, y - y0, x + x0, y - y0, color);
        error = 2 * (delta + y0) - 1;
        if (delta < 0 && error <= 0) {
            ++x0;
            delta += 2 * x0 + 1;
            continue;
        }
        error = 2 * (delta - x0) - 1;
        if (delta > 0 && error > 0) {
            --y0;
            delta += 1 - 2 * y0;
            continue;
        }
        ++x0;
        delta += 2 * (x0 - y0);
        --y0;
    }
}
void InputOutputGC::drawLineRect(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t size, uint32_t color)
{
    const bool carry = size % 2;
    const int32_t deltaX = abs(x2 - x1);
    const int32_t deltaY = abs(y2 - y1);
    const int32_t signX = x1 < x2 ? 1 : -1;
    const int32_t signY = y1 < y2 ? 1 : -1;
    int32_t error = deltaX - deltaY;
    size = size / 2;
    drawFilledRect(x2 - size + 1 - carry, y2 - size + 1 - carry, x2 + size, y2 + size, color);
    while (x1 != x2 || y1 != y2)
    {
        drawFilledRect(x1 - size + 1 - carry, y1 - size + 1 - carry, x1 + size, y1 + size, color);
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
void InputOutputGC::drawLineCircle(int32_t x1, int32_t y1, int32_t x2, int32_t y2, int32_t size, uint32_t color)
{
    const int32_t deltaX = abs(x2 - x1);
    const int32_t deltaY = abs(y2 - y1);
    const int32_t signX = x1 < x2 ? 1 : -1;
    const int32_t signY = y1 < y2 ? 1 : -1;
    int32_t error = deltaX - deltaY;
    drawFilledCircle(x2, y2, size / 2, color);
    while (x1 != x2 || y1 != y2)
    {
        drawFilledCircle(x1, y1, size / 2, color);
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
int32_t InputOutputGC::getGlobalCursorX()
{
    return cursor_global_new_x_;
}
int32_t InputOutputGC::getGlobalCursorY()
{
    return cursor_global_new_y_;
}
int32_t InputOutputGC::getWindowCursorX()
{
    return cursor_window_new_x_;
}
int32_t InputOutputGC::getWindowCursorY()
{
    return cursor_window_new_y_;
}
int32_t InputOutputGC::getRenderCursorX()
{
    return cursor_render_new_x_;
}
int32_t InputOutputGC::getRenderCursorY()
{
    return cursor_render_new_y_;
}
bool InputOutputGC::isShowCursor()
{
    return getFlag(CURSOR_SHOW);
}

//Info of motion cursor
int32_t InputOutputGC::getMotionCursorGlobalX()
{
    return cursor_global_motion_x_;
}
int32_t InputOutputGC::getMotionCursorGlobalY()
{
    return cursor_global_motion_y_;
}
int32_t InputOutputGC::getMotionCursorRenderX()
{
    return cursor_render_motion_x_;
}
int32_t InputOutputGC::getMotionCursorRenderY()
{
    return cursor_render_motion_y_;
}
bool InputOutputGC::isMotionMouse()
{
    return event_.type == SDL_MOUSEMOTION;
}

//Setting cursor
void InputOutputGC::setFixedCursor(bool toggle)
{
    setFlag(FIXED_CURSOR, toggle);
}
void InputOutputGC::setCursor(int32_t x, int32_t y, bool show_cursor)
{
    setFlag(CURSOR_SHOW, show_cursor);
    SDL_WarpMouseGlobal(x, y);
    SDL_ShowCursor(getFlag(CURSOR_SHOW));
}

//Keyboard
bool InputOutputGC::isPressedKeyFromKeyboard(uint8_t key)
{
    return state_[key];
}
bool InputOutputGC::isPressedKeyboard()
{
    return event_.type == SDL_KEYDOWN;
}
bool InputOutputGC::isReleasedKeyboard()
{
    return event_.type == SDL_KEYUP;
}

//Mouse
bool InputOutputGC::isPressedKeyFromMouse(uint8_t key)
{
    return event_.button.button == key;
}
bool InputOutputGC::isPressedMouse()
{
    return event_.type == SDL_MOUSEBUTTONDOWN;
}
bool InputOutputGC::isReleasedMouse()
{
    return event_.type == SDL_MOUSEBUTTONUP;
}

//Calculate FPS
int32_t InputOutputGC::getFPS()
{
    return fps_;
}
float InputOutputGC::getElapsedTime()
{
    return 1.0f / (float)fps_;
}
void InputOutputGC::setLimitFPS(int32_t fps)
{
    ms_per_frame_ = 1000.0f / (float)fps;
    limit_fps_ = fps;
}