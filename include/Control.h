#ifndef CONTROL_H
#define CONTROL_H

#include "Global.h"
#include "Button.h"
#include "InputBox.h"
#include "Command.h"
#include <queue>

class Control: public sf::Drawable
{
public: 
    Control(sf::Font* font);
    ~Control();

    void    handleEvent(sf::Event& event, sf::RenderWindow* window);
    void    handleRealTimeInput(sf::RenderWindow* window);
    void    update(float dt);
    bool    getCommand(Command& command);

    void loadSubOption();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:
    int curOption;
    int curSuboption;
    std::queue<Command> commandQueue;

    std::vector<Button> options;
    std::vector<std::vector<std::vector<std::string>>> suboptions;
    sf::Texture     btnTexture;
    sf::Texture     LeftTriBtnTexture;
    sf::Texture     RightTriBtnTexture;
    sf::Texture     bgSuboptionTexture;
    sf::Texture     suboptionTexture;
    sf::Sprite      bgSuboptionSprite;
    sf::Font*       mFont;

    Button*         leftBtn;
    Button*         rightBtn;
    Button*         goBtn;
    InputBox*       inputBox1;
    InputBox*       inputBox2;
    RectText*       subOption;
};

#endif // CONTROL_H