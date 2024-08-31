#pragma once

#include <SFML/Window/Keyboard.hpp>
#include <unordered_map>

class InputSystem
{
public:
  InputSystem();

  void update();

  bool isKeyPressed(sf::Keyboard::Key key) const;

private:
  std::unordered_map<sf::Keyboard::Key, bool> keys;
};
