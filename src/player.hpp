#pragma once

#include "input_system.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

class Player : public sf::CircleShape
{
public:
  Player();

  void update(const InputSystem &input);

private:
  bool is_moving = false;
  float speed = 5.0f;
};
