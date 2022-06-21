#include <utility>
#include "getDisplay.hxx"
#include "Engine.hxx"

int main()
{
  std::pair<int, int> display{getDisplay()};
  Engine engine{display.first, display.second};
  
  bool success{engine.initialize()};

  if (success)
  {
    engine.run();
  }

  engine.shutdown();
}

