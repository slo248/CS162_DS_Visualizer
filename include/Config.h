#ifndef CONFIG_H
#define CONFIG_H

#include "Global.h"

namespace Config
{
    const int MIN_VALUE=0;
    const int MAX_VALUE=99;

    namespace Window
    {
        const int WIDTH = 1500;
        const int HEIGHT = 900;
        const int FPS = 60;
        const sf::String TITLE = "Data Structure Visualizer";
        const sf::Uint32 STYLE = sf::Style::Titlebar | sf::Style::Close;
        const sf::ContextSettings SETTINGS = sf::ContextSettings(0, 0, 16);
    }

    namespace Circle
    {
        const float CHAR_SIZE           = 24.f;
        const float RADIUS              = 22.f;
        const float THICKNESS           = 3.f;
        const float HALF_WIDTH          = RADIUS+THICKNESS;
    }

    namespace Square
    {
        const float CHAR_SIZE           = 24.f;
        const float WIDTH               = 50.f;
        const float HEIGHT              = WIDTH;
        const float THICKNESS           = 3.f;
        const float HALF_WIDTH          = WIDTH/2.f+THICKNESS;
    }

    namespace Arrow
    {
        const float BAR_WIDTH           = 50.f;
        const float TRIANGLE_WIDTH      = 10.f;
        const float HEIGHT_EACH         = 4.f;
        const float WIDTH               = BAR_WIDTH+TRIANGLE_WIDTH;
    }

    namespace Button
    {
        const float HEIGHT              = 60.f;
        const float WIDTH               = 100.f;
        const float CHAR_SIZE           = 25.f;
        const sf::Color BG_COLOR        = GREEN;
        const sf::Color BG_MOUSE_OVER   = BLACK;
        const sf::Color TEXT_COLOR      = WHITE;
    }

    namespace TextBox
    {
        const int   LIMIT               = 20;
        const float HEIGHT              = 40.f;
        const float WIDTH               = 320.f;
        const float CHAR_SIZE           = 23.f;
        const float CURSOR_BLINK_TIME   = 0.5f;
        const char  CURSOR              = '_';
        const sf::Color BG_COLOR        = BLACK;
        const sf::Color TEXT_COLOR      = WHITE;
    }

    namespace InputBox
    {
        const float HEIGHT              = 60.f;
        const float WIDTH               = 400.f;
        const float CHAR_SIZE           = 23.f;
        const sf::Color BG_COLOR        = GREEN;
        const sf::Color TEXT_COLOR      = WHITE;
    }

    namespace SArr
    {
        const int MIN_NODE=0;
        const int MAX_NODE=20;
    }

    namespace SLL
    {
        const int MIN_NODE=0;
        const int MAX_NODE=10;
    }

    namespace DLL
    {
        const int MIN_NODE=0;
        const int MAX_NODE=10;
    }

    namespace Stack
    {
        const int MIN_NODE=0;
        const int MAX_NODE=5;
    }

    namespace Queue
    {
        const int MIN_NODE=0;
        const int MAX_NODE=10;
    }
}

#endif // CONFIG_H