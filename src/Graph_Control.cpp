#include "Graph_Control.h"

Graph_Control::Graph_Control(sf::Font* font): 
    mFont(font),
    isPause(false)
{
    assert(bgTexture.loadFromFile("media/image/bgGraphControl.png"));
    assert(playBtnTexture.loadFromFile("media/image/playBtn.png"));
    assert(pauseBtnTexture.loadFromFile("media/image/pauseBtn.png"));
    assert(nextBtnTexture.loadFromFile("media/image/nextBtn.png"));
    assert(prevBtnTexture.loadFromFile("media/image/prevBtn.png"));
    assert(beginBtnTexture.loadFromFile("media/image/beginBtn.png"));
    assert(endBtnTexture.loadFromFile("media/image/endBtn.png"));

    bgSprite.setTexture(bgTexture);

    playBtn = new Button(
        mFont,
        &playBtnTexture,
        "",
        sf::Vector2f(0,0),
        true
    );
    playBtn->setPosition(
        bgTexture.getSize().x/2,
        bgTexture.getSize().y/2
    );

    pauseBtn = new Button(
        mFont,
        &pauseBtnTexture,
        "",
        sf::Vector2f(0,0),
        true
    );
    pauseBtn->setPosition(playBtn->getPosition());

    prevBtn = new Button(
        mFont,
        &prevBtnTexture,
        "",
        sf::Vector2f(0,0),
        true
    );
    prevBtn->setPosition(
        playBtn->getPosition().x-80,
        bgTexture.getSize().y/2
    );

    nextBtn = new Button(
        mFont,
        &nextBtnTexture,
        "",
        sf::Vector2f(0,0),
        true
    );
    nextBtn->setPosition(
        playBtn->getPosition().x+80,
        bgTexture.getSize().y/2
    );

    beginBtn = new Button(
        mFont,
        &beginBtnTexture,
        "",
        sf::Vector2f(0,0),
        true
    );
    beginBtn->setPosition(
        prevBtn->getPosition().x-80,
        bgTexture.getSize().y/2
    );

    endBtn = new Button(
        mFont,
        &endBtnTexture,
        "",
        sf::Vector2f(0,0),
        true
    );
    endBtn->setPosition(
        nextBtn->getPosition().x+80,
        bgTexture.getSize().y/2
    );
}

Graph_Control::~Graph_Control()
{
    delete playBtn;
    delete pauseBtn;
    delete nextBtn;
    delete prevBtn;
    delete beginBtn;
    delete endBtn;
}

void Graph_Control::handleEvent(sf::Event &event, sf::RenderWindow *window, std::queue<Command> &commandQueue)
{
    if(event.type!=sf::Event::MouseButtonReleased) return;

    if(!isPause){
        isPause=pauseBtn->isMouseOver(window,getPosition());
        if(isPause) commandQueue.push(
            {
                -2,
                -1,
                -1,
                -1,
                std::vector<int>()
            }
        );
    }
    else{
        isPause=!playBtn->isMouseOver(window,getPosition());
        if(!isPause) commandQueue.push(
            {
                -3,
                -1,
                -1,
                -1,
                std::vector<int>()
            }
        );
    }

    if(prevBtn->isMouseOver(window,getPosition())) commandQueue.push(
        {
            -4,
            -1,
            -1,
            -1,
            std::vector<int>()
        }
    );
    
    if(nextBtn->isMouseOver(window,getPosition())) commandQueue.push(
        {
            -5,
            -1,
            -1,
            -1,
            std::vector<int>()
        }
    );

    if(beginBtn->isMouseOver(window,getPosition())) commandQueue.push(
        {
            -6,
            -1,
            -1,
            -1,
            std::vector<int>()
        }
    );

    if(endBtn->isMouseOver(window,getPosition())) commandQueue.push(
        {
            -7,
            -1,
            -1,
            -1,
            std::vector<int>()
        }
    );
}

void Graph_Control::handleRealTimeInput(sf::RenderWindow *window)
{
    if(!isPause) pauseBtn->isMouseOver(window,getPosition());
    else playBtn->isMouseOver(window,getPosition());
    nextBtn->isMouseOver(window,getPosition());
    prevBtn->isMouseOver(window,getPosition());
    beginBtn->isMouseOver(window,getPosition());
    endBtn->isMouseOver(window,getPosition());
}

void Graph_Control::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(bgSprite, states);
    if(!isPause) target.draw(*pauseBtn, states);
    else target.draw(*playBtn, states);
    target.draw(*nextBtn, states);
    target.draw(*prevBtn, states);
    target.draw(*beginBtn, states);
    target.draw(*endBtn, states);
}
