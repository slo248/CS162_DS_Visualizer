#include <Player.hpp>
#include <NodeCommand.hpp>
#include <ArrowCommand.hpp>
#include <iostream>

Player::Player()
{
    mKeyBinding.clear();
    mActionBinding.clear();

    mKeyBinding[sf::Keyboard::W] = MoveUp;
    mKeyBinding[sf::Keyboard::S] = MoveDown;
    mKeyBinding[sf::Keyboard::A] = MoveLeft;
    mKeyBinding[sf::Keyboard::D] = MoveRight;

    const float playerSpeed = 300.f;
    mActionBinding[MoveUp].action = derivedAction<Node>(NodeMover(0.f, -playerSpeed));
    mActionBinding[MoveDown].action = derivedAction<Node>(NodeMover(0.f, playerSpeed));
    mActionBinding[MoveLeft].action = derivedAction<Node>(NodeMover(-playerSpeed, 0.f));
    mActionBinding[MoveRight].action = derivedAction<Node>(NodeMover(playerSpeed, 0.f));

    for(auto& pair:mActionBinding)
        pair.second.category = Category::Node;
}

void Player::assignKey(Action action, sf::Keyboard::Key key)
{
    mKeyBinding[key] = action;
}

sf::Keyboard::Key Player::getAssignedKey(Action action) const
{
    auto found=std::find_if(mKeyBinding.begin(), mKeyBinding.end(), [action](std::pair<sf::Keyboard::Key, Action> pair){
        return pair.second == action;
    });
    if(found!=mKeyBinding.end())
        return found->first;
    return sf::Keyboard::Unknown;
}

void Player::handleEvent(const sf::Event &event, CommandQueue &commands)
{
    switch (event.type){
        case sf::Event::KeyPressed:
            switch (event.key.code){
                case sf::Keyboard::P:
                {
                    Command output;
                    output.category = Category::Node;
                    output.action = [](SceneNode &s, sf::Time)
                    {
                        std::cout << "Player position: " << s.getPosition().x
                                  << ", " << s.getPosition().y << std::endl;
                    };
                    commands.push(output);
                    break;
                }
                case sf::Keyboard::R:
                case sf::Keyboard::F:
                {
                    Command flag;
                    flag.category = Category::Node;
                    flag.action=derivedAction<Node>(NodeScaleFlag(true));
                    commands.push(flag);
                    break;
                }
                default:
                    break;
            }
        default:
            break;
    }
}

void Player::handleRealtimeInput(CommandQueue &commands)
{
    Command stop;
    stop.category = Category::Node;
    stop.action = derivedAction<Node>(NodeStopper());
    commands.push(stop);

    for(auto pair:mKeyBinding)
        if(sf::Keyboard::isKeyPressed(pair.first) && isRealtimeAction(pair.second)){
            commands.push(mActionBinding[pair.second]);
        }
}

bool Player::isRealtimeAction(Action action)
{
    return action == MoveUp || action == MoveDown || action == MoveLeft || action == MoveRight;
}
