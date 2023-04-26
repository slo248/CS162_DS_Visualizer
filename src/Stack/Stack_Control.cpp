#include "Stack_Control.h"
#include "Config.h"

Stack_Control::Stack_Control(sf::Font *font, sf::Vector2f windowSize): 
    Control(font)
{
    genOptions(windowSize);
    genSuboptions(windowSize);
    bgSuboptionSprite.setPosition(sf::Vector2f(
        btnTexture.getSize().x+10.f, 
        windowSize.y-5*btnTexture.getSize().y
    ));

    leftBtn=new Button(
        mFont, 
        &LeftTriBtnTexture, 
        "",
        sf::Vector2f(
            btnTexture.getSize().x+40.f, 
            Config::Window::HEIGHT-btnTexture.getSize().y*5+(btnTexture.getSize().y-LeftTriBtnTexture.getSize().y)/2
        )
    );

    rightBtn=new Button(
        mFont, 
        &RightTriBtnTexture, 
        "",
        sf::Vector2f(
            btnTexture.getSize().x+10.f+bgSuboptionTexture.getSize().x-RightTriBtnTexture.getSize().x-35, 
            Config::Window::HEIGHT-btnTexture.getSize().y*5+(btnTexture.getSize().y-RightTriBtnTexture.getSize().y)/2
        )
    );

    graphControl.setPosition(
        0,
        windowSize.y-6*btnTexture.getSize().y
    );
}

void Stack_Control::genOptions(sf::Vector2f windowSize)
{
    options.push_back(Button(mFont, &btnTexture, "Create", sf::Vector2f(0, windowSize.y-5*btnTexture.getSize().y)));
    options.push_back(Button(mFont, &btnTexture, "Peek", sf::Vector2f(0, windowSize.y-4*btnTexture.getSize().y)));
    options.push_back(Button(mFont, &btnTexture, "Push", sf::Vector2f(0, windowSize.y-3*btnTexture.getSize().y)));
    options.push_back(Button(mFont, &btnTexture, "Pop", sf::Vector2f(0, windowSize.y-2*btnTexture.getSize().y)));
}

void Stack_Control::genSuboptions(sf::Vector2f windowSize)
{
    // create
    suboptions.push_back(std::vector<std::vector<std::string>>{
        {"Empty", "", ""},
        {"User defined list", "A =",""},
        {"Random"},
        {"Random fixed size","n =",""},
        {"Load from file","",""}
    });

    // top
    suboptions.push_back(std::vector<std::vector<std::string>>{
        {"Return top value","",""}
    });

    // push
    suboptions.push_back(std::vector<std::vector<std::string>>{
        {"Specify v = ","v =",""}
    });

    //update
    suboptions.push_back(std::vector<std::vector<std::string>>{
        {"","",""}
    });
}
