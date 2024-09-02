#include "Events.hpp"
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

void processEvents(sf::Window &window)
{
  sf::Event event;

  while (window.pollEvent(event))
  {
    if (event.type == sf::Event::Closed)
    {
      window.close();
    }
    else if (event.type == event.KeyPressed)
    {
      if (event.key.code == sf::Keyboard::Escape)
      {
        window.close();
      }
    }
  }
}
