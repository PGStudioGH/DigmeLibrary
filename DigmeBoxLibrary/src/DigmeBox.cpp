#include <DigmeBox.h>

DigmeBox::DigmeBox()
{

}
DigmeBox::~DigmeBox()
{

}

void DigmeBox::construct(int32_t width_screen, int32_t height_screen, int32_t width_render, int32_t height_render, uint32_t flag)
{
  DB_createWindow(NameApp.c_str(), width_screen, height_screen, width_render, height_render, flag);
}
void DigmeBox::start()
{
  create();
  DB_enableDigmeBoxCore();
  while (DB_isWorkingDigmeBoxCore())
  {
    update();
    DB_updateDigmeBoxCore();
  }
  destroy();
}

bool DigmeBox::create()
{ return false; }
bool DigmeBox::update()
{ return false; }
bool DigmeBox::destroy()
{ return false; }