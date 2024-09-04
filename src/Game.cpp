#include "Game.hpp"
#include "Configuration.hpp"
#include "Events.hpp"
#include "Player.hpp"
#include "input_system.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/WindowStyle.hpp>

void Game::run() {
  sf::Clock clock;

  sf::RenderWindow window(
      sf::VideoMode(config::window_size.x, config::window_size.y), "2d-Game",
      sf::Style::None);

  window.setFramerateLimit(config::max_framerate);

  InputSystem input;

  Player player;

  while (window.isOpen()) {
    sf::Time deltatime = clock.restart();

    processEvents(window);

    window.clear();

    input.update();

    player.update(input);

    // draw
    window.draw(player);

    window.display();
  }
}
