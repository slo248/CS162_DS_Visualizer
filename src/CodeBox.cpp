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

void CodeBox::draw(sf::RenderWindow *window, int pos)
{
    std::vector<int> high;
    if(pos==0) high.push_back(0);
    else
        while(pos){
            high.push_back(pos%10);
            pos/=10;
        }

    sf::Vector2f O=window->getView().getSize();
    for(int i=0; i<MAX_LINE; i++){
        rect.setFillColor(BG_COLOR);
        if(i<code.size()){
            text.setString(code[i]);
            {
                sf::FloatRect bounds = text.getLocalBounds();
                text.setOrigin(
                    bounds.left, 
                    bounds.top  + bounds.height/2.0f
                );
            }
            
            for(int j:high) if(i==j)
                rect.setFillColor(CUR_LINE);               

            rect.setPosition(
                O.x-WIDTH,
                O.y-HEIGHT*(MAX_LINE-i)
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
                O.y-HEIGHT*(MAX_LINE-i)
            );
            window->draw(rect);
        }
    }
}
