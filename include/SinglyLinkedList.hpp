#pragma once

#include <Node.hpp>
#include <SceneNode.hpp>
#include <SFML/Graphics.hpp>

namespace Layer{
    enum Type{
        Background,
        Front,
        NumLayer
    };
}

class SinglyLinkedList : private sf::NonCopyable
{
    public:
        const float         DEFAULT_DIST=100.f;
        const int           MAX_NUM=99;
        const int           MAX_NUM_NODE=10;

    public:
        SinglyLinkedList(sf::RenderWindow& window,sf::Font& font);
        void    draw();
        void    setRandom();

    private:
        sf::RenderWindow&                           mWindow;
        SceneNode                                   mSceneGraph;
        std::array<SceneNode*,Layer::NumLayer>      mSceneLayers;
        Node*                                       pHead;
        sf::Font&                                   mFont;
        int                                         mNumNode;

    private:
        void            buildScene();
};