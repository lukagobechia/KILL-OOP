#include <iostream>
#include <SFML/Graphics.hpp>
#include "Hero.h"
#include "Enemy.h"
//Render Windowsrc
sf::Vector2f viewSize(1000,720);
sf::VideoMode vm(viewSize.x,viewSize.y);
sf::RenderWindow window(vm, "SFML works!");

//Background texture
sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;
Hero hero;
Enemy enemy0,enemy1;

void init(){
    backgroundTexture.loadFromFile("bg.jpg");
    backgroundSprite.setTexture(backgroundTexture);
    hero.init("c.png",sf::Vector2f(viewSize.x*0.5f,viewSize.y*0.5f),200); 
    enemy0.init("cpp.png",sf::Vector2f(viewSize.x*0.75f,viewSize.y*0.5f),200);
    enemy1.init("cpp.png",sf::Vector2f(viewSize.x*0.25f,viewSize.y*0.5f),200); 
}

//handle input
void updateInput(){
    sf::Event event;

    while(window.pollEvent(event)){
        if(event.type==sf::Event::KeyPressed){
           if (event.key.code == sf::Keyboard::Up) {
                hero.jump(750.0f);
                enemy0.jump(750.0f);
                enemy1.jump(750.0f);
            } else if (event.key.code == sf::Keyboard::Right) {
                hero.moveRight();
                enemy0.moveRight();
                enemy1.moveRight();
            } else if (event.key.code == sf::Keyboard::Left) {
                hero.moveLeft();
                enemy0.moveLeft();
                enemy1.moveLeft();
            }
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Right) {
                hero.stopMoving();
                enemy0.stopMoving();
                enemy1.stopMoving();
            } else if (event.key.code == sf::Keyboard::Left) {
                hero.stopMoving();
                enemy0.stopMoving();
                enemy1.stopMoving();
            }
        }

        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::Closed) {
            if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
}

void update(float dt){
    hero.update(dt);
    enemy0.update(dt);
    enemy1.update(dt);
}

void draw(){
    window.draw(backgroundSprite);
    window.draw(hero.getSprite());
    window.draw(enemy0.getSprite());
    window.draw(enemy1.getSprite());

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
