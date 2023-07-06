#include "Hero.h"
#include "Obstacle.h"

Hero::Hero(){}

Hero::~Hero(){}

void Hero::init(std::string textureName,int frameCount, float animDuration, sf::Vector2f position,float mass){
    m_position = position;
    m_mass = mass;
    m_grounded = false;

    m_frameCount = frameCount;
    m_animDuration = animDuration;

    m_spriteSize = sf::Vector2i(100,100);
    // Load a Texture
    m_texture.loadFromFile(textureName.c_str());
    // Create Sprite and Attach a Texture
    
    m_sprite.setTexture(m_texture);
    m_sprite.setTextureRect(sf::IntRect(0,0,m_spriteSize.x,m_spriteSize.y));
    m_sprite.setPosition(m_position);
    m_sprite.setOrigin(m_spriteSize.x / 2,
    m_spriteSize.y / 2);
}

void Hero::update(float dt){

    m_elapsedTime +=dt;
    int animFrame = static_cast<int> ((m_elapsedTime/m_animDuration)*m_frameCount)%m_frameCount;
    m_sprite.setTextureRect(sf::IntRect(animFrame*m_spriteSize.x,0,m_spriteSize.x,m_spriteSize.y));

    float acceleration = 500.0f;

    if (isMovingLeft) {
        m_position.x -= acceleration * dt;
    } else if (isMovingRight) {
        m_position.x += acceleration * dt;
    }

    if(m_position.x>=1000-m_spriteSize.x / 2){
        m_position.x=1000-m_spriteSize.x / 2;
    }else if(m_position.x<=m_spriteSize.x / 2){
        m_position.x=m_spriteSize.x / 2;
    }


    m_velocity -=m_mass*m_gravity*dt;
    m_position.y -=m_velocity * dt;
    m_sprite.setPosition(m_position);

    if(m_position.y>=768*0.75f){
        m_position.y = 768*0.75f;
        m_velocity = 0;
        m_grounded = true;
        jumpCount=0;
    }
}

void Hero::jump(float velocity){
        if(jumpCount<2){
            jumpCount++;

            m_velocity = velocity;
            m_grounded = false;
        }
}

void Hero::moveLeft(){
    isMovingLeft=true;
}
void Hero::moveRight(){
    isMovingRight=true;
}
void Hero::stopMoving(){
    isMovingRight=false;
    isMovingLeft=false;
}


sf::Sprite Hero::getSprite(){
    return m_sprite;
}

bool Hero::Collides(Obstacle o){
    if(m_sprite.getGlobalBounds().intersects(o.getSprite().getGlobalBounds())){
        
        return true;
    }

    return false;
}

void Hero::setAlive(bool flag){
    isAlive = flag;
}

bool Hero::isALive(){
    return isAlive;
}


