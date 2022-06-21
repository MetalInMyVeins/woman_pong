// Programmed By : Hossain Md. Fahim
#ifndef ENGINE_HXX
#define ENGINE_HXX

#include <cstdint>
#include <initializer_list>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

struct Vector2
{
  float x{};
  float y{};
};

class Engine
{
public:
  Engine(int, int);
  bool initialize();
  void run();
  void shutdown();

private:
  SDL_Texture* loadText(std::string, std::string, std::initializer_list<uint8_t> color = m_color);
  int getRandomValFromRange(int, int);
  void debugPerSec(float);

private:
  void processInput();
  void update();
  void render();
  void postRender();

private:
  void handleStartPage();
  void handlePlayerInput(int, bool);
  void handleScore();
  void handleGameOver();

private:
  void movePaddle(float);
  void movePaddleRight(float);
  void moveBall(float);

private:
  const int m_width{};
  const int m_height{};
  const int m_thickness{};
  const int m_paddleHeight{};
  const int m_paddleSpeed{};
  const int m_scoreWidth{};
  const int m_scoreHeight{};
  const int m_gameOverPromptWidth{};
  const int m_winningPromptWidth{};
  const int m_leftPaddleControlPromptWidth{};
  const int m_rightPaddleControlPromptWidth{};
  const int m_exitPromptWidth{};
  const int m_mePromptWidth{};
  static constexpr std::initializer_list<uint8_t> m_color{0, 50, 50, 255};

private:
  bool m_isDead{};
  bool m_isGameOver{};
  const int m_deathDelay{};
  const int m_path[2]{};
  const int m_arrBallInitVel[2]{};
  const int m_xMin{};
  const int m_xMax{};
  const int m_yMin{};
  const int m_yMax{};
  const int m_xySafe{};

private:
  std::string m_font1{};
  std::string m_font2{};
  std::string m_gameOverPromptText{};
  std::string m_winningPromptTextLeft{};
  std::string m_winningPromptTextRight{};
  std::string m_leftPaddleControlPrompt{};
  std::string m_rightPaddleControlPrompt{};
  std::string m_exitPrompt{};
  std::string m_mePrompt{};

private:
  int m_scoreLeft{};
  int m_scoreRight{};
  const int m_gameOverLimit{};
  int m_totalPaddleMovement{};
  int m_totalPaddleRightMovement{};
  bool m_paddleIsMovingUp{};
  bool m_paddleIsMovingDown{};
  bool m_paddleRightIsMovingUp{};
  bool m_paddleRightIsMovingDown{};
  uint32_t m_ticksCount{};
  int m_frameCount{};
  float m_frameTimes{};

private:
  const float m_initPaddlePosx{};
  const float m_initPaddlePosy{};
  const float m_initPaddleRightPosx{};
  const float m_initPaddleRightPosy{};
  const float m_initBallPosx{};
  const float m_initBallPosy{};
  const float m_initScoreLeftPosx{};
  const float m_initScoreLeftPosy{};
  const float m_initScoreRightPosx{};
  const float m_initScoreRightPosy{};
  const float m_initGameOverPromptPosx{};
  const float m_initGameOverPromptPosy{};
  const float m_initWinningPromptPosx{};
  const float m_initWinningPromptPosy{};
  const float m_initLeftPaddleControlPromptPosx{};
  const float m_initLeftPaddleControlPromptPosy{};
  const float m_initRightPaddleControlPromptPosx{};
  const float m_initRightPaddleControlPromptPosy{};
  const float m_initExitPromptPosx{};
  const float m_initExitPromptPosy{};
  const float m_initMePromptPosx{};
  const float m_initMePromptPosy{};

private:
  bool m_isStartPage{};
  std::string m_womanPong{};
  std::string m_pressAnyKey{};
  std::string m_imgWoman{};

private:
  const int m_womanPongWidth{};
  const int m_womanPongHeight{};
  const int m_pressAnyKeyWidth{};
  const int m_pressAnyKeyHeight{};
  const int m_imgWomanWidth{};
  const int m_imgWomanHeight{};
  const float m_initWomanPongPosx{};
  const float m_initWomanPongPosy{};
  const float m_initPressAnyKeyPosx{};
  const float m_initPressAnyKeyPosy{};
  const float m_initImgWomanPosx{};
  const float m_initImgWomanPosy{};

private:
  bool m_isRunning{};
  SDL_Window* m_window{nullptr};
  SDL_Renderer* m_renderer{nullptr};

private:
  Vector2 m_paddlePos{};
  Vector2 m_paddleRightPos{};
  Vector2 m_ballPos{};
  Vector2 m_ballVel{};
  Vector2 m_scoreLeftPos{};
  Vector2 m_scoreRightPos{};
  Vector2 m_womanPongPos{};
  Vector2 m_pressAnyKeyPos{};
  Vector2 m_imgWomanPos{};

private:
  SDL_Texture* m_scoreLeftTexture{nullptr};
  SDL_Texture* m_scoreRightTexture{nullptr};
  SDL_Texture* m_gameOverPromptTexture{nullptr};
  SDL_Texture* m_winningPromptTexture{nullptr};
  SDL_Texture* m_leftPaddleControlPromptTexture{nullptr};
  SDL_Texture* m_rightPaddleControlPromptTexture{nullptr};
  SDL_Texture* m_exitPromptTexture{nullptr};
  SDL_Texture* m_mePromptTexture{nullptr};
  SDL_Texture* m_womanPongTexture{nullptr};
  SDL_Texture* m_pressAnyKeyTexture{nullptr};
  SDL_Texture* m_imgWomanTexture{nullptr};
};

#endif

