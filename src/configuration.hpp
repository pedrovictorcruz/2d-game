#pragma once

#include <SFML/System/Vector2.hpp>
#include <cstdint>
namespace config
{

sf::Vector2u const window_size = {2560, 1440};

sf::Vector2f const window_size_f = static_cast<sf::Vector2f>(window_size);

uint32_t const max_framerate = 170;

float const dt = 1.0f / static_cast<float>(max_framerate);

} // namespace config
