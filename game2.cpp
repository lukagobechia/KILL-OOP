#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Hero.h"
#include "Enemy.h"
#include "Obstacle.h"


//Render Windowsrc
sf::Vector2f viewSize(1000,720);
sf::VideoMode vm(viewSize.x,viewSize.y);
sf::RenderWindow window(vm, "level 3");

//Background texture
sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;

//Game Characters
Hero hero;
std::vector<Enemy> enemies(3);
std::vector<Obstacle> obstacles(2);

//Background music
sf::SoundBuffer jumpBuffer;
sf::Sound jumpSound(jumpBuffer);
sf::SoundBuffer deathBuffer;
sf::Sound deathSound(deathBuffer);

void init(){

    backgroundTexture.loadFromFile("bg.jpg");
    backgroundSprite.setTexture(backgroundTexture);
    hero.init("c.png",7,1.0f,sf::Vector2f(viewSize.x*0.5f,viewSize.y*0.5f),200);
    enemies[0].init("cpp.png",7,1.0f,sf::Vector2f(viewSize.x*0.25f,viewSize.y*0.5f),200);
    enemies[1].init("cpp.png",7,1.0f,sf::Vector2f(viewSize.x*0.6f,viewSize.y*0.5f),200);
    enemies[2].init("cpp.png",7,1.0f,sf::Vector2f(viewSize.x*0.70f,viewSize.y*0.5f),200);
    obstacles[0].init("obstacle.png",sf::Vector2f(viewSize.x*0.9f,768*0.75f));
    obstacles[1].init("obstacle.png",sf::Vector2f(viewSize.x*0.1f,768*0.75f));


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
                for(int i=0;i<enemies.size();i++){
                    enemies[i].jump(750.0f);
                }
                jumpSound.play();
            } else if (event.key.code == sf::Keyboard::Right) {
                hero.moveRight();
                for(int i=0;i<enemies.size();i++){
                    enemies[i].moveRight();
                }

            } else if (event.key.code == sf::Keyboard::Left) {
                hero.moveLeft();
                for(int i=0;i<enemies.size();i++){
                    enemies[i].moveLeft();
                }
            }
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Right) {
                hero.stopMoving();
                for(int i=0;i<enemies.size();i++){
                    enemies[i].stopMoving();
                }
            } else if (event.key.code == sf::Keyboard::Left) {
                hero.stopMoving();
                for(int i=0;i<enemies.size();i++){
                    enemies[i].stopMoving();
                }
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
    
    // Check collision between hero and obstacle
    if (hero.Collides(obstacles[0]) || hero.Collides(obstacles[1])) {
        window.close();
        system("game2.exe");
    }

     for (int i = 0; i < enemies.size(); i++) {
        if ((enemies[i].Collides(obstacles[0]) || enemies[i].Collides(obstacles[1])) && enemies[i].isALive()) {
            enemies[i].setAlive(false);
            deathSound.play();
        }
    }

    hero.update(dt);
    for(int i=0;i<enemies.size();i++){
        enemies[i].update(dt);
    }
    obstacles[0].update(dt);

    for(int i=0;i<enemies.size();i++){
        if(enemies[i].isALive()) break;
        else if(i==2){
            window.close();
            system("win.exe");
        }
    }
   
}


void draw(){
    window.draw(backgroundSprite);
    window.draw(hero.getSprite());
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i].isALive()) {
            window.draw(enemies[i].getSprite());
        }
    }
    window.draw(obstacles[0].getSprite());
    window.draw(obstacles[1].getSprite());
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
