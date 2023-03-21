#pragma once

#include <SceneNode.hpp>
#include <SFML/Graphics.hpp>

class SinglyLinkedList : private sf::NonCopyable
{
    public:
        SinglyLinkedList(sf::RenderWindow& window);

    private:
        sf::RenderWindow&               mWindow;
        SceneNode                       mSceneGraph;
};