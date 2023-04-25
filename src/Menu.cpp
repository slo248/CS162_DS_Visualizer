#include "Menu.h"

Menu::Menu(sf::Font *sanf, sf::Vector2f windowSize)
{
    title.setFont(*sanf);
    title.setString("Data Structure Visualizer");
    title.setCharacterSize(50);
    title.setFillColor(BLACK);
    title.setPosition(sf::Vector2f(windowSize.x/2-title.getGlobalBounds().width/2, 50));

    subtitle.setFont(*sanf);
    subtitle.setString("Choose a data structure to visualize");
    subtitle.setCharacterSize(30);
    subtitle.setFillColor(BLACK);
    subtitle.setPosition(sf::Vector2f(windowSize.x/2-subtitle.getGlobalBounds().width/2, 150));

    btnTexture.loadFromFile("media/image/menuBtn.png");
    DS.push_back(Button(sanf, &btnTexture, "Singly Linked List", sf::Vector2f(windowSize.x/2 - 100, 250)));
    DS.push_back(Button(sanf, &btnTexture, "Doubly Linked List", sf::Vector2f(windowSize.x/2, 250)));
    DS.push_back(Button(sanf, &btnTexture, "Circular Linked List", sf::Vector2f(windowSize.x/2 + 100, 250)));
}