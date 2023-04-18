#include "SLL_Control.h"
#include "Config.h"

SLL_Control::SLL_Control(sf::Font *font, sf::Vector2f windowSize): 
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
            Config::Window::HEIGHT-btnTexture.getSize().y*options.size()+(btnTexture.getSize().y-LeftTriBtnTexture.getSize().y)/2
        )
    );

    rightBtn=new Button(
        mFont, 
        &RightTriBtnTexture, 
        "",
        sf::Vector2f(
            btnTexture.getSize().x+10.f+bgSuboptionTexture.getSize().x-RightTriBtnTexture.getSize().x-35, 
            Config::Window::HEIGHT-btnTexture.getSize().y*options.size()+(btnTexture.getSize().y-RightTriBtnTexture.getSize().y)/2
        )
    );
}

void SLL_Control::genOptions(sf::Vector2f windowSize)
{
    options.push_back(Button(mFont, &btnTexture, "Create", sf::Vector2f(0, windowSize.y-5*btnTexture.getSize().y)));
    options.push_back(Button(mFont, &btnTexture, "Insert", sf::Vector2f(0, windowSize.y-4*btnTexture.getSize().y)));
    options.push_back(Button(mFont, &btnTexture, "Search", sf::Vector2f(0, windowSize.y-3*btnTexture.getSize().y)));
    options.push_back(Button(mFont, &btnTexture, "Update", sf::Vector2f(0, windowSize.y-2*btnTexture.getSize().y)));
    options.push_back(Button(mFont, &btnTexture, "Delete", sf::Vector2f(0, windowSize.y-1*btnTexture.getSize().y)));
}

void SLL_Control::genSuboptions(sf::Vector2f windowSize)
{
    // create
    suboptions.push_back(std::vector<std::vector<std::string>>{
        {"Empty", "", ""},
        {"User defined list", "A =",""},
        {"Random","n =",""}
    });

    // insert
    suboptions.push_back(std::vector<std::vector<std::string>>{
        {"i=0 (Head), specify v=", "v =", ""},
        {"i=N (After Tail), specify v =", "A =",""},
        {"Specify i in [1,N-1] and v ="}
    });

    //search
    suboptions.push_back(std::vector<std::vector<std::string>>{
        {"Specify v = ","v =",""}
    });

    //update
    suboptions.push_back(std::vector<std::vector<std::string>>{
        {"Specify i in [0,N-1] and v =","i = ","v ="}
    });

    // delete
    suboptions.push_back(std::vector<std::vector<std::string>>{
        {"Remove i=0 (Head)", "", ""},
        {"Remove i=N-1 (Tail)", "",""},
        {"Specify i in [1,N-2]","i = ",""}
    });
}
