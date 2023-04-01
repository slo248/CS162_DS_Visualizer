#include "App.hpp"

App::App(sf::Font& font, const sf::ContextSettings &settings):
    mWindow(sf::VideoMode(windowWidth,windowHeight),"Data Structure Visualization",sf::Style::Titlebar|sf::Style::Close,settings),
    mIsPaused(false),
    mUpdateTime(),
    mNumFrame(0),
    mSLL(mWindow,font),
    mFont(font)
{
    mStatisticText.setFont(mFont);
    mStatisticText.setPosition(2.f,2.f);
    mStatisticText.setCharacterSize(25);
    mStatisticText.setFillColor(sf::Color::Black);
}

void App::run()
{
    sf::Clock clock;
    sf::Time timeElapsed=sf::Time::Zero;
    sf::Time timeSinceLastUpdate=sf::Time::Zero;
    while(mWindow.isOpen()){
        processInput();

        timeElapsed=clock.restart();
        updateStatistic(timeElapsed);

        timeSinceLastUpdate+=timeElapsed;
        while(timeSinceLastUpdate>TimePerFrame){
            processInput();
            if(!mIsPaused) update(TimePerFrame);
            timeSinceLastUpdate-=TimePerFrame;
        }

        render();
    }
}

void App::processInput()
{
    sf::Event event;
    while(mWindow.pollEvent(event))
        switch(event.type){
            case sf::Event::Closed:
                mWindow.close();
                break;
            case sf::Event::LostFocus:
                mIsPaused=true;
                break;
            case sf::Event::GainedFocus:
                mIsPaused=false;
                break;
            default:
                mSLL.handleEvent(event,TimePerFrame);
                break;
        }

    mSLL.handleRealTimeInput(TimePerFrame);    
}

void App::update(sf::Time dt)
{
    mSLL.update(dt);
}

void App::render()
{
    mWindow.clear(sf::Color::White);
    mSLL.draw();
    mWindow.draw(mStatisticText);
    mWindow.display();
}

void App::updateStatistic(sf::Time timeElapsed)
{
    mNumFrame++;
    mUpdateTime+=timeElapsed;
    if(mUpdateTime.asSeconds()>1.f){
        mStatisticText.setString(
            "FPS: "+std::to_string(mNumFrame)+'\n'+
            "Time / Update: "+std::to_string(mUpdateTime.asMicroseconds()/mNumFrame)+" us"
        );
        mNumFrame=0;
        mUpdateTime-=sf::seconds(1.f);
    }
}
