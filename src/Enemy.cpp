#include "Enemy.hpp"

#include <cmath>

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

EnemySystem::EnemySystem(unsigned int count)
    : m_enimies(count), m_vertices(sf::Points, count) {}

void EnemySystem::update(const Player &player, sf::Time &deltaTime) {

  for (std::size_t i = 0; i < m_enimies.size(); ++i) {

    sf::Vector2f direction = player.getPosition() - this->getPosition();

    const float lenght =
        sqrt(direction.x * direction.x + direction.y * direction.y);

    sf::Vector2f newPosition =
        direction * (m_initial_speed * 100) * deltaTime.asSeconds();

    this->move(newPosition / lenght);
  }
}
