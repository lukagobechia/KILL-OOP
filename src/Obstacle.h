#pragma once
#include <SFML/Graphics.hpp>

class Obstacle{

    private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_position;

    bool isMovingRight;
    bool isMovingLeft;

    public:
    Obstacle();
    ~Obstacle();

    void init(std::string,sf::Vector2f position);
    void update(float dt);
    void moveLeft();
    void moveRight();
    void stopMoving();
    sf::Sprite getSprite();

};