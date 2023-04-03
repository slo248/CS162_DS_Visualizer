#pragma once

#include <CommandQueue.hpp>
#include <NodeCommand.hpp>
#include <ArrowCommand.hpp>
#include <map>

class Player
{
public:
    Player();
    enum Action
    {
        MoveLeft,
        MoveRight,
        MoveUp,
        MoveDown,
        PrintPos,
        ScaleOn,
        ActionCount
    };

    void                assignKey(Action action, sf::Keyboard::Key key);
    sf::Keyboard::Key   getAssignedKey(Action action) const;

    void                handleEvent(const sf::Event& event, CommandQueue& commands);
    void                handleRealtimeInput(CommandQueue& commands);

private:
    static bool         isRealtimeAction(Action action);

private:
    std::map<sf::Keyboard::Key, Action> mKeyBinding;
    std::map<Action, Command>           mActionBinding;
};