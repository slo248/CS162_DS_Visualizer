#include "CodeBox.h"

CodeBox::CodeBox(sf::Font *font)
{
    text.setFont(*font);
    text.setCharacterSize(CHAR_SIZE);
    text.setFillColor(TEXT_COLOR);

    rect.setSize(sf::Vector2f(WIDTH, HEIGHT));
    rect.setFillColor(BG_COLOR);
}

void CodeBox::loadFromFile(std::string path)
{
    code.clear();

    std::ifstream fin(path);
    if(!fin.is_open()){
        std::cout << "Error: code file not found" << std::endl;
        return;
    }
    std::string line;
    while(std::getline(fin, line)) code.push_back(line);
    fin.close();
}

void CodeBox::draw(sf::RenderWindow *window)
{
    sf::Vector2f O=window->getView().getSize();
    const int maxBlk=10;
    for(int i=0; i<10; i++)
        if(i<code.size()){
            text.setString(code[i]);
            {
                sf::FloatRect bounds = text.getLocalBounds();
                text.setOrigin(
                    bounds.left, 
                    bounds.top  + bounds.height/2.0f
                );
            }

            rect.setPosition(
                O.x-WIDTH,
                O.y-HEIGHT*(maxBlk-i)
            );

            text.setPosition(
                rect.getPosition().x+10.f, 
                rect.getPosition().y+rect.getSize().y/2
            );

            window->draw(rect);
            window->draw(text);
        }
        else{
            rect.setPosition(
                O.x-WIDTH,
                O.y-HEIGHT*(maxBlk-i)
            );
            window->draw(rect);
        }
}
