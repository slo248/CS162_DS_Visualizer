#pragma once

#include <SinglyLinkedList.hpp>
#include <ResourceHolder.hpp>
#include <SFML/Graphics.hpp>

class App
{
    public:
                                    App(sf::Font& font);
        void                        run();

    private:
        const int                   windowWidth=1000;
        const int                   windowHeight=600;
        const sf::Time              TimePerFrame=sf::seconds(1.f/60.f);

    private:
        sf::Font&                   mFont;

    private:
        sf::RenderWindow            mWindow;
        sf::Text                    mStatisticText;
        sf::Time                    mUpdateTime;
        int                         mNumFrame;
        bool                        mIsPaused;
        SinglyLinkedList            mSLL;

    private:
        void                        processInput();
        void                        update(sf::Time dt);
        void                        render();
        void                        updateStatistic(sf::Time timeElapsed);
};