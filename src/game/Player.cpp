#include "Player.h"
#include "../graphics/Renderer.h"
#include "../input/InputManager.h"
#include "../utils/Constants.h"
#include "Level.h"
#include <iostream>

Player::Player() : 
    m_position(0, 0),
    m_velocity(0, 0),
    m_size(32, 32),
    m_onGround(false),
    m_facingRight(true),
    m_moveSpeed(200.0f),
    m_jumpPower(400.0f),
    m_gravity(800.0f),
    m_bambooCollected(0),
    m_lives(3) {}

void Player::Initialize(float x, float y) {
    m_position.x = x;
    m_position.y = y;
    m_velocity.x = 0;
    m_velocity.y = 0;
    m_onGround = false;
}

void Player::Update(float deltaTime, const Level& level) {
    // Apply gravity
    if (!m_onGround) {
        m_velocity.y += m_gravity * deltaTime;
    }
    
    // Update position
    m_position.x += m_velocity.x * deltaTime;
    m_position.y += m_velocity.y * deltaTime;
    
    // Check collisions with level
    m_onGround = level.CheckCollision(m_position, m_size, m_velocity);
    
    // Check bamboo collection
    if (level.CheckBambooCollection(m_position, m_size)) {
        CollectBamboo();
    }
    
    // Reduce horizontal velocity (friction)
    m_velocity.x *= 0.8f;
    
    // Prevent falling through bottom of screen
    if (m_position.y > SCREEN_HEIGHT) {
        TakeDamage();
        m_position.x = 100.0f;
        m_position.y = 400.0f;
        m_velocity.y = 0;
    }
}

void Player::Render(Renderer& renderer) {
    // Simple panda representation (black and white squares)
    // Main body (white)
    renderer.DrawRectangle(m_position.x, m_position.y, m_size.x, m_size.y, 255, 255, 255);
    
    // Panda ears (black)
    renderer.DrawRectangle(m_position.x + 4, m_position.y - 4, 8, 8, 0, 0, 0);
    renderer.DrawRectangle(m_position.x + 20, m_position.y - 4, 8, 8, 0, 0, 0);
    
    // Panda eyes (black)
    renderer.DrawRectangle(m_position.x + 8, m_position.y + 8, 4, 4, 0, 0, 0);
    renderer.DrawRectangle(m_position.x + 20, m_position.y + 8, 4, 4, 0, 0, 0);
}

void Player::MoveLeft() {
    m_velocity.x = -m_moveSpeed;
    m_facingRight = false;
}

void Player::MoveRight() {
    m_velocity.x = m_moveSpeed;
    m_facingRight = true;
}

void Player::Jump() {
    if (m_onGround) {
        m_velocity.y = -m_jumpPower;
        m_onGround = false;
    }
}

void Player::CollectBamboo() {
    m_bambooCollected++;
    std::cout << "Bamboo collected! Total: " << m_bambooCollected << std::endl;
}

void Player::TakeDamage() {
    m_lives--;
    std::cout << "Panda took damage! Lives remaining: " << m_lives << std::endl;
}