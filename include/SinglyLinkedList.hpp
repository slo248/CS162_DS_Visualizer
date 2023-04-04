#pragma once

#include <SceneNode.hpp>
#include <CommandQueue.hpp>
#include <Button.hpp>
#include <NodeCommand.hpp>
#include <ArrowCommand.hpp>
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
        const float         DEFAULT_LEN=130.f;
        const sf::Vector2f  DEFAULT_DIST=sf::Vector2f(DEFAULT_LEN,0.f);
        const int           MAX_NUM=99;
        const int           MAX_NUM_NODE=10;

    public:
        SinglyLinkedList(sf::RenderWindow& window,sf::Font& font);
        void            draw();
        void            setRandom();
        // Read data from a file
        // First line has a number N - number of nodes
        // N lines next contains the elements has the same order in the list
        void            loadFromFile(std::string dir);
        void            update(sf::Time dt);
        void            processInput(sf::Event event);
        CommandQueue&   getCommandQueue();

    private:
        sf::RenderWindow&                           mWindow;
        SceneNode                                   mSceneGraph;
        std::array<SceneNode*,Layer::NumLayer>      mSceneLayers;
        Node*                                       pHead;
        sf::Font&                                   mFont;
        int                                         mNumNode;

        CommandQueue                                mCommandQueue;
        std::vector<Button*>                        mButtons;

    private:
        void            buildScene();
        void            addArrow(Node* node, sf::Vector2f dist);
        void            removeSubButton();
};