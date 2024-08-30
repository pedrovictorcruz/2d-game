#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/System/Lock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cstdio>

class Player : public sf::RectangleShape
{
public:
  Player()
  {
    this->setSize(sf::Vector2f(20, 10));
    this->setOutlineColor(sf::Color::White);
    this->setOutlineThickness(5);
    this->setPosition(10, 10);
  };

  void update(sf::Event &event)
  {
    if (event.type == sf::Event::KeyPressed)
    {
      sf::Keyboard::Key key = event.key.code;

      if (key == sf::Keyboard::Up)
      {
        move(getOffsetBySpeed(sf::Vector2f(0.f, -0.5f)));
      }
      else if (key == sf::Keyboard::Down)
      {
        move(getOffsetBySpeed(sf::Vector2f(0.f, 0.5f)));
      }
      else if (key == sf::Keyboard::Left)
      {
        move(getOffsetBySpeed(sf::Vector2f(-0.5f, 0.f)));
      }
      else if (key == sf::Keyboard::Right)
      {
        move(getOffsetBySpeed(sf::Vector2f(0.5f, 0.f)));
      }
    }
  }

private:
  sf::Vector2f getOffsetBySpeed(sf::Vector2f offset)
  {
    offset.y = (offset.y * speed) / 100;
    offset.x = (offset.x * speed) / 100;
    return offset;
  }

  int speed = 50;
};
