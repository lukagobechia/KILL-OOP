#pragma onnce
#include <SFML/Graphics.hpp>

class Hero{


    private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
    sf::Vector2f m_position;

    int jumpCount =0;
    float m_mass;
    float m_velocity;
    float m_force;
    const float m_gravity = 9.80f;
    bool m_grounded;
    bool isMovingLeft;
    bool isMovingRight;


    public:
    Hero();
    ~Hero();

    void init(std::string,sf::Vector2f position,float mass);
    void update(float dt);
    void jump(float velocity);
    void moveLeft();
    void moveRight();
    void stopMoving();
    sf::Sprite getSprite();
};
