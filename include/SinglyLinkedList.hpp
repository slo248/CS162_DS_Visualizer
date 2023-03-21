#pragma once

#include <SceneNode.hpp>
#include <SFML/Graphics.hpp>

class SinglyLinkedList : private sf::NonCopyable
{
    private:
        sf::RenderWindow&               mWindow;
        SceneNode                       mSceneGraph;
    
    public:
        SinglyLinkedList();
};