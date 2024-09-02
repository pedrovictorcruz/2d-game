#include "input_system.hpp"

InputSystem::InputSystem()
{
  keys[sf::Keyboard::A] = false;
  keys[sf::Keyboard::D] = false;
  keys[sf::Keyboard::W] = false;
  keys[sf::Keyboard::S] = false;
}

void InputSystem::update()
{
  keys[sf::Keyboard::W] = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
  keys[sf::Keyboard::A] = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
  keys[sf::Keyboard::S] = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
  keys[sf::Keyboard::D] = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
};

bool InputSystem::isKeyPressed(sf::Keyboard::Key key) const
{
  auto it = keys.find(key);
  if (it != keys.end())
  {
    return it->second;
  }
  return false;
}
