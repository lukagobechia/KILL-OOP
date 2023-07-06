#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Hero.h"
#include "Enemy.h"
#include "Obstacle.h"

// Render Window
sf::Vector2f viewSize(1000, 720);
sf::VideoMode vm(viewSize.x, viewSize.y);
sf::RenderWindow window(vm, "level 2");

// Background texture
sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;

// Game Characters
Hero hero;
std::vector<Enemy> enemies(4);
Obstacle obstacle;

sf::SoundBuffer jumpBuffer;
sf::Sound jumpSound(jumpBuffer);
sf::SoundBuffer deathBuffer;
sf::Sound deathSound(deathBuffer);

void init() {
    backgroundTexture.loadFromFile("bg.jpg");
    backgroundSprite.setTexture(backgroundTexture);

    hero.init("c.png", 7, 1.0f, sf::Vector2f(viewSize.x * 0.2f, viewSize.y * 0.5f), 200);
    obstacle.init("obstacle.png", sf::Vector2f(viewSize.x * 0.9f, 768 * 0.75f));

    // Initialize enemies
    for (int i = 0; i < 4; i++) {
        enemies[i].init("cpp.png", 7, 1.0f, sf::Vector2f(viewSize.x * (0.4f + i * 0.1f), viewSize.y * 0.5f), 200);
    }

    deathBuffer.loadFromFile("src/include/SFML/Audio/death.wav");
    jumpBuffer.loadFromFile("src/include/SFML/Audio/jump.ogg");
}

// Handle input
void updateInput() {
    sf::Event event;

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up) {
                hero.jump(750.0f);
                for (int i = 0; i < 4; i++) {
                    enemies[i].jump(750.0f);
                }
                jumpSound.play();
            } else if (event.key.code == sf::Keyboard::Right) {
                hero.moveRight();
                for (int i = 0; i < 4; i++) {
                    enemies[i].moveRight();
                }
            } else if (event.key.code == sf::Keyboard::Left) {
                hero.moveLeft();
                for (int i = 0; i < 4; i++) {
                    enemies[i].moveLeft();
                }
            }
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Right) {
                hero.stopMoving();
                for (int i = 0; i < 4; i++) {
                    enemies[i].stopMoving();
                }
            } else if (event.key.code == sf::Keyboard::Left) {
                hero.stopMoving();
                for (int i = 0; i < 4; i++) {
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

void update(float dt) {
    // Update hero and enemies
    hero.update(dt);
    for (int i = 0; i < enemies.size(); i++) {
        enemies[i].update(dt);
    }

    // Check collision between hero and obstacle
    if (hero.Collides(obstacle)) {
        window.close();
        system("game1.exe");
    }

    // Check collision between enemies and obstacle
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i].Collides(obstacle) && enemies[i].isALive()) {
            enemies[i].setAlive(false);
            enemies.erase(enemies.begin()+i);
            deathSound.play();
        }
    }

    if(enemies.empty()){
        window.close();
        system("game2.exe");
    }
}

void draw() {
    window.draw(backgroundSprite);
    window.draw(hero.getSprite());
    for (int i = 0; i < enemies.size(); i++) {
        if (enemies[i].isALive()) {
            window.draw(enemies[i].getSprite());
        }
    }
    window.draw(obstacle.getSprite());
}

int main() {
    sf::Clock clock;
    window.setFramerateLimit(60);
    init();

    while (window.isOpen()) {
        // Update input
        updateInput();

        // Update game
        sf::Time dt = clock.restart();
        update(dt.asSeconds());

        window.clear();
        draw();
        window.display();
    }

    return 0;
}
