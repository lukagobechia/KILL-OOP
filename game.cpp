#include <iostream>
#include <SFML/Graphics.hpp>
#include "Hero.h"
//Render Windowsrc
sf::Vector2f viewSize(1000,720);
sf::VideoMode vm(viewSize.x,viewSize.y);
sf::RenderWindow window(vm, "SFML works!");

//Background texture
sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;
Hero hero;

void init(){
    backgroundTexture.loadFromFile("bg.jpg");
    backgroundSprite.setTexture(backgroundTexture);
    hero.init("c.png",sf::Vector2f(viewSize.x*0.25f,viewSize.y*0.5f),200); 
}

//handle input
void updateInput(){
    sf::Event event;

    while(window.pollEvent(event)){
        if(event.type==sf::Event::KeyPressed){
            if(event.key.code==sf::Keyboard::Up){
                hero.jump(750.0f);
            }
        }

        if(event.type == sf::Event::KeyPressed){
            if(event.key.code == sf::Keyboard::Right){
                hero.moveRight();
            }
         }

         if(event.type == sf::Event::KeyReleased){
            if(event.key.code == sf::Keyboard::Right){
                hero.stopMoving();

            }
         }

          if(event.type == sf::Event::KeyPressed){
            if(event.key.code == sf::Keyboard::Left){
                hero.moveLeft();
            }
         }

         if(event.type == sf::Event::KeyReleased){
            if(event.key.code == sf::Keyboard::Left){
                hero.stopMoving();
            }
         }


         if(event.key.code == sf::Keyboard::Escape 
            || event.type== sf::Event::Closed)
                    window.close();
    }
}

void update(float dt){
    hero.update(dt);
}

void draw(){
    window.draw(backgroundSprite);
    window.draw(hero.getSprite());
}

int main()
{
    sf::Clock clock;
    window.setFramerateLimit(60);
    init();

    while (window.isOpen())
    {
        //update input
        updateInput();

        //update game
        sf::Time dt = clock.restart();
        update(dt.asSeconds());

        window.clear();
        draw();
        window.display();
    }

    return 0;
}
