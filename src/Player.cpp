#include "Player.hpp"

void Player::handleRealtimeInput(CommandQueue &commands)
{
    const float playerSpeed = 30.f;
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