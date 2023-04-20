#ifndef GRAPH_CONTROL_H
#define GRAPH_CONTROL_H

#include "Global.h"
#include "Button.h"

class Graph_Control
{
public:
    Graph_Control(sf::Font* font);

private:
    sf::Texture     bgTexture;
    sf::Texture     playBtnTexture;
    sf::Texture     pauseBtnTexture;
    sf::Texture     nextBtnTexture;
    sf::Texture     prevBtnTexture;

    sf::Sprite      bgSprite;
    Button*         playBtn;
    Button*         pauseBtn;
    Button*         nextBtn;
    Button*         prevBtn;
};

#endif // GRAPH_CONTROL_H