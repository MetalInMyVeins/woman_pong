#include "Engine.hxx"

bool Engine::initialize()
{
  int sdlresult{SDL_Init(SDL_INIT_VIDEO)};
  if (sdlresult != 0)
  {
    SDL_Log("%s", SDL_GetError());
    return false;
  }

  m_window = SDL_CreateWindow("Woman Pong", 0, 0, m_width, m_height, SDL_WINDOW_FULLSCREEN);
  if (!m_window)
  {
    SDL_Log("%s", SDL_GetError());
    return false;
  }

  m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!m_renderer)
  {
    SDL_Log("%s", SDL_GetError());
    return false;
  }

  m_scoreLeftTexture = this->loadText(std::to_string(m_scoreLeft), m_font2);
  m_scoreRightTexture = this->loadText(std::to_string(m_scoreRight), m_font2);

  m_leftPaddleControlPromptTexture = this->loadText(m_leftPaddleControlPrompt, m_font1, {0, 0, 0, 255});
  m_rightPaddleControlPromptTexture = this->loadText(m_rightPaddleControlPrompt, m_font1, {0, 0, 0, 255});
  m_exitPromptTexture = this->loadText(m_exitPrompt, m_font1, {0, 0, 0, 255});
  m_mePromptTexture = this->loadText(m_mePrompt, m_font1, {0, 0, 0, 255});

  m_womanPongTexture = this->loadText(m_womanPong, m_font1);
  m_pressAnyKeyTexture = this->loadText(m_pressAnyKey, m_font1);

  m_imgWomanTexture = IMG_LoadTexture(m_renderer, m_imgWoman.c_str());

  return true;
}

void Engine::run()
{
  while (m_isRunning)
  {
    this->processInput();
    if (m_isStartPage){ this->handleStartPage(); }
    if (!m_isStartPage)
    {
      this->update();
      this->render();
      this->postRender();
    }
  }
}

void Engine::shutdown()
{
  SDL_DestroyWindow(m_window);
  SDL_DestroyRenderer(m_renderer);
  SDL_Quit();
}

