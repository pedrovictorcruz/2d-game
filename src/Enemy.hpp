#pragma once

#include "Player.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <vector>

class EnemySystem : public sf::Drawable, sf::Transformable {
public:
  EnemySystem(unsigned int count);

  void update(const Player &player, sf::Time &deltatime);

private:
  struct Enemy {
    sf::Vector2f velocity;
    sf::Time lifetime;
  };

private:
  float m_initial_speed = 4.0f;
  sf::VertexArray m_vertices;
  std::vector<Enemy> m_enimies;
};
