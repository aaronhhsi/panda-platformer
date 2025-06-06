#include "Level.h"
#include "../utils/Constants.h"

Level::Level() : m_backgroundSize(SCREEN_WIDTH, SCREEN_HEIGHT) {}

void Level::LoadLevel1() {
    m_platforms.clear();
    m_bambooItems.clear();
    
    // Ground platforms
    m_platforms.emplace_back(0, 550, 800, 50);
    
    // Floating platforms for panda to jump on
    m_platforms.emplace_back(150, 450, 100, 20);
    m_platforms.emplace_back(300, 350, 120, 20);
    m_platforms.emplace_back(500, 400, 100, 20);
    m_platforms.emplace_back(650, 300, 100, 20);
    
    // Bamboo collectibles
    m_bambooItems.emplace_back(180, 420, 16, 24, true);
    m_bambooItems.emplace_back(340, 320, 16, 24, true);
    m_bambooItems.emplace_back(530, 370, 16, 24, true);
    m_bambooItems.emplace_back(680, 270, 16, 24, true);
    m_bambooItems.emplace_back(400, 520, 16, 24, true);
}

void Level::LoadLevel2() {
    m_platforms.clear();
    m_bambooItems.clear();
    
    // More challenging level layout
    m_platforms.emplace_back(0, 550, 200, 50);
    m_platforms.emplace_back(250, 500, 80, 20);
    m_platforms.emplace_back(400, 420, 80, 20);
    m_platforms.emplace_back(550, 350, 80, 20);
    m_platforms.emplace_back(700, 280, 100, 20);
    
    // More bamboo scattered around
    m_bambooItems.emplace_back(270, 470, 16, 24, true);
    m_bambooItems.emplace_back(430, 390, 16, 24, true);
    m_bambooItems.emplace_back(580, 320, 16, 24, true);
    m_bambooItems.emplace_back(730, 250, 16, 24, true);
}

void Level::Render(Renderer& renderer) {
    // Render sky background (light blue)
    renderer.DrawRectangle(0, 0, m_backgroundSize.x, m_backgroundSize.y, 135, 206, 235);
    
    // Render platforms (brown/green)
    for (const auto& platform : m_platforms) {
        renderer.DrawRectangle(platform.position.x, platform.position.y, 
                              platform.size.x, platform.size.y, 101, 67, 33);
        // Add grass on top
        renderer.DrawRectangle(platform.position.x, platform.position.y - 2, 
                              platform.size.x, 2, 34, 139, 34);
    }
    
    // Render bamboo items (green stalks)
    for (const auto& bamboo : m_bambooItems) {
        if (!bamboo.isCollected) {
            // Bamboo stalk
            renderer.DrawRectangle(bamboo.position.x, bamboo.position.y, 
                                  bamboo.size.x, bamboo.size.y, 0, 128, 0);
            // Bamboo leaves
            renderer.DrawRectangle(bamboo.position.x - 2, bamboo.position.y, 
                                  4, 6, 34, 139, 34);
            renderer.DrawRectangle(bamboo.position.x + 14, bamboo.position.y + 6, 
                                  4, 6, 34, 139, 34);
        }
    }
}

bool Level::CheckCollision(Vector2& playerPos, Vector2 playerSize, Vector2& velocity) const {
    bool onGround = false;
    
    for (const auto& platform : m_platforms) {
        // Check if player is intersecting with platform
        if (playerPos.x < platform.position.x + platform.size.x &&
            playerPos.x + playerSize.x > platform.position.x &&
            playerPos.y < platform.position.y + platform.size.y &&
            playerPos.y + playerSize.y > platform.position.y) {
            
            // Landing on top of platform
            if (velocity.y > 0 && playerPos.y < platform.position.y) {
                playerPos.y = platform.position.y - playerSize.y;
                velocity.y = 0;
                onGround = true;
            }
            // Hitting platform from below
            else if (velocity.y < 0 && playerPos.y > platform.position.y) {
                playerPos.y = platform.position.y + platform.size.y;
                velocity.y = 0;
            }
            // Side collisions
            else if (velocity.x > 0) {
                playerPos.x = platform.position.x - playerSize.x;
                velocity.x = 0;
            }
            else if (velocity.x < 0) {
                playerPos.x = platform.position.x + platform.size.x;
                velocity.x = 0;
            }
        }
    }
    
    return onGround;
}

bool Level::CheckBambooCollection(Vector2 playerPos, Vector2 playerSize) const {
    for (auto& bamboo : m_bambooItems) {
        if (!bamboo.isCollected &&
            playerPos.x < bamboo.position.x + bamboo.size.x &&
            playerPos.x + playerSize.x > bamboo.position.x &&
            playerPos.y < bamboo.position.y + bamboo.size.y &&
            playerPos.y + playerSize.y > bamboo.position.y) {
            
            bamboo.isCollected = true; // This works because bamboo items are mutable
            return true;
        }
    }
    return false;
}

void Level::Reset() {
    for (auto& bamboo : m_bambooItems) {
        bamboo.isCollected = false;
    }
}