#include <Player.hpp>
#include <NodeCommand.hpp>
#include <ArrowCommand.hpp>
#include <iostream>

void Player::handleEvent(const sf::Event &event, CommandQueue &commands)
{
    if(event.type==sf::Event::KeyPressed &&
        event.key.code==sf::Keyboard::P)
    {
        Command output;
        output.category=Category::Node;
        output.action=[](SceneNode& s, sf::Time)
        {
            std::cout << "Player position: " << s.getPosition().x 
                    << ", " << s.getPosition().y << std::endl;
        };
        commands.push(output);
    }
}

void Player::handleRealtimeInput(CommandQueue &commands)
{
    const float playerSpeed = 300.f;

    Command stop;
    stop.category = Category::Node;
    stop.action = derivedAction<Node>(NodeStopper());
    commands.push(stop);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        Command moveUp;
        moveUp.category = Category::Node;
        moveUp.action = derivedAction<Node>(NodeMover(0.f, -playerSpeed));
        commands.push(moveUp);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        Command moveDown;
        moveDown.category = Category::Node;
        moveDown.action = derivedAction<Node>(NodeMover(0.f, playerSpeed));
        commands.push(moveDown);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        Command moveLeft;
        moveLeft.category = Category::Node;
        moveLeft.action = derivedAction<Node>(NodeMover(-playerSpeed, 0.f));
        commands.push(moveLeft);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        Command moveRight;
        moveRight.category = Category::Node;
        moveRight.action = derivedAction<Node>(NodeMover(playerSpeed, 0.f));
        commands.push(moveRight);
    }
}