#pragma once

#include <SinglyLinkedList.hpp>
#include <SFML/Graphics.hpp>

class App
{
    public:
                                    App(sf::Font& font, const sf::ContextSettings &settings);
        void                        run();

    private:
        const int                   windowWidth=1500;
        const int                   windowHeight=800;
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