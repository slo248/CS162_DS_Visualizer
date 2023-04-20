#ifndef GRAPH_CONTROL_H
#define GRAPH_CONTROL_H

#include "Global.h"
#include "Button.h"

class Graph_Control:
    public sf::Transformable,
    public sf::Drawable,
    public sf::NonCopyable
{
public:
    Graph_Control(sf::Font* font);
    ~Graph_Control();

    void handleEvent(sf::Event& event, sf::RenderWindow* window);
    void handleRealTimeInput(sf::RenderWindow* window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::Font*       mFont;

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