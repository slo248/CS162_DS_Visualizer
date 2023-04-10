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

void Graph::addStep(int frames)
{
    nFrames.push_back(frames);
    drawFunc.push_back(std::vector<functor>());
}
