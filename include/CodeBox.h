#ifndef CODE_BOX_H
#define CODE_BOX_H

#include "HNeed.h"

class CodeBox
{
public:
    const float         WIDTH = 500;
    const float         HEIGHT = 40;
    const float         CHAR_SIZE=23;
    const sf::Color     BG_COLOR = Colors::SILVER;
    const sf::Color     TEXT_COLOR = Colors::BLACK;

    CodeBox(sf::Font* font, std::string path);
    void loadFromFile(std::string path);
    void draw(sf::RenderWindow* window);
private:
    sf::RectangleShape rect;
    sf::Text text;
    std::vector<std::string> code;
};

#endif // CODE_BOX_H