#ifndef DIGMEBOX_H
#define DIGMEBOX_H

// O------------------------------------------------------------------------------O
// | INCLUDES                                                                     |
// O------------------------------------------------------------------------------O
#pragma region includes

/**
 * USE DIGMEBOX CORE
 */
#include <DigmeBoxCore.h>

#pragma endregion

// O------------------------------------------------------------------------------O
// | CODE EXAMPLE                                                                 |
// O------------------------------------------------------------------------------O
#pragma region digmebox_example

/** EXAMPLE CODE WITH USING INTERFACE DIGMEBOX FOR STUPID C++ PROGRAMMERS
 * 
 * DIGMEBOX_INIT()
 *   DIGMEBOX_CREATE_VARIABLES()
 *     int max_fps;
 * INIT_END
 * 
 * DIGMEBOX_CREATE(1024, 960, 256, 240)
 * 
 * DIGMEBOX_USER_CREATE()
 *   max_fps = 0;
 *   DB_setWindowTitle("Super app!");
 * SECTION_END
 * 
 * DIGMEBOX_USER_UPDATE()
 *   for (int i = 0; i < DB_getResolutionRenderByWidth(); i++)
 *     for (int j = 0; j < DB_getResolutionRenderByHeight(); j++)
 *       DB_drawPixel(i, j, getRandom32());
 *
 *   DB_clearTerminal();
 *   DB_Out << "FPS:" << DB_getFPS() << '\n';
 *   DB_Out << "MAX_FPS:" << max_fps;
 *  
 *   DB_updateTerminal();
 *   DB_updateDigmeBoxCore();
 *
 *   if (max_fps < DB_getFPS())
 *     max_fps = DB_getFPS();
 * SECTION_END
 * 
 * DIGMEBOX_USER_DESTROY()
 * SECTION_END
*/

/** EXAMPLE CODE ON C++
 * 
 * class Game : public DigmeBox
 * {
 * public:
 *   Game()
 *   {
 *     NameApp = "New window";
 *   };
 *   ~Game() {};
 * 
 * public:
 *   bool create() override
 *   {
 *     max_fps = 0;
 *     DB_setWindowTitle("Super app!");
 *   }
 *   bool update() override
 *   {
 *     for (int i = 0; i < DB_getResolutionRenderByWidth(); i++)
 *       for (int j = 0; j < DB_getResolutionRenderByHeight(); j++)
 *         DB_drawPixel(i, j, getRandom32());
 *
 *     DB_clearTerminal();
 *     DB_Out << "FPS:" << DB_getFPS() << '\n';
 *     DB_Out << "MAX_FPS:" << max_fps;
 *  
 *     DB_updateTerminal();
 *     DB_updateDigmeBoxCore();
 *
 *     if (max_fps < DB_getFPS())
 *       max_fps = DB_getFPS();
 *   }
 * private:
 *   int max_fps;
 * };
 * 
 * DIGMEBOX_MAIN()
 * {
 *   Game game;
 *   game.construct(1024, 960, 256, 240, HARDWARE_ACCELERATED);
 *   game.start();
 * 
 *   return 0;
 * }
*/

#pragma endregion

// O------------------------------------------------------------------------------O
// | INTERFACE DIGMEBOX FOR STUPID C++ PROGRAMMERS                                |
// O------------------------------------------------------------------------------O
#pragma region digmebox_interface

#define DIGMEBOX_INIT()                                                             \
class Class_for_DB : public DigmeBox                                                \
{                                                                                   \
public:                                                                             \
    Class_for_DB() { NameApp = "New window"; };                                     \
    ~Class_for_DB() {};                                                             \
                                                                                    \
public:                                                                             \
    bool create() override;                                                         \
    bool update() override;                                                         \
    bool destroy() override;

#define DIGMEBOX_CREATE_VARIABLES()                                                 \
private:

#define INIT_END                                                           \
};

#define DIGMEBOX_CREATE(width_window, height_window, width_render, height_render)   \
DIGMEBOX_MAIN()                                                                     \
{                                                                                   \
    Class_for_DB class_DB;                                                          \
    class_DB.construct(width_window, height_window, width_render, height_render, 0);\
    class_DB.start();                                                               \
                                                                                    \
    return 0;                                                                       \
}

#define DIGMEBOX_USER_CREATE()                                                      \
bool Class_for_DB::create() {

#define DIGMEBOX_USER_UPDATE()                                                      \
bool Class_for_DB::update() {

#define DIGMEBOX_USER_DESTROY()                                                     \
bool Class_for_DB::destroy() {

#define SECTION_END                                                        \
  return true;                                                                      \
}

#pragma endregion

// O------------------------------------------------------------------------------O
// | CLASS DIGMEBOX                                                               |
// O------------------------------------------------------------------------------O
#pragma region digmebox

class DigmeBox : public DigmeBox_Core
{
public:
  DigmeBox();
  ~DigmeBox();

  void construct(int32_t width_screen, int32_t height_screen, int32_t width_render, int32_t height_render, uint32_t flag);
  void start();
  
  virtual bool create();
  virtual bool update();
  virtual bool destroy();

  std::string NameApp;
};

#pragma endregion

#endif