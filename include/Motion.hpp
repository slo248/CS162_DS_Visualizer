#pragma once

#include <SFML/Graphics.hpp>

namespace Motion {
    const sf::Time      CREATE_TIME=sf::seconds(0.36f);
    const sf::Time      INSERT_TIME=sf::seconds(0.7f);

    float linear(float time);
    float Bezier(float time);
    float parametric(float time);
}