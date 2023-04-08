#pragma once

#include <SceneNode.hpp>
#include <Button.hpp>
#include <AnimationQueue.hpp>
#include <Node.hpp>
#include <SNAnimation.hpp>
#include <NodeAnimation.hpp>
#include <ArrowAnimation.hpp>
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
        const float         DEFAULT_LEN=120.f;
        const sf::Vector2f  DEFAULT_DIST=sf::Vector2f(DEFAULT_LEN,0);
        const int           MAX_NUM=99;
        const int           MAX_NUM_NODE=10;
        const sf::Vector2f  DEFAULT_POS=sf::Vector2f(200,200);

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

    private:
        sf::RenderWindow&                           mWindow;
        SceneNode                                   mSceneGraph;
        std::array<SceneNode*,Layer::NumLayer>      mSceneLayers;
        Node*                                       pHead;
        sf::Font&                                   mFont;
        int                                         mNumNode;

        AnimationQueue                              mAnimationQueue;
        std::vector<Button*>                        mButtons;

    private:
        void        buildScene();
        void        removeSubButton();
        void        removeAllChosen();
        void        appearNewNode();
        std::unique_ptr<Node>  createNode(sf::Vector2f pos, int value);
        std::unique_ptr<Arrow> createArrow(Node* a, Node* b);
        void        insertFront();
        void        insertWhenEmpty();
};