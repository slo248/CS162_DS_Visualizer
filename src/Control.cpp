#include "Control.h"
#include "Config.h"

Control::Control(sf::Font* font):
    curOption(-1),
    curSuboption(-1),
    mFont(font),
    inputBox1(nullptr),
    inputBox2(nullptr),
    subOption(nullptr)
{
    if (!btnTexture.loadFromFile("media/image/button.png"))
    {
        std::cout << "Error loading btn.png" << std::endl;
    }
    if (!bgSuboptionTexture.loadFromFile("media/image/bgSuboption.png"))
    {
        std::cout << "Error loading bgSuboption.png" << std::endl;
    }
    bgSuboptionSprite.setTexture(bgSuboptionTexture);
    if(!suboptionTexture.loadFromFile("media/image/suboption.png"))
    {
        std::cout << "Error loading suboption.png" << std::endl;
    }
}

Control::~Control()
{
    if(inputBox1) delete inputBox1;
    if(inputBox2) delete inputBox2;
    if(subOption) delete subOption;
}

void Control::handleEvent(sf::Event &event, sf::RenderWindow *window)
{
    if(inputBox1) inputBox1->handleEvent(event,window);
    if(inputBox2) inputBox2->handleEvent(event,window);

    switch (event.type)
    {
        case sf::Event::MouseButtonReleased:
            if(event.mouseButton.button==sf::Mouse::Left)
            {
                for(int i=0;i<options.size();i++)
                {
                    if(options[i].isMouseOver(window))
                    {
                        curOption=i;
                        curSuboption=0;
                        loadSubOption();
                        command.push(i);
                        break;
                    }
                }                
            }
            break;
    }
}

void Control::handleRealTimeInput(sf::RenderWindow *window)
{
    for(Button& btn: options)
        btn.isMouseOver(window);
}

void Control::update(float dt)
{
    if(inputBox1) inputBox1->update(dt);
    if(inputBox2) inputBox2->update(dt);
}

int Control::getCommand()
{
    if(command.empty()) return -1;
    int cmd=command.front();
    command.pop();
    return cmd;
}

void Control::loadSubOption()
{
    if(subOption) delete subOption;
    subOption=new RectText(
        mFont,
        &suboptionTexture,
        suboptions[curOption][curSuboption][0],
        sf::Vector2f(
            btnTexture.getSize().x+10+(bgSuboptionTexture.getSize().x-suboptionTexture.getSize().x)/2,
            Config::Window::HEIGHT-btnTexture.getSize().y*options.size()+(btnTexture.getSize().y-suboptionTexture.getSize().y)/2
        )
    );

    if(inputBox1) delete inputBox1;
    inputBox1=nullptr;
    if(suboptions[curOption][curSuboption].size()>1 && suboptions[curOption][curSuboption][1]!="")
    {
        inputBox1=new InputBox(
            mFont,
            sf::Vector2f(
                btnTexture.getSize().x+10+(bgSuboptionTexture.getSize().x-Config::InputBox::WIDTH)/2,
                Config::Window::HEIGHT-btnTexture.getSize().y*(options.size()-1)+(btnTexture.getSize().y-Config::InputBox::HEIGHT)/2
            ),
            suboptions[curOption][curSuboption][1]
        );
    }

    if(inputBox2) delete inputBox2;
    inputBox2=nullptr;
    if(suboptions[curOption][curSuboption].size()>1 && suboptions[curOption][curSuboption][2]!="")
    {
        inputBox2=new InputBox(
            mFont,
            sf::Vector2f(
                btnTexture.getSize().x+10+(bgSuboptionTexture.getSize().x-Config::InputBox::WIDTH)/2,
                Config::Window::HEIGHT-btnTexture.getSize().y*(options.size()-2)+(btnTexture.getSize().y-Config::InputBox::HEIGHT)/2
            ),
            suboptions[curOption][curSuboption][2]
        );
    }
}

void Control::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto &option : options)
        target.draw(option, states);
    if(curSuboption!=-1)
        target.draw(bgSuboptionSprite, states);
    if(inputBox1)
        target.draw(*inputBox1, states);
    if(inputBox2)
        target.draw(*inputBox2, states);
    if(subOption)
        target.draw(*subOption, states);
}
