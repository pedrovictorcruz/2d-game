#include "Player.hpp"
#include "Configuration.hpp"
#include <SFML/System/Vector2.hpp>

Player::Player()
{
  this->setRadius(10);
  this->setPosition(config::window_size.x / 2, config::window_size.y / 2);
  this->setPointCount(30);
}

void Player::update(const InputSystem &input)
{
  if (input.isKeyPressed(sf::Keyboard::W))
  {
    this->movePlayer(0.f, -speed);
  }
  if (input.isKeyPressed(sf::Keyboard::A))
  {
    this->movePlayer(-speed, 0.f);
  }
  if (input.isKeyPressed(sf::Keyboard::S))
  {
    this->movePlayer(0.f, speed);
  }
  if (input.isKeyPressed(sf::Keyboard::D))
  {
    this->movePlayer(speed, 0.f);
  }
}

void Player::movePlayer(float deltaX, float deltaY)
{
  sf::Vector2f newPosition = this->getPosition() + sf::Vector2f(deltaX, deltaY);

  // Window size collision
  if (newPosition.x - this->getRadius() > 0 &&
      newPosition.x + this->getRadius() < config::window_size.x &&
      newPosition.y - this->getRadius() > 0 &&
      newPosition.y + this->getRadius() < config::window_size.y)
  {
    this->move(deltaX, deltaY);
  }
}
