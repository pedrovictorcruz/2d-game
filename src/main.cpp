#include "./player.cpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

int main()
{
  sf::ContextSettings settings;
  // create the window
  sf::RenderWindow window(sf::VideoMode(800, 600), "Player");

  Player player;

  // run the main loop
  while (window.isOpen())
  {
    // handle events
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    player.update(event);

    // draw
    window.clear();

    window.draw(player);

    window.display();
  }

  return 0;
}
