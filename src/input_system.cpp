#include "input_system.hpp"
#include <SFML/System/Vector3.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>

InputSystem::InputSystem()
{
  keys[sf::Keyboard::A] = false;
  keys[sf::Keyboard::D] = false;
  keys[sf::Keyboard::W] = false;
  keys[sf::Keyboard::S] = false;
  keys[sf::Keyboard::Space] = false;

  buttons[sf::Mouse::Left] = false;
  buttons[sf::Mouse::Right] = false;
  buttons[sf::Mouse::Middle] = false;
}

void InputSystem::update()
{
  keys[sf::Keyboard::W] = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
  keys[sf::Keyboard::A] = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
  keys[sf::Keyboard::S] = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
  keys[sf::Keyboard::D] = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
  keys[sf::Keyboard::Space] = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

  buttons[sf::Mouse::Left] = sf::Mouse::isButtonPressed(sf::Mouse::Left);
  buttons[sf::Mouse::Right] = sf::Mouse::isButtonPressed(sf::Mouse::Right);
  buttons[sf::Mouse::Middle] = sf::Mouse::isButtonPressed(sf::Mouse::Middle);
};

bool InputSystem::isMousePressed(sf::Mouse::Button button) const
{
  auto it = buttons.find(button);
  if (it != buttons.end())
  {
    return it->second;
  }

  return false;
}

bool InputSystem::isKeyPressed(sf::Keyboard::Key key) const
{
  auto it = keys.find(key);
  if (it != keys.end())
  {
    return it->second;
  }
  return false;
}
