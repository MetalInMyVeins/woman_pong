// Programmed By : Hossain Md. Fahim
#include <utility>
#include <X11/Xlib.h>

std::pair<int, int> getDisplay()
{
  Display* display{XOpenDisplay(nullptr)};
  Screen* screen{DefaultScreenOfDisplay(display)};
  std::pair<int, int> screenSize{screen->width, screen->height};
  return screenSize;
}

