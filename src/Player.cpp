#include "Player.hpp"
#include "Configuration.hpp"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

Player::Player()
{
  this->setRadius(10);
  this->setPosition(config::window_size.x / 2, config::window_size.y / 2);
  this->setPointCount(30);
}

void Player::update(const InputSystem &input)
{
  if (input.isKeyPressed(sf::Keyboard::Space))
  {
    this->fire();
  }

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

void Player::fire() {}

void Player::movePlayer(float deltaX, float deltaY)
{
  sf::Vector2f newPosition = this->getPosition() + sf::Vector2f(deltaX, deltaY);

  // Window size collision
  if (newPosition.x > 0 &&
      newPosition.x + this->getRadius() * 2 < config::window_size.x &&
      newPosition.y > 0 &&
      newPosition.y + this->getRadius() * 2 < config::window_size.y)
  {
    this->move(deltaX, deltaY);
  }
}
