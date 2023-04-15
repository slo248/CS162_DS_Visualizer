#include "CodeBox.h"

CodeBox::CodeBox(sf::Font *font, std::string path)
{
    text.setFont(*font);
    text.setCharacterSize(CHAR_SIZE);
    {
        sf::FloatRect bounds = text.getLocalBounds();
        text.setOrigin(
            8.f,
            bounds.top + bounds.height/2
        );
    }
    text.setFillColor(TEXT_COLOR);

    rect.setSize(sf::Vector2f(WIDTH, HEIGHT));
    rect.setFillColor(BG_COLOR);
    {
        sf::FloatRect bounds = rect.getLocalBounds();
        rect.setOrigin(
            bounds.left + bounds.width,
            bounds.top + bounds.height
        );
    }
}

void CodeBox::loadFromFile(std::string path)
{
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
    for(int i=0; i<code.size(); i++){
        text.setString(code[i]);

        rect.setPosition(
            O.x,
            O.y-(code.size()-i-1)*rect.getSize().y
        );

        text.setPosition(
            rect.getPosition().x-rect.getSize().x+10.f,
            rect.getPosition().y-rect.getSize().y/2
        );

        window->draw(rect);
        window->draw(text);
    }
}
