#pragma once

#include <ResourceHolder.hpp>
#include <SFML/Graphics.hpp>

class App
{
    public:
                                    App();
        void                        run();

    private:
        const int                   windowWidth=1000;
        const int                   windowHeight=600;
        const sf::Time              TimePerFrame=sf::seconds(1.f/60.f);

    private:
        ResourceHolder<sf::Font,Fonts::ID>      fonts;

    private:
        sf::RenderWindow            mWindow;
        sf::CircleShape             mCircle;
        sf::Text                    mStatisticText;
        sf::Time                    mUpdateTime;
        int                         mNumFrame;
        bool                        mIsPaused;

    private:
        void                        processInput();
        void                        update(sf::Time dt);
        void                        render();
        void                        updateStatistic(sf::Time timeElapsed);
};