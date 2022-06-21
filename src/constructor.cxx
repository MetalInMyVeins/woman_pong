// Programmed By : Hossain Md. Fahim
#include "Engine.hxx"
#include "f2i.hxx"
#include "scaling.hxx"

Engine::Engine(int width, int height) :
  m_width{width},
  m_height{height},
  m_thickness{f2i(m_width * scale::s_thickness)},
  m_paddleHeight{f2i(m_width * scale::s_paddleHeight)},
  m_paddleSpeed{f2i(m_width * scale::s_paddleSpeed)},
  m_scoreWidth{f2i(m_width * scale::s_scoreWidth)},
  m_scoreHeight{f2i(m_width * scale::s_scoreHeight)},
  m_gameOverPromptWidth{f2i(m_width * scale::s_gameOverPromptWidth)},
  m_winningPromptWidth{f2i(m_width * scale::s_winningPromptWidth)},
  m_leftPaddleControlPromptWidth{f2i(m_width * scale::s_leftPaddleControlPromptWidth)},
  m_rightPaddleControlPromptWidth{m_leftPaddleControlPromptWidth},
  m_exitPromptWidth{m_leftPaddleControlPromptWidth},
  m_mePromptWidth{f2i(m_width * scale::s_mePromptWidth)},
  m_isDead{false},
  m_isGameOver{false},
  m_deathDelay{300},
  m_path{1, -1},
  m_arrBallInitVel{0, 1},
  m_xMin{f2i(m_width * scale::s_xMin)},
  m_xMax{f2i(m_width * scale::s_xMax)},
  m_yMin{f2i(m_width * scale::s_yMin)},
  m_yMax{f2i(m_width * scale::s_yMax)},
  m_xySafe{f2i(m_width * scale::s_xySafe)},
  m_font1{"assets/Roboto-BoldItalic.ttf"},
  m_font2{"assets/Roboto-Bold.ttf"},
  m_gameOverPromptText{"GAME OVER!"},
  m_winningPromptTextLeft{"LEFT PLAYER WON!"},
  m_winningPromptTextRight{"RIGHT PLAYER WON!"},
  m_leftPaddleControlPrompt{"LEFT PADDLE : W S"},
  m_rightPaddleControlPrompt{"RIGHT PADDLE : I J"},
  m_exitPrompt{"PRESS ESC TO EXIT"},
  m_mePrompt{"PROGRAMMED BY : HOSSAIN MD. FAHIM"},
  m_gameOverLimit{5},
  m_paddleIsMovingUp{false},
  m_paddleIsMovingDown{false},
  m_paddleRightIsMovingUp{false},
  m_paddleRightIsMovingDown{false},
  m_initPaddlePosx{static_cast<float>(m_thickness)},
  m_initPaddlePosy{m_height / 2.f - m_paddleHeight / 2.f},
  m_initPaddleRightPosx{static_cast<float>(m_width - 2 * m_thickness)},
  m_initPaddleRightPosy{m_initPaddlePosy},
  m_initBallPosx{m_width / 2.f - m_thickness / 2.f},
  m_initBallPosy{m_height / 2.f - m_thickness / 2.f},
  m_initScoreLeftPosx{m_width / 3.f},
  m_initScoreLeftPosy{m_height / 10.f},
  m_initScoreRightPosx{2 * m_width / 3.f - m_scoreWidth},
  m_initScoreRightPosy{m_initScoreLeftPosy},
  m_initGameOverPromptPosx{m_width / 2.f - m_gameOverPromptWidth / 2.f},
  m_initGameOverPromptPosy{m_height / 4.f},
  m_initWinningPromptPosx{m_width / 2.f - m_winningPromptWidth / 2.f},
  m_initWinningPromptPosy{m_height / 3.f},
  m_initLeftPaddleControlPromptPosx{1},
  m_initLeftPaddleControlPromptPosy{0},
  m_initRightPaddleControlPromptPosx{m_width - m_leftPaddleControlPromptWidth - 1.f},
  m_initRightPaddleControlPromptPosy{0},
  m_initExitPromptPosx{m_width / 2.f - m_exitPromptWidth / 2.f},
  m_initExitPromptPosy{0},
  m_initMePromptPosx{m_width / 2.f - m_mePromptWidth / 2.f},
  m_initMePromptPosy{m_height - m_thickness - 0.f},
  m_isStartPage{true},
  m_womanPong{"WOMAN PONG"},
  m_pressAnyKey{"PRESS ANY KEY TO START GAME"},
  m_imgWoman{"assets/woman.png"},
  m_womanPongWidth{f2i(m_width * scale::s_womanPongWidth)},
  m_womanPongHeight{f2i(m_width * scale::s_womanPongHeight)},
  m_pressAnyKeyWidth{f2i(m_width * scale::s_pressAnyKeyWidth)},
  m_pressAnyKeyHeight{f2i(m_width * scale::s_pressAnyKeyHeight)},
  m_imgWomanWidth{f2i(m_width * scale::s_imgWomanWidth)},
  m_imgWomanHeight{f2i(m_width * scale::s_imgWomanHeight)},
  m_initWomanPongPosx{m_width / 2.f - m_womanPongWidth / 2.f},
  m_initWomanPongPosy{m_height / 2.f - m_womanPongHeight},
  m_initPressAnyKeyPosx{m_width / 2.f - m_pressAnyKeyWidth / 2.f},
  m_initPressAnyKeyPosy{m_height / 2.f},
  m_initImgWomanPosx{m_width / 2.f - m_imgWomanWidth / 2.f},
  m_initImgWomanPosy{m_height - m_imgWomanHeight * 1.f},
  m_isRunning{true}
{
  m_paddlePos.x = m_initPaddlePosx;
  m_paddlePos.y = m_initPaddlePosy;

  m_paddleRightPos.x = m_initPaddleRightPosx;
  m_paddleRightPos.y = m_initPaddleRightPosy;

  m_ballPos.x = m_initBallPosx;
  m_ballPos.y = m_initBallPosy;

  m_ballVel.x = static_cast<float>(this->getRandomValFromRange(m_xMin, m_xMax));
  m_ballVel.y = static_cast<float>(this->getRandomValFromRange(m_yMin, m_yMax));

  m_scoreLeftPos.x = m_initScoreLeftPosx;
  m_scoreLeftPos.y = m_initScoreLeftPosy;

  m_scoreRightPos.x = m_initScoreRightPosx;
  m_scoreRightPos.y = m_initScoreRightPosy;

  m_womanPongPos.x = m_initWomanPongPosx;
  m_womanPongPos.y = m_initWomanPongPosy;

  m_pressAnyKeyPos.x = m_initPressAnyKeyPosx;
  m_pressAnyKeyPos.y = m_initPressAnyKeyPosy;

  m_imgWomanPos.x = m_initImgWomanPosx;
  m_imgWomanPos.y = m_initImgWomanPosy;
}

