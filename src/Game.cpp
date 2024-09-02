#include "Game.hpp"
#include "Configuration.hpp"
#include "Events.hpp"
#include "Player.hpp"
#include "input_system.hpp"
#include <SFML/Graphics/RenderWindow.hpp>

void Game::run()
{
  auto window = sf::RenderWindow{{config::window_size.x, config::window_size.y},
                                 "2d-game"};

  window.setFramerateLimit(config::max_framerate);

  InputSystem input;

  Player player;

  while (window.isOpen())
  {
    processEvents(window);

    window.clear();

    input.update();

    player.update(input);

    // draw
    window.draw(player);

    window.display();
  }
}
