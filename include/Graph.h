#include "HNeed.h"

class Graph
{
public:
    Graph(sf::RenderWindow* window, sf::CircleShape* hCircle, sf::CircleShape* sCircle);

    void clear();
    void addStep(int frames);

private:
    sf::RenderWindow* window;
    sf::CircleShape* hCircle;
    sf::CircleShape* sCircle;

    int curFrame, curStep;
    std::vector<int> nFrames;
    std::vector<std::vector<functor>> drawFunc;
};