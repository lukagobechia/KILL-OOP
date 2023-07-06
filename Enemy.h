#pragma once
#include <SFML/Graphics.hpp>
#include "Obstacle.h"

class Enemy{


    private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_position;

    int jumpCount =0;
    float m_mass;
    float m_velocity;
    float m_gravity = 9.80f;
    bool m_grounded;
    bool isMovingLeft;
    bool isMovingRight;

    int m_frameCount;
    float m_animDuration;
    float m_elapsedTime;
    sf::Vector2i m_spriteSize;

    bool isAlive = true;

    public:
    Enemy();
    ~Enemy();

    void init(std::string,int frameCount,float animDuration,sf::Vector2f position,float mass);
    void update(float dt);
    void jump(float velocity);
    void moveLeft();
    void moveRight();
    void stopMoving();
    sf::Sprite getSprite();
    bool Collides(Obstacle o);
    void setAlive(bool flag);
    bool isALive();
    
};
