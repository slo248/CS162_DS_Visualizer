#pragma once

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
        SinglyLinkedList(sf::RenderWindow& window);

    private:
        sf::RenderWindow&                           mWindow;
        SceneNode                                   mSceneGraph;
        std::array<SceneNode*,Layer::NumLayer>      mSceneLayers;

    private:
        void            buildScene();
};