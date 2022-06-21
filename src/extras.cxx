// Programmed By : Hossain Md. Fahim
#include "Engine.hxx"
#include <random>

SDL_Texture* Engine::loadText(std::string text, std::string fontname, std::initializer_list<uint8_t> color)
{
  if (TTF_Init() == -1)
  {
    SDL_Log("%s", SDL_GetError());
    return nullptr;
  }
  TTF_Font *font = TTF_OpenFont(fontname.c_str(), 256);
  if (font == nullptr)
  {
    SDL_Log("%s", SDL_GetError());
    return nullptr;
  }
  
  SDL_Color arrColor = {*(color.begin() + 0), *(color.begin() + 1), *(color.begin() + 2), *(color.begin() + 3)};
  SDL_Surface *surface = TTF_RenderText_Solid(font, text.c_str(), arrColor);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(m_renderer, surface);
  SDL_FreeSurface(surface);
  if (texture == nullptr)
  {
    SDL_Log("%s", SDL_GetError());
    return nullptr;
  }
  return texture;
}

int Engine::getRandomValFromRange(int min, int max)
{
  std::random_device dev;
  std::mt19937 rng{dev()};
  std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);
  return dist(rng);
}

void Engine::debugPerSec(float deltaTime)
{
  ++m_frameCount; m_frameTimes += deltaTime;
  if (m_frameTimes > 1.f)
  {
    m_frameTimes = 0.f;
    /* Debug code */
    m_frameCount = 0;
  }
}

