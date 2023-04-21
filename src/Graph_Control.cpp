#include "Graph_Control.h"

Graph_Control::Graph_Control(sf::Font* font): 
    mFont(font),
    playBtn(nullptr),
    pauseBtn(nullptr),
    nextBtn(nullptr),
    prevBtn(nullptr),
    isPause(false)
{
    assert(bgTexture.loadFromFile("media/image/bgGraphControl.png"));
    assert(playBtnTexture.loadFromFile("media/image/playBtn.png"));
    assert(pauseBtnTexture.loadFromFile("media/image/pauseBtn.png"));
    assert(nextBtnTexture.loadFromFile("media/image/nextBtn.png"));
    assert(prevBtnTexture.loadFromFile("media/image/prevBtn.png"));

    bgSprite.setTexture(bgTexture);

    playBtn = new Button(
        mFont,
        &playBtnTexture,
        "",
        sf::Vector2f(0,0)
    );
    playBtn->setCenter();
    playBtn->setPosition(
        130,
        bgTexture.getSize().y/2
    );

    pauseBtn = new Button(
        mFont,
        &pauseBtnTexture,
        "",
        sf::Vector2f(0,0)
    );
    pauseBtn->setCenter();
    pauseBtn->setPosition(playBtn->getPosition());

    prevBtn = new Button(
        mFont,
        &prevBtnTexture,
        "",
        sf::Vector2f(0,0)
    );
    prevBtn->setCenter();
    prevBtn->setPosition(
        playBtn->getPosition().x-80,
        bgTexture.getSize().y/2
    );

    nextBtn = new Button(
        mFont,
        &nextBtnTexture,
        "",
        sf::Vector2f(0,0)
    );
    nextBtn->setCenter();
    nextBtn->setPosition(
        playBtn->getPosition().x+80,
        bgTexture.getSize().y/2
    );
}

Graph_Control::~Graph_Control()
{
    delete playBtn;
    delete pauseBtn;
    delete nextBtn;
    delete prevBtn;
}

void Graph_Control::handleEvent(sf::Event &event, sf::RenderWindow *window)
{
    if(event.type!=sf::Event::MouseButtonReleased) return;

    if(isPause)
        isPause=!pauseBtn->isMouseOver(window);
    else
        isPause=playBtn->isMouseOver(window);
}

void Graph_Control::handleRealTimeInput(sf::RenderWindow *window)
{
    if(isPause) pauseBtn->isMouseOver(window);
    else playBtn->isMouseOver(window);
    nextBtn->isMouseOver(window);
    prevBtn->isMouseOver(window);
}

void Graph_Control::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(bgSprite, states);
    if(isPause) target.draw(*pauseBtn, states);
    else target.draw(*playBtn, states);
    target.draw(*nextBtn, states);
    target.draw(*prevBtn, states);
}
