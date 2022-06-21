// Programmed By : Hossain Md. Fahim
#include "Engine.hxx"

void Engine::handlePlayerInput(int keycode, bool isPressed)
{
  if (keycode == int('w')) m_paddleIsMovingUp = isPressed;
  else if (keycode == int('s')) m_paddleIsMovingDown = isPressed;
  else if (keycode == int('i')) m_paddleRightIsMovingUp = isPressed;
  else if (keycode == int('j')) m_paddleRightIsMovingDown = isPressed;
}

void Engine::handleStartPage()
{
  SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
  SDL_RenderClear(m_renderer);

  SDL_Rect womanPongPrompt{static_cast<int>(m_womanPongPos.x), static_cast<int>(m_womanPongPos.y), m_womanPongWidth, m_womanPongHeight};
  SDL_Rect pressAnyKeyPrompt{static_cast<int>(m_pressAnyKeyPos.x), static_cast<int>(m_pressAnyKeyPos.y), m_pressAnyKeyWidth, m_pressAnyKeyHeight};
  SDL_Rect imgWoman{static_cast<int>(m_imgWomanPos.x), static_cast<int>(m_imgWomanPos.y), m_imgWomanWidth, m_imgWomanHeight};

  SDL_RenderCopy(m_renderer, m_womanPongTexture, nullptr, &womanPongPrompt);
  SDL_RenderCopy(m_renderer, m_pressAnyKeyTexture, nullptr, &pressAnyKeyPrompt);
  SDL_RenderCopy(m_renderer, m_imgWomanTexture, nullptr, &imgWoman);
 
  SDL_RenderPresent(m_renderer);
}

void Engine::handleScore()
{
  m_scoreLeftTexture = this->loadText(std::to_string(m_scoreLeft), m_font2);
  m_scoreRightTexture = this->loadText(std::to_string(m_scoreRight), m_font2);
}

void Engine::handleGameOver()
{
  m_gameOverPromptTexture = this->loadText(m_gameOverPromptText, m_font1);
  if (m_scoreLeft > m_scoreRight){ m_winningPromptTexture = this->loadText(m_winningPromptTextLeft, m_font1); }
  if (m_scoreRight > m_scoreLeft){ m_winningPromptTexture = this->loadText(m_winningPromptTextRight, m_font1); }
  m_isGameOver = true;
}

void Engine::movePaddle(float deltaTime)
{
  if (m_paddleIsMovingUp) m_totalPaddleMovement -= m_paddleSpeed;
  if (m_paddleIsMovingDown) m_totalPaddleMovement += m_paddleSpeed;
  m_paddlePos.y += m_totalPaddleMovement * deltaTime;
  if (m_paddlePos.y < m_thickness) m_paddlePos.y = m_thickness;
  if (m_paddlePos.y + m_paddleHeight > m_height - m_thickness) m_paddlePos.y = m_height - m_thickness - m_paddleHeight;
  m_totalPaddleMovement = 0;
}

void Engine::movePaddleRight(float deltaTime)
{
  if (m_paddleRightIsMovingUp) m_totalPaddleRightMovement -= m_paddleSpeed;
  if (m_paddleRightIsMovingDown) m_totalPaddleRightMovement += m_paddleSpeed;
  m_paddleRightPos.y += m_totalPaddleRightMovement * deltaTime;
  if (m_paddleRightPos.y < m_thickness) m_paddleRightPos.y = m_thickness;
  if (m_paddleRightPos.y + m_paddleHeight > m_height - m_thickness) m_paddleRightPos.y = m_height - m_thickness - m_paddleHeight;
  m_totalPaddleRightMovement = 0;
}

void Engine::moveBall(float deltaTime)
{
  m_ballPos.x += m_ballVel.x * deltaTime;
  m_ballPos.y += m_ballVel.y * deltaTime;

  // Wall down
  if (m_ballPos.y > m_height - 2.f * m_thickness)
  {
    m_ballPos.y = m_height - 2.f * m_thickness;
    m_ballVel.x = static_cast<float>(this->getRandomValFromRange(m_xMin, m_xMax));
    m_ballVel.y = static_cast<float>(this->getRandomValFromRange(m_yMin, -m_xySafe));
    m_ballVel.y *= m_path[this->getRandomValFromRange(0, 1)];
  }

  // Wall up
  if (m_ballPos.y < m_thickness)
  {
    m_ballPos.y = m_thickness;
    m_ballVel.x = static_cast<float>(this->getRandomValFromRange(m_xMin, m_xMax));
    m_ballVel.y = static_cast<float>(this->getRandomValFromRange(m_xySafe, m_yMax));
    m_ballVel.y *= m_path[this->getRandomValFromRange(0, 1)];
  }

  // Death wall left
  if (m_ballPos.x < 0)
  {
    m_ballPos.x = m_initBallPosx;
    m_ballPos.y = m_initBallPosy;
    m_paddlePos.x = m_initPaddlePosx;
    m_paddlePos.y = m_initPaddlePosy;
    m_paddleRightPos.x = m_initPaddleRightPosx;
    m_paddleRightPos.y = m_initPaddleRightPosy;
    SDL_Delay(m_deathDelay);
    
    m_ballVel.x = static_cast<float>(this->getRandomValFromRange(m_xMin, m_xMax));
    m_ballVel.y = static_cast<float>(this->getRandomValFromRange(m_yMin, m_yMax));

    m_isDead = true;
    ++m_scoreRight;
  }

  // Death wall right
  if (m_ballPos.x > m_width - m_thickness)
  {
    m_ballPos.x = m_initBallPosx;
    m_ballPos.y = m_initBallPosy;
    m_paddlePos.x = m_initPaddlePosx;
    m_paddlePos.y = m_initPaddlePosy;
    m_paddleRightPos.x = m_initPaddleRightPosx;
    m_paddleRightPos.y = m_initPaddleRightPosy;
    SDL_Delay(m_deathDelay);
    m_ballVel.x = static_cast<float>(this->getRandomValFromRange(m_xMin, m_xMax));
    m_ballVel.y = static_cast<float>(this->getRandomValFromRange(m_yMin, m_yMax));

    m_isDead = true;
    ++m_scoreLeft;
  }

  // Paddle left
  if (m_ballPos.x < 2.f * m_thickness and m_ballPos.y > m_paddlePos.y - m_thickness and m_ballPos.y < (m_paddlePos.y + m_paddleHeight))
  {
    m_ballPos.x = 2.f * m_thickness;
    m_ballVel.x = static_cast<float>(this->getRandomValFromRange(m_xySafe, m_xMax));
    m_ballVel.y = static_cast<float>(this->getRandomValFromRange(m_yMin, m_yMax));
    m_ballVel.y *= m_path[this->getRandomValFromRange(0, 1)];
  }

  // Paddle right
  if (m_ballPos.x > (m_width - 3.f * m_thickness) and m_ballPos.y > (m_paddleRightPos.y - m_thickness) and m_ballPos.y < (m_paddleRightPos.y + m_paddleHeight))
  {
    m_ballPos.x = m_width - 3.f * m_thickness;
    m_ballVel.x = static_cast<float>(this->getRandomValFromRange(m_xMin, -m_xySafe));
    m_ballVel.y = static_cast<float>(this->getRandomValFromRange(m_yMin, m_yMax));
    m_ballVel.y *= m_path[this->getRandomValFromRange(0, 1)];
  }
}

