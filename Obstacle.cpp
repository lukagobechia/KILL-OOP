#include "Obstacle.h"

Obstacle::Obstacle(){}
Obstacle::~Obstacle(){}

void Obstacle::init(std::string textureName,sf::Vector2f position){
    m_texture.loadFromFile(textureName.c_str());
    m_position = position;
    m_sprite.setTexture(m_texture);
    m_sprite.setPosition(position);
    m_sprite.setOrigin(m_texture.getSize().x / 2,
    m_texture.getSize().y / 2);
    m_spriteSize = sf::Vector2i(100,100);
    m_speed = 500.0f;
}



void Obstacle::update(float dt) {

    if (m_sprite.getPosition().x <= m_spriteSize.x / 2 || m_sprite.getPosition().x >= 1000 - m_spriteSize.x / 2) {
        m_speed *= -1; // Reverse direction when reaching the edge
    }

    m_position.x += m_speed * dt;
    m_sprite.setPosition(m_position);
}



sf::Sprite Obstacle::getSprite(){
    return m_sprite;
}

