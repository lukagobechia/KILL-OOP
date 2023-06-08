#include <iostream>
#include <SFML/Graphics.hpp>

bool playerMovingRight = false;
bool playerMovingLeft = false;

//Render Window
sf::Vector2f viewSize(1000,720);
sf::VideoMode vm(viewSize.x,viewSize.y);
sf::RenderWindow window(vm, "SFML works!");

//Background texture
sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;

//hero texture
sf::Texture heroTexture;
sf::Sprite heroSprite;

//update hero moving
void update(float dt){
    if(playerMovingRight){
        heroSprite.move(150.0f*dt,0);
    }else if(playerMovingLeft){
        heroSprite.move(-150.0f*dt,0);
    }
}


//handle input
void updateInput(){
    sf::Event event;

    while(window.pollEvent(event)){
         if(event.type == sf::Event::KeyPressed){
            if(event.key.code == sf::Keyboard::Right){
                playerMovingRight = true;
            }
         }

         if(event.type == sf::Event::KeyReleased){
            if(event.key.code == sf::Keyboard::Right){
                playerMovingRight = false;

            }
         }

          if(event.type == sf::Event::KeyPressed){
            if(event.key.code == sf::Keyboard::Left){
                playerMovingLeft = true;
            }
         }

         if(event.type == sf::Event::KeyReleased){
            if(event.key.code == sf::Keyboard::Left){
                playerMovingLeft = false;
            }
         }

         if(event.key.code == sf::Keyboard::Escape 
            || event.type== sf::Event::Closed)
                    window.close();
    }
}

int main()
{
    //handle background error
    if (!backgroundTexture.loadFromFile("bg.jpg"))
    {
        std::cout << "Failed to load Background!" << std::endl;
    }

    //set background
    backgroundSprite.setTexture(backgroundTexture);

    //handle hero error I NEED A HERO
    if(!heroTexture.loadFromFile("c.png")){
        std::cout << "Failed to load HERO!" << std::endl;
    }

    //set hero and its position
    heroSprite.setTexture(heroTexture);
    heroSprite.setPosition(sf::Vector2f(viewSize.x/2,viewSize.y/2));
    heroSprite.setOrigin(heroTexture.getSize().x/2,heroTexture.getSize().y/2);

    sf::Clock clock;

    while (window.isOpen())
    {
        //update input
        updateInput();

        //update game
        sf::Time dt = clock.restart();
        update(dt.asSeconds());

        window.clear();
        window.draw(backgroundSprite);
        window.draw(heroSprite);
        window.display();
    }

    return 0;
}
