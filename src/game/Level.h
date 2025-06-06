#ifndef LEVEL_H
#define LEVEL_H

#include "../utils/Vector2.h"
#include "../graphics/Renderer.h"
#include <vector>

struct Platform {
    Vector2 position;
    Vector2 size;
    bool isBamboo;
    mutable bool isCollected; // Make this mutable so it can be modified in const methods
    
    Platform(float x, float y, float w, float h, bool bamboo = false) 
        : position(x, y), size(w, h), isBamboo(bamboo), isCollected(false) {}
};

class Level {
private:
    std::vector<Platform> m_platforms;
    mutable std::vector<Platform> m_bambooItems; // Make mutable for const methods
    Vector2 m_backgroundSize;
    
public:
    Level();
    
    void LoadLevel1();
    void LoadLevel2();
    void Render(Renderer& renderer);
    bool CheckCollision(Vector2& playerPos, Vector2 playerSize, Vector2& velocity) const;
    bool CheckBambooCollection(Vector2 playerPos, Vector2 playerSize) const; // Now const
    
    void Reset();
};

#endif