#ifndef CONTROL_H
#define CONTROL_H

#include "Global.h"
#include "Button.h"
#include "InputBox.h"
#include <queue>

class Control: public sf::Drawable
{
public: 
    Control(sf::Font* font);
    ~Control();

    void    handleEvent(sf::Event& event, sf::RenderWindow* window);
    void    handleRealTimeInput(sf::RenderWindow* window);
    void    update(float dt);
    int     getCommand();

    void loadSubOption();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:
    int curOption;
    int curSuboption;
    std::queue<int> command;

    std::vector<Button> options;
    std::vector<std::vector<std::vector<std::string>>> suboptions;
    sf::Texture     btnTexture;
    sf::Texture     bgSuboptionTexture;
    sf::Texture     suboptionTexture;
    sf::Sprite      bgSuboptionSprite;
    sf::Font*       mFont;

    InputBox*       inputBox;
    RectText*       subOption;
};

#endif // CONTROL_H