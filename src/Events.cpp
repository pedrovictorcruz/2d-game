#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

void processEvents(sf::RenderWindow &window)
{
  sf::Event event;
  sf::View view = window.getDefaultView();

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
    else if (event.type == sf::Event::Resized)
    {
      // update the view to the new size of te window
      sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
      window.setView(sf::View(visibleArea));
    }
  }
}
