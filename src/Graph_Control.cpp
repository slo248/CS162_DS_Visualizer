#include "Graph_Control.h"

Graph_Control::Graph_Control(sf::Font* font)
{
    assert(bgTexture.loadFromFile("media/image/bgGraphControl.png"));
    assert(playBtnTexture.loadFromFile("media/image/playBtn.png"));
    assert(pauseBtnTexture.loadFromFile("media/image/pauseBtn.png"));
    assert(nextBtnTexture.loadFromFile("media/image/nextBtn.png"));
    assert(prevBtnTexture.loadFromFile("media/image/prevBtn.png"));

    bgSprite.setTexture(bgTexture);
    playBtn = new Button(
        font,
        &playBtnTexture,
        "",
        sf::Vector2f(
            bgSprite.getPosition().x + 10,
            bgSprite.getPosition().y + 10
        )
    );
}

Graph_Control::~Graph_Control()
{
    if(playBtn) delete playBtn;
    if(pauseBtn) delete pauseBtn;
    if(nextBtn) delete nextBtn;
    if(prevBtn) delete prevBtn;
}

void Graph_Control::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(bgSprite);
    if(playBtn) target.draw(*playBtn);
}
