#ifndef FIGURE_H
#define FIGURE_H

#include <SFML/Graphics.hpp>

struct Figure
{
    sf::CircleShape* hCircle; // hollow circle
    sf::CircleShape* sCircle; // solid circle
};

#endif // FIGURE_H