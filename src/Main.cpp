#include "Game.hpp"
#include "Logger.hpp"

int main()
{
  Logger::info("Game started");

  Game::run();

  return 0;
}
