#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Hero.h"
#include "Enemy.h"
#include "Obstacle.h"


//Render Windowsrc
sf::Vector2f viewSize(1000,720);
sf::VideoMode vm(viewSize.x,viewSize.y);
sf::RenderWindow window(vm, "level 1");

//Background texture
sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;

//Game Characters
Hero hero;
Enemy enemy0,enemy1;
Obstacle o1,o2;

//Background music
sf::SoundBuffer jumpBuffer;
sf::Sound jumpSound(jumpBuffer);
sf::SoundBuffer deathBuffer;
sf::Sound deathSound(deathBuffer);

void init(){

    backgroundTexture.loadFromFile("bg.jpg");
    backgroundSprite.setTexture(backgroundTexture);
    hero.init("c.png",7,1.0f,sf::Vector2f(viewSize.x*0.5f,viewSize.y*0.5f),200);
    enemy0.init("cpp.png",7,1.0f,sf::Vector2f(viewSize.x*0.25f,viewSize.y*0.5f),200);
    enemy1.init("cpp.png",7,1.0f,sf::Vector2f(viewSize.x*0.75f,viewSize.y*0.5f),200);
    o1.init("obstacle.png",sf::Vector2f(viewSize.x*0.9f,768*0.75f));
    o2.init("obstacle.png",sf::Vector2f(viewSize.x*0.1f,768*0.75f));


    deathBuffer.loadFromFile("src/include/SFML/Audio/death.wav");
    jumpBuffer.loadFromFile("src/include/SFML/Audio/jump.ogg");
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
                jumpSound.play();
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
    // Update hero and enemies
    hero.update(dt);
    enemy0.update(dt);
    enemy1.update(dt);
    
    // Check collision between hero and obstacle
    if (hero.Collides(o1) || hero.Collides(o2)) {
        window.close();
        system("game.exe");
    }

    if (enemy0.Collides(o1) && enemy0.isALive()){
        enemy0.setAlive(false);
        deathSound.play();
    }else if(enemy0.Collides(o2) && enemy0.isALive()){
        enemy0.setAlive(false);
        deathSound.play();
    }

    if (enemy1.Collides(o1) && enemy1.isALive()){
        enemy1.setAlive(false);
        deathSound.play();
    }else if(enemy0.Collides(o2) && enemy0.isALive()){
        enemy0.setAlive(false);
        deathSound.play();
    }

    if (!enemy0.isALive() && !enemy1.isALive()){
        window.close();
        system("game1.exe");
    }
   
}


void draw(){
    window.draw(backgroundSprite);
    window.draw(hero.getSprite());
    if(enemy0.isALive()){
        window.draw(enemy0.getSprite());
    }
    if(enemy1.isALive()){
        window.draw(enemy1.getSprite());
    }
    window.draw(o1.getSprite());
    window.draw(o2.getSprite());
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
