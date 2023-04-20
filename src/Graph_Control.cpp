#include "Graph_Control.h"

Graph_Control::Graph_Control(sf::Font* font): 
    mFont(font),
    playBtn(nullptr),
    pauseBtn(nullptr),
    nextBtn(nullptr),
    prevBtn(nullptr)
{
    assert(bgTexture.loadFromFile("media/image/bgGraphControl.png"));
    assert(playBtnTexture.loadFromFile("media/image/playBtn.png"));
    assert(pauseBtnTexture.loadFromFile("media/image/pauseBtn.png"));
    assert(nextBtnTexture.loadFromFile("media/image/nextBtn.png"));
    assert(prevBtnTexture.loadFromFile("media/image/prevBtn.png"));

    bgSprite.setTexture(bgTexture);

    prevBtn = new Button(
        font,
        &prevBtnTexture,
        "",
        sf::Vector2f(
            bgSprite.getPosition().x + 20,
            bgSprite.getPosition().y + 10
        )
    );

    playBtn = new Button(
        font,
        &playBtnTexture,
        "",
        sf::Vector2f(
            bgSprite.getPosition().x + prevBtnTexture.getSize().x + 50,
            bgSprite.getPosition().y + 10
        )
    );

    nextBtn = new Button(
        font,
        &nextBtnTexture,
        "",
        sf::Vector2f(
            bgSprite.getPosition().x + prevBtnTexture.getSize().x + playBtnTexture.getSize().x + 50,
            bgSprite.getPosition().y + 10
        )
    );
}

Graph_Control::~Graph_Control()
{
    if(playBtn) delete playBtn;
    if(nextBtn) delete nextBtn;
    if(prevBtn) delete prevBtn;
}

void Graph_Control::handleEvent(sf::Event &event, sf::RenderWindow *window)
{
    if(event.type!=sf::Event::MouseButtonReleased) return;

    if(playBtn) playBtn->isMouseOver(window);
    if(nextBtn) nextBtn->isMouseOver(window);
    if(prevBtn) prevBtn->isMouseOver(window);
}

void Graph_Control::handleRealTimeInput(sf::RenderWindow *window)
{
    if(playBtn) playBtn->isMouseOver(window);
    if(nextBtn) nextBtn->isMouseOver(window);
    if(prevBtn) prevBtn->isMouseOver(window);
}

void Graph_Control::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(bgSprite, states);
    if(playBtn) target.draw(*playBtn, states);
    if(nextBtn) target.draw(*nextBtn, states);
    if(prevBtn) target.draw(*prevBtn, states);
}
