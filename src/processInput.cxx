#include "Engine.hxx"

void Engine::processInput()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
        m_isRunning = false;
        break;

      case SDL_KEYDOWN:
        if (event.key.keysym.sym == 27){ m_isRunning = false; break; }
        if (m_isStartPage){ m_isStartPage = false; break; }
        handlePlayerInput(event.key.keysym.sym, true);
        break;

      case SDL_KEYUP:
        handlePlayerInput(event.key.keysym.sym, false);
        break;
    }
  }
}

