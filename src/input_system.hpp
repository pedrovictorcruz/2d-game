#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <unordered_map>

class InputSystem
{
public:
  InputSystem();

  void update();

  bool isKeyPressed(sf::Keyboard::Key key) const;

  bool isMousePressed(sf::Mouse::Button button) const;

  sf::Vector2i getMousePosition() const;

private:
  std::unordered_map<sf::Keyboard::Key, bool> keys;

  std::unordered_map<sf::Mouse::Button, bool> buttons;
};
