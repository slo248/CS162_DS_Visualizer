#include "Menu.h"

Menu::Menu(sf::Font *sanf, sf::Vector2f windowSize)
{
    title.setFont(*sanf);
    title.setString("Data Structure Visualizer");
    title.setCharacterSize(50);
    title.setFillColor(BLACK);
    title.setPosition(sf::Vector2f(windowSize.x/2-title.getGlobalBounds().width/2, 50));

    subtitle.setFont(*sanf);
    subtitle.setString("visualising data structures through animation");
    subtitle.setCharacterSize(30);
    subtitle.setFillColor(BLACK);
    subtitle.setPosition(sf::Vector2f(windowSize.x/2-subtitle.getGlobalBounds().width/2, 150));

    btnTexture.loadFromFile("media/image/menuBtn.png");
    DS.push_back(Button(sanf, &btnTexture, "Singly Linked List", sf::Vector2f(windowSize.x/2 - btnTexture.getSize().x/2 - 300, 250)));
    DS.push_back(Button(sanf, &btnTexture, "Doubly Linked List", sf::Vector2f(windowSize.x/2 - btnTexture.getSize().x/2, 250)));
    DS.push_back(Button(sanf, &btnTexture, "Circular Linked List", sf::Vector2f(windowSize.x/2 - btnTexture.getSize().x/2 + 300, 250)));
    DS.push_back(Button(sanf, &btnTexture, "Stack", sf::Vector2f(windowSize.x/2 - btnTexture.getSize().x/2 - 300, 450)));
    DS.push_back(Button(sanf, &btnTexture, "Queue", sf::Vector2f(windowSize.x/2 - btnTexture.getSize().x/2, 450)));
    DS.push_back(Button(sanf, &btnTexture, "Array", sf::Vector2f(windowSize.x/2 - btnTexture.getSize().x/2 + 300, 450)));
}

void Menu::handleEvent(sf::Event &event, sf::RenderWindow *window)
{
    for (auto &btn : DS)
        if(btn.isMouseOver(window));
}

void Menu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(title);
    target.draw(subtitle);
    for (auto &btn : DS) target.draw(btn);
}
