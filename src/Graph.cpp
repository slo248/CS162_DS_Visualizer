#include "Graph.h"

Graph::Graph(sf::RenderWindow *window, sf::CircleShape *hCircle, sf::CircleShape *sCircle):
    window(window), hCircle(hCircle), sCircle(sCircle)
{
    clear();
}

void Graph::clear()
{
    curFrame=curStep=0;
    nFrames.clear();
    drawFunc.clear();
}