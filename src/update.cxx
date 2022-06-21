#include "Engine.hxx"

void Engine::update()
{
  while (!SDL_TICKS_PASSED(SDL_GetTicks(), m_ticksCount + 16));

  float deltaTime{(SDL_GetTicks() - m_ticksCount) / 1000.0f};
  m_ticksCount = SDL_GetTicks();
  if (deltaTime > 0.05f) deltaTime = 0.05f;

  this->movePaddle(deltaTime);
  this->movePaddleRight(deltaTime);
  this->moveBall(deltaTime);
  
  if (m_isDead){ this->handleScore(); m_isDead = false; }
  if (m_scoreLeft == m_gameOverLimit or m_scoreRight == m_gameOverLimit)
  {
    this->handleGameOver();
    m_scoreLeftTexture = this->loadText(std::to_string(m_scoreLeft), m_font2);
    m_scoreRightTexture = this->loadText(std::to_string(m_scoreRight), m_font2);
    m_scoreLeft = 0;
    m_scoreRight = 0;
  }
}

