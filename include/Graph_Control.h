#ifndef GRAPH_CONTROL_H
#define GRAPH_CONTROL_H

#include "Global.h"
#include "Button.h"
#include "Command.h"
#include <queue>

class Graph_Control:
    public sf::Transformable,
    public sf::Drawable,
    public sf::NonCopyable
{
public:
    Graph_Control(sf::Font* font);
    ~Graph_Control();

    void handleEvent(sf::Event& event, sf::RenderWindow* window, std::queue<Command>& commandQueue);
    void handleRealTimeInput(sf::RenderWindow* window);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::Font*       mFont;

    sf::Texture     bgTexture;
    sf::Texture     playBtnTexture;
    sf::Texture     pauseBtnTexture;
    sf::Texture     nextBtnTexture;
    sf::Texture     prevBtnTexture;
    sf::Texture     beginBtnTexture;
    sf::Texture     endBtnTexture;

    sf::Sprite      bgSprite;
    Button*         playBtn;
    Button*         pauseBtn;
    Button*         nextBtn;
    Button*         prevBtn;
    Button*         beginBtn;
    Button*         endBtn;

    bool            isPause;
};

#endif // GRAPH_CONTROL_H