#include "Engine.hxx"

void Engine::render()
{
  SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
  SDL_RenderClear(m_renderer);

  SDL_Rect scoreLeft{static_cast<int>(m_initScoreLeftPosx), static_cast<int>(m_initScoreLeftPosy), m_scoreWidth, m_scoreHeight};
  SDL_Rect scoreRight{static_cast<int>(m_initScoreRightPosx), static_cast<int>(m_initScoreRightPosy), m_scoreWidth, m_scoreHeight};
  SDL_Rect gameOverPrompt{static_cast<int>(m_initGameOverPromptPosx), static_cast<int>(m_initGameOverPromptPosy), m_gameOverPromptWidth, m_scoreHeight};
  SDL_Rect winningPrompt{static_cast<int>(m_initWinningPromptPosx), static_cast<int>(m_initWinningPromptPosy), m_winningPromptWidth, m_scoreHeight};
  SDL_RenderCopy(m_renderer, m_scoreLeftTexture, nullptr, &scoreLeft);
  SDL_RenderCopy(m_renderer, m_scoreRightTexture, nullptr, &scoreRight);
  SDL_RenderCopy(m_renderer, m_gameOverPromptTexture, nullptr, &gameOverPrompt);
  SDL_RenderCopy(m_renderer, m_winningPromptTexture, nullptr, &winningPrompt);
  
  SDL_Rect wallUp{0, 0, m_width, m_thickness};
  SDL_Rect wallRight{m_width - 1, 0, 1, m_height};
  SDL_Rect wallDown{0, m_height - m_thickness, m_width, m_thickness};
  SDL_Rect wallLeft{0, 0, 1, m_height};
  SDL_SetRenderDrawColor(m_renderer, 0, 128, 128, 255);
  SDL_RenderFillRect(m_renderer, &wallUp);
  SDL_RenderFillRect(m_renderer, &wallDown);
  SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
  SDL_RenderFillRect(m_renderer, &wallLeft);
  SDL_RenderFillRect(m_renderer, &wallRight);

  SDL_Rect leftPaddleControlPrompt{static_cast<int>(m_initLeftPaddleControlPromptPosx), static_cast<int>(m_initLeftPaddleControlPromptPosy), m_leftPaddleControlPromptWidth, m_thickness};
  SDL_Rect rightPaddleControlPrompt{static_cast<int>(m_initRightPaddleControlPromptPosx), static_cast<int>(m_initRightPaddleControlPromptPosy), m_rightPaddleControlPromptWidth, m_thickness};
  SDL_Rect exitPrompt{static_cast<int>(m_initExitPromptPosx), static_cast<int>(m_initExitPromptPosy), m_exitPromptWidth, m_thickness};
  SDL_Rect mePrompt{static_cast<int>(m_initMePromptPosx), static_cast<int>(m_initMePromptPosy), m_mePromptWidth, m_thickness};

  SDL_RenderCopy(m_renderer, m_leftPaddleControlPromptTexture, nullptr, &leftPaddleControlPrompt);
  SDL_RenderCopy(m_renderer, m_rightPaddleControlPromptTexture, nullptr, &rightPaddleControlPrompt);
  SDL_RenderCopy(m_renderer, m_exitPromptTexture, nullptr, &exitPrompt);
  SDL_RenderCopy(m_renderer, m_mePromptTexture, nullptr, &mePrompt);
  
  SDL_Rect ball{static_cast<int>(m_ballPos.x), static_cast<int>(m_ballPos.y), m_thickness, m_thickness};
  SDL_Rect paddle{static_cast<int>(m_paddlePos.x), static_cast<int>(m_paddlePos.y), m_thickness, m_paddleHeight};
  SDL_Rect paddleRight{static_cast<int>(m_paddleRightPos.x), static_cast<int>(m_paddleRightPos.y), m_thickness, m_paddleHeight};

  SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
  SDL_RenderFillRect(m_renderer, &ball);
  SDL_SetRenderDrawColor(m_renderer, 0, 128, 128, 255);
  SDL_RenderFillRect(m_renderer, &paddle);
  SDL_RenderFillRect(m_renderer, &paddleRight);

  SDL_RenderPresent(m_renderer);
}

void Engine::postRender()
{
  if (m_isGameOver)
  {
    SDL_Delay(2000);
    m_scoreLeftTexture = this->loadText(std::to_string(m_scoreLeft), m_font2);
    m_scoreRightTexture = this->loadText(std::to_string(m_scoreRight), m_font2);
    m_isGameOver = false;
    m_gameOverPromptTexture = this->loadText(" ", m_font1);
    m_winningPromptTexture = this->loadText(" ", m_font1);
  }
}

