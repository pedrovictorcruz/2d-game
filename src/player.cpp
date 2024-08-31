#include "player.hpp"
#include <SFML/System/Vector2.hpp>

Player::Player()
{
  this->setRadius(10);
  this->setPosition(10, 10);
  this->setPointCount(30);
}

void Player::update(const InputSystem &input)
{
  if (input.isKeyPressed(sf::Keyboard::W))
  {
    this->move(0.f, -speed);
  }
  if (input.isKeyPressed(sf::Keyboard::A))
  {
    this->move(-speed, 0.f);
  }
  if (input.isKeyPressed(sf::Keyboard::S))
  {
    this->move(0.f, speed);
  }
  if (input.isKeyPressed(sf::Keyboard::D))
  {
    this->move(speed, 0.f);
  }
}
