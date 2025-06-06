#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Level.h"
#include "../graphics/Renderer.h"
#include "../input/InputManager.h"

class Game {
private:
    bool m_isRunning;
    Player m_panda;
    Level m_currentLevel;
    Renderer m_renderer;
    InputManager m_inputManager;
    
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 600;
    const int TARGET_FPS = 60;
    
public:
    Game();
    ~Game();
    
    bool Initialize();
    void Run();
    void Update(float deltaTime);
    void Render();
    void HandleInput();
    void Cleanup();
};

#endif