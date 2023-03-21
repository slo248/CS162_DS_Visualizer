#include "App.hpp"

App::App():
    mWindow(sf::VideoMode(windowWidth,windowHeight,sf::Style::Titlebar|sf::Style::Close),"Data Structure Visualization"),
    mCircle()
{
    mCircle.setPosition(100.f,100.f);
    mCircle.setRadius(10.f);
    mCircle.setFillColor(sf::Color::White);
    mCircle.setOutlineThickness(8.f);
    mCircle.setOutlineColor(sf::Color::Blue);

    fonts.load(Fonts::ID::Times,"media/font/times.ttf");    
}

void App::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate=sf::Time::Zero;
    while(mWindow.isOpen()){
        processInput();
        timeSinceLastUpdate+=clock.restart();
        while(timeSinceLastUpdate>TimePerFrame){
            processInput();
            update(TimePerFrame);
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
        }
}

void App::update(sf::Time dt)
{
    
}

void App::render()
{
    mWindow.clear();
    mWindow.draw(mCircle);
    mWindow.display();
}
