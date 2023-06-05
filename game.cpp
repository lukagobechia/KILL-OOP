#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(564, 317), "SFML works!");
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    if (!backgroundTexture.loadFromFile("background.jpg"))
    {
        std::cout << "Failed to load texture!" << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(backgroundSprite);
        window.display();
    }

    return 0;
}
