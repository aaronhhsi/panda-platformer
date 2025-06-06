#ifndef PLAYER_H
#define PLAYER_H

#include "../utils/Vector2.h"
#include "../graphics/Renderer.h"

class Level; // Forward declaration

class Player {
private:
    Vector2 m_position;
    Vector2 m_velocity;
    Vector2 m_size;
    
    bool m_onGround;
    bool m_facingRight;
    
    // Panda-specific properties
    float m_moveSpeed;
    float m_jumpPower;
    float m_gravity;
    int m_bambooCollected;
    int m_lives;
    
public:
    Player();
    
    void Initialize(float x, float y);
    void Update(float deltaTime, const Level& level);
    void Render(Renderer& renderer);
    
    void MoveLeft();
    void MoveRight();
    void Jump();
    
    // Panda-specific methods
    void CollectBamboo();
    void TakeDamage();
    bool IsAlive() const { return m_lives > 0; }
    
    // Getters
    Vector2 GetPosition() const { return m_position; }
    Vector2 GetSize() const { return m_size; }
    int GetBambooCount() const { return m_bambooCollected; }
    int GetLives() const { return m_lives; }
};

#endif