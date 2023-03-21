#include "App.hpp"

App::App():
    mWindow(sf::VideoMode(windowWidth,windowHeight,sf::Style::Titlebar|sf::Style::Close),"Data Structure Visualization"),
    mIsPaused(false),
    mCircle(),
    mUpdateTime(),
    mNumFrame(0)
{
    mCircle.setPosition(100.f,100.f);
    mCircle.setRadius(10.f);
    mCircle.setFillColor(sf::Color::White);
    mCircle.setOutlineThickness(8.f);
    mCircle.setOutlineColor(sf::Color::Blue);

    fonts.load(Fonts::ID::Times,"media/font/times.ttf");   

    mStatisticText.setFont(fonts.get(Fonts::ID::Times));
    mStatisticText.setPosition(2.f,2.f);
    mStatisticText.setCharacterSize(25);
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
            case sf::Event::LostFocus:
                mIsPaused=true;
                break;
            case sf::Event::GainedFocus:
                mIsPaused=false;
                break;
            case sf::Event::Closed:
                mWindow.close();
                break;
        }
}

void App::update(sf::Time dt)
{
    
}

void App::render()
{
    mWindow.clear();
    mWindow.draw(mCircle);
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
