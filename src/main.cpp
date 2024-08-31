#include "configuration.hpp"
#include "events.hpp"
#include "input_system.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

int main()
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

  return 0;
}
