#pragma once
#include <SFML/Graphics.hpp>

class Obstacle{
    private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_position;
    sf::Vector2i m_spriteSize;
    
    float m_speed = 0.5f;

    public:
    Obstacle();
    ~Obstacle();

    void init(std::string textureName,sf::Vector2f position);
    sf::Sprite getSprite();

    void update(float dt);
};